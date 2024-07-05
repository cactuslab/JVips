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
 * Optional arguments for the "rawload" operation.
 */
public class RawLoadOptions {

	private Long offset;
	private com.criteo.vips.enums.VipsBandFormat format;
	private com.criteo.vips.enums.VipsInterpretation interpretation;
	private Boolean memory;
	private com.criteo.vips.enums.VipsAccess access;
	private com.criteo.vips.enums.VipsFailOn failOn;
	private Boolean revalidate;

	/**
	 * Optional argument: offset
	 * <p>
	 * Offset in bytes from start of file
	 * @return the value of {@code offset}
	 */
	public Long getOffset() {
		return this.offset;
	}

	/**
	 * Set the optional "offset" argument.
	 * <p>
	 * Offset in bytes from start of file
	 * @param offset the new value of {@code offset}
	 */
	public void setOffset(Long offset) {
		this.offset = offset;
	}

	/**
	 * Set the optional "offset" argument.
	 * <p>
	 * Offset in bytes from start of file
	 * @param offset the new value of {@code offset}
	 * @return this object for chaining
	 */
	public RawLoadOptions offset(Long offset) {
		setOffset(offset);
		return this;
	}

	/**
	 * Optional argument: format
	 * <p>
	 * Pixel format in image
	 * @return the value of {@code format}
	 */
	public com.criteo.vips.enums.VipsBandFormat getFormat() {
		return this.format;
	}

	/**
	 * Set the optional "format" argument.
	 * <p>
	 * Pixel format in image
	 * @param format the new value of {@code format}
	 */
	public void setFormat(com.criteo.vips.enums.VipsBandFormat format) {
		this.format = format;
	}

	/**
	 * Set the optional "format" argument.
	 * <p>
	 * Pixel format in image
	 * @param format the new value of {@code format}
	 * @return this object for chaining
	 */
	public RawLoadOptions format(com.criteo.vips.enums.VipsBandFormat format) {
		setFormat(format);
		return this;
	}

	/**
	 * Optional argument: interpretation
	 * <p>
	 * Pixel interpretation
	 * @return the value of {@code interpretation}
	 */
	public com.criteo.vips.enums.VipsInterpretation getInterpretation() {
		return this.interpretation;
	}

	/**
	 * Set the optional "interpretation" argument.
	 * <p>
	 * Pixel interpretation
	 * @param interpretation the new value of {@code interpretation}
	 */
	public void setInterpretation(com.criteo.vips.enums.VipsInterpretation interpretation) {
		this.interpretation = interpretation;
	}

	/**
	 * Set the optional "interpretation" argument.
	 * <p>
	 * Pixel interpretation
	 * @param interpretation the new value of {@code interpretation}
	 * @return this object for chaining
	 */
	public RawLoadOptions interpretation(com.criteo.vips.enums.VipsInterpretation interpretation) {
		setInterpretation(interpretation);
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
	public RawLoadOptions memory(Boolean memory) {
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
	public RawLoadOptions access(com.criteo.vips.enums.VipsAccess access) {
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
	public RawLoadOptions failOn(com.criteo.vips.enums.VipsFailOn failOn) {
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
	public RawLoadOptions revalidate(Boolean revalidate) {
		setRevalidate(revalidate);
		return this;
	}

}
