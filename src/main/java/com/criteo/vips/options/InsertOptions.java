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
 * Optional arguments for the "insert" operation.
 */
public class InsertOptions {

	private Boolean expand;
	private double[] background;
	private PixelPacket backgroundPixelPacket;

	/**
	 * Optional argument: expand
	 * <p>
	 * Expand output to hold all of both inputs
	 * @return the value of {@code expand}
	 */
	public Boolean getExpand() {
		return this.expand;
	}

	/**
	 * Set the optional "expand" argument.
	 * <p>
	 * Expand output to hold all of both inputs
	 * @param expand the new value of {@code expand}
	 */
	public void setExpand(Boolean expand) {
		this.expand = expand;
	}

	/**
	 * Set the optional "expand" argument.
	 * <p>
	 * Expand output to hold all of both inputs
	 * @param expand the new value of {@code expand}
	 * @return this object for chaining
	 */
	public InsertOptions expand(Boolean expand) {
		setExpand(expand);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Color for new pixels
	 * @return the value of {@code background}
	 */
	public double[] getBackground() {
		return this.background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for new pixels
	 * @param background the new value of {@code background}
	 */
	public void setBackground(double[] background) {
		this.background = background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for new pixels
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public InsertOptions background(double[] background) {
		setBackground(background);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Color for new pixels
	 * @return the value of {@code background}
	 */
	public PixelPacket getBackgroundPixelPacket() {
		return this.backgroundPixelPacket;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for new pixels
	 * @param background the new value of {@code background}
	 */
	public void setBackgroundPixelPacket(PixelPacket background) {
		if (background != null) {
			this.backgroundPixelPacket = background;
		} else {
			this.backgroundPixelPacket = null;
		}
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for new pixels
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public InsertOptions backgroundPixelPacket(PixelPacket background) {
		setBackgroundPixelPacket(background);
		return this;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for new pixels
	 * @param background the new value of {@code background}
	 */
	public void setBackground(java.awt.Color background) {
		if (background != null) {
			float[] components = background.getComponents(new float[4]);
			PixelPacket pixelPacket = new PixelPacket(components[0], components[1], components[2], components[3]);
			setBackgroundPixelPacket(pixelPacket);
		} else {
			setBackgroundPixelPacket(null);
		}
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for new pixels
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public InsertOptions background(java.awt.Color background) {
		setBackground(background);
		return this;
	}

}
