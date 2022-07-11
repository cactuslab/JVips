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
 * Optional arguments for the "black" operation.
 */
public class BlackOptions {

	private Integer bands;

	/**
	 * Optional argument: bands
	 * <p>
	 * Number of bands in image
	 * @return the value of {@code bands}
	 */
	public Integer getBands() {
		return this.bands;
	}

	/**
	 * Set the optional "bands" argument.
	 * <p>
	 * Number of bands in image
	 * @param bands the new value of {@code bands}
	 */
	public void setBands(Integer bands) {
		this.bands = bands;
	}

	/**
	 * Set the optional "bands" argument.
	 * <p>
	 * Number of bands in image
	 * @param bands the new value of {@code bands}
	 * @return this object for chaining
	 */
	public BlackOptions bands(Integer bands) {
		setBands(bands);
		return this;
	}

}
