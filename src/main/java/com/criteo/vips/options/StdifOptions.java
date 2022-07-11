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
 * Optional arguments for the "stdif" operation.
 */
public class StdifOptions {

	private Double s0;
	private Double b;
	private Double m0;
	private Double a;

	/**
	 * Optional argument: s0
	 * <p>
	 * New deviation
	 * @return the value of {@code s0}
	 */
	public Double getS0() {
		return this.s0;
	}

	/**
	 * Set the optional "s0" argument.
	 * <p>
	 * New deviation
	 * @param s0 the new value of {@code s0}
	 */
	public void setS0(Double s0) {
		this.s0 = s0;
	}

	/**
	 * Set the optional "s0" argument.
	 * <p>
	 * New deviation
	 * @param s0 the new value of {@code s0}
	 * @return this object for chaining
	 */
	public StdifOptions s0(Double s0) {
		setS0(s0);
		return this;
	}

	/**
	 * Optional argument: b
	 * <p>
	 * Weight of new deviation
	 * @return the value of {@code b}
	 */
	public Double getB() {
		return this.b;
	}

	/**
	 * Set the optional "b" argument.
	 * <p>
	 * Weight of new deviation
	 * @param b the new value of {@code b}
	 */
	public void setB(Double b) {
		this.b = b;
	}

	/**
	 * Set the optional "b" argument.
	 * <p>
	 * Weight of new deviation
	 * @param b the new value of {@code b}
	 * @return this object for chaining
	 */
	public StdifOptions b(Double b) {
		setB(b);
		return this;
	}

	/**
	 * Optional argument: m0
	 * <p>
	 * New mean
	 * @return the value of {@code m0}
	 */
	public Double getM0() {
		return this.m0;
	}

	/**
	 * Set the optional "m0" argument.
	 * <p>
	 * New mean
	 * @param m0 the new value of {@code m0}
	 */
	public void setM0(Double m0) {
		this.m0 = m0;
	}

	/**
	 * Set the optional "m0" argument.
	 * <p>
	 * New mean
	 * @param m0 the new value of {@code m0}
	 * @return this object for chaining
	 */
	public StdifOptions m0(Double m0) {
		setM0(m0);
		return this;
	}

	/**
	 * Optional argument: a
	 * <p>
	 * Weight of new mean
	 * @return the value of {@code a}
	 */
	public Double getA() {
		return this.a;
	}

	/**
	 * Set the optional "a" argument.
	 * <p>
	 * Weight of new mean
	 * @param a the new value of {@code a}
	 */
	public void setA(Double a) {
		this.a = a;
	}

	/**
	 * Set the optional "a" argument.
	 * <p>
	 * Weight of new mean
	 * @param a the new value of {@code a}
	 * @return this object for chaining
	 */
	public StdifOptions a(Double a) {
		setA(a);
		return this;
	}

}
