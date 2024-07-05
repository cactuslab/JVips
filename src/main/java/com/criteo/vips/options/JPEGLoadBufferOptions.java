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
 * Optional arguments for the "jpegload_buffer" operation.
 */
public class JPEGLoadBufferOptions {

	private Integer shrink;
	private Boolean autorotate;
	private Boolean unlimited;
	private Boolean memory;
	private com.criteo.vips.enums.VipsAccess access;
	private com.criteo.vips.enums.VipsFailOn failOn;
	private Boolean revalidate;

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
	public JPEGLoadBufferOptions shrink(Integer shrink) {
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
	public JPEGLoadBufferOptions autorotate(Boolean autorotate) {
		setAutorotate(autorotate);
		return this;
	}

	/**
	 * Optional argument: unlimited
	 * <p>
	 * Remove all denial of service limits
	 * @return the value of {@code unlimited}
	 */
	public Boolean getUnlimited() {
		return this.unlimited;
	}

	/**
	 * Set the optional "unlimited" argument.
	 * <p>
	 * Remove all denial of service limits
	 * @param unlimited the new value of {@code unlimited}
	 */
	public void setUnlimited(Boolean unlimited) {
		this.unlimited = unlimited;
	}

	/**
	 * Set the optional "unlimited" argument.
	 * <p>
	 * Remove all denial of service limits
	 * @param unlimited the new value of {@code unlimited}
	 * @return this object for chaining
	 */
	public JPEGLoadBufferOptions unlimited(Boolean unlimited) {
		setUnlimited(unlimited);
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
	public JPEGLoadBufferOptions memory(Boolean memory) {
		setMemory(memory);
		return this;
	}

	/**
	 * Optional argument: access
	 * <p>
	 * Required access pattern for this file
	 * @return the value of {@code access}
	 */
	public com.criteo.vips.enums.VipsAccess getAccess() {
		return this.access;
	}

	/**
	 * Set the optional "access" argument.
	 * <p>
	 * Required access pattern for this file
	 * @param access the new value of {@code access}
	 */
	public void setAccess(com.criteo.vips.enums.VipsAccess access) {
		this.access = access;
	}

	/**
	 * Set the optional "access" argument.
	 * <p>
	 * Required access pattern for this file
	 * @param access the new value of {@code access}
	 * @return this object for chaining
	 */
	public JPEGLoadBufferOptions access(com.criteo.vips.enums.VipsAccess access) {
		setAccess(access);
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
	public JPEGLoadBufferOptions failOn(com.criteo.vips.enums.VipsFailOn failOn) {
		setFailOn(failOn);
		return this;
	}

	/**
	 * Optional argument: revalidate
	 * <p>
	 * Don't use a cached result for this operation
	 * @return the value of {@code revalidate}
	 */
	public Boolean getRevalidate() {
		return this.revalidate;
	}

	/**
	 * Set the optional "revalidate" argument.
	 * <p>
	 * Don't use a cached result for this operation
	 * @param revalidate the new value of {@code revalidate}
	 */
	public void setRevalidate(Boolean revalidate) {
		this.revalidate = revalidate;
	}

	/**
	 * Set the optional "revalidate" argument.
	 * <p>
	 * Don't use a cached result for this operation
	 * @param revalidate the new value of {@code revalidate}
	 * @return this object for chaining
	 */
	public JPEGLoadBufferOptions revalidate(Boolean revalidate) {
		setRevalidate(revalidate);
		return this;
	}

}
