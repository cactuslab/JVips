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

/**
 * Optional arguments for the "tiffload_buffer" operation.
 */
public class TIFFLoadBufferOptions {

	private Integer page;
	private Integer subifd;
	private Integer n;
	private Boolean autorotate;
	private Boolean memory;
	private com.criteo.vips.enums.VipsAccess access;
	private com.criteo.vips.enums.VipsFailOn failOn;
	private Boolean revalidate;

	/**
	 * Optional argument: page
	 * <p>
	 * First page to load
	 * @return the value of {@code page}
	 */
	public Integer getPage() {
		return this.page;
	}

	/**
	 * Set the optional "page" argument.
	 * <p>
	 * First page to load
	 * @param page the new value of {@code page}
	 */
	public void setPage(Integer page) {
		this.page = page;
	}

	/**
	 * Set the optional "page" argument.
	 * <p>
	 * First page to load
	 * @param page the new value of {@code page}
	 * @return this object for chaining
	 */
	public TIFFLoadBufferOptions page(Integer page) {
		setPage(page);
		return this;
	}

	/**
	 * Optional argument: subifd
	 * <p>
	 * Subifd index
	 * @return the value of {@code subifd}
	 */
	public Integer getSubifd() {
		return this.subifd;
	}

	/**
	 * Set the optional "subifd" argument.
	 * <p>
	 * Subifd index
	 * @param subifd the new value of {@code subifd}
	 */
	public void setSubifd(Integer subifd) {
		this.subifd = subifd;
	}

	/**
	 * Set the optional "subifd" argument.
	 * <p>
	 * Subifd index
	 * @param subifd the new value of {@code subifd}
	 * @return this object for chaining
	 */
	public TIFFLoadBufferOptions subifd(Integer subifd) {
		setSubifd(subifd);
		return this;
	}

	/**
	 * Optional argument: n
	 * <p>
	 * Number of pages to load, -1 for all
	 * @return the value of {@code n}
	 */
	public Integer getN() {
		return this.n;
	}

	/**
	 * Set the optional "n" argument.
	 * <p>
	 * Number of pages to load, -1 for all
	 * @param n the new value of {@code n}
	 */
	public void setN(Integer n) {
		this.n = n;
	}

	/**
	 * Set the optional "n" argument.
	 * <p>
	 * Number of pages to load, -1 for all
	 * @param n the new value of {@code n}
	 * @return this object for chaining
	 */
	public TIFFLoadBufferOptions n(Integer n) {
		setN(n);
		return this;
	}

	/**
	 * Optional argument: autorotate
	 * <p>
	 * Rotate image using orientation tag
	 * @return the value of {@code autorotate}
	 */
	public Boolean getAutorotate() {
		return this.autorotate;
	}

	/**
	 * Set the optional "autorotate" argument.
	 * <p>
	 * Rotate image using orientation tag
	 * @param autorotate the new value of {@code autorotate}
	 */
	public void setAutorotate(Boolean autorotate) {
		this.autorotate = autorotate;
	}

	/**
	 * Set the optional "autorotate" argument.
	 * <p>
	 * Rotate image using orientation tag
	 * @param autorotate the new value of {@code autorotate}
	 * @return this object for chaining
	 */
	public TIFFLoadBufferOptions autorotate(Boolean autorotate) {
		setAutorotate(autorotate);
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
	public TIFFLoadBufferOptions memory(Boolean memory) {
		setMemory(memory);
		return this;
	}

	/**
	 * Optional argument: access
	 * <p>
	 * Required access pattern for this file
	 * @return the value of {@code access}
	 */
	public com.criteo.vips.enums.VipsAccess getAccess() {
		return this.access;
	}

	/**
	 * Set the optional "access" argument.
	 * <p>
	 * Required access pattern for this file
	 * @param access the new value of {@code access}
	 */
	public void setAccess(com.criteo.vips.enums.VipsAccess access) {
		this.access = access;
	}

	/**
	 * Set the optional "access" argument.
	 * <p>
	 * Required access pattern for this file
	 * @param access the new value of {@code access}
	 * @return this object for chaining
	 */
	public TIFFLoadBufferOptions access(com.criteo.vips.enums.VipsAccess access) {
		setAccess(access);
		return this;
	}

	/**
	 * Optional argument: fail-on
	 * <p>
	 * Error level to fail on
	 * @return the value of {@code failOn}
	 */
	public com.criteo.vips.enums.VipsFailOn getFailOn() {
		return this.failOn;
	}

	/**
	 * Set the optional "fail-on" argument.
	 * <p>
	 * Error level to fail on
	 * @param failOn the new value of {@code failOn}
	 */
	public void setFailOn(com.criteo.vips.enums.VipsFailOn failOn) {
		this.failOn = failOn;
	}

	/**
	 * Set the optional "fail-on" argument.
	 * <p>
	 * Error level to fail on
	 * @param failOn the new value of {@code failOn}
	 * @return this object for chaining
	 */
	public TIFFLoadBufferOptions failOn(com.criteo.vips.enums.VipsFailOn failOn) {
		setFailOn(failOn);
		return this;
	}

	/**
	 * Optional argument: revalidate
	 * <p>
	 * Don't use a cached result for this operation
	 * @return the value of {@code revalidate}
	 */
	public Boolean getRevalidate() {
		return this.revalidate;
	}

	/**
	 * Set the optional "revalidate" argument.
	 * <p>
	 * Don't use a cached result for this operation
	 * @param revalidate the new value of {@code revalidate}
	 */
	public void setRevalidate(Boolean revalidate) {
		this.revalidate = revalidate;
	}

	/**
	 * Set the optional "revalidate" argument.
	 * <p>
	 * Don't use a cached result for this operation
	 * @param revalidate the new value of {@code revalidate}
	 * @return this object for chaining
	 */
	public TIFFLoadBufferOptions revalidate(Boolean revalidate) {
		setRevalidate(revalidate);
		return this;
	}

}
