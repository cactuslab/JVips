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
 * Optional arguments for the "flatten" operation.
 */
public class FlattenOptions {

	private PixelPacket background;
	private Double maxAlpha;

	/**
	 * Optional argument: background
	 * <p>
	 * Background value
	 * @return the value of {@code background}
	 */
	public PixelPacket getBackground() {
		return this.background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background value
	 * @param background the new value of {@code background}
	 */
	public void setBackground(PixelPacket background) {
		this.background = background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background value
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public FlattenOptions background(PixelPacket background) {
		setBackground(background);
		return this;
	}

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
	public FlattenOptions maxAlpha(Double maxAlpha) {
		setMaxAlpha(maxAlpha);
		return this;
	}

}