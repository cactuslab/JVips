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

import com.criteo.vips.Image;
import com.criteo.vips.enums.*;

/**
 * Optional arguments for the "openslideload" operation.
 */
public class OpenslideLoadOptions {

	private Boolean attachAssociated;
	private Integer level;
	private Boolean autocrop;
	private String associated;
	private Boolean memory;
	private VipsAccess access;
	private VipsFailOn failOn;

	/**
	 * Optional argument: attach-associated
	 * <p>
	 * Attach all associated images
	 * @return the value of {@code attachAssociated}
	 */
	public Boolean getAttachAssociated() {
		return this.attachAssociated;
	}

	/**
	 * Set the optional "attach-associated" argument.
	 * <p>
	 * Attach all associated images
	 * @param attachAssociated the new value of {@code attachAssociated}
	 */
	public void setAttachAssociated(Boolean attachAssociated) {
		this.attachAssociated = attachAssociated;
	}

	/**
	 * Set the optional "attach-associated" argument.
	 * <p>
	 * Attach all associated images
	 * @param attachAssociated the new value of {@code attachAssociated}
	 * @return this object for chaining
	 */
	public OpenslideLoadOptions attachAssociated(Boolean attachAssociated) {
		setAttachAssociated(attachAssociated);
		return this;
	}

	/**
	 * Optional argument: level
	 * <p>
	 * Load this level from the file
	 * @return the value of {@code level}
	 */
	public Integer getLevel() {
		return this.level;
	}

	/**
	 * Set the optional "level" argument.
	 * <p>
	 * Load this level from the file
	 * @param level the new value of {@code level}
	 */
	public void setLevel(Integer level) {
		this.level = level;
	}

	/**
	 * Set the optional "level" argument.
	 * <p>
	 * Load this level from the file
	 * @param level the new value of {@code level}
	 * @return this object for chaining
	 */
	public OpenslideLoadOptions level(Integer level) {
		setLevel(level);
		return this;
	}

	/**
	 * Optional argument: autocrop
	 * <p>
	 * Crop to image bounds
	 * @return the value of {@code autocrop}
	 */
	public Boolean getAutocrop() {
		return this.autocrop;
	}

	/**
	 * Set the optional "autocrop" argument.
	 * <p>
	 * Crop to image bounds
	 * @param autocrop the new value of {@code autocrop}
	 */
	public void setAutocrop(Boolean autocrop) {
		this.autocrop = autocrop;
	}

	/**
	 * Set the optional "autocrop" argument.
	 * <p>
	 * Crop to image bounds
	 * @param autocrop the new value of {@code autocrop}
	 * @return this object for chaining
	 */
	public OpenslideLoadOptions autocrop(Boolean autocrop) {
		setAutocrop(autocrop);
		return this;
	}

	/**
	 * Optional argument: associated
	 * <p>
	 * Load this associated image
	 * @return the value of {@code associated}
	 */
	public String getAssociated() {
		return this.associated;
	}

	/**
	 * Set the optional "associated" argument.
	 * <p>
	 * Load this associated image
	 * @param associated the new value of {@code associated}
	 */
	public void setAssociated(String associated) {
		this.associated = associated;
	}

	/**
	 * Set the optional "associated" argument.
	 * <p>
	 * Load this associated image
	 * @param associated the new value of {@code associated}
	 * @return this object for chaining
	 */
	public OpenslideLoadOptions associated(String associated) {
		setAssociated(associated);
		return this;
	}

	/**
	 * Optional argument: memory
	 * <p>
	 * Force open via memory
	 * @return the value of {@code memory}
	 */
	public Boolean getMemory() {
		return this.memory;
	}

	/**
	 * Set the optional "memory" argument.
	 * <p>
	 * Force open via memory
	 * @param memory the new value of {@code memory}
	 */
	public void setMemory(Boolean memory) {
		this.memory = memory;
	}

	/**
	 * Set the optional "memory" argument.
	 * <p>
	 * Force open via memory
	 * @param memory the new value of {@code memory}
	 * @return this object for chaining
	 */
	public OpenslideLoadOptions memory(Boolean memory) {
		setMemory(memory);
		return this;
	}

	/**
	 * Optional argument: access
	 * <p>
	 * Required access pattern for this file
	 * @return the value of {@code access}
	 */
	public VipsAccess getAccess() {
		return this.access;
	}

	/**
	 * Set the optional "access" argument.
	 * <p>
	 * Required access pattern for this file
	 * @param access the new value of {@code access}
	 */
	public void setAccess(VipsAccess access) {
		this.access = access;
	}

	/**
	 * Set the optional "access" argument.
	 * <p>
	 * Required access pattern for this file
	 * @param access the new value of {@code access}
	 * @return this object for chaining
	 */
	public OpenslideLoadOptions access(VipsAccess access) {
		setAccess(access);
		return this;
	}

	/**
	 * Optional argument: fail-on
	 * <p>
	 * Error level to fail on
	 * @return the value of {@code failOn}
	 */
	public VipsFailOn getFailOn() {
		return this.failOn;
	}

	/**
	 * Set the optional "fail-on" argument.
	 * <p>
	 * Error level to fail on
	 * @param failOn the new value of {@code failOn}
	 */
	public void setFailOn(VipsFailOn failOn) {
		this.failOn = failOn;
	}

	/**
	 * Set the optional "fail-on" argument.
	 * <p>
	 * Error level to fail on
	 * @param failOn the new value of {@code failOn}
	 * @return this object for chaining
	 */
	public OpenslideLoadOptions failOn(VipsFailOn failOn) {
		setFailOn(failOn);
		return this;
	}

}
