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
 * Optional arguments for the "find_trim" operation.
 */
public class FindTrimOptions {

	private Double threshold;
	private double[] background;
	private com.criteo.vips.PixelPacket backgroundPixelPacket;

	/**
	 * Optional argument: threshold
	 * <p>
	 * Object threshold
	 * @return the value of {@code threshold}
	 */
	public Double getThreshold() {
		return this.threshold;
	}

	/**
	 * Set the optional "threshold" argument.
	 * <p>
	 * Object threshold
	 * @param threshold the new value of {@code threshold}
	 */
	public void setThreshold(Double threshold) {
		this.threshold = threshold;
	}

	/**
	 * Set the optional "threshold" argument.
	 * <p>
	 * Object threshold
	 * @param threshold the new value of {@code threshold}
	 * @return this object for chaining
	 */
	public FindTrimOptions threshold(Double threshold) {
		setThreshold(threshold);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Color for background pixels
	 * @return the value of {@code background}
	 */
	public double[] getBackground() {
		return this.background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for background pixels
	 * @param background the new value of {@code background}
	 */
	public void setBackground(double[] background) {
		this.background = background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for background pixels
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public FindTrimOptions background(double[] background) {
		setBackground(background);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Color for background pixels
	 * @return the value of {@code background}
	 */
	public com.criteo.vips.PixelPacket getBackgroundPixelPacket() {
		return this.backgroundPixelPacket;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for background pixels
	 * @param background the new value of {@code background}
	 */
	public void setBackgroundPixelPacket(com.criteo.vips.PixelPacket background) {
		if (background != null) {
			this.backgroundPixelPacket = background;
		} else {
			this.backgroundPixelPacket = null;
		}
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for background pixels
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public FindTrimOptions backgroundPixelPacket(com.criteo.vips.PixelPacket background) {
		setBackgroundPixelPacket(background);
		return this;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for background pixels
	 * @param background the new value of {@code background}
	 */
	public void setBackground(java.awt.Color background) {
		if (background != null) {
			com.criteo.vips.PixelPacket pixelPacket = new com.criteo.vips.PixelPacket(background.getRed(), background.getGreen(), background.getBlue(), background.getAlpha());
			setBackgroundPixelPacket(pixelPacket);
		} else {
			setBackgroundPixelPacket(null);
		}
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for background pixels
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public FindTrimOptions background(java.awt.Color background) {
		setBackground(background);
		return this;
	}

}
