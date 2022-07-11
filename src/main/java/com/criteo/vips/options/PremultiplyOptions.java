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
 * Optional arguments for the "premultiply" operation.
 */
public class PremultiplyOptions {

	private Double maxAlpha;

	/**
	 * Optional argument: max-alpha
	 * <p>
	 * Maximum value of alpha channel
	 * @return the value of {@code maxAlpha}
	 */
	public Double getMaxAlpha() {
		return this.maxAlpha;
	}

	/**
	 * Set the optional "max-alpha" argument.
	 * <p>
	 * Maximum value of alpha channel
	 * @param maxAlpha the new value of {@code maxAlpha}
	 */
	public void setMaxAlpha(Double maxAlpha) {
		this.maxAlpha = maxAlpha;
	}

	/**
	 * Set the optional "max-alpha" argument.
	 * <p>
	 * Maximum value of alpha channel
	 * @param maxAlpha the new value of {@code maxAlpha}
	 * @return this object for chaining
	 */
	public PremultiplyOptions maxAlpha(Double maxAlpha) {
		setMaxAlpha(maxAlpha);
		return this;
	}

}
