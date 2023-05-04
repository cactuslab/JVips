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

/**
 * Optional arguments for the "Lab2XYZ" operation.
 */
public class LAB2XYZOptions {

	private double[] temp;
	private com.criteo.vips.PixelPacket tempPixelPacket;

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
	public com.criteo.vips.PixelPacket getTempPixelPacket() {
		return this.tempPixelPacket;
	}

	/**
	 * Set the optional "temp" argument.
	 * <p>
	 * Color temperature
	 * @param temp the new value of {@code temp}
	 */
	public void setTempPixelPacket(com.criteo.vips.PixelPacket temp) {
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
	public LAB2XYZOptions tempPixelPacket(com.criteo.vips.PixelPacket temp) {
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
			com.criteo.vips.PixelPacket pixelPacket = new com.criteo.vips.PixelPacket(temp.getRed(), temp.getGreen(), temp.getBlue(), temp.getAlpha());
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
