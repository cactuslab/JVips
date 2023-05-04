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
 * Optional arguments for the "bandfold" operation.
 */
public class BandfoldOptions {

	private Integer factor;

	/**
	 * Optional argument: factor
	 * <p>
	 * Fold by this factor
	 * @return the value of {@code factor}
	 */
	public Integer getFactor() {
		return this.factor;
	}

	/**
	 * Set the optional "factor" argument.
	 * <p>
	 * Fold by this factor
	 * @param factor the new value of {@code factor}
	 */
	public void setFactor(Integer factor) {
		this.factor = factor;
	}

	/**
	 * Set the optional "factor" argument.
	 * <p>
	 * Fold by this factor
	 * @param factor the new value of {@code factor}
	 * @return this object for chaining
	 */
	public BandfoldOptions factor(Integer factor) {
		setFactor(factor);
		return this;
	}

}
