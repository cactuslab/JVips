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
 * Optional arguments for the "sharpen" operation.
 */
public class SharpenOptions {

	private Double sigma;
	private Double x1;
	private Double y2;
	private Double y3;
	private Double m1;
	private Double m2;

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
	public SharpenOptions sigma(Double sigma) {
		setSigma(sigma);
		return this;
	}

	/**
	 * Optional argument: x1
	 * <p>
	 * Flat/jaggy threshold
	 * @return the value of {@code x1}
	 */
	public Double getX1() {
		return this.x1;
	}

	/**
	 * Set the optional "x1" argument.
	 * <p>
	 * Flat/jaggy threshold
	 * @param x1 the new value of {@code x1}
	 */
	public void setX1(Double x1) {
		this.x1 = x1;
	}

	/**
	 * Set the optional "x1" argument.
	 * <p>
	 * Flat/jaggy threshold
	 * @param x1 the new value of {@code x1}
	 * @return this object for chaining
	 */
	public SharpenOptions x1(Double x1) {
		setX1(x1);
		return this;
	}

	/**
	 * Optional argument: y2
	 * <p>
	 * Maximum brightening
	 * @return the value of {@code y2}
	 */
	public Double getY2() {
		return this.y2;
	}

	/**
	 * Set the optional "y2" argument.
	 * <p>
	 * Maximum brightening
	 * @param y2 the new value of {@code y2}
	 */
	public void setY2(Double y2) {
		this.y2 = y2;
	}

	/**
	 * Set the optional "y2" argument.
	 * <p>
	 * Maximum brightening
	 * @param y2 the new value of {@code y2}
	 * @return this object for chaining
	 */
	public SharpenOptions y2(Double y2) {
		setY2(y2);
		return this;
	}

	/**
	 * Optional argument: y3
	 * <p>
	 * Maximum darkening
	 * @return the value of {@code y3}
	 */
	public Double getY3() {
		return this.y3;
	}

	/**
	 * Set the optional "y3" argument.
	 * <p>
	 * Maximum darkening
	 * @param y3 the new value of {@code y3}
	 */
	public void setY3(Double y3) {
		this.y3 = y3;
	}

	/**
	 * Set the optional "y3" argument.
	 * <p>
	 * Maximum darkening
	 * @param y3 the new value of {@code y3}
	 * @return this object for chaining
	 */
	public SharpenOptions y3(Double y3) {
		setY3(y3);
		return this;
	}

	/**
	 * Optional argument: m1
	 * <p>
	 * Slope for flat areas
	 * @return the value of {@code m1}
	 */
	public Double getM1() {
		return this.m1;
	}

	/**
	 * Set the optional "m1" argument.
	 * <p>
	 * Slope for flat areas
	 * @param m1 the new value of {@code m1}
	 */
	public void setM1(Double m1) {
		this.m1 = m1;
	}

	/**
	 * Set the optional "m1" argument.
	 * <p>
	 * Slope for flat areas
	 * @param m1 the new value of {@code m1}
	 * @return this object for chaining
	 */
	public SharpenOptions m1(Double m1) {
		setM1(m1);
		return this;
	}

	/**
	 * Optional argument: m2
	 * <p>
	 * Slope for jaggy areas
	 * @return the value of {@code m2}
	 */
	public Double getM2() {
		return this.m2;
	}

	/**
	 * Set the optional "m2" argument.
	 * <p>
	 * Slope for jaggy areas
	 * @param m2 the new value of {@code m2}
	 */
	public void setM2(Double m2) {
		this.m2 = m2;
	}

	/**
	 * Set the optional "m2" argument.
	 * <p>
	 * Slope for jaggy areas
	 * @param m2 the new value of {@code m2}
	 * @return this object for chaining
	 */
	public SharpenOptions m2(Double m2) {
		setM2(m2);
		return this;
	}

}
