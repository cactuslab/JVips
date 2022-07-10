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
 * Optional arguments for the "extract_band" operation.
 */
public class ExtractBandOptions {

	private Integer n;

	/**
	 * Optional argument: n
	 * <p>
	 * Number of bands to extract
	 * @return the value of {@code n}
	 */
	public Integer getN() {
		return this.n;
	}

	/**
	 * Set the optional "n" argument.
	 * <p>
	 * Number of bands to extract
	 * @param n the new value of {@code n}
	 */
	public void setN(Integer n) {
		this.n = n;
	}

	/**
	 * Set the optional "n" argument.
	 * <p>
	 * Number of bands to extract
	 * @param n the new value of {@code n}
	 * @return this object for chaining
	 */
	public ExtractBandOptions n(Integer n) {
		setN(n);
		return this;
	}

}