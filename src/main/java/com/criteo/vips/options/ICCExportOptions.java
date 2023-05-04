/*
Copyright (c) 2022 Criteo

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

package com.criteo.vips.options;

/**
 * Optional arguments for the "icc_export" operation.
 */
public class ICCExportOptions {

	private com.criteo.vips.enums.VipsPCS pcs;
	private com.criteo.vips.enums.VipsIntent intent;
	private Boolean blackPointCompensation;
	private String outputProfile;
	private Integer depth;

	/**
	 * Optional argument: pcs
	 * <p>
	 * Set Profile Connection Space
	 * @return the value of {@code pcs}
	 */
	public com.criteo.vips.enums.VipsPCS getPcs() {
		return this.pcs;
	}

	/**
	 * Set the optional "pcs" argument.
	 * <p>
	 * Set Profile Connection Space
	 * @param pcs the new value of {@code pcs}
	 */
	public void setPcs(com.criteo.vips.enums.VipsPCS pcs) {
		this.pcs = pcs;
	}

	/**
	 * Set the optional "pcs" argument.
	 * <p>
	 * Set Profile Connection Space
	 * @param pcs the new value of {@code pcs}
	 * @return this object for chaining
	 */
	public ICCExportOptions pcs(com.criteo.vips.enums.VipsPCS pcs) {
		setPcs(pcs);
		return this;
	}

	/**
	 * Optional argument: intent
	 * <p>
	 * Rendering intent
	 * @return the value of {@code intent}
	 */
	public com.criteo.vips.enums.VipsIntent getIntent() {
		return this.intent;
	}

	/**
	 * Set the optional "intent" argument.
	 * <p>
	 * Rendering intent
	 * @param intent the new value of {@code intent}
	 */
	public void setIntent(com.criteo.vips.enums.VipsIntent intent) {
		this.intent = intent;
	}

	/**
	 * Set the optional "intent" argument.
	 * <p>
	 * Rendering intent
	 * @param intent the new value of {@code intent}
	 * @return this object for chaining
	 */
	public ICCExportOptions intent(com.criteo.vips.enums.VipsIntent intent) {
		setIntent(intent);
		return this;
	}

	/**
	 * Optional argument: black-point-compensation
	 * <p>
	 * Enable black point compensation
	 * @return the value of {@code blackPointCompensation}
	 */
	public Boolean getBlackPointCompensation() {
		return this.blackPointCompensation;
	}

	/**
	 * Set the optional "black-point-compensation" argument.
	 * <p>
	 * Enable black point compensation
	 * @param blackPointCompensation the new value of {@code blackPointCompensation}
	 */
	public void setBlackPointCompensation(Boolean blackPointCompensation) {
		this.blackPointCompensation = blackPointCompensation;
	}

	/**
	 * Set the optional "black-point-compensation" argument.
	 * <p>
	 * Enable black point compensation
	 * @param blackPointCompensation the new value of {@code blackPointCompensation}
	 * @return this object for chaining
	 */
	public ICCExportOptions blackPointCompensation(Boolean blackPointCompensation) {
		setBlackPointCompensation(blackPointCompensation);
		return this;
	}

	/**
	 * Optional argument: output-profile
	 * <p>
	 * Filename to load output profile from
	 * @return the value of {@code outputProfile}
	 */
	public String getOutputProfile() {
		return this.outputProfile;
	}

	/**
	 * Set the optional "output-profile" argument.
	 * <p>
	 * Filename to load output profile from
	 * @param outputProfile the new value of {@code outputProfile}
	 */
	public void setOutputProfile(String outputProfile) {
		this.outputProfile = outputProfile;
	}

	/**
	 * Set the optional "output-profile" argument.
	 * <p>
	 * Filename to load output profile from
	 * @param outputProfile the new value of {@code outputProfile}
	 * @return this object for chaining
	 */
	public ICCExportOptions outputProfile(String outputProfile) {
		setOutputProfile(outputProfile);
		return this;
	}

	/**
	 * Optional argument: depth
	 * <p>
	 * Output device space depth in bits
	 * @return the value of {@code depth}
	 */
	public Integer getDepth() {
		return this.depth;
	}

	/**
	 * Set the optional "depth" argument.
	 * <p>
	 * Output device space depth in bits
	 * @param depth the new value of {@code depth}
	 */
	public void setDepth(Integer depth) {
		this.depth = depth;
	}

	/**
	 * Set the optional "depth" argument.
	 * <p>
	 * Output device space depth in bits
	 * @param depth the new value of {@code depth}
	 * @return this object for chaining
	 */
	public ICCExportOptions depth(Integer depth) {
		setDepth(depth);
		return this;
	}

}
