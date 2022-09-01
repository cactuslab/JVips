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
 * Optional arguments for the "join" operation.
 */
public class JoinOptions {

	private Boolean expand;
	private Integer shim;
	private double[] background;
	private PixelPacket backgroundPixelPacket;
	private VipsAlign align;

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
	public JoinOptions expand(Boolean expand) {
		setExpand(expand);
		return this;
	}

	/**
	 * Optional argument: shim
	 * <p>
	 * Pixels between images
	 * @return the value of {@code shim}
	 */
	public Integer getShim() {
		return this.shim;
	}

	/**
	 * Set the optional "shim" argument.
	 * <p>
	 * Pixels between images
	 * @param shim the new value of {@code shim}
	 */
	public void setShim(Integer shim) {
		this.shim = shim;
	}

	/**
	 * Set the optional "shim" argument.
	 * <p>
	 * Pixels between images
	 * @param shim the new value of {@code shim}
	 * @return this object for chaining
	 */
	public JoinOptions shim(Integer shim) {
		setShim(shim);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Colour for new pixels
	 * @return the value of {@code background}
	 */
	public double[] getBackground() {
		return this.background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Colour for new pixels
	 * @param background the new value of {@code background}
	 */
	public void setBackground(double[] background) {
		this.background = background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Colour for new pixels
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public JoinOptions background(double[] background) {
		setBackground(background);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Colour for new pixels
	 * @return the value of {@code background}
	 */
	public PixelPacket getBackgroundPixelPacket() {
		return this.backgroundPixelPacket;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Colour for new pixels
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
	 * Colour for new pixels
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public JoinOptions backgroundPixelPacket(PixelPacket background) {
		setBackgroundPixelPacket(background);
		return this;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Colour for new pixels
	 * @param background the new value of {@code background}
	 */
	public void setBackground(java.awt.Color background) {
		if (background != null) {
			PixelPacket pixelPacket = new PixelPacket(background.getRed(), background.getGreen(), background.getBlue(), background.getAlpha());
			setBackgroundPixelPacket(pixelPacket);
		} else {
			setBackgroundPixelPacket(null);
		}
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Colour for new pixels
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public JoinOptions background(java.awt.Color background) {
		setBackground(background);
		return this;
	}

	/**
	 * Optional argument: align
	 * <p>
	 * Align on the low, centre or high coordinate edge
	 * @return the value of {@code align}
	 */
	public VipsAlign getAlign() {
		return this.align;
	}

	/**
	 * Set the optional "align" argument.
	 * <p>
	 * Align on the low, centre or high coordinate edge
	 * @param align the new value of {@code align}
	 */
	public void setAlign(VipsAlign align) {
		this.align = align;
	}

	/**
	 * Set the optional "align" argument.
	 * <p>
	 * Align on the low, centre or high coordinate edge
	 * @param align the new value of {@code align}
	 * @return this object for chaining
	 */
	public JoinOptions align(VipsAlign align) {
		setAlign(align);
		return this;
	}

}
