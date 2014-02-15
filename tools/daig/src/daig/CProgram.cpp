#include <iostream>
#include <boost/foreach.hpp>
#include "Node.h"
#include "CProgram.h"

/*********************************************************************/
//print the program to an output stream with proper indentation
/*********************************************************************/
void
daig::CProgram::print (std::ostream &os,unsigned int indent)
{
  std::string spacer (indent, ' ');

  //print functions
  for (daig::Functions::iterator i = funcs.begin (); i != funcs.end (); ++i)
    i->second.print (os,indent);
}

/*********************************************************************/
//end of file
/*********************************************************************/
