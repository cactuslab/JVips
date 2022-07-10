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
 * Optional arguments for the "cache" operation.
 */
public class CacheOptions {

	private Integer maxTiles;
	private Integer tileHeight;
	private Integer tileWidth;

	/**
	 * Optional argument: max-tiles
	 * <p>
	 * Maximum number of tiles to cache
	 * @return the value of {@code maxTiles}
	 */
	public Integer getMaxTiles() {
		return this.maxTiles;
	}

	/**
	 * Set the optional "max-tiles" argument.
	 * <p>
	 * Maximum number of tiles to cache
	 * @param maxTiles the new value of {@code maxTiles}
	 */
	public void setMaxTiles(Integer maxTiles) {
		this.maxTiles = maxTiles;
	}

	/**
	 * Set the optional "max-tiles" argument.
	 * <p>
	 * Maximum number of tiles to cache
	 * @param maxTiles the new value of {@code maxTiles}
	 * @return this object for chaining
	 */
	public CacheOptions maxTiles(Integer maxTiles) {
		setMaxTiles(maxTiles);
		return this;
	}

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
	public CacheOptions tileHeight(Integer tileHeight) {
		setTileHeight(tileHeight);
		return this;
	}

	/**
	 * Optional argument: tile-width
	 * <p>
	 * Tile width in pixels
	 * @return the value of {@code tileWidth}
	 */
	public Integer getTileWidth() {
		return this.tileWidth;
	}

	/**
	 * Set the optional "tile-width" argument.
	 * <p>
	 * Tile width in pixels
	 * @param tileWidth the new value of {@code tileWidth}
	 */
	public void setTileWidth(Integer tileWidth) {
		this.tileWidth = tileWidth;
	}

	/**
	 * Set the optional "tile-width" argument.
	 * <p>
	 * Tile width in pixels
	 * @param tileWidth the new value of {@code tileWidth}
	 * @return this object for chaining
	 */
	public CacheOptions tileWidth(Integer tileWidth) {
		setTileWidth(tileWidth);
		return this;
	}

}
