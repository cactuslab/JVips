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
 * Optional arguments for the "find_trim" operation.
 */
public class FindTrimOptions {

	private Double threshold;
	private PixelPacket background;

	/**
	 * Optional argument: threshold
	 * <p>
	 * Object threshold
	 * @return the value of {@code threshold}
	 */
	public Double getThreshold() {
		return this.threshold;
	}

	/**
	 * Set the optional "threshold" argument.
	 * <p>
	 * Object threshold
	 * @param threshold the new value of {@code threshold}
	 */
	public void setThreshold(Double threshold) {
		this.threshold = threshold;
	}

	/**
	 * Set the optional "threshold" argument.
	 * <p>
	 * Object threshold
	 * @param threshold the new value of {@code threshold}
	 * @return this object for chaining
	 */
	public FindTrimOptions threshold(Double threshold) {
		setThreshold(threshold);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Color for background pixels
	 * @return the value of {@code background}
	 */
	public PixelPacket getBackground() {
		return this.background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for background pixels
	 * @param background the new value of {@code background}
	 */
	public void setBackground(PixelPacket background) {
		this.background = background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Color for background pixels
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public FindTrimOptions background(PixelPacket background) {
		setBackground(background);
		return this;
	}

}
