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
 * Optional arguments for the "hist_local" operation.
 */
public class HistLocalOptions {

	private Integer maxSlope;

	/**
	 * Optional argument: max-slope
	 * <p>
	 * Maximum slope (CLAHE)
	 * @return the value of {@code maxSlope}
	 */
	public Integer getMaxSlope() {
		return this.maxSlope;
	}

	/**
	 * Set the optional "max-slope" argument.
	 * <p>
	 * Maximum slope (CLAHE)
	 * @param maxSlope the new value of {@code maxSlope}
	 */
	public void setMaxSlope(Integer maxSlope) {
		this.maxSlope = maxSlope;
	}

	/**
	 * Set the optional "max-slope" argument.
	 * <p>
	 * Maximum slope (CLAHE)
	 * @param maxSlope the new value of {@code maxSlope}
	 * @return this object for chaining
	 */
	public HistLocalOptions maxSlope(Integer maxSlope) {
		setMaxSlope(maxSlope);
		return this;
	}

}
