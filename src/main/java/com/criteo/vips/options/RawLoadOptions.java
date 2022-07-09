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
 * Optional arguments for the "rawload" operation.
 */
public class RawLoadOptions {

	private Long offset;
	private VipsBandFormat format;
	private VipsInterpretation interpretation;
	private Boolean memory;
	private VipsAccess access;
	private VipsFailOn failOn;

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
	public VipsBandFormat getFormat() {
		return this.format;
	}

	/**
	 * Set the optional "format" argument.
	 * <p>
	 * Pixel format in image
	 * @param format the new value of {@code format}
	 */
	public void setFormat(VipsBandFormat format) {
		this.format = format;
	}

	/**
	 * Set the optional "format" argument.
	 * <p>
	 * Pixel format in image
	 * @param format the new value of {@code format}
	 * @return this object for chaining
	 */
	public RawLoadOptions format(VipsBandFormat format) {
		setFormat(format);
		return this;
	}

	/**
	 * Optional argument: interpretation
	 * <p>
	 * Pixel interpretation
	 * @return the value of {@code interpretation}
	 */
	public VipsInterpretation getInterpretation() {
		return this.interpretation;
	}

	/**
	 * Set the optional "interpretation" argument.
	 * <p>
	 * Pixel interpretation
	 * @param interpretation the new value of {@code interpretation}
	 */
	public void setInterpretation(VipsInterpretation interpretation) {
		this.interpretation = interpretation;
	}

	/**
	 * Set the optional "interpretation" argument.
	 * <p>
	 * Pixel interpretation
	 * @param interpretation the new value of {@code interpretation}
	 * @return this object for chaining
	 */
	public RawLoadOptions interpretation(VipsInterpretation interpretation) {
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
	public RawLoadOptions access(VipsAccess access) {
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
	public RawLoadOptions failOn(VipsFailOn failOn) {
		setFailOn(failOn);
		return this;
	}

}
