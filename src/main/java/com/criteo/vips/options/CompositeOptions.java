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
 * Optional arguments for the "composite" operation.
 */
public class CompositeOptions {

	private int[] x;
	private int[] y;
	private com.criteo.vips.enums.VipsInterpretation compositingSpace;
	private Boolean premultiplied;

	/**
	 * Optional argument: x
	 * <p>
	 * Array of x coordinates to join at
	 * @return the value of {@code x}
	 */
	public int[] getX() {
		return this.x;
	}

	/**
	 * Set the optional "x" argument.
	 * <p>
	 * Array of x coordinates to join at
	 * @param x the new value of {@code x}
	 */
	public void setX(int[] x) {
		this.x = x;
	}

	/**
	 * Set the optional "x" argument.
	 * <p>
	 * Array of x coordinates to join at
	 * @param x the new value of {@code x}
	 * @return this object for chaining
	 */
	public CompositeOptions x(int[] x) {
		setX(x);
		return this;
	}

	/**
	 * Optional argument: y
	 * <p>
	 * Array of y coordinates to join at
	 * @return the value of {@code y}
	 */
	public int[] getY() {
		return this.y;
	}

	/**
	 * Set the optional "y" argument.
	 * <p>
	 * Array of y coordinates to join at
	 * @param y the new value of {@code y}
	 */
	public void setY(int[] y) {
		this.y = y;
	}

	/**
	 * Set the optional "y" argument.
	 * <p>
	 * Array of y coordinates to join at
	 * @param y the new value of {@code y}
	 * @return this object for chaining
	 */
	public CompositeOptions y(int[] y) {
		setY(y);
		return this;
	}

	/**
	 * Optional argument: compositing-space
	 * <p>
	 * Composite images in this colour space
	 * @return the value of {@code compositingSpace}
	 */
	public com.criteo.vips.enums.VipsInterpretation getCompositingSpace() {
		return this.compositingSpace;
	}

	/**
	 * Set the optional "compositing-space" argument.
	 * <p>
	 * Composite images in this colour space
	 * @param compositingSpace the new value of {@code compositingSpace}
	 */
	public void setCompositingSpace(com.criteo.vips.enums.VipsInterpretation compositingSpace) {
		this.compositingSpace = compositingSpace;
	}

	/**
	 * Set the optional "compositing-space" argument.
	 * <p>
	 * Composite images in this colour space
	 * @param compositingSpace the new value of {@code compositingSpace}
	 * @return this object for chaining
	 */
	public CompositeOptions compositingSpace(com.criteo.vips.enums.VipsInterpretation compositingSpace) {
		setCompositingSpace(compositingSpace);
		return this;
	}

	/**
	 * Optional argument: premultiplied
	 * <p>
	 * Images have premultiplied alpha
	 * @return the value of {@code premultiplied}
	 */
	public Boolean getPremultiplied() {
		return this.premultiplied;
	}

	/**
	 * Set the optional "premultiplied" argument.
	 * <p>
	 * Images have premultiplied alpha
	 * @param premultiplied the new value of {@code premultiplied}
	 */
	public void setPremultiplied(Boolean premultiplied) {
		this.premultiplied = premultiplied;
	}

	/**
	 * Set the optional "premultiplied" argument.
	 * <p>
	 * Images have premultiplied alpha
	 * @param premultiplied the new value of {@code premultiplied}
	 * @return this object for chaining
	 */
	public CompositeOptions premultiplied(Boolean premultiplied) {
		setPremultiplied(premultiplied);
		return this;
	}

}
