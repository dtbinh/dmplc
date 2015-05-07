/**
 * Copyright (c) 2014 Carnegie Mellon University. All Rights Reserved.

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

 * DM-0001023
**/


#include "Analyzer_Builder.hpp"
#include <dmpl/gams/Function_Visitor.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <map>
#include <dmplc/dmpl-parser.hpp>

dmpl::gams::Analyzer_Builder::Analyzer_Builder (dmpl::DmplBuilder & builder, const std::string &target)
    : builder_(builder), target_(target) {}

void
dmpl::gams::Analyzer_Builder::build ()
{
  build_header_includes ();
  build_target_thunk_includes ();
  // open dmpl namespace after including ALL libraries
  open_dmpl_namespace ();
  build_common_global_variables ();
  build_program_variables ();
  build_common_filters ();
  build_target_thunk ();
  build_parse_args ();
  build_functions_declarations ();
  build_functions ();
  // close dmpl namespace
  close_dmpl_namespace ();
  buffer_ << "using namespace dmpl;\n";
  build_main_function ();
}

void
dmpl::gams::Analyzer_Builder::build_header_includes ()
{
  buffer_ << "#include <string>\n";
  buffer_ << "#include <vector>\n";
  buffer_ << "#include <sstream>\n";
  buffer_ << "#include <fstream>\n";
  buffer_ << "#include <assert.h>\n";
  buffer_ << "#include <math.h>\n";
  buffer_ << "\n";
  buffer_ << "#include \"madara/knowledge_engine/Knowledge_Base.h\"\n";
  buffer_ << "#include \"madara/knowledge_engine/Knowledge_Record.h\"\n";
  buffer_ << "#include \"madara/knowledge_engine/Functions.h\"\n";
  buffer_ << "#include \"madara/knowledge_engine/containers/Integer_Vector.h\"\n";
  buffer_ << "#include \"madara/knowledge_engine/containers/Double_Vector.h\"\n";
  buffer_ << "#include \"madara/knowledge_engine/containers/Vector_N.h\"\n";
  buffer_ << "#include \"madara/threads/Threader.h\"\n";
  buffer_ << "#include \"madara/filters/Generic_Filters.h\"\n";
  buffer_ << "\n";
  buffer_ << "#include \"gams/controllers/Base_Controller.h\"\n";
  buffer_ << "#include \"gams/algorithms/Base_Algorithm.h\"\n";
  buffer_ << "#include \"gams/variables/Sensor.h\"\n";
  buffer_ << "#include \"gams/platforms/Base_Platform.h\"\n";
  buffer_ << "#include \"gams/variables/Algorithm.h\"\n";
  buffer_ << "#include \"gams/variables/Self.h\"\n";
  buffer_ << "#include \"gams/utility/GPS_Position.h\"\n";
  buffer_ << "\n";
  buffer_ << "#include \"dmpl/Reference.hpp\"\n";
  buffer_ << "#include \"dmpl/ArrayReference.hpp\"\n";
  buffer_ << "#include \"dmpl/LogAnalyzer.hpp\"\n";
}

void
dmpl::gams::Analyzer_Builder::build_target_thunk_includes ()
{
  const std::string include_lines = remove_include_lines_from_target_thunk ();
  buffer_ << include_lines << '\n';
}

void
dmpl::gams::Analyzer_Builder::build_common_global_variables ()
{
  buffer_ << "// typedefs\n";
  buffer_ << "typedef   Madara::Knowledge_Record::Integer   Integer;\n\n";
  buffer_ << "// namespace shortcuts\n";
  //buffer_ << "namespace engine = Madara::Knowledge_Engine;\n";
  buffer_ << "namespace threads = Madara::Threads;\n\n";
  buffer_ << "namespace containers = engine::Containers;\n\n";
  buffer_ << "namespace controllers = gams::controllers;\n\n";
  buffer_ << "namespace platforms = gams::platforms;\n\n";
  buffer_ << "namespace variables = gams::variables;\n\n";
  buffer_ << "using containers::Reference;\n\n";
  buffer_ << "using containers::ArrayReference;\n\n";
  buffer_ << "\n";
  buffer_ << "engine::Knowledge_Base knowledge;\n";
  buffer_ << "int verbosity = 0;\n";
  buffer_ << "\n";

  buffer_ << "template<class T> std::string to_string(const T &in)\n";
  buffer_ << "{\n";
  buffer_ << "  std::stringstream ss;\n";
  buffer_ << "  ss << in;\n";
  buffer_ << "  return ss.str();\n";
  buffer_ << "}\n";
  buffer_ << "\n";
  buffer_ << "double integrate_knowledge(const std::string &name, double value)\n";
  buffer_ << "{\n";
  buffer_ << "  engine::Variable_Reference ref = knowledge.get_ref(name);\n";
  buffer_ << "  Madara::Knowledge_Record rec = knowledge.get(ref);\n";
  buffer_ << "  double orig = rec.to_double();\n";
  buffer_ << "  double ret = orig + value * 0.2;\n";
  buffer_ << "  knowledge.set(ref, ret);\n";
  buffer_ << "  if(::dmpl::verbosity > 0)\n";
  buffer_ << "    std::cerr << name << \": \" << ret << \"  (+\" << ret - orig << \")\" << std::endl;\n";
  buffer_ << "  return ret;\n";
  buffer_ << "}\n";
  buffer_ << "\n";
  buffer_ << "// Needed as a workaround for non-const-correctness in Madara; use carefully\n";
  buffer_ << "inline engine::Function_Arguments &__strip_const(const engine::Function_Arguments &c)\n";
  buffer_ << "{\n";
  buffer_ << "  return const_cast<engine::Function_Arguments &>(c);\n";
  buffer_ << "}\n";
  buffer_ << "\n";
  buffer_ << "inline engine::Function_Arguments &__chain_set(engine::Function_Arguments &c, int i, const Madara::Knowledge_Record &v)\n";
  buffer_ << "{\n";
  buffer_ << "  c[i] = v;\n";
  buffer_ << "  return c;\n";
  buffer_ << "}\n";
  buffer_ << "\n";

  buffer_ << "// default transport variables\n";
  buffer_ << "std::string host (\"\");\n";
  buffer_ << "std::vector<std::string> platform_params;\n";
  buffer_ << "std::string platform_name (\"debug\");\n";
  buffer_ << "typedef void (*PlatformInitFn)(const std::vector<std::string> &, engine::Knowledge_Base &);\n";
  buffer_ << "typedef std::map<std::string, PlatformInitFn> PlatformInitFns;\n";
  buffer_ << "PlatformInitFns platform_init_fns;\n";
  buffer_ << "const std::string default_multicast (\"239.255.0.1:4150\");\n";
  buffer_ << "Madara::Transport::QoS_Transport_Settings settings;\n";
  buffer_ << "int write_fd (-1);\n";
  buffer_ << "ofstream expect_file;\n";
  buffer_ << "\n";

  buffer_ << "// Containers for commonly used variables\n";
  buffer_ << "// Global variables\n";
  //buffer_ << "containers::Integer_Array barrier;\n";

  buffer_ << "Reference<unsigned int> id(knowledge, \".id\");\n";
  buffer_ << "Reference<unsigned int>  num_processes(knowledge, \".num_processes\");\n";
  buffer_ << "double max_barrier_time (-1);\n";
  buffer_ << "engine::Knowledge_Update_Settings private_update (true);\n";
  buffer_ << "\n";
  buffer_ << "// number of participating processes\n";
  buffer_ << "unsigned int processes (";
  buffer_ << builder_.program.processes.size ();
  buffer_ << ");\n\n";
}

void
dmpl::gams::Analyzer_Builder::build_target_thunk (void)
{
  buffer_ << "// target (" << target_ << ") specific thunk\n";

  // we use target_ as a key to all related thunks
  Program::TargetType::const_iterator it =
    builder_.program.targets.find (target_);
  
  // if there was any such target, print it
  if (it != builder_.program.targets.end ())
  {
    buffer_ << it->second << "\n\n";
  }
}

std::string
dmpl::gams::Analyzer_Builder::remove_include_lines_from_target_thunk (void)
{
  Program::TargetType::const_iterator it =
    builder_.program.targets.find (target_);

  if (it != builder_.program.targets.end ())
  {
    std::pair<std::string, std::string> blocks = split_include_and_non_include_blocks (it->second);
    builder_.program.targets[target_] = blocks.second;

    return blocks.first;
  }

  return "";
}

std::pair<std::string, std::string>
dmpl::gams::Analyzer_Builder::split_include_and_non_include_blocks (const std::string target_str)
{
  std::vector<std::string> all_lines;
  std::vector<std::string> include_lines;
  std::vector<std::string> non_include_lines;

  boost::split (all_lines, target_str, boost::is_any_of ("\n"));
  for (std::vector<std::string>::iterator it = all_lines.begin (); it != all_lines.end (); ++it)
  {
    std::string line = *it;
    if (line.find ("#include") == 0)
    {
      include_lines.push_back (line);
    }
    else
    {
      non_include_lines.push_back (line);
    }
  }

  // all lines starting with #include
  std::string include_str ("");
  for (std::vector<std::string>::iterator it = include_lines.begin (); it != include_lines.end (); ++it)
  {
    include_str += *it + "\n";
  }

  // all lines not starting with #include
  std::string non_include_str ("");
  for (std::vector<std::string>::iterator it = non_include_lines.begin (); it != non_include_lines.end (); ++it)
  {
    non_include_str += *it + "\n";
  }

  std::pair<std::string, std::string> blocks (include_str, non_include_str);
  return blocks;
}

void
dmpl::gams::Analyzer_Builder::build_common_filters (void)
{
}

void
dmpl::gams::Analyzer_Builder::build_common_filters_helper (
    const std::string filter_name,
    std::stringstream & filter_content)
{
  buffer_ << "Madara::Knowledge_Record\n";
  buffer_ << filter_name << " (Madara::Knowledge_Map & records,\n";
  buffer_ << "  const Madara::Transport::Transport_Context & context,\n";
  buffer_ << "  Madara::Knowledge_Engine::Variables & vars)\n";
  buffer_ << "{\n";
  buffer_ << "  Madara::Knowledge_Record result;\n";
  buffer_ << filter_content.str ();
  buffer_ << "  return result;\n";
  buffer_ << "}\n\n";
}

namespace
{
  std::string get_type_name(const dmpl::Var &var)
  {
    if(var->type->type == TCHAR)
      return "short";
    else
      return var->type->toString();
  }
}

void
dmpl::gams::Analyzer_Builder::build_program_variables ()
{
  buffer_ << "// Defining program-specific constants\n";
  
  Program::ConstDef & consts = builder_.program.constDef;
  for (Program::ConstDef::iterator i = consts.begin (); i != consts.end (); ++i)
  {
    buffer_ << "#define ";
    buffer_ << i->first;
    buffer_ << " ";
    buffer_ << i->second;
    buffer_ << "\n";
  }

  buffer_ << "\n";
  
  Nodes & nodes = builder_.program.nodes;
  for (Nodes::iterator n = nodes.begin (); n != nodes.end (); ++n)
  {
    buffer_ << "// Defining program-specific global variables\n";
    Vars & vars = n->second.globVars;
    for (Vars::iterator i = vars.begin (); i != vars.end (); ++i)
    {
      Var & var = i->second;
      var->type = var->type->incrDim(-1);
      build_program_variable (var);
    }
    
    buffer_ << "\n// Defining program-specific local variables\n";
    Vars & locals = n->second.locVars;
    for (Vars::iterator i = locals.begin (); i != locals.end (); ++i)
    {
      Var & var = i->second;
      var->type = var->type->incrDim(-1);
      build_program_variable (var);
    }
  }

  //Create proxy variables for EXTERN functions with no arguments
  for (Funcs::iterator f = builder_.program.funcs.begin(); f != builder_.program.funcs.end (); ++f)
  {
    Func func = f->second;
    if(func->isExtern && func->params.size() == 0 && func->retType->type != TVOID)
    {
      buffer_ << "ArrayReference<" << func->retType->toString()
              << ", " << builder_.program.processes.size () << "> EXTERN_"
              << func->getName() << "(knowledge, \""
              << func->getName() << "\");\n";
    }
  }

  buffer_ << "\n";
}

void
dmpl::gams::Analyzer_Builder::build_program_variable_init (
  const Var & var)
{
  if (var->type->dims.size () <= 1)
  {
    buffer_ << get_type_name(var) << " var_init_";
    buffer_ << var->name;
    if (var->type->type == TDOUBLE_TYPE)
      buffer_ << " (0.0);\n";
    else
      buffer_ << " (0);\n";
  }
}

void
dmpl::gams::Analyzer_Builder::build_program_variable (const Var & var)
{
#if 0
  // is this an array type?
  if (var->type->dims.size () == 1)
  {
    if (var->type->type == TINT)
    {
      buffer_ << "containers::Integer_Array ";
    }
    else if (var->type->type == TDOUBLE_TYPE)
    {
      buffer_ << "containers::Double_Array ";
    }
    else
    {
      // Default to integer array
      buffer_ << "containers::Integer_Array ";
    }
  }
  // multi-dimensional array type?
  else if (var->type->dims.size () > 1)
  {
    buffer_ << "containers::Array_N ";
  }
  // non-array type
#endif

  // is this an array type?
  if (var->type->dims.size () >= 1)
  {
    buffer_ << "ArrayReference<" << get_type_name(var);
    BOOST_FOREACH(int dim, var->type->dims)
    {
      buffer_ << ", ";
      if(dim > 0)
        buffer_ << dim;
      else
        buffer_ << builder_.program.processes.size ();
    }
    buffer_ << "> ";
  }
  else
  {
    buffer_ << "Reference<" << get_type_name(var) << "> ";
  }
  buffer_ << var->name;
  buffer_ << "(knowledge, \"";
  if(var->scope == Variable::LOCAL)
    buffer_ << ".";
  buffer_ << var->name << "\")";
  buffer_ << ";\n";

  build_program_variable_init (var);
  buffer_ << "\n";
}

void
dmpl::gams::Analyzer_Builder::build_program_variables_bindings ()
{ 
  buffer_ << "  // Binding common variables\n";
  //buffer_ << "  barrier.set_name (\"mbarrier\", *knowledge, ";
  //buffer_ << builder_.program.processes.size ();
  //buffer_ << ");\n";

  //buffer_ << "  id.set_name (\".id\", knowledge);\n";
  //buffer_ << "  num_processes.set_name (\".processes\", knowledge);\n";
  buffer_ << "\n";

  Nodes & nodes = builder_.program.nodes;
  for (Nodes::iterator n = nodes.begin (); n != nodes.end (); ++n)
  {
    buffer_ << "  // Binding program-specific global variables\n";
    Vars & vars = n->second.globVars;
    for (Vars::iterator i = vars.begin (); i != vars.end (); ++i)
    {
      Var & var = i->second;
      build_program_variable_binding (var);
    }
    
    buffer_ << "\n  // Binding program-specific local variables\n";
    Vars & locals = n->second.locVars;
    for (Vars::iterator i = locals.begin (); i != locals.end (); ++i)
    {
      Var & var = i->second;
      build_program_variable_binding (var);
    }
  }

  buffer_ << "\n";
}

void
dmpl::gams::Analyzer_Builder::build_program_variable_binding (
  const Var & var)
{
#if 0
  // if scalar, already bound
  if (var->type->dims.size () > 0)
  {
    buffer_ << "  ";
    buffer_ << var->name;
    buffer_ << ".set_name (\"";

    // local variables will have a period in front of them
    if (var->scope == Variable::LOCAL)
      buffer_ << ".";

    buffer_ << var->name;
    buffer_ << "\", knowledge";

    // is this an array type?
    if (var->type->dims.size () == 1)
    {
      buffer_ << ", ";
      buffer_ << builder_.program.processes.size ();
    }

    buffer_ << ");\n";
  }
#endif

  build_program_variable_assignment (var);

  buffer_ << "\n";
}

void
dmpl::gams::Analyzer_Builder::build_program_variable_assignment (
  const Var & var)
{
  // is this a GLOBAL scalar (i.e., 1-dimensional array)?
  if (var->scope == Variable::GLOBAL && var->type->dims.size () == 1)
  {
    buffer_ << "  " << var->name;
    buffer_ << "[settings.id] = var_init_";
    buffer_ << var->name;
    buffer_ << ";\n";
  }
  else if (var->type->dims.size () == 0)
  {
    buffer_ << "  " << var->name;
    buffer_ << " = ";
    buffer_ << "var_init_";
    buffer_ << var->name;
    buffer_ << ";\n";
  }
}

void
dmpl::gams::Analyzer_Builder::build_parse_args ()
{
  std::stringstream variable_help;

  buffer_ << "template < class ContainerT >\n";
  buffer_ << "void tokenize(const std::string& str, ContainerT& tokens,\n";
  buffer_ << "              const std::string& delimiters = \" \", bool trimEmpty = false)\n";
  buffer_ << "{\n";
  buffer_ << "   std::string::size_type pos, lastPos = 0;\n";
  buffer_ << "\n";
  buffer_ << "   typedef typename ContainerT::value_type value_type;\n";
  buffer_ << "   typedef typename ContainerT::size_type size_type;\n";
  buffer_ << "\n";
  buffer_ << "   while(true)\n";
  buffer_ << "   {\n";
  buffer_ << "      pos = str.find_first_of(delimiters, lastPos);\n";
  buffer_ << "      if(pos == std::string::npos)\n";
  buffer_ << "      {\n";
  buffer_ << "         pos = str.length();\n";
  buffer_ << "\n";
  buffer_ << "         if(pos != lastPos || !trimEmpty)\n";
  buffer_ << "            tokens.push_back(value_type(str.data()+lastPos,\n";
  buffer_ << "                  (size_type)pos-lastPos ));\n";
  buffer_ << "\n";
  buffer_ << "         break;\n";
  buffer_ << "      }\n";
  buffer_ << "      else\n";
  buffer_ << "      {\n";
  buffer_ << "         if(pos != lastPos || !trimEmpty)\n";
  buffer_ << "            tokens.push_back(value_type(str.data()+lastPos,\n";
  buffer_ << "                  (size_type)pos-lastPos ));\n";
  buffer_ << "      }\n";
  buffer_ << "\n";
  buffer_ << "      lastPos = pos + 1;\n";
  buffer_ << "   }\n";
  buffer_ << "}\n";
  buffer_ << "\n";
  buffer_ << "// handle arguments from the command line\n";
  buffer_ << "void handle_arguments (int argc, char ** argv)\n";
  buffer_ << "{\n";
  buffer_ << "  for (int i = 1; i < argc; ++i)\n";
  buffer_ << "  {\n";
  buffer_ << "    std::string arg1 (argv[i]);\n";
  buffer_ << "\n";
  buffer_ << "    if (arg1 == \"-m\" || arg1 == \"--multicast\")\n";
  buffer_ << "    {\n";
  buffer_ << "      if (i + 1 < argc)\n";
  buffer_ << "      {\n";
  buffer_ << "        settings.hosts.push_back (argv[i + 1]);\n";
  buffer_ << "        settings.type = Madara::Transport::MULTICAST;\n";
  buffer_ << "      }\n";
  buffer_ << "      ++i;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"-p\" || arg1 == \"--platform\")\n";
  buffer_ << "    {\n";
  buffer_ << "      if (i + 1 < argc)\n";
  buffer_ << "      {\n";
  buffer_ << "        tokenize(std::string(argv[i + 1]), platform_params, \":\");\n";
  buffer_ << "        platform_name = (platform_params[0]);\n";
  buffer_ << "      }\n";
  buffer_ << "      ++i;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"-b\" || arg1 == \"--broadcast\")\n";
  buffer_ << "    {\n";
  buffer_ << "      if (i + 1 < argc)\n";
  buffer_ << "      {\n";
  buffer_ << "        settings.hosts.push_back (argv[i + 1]);\n";
  buffer_ << "        settings.type = Madara::Transport::BROADCAST;\n";
  buffer_ << "      }\n";
  buffer_ << "      ++i;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"-u\" || arg1 == \"--udp\")\n";
  buffer_ << "    {\n";
  buffer_ << "      if (i + 1 < argc)\n";
  buffer_ << "      {\n";
  buffer_ << "        settings.hosts.push_back (argv[i + 1]);\n";
  buffer_ << "        settings.type = Madara::Transport::UDP;\n";
  buffer_ << "      }\n";
  buffer_ << "      ++i;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"-o\" || arg1 == \"--host\")\n";
  buffer_ << "    {\n";
  buffer_ << "      if (i + 1 < argc)\n";
  buffer_ << "        host = argv[i + 1];\n";
  buffer_ << "        \n";
  buffer_ << "      ++i;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"-mb\" || arg1 == \"--max-barrier-time\")\n";
  buffer_ << "    {\n";
  buffer_ << "      if (i + 1 < argc)\n";
  buffer_ << "      {\n";
  buffer_ << "        std::stringstream buffer (argv[i + 1]);\n";
  buffer_ << "        buffer >> max_barrier_time;\n";
  buffer_ << "      }\n";
  buffer_ << "      \n";
  buffer_ << "      ++i;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"-d\" || arg1 == \"--domain\")\n";
  buffer_ << "    {\n";
  buffer_ << "      if (i + 1 < argc)\n";
  buffer_ << "        settings.domains = argv[i + 1];\n";
  buffer_ << "        \n";
  buffer_ << "      ++i;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"-i\" || arg1 == \"--id\")\n";
  buffer_ << "    {\n";
  buffer_ << "      if (i + 1 < argc)\n";
  buffer_ << "      {\n";
  buffer_ << "        std::stringstream buffer (argv[i + 1]);\n";
  buffer_ << "        buffer >> settings.id;\n";
  buffer_ << "      }\n";
  buffer_ << "      \n";
  buffer_ << "      ++i;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"-v\" || arg1 == \"--verbose\")\n";
  buffer_ << "    {\n";
  buffer_ << "      ::dmpl::verbosity++;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"-l\" || arg1 == \"--level\")\n";
  buffer_ << "    {\n";
  buffer_ << "      if (i + 1 < argc)\n";
  buffer_ << "      {\n";
  buffer_ << "        std::stringstream buffer (argv[i + 1]);\n";
  buffer_ << "        buffer >> MADARA_debug_level;\n";
  buffer_ << "      }\n";
  buffer_ << "      \n";
  buffer_ << "      ++i;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"--drop-rate\")\n";
  buffer_ << "    {\n";
  buffer_ << "      if (i + 1 < argc)\n";
  buffer_ << "      {\n";
  buffer_ << "        double drop_rate;\n";
  buffer_ << "        std::stringstream buffer (argv[i + 1]);\n";
  buffer_ << "        buffer >> drop_rate;\n";
  buffer_ << "        \n";
  buffer_ << "        settings.update_drop_rate (drop_rate,\n";
  buffer_ << "          Madara::Transport::PACKET_DROP_DETERMINISTIC);\n";
  buffer_ << "      }\n";
  buffer_ << "      \n";
  buffer_ << "      ++i;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"-e\" || arg1 == \"--expect-log\")\n";
  buffer_ << "    {\n";
  buffer_ << "      if (i + 1 < argc)\n";
  buffer_ << "      {\n";
  buffer_ << "        expect_file.open(argv[i + 1], ios::out | ios::trunc);\n";
  buffer_ << "      }\n";
  buffer_ << "      \n";
  buffer_ << "      ++i;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"-f\" || arg1 == \"--logfile\")\n";
  buffer_ << "    {\n";
  buffer_ << "      if (i + 1 < argc)\n";
  buffer_ << "      {\n";
  buffer_ << "        Madara::Knowledge_Engine::Knowledge_Base::log_to_file (argv[i + 1]);\n";
  buffer_ << "      }\n";
  buffer_ << "      \n";
  buffer_ << "      ++i;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"-r\" || arg1 == \"--reduced\")\n";
  buffer_ << "    {\n";
  buffer_ << "      settings.send_reduced_message_header = true;\n";
  buffer_ << "    }\n";
  buffer_ << "    else if (arg1 == \"--write-fd\")\n";
  buffer_ << "    {\n";
  buffer_ << "      if (i + 1 < argc)\n";
  buffer_ << "      {\n";
  buffer_ << "        std::stringstream buffer (argv[i + 1]);\n";
  buffer_ << "        buffer >> write_fd;\n";
  buffer_ << "      }\n";
  buffer_ << "      \n";
  buffer_ << "      ++i;\n";
  buffer_ << "    }\n";

  Nodes & nodes = builder_.program.nodes;
  for (Nodes::iterator n = nodes.begin (); n != nodes.end (); ++n)
  {
    buffer_ << "\n    // Providing init for global variables\n";
    Vars & vars = n->second.globVars;
    for (Vars::iterator i = vars.begin (); i != vars.end (); ++i)
    {
      Var& var = i->second;
      variable_help << build_parse_args (var);
    }
    
    buffer_ << "\n    // Providing init for local variables\n";
    Vars & locals = n->second.locVars;
    for (Vars::iterator i = locals.begin (); i != locals.end (); ++i)
    {
      Var& var = i->second;
      variable_help << build_parse_args (var);
    }
  }

  if (false)
  {
    buffer_ << "\n    // Providing init for VREP variables";
    buffer_ << "\n    else if (arg1 == \"-vq\" || arg1 == \"--vrep-quad\")";
    buffer_ << "\n    {";
    buffer_ << "\n       vrep_model = 1;";
    buffer_ << "\n    }";
    buffer_ << "\n    else if (arg1 == \"-va\" || arg1 == \"--vrep-ant\")";
    buffer_ << "\n    {";
    buffer_ << "\n       vrep_model = 2;";
    buffer_ << "\n    }";
    buffer_ << "\n    else if (arg1 == \"-vh\" || arg1 == \"--vrep-host\")";
    buffer_ << "\n    {";
    buffer_ << "\n      if (i + 1 < argc)";
    buffer_ << "\n      {";
    buffer_ << "\n        vrep_host = argv[i + 1];";
    buffer_ << "\n      }";
    buffer_ << "\n";
    buffer_ << "\n      ++i;";
    buffer_ << "\n    }";
    buffer_ << "\n    else if (arg1 == \"-vp\" || arg1 == \"--vrep-port\")";
    buffer_ << "\n    {";
    buffer_ << "\n      if (i + 1 < argc)";
    buffer_ << "\n      {";
    buffer_ << "\n        std::stringstream buffer (argv[i + 1]);";
    buffer_ << "\n        buffer >> vrep_port;";
    buffer_ << "\n      }";
    buffer_ << "\n";
    buffer_ << "\n      ++i;";
    buffer_ << "\n    }\n";
  }

  buffer_ << "    else\n";
  buffer_ << "    {\n";
  buffer_ << "      MADARA_DEBUG (MADARA_LOG_EMERGENCY, (LM_DEBUG, \n";
  buffer_ << "        \"\\nProgram summary for %s:\\n\\n\"\\\n";
  buffer_ << "        \" [-v|--verbose]           output additional information to stderr\\n\"\\\n";
  buffer_ << "        \" [-p|--platform type]     platform for loop (vrep, dronerk)\\n\"\\\n";
  buffer_ << "        \" [-b|--broadcast ip:port] the broadcast ip to send and listen to\\n\"\\\n";
  buffer_ << "        \" [-d|--domain domain]     the knowledge domain to send and listen to\\n\"\\\n";
  buffer_ << "        \" [-e|--expect-log file]   file to log variables related to 'expect' clauses\\n\"\\\n";
  buffer_ << "        \" [-f|--logfile file]      log to a file\\n\"\\\n";
  buffer_ << "        \" [-i|--id id]             the id of this agent (should be non-negative)\\n\"\\\n";
  buffer_ << "        \" [-l|--level level]       the logger level (0+, higher is higher detail)\\n\"\\\n";
  buffer_ << "        \" [-m|--multicast ip:port] the multicast ip to send and listen to\\n\"\\\n";
  buffer_ << "        \" [-mb|--max-barrier-time time] time in seconds to barrier for other processes\\n\"\\\n";
  buffer_ << "        \" [-o|--host hostname]     the hostname of this process (def:localhost)\\n\"\\\n";
  buffer_ << "        \" [-r|--reduced]           use the reduced message header\\n\"\\\n";
  buffer_ << "        \" [-u|--udp ip:port]       the udp ips to send to (first is self to bind to)\\n\"\\\n";

  buffer_ << variable_help.str ();

  if (false)
  {
    buffer_ << "        \" [-vq|--vrep-quad] use Quadricopter model in VREP (default)\\n\"\\\n";
    buffer_ << "        \" [-va|--vrep-ant] use Ant model in VREP\\n\"\\\n";
    buffer_ << "        \" [-vh|--vrep-host] sets the IP address of VREP\\n\"\\\n";
    buffer_ << "        \" [-vp|--vrep-port] sets the IP port of VREP\\n\"\\\n";
  }

  buffer_ << "        , argv[0]));\n";
  buffer_ << "      exit (0);\n";
  buffer_ << "    }\n";
  buffer_ << "  }\n";
  buffer_ << "}\n\n";
}

std::string
dmpl::gams::Analyzer_Builder::build_parse_args (const Var& var)
{
  std::stringstream return_value;
  
  // we do not allow setting multi-dimensional vars from command line
  if (var->type->dims.size () <= 1)
  {
    buffer_ << "    else if (arg1 == \"--var_";
    buffer_ << var->name;
    buffer_ << "\")\n";
    buffer_ << "    {\n";
    buffer_ << "      if (i + 1 < argc)\n";
    buffer_ << "      {\n";
    buffer_ << "        std::stringstream buffer (argv[i + 1]);\n";
    buffer_ << "        buffer >> var_init_";
    buffer_ << var->name;
    buffer_ << ";\n";
    buffer_ << "      }\n";
    buffer_ << "      \n";
    buffer_ << "      ++i;\n";
    buffer_ << "    }\n";

    // build the help string
    return_value << "        \" [--var_";
    return_value << var->name;
    return_value << "] sets the initial value of a generated variable\\n\"\\\n";
  }

  return return_value.str ();
}

void
dmpl::gams::Analyzer_Builder::build_functions_declarations ()
{
  buffer_ << "// Forward declaring global functions\n\n";
  Funcs & funcs = builder_.program.funcs;
  for (Funcs::iterator i = funcs.begin (); i != funcs.end (); ++i)
  {
    build_function_declaration (Node (), i->second);
  }
  
  buffer_ << "\n// Forward declaring node functions\n\n";
  Nodes & nodes = builder_.program.nodes;
  buffer_ << "// Nodes: " << builder_.program.nodes.size() << std::endl;
  for (Nodes::iterator n = nodes.begin (); n != nodes.end (); ++n)
  {
    Funcs & funcs = n->second.funcs;
    buffer_ << "// Funcs: " << funcs.size() << std::endl;
    for (Funcs::iterator i = funcs.begin (); i != funcs.end (); ++i)
    {
      build_function_declaration (n->second, i->second);
    }
  }

  buffer_ << "\n";
}

void
dmpl::gams::Analyzer_Builder::build_functions (void)
{
  buffer_ << "// Defining global functions\n\n";
  Funcs & funcs = builder_.program.funcs;
  for (Funcs::iterator i = funcs.begin (); i != funcs.end (); ++i)
  {
    build_function (Node (), i->second);
  }

  buffer_ << "// Defining node functions\n\n";
  Nodes & nodes = builder_.program.nodes;
  for (Nodes::iterator n = nodes.begin (); n != nodes.end (); ++n)
  {
    Funcs & funcs = n->second.funcs;
    for (Funcs::iterator i = funcs.begin (); i != funcs.end (); ++i)
    {
      build_function (n->second, i->second);
    }
  }

  buffer_ << "\n";
}

void
dmpl::gams::Analyzer_Builder::build_function_declaration (
  const dmpl::Node & node, dmpl::Func & function)
{
  if (function->isExtern || function->attrs.count("INIT") > 0 || function->attrs.count("SAFETY") > 0 ||
      !function->usage_summary.anyExpect().any())
    return;

  buffer_ << "Madara::Knowledge_Record\n";
  buffer_ << node.name << "_" << function->name;
  buffer_ << " (engine::Function_Arguments & args, engine::Variables & vars);\n";
}

void
dmpl::gams::Analyzer_Builder::build_function (
  const dmpl::Node & node, dmpl::Func & function)
{
  if (function->isExtern || function->attrs.count("INIT") > 0 || function->attrs.count("SAFETY") > 0 ||
      !function->usage_summary.anyExpect().any())
    return;

  BOOST_FOREACH (Attributes::value_type & attr, function->attrs)
  {
    buffer_ << "// @" << attr.second.name;
    BOOST_FOREACH (Expr p, attr.second.paramList)
    {
      buffer_ << " " << p->toString();
    }
    buffer_ << "\n";
  }

  buffer_ << "Madara::Knowledge_Record\n";
  buffer_ << node.name << "_" << function->name;
  buffer_ << " (engine::Function_Arguments & args, engine::Variables & vars)\n";
  buffer_ << "{\n";
  buffer_ << "  // Declare local variables\n";
  
  //buffer_ << "  Integer result (0);\n";
  int i = 0;
  BOOST_FOREACH (Vars::value_type & variable, function->paramSet)
  {
    buffer_ << "  " << get_type_name(variable.second) << " ";
    buffer_ << variable.second->name;
    buffer_ << " = args[" << i << "].to_double();\n";
    buffer_ << ";\n";
    ++i;
  }
  BOOST_FOREACH (Vars::value_type & variable, function->temps)
  {
    buffer_ << "  " << get_type_name(variable.second);
    buffer_ << " " << variable.second->name;
    buffer_ << ";\n";
  }
  
  buffer_ << "\n";

  dmpl::madara::Function_Visitor visitor (function, node, builder_, buffer_, false, true);

  //transform the body of safety
  BOOST_FOREACH (const Stmt & statement, function->body)
  {
    visitor.visit (statement);
  }

  buffer_ << "\n  // Insert return statement, in case user program did not\n";
  buffer_ << "  return Integer(0);\n";
  buffer_ << "}\n\n";
}

void
dmpl::gams::Analyzer_Builder::build_main_function ()
{
  buffer_ << "int main (int argc, char ** argv)\n";
  buffer_ << "{\n";
  buffer_ << "  // handle any command line arguments\n";
  buffer_ << "  handle_arguments (argc, argv);\n";
  buffer_ << "\n";

  Node &node = builder_.program.nodes.begin()->second;

  buffer_ << "  // NODE: " << node.name << "\n";
  BOOST_FOREACH (Attributes::value_type & attr, node.attrs)
    {
      buffer_ << "  // @" << attr.second.name;
      BOOST_FOREACH (Expr p, attr.second.paramList)
        {
          buffer_ << " " << p->toString();
        }
      buffer_ << "\n";
    }


  build_program_variables_bindings ();
  build_main_define_functions ();

  // set the values for id and processes
  buffer_ << "  // Initialize commonly used local variables\n";  
  buffer_ << "  num_processes = processes;\n";

  buffer_ << "\n";
  buffer_ << "  LogAnalyzer analyzer(std::cin, knowledge);\n";

  buffer_ << "  std::cout << \"Time,Name,Node,Value\" << std::endl;\n";
  buffer_ << "  for(;;) {\n";
  buffer_ << "    bool done = !analyzer.next_step();\n";
  
  StmtList &stmts = node.stmts;
  BOOST_FOREACH(Stmt stmt, stmts)
  {
    CondStmt *cond = dynamic_cast<CondStmt*>(stmt.get());
    if(cond->kind == "expect")
    {
      Attribute *attrAtEnd = cond->getAttribute("AtEnd", 0);
      Attribute *attrAtLeast = cond->getAttribute("AtLeast", 1);
      Attribute *attrAtNode = cond->getAttribute("AtNode", 1);
      if (attrAtNode)
      {
        buffer_ << "    {" << std::endl;
        buffer_ << "      " << node.idVar->getName() << " = " << attrAtNode->paramList.front()->requireInt() << ";" << std::endl;
        buffer_ << "      int n = " << node.idVar->getName() << ";" << std::endl;
      }
      else
      {
        buffer_ << "    for(int n = 0; n < processes; n++) {" << std::endl;

        buffer_ << "      " << node.idVar->getName() << " = n;" << std::endl;
      }
      buffer_ << "      engine::Variables vars;" << std::endl;
      buffer_ << "      bool value = (";
      dmpl::madara::Function_Visitor visitor (stmt, node, builder_, buffer_, false, true);
      visitor.visit(cond->cond);
      buffer_ << ");" << std::endl;

      if (attrAtEnd)
      {
        buffer_ << "      knowledge.set(\"AtEnd_RESULT.\"+to_string(n)+\"." << cond->name << "\", Integer(value?1:0));\n";
      }
      else if (attrAtLeast)
      {
        buffer_ << "      int total_so_far = knowledge.get(\"AtLeast_TOTAL.\"+to_string(n)+\"." << cond->name << "\").to_integer();\n";
        buffer_ << "      int count_so_far = knowledge.get(\"AtLeast_COUNT.\"+to_string(n)+\"." << cond->name << "\").to_integer();\n";
        buffer_ << "      knowledge.set(\"AtLeast_TOTAL.\"+to_string(n)+\"." << cond->name << "\", total_so_far + Integer(value?1:0));\n";
        buffer_ << "      knowledge.set(\"AtLeast_COUNT.\"+to_string(n)+\"." << cond->name << "\", Integer(count_so_far + 1));\n";
      }
      else
      {
        buffer_ << "      std::cout << analyzer.get_cur_frame() << \"," << cond->name << ",\" << ";
        buffer_ << "n";
        buffer_ << " << \",\" << value << std::endl;" << std::endl;
      }

      buffer_ << "    }" << std::endl;
    }
  }

  buffer_ << "    if(done) break;\n";
  buffer_ << "  }\n";
  BOOST_FOREACH(Stmt stmt, stmts)
  {
    CondStmt *cond = dynamic_cast<CondStmt*>(stmt.get());
    if(cond->kind == "expect")
    {
      Attribute *attrAtNode = cond->getAttribute("AtNode", 1);
      Attribute *attrAtEnd = cond->getAttribute("AtEnd", 0);
      Attribute *attrAtLeast = cond->getAttribute("AtLeast", 1);
      if(attrAtEnd)
      {
        if (attrAtNode)
          buffer_ << "  { int n = " << node.idVar->getName() << ";" << std::endl;
        else
          buffer_ << "  for(int n = 0; n < processes; n++) {" << std::endl;
        buffer_ << "    bool value = knowledge.get(\"AtEnd_RESULT.\"+to_string(n)+\"." << cond->name << "\").to_integer() == 1;\n";
        buffer_ << "    std::cout << \"AtEnd," << cond->name << ",\" << n << \",\" << value << std::endl;" << std::endl;
        buffer_ << "  }\n";
      }
      else if(attrAtLeast)
      {
        if (attrAtNode)
          buffer_ << "  { int n = " << node.idVar->getName() << ";" << std::endl;
        else
          buffer_ << "  for(int n = 0; n < processes; n++) {" << std::endl;
        buffer_ << "    double total = knowledge.get(\"AtLeast_TOTAL.\"+to_string(n)+\"." << cond->name << "\").to_double();\n";
        buffer_ << "    double count = knowledge.get(\"AtLeast_COUNT.\"+to_string(n)+\"." << cond->name << "\").to_double();\n";
        buffer_ << "    bool value = (total / count) >= " << attrAtLeast->paramList.front()->requireDouble() << ";\n";
        buffer_ << "    std::cout << \"AtLeast," << cond->name << ",\" << n << \",\" << value << std::endl;" << std::endl;
        buffer_ << "  }\n";
      }
    }
  }

  buffer_ << "  return 0;\n";
  buffer_ << "}\n";
}

void
dmpl::gams::Analyzer_Builder::build_main_define_functions ()
{
  buffer_ << "  // Defining common functions\n\n";

  buffer_ << "  // Defining global functions for MADARA\n\n";
  Funcs & funcs = builder_.program.funcs;
  for (Funcs::iterator i = funcs.begin (); i != funcs.end (); ++i)
    {
      build_main_define_function (Node (), i->second);
    }
  
  buffer_ << "\n";

  buffer_ << "  // Defining node functions for MADARA\n\n";
  Nodes & nodes = builder_.program.nodes;
  for (Nodes::iterator n = nodes.begin (); n != nodes.end (); ++n)
    {
      Funcs & funcs = n->second.funcs;
      for (Funcs::iterator i = funcs.begin (); i != funcs.end (); ++i)
        {
          build_main_define_function (n->second, i->second);
        }
    }

}


void
dmpl::gams::Analyzer_Builder::build_main_define_function (const Node & node,
                                                      Func & function)
{
  if (!(function->isExtern || function->attrs.count("INIT") > 0 || function->attrs.count("SAFETY") > 0 ||
        !function->usage_summary.anyExpect().any()))
    {
      buffer_ << "  knowledge.define_function (\"";
      buffer_ << function->name;
      buffer_ << "\", ";
      buffer_ << node.name << "_" << function->name;
      buffer_ << ");\n";
    }
}

void
dmpl::gams::Analyzer_Builder::clear_buffer ()
{
  buffer_.str ("");
}

void
dmpl::gams::Analyzer_Builder::print (std::ostream & os)
{
  os << buffer_.str ();
}

void
dmpl::gams::Analyzer_Builder::open_dmpl_namespace ()
{
  buffer_ << "// begin dmpl namespace\n";
  buffer_ << "namespace dmpl\n";
  buffer_ << "{\n";
}

void
dmpl::gams::Analyzer_Builder::close_dmpl_namespace ()
{
  buffer_ << "} // end dmpl namespace\n";
  buffer_ << "\n";
}