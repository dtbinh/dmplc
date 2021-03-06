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


#ifndef __GAMS_GAMS_BUILDER_H__
#define __GAMS_GAMS_BUILDER_H__

#include <sstream>
#include "dmplc/DmplBuilder.hpp"
#include "dmplc/CodeGenerator.hpp"

namespace dmpl
{
  namespace gams
  {
    /*******************************************************************/
    // Synchronous program builder for GAMS
    /*******************************************************************/
    class GAMSBuilder : public CodeGenerator
    {
    public:
      /**
       * Constructor
       * @param  builder   the source for building a program
       **/
      GAMSBuilder (DmplBuilder & builder,const std::string &target, const int deadline,
                   const SchedType &schedType, bool do_expect);

      /**
       * Builds the underlying character stream that can then be printed
       **/
      void build (void);
      
      /**
       * Builds the target-specific thunk from the DASL program
       */
      void build_target_thunk (void);
      
      /**
       * Builds the header includes
       **/
      void build_header_includes (void);

      /**
       * Builds the common global MADARA generated variables
       **/
      void build_common_global_variables (void);
      
      /**
       * Builds the program's MADARA generated variables
       **/
      void build_program_variables (void);
      
      /**
       * Declare and initialize node-level variables. scope = local/global/group
       **/
      void build_node_variables (const Node &node, const std::string &scope);
      
      /**
       * Declare and initialize role-level variables. scope = local/global/group
       **/
      void build_role_variables (const Role &role, const std::string &scope);

      /**
       * Builds the program's MADARA generated variables
       **/
      void build_program_variable_decl (const Var & var);
      
      /**
       * Builds the program's MADARA generated variables
       **/
      void build_program_variable_init (const Var & var);
      
      /**
       * Builds commonly used filters
       */
      void build_common_filters (void);

      /**
       * Helper function of build_common_filters
       */
      void build_common_filters_helper (const std::string filter_name,
                                        std::stringstream & filter_content);
      
      /**
       * Builds a threads's variables for Read-Execute-Write semantics
       **/
      void build_thread_variables (const Func &thread, const Vars & vars, const std::string &scope);

      /**
       * Builds a threads's variable for Read-Execute-Write semantics
       **/
      void build_thread_variable (const Func &thread, const Var & var);
      
      /**
       * Generate code to initialize the role2Id map
       **/
      void build_init_role_id (void);
      
      /**
       * Generate code to initialize the nodesInGroup map
       **/
      void build_init_nodes_in_group (void);
      
      /**
       * Generate constructor invocation for all program variables
       **/
      void build_constructors (void);
      
      /**
       * Builds a MADARA generated variable binding in main
       **/
      void build_program_variable_assignment (const Var & var);

      /**
       * Builds the arguments parser
       **/
      void build_parse_args (void);
      
      /**
       * Builds variable value parsing
       * @return help printout for variable
       **/
      std::string build_parse_args (const std::string &var,
                                    const std::list<std::pair<Node,Role>> &roles);

      /**
       * Builds all function declarations to prevent undefined references
       **/
      void build_function_declarations (void);

      //-- build function declarations for a thread
      void build_function_declarations_for_thread (const Func & thread, const Funcs & funcs);

      /**
       * Builds a function
       * @param  function  a defined function in the parsed program
       **/
      void build_function_declaration (const Func & thread, const Func & function);

      //-- declare class that encapsulates the expect thread for a role
      void build_expect_thread_declaration (const Role &role);

      void build_gams_functions (void);

      /**
       * Builds global functions
       **/
      void build_global_functions (void);

      /**
       * Builds nodes
       **/
      void build_nodes (void);

      /**
       * Generate constructor for a variable
       **/
      void build_constructor_for_variable (Var &v, Node &node);

      /**
       * Builds a function for refreshing modification flag on input globals
       **/
      void build_refresh_modify_input_globals (const Node &node, const Role &role);

      /**
       * Builds a function for refreshing modification flag on globals
       **/
      void build_refresh_modify_globals (const Node &node, const Role &role, const Func &thread);
      
      /**
       * Builds a refresh statement for modification on a global
       **/
      void build_refresh_modify_global (const Node &node, const Var& var);

      void build_push_pull (const Func& thread, bool push);

      /**
       * Builds all functions for a specific thread
       * @param  thread  the target thread
       * @node  thread  the target node
       * @param  function  a defined function in the parsed program
       **/
      void build_functions_for_thread (const Func& thread, const dmpl::Node & node,
                                       const dmpl::Funcs & funcs);

      /**
       * Builds a function
       * @param  thread  the target thread
       * @node  thread  the target node
       * @param  function  a defined function in the parsed program
       **/
      void build_function (const Func& thread, const dmpl::Node & node, const dmpl::Func& function);

      //-- generate expect thread method definitions for a role
      void build_expect_thread_definition (const Role &role);

      void build_algo_declaration (void);
      void build_algo_functions (void);

      //-- generate the role2Id function
      void build_role2Id (void);      
      
      /**
       * Computes priorities, criticalities, and zero slack instants
       * of functions.
       **/
      void compute_priorities (void);

      /**
       * Builds the main function
       **/
      void build_main_function (void);

      /**
       * Generate code to create functions for a role
       **/
      void build_algo_creation (const Node &node, const dmpl::Role &role);

      /**
       * Builds the section of main that defines MADARA callable functions
       **/
      void build_main_define_functions (void);
      
      /**
       * Builds a function definition for MADARA
       * @param  function  a defined function in the parsed program
       **/
      void build_main_define_function (const dmpl::Node & node, const dmpl::Role &role,
                                       const dmpl::Func& thread);
      
      /**
       * Clears the underlying buffer
       **/
      void clear_buffer (void);

      /**
       * Prints the MADARA program to a stream
       * @param  os  the stream to print to
       **/
      void print (std::ostream & os);

      /**
       * Begins a namespace
       */
      void open_namespace (const std::string &ns);

      /**
       * Ends a namespace
       */
      void close_namespace (const std::string &ns);

      /**
       * Build a comment with prefix and suffix
       */
      void build_comment (const std::string &comment, const std::string &prefix,
                          const std::string &suffix, size_t indent);

    private:
      ///the deadline for MADARA to drop packets
      int madara_deadline;
      
      /// character buffer for holding results of build
      std::stringstream buffer_;

      //-- map from function names to priorities, criticalities and
      //-- Zero-Slack instants
      std::map<std::string,unsigned> funcPrios;
      std::map<std::string,unsigned> funcCrits;
      std::map<std::string,unsigned> funcZsinsts;

      //-- map from roles to roles that their functions refer to
      std::map<std::string,std::set<std::string>> rolesRefRoles;

      //-- helper function to return number of nodes
      inline size_t numNodes() const { return builder_.program.processes.size (); }
    };
  } // namespace gams
} //namespace dmpl

#endif //__GAMS_GAMS_BUILDER_H__
