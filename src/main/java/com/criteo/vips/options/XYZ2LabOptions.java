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
 * Optional arguments for the "XYZ2Lab" operation.
 */
public class XYZ2LabOptions {

	private PixelPacket temp;

	/**
	 * Optional argument: temp
	 * <p>
	 * Colour temperature
	 * @return the value of {@code temp}
	 */
	public PixelPacket getTemp() {
		return this.temp;
	}

	/**
	 * Set the optional "temp" argument.
	 * <p>
	 * Colour temperature
	 * @param temp the new value of {@code temp}
	 */
	public void setTemp(PixelPacket temp) {
		this.temp = temp;
	}

	/**
	 * Set the optional "temp" argument.
	 * <p>
	 * Colour temperature
	 * @param temp the new value of {@code temp}
	 * @return this object for chaining
	 */
	public XYZ2LabOptions temp(PixelPacket temp) {
		setTemp(temp);
		return this;
	}

}
