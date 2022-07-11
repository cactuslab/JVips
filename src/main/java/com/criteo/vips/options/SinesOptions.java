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
 * Optional arguments for the "sines" operation.
 */
public class SinesOptions {

	private Boolean uchar;
	private Double hfreq;
	private Double vfreq;

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
	public SinesOptions uchar(Boolean uchar) {
		setUchar(uchar);
		return this;
	}

	/**
	 * Optional argument: hfreq
	 * <p>
	 * Horizontal spatial frequency
	 * @return the value of {@code hfreq}
	 */
	public Double getHfreq() {
		return this.hfreq;
	}

	/**
	 * Set the optional "hfreq" argument.
	 * <p>
	 * Horizontal spatial frequency
	 * @param hfreq the new value of {@code hfreq}
	 */
	public void setHfreq(Double hfreq) {
		this.hfreq = hfreq;
	}

	/**
	 * Set the optional "hfreq" argument.
	 * <p>
	 * Horizontal spatial frequency
	 * @param hfreq the new value of {@code hfreq}
	 * @return this object for chaining
	 */
	public SinesOptions hfreq(Double hfreq) {
		setHfreq(hfreq);
		return this;
	}

	/**
	 * Optional argument: vfreq
	 * <p>
	 * Vertical spatial frequency
	 * @return the value of {@code vfreq}
	 */
	public Double getVfreq() {
		return this.vfreq;
	}

	/**
	 * Set the optional "vfreq" argument.
	 * <p>
	 * Vertical spatial frequency
	 * @param vfreq the new value of {@code vfreq}
	 */
	public void setVfreq(Double vfreq) {
		this.vfreq = vfreq;
	}

	/**
	 * Set the optional "vfreq" argument.
	 * <p>
	 * Vertical spatial frequency
	 * @param vfreq the new value of {@code vfreq}
	 * @return this object for chaining
	 */
	public SinesOptions vfreq(Double vfreq) {
		setVfreq(vfreq);
		return this;
	}

}
