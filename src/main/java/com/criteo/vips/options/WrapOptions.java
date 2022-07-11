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
 * Optional arguments for the "wrap" operation.
 */
public class WrapOptions {

	private Integer x;
	private Integer y;

	/**
	 * Optional argument: x
	 * <p>
	 * Left edge of input in output
	 * @return the value of {@code x}
	 */
	public Integer getX() {
		return this.x;
	}

	/**
	 * Set the optional "x" argument.
	 * <p>
	 * Left edge of input in output
	 * @param x the new value of {@code x}
	 */
	public void setX(Integer x) {
		this.x = x;
	}

	/**
	 * Set the optional "x" argument.
	 * <p>
	 * Left edge of input in output
	 * @param x the new value of {@code x}
	 * @return this object for chaining
	 */
	public WrapOptions x(Integer x) {
		setX(x);
		return this;
	}

	/**
	 * Optional argument: y
	 * <p>
	 * Top edge of input in output
	 * @return the value of {@code y}
	 */
	public Integer getY() {
		return this.y;
	}

	/**
	 * Set the optional "y" argument.
	 * <p>
	 * Top edge of input in output
	 * @param y the new value of {@code y}
	 */
	public void setY(Integer y) {
		this.y = y;
	}

	/**
	 * Set the optional "y" argument.
	 * <p>
	 * Top edge of input in output
	 * @param y the new value of {@code y}
	 * @return this object for chaining
	 */
	public WrapOptions y(Integer y) {
		setY(y);
		return this;
	}

}
