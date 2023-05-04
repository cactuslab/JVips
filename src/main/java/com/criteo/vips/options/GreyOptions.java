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
 * Optional arguments for the "grey" operation.
 */
public class GreyOptions {

	private Boolean uchar;

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
	public GreyOptions uchar(Boolean uchar) {
		setUchar(uchar);
		return this;
	}

}
