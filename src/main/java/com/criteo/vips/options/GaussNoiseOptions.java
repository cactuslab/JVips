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
 * Optional arguments for the "gaussnoise" operation.
 */
public class GaussNoiseOptions {

	private Double sigma;
	private Double mean;
	private Integer seed;

	/**
	 * Optional argument: sigma
	 * <p>
	 * Standard deviation of pixels in generated image
	 * @return the value of {@code sigma}
	 */
	public Double getSigma() {
		return this.sigma;
	}

	/**
	 * Set the optional "sigma" argument.
	 * <p>
	 * Standard deviation of pixels in generated image
	 * @param sigma the new value of {@code sigma}
	 */
	public void setSigma(Double sigma) {
		this.sigma = sigma;
	}

	/**
	 * Set the optional "sigma" argument.
	 * <p>
	 * Standard deviation of pixels in generated image
	 * @param sigma the new value of {@code sigma}
	 * @return this object for chaining
	 */
	public GaussNoiseOptions sigma(Double sigma) {
		setSigma(sigma);
		return this;
	}

	/**
	 * Optional argument: mean
	 * <p>
	 * Mean of pixels in generated image
	 * @return the value of {@code mean}
	 */
	public Double getMean() {
		return this.mean;
	}

	/**
	 * Set the optional "mean" argument.
	 * <p>
	 * Mean of pixels in generated image
	 * @param mean the new value of {@code mean}
	 */
	public void setMean(Double mean) {
		this.mean = mean;
	}

	/**
	 * Set the optional "mean" argument.
	 * <p>
	 * Mean of pixels in generated image
	 * @param mean the new value of {@code mean}
	 * @return this object for chaining
	 */
	public GaussNoiseOptions mean(Double mean) {
		setMean(mean);
		return this;
	}

	/**
	 * Optional argument: seed
	 * <p>
	 * Random number seed
	 * @return the value of {@code seed}
	 */
	public Integer getSeed() {
		return this.seed;
	}

	/**
	 * Set the optional "seed" argument.
	 * <p>
	 * Random number seed
	 * @param seed the new value of {@code seed}
	 */
	public void setSeed(Integer seed) {
		this.seed = seed;
	}

	/**
	 * Set the optional "seed" argument.
	 * <p>
	 * Random number seed
	 * @param seed the new value of {@code seed}
	 * @return this object for chaining
	 */
	public GaussNoiseOptions seed(Integer seed) {
		setSeed(seed);
		return this;
	}

}
