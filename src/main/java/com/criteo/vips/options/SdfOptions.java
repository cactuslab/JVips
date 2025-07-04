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
 * Optional arguments for the "sdf" operation.
 */
public class SdfOptions {

	private Double r;
	private double[] a;
	private com.criteo.vips.PixelPacket aPixelPacket;
	private double[] b;
	private com.criteo.vips.PixelPacket bPixelPacket;
	private double[] corners;
	private com.criteo.vips.PixelPacket cornersPixelPacket;

	/**
	 * Optional argument: r
	 * <p>
	 * Radius
	 * @return the value of {@code r}
	 */
	public Double getR() {
		return this.r;
	}

	/**
	 * Set the optional "r" argument.
	 * <p>
	 * Radius
	 * @param r the new value of {@code r}
	 */
	public void setR(Double r) {
		this.r = r;
	}

	/**
	 * Set the optional "r" argument.
	 * <p>
	 * Radius
	 * @param r the new value of {@code r}
	 * @return this object for chaining
	 */
	public SdfOptions r(Double r) {
		setR(r);
		return this;
	}

	/**
	 * Optional argument: a
	 * <p>
	 * Point a
	 * @return the value of {@code a}
	 */
	public double[] getA() {
		return this.a;
	}

	/**
	 * Set the optional "a" argument.
	 * <p>
	 * Point a
	 * @param a the new value of {@code a}
	 */
	public void setA(double[] a) {
		this.a = a;
	}

	/**
	 * Set the optional "a" argument.
	 * <p>
	 * Point a
	 * @param a the new value of {@code a}
	 * @return this object for chaining
	 */
	public SdfOptions a(double[] a) {
		setA(a);
		return this;
	}

	/**
	 * Optional argument: a
	 * <p>
	 * Point a
	 * @return the value of {@code a}
	 */
	public com.criteo.vips.PixelPacket getAPixelPacket() {
		return this.aPixelPacket;
	}

	/**
	 * Set the optional "a" argument.
	 * <p>
	 * Point a
	 * @param a the new value of {@code a}
	 */
	public void setAPixelPacket(com.criteo.vips.PixelPacket a) {
		if (a != null) {
			this.aPixelPacket = a;
		} else {
			this.aPixelPacket = null;
		}
	}

	/**
	 * Set the optional "a" argument.
	 * <p>
	 * Point a
	 * @param a the new value of {@code a}
	 * @return this object for chaining
	 */
	public SdfOptions aPixelPacket(com.criteo.vips.PixelPacket a) {
		setAPixelPacket(a);
		return this;
	}

	/**
	 * Set the optional "a" argument.
	 * <p>
	 * Point a
	 * @param a the new value of {@code a}
	 */
	public void setA(java.awt.Color a) {
		if (a != null) {
			com.criteo.vips.PixelPacket pixelPacket = new com.criteo.vips.PixelPacket(a);
			setAPixelPacket(pixelPacket);
		} else {
			setAPixelPacket(null);
		}
	}

	/**
	 * Set the optional "a" argument.
	 * <p>
	 * Point a
	 * @param a the new value of {@code a}
	 * @return this object for chaining
	 */
	public SdfOptions a(java.awt.Color a) {
		setA(a);
		return this;
	}

	/**
	 * Optional argument: b
	 * <p>
	 * Point b
	 * @return the value of {@code b}
	 */
	public double[] getB() {
		return this.b;
	}

	/**
	 * Set the optional "b" argument.
	 * <p>
	 * Point b
	 * @param b the new value of {@code b}
	 */
	public void setB(double[] b) {
		this.b = b;
	}

	/**
	 * Set the optional "b" argument.
	 * <p>
	 * Point b
	 * @param b the new value of {@code b}
	 * @return this object for chaining
	 */
	public SdfOptions b(double[] b) {
		setB(b);
		return this;
	}

	/**
	 * Optional argument: b
	 * <p>
	 * Point b
	 * @return the value of {@code b}
	 */
	public com.criteo.vips.PixelPacket getBPixelPacket() {
		return this.bPixelPacket;
	}

	/**
	 * Set the optional "b" argument.
	 * <p>
	 * Point b
	 * @param b the new value of {@code b}
	 */
	public void setBPixelPacket(com.criteo.vips.PixelPacket b) {
		if (b != null) {
			this.bPixelPacket = b;
		} else {
			this.bPixelPacket = null;
		}
	}

	/**
	 * Set the optional "b" argument.
	 * <p>
	 * Point b
	 * @param b the new value of {@code b}
	 * @return this object for chaining
	 */
	public SdfOptions bPixelPacket(com.criteo.vips.PixelPacket b) {
		setBPixelPacket(b);
		return this;
	}

	/**
	 * Set the optional "b" argument.
	 * <p>
	 * Point b
	 * @param b the new value of {@code b}
	 */
	public void setB(java.awt.Color b) {
		if (b != null) {
			com.criteo.vips.PixelPacket pixelPacket = new com.criteo.vips.PixelPacket(b);
			setBPixelPacket(pixelPacket);
		} else {
			setBPixelPacket(null);
		}
	}

	/**
	 * Set the optional "b" argument.
	 * <p>
	 * Point b
	 * @param b the new value of {@code b}
	 * @return this object for chaining
	 */
	public SdfOptions b(java.awt.Color b) {
		setB(b);
		return this;
	}

	/**
	 * Optional argument: corners
	 * <p>
	 * Corner radii
	 * @return the value of {@code corners}
	 */
	public double[] getCorners() {
		return this.corners;
	}

	/**
	 * Set the optional "corners" argument.
	 * <p>
	 * Corner radii
	 * @param corners the new value of {@code corners}
	 */
	public void setCorners(double[] corners) {
		this.corners = corners;
	}

	/**
	 * Set the optional "corners" argument.
	 * <p>
	 * Corner radii
	 * @param corners the new value of {@code corners}
	 * @return this object for chaining
	 */
	public SdfOptions corners(double[] corners) {
		setCorners(corners);
		return this;
	}

	/**
	 * Optional argument: corners
	 * <p>
	 * Corner radii
	 * @return the value of {@code corners}
	 */
	public com.criteo.vips.PixelPacket getCornersPixelPacket() {
		return this.cornersPixelPacket;
	}

	/**
	 * Set the optional "corners" argument.
	 * <p>
	 * Corner radii
	 * @param corners the new value of {@code corners}
	 */
	public void setCornersPixelPacket(com.criteo.vips.PixelPacket corners) {
		if (corners != null) {
			this.cornersPixelPacket = corners;
		} else {
			this.cornersPixelPacket = null;
		}
	}

	/**
	 * Set the optional "corners" argument.
	 * <p>
	 * Corner radii
	 * @param corners the new value of {@code corners}
	 * @return this object for chaining
	 */
	public SdfOptions cornersPixelPacket(com.criteo.vips.PixelPacket corners) {
		setCornersPixelPacket(corners);
		return this;
	}

	/**
	 * Set the optional "corners" argument.
	 * <p>
	 * Corner radii
	 * @param corners the new value of {@code corners}
	 */
	public void setCorners(java.awt.Color corners) {
		if (corners != null) {
			com.criteo.vips.PixelPacket pixelPacket = new com.criteo.vips.PixelPacket(corners);
			setCornersPixelPacket(pixelPacket);
		} else {
			setCornersPixelPacket(null);
		}
	}

	/**
	 * Set the optional "corners" argument.
	 * <p>
	 * Corner radii
	 * @param corners the new value of {@code corners}
	 * @return this object for chaining
	 */
	public SdfOptions corners(java.awt.Color corners) {
		setCorners(corners);
		return this;
	}

}
