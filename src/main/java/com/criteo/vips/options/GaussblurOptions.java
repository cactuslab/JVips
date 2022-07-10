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
 * Optional arguments for the "gaussblur" operation.
 */
public class GaussBlurOptions {

	private Double minAmpl;
	private VipsPrecision precision;

	/**
	 * Optional argument: min-ampl
	 * <p>
	 * Minimum amplitude of Gaussian
	 * @return the value of {@code minAmpl}
	 */
	public Double getMinAmpl() {
		return this.minAmpl;
	}

	/**
	 * Set the optional "min-ampl" argument.
	 * <p>
	 * Minimum amplitude of Gaussian
	 * @param minAmpl the new value of {@code minAmpl}
	 */
	public void setMinAmpl(Double minAmpl) {
		this.minAmpl = minAmpl;
	}

	/**
	 * Set the optional "min-ampl" argument.
	 * <p>
	 * Minimum amplitude of Gaussian
	 * @param minAmpl the new value of {@code minAmpl}
	 * @return this object for chaining
	 */
	public GaussBlurOptions minAmpl(Double minAmpl) {
		setMinAmpl(minAmpl);
		return this;
	}

	/**
	 * Optional argument: precision
	 * <p>
	 * Convolve with this precision
	 * @return the value of {@code precision}
	 */
	public VipsPrecision getPrecision() {
		return this.precision;
	}

	/**
	 * Set the optional "precision" argument.
	 * <p>
	 * Convolve with this precision
	 * @param precision the new value of {@code precision}
	 */
	public void setPrecision(VipsPrecision precision) {
		this.precision = precision;
	}

	/**
	 * Set the optional "precision" argument.
	 * <p>
	 * Convolve with this precision
	 * @param precision the new value of {@code precision}
	 * @return this object for chaining
	 */
	public GaussBlurOptions precision(VipsPrecision precision) {
		setPrecision(precision);
		return this;
	}

}
