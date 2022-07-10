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
 * Optional arguments for the "gamma" operation.
 */
public class GammaOptions {

	private Double exponent;

	/**
	 * Optional argument: exponent
	 * <p>
	 * Gamma factor
	 * @return the value of {@code exponent}
	 */
	public Double getExponent() {
		return this.exponent;
	}

	/**
	 * Set the optional "exponent" argument.
	 * <p>
	 * Gamma factor
	 * @param exponent the new value of {@code exponent}
	 */
	public void setExponent(Double exponent) {
		this.exponent = exponent;
	}

	/**
	 * Set the optional "exponent" argument.
	 * <p>
	 * Gamma factor
	 * @param exponent the new value of {@code exponent}
	 * @return this object for chaining
	 */
	public GammaOptions exponent(Double exponent) {
		setExponent(exponent);
		return this;
	}

}