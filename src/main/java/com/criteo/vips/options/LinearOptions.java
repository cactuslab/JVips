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
 * Optional arguments for the "linear" operation.
 */
public class LinearOptions {

	private Boolean uchar;

	/**
	 * Optional argument: uchar
	 * <p>
	 * Output should be uchar
	 * @return the value of {@code uchar}
	 */
	public Boolean getUchar() {
		return this.uchar;
	}

	/**
	 * Set the optional "uchar" argument.
	 * <p>
	 * Output should be uchar
	 * @param uchar the new value of {@code uchar}
	 */
	public void setUchar(Boolean uchar) {
		this.uchar = uchar;
	}

	/**
	 * Set the optional "uchar" argument.
	 * <p>
	 * Output should be uchar
	 * @param uchar the new value of {@code uchar}
	 * @return this object for chaining
	 */
	public LinearOptions uchar(Boolean uchar) {
		setUchar(uchar);
		return this;
	}

}
