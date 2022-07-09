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
 * Optional arguments for the "hough_circle" operation.
 */
public class HoughCircleOptions {

	private Integer scale;
	private Integer minRadius;
	private Integer maxRadius;

	/**
	 * Optional argument: scale
	 * <p>
	 * Scale down dimensions by this factor
	 * @return the value of {@code scale}
	 */
	public Integer getScale() {
		return this.scale;
	}

	/**
	 * Set the optional "scale" argument.
	 * <p>
	 * Scale down dimensions by this factor
	 * @param scale the new value of {@code scale}
	 */
	public void setScale(Integer scale) {
		this.scale = scale;
	}

	/**
	 * Set the optional "scale" argument.
	 * <p>
	 * Scale down dimensions by this factor
	 * @param scale the new value of {@code scale}
	 * @return this object for chaining
	 */
	public HoughCircleOptions scale(Integer scale) {
		setScale(scale);
		return this;
	}

	/**
	 * Optional argument: min-radius
	 * <p>
	 * Smallest radius to search for
	 * @return the value of {@code minRadius}
	 */
	public Integer getMinRadius() {
		return this.minRadius;
	}

	/**
	 * Set the optional "min-radius" argument.
	 * <p>
	 * Smallest radius to search for
	 * @param minRadius the new value of {@code minRadius}
	 */
	public void setMinRadius(Integer minRadius) {
		this.minRadius = minRadius;
	}

	/**
	 * Set the optional "min-radius" argument.
	 * <p>
	 * Smallest radius to search for
	 * @param minRadius the new value of {@code minRadius}
	 * @return this object for chaining
	 */
	public HoughCircleOptions minRadius(Integer minRadius) {
		setMinRadius(minRadius);
		return this;
	}

	/**
	 * Optional argument: max-radius
	 * <p>
	 * Largest radius to search for
	 * @return the value of {@code maxRadius}
	 */
	public Integer getMaxRadius() {
		return this.maxRadius;
	}

	/**
	 * Set the optional "max-radius" argument.
	 * <p>
	 * Largest radius to search for
	 * @param maxRadius the new value of {@code maxRadius}
	 */
	public void setMaxRadius(Integer maxRadius) {
		this.maxRadius = maxRadius;
	}

	/**
	 * Set the optional "max-radius" argument.
	 * <p>
	 * Largest radius to search for
	 * @param maxRadius the new value of {@code maxRadius}
	 * @return this object for chaining
	 */
	public HoughCircleOptions maxRadius(Integer maxRadius) {
		setMaxRadius(maxRadius);
		return this;
	}

}
