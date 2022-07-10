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
import com.criteo.vips.enums.*;

/**
 * Optional arguments for the "arrayjoin" operation.
 */
public class ArrayjoinOptions {

	private Integer across;
	private Integer shim;
	private double[] background;
	private VipsAlign halign;
	private VipsAlign valign;
	private Integer hspacing;
	private Integer vspacing;

	/**
	 * Optional argument: across
	 * <p>
	 * Number of images across grid
	 * @return the value of {@code across}
	 */
	public Integer getAcross() {
		return this.across;
	}

	/**
	 * Set the optional "across" argument.
	 * <p>
	 * Number of images across grid
	 * @param across the new value of {@code across}
	 */
	public void setAcross(Integer across) {
		this.across = across;
	}

	/**
	 * Set the optional "across" argument.
	 * <p>
	 * Number of images across grid
	 * @param across the new value of {@code across}
	 * @return this object for chaining
	 */
	public ArrayjoinOptions across(Integer across) {
		setAcross(across);
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
	public ArrayjoinOptions shim(Integer shim) {
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
	public ArrayjoinOptions background(double[] background) {
		setBackground(background);
		return this;
	}

	/**
	 * Optional argument: halign
	 * <p>
	 * Align on the left, centre or right
	 * @return the value of {@code halign}
	 */
	public VipsAlign getHalign() {
		return this.halign;
	}

	/**
	 * Set the optional "halign" argument.
	 * <p>
	 * Align on the left, centre or right
	 * @param halign the new value of {@code halign}
	 */
	public void setHalign(VipsAlign halign) {
		this.halign = halign;
	}

	/**
	 * Set the optional "halign" argument.
	 * <p>
	 * Align on the left, centre or right
	 * @param halign the new value of {@code halign}
	 * @return this object for chaining
	 */
	public ArrayjoinOptions halign(VipsAlign halign) {
		setHalign(halign);
		return this;
	}

	/**
	 * Optional argument: valign
	 * <p>
	 * Align on the top, centre or bottom
	 * @return the value of {@code valign}
	 */
	public VipsAlign getValign() {
		return this.valign;
	}

	/**
	 * Set the optional "valign" argument.
	 * <p>
	 * Align on the top, centre or bottom
	 * @param valign the new value of {@code valign}
	 */
	public void setValign(VipsAlign valign) {
		this.valign = valign;
	}

	/**
	 * Set the optional "valign" argument.
	 * <p>
	 * Align on the top, centre or bottom
	 * @param valign the new value of {@code valign}
	 * @return this object for chaining
	 */
	public ArrayjoinOptions valign(VipsAlign valign) {
		setValign(valign);
		return this;
	}

	/**
	 * Optional argument: hspacing
	 * <p>
	 * Horizontal spacing between images
	 * @return the value of {@code hspacing}
	 */
	public Integer getHspacing() {
		return this.hspacing;
	}

	/**
	 * Set the optional "hspacing" argument.
	 * <p>
	 * Horizontal spacing between images
	 * @param hspacing the new value of {@code hspacing}
	 */
	public void setHspacing(Integer hspacing) {
		this.hspacing = hspacing;
	}

	/**
	 * Set the optional "hspacing" argument.
	 * <p>
	 * Horizontal spacing between images
	 * @param hspacing the new value of {@code hspacing}
	 * @return this object for chaining
	 */
	public ArrayjoinOptions hspacing(Integer hspacing) {
		setHspacing(hspacing);
		return this;
	}

	/**
	 * Optional argument: vspacing
	 * <p>
	 * Vertical spacing between images
	 * @return the value of {@code vspacing}
	 */
	public Integer getVspacing() {
		return this.vspacing;
	}

	/**
	 * Set the optional "vspacing" argument.
	 * <p>
	 * Vertical spacing between images
	 * @param vspacing the new value of {@code vspacing}
	 */
	public void setVspacing(Integer vspacing) {
		this.vspacing = vspacing;
	}

	/**
	 * Set the optional "vspacing" argument.
	 * <p>
	 * Vertical spacing between images
	 * @param vspacing the new value of {@code vspacing}
	 * @return this object for chaining
	 */
	public ArrayjoinOptions vspacing(Integer vspacing) {
		setVspacing(vspacing);
		return this;
	}

}
