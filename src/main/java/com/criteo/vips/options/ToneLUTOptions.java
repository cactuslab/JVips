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
 * Optional arguments for the "tonelut" operation.
 */
public class ToneLUTOptions {

	private Integer inMax;
	private Integer outMax;
	private Double lb;
	private Double lw;
	private Double ps;
	private Double pm;
	private Double ph;
	private Double s;
	private Double m;
	private Double h;

	/**
	 * Optional argument: in-max
	 * <p>
	 * Size of LUT to build
	 * @return the value of {@code inMax}
	 */
	public Integer getInMax() {
		return this.inMax;
	}

	/**
	 * Set the optional "in-max" argument.
	 * <p>
	 * Size of LUT to build
	 * @param inMax the new value of {@code inMax}
	 */
	public void setInMax(Integer inMax) {
		this.inMax = inMax;
	}

	/**
	 * Set the optional "in-max" argument.
	 * <p>
	 * Size of LUT to build
	 * @param inMax the new value of {@code inMax}
	 * @return this object for chaining
	 */
	public ToneLUTOptions inMax(Integer inMax) {
		setInMax(inMax);
		return this;
	}

	/**
	 * Optional argument: out-max
	 * <p>
	 * Maximum value in output LUT
	 * @return the value of {@code outMax}
	 */
	public Integer getOutMax() {
		return this.outMax;
	}

	/**
	 * Set the optional "out-max" argument.
	 * <p>
	 * Maximum value in output LUT
	 * @param outMax the new value of {@code outMax}
	 */
	public void setOutMax(Integer outMax) {
		this.outMax = outMax;
	}

	/**
	 * Set the optional "out-max" argument.
	 * <p>
	 * Maximum value in output LUT
	 * @param outMax the new value of {@code outMax}
	 * @return this object for chaining
	 */
	public ToneLUTOptions outMax(Integer outMax) {
		setOutMax(outMax);
		return this;
	}

	/**
	 * Optional argument: Lb
	 * <p>
	 * Lowest value in output
	 * @return the value of {@code lb}
	 */
	public Double getLb() {
		return this.lb;
	}

	/**
	 * Set the optional "Lb" argument.
	 * <p>
	 * Lowest value in output
	 * @param lb the new value of {@code lb}
	 */
	public void setLb(Double lb) {
		this.lb = lb;
	}

	/**
	 * Set the optional "Lb" argument.
	 * <p>
	 * Lowest value in output
	 * @param lb the new value of {@code lb}
	 * @return this object for chaining
	 */
	public ToneLUTOptions lb(Double lb) {
		setLb(lb);
		return this;
	}

	/**
	 * Optional argument: Lw
	 * <p>
	 * Highest value in output
	 * @return the value of {@code lw}
	 */
	public Double getLw() {
		return this.lw;
	}

	/**
	 * Set the optional "Lw" argument.
	 * <p>
	 * Highest value in output
	 * @param lw the new value of {@code lw}
	 */
	public void setLw(Double lw) {
		this.lw = lw;
	}

	/**
	 * Set the optional "Lw" argument.
	 * <p>
	 * Highest value in output
	 * @param lw the new value of {@code lw}
	 * @return this object for chaining
	 */
	public ToneLUTOptions lw(Double lw) {
		setLw(lw);
		return this;
	}

	/**
	 * Optional argument: Ps
	 * <p>
	 * Position of shadow
	 * @return the value of {@code ps}
	 */
	public Double getPs() {
		return this.ps;
	}

	/**
	 * Set the optional "Ps" argument.
	 * <p>
	 * Position of shadow
	 * @param ps the new value of {@code ps}
	 */
	public void setPs(Double ps) {
		this.ps = ps;
	}

	/**
	 * Set the optional "Ps" argument.
	 * <p>
	 * Position of shadow
	 * @param ps the new value of {@code ps}
	 * @return this object for chaining
	 */
	public ToneLUTOptions ps(Double ps) {
		setPs(ps);
		return this;
	}

	/**
	 * Optional argument: Pm
	 * <p>
	 * Position of mid-tones
	 * @return the value of {@code pm}
	 */
	public Double getPm() {
		return this.pm;
	}

	/**
	 * Set the optional "Pm" argument.
	 * <p>
	 * Position of mid-tones
	 * @param pm the new value of {@code pm}
	 */
	public void setPm(Double pm) {
		this.pm = pm;
	}

	/**
	 * Set the optional "Pm" argument.
	 * <p>
	 * Position of mid-tones
	 * @param pm the new value of {@code pm}
	 * @return this object for chaining
	 */
	public ToneLUTOptions pm(Double pm) {
		setPm(pm);
		return this;
	}

	/**
	 * Optional argument: Ph
	 * <p>
	 * Position of highlights
	 * @return the value of {@code ph}
	 */
	public Double getPh() {
		return this.ph;
	}

	/**
	 * Set the optional "Ph" argument.
	 * <p>
	 * Position of highlights
	 * @param ph the new value of {@code ph}
	 */
	public void setPh(Double ph) {
		this.ph = ph;
	}

	/**
	 * Set the optional "Ph" argument.
	 * <p>
	 * Position of highlights
	 * @param ph the new value of {@code ph}
	 * @return this object for chaining
	 */
	public ToneLUTOptions ph(Double ph) {
		setPh(ph);
		return this;
	}

	/**
	 * Optional argument: S
	 * <p>
	 * Adjust shadows by this much
	 * @return the value of {@code s}
	 */
	public Double getS() {
		return this.s;
	}

	/**
	 * Set the optional "S" argument.
	 * <p>
	 * Adjust shadows by this much
	 * @param s the new value of {@code s}
	 */
	public void setS(Double s) {
		this.s = s;
	}

	/**
	 * Set the optional "S" argument.
	 * <p>
	 * Adjust shadows by this much
	 * @param s the new value of {@code s}
	 * @return this object for chaining
	 */
	public ToneLUTOptions s(Double s) {
		setS(s);
		return this;
	}

	/**
	 * Optional argument: M
	 * <p>
	 * Adjust mid-tones by this much
	 * @return the value of {@code m}
	 */
	public Double getM() {
		return this.m;
	}

	/**
	 * Set the optional "M" argument.
	 * <p>
	 * Adjust mid-tones by this much
	 * @param m the new value of {@code m}
	 */
	public void setM(Double m) {
		this.m = m;
	}

	/**
	 * Set the optional "M" argument.
	 * <p>
	 * Adjust mid-tones by this much
	 * @param m the new value of {@code m}
	 * @return this object for chaining
	 */
	public ToneLUTOptions m(Double m) {
		setM(m);
		return this;
	}

	/**
	 * Optional argument: H
	 * <p>
	 * Adjust highlights by this much
	 * @return the value of {@code h}
	 */
	public Double getH() {
		return this.h;
	}

	/**
	 * Set the optional "H" argument.
	 * <p>
	 * Adjust highlights by this much
	 * @param h the new value of {@code h}
	 */
	public void setH(Double h) {
		this.h = h;
	}

	/**
	 * Set the optional "H" argument.
	 * <p>
	 * Adjust highlights by this much
	 * @param h the new value of {@code h}
	 * @return this object for chaining
	 */
	public ToneLUTOptions h(Double h) {
		setH(h);
		return this;
	}

}
