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
 * Optional arguments for the "hough_line" operation.
 */
public class HoughLineOptions {

	private Integer width;
	private Integer height;

	/**
	 * Optional argument: width
	 * <p>
	 * horizontal size of parameter space
	 * @return the value of {@code width}
	 */
	public Integer getWidth() {
		return this.width;
	}

	/**
	 * Set the optional "width" argument.
	 * <p>
	 * horizontal size of parameter space
	 * @param width the new value of {@code width}
	 */
	public void setWidth(Integer width) {
		this.width = width;
	}

	/**
	 * Set the optional "width" argument.
	 * <p>
	 * horizontal size of parameter space
	 * @param width the new value of {@code width}
	 * @return this object for chaining
	 */
	public HoughLineOptions width(Integer width) {
		setWidth(width);
		return this;
	}

	/**
	 * Optional argument: height
	 * <p>
	 * Vertical size of parameter space
	 * @return the value of {@code height}
	 */
	public Integer getHeight() {
		return this.height;
	}

	/**
	 * Set the optional "height" argument.
	 * <p>
	 * Vertical size of parameter space
	 * @param height the new value of {@code height}
	 */
	public void setHeight(Integer height) {
		this.height = height;
	}

	/**
	 * Set the optional "height" argument.
	 * <p>
	 * Vertical size of parameter space
	 * @param height the new value of {@code height}
	 * @return this object for chaining
	 */
	public HoughLineOptions height(Integer height) {
		setHeight(height);
		return this;
	}

}
