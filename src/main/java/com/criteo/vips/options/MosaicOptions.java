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
 * Optional arguments for the "mosaic" operation.
 */
public class MosaicOptions {

	private Integer hwindow;
	private Integer harea;
	private Integer mblend;
	private Integer bandno;

	/**
	 * Optional argument: hwindow
	 * <p>
	 * Half window size
	 * @return the value of {@code hwindow}
	 */
	public Integer getHwindow() {
		return this.hwindow;
	}

	/**
	 * Set the optional "hwindow" argument.
	 * <p>
	 * Half window size
	 * @param hwindow the new value of {@code hwindow}
	 */
	public void setHwindow(Integer hwindow) {
		this.hwindow = hwindow;
	}

	/**
	 * Set the optional "hwindow" argument.
	 * <p>
	 * Half window size
	 * @param hwindow the new value of {@code hwindow}
	 * @return this object for chaining
	 */
	public MosaicOptions hwindow(Integer hwindow) {
		setHwindow(hwindow);
		return this;
	}

	/**
	 * Optional argument: harea
	 * <p>
	 * Half area size
	 * @return the value of {@code harea}
	 */
	public Integer getHarea() {
		return this.harea;
	}

	/**
	 * Set the optional "harea" argument.
	 * <p>
	 * Half area size
	 * @param harea the new value of {@code harea}
	 */
	public void setHarea(Integer harea) {
		this.harea = harea;
	}

	/**
	 * Set the optional "harea" argument.
	 * <p>
	 * Half area size
	 * @param harea the new value of {@code harea}
	 * @return this object for chaining
	 */
	public MosaicOptions harea(Integer harea) {
		setHarea(harea);
		return this;
	}

	/**
	 * Optional argument: mblend
	 * <p>
	 * Maximum blend size
	 * @return the value of {@code mblend}
	 */
	public Integer getMblend() {
		return this.mblend;
	}

	/**
	 * Set the optional "mblend" argument.
	 * <p>
	 * Maximum blend size
	 * @param mblend the new value of {@code mblend}
	 */
	public void setMblend(Integer mblend) {
		this.mblend = mblend;
	}

	/**
	 * Set the optional "mblend" argument.
	 * <p>
	 * Maximum blend size
	 * @param mblend the new value of {@code mblend}
	 * @return this object for chaining
	 */
	public MosaicOptions mblend(Integer mblend) {
		setMblend(mblend);
		return this;
	}

	/**
	 * Optional argument: bandno
	 * <p>
	 * Band to search for features on
	 * @return the value of {@code bandno}
	 */
	public Integer getBandno() {
		return this.bandno;
	}

	/**
	 * Set the optional "bandno" argument.
	 * <p>
	 * Band to search for features on
	 * @param bandno the new value of {@code bandno}
	 */
	public void setBandno(Integer bandno) {
		this.bandno = bandno;
	}

	/**
	 * Set the optional "bandno" argument.
	 * <p>
	 * Band to search for features on
	 * @param bandno the new value of {@code bandno}
	 * @return this object for chaining
	 */
	public MosaicOptions bandno(Integer bandno) {
		setBandno(bandno);
		return this;
	}

}
