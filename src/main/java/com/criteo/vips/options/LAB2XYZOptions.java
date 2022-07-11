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
 * Optional arguments for the "Lab2XYZ" operation.
 */
public class LAB2XYZOptions {

	private double[] temp;
	private PixelPacket tempPixelPacket;

	/**
	 * Optional argument: temp
	 * <p>
	 * Color temperature
	 * @return the value of {@code temp}
	 */
	public double[] getTemp() {
		return this.temp;
	}

	/**
	 * Set the optional "temp" argument.
	 * <p>
	 * Color temperature
	 * @param temp the new value of {@code temp}
	 */
	public void setTemp(double[] temp) {
		this.temp = temp;
	}

	/**
	 * Set the optional "temp" argument.
	 * <p>
	 * Color temperature
	 * @param temp the new value of {@code temp}
	 * @return this object for chaining
	 */
	public LAB2XYZOptions temp(double[] temp) {
		setTemp(temp);
		return this;
	}

	/**
	 * Optional argument: temp
	 * <p>
	 * Color temperature
	 * @return the value of {@code temp}
	 */
	public PixelPacket getTempPixelPacket() {
		return this.tempPixelPacket;
	}

	/**
	 * Set the optional "temp" argument.
	 * <p>
	 * Color temperature
	 * @param temp the new value of {@code temp}
	 */
	public void setTempPixelPacket(PixelPacket temp) {
		if (temp != null) {
			this.tempPixelPacket = temp;
		} else {
			this.tempPixelPacket = null;
		}
	}

	/**
	 * Set the optional "temp" argument.
	 * <p>
	 * Color temperature
	 * @param temp the new value of {@code temp}
	 * @return this object for chaining
	 */
	public LAB2XYZOptions tempPixelPacket(PixelPacket temp) {
		setTempPixelPacket(temp);
		return this;
	}

	/**
	 * Set the optional "temp" argument.
	 * <p>
	 * Color temperature
	 * @param temp the new value of {@code temp}
	 */
	public void setTemp(java.awt.Color temp) {
		if (temp != null) {
			float[] components = temp.getComponents(new float[4]);
			PixelPacket pixelPacket = new PixelPacket(components[0], components[1], components[2], components[3]);
			setTempPixelPacket(pixelPacket);
		} else {
			setTempPixelPacket(null);
		}
	}

	/**
	 * Set the optional "temp" argument.
	 * <p>
	 * Color temperature
	 * @param temp the new value of {@code temp}
	 * @return this object for chaining
	 */
	public LAB2XYZOptions temp(java.awt.Color temp) {
		setTemp(temp);
		return this;
	}

}
