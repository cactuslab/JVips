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
 * Optional arguments for the "svgload_buffer" operation.
 */
public class SvgLoadBufferOptions {

	private Double dpi;
	private Double scale;
	private Boolean unlimited;
	private Boolean memory;
	private com.criteo.vips.enums.VipsAccess access;
	private com.criteo.vips.enums.VipsFailOn failOn;
	private Boolean revalidate;

	/**
	 * Optional argument: dpi
	 * <p>
	 * Render at this DPI
	 * @return the value of {@code dpi}
	 */
	public Double getDpi() {
		return this.dpi;
	}

	/**
	 * Set the optional "dpi" argument.
	 * <p>
	 * Render at this DPI
	 * @param dpi the new value of {@code dpi}
	 */
	public void setDpi(Double dpi) {
		this.dpi = dpi;
	}

	/**
	 * Set the optional "dpi" argument.
	 * <p>
	 * Render at this DPI
	 * @param dpi the new value of {@code dpi}
	 * @return this object for chaining
	 */
	public SvgLoadBufferOptions dpi(Double dpi) {
		setDpi(dpi);
		return this;
	}

	/**
	 * Optional argument: scale
	 * <p>
	 * Scale output by this factor
	 * @return the value of {@code scale}
	 */
	public Double getScale() {
		return this.scale;
	}

	/**
	 * Set the optional "scale" argument.
	 * <p>
	 * Scale output by this factor
	 * @param scale the new value of {@code scale}
	 */
	public void setScale(Double scale) {
		this.scale = scale;
	}

	/**
	 * Set the optional "scale" argument.
	 * <p>
	 * Scale output by this factor
	 * @param scale the new value of {@code scale}
	 * @return this object for chaining
	 */
	public SvgLoadBufferOptions scale(Double scale) {
		setScale(scale);
		return this;
	}

	/**
	 * Optional argument: unlimited
	 * <p>
	 * Allow SVG of any size
	 * @return the value of {@code unlimited}
	 */
	public Boolean getUnlimited() {
		return this.unlimited;
	}

	/**
	 * Set the optional "unlimited" argument.
	 * <p>
	 * Allow SVG of any size
	 * @param unlimited the new value of {@code unlimited}
	 */
	public void setUnlimited(Boolean unlimited) {
		this.unlimited = unlimited;
	}

	/**
	 * Set the optional "unlimited" argument.
	 * <p>
	 * Allow SVG of any size
	 * @param unlimited the new value of {@code unlimited}
	 * @return this object for chaining
	 */
	public SvgLoadBufferOptions unlimited(Boolean unlimited) {
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
	public SvgLoadBufferOptions memory(Boolean memory) {
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
	public SvgLoadBufferOptions access(com.criteo.vips.enums.VipsAccess access) {
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
	public SvgLoadBufferOptions failOn(com.criteo.vips.enums.VipsFailOn failOn) {
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
	public SvgLoadBufferOptions revalidate(Boolean revalidate) {
		setRevalidate(revalidate);
		return this;
	}

}
