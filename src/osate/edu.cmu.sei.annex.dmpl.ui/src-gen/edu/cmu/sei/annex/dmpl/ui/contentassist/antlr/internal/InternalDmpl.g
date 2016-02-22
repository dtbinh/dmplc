/*
 * generated by Xtext
 */
grammar InternalDmpl;

options {
	superClass=AbstractInternalContentAssistParser;
	
}

@lexer::header {
package edu.cmu.sei.annex.dmpl.ui.contentassist.antlr.internal;

// Hack: Use our own Lexer superclass by means of import. 
// Currently there is no other way to specify the superclass for the lexer.
import org.eclipse.xtext.ui.editor.contentassist.antlr.internal.Lexer;
}

@parser::header {
package edu.cmu.sei.annex.dmpl.ui.contentassist.antlr.internal; 

import java.io.InputStream;
import org.eclipse.xtext.*;
import org.eclipse.xtext.parser.*;
import org.eclipse.xtext.parser.impl.*;
import org.eclipse.emf.ecore.util.EcoreUtil;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.xtext.parser.antlr.XtextTokenStream;
import org.eclipse.xtext.parser.antlr.XtextTokenStream.HiddenTokens;
import org.eclipse.xtext.ui.editor.contentassist.antlr.internal.AbstractInternalContentAssistParser;
import org.eclipse.xtext.ui.editor.contentassist.antlr.internal.DFA;
import edu.cmu.sei.annex.dmpl.services.DmplGrammarAccess;

}

@parser::members {
 
 	private DmplGrammarAccess grammarAccess;
 	
    public void setGrammarAccess(DmplGrammarAccess grammarAccess) {
    	this.grammarAccess = grammarAccess;
    }
    
    @Override
    protected Grammar getGrammar() {
    	return grammarAccess.getGrammar();
    }
    
    @Override
    protected String getValueForTokenName(String tokenName) {
    	return tokenName;
    }

}




// Entry rule entryRuleAnnexSubclause
entryRuleAnnexSubclause 
:
{ before(grammarAccess.getAnnexSubclauseRule()); }
	 ruleAnnexSubclause
{ after(grammarAccess.getAnnexSubclauseRule()); } 
	 EOF 
;

// Rule AnnexSubclause
ruleAnnexSubclause
    @init {
		int stackSize = keepStackSize();
    }
	:
(
{ before(grammarAccess.getAnnexSubclauseAccess().getDmplSubclauseParserRuleCall()); }
	ruleDmplSubclause
{ after(grammarAccess.getAnnexSubclauseAccess().getDmplSubclauseParserRuleCall()); }
)

;
finally {
	restoreStackSize(stackSize);
}



// Entry rule entryRuleDmplSubclause
entryRuleDmplSubclause 
:
{ before(grammarAccess.getDmplSubclauseRule()); }
	 ruleDmplSubclause
{ after(grammarAccess.getDmplSubclauseRule()); } 
	 EOF 
;

// Rule DmplSubclause
ruleDmplSubclause
    @init {
		int stackSize = keepStackSize();
    }
	:
(
{ before(grammarAccess.getDmplSubclauseAccess().getGroup()); }
(rule__DmplSubclause__Group__0)
{ after(grammarAccess.getDmplSubclauseAccess().getGroup()); }
)

;
finally {
	restoreStackSize(stackSize);
}



// Entry rule entryRuleFunctionCall
entryRuleFunctionCall 
:
{ before(grammarAccess.getFunctionCallRule()); }
	 ruleFunctionCall
{ after(grammarAccess.getFunctionCallRule()); } 
	 EOF 
;

// Rule FunctionCall
ruleFunctionCall
    @init {
		int stackSize = keepStackSize();
    }
	:
(
{ before(grammarAccess.getFunctionCallAccess().getFunctionNameAssignment()); }
(rule__FunctionCall__FunctionNameAssignment)
{ after(grammarAccess.getFunctionCallAccess().getFunctionNameAssignment()); }
)

;
finally {
	restoreStackSize(stackSize);
}






rule__DmplSubclause__Group__0
    @init {
		int stackSize = keepStackSize();
    }
:
	rule__DmplSubclause__Group__0__Impl
	rule__DmplSubclause__Group__1
;
finally {
	restoreStackSize(stackSize);
}

rule__DmplSubclause__Group__0__Impl
    @init {
		int stackSize = keepStackSize();
    }
:
(
{ before(grammarAccess.getDmplSubclauseAccess().getDmplSubclauseAction_0()); }
(

)
{ after(grammarAccess.getDmplSubclauseAccess().getDmplSubclauseAction_0()); }
)

;
finally {
	restoreStackSize(stackSize);
}


rule__DmplSubclause__Group__1
    @init {
		int stackSize = keepStackSize();
    }
:
	rule__DmplSubclause__Group__1__Impl
;
finally {
	restoreStackSize(stackSize);
}

rule__DmplSubclause__Group__1__Impl
    @init {
		int stackSize = keepStackSize();
    }
:
(
{ before(grammarAccess.getDmplSubclauseAccess().getFunctionCallsAssignment_1()); }
(rule__DmplSubclause__FunctionCallsAssignment_1)*
{ after(grammarAccess.getDmplSubclauseAccess().getFunctionCallsAssignment_1()); }
)

;
finally {
	restoreStackSize(stackSize);
}







rule__DmplSubclause__FunctionCallsAssignment_1
    @init {
		int stackSize = keepStackSize();
    }
:
(
{ before(grammarAccess.getDmplSubclauseAccess().getFunctionCallsFunctionCallParserRuleCall_1_0()); }
	ruleFunctionCall{ after(grammarAccess.getDmplSubclauseAccess().getFunctionCallsFunctionCallParserRuleCall_1_0()); }
)

;
finally {
	restoreStackSize(stackSize);
}

rule__FunctionCall__FunctionNameAssignment
    @init {
		int stackSize = keepStackSize();
    }
:
(
{ before(grammarAccess.getFunctionCallAccess().getFunctionNameIDTerminalRuleCall_0()); }
	RULE_ID{ after(grammarAccess.getFunctionCallAccess().getFunctionNameIDTerminalRuleCall_0()); }
)

;
finally {
	restoreStackSize(stackSize);
}


RULE_ID : '^'? ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')*;

RULE_INT : ('0'..'9')+;

RULE_STRING : ('"' ('\\' .|~(('\\'|'"')))* '"'|'\'' ('\\' .|~(('\\'|'\'')))* '\'');

RULE_ML_COMMENT : '/*' ( options {greedy=false;} : . )*'*/';

RULE_SL_COMMENT : '//' ~(('\n'|'\r'))* ('\r'? '\n')?;

RULE_WS : (' '|'\t'|'\r'|'\n')+;

RULE_ANY_OTHER : .;


