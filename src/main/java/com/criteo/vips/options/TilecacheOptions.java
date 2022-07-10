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
 * Optional arguments for the "tilecache" operation.
 */
public class TilecacheOptions {

	private Integer tileWidth;
	private Integer tileHeight;
	private Integer maxTiles;
	private VipsAccess access;
	private Boolean threaded;
	private Boolean persistent;

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
	public TilecacheOptions tileWidth(Integer tileWidth) {
		setTileWidth(tileWidth);
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
	public TilecacheOptions tileHeight(Integer tileHeight) {
		setTileHeight(tileHeight);
		return this;
	}

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
	public TilecacheOptions maxTiles(Integer maxTiles) {
		setMaxTiles(maxTiles);
		return this;
	}

	/**
	 * Optional argument: access
	 * <p>
	 * Expected access pattern
	 * @return the value of {@code access}
	 */
	public VipsAccess getAccess() {
		return this.access;
	}

	/**
	 * Set the optional "access" argument.
	 * <p>
	 * Expected access pattern
	 * @param access the new value of {@code access}
	 */
	public void setAccess(VipsAccess access) {
		this.access = access;
	}

	/**
	 * Set the optional "access" argument.
	 * <p>
	 * Expected access pattern
	 * @param access the new value of {@code access}
	 * @return this object for chaining
	 */
	public TilecacheOptions access(VipsAccess access) {
		setAccess(access);
		return this;
	}

	/**
	 * Optional argument: threaded
	 * <p>
	 * Allow threaded access
	 * @return the value of {@code threaded}
	 */
	public Boolean getThreaded() {
		return this.threaded;
	}

	/**
	 * Set the optional "threaded" argument.
	 * <p>
	 * Allow threaded access
	 * @param threaded the new value of {@code threaded}
	 */
	public void setThreaded(Boolean threaded) {
		this.threaded = threaded;
	}

	/**
	 * Set the optional "threaded" argument.
	 * <p>
	 * Allow threaded access
	 * @param threaded the new value of {@code threaded}
	 * @return this object for chaining
	 */
	public TilecacheOptions threaded(Boolean threaded) {
		setThreaded(threaded);
		return this;
	}

	/**
	 * Optional argument: persistent
	 * <p>
	 * Keep cache between evaluations
	 * @return the value of {@code persistent}
	 */
	public Boolean getPersistent() {
		return this.persistent;
	}

	/**
	 * Set the optional "persistent" argument.
	 * <p>
	 * Keep cache between evaluations
	 * @param persistent the new value of {@code persistent}
	 */
	public void setPersistent(Boolean persistent) {
		this.persistent = persistent;
	}

	/**
	 * Set the optional "persistent" argument.
	 * <p>
	 * Keep cache between evaluations
	 * @param persistent the new value of {@code persistent}
	 * @return this object for chaining
	 */
	public TilecacheOptions persistent(Boolean persistent) {
		setPersistent(persistent);
		return this;
	}

}
