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
 * Optional arguments for the "sequential" operation.
 */
public class SequentialOptions {

	private Integer tileHeight;

	/**
	 * Optional argument: tile-height
	 * <p>
	 * Tile height in pixels
	 * @return the value of {@code tileHeight}
	 */
	public Integer getTileHeight() {
		return this.tileHeight;
	}

	/**
	 * Set the optional "tile-height" argument.
	 * <p>
	 * Tile height in pixels
	 * @param tileHeight the new value of {@code tileHeight}
	 */
	public void setTileHeight(Integer tileHeight) {
		this.tileHeight = tileHeight;
	}

	/**
	 * Set the optional "tile-height" argument.
	 * <p>
	 * Tile height in pixels
	 * @param tileHeight the new value of {@code tileHeight}
	 * @return this object for chaining
	 */
	public SequentialOptions tileHeight(Integer tileHeight) {
		setTileHeight(tileHeight);
		return this;
	}

}
