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
 * Optional arguments for the "pdfload_buffer" operation.
 */
public class PDFLoadBufferOptions {

	private Integer page;
	private Integer n;
	private Double dpi;
	private Double scale;
	private double[] background;
	private PixelPacket backgroundPixelPacket;
	private String password;
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
	public PDFLoadBufferOptions page(Integer page) {
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
	public PDFLoadBufferOptions n(Integer n) {
		setN(n);
		return this;
	}

	/**
	 * Optional argument: dpi
	 * <p>
	 * Render at this DPI
	 * @return the value of {@code dpi}
	 */
	public Double getDpi() {
		return this.dpi;
	}

	/**
	 * Set the optional "dpi" argument.
	 * <p>
	 * Render at this DPI
	 * @param dpi the new value of {@code dpi}
	 */
	public void setDpi(Double dpi) {
		this.dpi = dpi;
	}

	/**
	 * Set the optional "dpi" argument.
	 * <p>
	 * Render at this DPI
	 * @param dpi the new value of {@code dpi}
	 * @return this object for chaining
	 */
	public PDFLoadBufferOptions dpi(Double dpi) {
		setDpi(dpi);
		return this;
	}

	/**
	 * Optional argument: scale
	 * <p>
	 * Scale output by this factor
	 * @return the value of {@code scale}
	 */
	public Double getScale() {
		return this.scale;
	}

	/**
	 * Set the optional "scale" argument.
	 * <p>
	 * Scale output by this factor
	 * @param scale the new value of {@code scale}
	 */
	public void setScale(Double scale) {
		this.scale = scale;
	}

	/**
	 * Set the optional "scale" argument.
	 * <p>
	 * Scale output by this factor
	 * @param scale the new value of {@code scale}
	 * @return this object for chaining
	 */
	public PDFLoadBufferOptions scale(Double scale) {
		setScale(scale);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Background value
	 * @return the value of {@code background}
	 */
	public double[] getBackground() {
		return this.background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background value
	 * @param background the new value of {@code background}
	 */
	public void setBackground(double[] background) {
		this.background = background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background value
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public PDFLoadBufferOptions background(double[] background) {
		setBackground(background);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Background value
	 * @return the value of {@code background}
	 */
	public PixelPacket getBackgroundPixelPacket() {
		return this.backgroundPixelPacket;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background value
	 * @param background the new value of {@code background}
	 */
	public void setBackgroundPixelPacket(PixelPacket background) {
		if (background != null) {
			this.backgroundPixelPacket = background;
		} else {
			this.backgroundPixelPacket = null;
		}
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background value
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public PDFLoadBufferOptions backgroundPixelPacket(PixelPacket background) {
		setBackgroundPixelPacket(background);
		return this;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background value
	 * @param background the new value of {@code background}
	 */
	public void setBackground(java.awt.Color background) {
		if (background != null) {
			float[] components = background.getComponents(new float[4]);
			PixelPacket pixelPacket = new PixelPacket(components[0], components[1], components[2], components[3]);
			setBackgroundPixelPacket(pixelPacket);
		} else {
			setBackgroundPixelPacket(null);
		}
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background value
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public PDFLoadBufferOptions background(java.awt.Color background) {
		setBackground(background);
		return this;
	}

	/**
	 * Optional argument: password
	 * <p>
	 * Decrypt with this password
	 * @return the value of {@code password}
	 */
	public String getPassword() {
		return this.password;
	}

	/**
	 * Set the optional "password" argument.
	 * <p>
	 * Decrypt with this password
	 * @param password the new value of {@code password}
	 */
	public void setPassword(String password) {
		this.password = password;
	}

	/**
	 * Set the optional "password" argument.
	 * <p>
	 * Decrypt with this password
	 * @param password the new value of {@code password}
	 * @return this object for chaining
	 */
	public PDFLoadBufferOptions password(String password) {
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
	public PDFLoadBufferOptions memory(Boolean memory) {
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
	public PDFLoadBufferOptions access(VipsAccess access) {
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
	public PDFLoadBufferOptions failOn(VipsFailOn failOn) {
		setFailOn(failOn);
		return this;
	}

}
