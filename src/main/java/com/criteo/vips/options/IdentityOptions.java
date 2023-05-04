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
 * Optional arguments for the "identity" operation.
 */
public class IdentityOptions {

	private Integer bands;
	private Boolean ushort;
	private Integer size;

	/**
	 * Optional argument: bands
	 * <p>
	 * Number of bands in LUT
	 * @return the value of {@code bands}
	 */
	public Integer getBands() {
		return this.bands;
	}

	/**
	 * Set the optional "bands" argument.
	 * <p>
	 * Number of bands in LUT
	 * @param bands the new value of {@code bands}
	 */
	public void setBands(Integer bands) {
		this.bands = bands;
	}

	/**
	 * Set the optional "bands" argument.
	 * <p>
	 * Number of bands in LUT
	 * @param bands the new value of {@code bands}
	 * @return this object for chaining
	 */
	public IdentityOptions bands(Integer bands) {
		setBands(bands);
		return this;
	}

	/**
	 * Optional argument: ushort
	 * <p>
	 * Create a 16-bit LUT
	 * @return the value of {@code ushort}
	 */
	public Boolean getUshort() {
		return this.ushort;
	}

	/**
	 * Set the optional "ushort" argument.
	 * <p>
	 * Create a 16-bit LUT
	 * @param ushort the new value of {@code ushort}
	 */
	public void setUshort(Boolean ushort) {
		this.ushort = ushort;
	}

	/**
	 * Set the optional "ushort" argument.
	 * <p>
	 * Create a 16-bit LUT
	 * @param ushort the new value of {@code ushort}
	 * @return this object for chaining
	 */
	public IdentityOptions ushort(Boolean ushort) {
		setUshort(ushort);
		return this;
	}

	/**
	 * Optional argument: size
	 * <p>
	 * Size of 16-bit LUT
	 * @return the value of {@code size}
	 */
	public Integer getSize() {
		return this.size;
	}

	/**
	 * Set the optional "size" argument.
	 * <p>
	 * Size of 16-bit LUT
	 * @param size the new value of {@code size}
	 */
	public void setSize(Integer size) {
		this.size = size;
	}

	/**
	 * Set the optional "size" argument.
	 * <p>
	 * Size of 16-bit LUT
	 * @param size the new value of {@code size}
	 * @return this object for chaining
	 */
	public IdentityOptions size(Integer size) {
		setSize(size);
		return this;
	}

}
