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
 * Optional arguments for the "resize" operation.
 */
public class ResizeOptions {

	private VipsKernel kernel;
	private Double gap;
	private Double vscale;

	/**
	 * Optional argument: kernel
	 * <p>
	 * Resampling kernel
	 * @return the value of {@code kernel}
	 */
	public VipsKernel getKernel() {
		return this.kernel;
	}

	/**
	 * Set the optional "kernel" argument.
	 * <p>
	 * Resampling kernel
	 * @param kernel the new value of {@code kernel}
	 */
	public void setKernel(VipsKernel kernel) {
		this.kernel = kernel;
	}

	/**
	 * Set the optional "kernel" argument.
	 * <p>
	 * Resampling kernel
	 * @param kernel the new value of {@code kernel}
	 * @return this object for chaining
	 */
	public ResizeOptions kernel(VipsKernel kernel) {
		setKernel(kernel);
		return this;
	}

	/**
	 * Optional argument: gap
	 * <p>
	 * Reducing gap
	 * @return the value of {@code gap}
	 */
	public Double getGap() {
		return this.gap;
	}

	/**
	 * Set the optional "gap" argument.
	 * <p>
	 * Reducing gap
	 * @param gap the new value of {@code gap}
	 */
	public void setGap(Double gap) {
		this.gap = gap;
	}

	/**
	 * Set the optional "gap" argument.
	 * <p>
	 * Reducing gap
	 * @param gap the new value of {@code gap}
	 * @return this object for chaining
	 */
	public ResizeOptions gap(Double gap) {
		setGap(gap);
		return this;
	}

	/**
	 * Optional argument: vscale
	 * <p>
	 * Vertical scale image by this factor
	 * @return the value of {@code vscale}
	 */
	public Double getVscale() {
		return this.vscale;
	}

	/**
	 * Set the optional "vscale" argument.
	 * <p>
	 * Vertical scale image by this factor
	 * @param vscale the new value of {@code vscale}
	 */
	public void setVscale(Double vscale) {
		this.vscale = vscale;
	}

	/**
	 * Set the optional "vscale" argument.
	 * <p>
	 * Vertical scale image by this factor
	 * @param vscale the new value of {@code vscale}
	 * @return this object for chaining
	 */
	public ResizeOptions vscale(Double vscale) {
		setVscale(vscale);
		return this;
	}

}
