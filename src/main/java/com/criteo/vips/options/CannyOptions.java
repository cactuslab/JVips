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
 * Optional arguments for the "canny" operation.
 */
public class CannyOptions {

	private Double sigma;
	private VipsPrecision precision;

	/**
	 * Optional argument: sigma
	 * <p>
	 * Sigma of Gaussian
	 * @return the value of {@code sigma}
	 */
	public Double getSigma() {
		return this.sigma;
	}

	/**
	 * Set the optional "sigma" argument.
	 * <p>
	 * Sigma of Gaussian
	 * @param sigma the new value of {@code sigma}
	 */
	public void setSigma(Double sigma) {
		this.sigma = sigma;
	}

	/**
	 * Set the optional "sigma" argument.
	 * <p>
	 * Sigma of Gaussian
	 * @param sigma the new value of {@code sigma}
	 * @return this object for chaining
	 */
	public CannyOptions sigma(Double sigma) {
		setSigma(sigma);
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
	public CannyOptions precision(VipsPrecision precision) {
		setPrecision(precision);
		return this;
	}

}
