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
 * Optional arguments for the "globalbalance" operation.
 */
public class GlobalbalanceOptions {

	private Double gamma;
	private Boolean intOutput;

	/**
	 * Optional argument: gamma
	 * <p>
	 * Image gamma
	 * @return the value of {@code gamma}
	 */
	public Double getGamma() {
		return this.gamma;
	}

	/**
	 * Set the optional "gamma" argument.
	 * <p>
	 * Image gamma
	 * @param gamma the new value of {@code gamma}
	 */
	public void setGamma(Double gamma) {
		this.gamma = gamma;
	}

	/**
	 * Set the optional "gamma" argument.
	 * <p>
	 * Image gamma
	 * @param gamma the new value of {@code gamma}
	 * @return this object for chaining
	 */
	public GlobalbalanceOptions gamma(Double gamma) {
		setGamma(gamma);
		return this;
	}

	/**
	 * Optional argument: int-output
	 * <p>
	 * Integer output
	 * @return the value of {@code intOutput}
	 */
	public Boolean getIntOutput() {
		return this.intOutput;
	}

	/**
	 * Set the optional "int-output" argument.
	 * <p>
	 * Integer output
	 * @param intOutput the new value of {@code intOutput}
	 */
	public void setIntOutput(Boolean intOutput) {
		this.intOutput = intOutput;
	}

	/**
	 * Set the optional "int-output" argument.
	 * <p>
	 * Integer output
	 * @param intOutput the new value of {@code intOutput}
	 * @return this object for chaining
	 */
	public GlobalbalanceOptions intOutput(Boolean intOutput) {
		setIntOutput(intOutput);
		return this;
	}

}
