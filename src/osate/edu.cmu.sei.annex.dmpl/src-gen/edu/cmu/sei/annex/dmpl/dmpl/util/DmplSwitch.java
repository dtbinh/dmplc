/**
 */
package edu.cmu.sei.annex.dmpl.dmpl.util;

import edu.cmu.sei.annex.dmpl.dmpl.*;

import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EPackage;

import org.eclipse.emf.ecore.util.Switch;

import org.osate.aadl2.AnnexSubclause;
import org.osate.aadl2.Element;
import org.osate.aadl2.ModalElement;
import org.osate.aadl2.NamedElement;

/**
 * <!-- begin-user-doc -->
 * The <b>Switch</b> for the model's inheritance hierarchy.
 * It supports the call {@link #doSwitch(EObject) doSwitch(object)}
 * to invoke the <code>caseXXX</code> method for each class of the model,
 * starting with the actual class of the object
 * and proceeding up the inheritance hierarchy
 * until a non-null result is returned,
 * which is the result of the switch.
 * <!-- end-user-doc -->
 * @see edu.cmu.sei.annex.dmpl.dmpl.DmplPackage
 * @generated
 */
public class DmplSwitch<T> extends Switch<T>
{
  /**
   * The cached model package
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @generated
   */
  protected static DmplPackage modelPackage;

  /**
   * Creates an instance of the switch.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @generated
   */
  public DmplSwitch()
  {
    if (modelPackage == null)
    {
      modelPackage = DmplPackage.eINSTANCE;
    }
  }

  /**
   * Checks whether this is a switch for the given package.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @param ePackage the package in question.
   * @return whether this is a switch for the given package.
   * @generated
   */
  @Override
  protected boolean isSwitchFor(EPackage ePackage)
  {
    return ePackage == modelPackage;
  }

  /**
   * Calls <code>caseXXX</code> for each class of the model until one returns a non null result; it yields that result.
   * <!-- begin-user-doc -->
   * <!-- end-user-doc -->
   * @return the first non-null result returned by a <code>caseXXX</code> call.
   * @generated
   */
  @Override
  protected T doSwitch(int classifierID, EObject theEObject)
  {
    switch (classifierID)
    {
      case DmplPackage.PROGRAM:
      {
        Program program = (Program)theEObject;
        T result = caseProgram(program);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.DMPL_SUBCLAUSE:
      {
        DmplSubclause dmplSubclause = (DmplSubclause)theEObject;
        T result = caseDmplSubclause(dmplSubclause);
        if (result == null) result = caseAnnexSubclause(dmplSubclause);
        if (result == null) result = caseModalElement(dmplSubclause);
        if (result == null) result = caseNamedElement(dmplSubclause);
        if (result == null) result = caseElement(dmplSubclause);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.PROGRAM_ELEMENT:
      {
        ProgramElement programElement = (ProgramElement)theEObject;
        T result = caseProgramElement(programElement);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.PROGRAM_ELEMENT_NO_TARGET:
      {
        ProgramElementNoTarget programElementNoTarget = (ProgramElementNoTarget)theEObject;
        T result = caseProgramElementNoTarget(programElementNoTarget);
        if (result == null) result = caseProgramElement(programElementNoTarget);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.ATTRIBUTABLE_NODE_OR_PROCEDURE:
      {
        AttributableNodeOrProcedure attributableNodeOrProcedure = (AttributableNodeOrProcedure)theEObject;
        T result = caseAttributableNodeOrProcedure(attributableNodeOrProcedure);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.NUMBER_CONST:
      {
        NumberConst numberConst = (NumberConst)theEObject;
        T result = caseNumberConst(numberConst);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.DOUBLE_CONST:
      {
        DoubleConst doubleConst = (DoubleConst)theEObject;
        T result = caseDoubleConst(doubleConst);
        if (result == null) result = caseNumberConst(doubleConst);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.SPECIFICATION:
      {
        Specification specification = (Specification)theEObject;
        T result = caseSpecification(specification);
        if (result == null) result = caseAttributableElement(specification);
        if (result == null) result = caseAttributableNoRoleElement(specification);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.NODE_BODY_ELEMENT:
      {
        NodeBodyElement nodeBodyElement = (NodeBodyElement)theEObject;
        T result = caseNodeBodyElement(nodeBodyElement);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.ATTRIBUTABLE_ELEMENT:
      {
        AttributableElement attributableElement = (AttributableElement)theEObject;
        T result = caseAttributableElement(attributableElement);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.ROLE_BODY_ELEMENT:
      {
        RoleBodyElement roleBodyElement = (RoleBodyElement)theEObject;
        T result = caseRoleBodyElement(roleBodyElement);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.ATTRIBUTABLE_NO_ROLE_ELEMENT:
      {
        AttributableNoRoleElement attributableNoRoleElement = (AttributableNoRoleElement)theEObject;
        T result = caseAttributableNoRoleElement(attributableNoRoleElement);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.VAR_BLOCK:
      {
        VarBlock varBlock = (VarBlock)theEObject;
        T result = caseVarBlock(varBlock);
        if (result == null) result = caseNodeBodyElement(varBlock);
        if (result == null) result = caseRoleBodyElement(varBlock);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.RECORD_BLOCK:
      {
        RecordBlock recordBlock = (RecordBlock)theEObject;
        T result = caseRecordBlock(recordBlock);
        if (result == null) result = caseNodeBodyElement(recordBlock);
        if (result == null) result = caseRoleBodyElement(recordBlock);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.NODE_VAR_INIT:
      {
        NodeVarInit nodeVarInit = (NodeVarInit)theEObject;
        T result = caseNodeVarInit(nodeVarInit);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.VAR_INIT:
      {
        VarInit varInit = (VarInit)theEObject;
        T result = caseVarInit(varInit);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.VAR_ASGN:
      {
        VarAsgn varAsgn = (VarAsgn)theEObject;
        T result = caseVarAsgn(varAsgn);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.VAR:
      {
        Var var = (Var)theEObject;
        T result = caseVar(var);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.DIMENSION:
      {
        Dimension dimension = (Dimension)theEObject;
        T result = caseDimension(dimension);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.TYPE:
      {
        Type type = (Type)theEObject;
        T result = caseType(type);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.PROCEDURE:
      {
        Procedure procedure = (Procedure)theEObject;
        T result = caseProcedure(procedure);
        if (result == null) result = caseAttributableNodeOrProcedure(procedure);
        if (result == null) result = caseAttributableElement(procedure);
        if (result == null) result = caseAttributableNoRoleElement(procedure);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.FN_BODY:
      {
        FnBody fnBody = (FnBody)theEObject;
        T result = caseFnBody(fnBody);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.ATTR:
      {
        Attr attr = (Attr)theEObject;
        T result = caseAttr(attr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.PARAM:
      {
        Param param = (Param)theEObject;
        T result = caseParam(param);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.STMT:
      {
        Stmt stmt = (Stmt)theEObject;
        T result = caseStmt(stmt);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.ASSIGNMENT_STMT:
      {
        AssignmentStmt assignmentStmt = (AssignmentStmt)theEObject;
        T result = caseAssignmentStmt(assignmentStmt);
        if (result == null) result = caseStmt(assignmentStmt);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.LVAL:
      {
        LVal lVal = (LVal)theEObject;
        T result = caseLVal(lVal);
        if (result == null) result = caseExpr(lVal);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.EXPR:
      {
        Expr expr = (Expr)theEObject;
        T result = caseExpr(expr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.CALL_EXPR:
      {
        CallExpr callExpr = (CallExpr)theEObject;
        T result = caseCallExpr(callExpr);
        if (result == null) result = caseStmt(callExpr);
        if (result == null) result = caseExpr(callExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.TARGET:
      {
        Target target = (Target)theEObject;
        T result = caseTarget(target);
        if (result == null) result = caseProgramElement(target);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.CONSTANT:
      {
        Constant constant = (Constant)theEObject;
        T result = caseConstant(constant);
        if (result == null) result = caseProgramElementNoTarget(constant);
        if (result == null) result = caseProgramElement(constant);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.ATTRIBUTABLE_PROGRAM_ELEMENT:
      {
        AttributableProgramElement attributableProgramElement = (AttributableProgramElement)theEObject;
        T result = caseAttributableProgramElement(attributableProgramElement);
        if (result == null) result = caseProgramElementNoTarget(attributableProgramElement);
        if (result == null) result = caseProgramElement(attributableProgramElement);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.NODE:
      {
        Node node = (Node)theEObject;
        T result = caseNode(node);
        if (result == null) result = caseAttributableNodeOrProcedure(node);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.INT_CONST:
      {
        IntConst intConst = (IntConst)theEObject;
        T result = caseIntConst(intConst);
        if (result == null) result = caseNumberConst(intConst);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.AT_END_SPEC:
      {
        AtEndSpec atEndSpec = (AtEndSpec)theEObject;
        T result = caseAtEndSpec(atEndSpec);
        if (result == null) result = caseSpecification(atEndSpec);
        if (result == null) result = caseAttributableElement(atEndSpec);
        if (result == null) result = caseAttributableNoRoleElement(atEndSpec);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.AT_LEAST_SPEC:
      {
        AtLeastSpec atLeastSpec = (AtLeastSpec)theEObject;
        T result = caseAtLeastSpec(atLeastSpec);
        if (result == null) result = caseSpecification(atLeastSpec);
        if (result == null) result = caseAttributableElement(atLeastSpec);
        if (result == null) result = caseAttributableNoRoleElement(atLeastSpec);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.REQUIRE_SPEC:
      {
        RequireSpec requireSpec = (RequireSpec)theEObject;
        T result = caseRequireSpec(requireSpec);
        if (result == null) result = caseSpecification(requireSpec);
        if (result == null) result = caseAttributableElement(requireSpec);
        if (result == null) result = caseAttributableNoRoleElement(requireSpec);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.ATTRIBUTABLE:
      {
        Attributable attributable = (Attributable)theEObject;
        T result = caseAttributable(attributable);
        if (result == null) result = caseNodeBodyElement(attributable);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.SIMPLE_ROLE:
      {
        SimpleRole simpleRole = (SimpleRole)theEObject;
        T result = caseSimpleRole(simpleRole);
        if (result == null) result = caseAttributableElement(simpleRole);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.ID_ROLE:
      {
        IdRole idRole = (IdRole)theEObject;
        T result = caseIdRole(idRole);
        if (result == null) result = caseAttributableElement(idRole);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.ATTRIBUTABLE_NO_ROLE:
      {
        AttributableNoRole attributableNoRole = (AttributableNoRole)theEObject;
        T result = caseAttributableNoRole(attributableNoRole);
        if (result == null) result = caseRoleBodyElement(attributableNoRole);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.EXPR_VAR_ASGN:
      {
        ExprVarAsgn exprVarAsgn = (ExprVarAsgn)theEObject;
        T result = caseExprVarAsgn(exprVarAsgn);
        if (result == null) result = caseVarAsgn(exprVarAsgn);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.FN_VAR_ASGN:
      {
        FnVarAsgn fnVarAsgn = (FnVarAsgn)theEObject;
        T result = caseFnVarAsgn(fnVarAsgn);
        if (result == null) result = caseVarAsgn(fnVarAsgn);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.INT_DIMENSION:
      {
        IntDimension intDimension = (IntDimension)theEObject;
        T result = caseIntDimension(intDimension);
        if (result == null) result = caseDimension(intDimension);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.NODE_NUM_DIMENSION:
      {
        NodeNumDimension nodeNumDimension = (NodeNumDimension)theEObject;
        T result = caseNodeNumDimension(nodeNumDimension);
        if (result == null) result = caseDimension(nodeNumDimension);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.ID_DIMENSION:
      {
        IdDimension idDimension = (IdDimension)theEObject;
        T result = caseIdDimension(idDimension);
        if (result == null) result = caseDimension(idDimension);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.THREAD_DECLARATION:
      {
        ThreadDeclaration threadDeclaration = (ThreadDeclaration)theEObject;
        T result = caseThreadDeclaration(threadDeclaration);
        if (result == null) result = caseProcedure(threadDeclaration);
        if (result == null) result = caseAttributableNodeOrProcedure(threadDeclaration);
        if (result == null) result = caseAttributableElement(threadDeclaration);
        if (result == null) result = caseAttributableNoRoleElement(threadDeclaration);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.FUNCTION_DECLARATION:
      {
        FunctionDeclaration functionDeclaration = (FunctionDeclaration)theEObject;
        T result = caseFunctionDeclaration(functionDeclaration);
        if (result == null) result = caseProcedure(functionDeclaration);
        if (result == null) result = caseAttributableNodeOrProcedure(functionDeclaration);
        if (result == null) result = caseAttributableElement(functionDeclaration);
        if (result == null) result = caseAttributableNoRoleElement(functionDeclaration);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.NESTED_STMT:
      {
        NestedStmt nestedStmt = (NestedStmt)theEObject;
        T result = caseNestedStmt(nestedStmt);
        if (result == null) result = caseStmt(nestedStmt);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.WHILE_STMT:
      {
        WhileStmt whileStmt = (WhileStmt)theEObject;
        T result = caseWhileStmt(whileStmt);
        if (result == null) result = caseStmt(whileStmt);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.FOR_STMT:
      {
        ForStmt forStmt = (ForStmt)theEObject;
        T result = caseForStmt(forStmt);
        if (result == null) result = caseStmt(forStmt);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.COND_STMT:
      {
        CondStmt condStmt = (CondStmt)theEObject;
        T result = caseCondStmt(condStmt);
        if (result == null) result = caseStmt(condStmt);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.SIMPLE_STMT:
      {
        SimpleStmt simpleStmt = (SimpleStmt)theEObject;
        T result = caseSimpleStmt(simpleStmt);
        if (result == null) result = caseStmt(simpleStmt);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.RETURN_VALUE_STMT:
      {
        ReturnValueStmt returnValueStmt = (ReturnValueStmt)theEObject;
        T result = caseReturnValueStmt(returnValueStmt);
        if (result == null) result = caseStmt(returnValueStmt);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.FOR_ALL_STMT:
      {
        ForAllStmt forAllStmt = (ForAllStmt)theEObject;
        T result = caseForAllStmt(forAllStmt);
        if (result == null) result = caseStmt(forAllStmt);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.FADNP_STMT:
      {
        FadnpStmt fadnpStmt = (FadnpStmt)theEObject;
        T result = caseFadnpStmt(fadnpStmt);
        if (result == null) result = caseStmt(fadnpStmt);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.TERNARY_EXPR:
      {
        TernaryExpr ternaryExpr = (TernaryExpr)theEObject;
        T result = caseTernaryExpr(ternaryExpr);
        if (result == null) result = caseExpr(ternaryExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.OR_EXPR:
      {
        OrExpr orExpr = (OrExpr)theEObject;
        T result = caseOrExpr(orExpr);
        if (result == null) result = caseExpr(orExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.AND_EXPR:
      {
        AndExpr andExpr = (AndExpr)theEObject;
        T result = caseAndExpr(andExpr);
        if (result == null) result = caseExpr(andExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.BITWISE_OR_EXPR:
      {
        BitwiseOrExpr bitwiseOrExpr = (BitwiseOrExpr)theEObject;
        T result = caseBitwiseOrExpr(bitwiseOrExpr);
        if (result == null) result = caseExpr(bitwiseOrExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.XOR_EXPR:
      {
        XorExpr xorExpr = (XorExpr)theEObject;
        T result = caseXorExpr(xorExpr);
        if (result == null) result = caseExpr(xorExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.BITWISE_AND_EXPR:
      {
        BitwiseAndExpr bitwiseAndExpr = (BitwiseAndExpr)theEObject;
        T result = caseBitwiseAndExpr(bitwiseAndExpr);
        if (result == null) result = caseExpr(bitwiseAndExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.EQUALITY_EXPR:
      {
        EqualityExpr equalityExpr = (EqualityExpr)theEObject;
        T result = caseEqualityExpr(equalityExpr);
        if (result == null) result = caseExpr(equalityExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.COMPARE_EXPR:
      {
        CompareExpr compareExpr = (CompareExpr)theEObject;
        T result = caseCompareExpr(compareExpr);
        if (result == null) result = caseExpr(compareExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.SHIFT_EXPR:
      {
        ShiftExpr shiftExpr = (ShiftExpr)theEObject;
        T result = caseShiftExpr(shiftExpr);
        if (result == null) result = caseExpr(shiftExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.ADDITIVE_EXPR:
      {
        AdditiveExpr additiveExpr = (AdditiveExpr)theEObject;
        T result = caseAdditiveExpr(additiveExpr);
        if (result == null) result = caseExpr(additiveExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.MULTIPLICATIVE_EXPR:
      {
        MultiplicativeExpr multiplicativeExpr = (MultiplicativeExpr)theEObject;
        T result = caseMultiplicativeExpr(multiplicativeExpr);
        if (result == null) result = caseExpr(multiplicativeExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.ID_EXPR:
      {
        IdExpr idExpr = (IdExpr)theEObject;
        T result = caseIdExpr(idExpr);
        if (result == null) result = caseExpr(idExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.INT_EXPR:
      {
        IntExpr intExpr = (IntExpr)theEObject;
        T result = caseIntExpr(intExpr);
        if (result == null) result = caseExpr(intExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.DOUBLE_EXPR:
      {
        DoubleExpr doubleExpr = (DoubleExpr)theEObject;
        T result = caseDoubleExpr(doubleExpr);
        if (result == null) result = caseExpr(doubleExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.NODE_NUM_EXPR:
      {
        NodeNumExpr nodeNumExpr = (NodeNumExpr)theEObject;
        T result = caseNodeNumExpr(nodeNumExpr);
        if (result == null) result = caseExpr(nodeNumExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.UNARY_EXPR:
      {
        UnaryExpr unaryExpr = (UnaryExpr)theEObject;
        T result = caseUnaryExpr(unaryExpr);
        if (result == null) result = caseExpr(unaryExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      case DmplPackage.BUILT_IN_EXPR:
      {
        BuiltInExpr builtInExpr = (BuiltInExpr)theEObject;
        T result = caseBuiltInExpr(builtInExpr);
        if (result == null) result = caseExpr(builtInExpr);
        if (result == null) result = defaultCase(theEObject);
        return result;
      }
      default: return defaultCase(theEObject);
    }
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Program</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Program</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseProgram(Program object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Subclause</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Subclause</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseDmplSubclause(DmplSubclause object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Program Element</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Program Element</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseProgramElement(ProgramElement object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Program Element No Target</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Program Element No Target</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseProgramElementNoTarget(ProgramElementNoTarget object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Attributable Node Or Procedure</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Attributable Node Or Procedure</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseAttributableNodeOrProcedure(AttributableNodeOrProcedure object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Number Const</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Number Const</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseNumberConst(NumberConst object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Double Const</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Double Const</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseDoubleConst(DoubleConst object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Specification</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Specification</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseSpecification(Specification object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Node Body Element</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Node Body Element</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseNodeBodyElement(NodeBodyElement object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Attributable Element</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Attributable Element</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseAttributableElement(AttributableElement object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Role Body Element</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Role Body Element</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseRoleBodyElement(RoleBodyElement object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Attributable No Role Element</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Attributable No Role Element</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseAttributableNoRoleElement(AttributableNoRoleElement object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Var Block</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Var Block</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseVarBlock(VarBlock object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Record Block</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Record Block</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseRecordBlock(RecordBlock object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Node Var Init</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Node Var Init</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseNodeVarInit(NodeVarInit object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Var Init</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Var Init</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseVarInit(VarInit object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Var Asgn</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Var Asgn</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseVarAsgn(VarAsgn object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Var</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Var</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseVar(Var object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Dimension</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Dimension</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseDimension(Dimension object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Type</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Type</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseType(Type object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Procedure</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Procedure</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseProcedure(Procedure object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Fn Body</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Fn Body</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseFnBody(FnBody object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Attr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Attr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseAttr(Attr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Param</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Param</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseParam(Param object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Stmt</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Stmt</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseStmt(Stmt object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Assignment Stmt</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Assignment Stmt</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseAssignmentStmt(AssignmentStmt object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>LVal</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>LVal</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseLVal(LVal object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseExpr(Expr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Call Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Call Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseCallExpr(CallExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Target</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Target</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseTarget(Target object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Constant</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Constant</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseConstant(Constant object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Attributable Program Element</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Attributable Program Element</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseAttributableProgramElement(AttributableProgramElement object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Node</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Node</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseNode(Node object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Int Const</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Int Const</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseIntConst(IntConst object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>At End Spec</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>At End Spec</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseAtEndSpec(AtEndSpec object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>At Least Spec</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>At Least Spec</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseAtLeastSpec(AtLeastSpec object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Require Spec</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Require Spec</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseRequireSpec(RequireSpec object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Attributable</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Attributable</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseAttributable(Attributable object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Simple Role</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Simple Role</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseSimpleRole(SimpleRole object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Id Role</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Id Role</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseIdRole(IdRole object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Attributable No Role</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Attributable No Role</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseAttributableNoRole(AttributableNoRole object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Expr Var Asgn</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Expr Var Asgn</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseExprVarAsgn(ExprVarAsgn object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Fn Var Asgn</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Fn Var Asgn</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseFnVarAsgn(FnVarAsgn object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Int Dimension</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Int Dimension</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseIntDimension(IntDimension object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Node Num Dimension</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Node Num Dimension</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseNodeNumDimension(NodeNumDimension object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Id Dimension</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Id Dimension</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseIdDimension(IdDimension object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Thread Declaration</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Thread Declaration</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseThreadDeclaration(ThreadDeclaration object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Function Declaration</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Function Declaration</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseFunctionDeclaration(FunctionDeclaration object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Nested Stmt</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Nested Stmt</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseNestedStmt(NestedStmt object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>While Stmt</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>While Stmt</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseWhileStmt(WhileStmt object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>For Stmt</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>For Stmt</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseForStmt(ForStmt object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Cond Stmt</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Cond Stmt</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseCondStmt(CondStmt object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Simple Stmt</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Simple Stmt</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseSimpleStmt(SimpleStmt object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Return Value Stmt</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Return Value Stmt</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseReturnValueStmt(ReturnValueStmt object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>For All Stmt</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>For All Stmt</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseForAllStmt(ForAllStmt object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Fadnp Stmt</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Fadnp Stmt</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseFadnpStmt(FadnpStmt object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Ternary Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Ternary Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseTernaryExpr(TernaryExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Or Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Or Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseOrExpr(OrExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>And Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>And Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseAndExpr(AndExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Bitwise Or Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Bitwise Or Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseBitwiseOrExpr(BitwiseOrExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Xor Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Xor Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseXorExpr(XorExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Bitwise And Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Bitwise And Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseBitwiseAndExpr(BitwiseAndExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Equality Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Equality Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseEqualityExpr(EqualityExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Compare Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Compare Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseCompareExpr(CompareExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Shift Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Shift Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseShiftExpr(ShiftExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Additive Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Additive Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseAdditiveExpr(AdditiveExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Multiplicative Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Multiplicative Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseMultiplicativeExpr(MultiplicativeExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Id Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Id Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseIdExpr(IdExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Int Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Int Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseIntExpr(IntExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Double Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Double Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseDoubleExpr(DoubleExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Node Num Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Node Num Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseNodeNumExpr(NodeNumExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Unary Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Unary Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseUnaryExpr(UnaryExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Built In Expr</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Built In Expr</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseBuiltInExpr(BuiltInExpr object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Element</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Element</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseElement(Element object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Named Element</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Named Element</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseNamedElement(NamedElement object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Modal Element</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Modal Element</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseModalElement(ModalElement object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>Annex Subclause</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>Annex Subclause</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject) doSwitch(EObject)
   * @generated
   */
  public T caseAnnexSubclause(AnnexSubclause object)
  {
    return null;
  }

  /**
   * Returns the result of interpreting the object as an instance of '<em>EObject</em>'.
   * <!-- begin-user-doc -->
   * This implementation returns null;
   * returning a non-null result will terminate the switch, but this is the last case anyway.
   * <!-- end-user-doc -->
   * @param object the target of the switch.
   * @return the result of interpreting the object as an instance of '<em>EObject</em>'.
   * @see #doSwitch(org.eclipse.emf.ecore.EObject)
   * @generated
   */
  @Override
  public T defaultCase(EObject object)
  {
    return null;
  }

} //DmplSwitch
