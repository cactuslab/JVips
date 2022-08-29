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
 * Optional arguments for the "shrink" operation.
 */
public class ShrinkOptions {

	private Boolean ceil;

	/**
	 * Optional argument: ceil
	 * <p>
	 * Round-up output dimensions
	 * @return the value of {@code ceil}
	 */
	public Boolean getCeil() {
		return this.ceil;
	}

	/**
	 * Set the optional "ceil" argument.
	 * <p>
	 * Round-up output dimensions
	 * @param ceil the new value of {@code ceil}
	 */
	public void setCeil(Boolean ceil) {
		this.ceil = ceil;
	}

	/**
	 * Set the optional "ceil" argument.
	 * <p>
	 * Round-up output dimensions
	 * @param ceil the new value of {@code ceil}
	 * @return this object for chaining
	 */
	public ShrinkOptions ceil(Boolean ceil) {
		setCeil(ceil);
		return this;
	}

}
