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
 * Optional arguments for the "thumbnail" operation.
 */
public class ThumbnailOptions {

	private Integer height;
	private com.criteo.vips.enums.VipsSize size;
	private Boolean noRotate;
	private com.criteo.vips.enums.VipsInteresting crop;
	private Boolean linear;
	private String importProfile;
	private String exportProfile;
	private com.criteo.vips.enums.VipsIntent intent;
	private com.criteo.vips.enums.VipsFailOn failOn;

	/**
	 * Optional argument: height
	 * <p>
	 * Size to this height
	 * @return the value of {@code height}
	 */
	public Integer getHeight() {
		return this.height;
	}

	/**
	 * Set the optional "height" argument.
	 * <p>
	 * Size to this height
	 * @param height the new value of {@code height}
	 */
	public void setHeight(Integer height) {
		this.height = height;
	}

	/**
	 * Set the optional "height" argument.
	 * <p>
	 * Size to this height
	 * @param height the new value of {@code height}
	 * @return this object for chaining
	 */
	public ThumbnailOptions height(Integer height) {
		setHeight(height);
		return this;
	}

	/**
	 * Optional argument: size
	 * <p>
	 * Only upsize, only downsize, or both
	 * @return the value of {@code size}
	 */
	public com.criteo.vips.enums.VipsSize getSize() {
		return this.size;
	}

	/**
	 * Set the optional "size" argument.
	 * <p>
	 * Only upsize, only downsize, or both
	 * @param size the new value of {@code size}
	 */
	public void setSize(com.criteo.vips.enums.VipsSize size) {
		this.size = size;
	}

	/**
	 * Set the optional "size" argument.
	 * <p>
	 * Only upsize, only downsize, or both
	 * @param size the new value of {@code size}
	 * @return this object for chaining
	 */
	public ThumbnailOptions size(com.criteo.vips.enums.VipsSize size) {
		setSize(size);
		return this;
	}

	/**
	 * Optional argument: no-rotate
	 * <p>
	 * Don't use orientation tags to rotate image upright
	 * @return the value of {@code noRotate}
	 */
	public Boolean getNoRotate() {
		return this.noRotate;
	}

	/**
	 * Set the optional "no-rotate" argument.
	 * <p>
	 * Don't use orientation tags to rotate image upright
	 * @param noRotate the new value of {@code noRotate}
	 */
	public void setNoRotate(Boolean noRotate) {
		this.noRotate = noRotate;
	}

	/**
	 * Set the optional "no-rotate" argument.
	 * <p>
	 * Don't use orientation tags to rotate image upright
	 * @param noRotate the new value of {@code noRotate}
	 * @return this object for chaining
	 */
	public ThumbnailOptions noRotate(Boolean noRotate) {
		setNoRotate(noRotate);
		return this;
	}

	/**
	 * Optional argument: crop
	 * <p>
	 * Reduce to fill target rectangle, then crop
	 * @return the value of {@code crop}
	 */
	public com.criteo.vips.enums.VipsInteresting getCrop() {
		return this.crop;
	}

	/**
	 * Set the optional "crop" argument.
	 * <p>
	 * Reduce to fill target rectangle, then crop
	 * @param crop the new value of {@code crop}
	 */
	public void setCrop(com.criteo.vips.enums.VipsInteresting crop) {
		this.crop = crop;
	}

	/**
	 * Set the optional "crop" argument.
	 * <p>
	 * Reduce to fill target rectangle, then crop
	 * @param crop the new value of {@code crop}
	 * @return this object for chaining
	 */
	public ThumbnailOptions crop(com.criteo.vips.enums.VipsInteresting crop) {
		setCrop(crop);
		return this;
	}

	/**
	 * Optional argument: linear
	 * <p>
	 * Reduce in linear light
	 * @return the value of {@code linear}
	 */
	public Boolean getLinear() {
		return this.linear;
	}

	/**
	 * Set the optional "linear" argument.
	 * <p>
	 * Reduce in linear light
	 * @param linear the new value of {@code linear}
	 */
	public void setLinear(Boolean linear) {
		this.linear = linear;
	}

	/**
	 * Set the optional "linear" argument.
	 * <p>
	 * Reduce in linear light
	 * @param linear the new value of {@code linear}
	 * @return this object for chaining
	 */
	public ThumbnailOptions linear(Boolean linear) {
		setLinear(linear);
		return this;
	}

	/**
	 * Optional argument: import-profile
	 * <p>
	 * Fallback import profile
	 * @return the value of {@code importProfile}
	 */
	public String getImportProfile() {
		return this.importProfile;
	}

	/**
	 * Set the optional "import-profile" argument.
	 * <p>
	 * Fallback import profile
	 * @param importProfile the new value of {@code importProfile}
	 */
	public void setImportProfile(String importProfile) {
		this.importProfile = importProfile;
	}

	/**
	 * Set the optional "import-profile" argument.
	 * <p>
	 * Fallback import profile
	 * @param importProfile the new value of {@code importProfile}
	 * @return this object for chaining
	 */
	public ThumbnailOptions importProfile(String importProfile) {
		setImportProfile(importProfile);
		return this;
	}

	/**
	 * Optional argument: export-profile
	 * <p>
	 * Fallback export profile
	 * @return the value of {@code exportProfile}
	 */
	public String getExportProfile() {
		return this.exportProfile;
	}

	/**
	 * Set the optional "export-profile" argument.
	 * <p>
	 * Fallback export profile
	 * @param exportProfile the new value of {@code exportProfile}
	 */
	public void setExportProfile(String exportProfile) {
		this.exportProfile = exportProfile;
	}

	/**
	 * Set the optional "export-profile" argument.
	 * <p>
	 * Fallback export profile
	 * @param exportProfile the new value of {@code exportProfile}
	 * @return this object for chaining
	 */
	public ThumbnailOptions exportProfile(String exportProfile) {
		setExportProfile(exportProfile);
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
	public ThumbnailOptions intent(com.criteo.vips.enums.VipsIntent intent) {
		setIntent(intent);
		return this;
	}

	/**
	 * Optional argument: fail-on
	 * <p>
	 * Error level to fail on
	 * @return the value of {@code failOn}
	 */
	public com.criteo.vips.enums.VipsFailOn getFailOn() {
		return this.failOn;
	}

	/**
	 * Set the optional "fail-on" argument.
	 * <p>
	 * Error level to fail on
	 * @param failOn the new value of {@code failOn}
	 */
	public void setFailOn(com.criteo.vips.enums.VipsFailOn failOn) {
		this.failOn = failOn;
	}

	/**
	 * Set the optional "fail-on" argument.
	 * <p>
	 * Error level to fail on
	 * @param failOn the new value of {@code failOn}
	 * @return this object for chaining
	 */
	public ThumbnailOptions failOn(com.criteo.vips.enums.VipsFailOn failOn) {
		setFailOn(failOn);
		return this;
	}

}
