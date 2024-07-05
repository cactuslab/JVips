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
 * Optional arguments for the "pdfload" operation.
 */
public class PDFLoadOptions {

	private Integer page;
	private Integer n;
	private Double dpi;
	private Double scale;
	private double[] background;
	private com.criteo.vips.PixelPacket backgroundPixelPacket;
	private String password;
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
	public PDFLoadOptions page(Integer page) {
		setPage(page);
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
	public PDFLoadOptions n(Integer n) {
		setN(n);
		return this;
	}

	/**
	 * Optional argument: dpi
	 * <p>
	 * DPI to render at
	 * @return the value of {@code dpi}
	 */
	public Double getDpi() {
		return this.dpi;
	}

	/**
	 * Set the optional "dpi" argument.
	 * <p>
	 * DPI to render at
	 * @param dpi the new value of {@code dpi}
	 */
	public void setDpi(Double dpi) {
		this.dpi = dpi;
	}

	/**
	 * Set the optional "dpi" argument.
	 * <p>
	 * DPI to render at
	 * @param dpi the new value of {@code dpi}
	 * @return this object for chaining
	 */
	public PDFLoadOptions dpi(Double dpi) {
		setDpi(dpi);
		return this;
	}

	/**
	 * Optional argument: scale
	 * <p>
	 * Factor to scale by
	 * @return the value of {@code scale}
	 */
	public Double getScale() {
		return this.scale;
	}

	/**
	 * Set the optional "scale" argument.
	 * <p>
	 * Factor to scale by
	 * @param scale the new value of {@code scale}
	 */
	public void setScale(Double scale) {
		this.scale = scale;
	}

	/**
	 * Set the optional "scale" argument.
	 * <p>
	 * Factor to scale by
	 * @param scale the new value of {@code scale}
	 * @return this object for chaining
	 */
	public PDFLoadOptions scale(Double scale) {
		setScale(scale);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Background colour
	 * @return the value of {@code background}
	 */
	public double[] getBackground() {
		return this.background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background colour
	 * @param background the new value of {@code background}
	 */
	public void setBackground(double[] background) {
		this.background = background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background colour
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public PDFLoadOptions background(double[] background) {
		setBackground(background);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Background colour
	 * @return the value of {@code background}
	 */
	public com.criteo.vips.PixelPacket getBackgroundPixelPacket() {
		return this.backgroundPixelPacket;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background colour
	 * @param background the new value of {@code background}
	 */
	public void setBackgroundPixelPacket(com.criteo.vips.PixelPacket background) {
		if (background != null) {
			this.backgroundPixelPacket = background;
		} else {
			this.backgroundPixelPacket = null;
		}
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background colour
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public PDFLoadOptions backgroundPixelPacket(com.criteo.vips.PixelPacket background) {
		setBackgroundPixelPacket(background);
		return this;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background colour
	 * @param background the new value of {@code background}
	 */
	public void setBackground(java.awt.Color background) {
		if (background != null) {
			com.criteo.vips.PixelPacket pixelPacket = new com.criteo.vips.PixelPacket(background.getRed(), background.getGreen(), background.getBlue(), background.getAlpha());
			setBackgroundPixelPacket(pixelPacket);
		} else {
			setBackgroundPixelPacket(null);
		}
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background colour
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public PDFLoadOptions background(java.awt.Color background) {
		setBackground(background);
		return this;
	}

	/**
	 * Optional argument: password
	 * <p>
	 * Password to decrypt with
	 * @return the value of {@code password}
	 */
	public String getPassword() {
		return this.password;
	}

	/**
	 * Set the optional "password" argument.
	 * <p>
	 * Password to decrypt with
	 * @param password the new value of {@code password}
	 */
	public void setPassword(String password) {
		this.password = password;
	}

	/**
	 * Set the optional "password" argument.
	 * <p>
	 * Password to decrypt with
	 * @param password the new value of {@code password}
	 * @return this object for chaining
	 */
	public PDFLoadOptions password(String password) {
		setPassword(password);
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
	public PDFLoadOptions memory(Boolean memory) {
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
	public PDFLoadOptions access(com.criteo.vips.enums.VipsAccess access) {
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
	public PDFLoadOptions failOn(com.criteo.vips.enums.VipsFailOn failOn) {
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
	public PDFLoadOptions revalidate(Boolean revalidate) {
		setRevalidate(revalidate);
		return this;
	}

}
