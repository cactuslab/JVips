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
 * Optional arguments for the "min" operation.
 */
public class MinOptions {

	private Integer size;

	/**
	 * Optional argument: size
	 * <p>
	 * Number of minimum values to find
	 * @return the value of {@code size}
	 */
	public Integer getSize() {
		return this.size;
	}

	/**
	 * Set the optional "size" argument.
	 * <p>
	 * Number of minimum values to find
	 * @param size the new value of {@code size}
	 */
	public void setSize(Integer size) {
		this.size = size;
	}

	/**
	 * Set the optional "size" argument.
	 * <p>
	 * Number of minimum values to find
	 * @param size the new value of {@code size}
	 * @return this object for chaining
	 */
	public MinOptions size(Integer size) {
		setSize(size);
		return this;
	}

}
