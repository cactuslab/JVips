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
 * Optional arguments for the "draw_circle" operation.
 */
public class DrawCircleOptions {

	private Boolean fill;

	/**
	 * Optional argument: fill
	 * <p>
	 * Draw a solid object
	 * @return the value of {@code fill}
	 */
	public Boolean getFill() {
		return this.fill;
	}

	/**
	 * Set the optional "fill" argument.
	 * <p>
	 * Draw a solid object
	 * @param fill the new value of {@code fill}
	 */
	public void setFill(Boolean fill) {
		this.fill = fill;
	}

	/**
	 * Set the optional "fill" argument.
	 * <p>
	 * Draw a solid object
	 * @param fill the new value of {@code fill}
	 * @return this object for chaining
	 */
	public DrawCircleOptions fill(Boolean fill) {
		setFill(fill);
		return this;
	}

}
