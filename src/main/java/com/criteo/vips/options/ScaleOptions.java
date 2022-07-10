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
 * Optional arguments for the "scale" operation.
 */
public class ScaleOptions {

	private Double exp;
	private Boolean log;

	/**
	 * Optional argument: exp
	 * <p>
	 * Exponent for log scale
	 * @return the value of {@code exp}
	 */
	public Double getExp() {
		return this.exp;
	}

	/**
	 * Set the optional "exp" argument.
	 * <p>
	 * Exponent for log scale
	 * @param exp the new value of {@code exp}
	 */
	public void setExp(Double exp) {
		this.exp = exp;
	}

	/**
	 * Set the optional "exp" argument.
	 * <p>
	 * Exponent for log scale
	 * @param exp the new value of {@code exp}
	 * @return this object for chaining
	 */
	public ScaleOptions exp(Double exp) {
		setExp(exp);
		return this;
	}

	/**
	 * Optional argument: log
	 * <p>
	 * Log scale
	 * @return the value of {@code log}
	 */
	public Boolean getLog() {
		return this.log;
	}

	/**
	 * Set the optional "log" argument.
	 * <p>
	 * Log scale
	 * @param log the new value of {@code log}
	 */
	public void setLog(Boolean log) {
		this.log = log;
	}

	/**
	 * Set the optional "log" argument.
	 * <p>
	 * Log scale
	 * @param log the new value of {@code log}
	 * @return this object for chaining
	 */
	public ScaleOptions log(Boolean log) {
		setLog(log);
		return this;
	}

}
