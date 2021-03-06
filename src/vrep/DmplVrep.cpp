/**
 * Copyright (c) 2015 Carnegie Mellon University. All Rights Reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:

 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following acknowledgments
 * and disclaimers.

 * 2. Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided
 * with the distribution.

 * 3. The names "Carnegie Mellon University," "SEI" and/or "Software
 * Engineering Institute" shall not be used to endorse or promote
 * products derived from this software without prior written
 * permission. For written permission, please contact
 * permission@sei.cmu.edu.

 * 4. Products derived from this software may not be called "SEI" nor
 * may "SEI" appear in their names without prior written permission of
 * permission@sei.cmu.edu.

 * 5. Redistributions of any form whatsoever must retain the following
 * acknowledgment:

 * This material is based upon work funded and supported by the
 * Department of Defense under Contract No. FA8721-05-C-0003 with
 * Carnegie Mellon University for the operation of the Software
 * Engineering Institute, a federally funded research and development
 * center.

 * Any opinions, findings and conclusions or recommendations expressed
 * in this material are those of the author(s) and do not necessarily
 * reflect the views of the United States Department of Defense.

 * NO WARRANTY. THIS CARNEGIE MELLON UNIVERSITY AND SOFTWARE
 * ENGINEERING INSTITUTE MATERIAL IS FURNISHED ON AN "AS-IS"
 * BASIS. CARNEGIE MELLON UNIVERSITY MAKES NO WARRANTIES OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, AS TO ANY MATTER INCLUDING, BUT NOT
 * LIMITED TO, WARRANTY OF FITNESS FOR PURPOSE OR MERCHANTABILITY,
 * EXCLUSIVITY, OR RESULTS OBTAINED FROM USE OF THE MATERIAL. CARNEGIE
 * MELLON UNIVERSITY DOES NOT MAKE ANY WARRANTY OF ANY KIND WITH
 * RESPECT TO FREEDOM FROM PATENT, TRADEMARK, OR COPYRIGHT
 * INFRINGEMENT.

 * This material has been approved for public release and unlimited
 * distribution.

 * DM-0002494
**/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "DmplVrep.hpp"

#define FLOOR "20mX20m_floor#"

//distance tolerance when determining if a node has reached a location.
#define DIST_TOL 0.2

//increment by which the target is shifted
#define TARGET_INCR 0.25


const double TrackerAnt::antZ = 0.0468;

/*********************************************************************/
//constructor
/*********************************************************************/
DmplVrep::DmplVrep(simxInt _xdim,simxInt _ydim)
  : clientId(-1),xdim(_xdim),ydim(_ydim),debug(false) {}

/*********************************************************************/
//connect to the simulator
/*********************************************************************/
simxInt DmplVrep::connect(simxChar *ipAddr,simxInt port)
{
  clientId = simxStart(ipAddr,port,true,true,2000,5);

  //compute floor dimensions and coordinates

  //get the floor object
  simxInt floor;
  simxGetObjectHandle(clientId,FLOOR,&floor,simx_opmode_oneshot_wait);
  if(debug) std::cout << "floor handle = " << floor << '\n';

  //get the floor center coordinate
  simxGetObjectPosition(clientId,floor,sim_handle_parent,floorCenter,simx_opmode_oneshot_wait);

  if(debug) std::cout << "floor coordinates are : (" << floorCenter[0] << "," 
                      << floorCenter[1] << "," << floorCenter[2] << ")\n";

  simxGetObjectFloatParameter(clientId,floor,15,&minx,simx_opmode_oneshot_wait);
  if(debug) std::cout << "floor min x = " << minx << '\n';
  simxGetObjectFloatParameter(clientId,floor,18,&maxx,simx_opmode_oneshot_wait);
  if(debug) std::cout << "floor max x = " << maxx << '\n';

  simxGetObjectFloatParameter(clientId,floor,16,&miny,simx_opmode_oneshot_wait);
  if(debug) std::cout << "floor min y = " << miny << '\n';
  simxGetObjectFloatParameter(clientId,floor,19,&maxy,simx_opmode_oneshot_wait);
  if(debug) std::cout << "floor max y = " << maxy << '\n';

  return clientId;
}

/*********************************************************************/
//disconnect from the simulator
/*********************************************************************/
void DmplVrep::disconnect()
{
  simxFinish(clientId);
}

/*********************************************************************/
//set the debug flag
/*********************************************************************/
void DmplVrep::setDebug(const bool d) { debug = d; }

/*********************************************************************/
//create a node and return its handle. return -1 on failure.
/*********************************************************************/
simxInt DmplVrep::createNode(const std::string &modelFile)
{
  simxInt nodeId = -1;
  if(simxLoadModel(clientId,modelFile.c_str(),0,&nodeId,simx_opmode_oneshot_wait) != simx_error_noerror)
    return -1;

  if(debug) std::cout << "newly created node id = " << nodeId << '\n';

  //update the node2Targets maps


  node2Targets[nodeId] = getTargetHandle(nodeId);

  return nodeId;
}

/*********************************************************************/
//destroy node with handle passed as argument. return 0 on success and
//1 on failure.
/*********************************************************************/
simxInt DmplVrep::destroyNode(const simxInt nodeId)
{
  //delete all children
  for(;;) {
    simxInt retVal = 0,childId = 0;
    retVal = simxGetObjectChild(clientId,nodeId,0,&childId,simx_opmode_oneshot_wait);
    if(retVal != simx_error_noerror) return 1;

    if(childId == -1) break;

    retVal = simxRemoveObject(clientId,childId,simx_opmode_oneshot_wait);
    if(retVal != simx_error_noerror) return 1;
  }

  return (simxRemoveObject(clientId,nodeId,simx_opmode_oneshot_wait) != simx_error_noerror);
}

/*********************************************************************/
//return the number of objects in the scene, -1 on failure
/*********************************************************************/
simxInt DmplVrep::getNumObjects()
{
  simxInt objCount = 0,*objHandles=0;
  return (simxGetObjects(clientId,sim_object_shape_type,&objCount,&objHandles,
                         simx_opmode_oneshot_wait) != simx_error_noerror) ? -1 : objCount;
}

/*********************************************************************/
//return ping time to server
/*********************************************************************/
simxInt DmplVrep::getPingTime()
{  
  simxInt pingTime = -1;
  simxGetPingTime(clientId,&pingTime);
  return pingTime;
}

/*********************************************************************/
//move node specified by nodeId instantaneoulsy to coordinates
//(x,y,z). return 0 on success and 1 on failure. this function should
//not be called while the simulation is running.
/*********************************************************************/
simxInt DmplVrep::placeNodeAt(simxInt nodeId,simxFloat x,simxFloat y,simxFloat z)
{
  if(debug) std::cout << "placing handle " << nodeId << " at (" << x << "," << y << "," << z << ")\n";

  //compute object coordinates
  simxFloat objCoord[3];

  objCoord[0] = floorCenter[0] + minx + x / xdim * (maxx - minx); 
  objCoord[1] = floorCenter[1] + miny + y / ydim * (maxy - miny); 
  objCoord[2] = floorCenter[2] + z;

  return simxSetObjectPosition(clientId,nodeId,sim_handle_parent,objCoord,
                               simx_opmode_oneshot_wait) != simx_error_noerror;
}

/*********************************************************************/
//return true if the argument node is close enough to its target
/*********************************************************************/
bool DmplVrep::nodeAtTarget(simxInt nodeId)
{
  simxFloat currPos[3];
  simxGetObjectPosition(clientId,nodeId,sim_handle_parent,currPos,simx_opmode_oneshot_wait);

  //check if the current position is within tolerance of target
  for(int i = 0;i < 3;++i) {
    if(debug) std::cout << "node[" << i << "] = " << currPos[i]
                        << "\t\ttarget[" << i << "] = " << node2TargetPos[nodeId][i] << '\n';
    if(fabsf(currPos[i] - node2TargetPos[nodeId][i]) > DIST_TOL) return false;
  }

  return true;
}

/*********************************************************************/
//return true if the argument node's target is close enough to its
//waypoint
/*********************************************************************/
bool DmplVrep::targetAtWaypoint(simxInt nodeId)
{
  for(int i = 0;i < 3;++i)
    if(fabsf(node2TargetPos[nodeId][i] - node2Waypoint[nodeId][i]) > DIST_TOL) return false;

  return true;
}

/*********************************************************************/
//start simulatiom
/*********************************************************************/
simxInt DmplVrep::startSim()
{
  return simxStartSimulation(clientId,simx_opmode_oneshot_wait);
}

/*********************************************************************/
//pause simulatiom
/*********************************************************************/
simxInt DmplVrep::pauseSim()
{
  return simxPauseSimulation(clientId,simx_opmode_oneshot_wait);
}

/*********************************************************************/
//stop simulatiom
/*********************************************************************/
simxInt DmplVrep::stopSim()
{
  return simxStopSimulation(clientId,simx_opmode_oneshot_wait);
}

/*********************************************************************/
//create a quadcopter and return its handle. return -1 on
//failure. uses the base class's method.
/*********************************************************************/
simxInt QuadriRotor::createNode()
{
  std::string modelFile(getenv("VREP_ROOT"));
  modelFile += "/models/robots/mobile/Quadricopter.ttm";
  return DmplVrep::createNode(modelFile);
}

simxInt QuadriRotor::getTargetHandle(simxInt nodeId)
{
  //find the dummy base sub-object
  simxInt handlesCount = 0,*handles = NULL;
  simxInt parentsCount = 0,*parents = NULL;
  simxGetObjectGroupData(clientId,sim_object_dummy_type,2,&handlesCount,&handles,
                         &parentsCount,&parents,NULL,NULL,NULL,NULL,simx_opmode_oneshot_wait);

  if(debug) std::cout << "dummy objects obtained = " << handlesCount << '\n';
  if(debug) std::cout << "parent objects obtained = " << parentsCount << '\n';

  simxInt nodeBase = -1;
  for(simxInt i = 0;i < handlesCount;++i) {
    if(parents[i] == nodeId) {
      nodeBase = handles[i];
      break;
    }
  }
  if(debug) std::cout << "node base handle = " << nodeBase << '\n';

  //find the target sub-object of the base sub-object
  simxInt nodeTarget = -1;
  simxGetObjectChild(clientId,nodeBase,0,&nodeTarget,simx_opmode_oneshot_wait);
  if(debug) std::cout << "node target handle = " << nodeTarget << '\n';

  return nodeTarget;
}

/*********************************************************************/
//place quadcopter at position. uses the base class's method.
/*********************************************************************/
simxInt QuadriRotor::placeNodeAt(simxInt nodeId,simxFloat x,simxFloat y,simxFloat z)
{
  return DmplVrep::placeNodeAt(nodeId,x,y,z);
}

/*********************************************************************/
//move a quadcopter to specified coordinate -- return 0 if reached
//destination, -1 if there is an error, and 1 otherwise. an
//application should call this method repeatedly until it returns
//0. there should be some delay between successive calls.
/*********************************************************************/
simxInt QuadriRotor::moveNodeTo(simxInt nodeId,simxFloat x,simxFloat y,simxFloat z)
{
  //if the waypoint has not been set, set it and move the waypoint
  TargetMap::iterator it = node2Waypoint.find(nodeId);

  if(it == node2Waypoint.end()) {
    //set waypoint of node
    node2Waypoint[nodeId].resize(3);
    node2Waypoint[nodeId][0] = floorCenter[0] + minx + x / xdim * (maxx - minx); 
    node2Waypoint[nodeId][1] = floorCenter[1] + miny + y / ydim * (maxy - miny); 
    node2Waypoint[nodeId][2] = floorCenter[2] + z;

    if(debug) std::cout << "waypoint = (" << node2Waypoint[nodeId][0] << ","
                        << node2Waypoint[nodeId][1] << ","
                        << node2Waypoint[nodeId][2] << ")\n";

    //set current position of node target
    simxFloat currPos[3];
    simxGetObjectPosition(clientId,node2Targets[nodeId],sim_handle_parent,currPos,
                          simx_opmode_oneshot_wait);
    node2TargetPos[nodeId].resize(3);
    for(int i = 0;i < 3;++i) node2TargetPos[nodeId][i] = currPos[i];

    if(debug) std::cout << "target = (" << node2TargetPos[nodeId][0] << ","
                        << node2TargetPos[nodeId][1] << ","
                        << node2TargetPos[nodeId][2] << ")\n";
  }

  if(!nodeAtTarget(nodeId)) {
    if(debug) std::cout << "node not yet at target ...\n";
    return 1;
  }

  if(debug) std::cout << "node already at target ...\n";

  if(targetAtWaypoint(nodeId)) {
    if(debug) std::cout << "target at waypoint ... done ...\n";
    //clear the waypoint and target positions and return 0
    node2Waypoint.erase(nodeId);
    node2TargetPos.erase(nodeId);
    return 0;
  }

  if(debug) std::cout << "target not at waypoint ...\n";

  //move target closer to the waypoint and return 1
  simxFloat currPos[3];
  for(int i = 0;i < 3;++i) {
    if(node2TargetPos[nodeId][i] < node2Waypoint[nodeId][i] - TARGET_INCR)
      currPos[i] = node2TargetPos[nodeId][i] + TARGET_INCR;
    else if(node2TargetPos[nodeId][i] > node2Waypoint[nodeId][i] + TARGET_INCR)
      currPos[i] = node2TargetPos[nodeId][i] - TARGET_INCR;
    else
      currPos[i] = node2Waypoint[nodeId][i];
    node2TargetPos[nodeId][i] = currPos[i];
  }
  simxSetObjectPosition(clientId,node2Targets[nodeId],sim_handle_parent,currPos,
                        simx_opmode_oneshot_wait);

  if(debug) std::cout << "new target = (" << node2TargetPos[nodeId][0] << ","
                      << node2TargetPos[nodeId][1] << ","
                      << node2TargetPos[nodeId][2] << ")\n";

  return 1;
}

/*********************************************************************/
//create a quadcopter and return its handle. return -1 on
//failure. uses the base class's method.
/*********************************************************************/
simxInt TrackerAnt::createNode()
{
  std::string modelFile(getenv("DMPL_ROOT"));
  modelFile += "/dmpl/src/vrep/tracker_ant.ttm";
  return DmplVrep::createNode(modelFile);
}

simxInt TrackerAnt::getTargetHandle(simxInt nodeId)
{
  simxInt nodeTarget = -1;
  simxGetObjectChild(clientId,nodeId,0,&nodeTarget,simx_opmode_oneshot_wait);
  if(debug) std::cout << "node target handle = " << nodeTarget << '\n';

  return nodeTarget;
}

/*********************************************************************/
//place quadcopter at position. uses the base class's method.
/*********************************************************************/
simxInt TrackerAnt::placeNodeAt(simxInt nodeId,simxFloat x,simxFloat y,simxFloat z)
{
  //set Z to 0 since the ant cannot fly
  return DmplVrep::placeNodeAt(nodeId,x,y,antZ);
}

/*********************************************************************/
//move a quadcopter to specified coordinate -- return 0 if reached
//destination, -1 if there is an error, and 1 otherwise. an
//application should call this method repeatedly until it returns
//0. there should be some delay between successive calls.
/*********************************************************************/
simxInt TrackerAnt::moveNodeTo(simxInt nodeId,simxFloat x,simxFloat y,simxFloat z)
{
  //if the waypoint has not been set, set it and move the waypoint
  TargetMap::iterator it = node2Waypoint.find(nodeId);

  if(it == node2Waypoint.end()) {
    //set waypoint of node
    node2Waypoint[nodeId].resize(3);
    node2Waypoint[nodeId][0] = floorCenter[0] + minx + x / xdim * (maxx - minx); 
    node2Waypoint[nodeId][1] = floorCenter[1] + miny + y / ydim * (maxy - miny); 
    node2Waypoint[nodeId][2] = floorCenter[2] + antZ;

    if(debug) std::cout << "waypoint = (" << node2Waypoint[nodeId][0] << ","
                        << node2Waypoint[nodeId][1] << ","
                        << node2Waypoint[nodeId][2] << ")\n";

    //set current position of node target
    simxFloat currPos[3];
    simxGetObjectPosition(clientId,node2Targets[nodeId],sim_handle_parent,currPos,
                          simx_opmode_oneshot_wait);
    node2TargetPos[nodeId].resize(3);
    for(int i = 0;i < 3;++i) node2TargetPos[nodeId][i] = currPos[i];

    if(debug) std::cout << "target = (" << node2TargetPos[nodeId][0] << ","
                        << node2TargetPos[nodeId][1] << ","
                        << node2TargetPos[nodeId][2] << ")\n";
  }

  if(!nodeAtTarget(nodeId)) {
    if(debug) std::cout << "node not yet at target ...\n";
    return 1;
  }

  if(debug) std::cout << "node already at target ...\n";

  if(targetAtWaypoint(nodeId)) {
    if(debug) std::cout << "target at waypoint ... done ...\n";
    //clear the waypoint and target positions and return 0
    node2Waypoint.erase(nodeId);
    node2TargetPos.erase(nodeId);
    return 0;
  }

  if(debug) std::cout << "target not at waypoint ...\n";

  //move target closer to the waypoint and return 1
  simxFloat currPos[3];
  for(int i = 0;i < 3;++i) {
    if(node2TargetPos[nodeId][i] < node2Waypoint[nodeId][i] - TARGET_INCR)
      currPos[i] = node2TargetPos[nodeId][i] + TARGET_INCR;
    else if(node2TargetPos[nodeId][i] > node2Waypoint[nodeId][i] + TARGET_INCR)
      currPos[i] = node2TargetPos[nodeId][i] - TARGET_INCR;
    else
      currPos[i] = node2Waypoint[nodeId][i];
    node2TargetPos[nodeId][i] = currPos[i];
  }
  simxSetObjectPosition(clientId,node2Targets[nodeId],sim_handle_parent,currPos,
                        simx_opmode_oneshot_wait);

  if(debug) std::cout << "new target = (" << node2TargetPos[nodeId][0] << ","
                      << node2TargetPos[nodeId][1] << ","
                      << node2TargetPos[nodeId][2] << ")\n";

  return 1;
}

/*********************************************************************/
//end of file
/*********************************************************************/
