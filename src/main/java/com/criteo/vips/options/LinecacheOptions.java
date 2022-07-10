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
 * Optional arguments for the "linecache" operation.
 */
public class LinecacheOptions {

	private Integer tileHeight;
	private VipsAccess access;
	private Boolean threaded;
	private Boolean persistent;

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
	public LinecacheOptions tileHeight(Integer tileHeight) {
		setTileHeight(tileHeight);
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
	public LinecacheOptions access(VipsAccess access) {
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
	public LinecacheOptions threaded(Boolean threaded) {
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
	public LinecacheOptions persistent(Boolean persistent) {
		setPersistent(persistent);
		return this;
	}

}