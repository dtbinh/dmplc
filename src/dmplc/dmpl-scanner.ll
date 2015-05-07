%{
#include <string>
#include <map>
#include "dmpl/Type.h"
#include "dmpl/Expression.h"
#include "dmpl/Statement.h"
#include "DmplBuilder.hpp"
#include "dmpl-parser.hpp"
extern dmpl::DmplBuilder *builder; /* the dag builder */
#define PRINT_TOKEN if(builder->debug) printf("%s\n",yytext)
#define SAVE_TOKEN PRINT_TOKEN; yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
extern std::string thunk;
extern "C" int yywrap() { return 1; }
%}

%x IN_COMMENT IN_THUNK

%%
"/*"             { BEGIN(IN_COMMENT); }
<IN_COMMENT>"*/" { BEGIN(INITIAL); }
<IN_COMMENT>\n   { }
<IN_COMMENT>.    { }
"%%{"            { thunk.clear(); BEGIN(IN_THUNK); }
<IN_THUNK>"%%}"  { BEGIN(INITIAL); return TOKEN(TTHUNK); }
<IN_THUNK>\n     { 
                   thunk.push_back(yytext[0]); 
                   if(builder->debug) printf("thunk = {%s}\n",thunk.c_str());
                 }
<IN_THUNK>.      { 
                   thunk.push_back(yytext[0]);
                   if(builder->debug) printf("thunk = {%s}\n",thunk.c_str());
                 }
[ \t\n]                     ;
"CONST"                     PRINT_TOKEN; return TOKEN(TCONST);
"const"                     PRINT_TOKEN; return TOKEN(TCONST);
"NODE"                      PRINT_TOKEN; return TOKEN(TNODE);
"node"                      PRINT_TOKEN; return TOKEN(TNODE);
"GLOBAL"                    PRINT_TOKEN; return TOKEN(TGLOBAL);
"global"                    PRINT_TOKEN; return TOKEN(TGLOBAL);
"LOCAL"                     PRINT_TOKEN; return TOKEN(TLOCAL);
"local"                     PRINT_TOKEN; return TOKEN(TLOCAL);
"TARGET"                    PRINT_TOKEN; return TOKEN(TTARGET);
"target"                    PRINT_TOKEN; return TOKEN(TTARGET);
"_Bool"                     PRINT_TOKEN; return TOKEN(TBOOL);
"bool"                      PRINT_TOKEN; return TOKEN(TBOOL);
"int"                       PRINT_TOKEN; return TOKEN(TINT);
"double"                    PRINT_TOKEN; return TOKEN(TDOUBLE_TYPE);
"void"                      PRINT_TOKEN; return TOKEN(TVOID);
"char"                      PRINT_TOKEN; return TOKEN(TCHAR);
"signed"                    PRINT_TOKEN; return TOKEN(TSIGNED);
"unsigned"                  PRINT_TOKEN; return TOKEN(TUNSIGNED);
"#N"                        PRINT_TOKEN; return TOKEN(TNODENUM);
"EXTERN"                    PRINT_TOKEN; return TOKEN(TEXTERN);
"extern"                    PRINT_TOKEN; return TOKEN(TEXTERN);
"PURE"                      PRINT_TOKEN; return TOKEN(TPURE);
"pure"                      PRINT_TOKEN; return TOKEN(TPURE);
"THREAD"                    PRINT_TOKEN; return TOKEN(TTHREAD);
"thread"                    PRINT_TOKEN; return TOKEN(TTHREAD);
"if"                        SAVE_TOKEN; return TIF;
"require"                   SAVE_TOKEN; return TREQUIRE;
"expect"                    SAVE_TOKEN; return TEXPECT;
"else"                      PRINT_TOKEN; return TOKEN(TELSE);
"for"                       PRINT_TOKEN; return TOKEN(TFOR);
"while"                     PRINT_TOKEN; return TOKEN(TWHILE);
"break"                     PRINT_TOKEN; return TOKEN(TBREAK);
"continue"                  PRINT_TOKEN; return TOKEN(TCONTINUE);
"return"                    PRINT_TOKEN; return TOKEN(TRETURN);
"EXISTS_OTHER"              PRINT_TOKEN; return TOKEN(TEXO);
"EXISTS_HIGHER"             PRINT_TOKEN; return TOKEN(TEXH);
"EXISTS_LOWER"              PRINT_TOKEN; return TOKEN(TEXL);
"exists_other"              PRINT_TOKEN; return TOKEN(TEXO);
"exists_higher"             PRINT_TOKEN; return TOKEN(TEXH);
"exists_lower"              PRINT_TOKEN; return TOKEN(TEXL);
  /*"PROGRAM"                   PRINT_TOKEN; return TOKEN(TPROGRAM); */
  /*"INIT"                      PRINT_TOKEN; return TOKEN(TINIT); */
  /*"SAFETY"                    PRINT_TOKEN; return TOKEN(TSAFETY); */
"FORALL_NODE"               PRINT_TOKEN; return TOKEN(TFAN);
"FORALL_DISTINCT_NODE_PAIR" PRINT_TOKEN; return TOKEN(TFADNP);
"FORALL_OTHER"              PRINT_TOKEN; return TOKEN(TFAO);
"FORALL_OTHER_LOWER"        PRINT_TOKEN; return TOKEN(TFAOL);
"FORALL_OTHER_HIGHER"       PRINT_TOKEN; return TOKEN(TFAOH);
"forall_node"               PRINT_TOKEN; return TOKEN(TFAN);
"forall_distinct_node_pair" PRINT_TOKEN; return TOKEN(TFADNP);
"forall_other"              PRINT_TOKEN; return TOKEN(TFAO);
"forall_other_lower"        PRINT_TOKEN; return TOKEN(TFAOL);
"forall_other_higher"       PRINT_TOKEN; return TOKEN(TFAOH);
  /*"@TRACK_LOCATIONS"          PRINT_TOKEN; return TOKEN(TTRACK_LOCATIONS);
    "@SEND_HEARTBEATS"          PRINT_TOKEN; return TOKEN(TSEND_HEARTBEATS);
    "@ON_PRE_ROUND_BARRIER_TIMEOUT"  PRINT_TOKEN; return TOKEN(TON_PRE_TIMEOUT);
    "@ON_POST_ROUND_BARRIER_TIMEOUT" PRINT_TOKEN; return TOKEN(TON_POST_TIMEOUT);
    "@ON_RECEIVE_FILTER"        PRINT_TOKEN; return TOKEN(TON_RECV_FILTER); */
"NAN"                       SAVE_TOKEN; return TDOUBLE;
-?[0-9]+\.[0-9]*            SAVE_TOKEN; return TDOUBLE;
-?[0-9]+                    SAVE_TOKEN; return TINTEGER;
  /*"NODE_INIT"                 PRINT_TOKEN; return TOKEN(TNODE_INIT); */
  /* [a-zA-Z_][a-zA-Z0-9_]*(::[a-zA-Z_][a-zA-Z0-9_]*)+  SAVE_TOKEN; return TNAMESPACE; */
[a-zA-Z_][a-zA-Z0-9_]*  {
                          /** substitute constant definitions */
                          /*std::map<std::string,std::string>::const_iterator it = 
                            builder->program.constDef.find(std::string(yytext));
                          if(it == builder->program.constDef.end()) {*/
                            SAVE_TOKEN; return TIDENTIFIER;
                          /*}
                          yylval.string = new std::string(it->second);
                          if(builder->debug) printf("%s\n",yylval.string->c_str());
                          return TINTEGER;*/
                        }
"@"                     PRINT_TOKEN; return TOKEN(TAT);
@[a-zA-Z_][a-zA-Z0-9_]* SAVE_TOKEN; return TATTRIBUTE;
"="                     PRINT_TOKEN; return TOKEN(TEQUAL);
"=="                    PRINT_TOKEN; return TOKEN(TCEQ);
"!="                    PRINT_TOKEN; return TOKEN(TCNE);
"<"                     PRINT_TOKEN; return TOKEN(TCLT);
"<="                    PRINT_TOKEN; return TOKEN(TCLE);
">"                     PRINT_TOKEN; return TOKEN(TCGT);
">="                    PRINT_TOKEN; return TOKEN(TCGE);
"&&"                    PRINT_TOKEN; return TOKEN(TLAND);
"||"                    PRINT_TOKEN; return TOKEN(TLOR);
"!"                     PRINT_TOKEN; return TOKEN(TLNOT);
"?"                     PRINT_TOKEN; return TOKEN(TQUEST);
":"                     PRINT_TOKEN; return TOKEN(TCOLON);
"("                     PRINT_TOKEN; return TOKEN(TLPAREN);
")"                     PRINT_TOKEN; return TOKEN(TRPAREN);
"{"                     PRINT_TOKEN; return TOKEN(TLBRACE);
"}"                     PRINT_TOKEN; return TOKEN(TRBRACE);
"["                     PRINT_TOKEN; return TOKEN(TLBRACKET);
"]"                     PRINT_TOKEN; return TOKEN(TRBRACKET);
"."                     PRINT_TOKEN; return TOKEN(TDOT);
","                     PRINT_TOKEN; return TOKEN(TCOMMA);
"+"                     PRINT_TOKEN; return TOKEN(TPLUS);
"-"                     PRINT_TOKEN; return TOKEN(TMINUS);
"*"                     PRINT_TOKEN; return TOKEN(TMUL);
"/"                     PRINT_TOKEN; return TOKEN(TDIV);
"%"                     PRINT_TOKEN; return TOKEN(TMOD);
"~"                     PRINT_TOKEN; return TOKEN(TBWNOT);
"&"                     PRINT_TOKEN; return TOKEN(TBWAND);
"|"                     PRINT_TOKEN; return TOKEN(TBWOR);
"^"                     PRINT_TOKEN; return TOKEN(TBWXOR);
"<<"                    PRINT_TOKEN; return TOKEN(TBWLSH);
">>"                    PRINT_TOKEN; return TOKEN(TBWRSH);
";"                     PRINT_TOKEN; return TOKEN(TSEMICOLON);
"//".*\n
.                       printf("Unknown token <%s>!\n",yytext); yyterminate();

%%