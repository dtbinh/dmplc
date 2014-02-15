#ifndef _DAIG_VARIABLE_
#define _DAIG_VARIABLE_

/**
 * @file Variable.h
 * @author James Edmondson <jedmondson@gmail.com>
 *
 * This file contains a class definition for the DAIG model of computation.
 **/

#include <map>
#include <string>
#include "Type.h"

namespace daig
{
  /**
    * @class Variable
    * @brief A variable
    */
  class Variable
  {
  public:
    enum Scopes { LOCAL = 501, GLOBAL, PARAM, TEMP };
    
    /**
     * The variable name
     **/
    std::string name;
    
    /**
     * The variable type
     **/
    Type type;
    
    /**
     * The variable scope
     **/
    int scope;

    //constructors
    Variable() {}
    Variable(const std::string &n);
    Variable(const std::string &n,const std::list<int> &d);

    //convert to string
    std::string toString() const;

    /**
     * Prints variable information
     * @param  indent  spaces to indent printout
     **/
    void print (std::ostream &os,unsigned int indent);

    ///return a copy but instantiate dimension #N with nodeNum
    Variable instDim(size_t nodeNum) const;

    ///return a copy but change name to name+ext
    Variable instName(std::string ext) const;
  };

  typedef std::map <std::string, Variable> Variables;
}


#endif // _DAIG_VARIABLE_
