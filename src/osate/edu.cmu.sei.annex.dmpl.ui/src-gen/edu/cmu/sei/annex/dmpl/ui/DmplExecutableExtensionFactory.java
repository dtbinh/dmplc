/*
 * generated by Xtext
 */
package edu.cmu.sei.annex.dmpl.ui;

import org.eclipse.xtext.ui.guice.AbstractGuiceAwareExecutableExtensionFactory;
import org.osgi.framework.Bundle;

import com.google.inject.Injector;

import edu.cmu.sei.annex.dmpl.ui.internal.DmplActivator;

/**
 * This class was generated. Customizations should only happen in a newly
 * introduced subclass. 
 */
public class DmplExecutableExtensionFactory extends AbstractGuiceAwareExecutableExtensionFactory {

	@Override
	protected Bundle getBundle() {
		return DmplActivator.getInstance().getBundle();
	}
	
	@Override
	protected Injector getInjector() {
		return DmplActivator.getInstance().getInjector(DmplActivator.EDU_CMU_SEI_ANNEX_DMPL_DMPL);
	}
	
}
