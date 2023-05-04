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
 * Optional arguments for the "reduce" operation.
 */
public class ReduceOptions {

	private com.criteo.vips.enums.VipsKernel kernel;
	private Double gap;

	/**
	 * Optional argument: kernel
	 * <p>
	 * Resampling kernel
	 * @return the value of {@code kernel}
	 */
	public com.criteo.vips.enums.VipsKernel getKernel() {
		return this.kernel;
	}

	/**
	 * Set the optional "kernel" argument.
	 * <p>
	 * Resampling kernel
	 * @param kernel the new value of {@code kernel}
	 */
	public void setKernel(com.criteo.vips.enums.VipsKernel kernel) {
		this.kernel = kernel;
	}

	/**
	 * Set the optional "kernel" argument.
	 * <p>
	 * Resampling kernel
	 * @param kernel the new value of {@code kernel}
	 * @return this object for chaining
	 */
	public ReduceOptions kernel(com.criteo.vips.enums.VipsKernel kernel) {
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
	public ReduceOptions gap(Double gap) {
		setGap(gap);
		return this;
	}

}
