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

import com.criteo.vips.enums.*;
import com.criteo.vips.PixelPacket;

/**
 * Optional arguments for the "icc_import" operation.
 */
public class ICCImportOptions {

	private VipsPCS pcs;
	private VipsIntent intent;
	private Boolean blackPointCompensation;
	private Boolean embedded;
	private String inputProfile;

	/**
	 * Optional argument: pcs
	 * <p>
	 * Set Profile Connection Space
	 * @return the value of {@code pcs}
	 */
	public VipsPCS getPcs() {
		return this.pcs;
	}

	/**
	 * Set the optional "pcs" argument.
	 * <p>
	 * Set Profile Connection Space
	 * @param pcs the new value of {@code pcs}
	 */
	public void setPcs(VipsPCS pcs) {
		this.pcs = pcs;
	}

	/**
	 * Set the optional "pcs" argument.
	 * <p>
	 * Set Profile Connection Space
	 * @param pcs the new value of {@code pcs}
	 * @return this object for chaining
	 */
	public ICCImportOptions pcs(VipsPCS pcs) {
		setPcs(pcs);
		return this;
	}

	/**
	 * Optional argument: intent
	 * <p>
	 * Rendering intent
	 * @return the value of {@code intent}
	 */
	public VipsIntent getIntent() {
		return this.intent;
	}

	/**
	 * Set the optional "intent" argument.
	 * <p>
	 * Rendering intent
	 * @param intent the new value of {@code intent}
	 */
	public void setIntent(VipsIntent intent) {
		this.intent = intent;
	}

	/**
	 * Set the optional "intent" argument.
	 * <p>
	 * Rendering intent
	 * @param intent the new value of {@code intent}
	 * @return this object for chaining
	 */
	public ICCImportOptions intent(VipsIntent intent) {
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
	public ICCImportOptions blackPointCompensation(Boolean blackPointCompensation) {
		setBlackPointCompensation(blackPointCompensation);
		return this;
	}

	/**
	 * Optional argument: embedded
	 * <p>
	 * Use embedded input profile, if available
	 * @return the value of {@code embedded}
	 */
	public Boolean getEmbedded() {
		return this.embedded;
	}

	/**
	 * Set the optional "embedded" argument.
	 * <p>
	 * Use embedded input profile, if available
	 * @param embedded the new value of {@code embedded}
	 */
	public void setEmbedded(Boolean embedded) {
		this.embedded = embedded;
	}

	/**
	 * Set the optional "embedded" argument.
	 * <p>
	 * Use embedded input profile, if available
	 * @param embedded the new value of {@code embedded}
	 * @return this object for chaining
	 */
	public ICCImportOptions embedded(Boolean embedded) {
		setEmbedded(embedded);
		return this;
	}

	/**
	 * Optional argument: input-profile
	 * <p>
	 * Filename to load input profile from
	 * @return the value of {@code inputProfile}
	 */
	public String getInputProfile() {
		return this.inputProfile;
	}

	/**
	 * Set the optional "input-profile" argument.
	 * <p>
	 * Filename to load input profile from
	 * @param inputProfile the new value of {@code inputProfile}
	 */
	public void setInputProfile(String inputProfile) {
		this.inputProfile = inputProfile;
	}

	/**
	 * Set the optional "input-profile" argument.
	 * <p>
	 * Filename to load input profile from
	 * @param inputProfile the new value of {@code inputProfile}
	 * @return this object for chaining
	 */
	public ICCImportOptions inputProfile(String inputProfile) {
		setInputProfile(inputProfile);
		return this;
	}

}
