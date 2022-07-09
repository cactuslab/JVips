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
 * Optional arguments for the "mask_butterworth_ring" operation.
 */
public class MaskButterworthRingOptions {

	private Boolean uchar;
	private Boolean nodc;
	private Boolean reject;
	private Boolean optical;

	/**
	 * Optional argument: uchar
	 * <p>
	 * Output an unsigned char image
	 * @return the value of {@code uchar}
	 */
	public Boolean getUchar() {
		return this.uchar;
	}

	/**
	 * Set the optional "uchar" argument.
	 * <p>
	 * Output an unsigned char image
	 * @param uchar the new value of {@code uchar}
	 */
	public void setUchar(Boolean uchar) {
		this.uchar = uchar;
	}

	/**
	 * Set the optional "uchar" argument.
	 * <p>
	 * Output an unsigned char image
	 * @param uchar the new value of {@code uchar}
	 * @return this object for chaining
	 */
	public MaskButterworthRingOptions uchar(Boolean uchar) {
		setUchar(uchar);
		return this;
	}

	/**
	 * Optional argument: nodc
	 * <p>
	 * Remove DC component
	 * @return the value of {@code nodc}
	 */
	public Boolean getNodc() {
		return this.nodc;
	}

	/**
	 * Set the optional "nodc" argument.
	 * <p>
	 * Remove DC component
	 * @param nodc the new value of {@code nodc}
	 */
	public void setNodc(Boolean nodc) {
		this.nodc = nodc;
	}

	/**
	 * Set the optional "nodc" argument.
	 * <p>
	 * Remove DC component
	 * @param nodc the new value of {@code nodc}
	 * @return this object for chaining
	 */
	public MaskButterworthRingOptions nodc(Boolean nodc) {
		setNodc(nodc);
		return this;
	}

	/**
	 * Optional argument: reject
	 * <p>
	 * Invert the sense of the filter
	 * @return the value of {@code reject}
	 */
	public Boolean getReject() {
		return this.reject;
	}

	/**
	 * Set the optional "reject" argument.
	 * <p>
	 * Invert the sense of the filter
	 * @param reject the new value of {@code reject}
	 */
	public void setReject(Boolean reject) {
		this.reject = reject;
	}

	/**
	 * Set the optional "reject" argument.
	 * <p>
	 * Invert the sense of the filter
	 * @param reject the new value of {@code reject}
	 * @return this object for chaining
	 */
	public MaskButterworthRingOptions reject(Boolean reject) {
		setReject(reject);
		return this;
	}

	/**
	 * Optional argument: optical
	 * <p>
	 * Rotate quadrants to optical space
	 * @return the value of {@code optical}
	 */
	public Boolean getOptical() {
		return this.optical;
	}

	/**
	 * Set the optional "optical" argument.
	 * <p>
	 * Rotate quadrants to optical space
	 * @param optical the new value of {@code optical}
	 */
	public void setOptical(Boolean optical) {
		this.optical = optical;
	}

	/**
	 * Set the optional "optical" argument.
	 * <p>
	 * Rotate quadrants to optical space
	 * @param optical the new value of {@code optical}
	 * @return this object for chaining
	 */
	public MaskButterworthRingOptions optical(Boolean optical) {
		setOptical(optical);
		return this;
	}

}
