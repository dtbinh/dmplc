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


//a class for sequentializing DMPL into a C program

#ifndef __COPY_VISITOR_HPP__
#define __COPY_VISITOR_HPP__

#include <iostream>
#include "dmpl/CProgram.h"
#include "dmpl/Visitor.h"

namespace dmpl {

  /*******************************************************************/
  //a visitor that simply creates a copy
  /*******************************************************************/
  struct CopyVisitor : public Visitor
  {
    //map from expressions to the result of transforming them
    std::map<Expr,Expr> exprMap;

    //map from statements to the result of transforming them
    std::map<Stmt,Stmt> stmtMap;

    //constructors
    CopyVisitor() {} 

    //collect results
    ExprList collect(const ExprList &el);
    StmtList collect(const StmtList &sl);

    //dispatchers
    void exitInt(IntExpr &expr);
    void exitDouble(DoubleExpr &expr);
    void exitLval(LvalExpr &expr);
    void exitComp(CompExpr &expr);
    void exitCall(CallExpr &expr);
    void exitEXO(EXOExpr &expr);
    void exitEXH(EXHExpr &expr);
    void exitEXL(EXLExpr &expr);
    void exitPrivate(PrivateStmt &stmt);
    void exitBlock(BlockStmt &stmt);
    void exitAsgn(AsgnStmt &stmt);
    void exitCond(CondStmt &stmt);
    void exitFor(ForStmt &stmt);
    void exitWhile(WhileStmt &stmt);
    void exitBreak(BreakStmt &stmt);
    void exitCont(ContStmt &stmt);
    void exitRet(RetStmt &stmt);
    void exitRetVoid(RetVoidStmt &stmt);
    void exitCall(CallStmt &stmt);
    void exitFAN(FANStmt &stmt);
    void exitFADNP(FADNPStmt &stmt);
    void exitFAO(FAOStmt &stmt);
    void exitFAOL(FAOLStmt &stmt);
    void exitFAOH(FAOHStmt &stmt);
  };
} //namespace dmpl

#endif //__COPY_VISITOR_HPP__
