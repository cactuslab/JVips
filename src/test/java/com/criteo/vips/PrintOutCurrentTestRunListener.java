package com.criteo.vips;

import org.junit.runner.Description;
import org.junit.runner.Result;
import org.junit.runner.notification.RunListener;

public class PrintOutCurrentTestRunListener extends RunListener {

	@Override
	public void testRunStarted(Description description) throws Exception {
		
	}

	public void testStarted(Description description) throws Exception {
		System.out.print("[TEST] " + description.toString() + " ...");
	}

	public void testFinished(Description description) throws Exception {
		System.out.println(" done");
	}

	public void testRunFinished(Result result) throws Exception {
		
	}

}
