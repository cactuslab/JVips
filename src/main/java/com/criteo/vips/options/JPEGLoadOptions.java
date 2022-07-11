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
import com.criteo.vips.PixelPacket;
import com.criteo.vips.enums.*;

/**
 * Optional arguments for the "jpegload" operation.
 */
public class JPEGLoadOptions {

	private Integer shrink;
	private Boolean autorotate;
	private Boolean memory;
	private VipsAccess access;
	private VipsFailOn failOn;

	/**
	 * Optional argument: shrink
	 * <p>
	 * Shrink factor on load
	 * @return the value of {@code shrink}
	 */
	public Integer getShrink() {
		return this.shrink;
	}

	/**
	 * Set the optional "shrink" argument.
	 * <p>
	 * Shrink factor on load
	 * @param shrink the new value of {@code shrink}
	 */
	public void setShrink(Integer shrink) {
		this.shrink = shrink;
	}

	/**
	 * Set the optional "shrink" argument.
	 * <p>
	 * Shrink factor on load
	 * @param shrink the new value of {@code shrink}
	 * @return this object for chaining
	 */
	public JPEGLoadOptions shrink(Integer shrink) {
		setShrink(shrink);
		return this;
	}

	/**
	 * Optional argument: autorotate
	 * <p>
	 * Rotate image using exif orientation
	 * @return the value of {@code autorotate}
	 */
	public Boolean getAutorotate() {
		return this.autorotate;
	}

	/**
	 * Set the optional "autorotate" argument.
	 * <p>
	 * Rotate image using exif orientation
	 * @param autorotate the new value of {@code autorotate}
	 */
	public void setAutorotate(Boolean autorotate) {
		this.autorotate = autorotate;
	}

	/**
	 * Set the optional "autorotate" argument.
	 * <p>
	 * Rotate image using exif orientation
	 * @param autorotate the new value of {@code autorotate}
	 * @return this object for chaining
	 */
	public JPEGLoadOptions autorotate(Boolean autorotate) {
		setAutorotate(autorotate);
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
	public JPEGLoadOptions memory(Boolean memory) {
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
	public JPEGLoadOptions access(VipsAccess access) {
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
	public JPEGLoadOptions failOn(VipsFailOn failOn) {
		setFailOn(failOn);
		return this;
	}

}
