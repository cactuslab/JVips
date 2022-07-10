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
 * Optional arguments for the "scRGB2sRGB" operation.
 */
public class ScRGB2sRGBOptions {

	private Integer depth;

	/**
	 * Optional argument: depth
	 * <p>
	 * Output device space depth in bits
	 * @return the value of {@code depth}
	 */
	public Integer getDepth() {
		return this.depth;
	}

	/**
	 * Set the optional "depth" argument.
	 * <p>
	 * Output device space depth in bits
	 * @param depth the new value of {@code depth}
	 */
	public void setDepth(Integer depth) {
		this.depth = depth;
	}

	/**
	 * Set the optional "depth" argument.
	 * <p>
	 * Output device space depth in bits
	 * @param depth the new value of {@code depth}
	 * @return this object for chaining
	 */
	public ScRGB2sRGBOptions depth(Integer depth) {
		setDepth(depth);
		return this;
	}

}
