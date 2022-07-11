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
 * Optional arguments for the "heifload" operation.
 */
public class HEIFLoadOptions {

	private Integer page;
	private Integer n;
	private Boolean thumbnail;
	private Boolean memory;
	private VipsAccess access;
	private VipsFailOn failOn;

	/**
	 * Optional argument: page
	 * <p>
	 * Load this page from the file
	 * @return the value of {@code page}
	 */
	public Integer getPage() {
		return this.page;
	}

	/**
	 * Set the optional "page" argument.
	 * <p>
	 * Load this page from the file
	 * @param page the new value of {@code page}
	 */
	public void setPage(Integer page) {
		this.page = page;
	}

	/**
	 * Set the optional "page" argument.
	 * <p>
	 * Load this page from the file
	 * @param page the new value of {@code page}
	 * @return this object for chaining
	 */
	public HEIFLoadOptions page(Integer page) {
		setPage(page);
		return this;
	}

	/**
	 * Optional argument: n
	 * <p>
	 * Load this many pages
	 * @return the value of {@code n}
	 */
	public Integer getN() {
		return this.n;
	}

	/**
	 * Set the optional "n" argument.
	 * <p>
	 * Load this many pages
	 * @param n the new value of {@code n}
	 */
	public void setN(Integer n) {
		this.n = n;
	}

	/**
	 * Set the optional "n" argument.
	 * <p>
	 * Load this many pages
	 * @param n the new value of {@code n}
	 * @return this object for chaining
	 */
	public HEIFLoadOptions n(Integer n) {
		setN(n);
		return this;
	}

	/**
	 * Optional argument: thumbnail
	 * <p>
	 * Fetch thumbnail image
	 * @return the value of {@code thumbnail}
	 */
	public Boolean getThumbnail() {
		return this.thumbnail;
	}

	/**
	 * Set the optional "thumbnail" argument.
	 * <p>
	 * Fetch thumbnail image
	 * @param thumbnail the new value of {@code thumbnail}
	 */
	public void setThumbnail(Boolean thumbnail) {
		this.thumbnail = thumbnail;
	}

	/**
	 * Set the optional "thumbnail" argument.
	 * <p>
	 * Fetch thumbnail image
	 * @param thumbnail the new value of {@code thumbnail}
	 * @return this object for chaining
	 */
	public HEIFLoadOptions thumbnail(Boolean thumbnail) {
		setThumbnail(thumbnail);
		return this;
	}

	/**
	 * Optional argument: memory
	 * <p>
	 * Force open via memory
	 * @return the value of {@code memory}
	 */
	public Boolean getMemory() {
		return this.memory;
	}

	/**
	 * Set the optional "memory" argument.
	 * <p>
	 * Force open via memory
	 * @param memory the new value of {@code memory}
	 */
	public void setMemory(Boolean memory) {
		this.memory = memory;
	}

	/**
	 * Set the optional "memory" argument.
	 * <p>
	 * Force open via memory
	 * @param memory the new value of {@code memory}
	 * @return this object for chaining
	 */
	public HEIFLoadOptions memory(Boolean memory) {
		setMemory(memory);
		return this;
	}

	/**
	 * Optional argument: access
	 * <p>
	 * Required access pattern for this file
	 * @return the value of {@code access}
	 */
	public VipsAccess getAccess() {
		return this.access;
	}

	/**
	 * Set the optional "access" argument.
	 * <p>
	 * Required access pattern for this file
	 * @param access the new value of {@code access}
	 */
	public void setAccess(VipsAccess access) {
		this.access = access;
	}

	/**
	 * Set the optional "access" argument.
	 * <p>
	 * Required access pattern for this file
	 * @param access the new value of {@code access}
	 * @return this object for chaining
	 */
	public HEIFLoadOptions access(VipsAccess access) {
		setAccess(access);
		return this;
	}

	/**
	 * Optional argument: fail-on
	 * <p>
	 * Error level to fail on
	 * @return the value of {@code failOn}
	 */
	public VipsFailOn getFailOn() {
		return this.failOn;
	}

	/**
	 * Set the optional "fail-on" argument.
	 * <p>
	 * Error level to fail on
	 * @param failOn the new value of {@code failOn}
	 */
	public void setFailOn(VipsFailOn failOn) {
		this.failOn = failOn;
	}

	/**
	 * Set the optional "fail-on" argument.
	 * <p>
	 * Error level to fail on
	 * @param failOn the new value of {@code failOn}
	 * @return this object for chaining
	 */
	public HEIFLoadOptions failOn(VipsFailOn failOn) {
		setFailOn(failOn);
		return this;
	}

}
