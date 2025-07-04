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
 * Optional arguments for the "clamp" operation.
 */
public class ClampOptions {

	private Double min;
	private Double max;

	/**
	 * Optional argument: min
	 * <p>
	 * Minimum value
	 * @return the value of {@code min}
	 */
	public Double getMin() {
		return this.min;
	}

	/**
	 * Set the optional "min" argument.
	 * <p>
	 * Minimum value
	 * @param min the new value of {@code min}
	 */
	public void setMin(Double min) {
		this.min = min;
	}

	/**
	 * Set the optional "min" argument.
	 * <p>
	 * Minimum value
	 * @param min the new value of {@code min}
	 * @return this object for chaining
	 */
	public ClampOptions min(Double min) {
		setMin(min);
		return this;
	}

	/**
	 * Optional argument: max
	 * <p>
	 * Maximum value
	 * @return the value of {@code max}
	 */
	public Double getMax() {
		return this.max;
	}

	/**
	 * Set the optional "max" argument.
	 * <p>
	 * Maximum value
	 * @param max the new value of {@code max}
	 */
	public void setMax(Double max) {
		this.max = max;
	}

	/**
	 * Set the optional "max" argument.
	 * <p>
	 * Maximum value
	 * @param max the new value of {@code max}
	 * @return this object for chaining
	 */
	public ClampOptions max(Double max) {
		setMax(max);
		return this;
	}

}
