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
 * Optional arguments for the "logmat" operation.
 */
public class LogmatOptions {

	private Boolean separable;
	private com.criteo.vips.enums.VipsPrecision precision;

	/**
	 * Optional argument: separable
	 * <p>
	 * Generate separable Gaussian
	 * @return the value of {@code separable}
	 */
	public Boolean getSeparable() {
		return this.separable;
	}

	/**
	 * Set the optional "separable" argument.
	 * <p>
	 * Generate separable Gaussian
	 * @param separable the new value of {@code separable}
	 */
	public void setSeparable(Boolean separable) {
		this.separable = separable;
	}

	/**
	 * Set the optional "separable" argument.
	 * <p>
	 * Generate separable Gaussian
	 * @param separable the new value of {@code separable}
	 * @return this object for chaining
	 */
	public LogmatOptions separable(Boolean separable) {
		setSeparable(separable);
		return this;
	}

	/**
	 * Optional argument: precision
	 * <p>
	 * Generate with this precision
	 * @return the value of {@code precision}
	 */
	public com.criteo.vips.enums.VipsPrecision getPrecision() {
		return this.precision;
	}

	/**
	 * Set the optional "precision" argument.
	 * <p>
	 * Generate with this precision
	 * @param precision the new value of {@code precision}
	 */
	public void setPrecision(com.criteo.vips.enums.VipsPrecision precision) {
		this.precision = precision;
	}

	/**
	 * Set the optional "precision" argument.
	 * <p>
	 * Generate with this precision
	 * @param precision the new value of {@code precision}
	 * @return this object for chaining
	 */
	public LogmatOptions precision(com.criteo.vips.enums.VipsPrecision precision) {
		setPrecision(precision);
		return this;
	}

}
