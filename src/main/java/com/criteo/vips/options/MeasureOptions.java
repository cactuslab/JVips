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
 * Optional arguments for the "measure" operation.
 */
public class MeasureOptions {

	private Integer left;
	private Integer top;
	private Integer width;
	private Integer height;

	/**
	 * Optional argument: left
	 * <p>
	 * Left edge of extract area
	 * @return the value of {@code left}
	 */
	public Integer getLeft() {
		return this.left;
	}

	/**
	 * Set the optional "left" argument.
	 * <p>
	 * Left edge of extract area
	 * @param left the new value of {@code left}
	 */
	public void setLeft(Integer left) {
		this.left = left;
	}

	/**
	 * Set the optional "left" argument.
	 * <p>
	 * Left edge of extract area
	 * @param left the new value of {@code left}
	 * @return this object for chaining
	 */
	public MeasureOptions left(Integer left) {
		setLeft(left);
		return this;
	}

	/**
	 * Optional argument: top
	 * <p>
	 * Top edge of extract area
	 * @return the value of {@code top}
	 */
	public Integer getTop() {
		return this.top;
	}

	/**
	 * Set the optional "top" argument.
	 * <p>
	 * Top edge of extract area
	 * @param top the new value of {@code top}
	 */
	public void setTop(Integer top) {
		this.top = top;
	}

	/**
	 * Set the optional "top" argument.
	 * <p>
	 * Top edge of extract area
	 * @param top the new value of {@code top}
	 * @return this object for chaining
	 */
	public MeasureOptions top(Integer top) {
		setTop(top);
		return this;
	}

	/**
	 * Optional argument: width
	 * <p>
	 * Width of extract area
	 * @return the value of {@code width}
	 */
	public Integer getWidth() {
		return this.width;
	}

	/**
	 * Set the optional "width" argument.
	 * <p>
	 * Width of extract area
	 * @param width the new value of {@code width}
	 */
	public void setWidth(Integer width) {
		this.width = width;
	}

	/**
	 * Set the optional "width" argument.
	 * <p>
	 * Width of extract area
	 * @param width the new value of {@code width}
	 * @return this object for chaining
	 */
	public MeasureOptions width(Integer width) {
		setWidth(width);
		return this;
	}

	/**
	 * Optional argument: height
	 * <p>
	 * Height of extract area
	 * @return the value of {@code height}
	 */
	public Integer getHeight() {
		return this.height;
	}

	/**
	 * Set the optional "height" argument.
	 * <p>
	 * Height of extract area
	 * @param height the new value of {@code height}
	 */
	public void setHeight(Integer height) {
		this.height = height;
	}

	/**
	 * Set the optional "height" argument.
	 * <p>
	 * Height of extract area
	 * @param height the new value of {@code height}
	 * @return this object for chaining
	 */
	public MeasureOptions height(Integer height) {
		setHeight(height);
		return this;
	}

}
