/*
 * generated by Xtext
 */
package edu.cmu.sei.annex.dmpl;

import org.eclipse.xtext.conversion.IValueConverterService;

import edu.cmu.sei.annex.dmpl.conversion.DmplValueConverterService;

/**
 * Use this class to register components to be used at runtime / without the Equinox extension registry.
 */
public class DmplRuntimeModule extends edu.cmu.sei.annex.dmpl.AbstractDmplRuntimeModule {
	@Override
	public Class<? extends IValueConverterService> bindIValueConverterService() {
		return DmplValueConverterService.class;
	}
}