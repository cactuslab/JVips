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
 * Optional arguments for the "heifsave_buffer" operation.
 */
public class HEIFSaveBufferOptions {

	private Integer q;
	private Boolean lossless;
	private VipsForeignHeifCompression compression;
	private Integer effort;
	private VipsForeignSubsample subsampleMode;
	private Boolean strip;
	private PixelPacket background;
	private Integer pageHeight;

	/**
	 * Optional argument: Q
	 * <p>
	 * Q factor
	 * @return the value of {@code q}
	 */
	public Integer getQ() {
		return this.q;
	}

	/**
	 * Set the optional "Q" argument.
	 * <p>
	 * Q factor
	 * @param q the new value of {@code q}
	 */
	public void setQ(Integer q) {
		this.q = q;
	}

	/**
	 * Set the optional "Q" argument.
	 * <p>
	 * Q factor
	 * @param q the new value of {@code q}
	 * @return this object for chaining
	 */
	public HEIFSaveBufferOptions q(Integer q) {
		setQ(q);
		return this;
	}

	/**
	 * Optional argument: lossless
	 * <p>
	 * Enable lossless compression
	 * @return the value of {@code lossless}
	 */
	public Boolean getLossless() {
		return this.lossless;
	}

	/**
	 * Set the optional "lossless" argument.
	 * <p>
	 * Enable lossless compression
	 * @param lossless the new value of {@code lossless}
	 */
	public void setLossless(Boolean lossless) {
		this.lossless = lossless;
	}

	/**
	 * Set the optional "lossless" argument.
	 * <p>
	 * Enable lossless compression
	 * @param lossless the new value of {@code lossless}
	 * @return this object for chaining
	 */
	public HEIFSaveBufferOptions lossless(Boolean lossless) {
		setLossless(lossless);
		return this;
	}

	/**
	 * Optional argument: compression
	 * <p>
	 * Compression format
	 * @return the value of {@code compression}
	 */
	public VipsForeignHeifCompression getCompression() {
		return this.compression;
	}

	/**
	 * Set the optional "compression" argument.
	 * <p>
	 * Compression format
	 * @param compression the new value of {@code compression}
	 */
	public void setCompression(VipsForeignHeifCompression compression) {
		this.compression = compression;
	}

	/**
	 * Set the optional "compression" argument.
	 * <p>
	 * Compression format
	 * @param compression the new value of {@code compression}
	 * @return this object for chaining
	 */
	public HEIFSaveBufferOptions compression(VipsForeignHeifCompression compression) {
		setCompression(compression);
		return this;
	}

	/**
	 * Optional argument: effort
	 * <p>
	 * CPU effort
	 * @return the value of {@code effort}
	 */
	public Integer getEffort() {
		return this.effort;
	}

	/**
	 * Set the optional "effort" argument.
	 * <p>
	 * CPU effort
	 * @param effort the new value of {@code effort}
	 */
	public void setEffort(Integer effort) {
		this.effort = effort;
	}

	/**
	 * Set the optional "effort" argument.
	 * <p>
	 * CPU effort
	 * @param effort the new value of {@code effort}
	 * @return this object for chaining
	 */
	public HEIFSaveBufferOptions effort(Integer effort) {
		setEffort(effort);
		return this;
	}

	/**
	 * Optional argument: subsample-mode
	 * <p>
	 * Select chroma subsample operation mode
	 * @return the value of {@code subsampleMode}
	 */
	public VipsForeignSubsample getSubsampleMode() {
		return this.subsampleMode;
	}

	/**
	 * Set the optional "subsample-mode" argument.
	 * <p>
	 * Select chroma subsample operation mode
	 * @param subsampleMode the new value of {@code subsampleMode}
	 */
	public void setSubsampleMode(VipsForeignSubsample subsampleMode) {
		this.subsampleMode = subsampleMode;
	}

	/**
	 * Set the optional "subsample-mode" argument.
	 * <p>
	 * Select chroma subsample operation mode
	 * @param subsampleMode the new value of {@code subsampleMode}
	 * @return this object for chaining
	 */
	public HEIFSaveBufferOptions subsampleMode(VipsForeignSubsample subsampleMode) {
		setSubsampleMode(subsampleMode);
		return this;
	}

	/**
	 * Optional argument: strip
	 * <p>
	 * Strip all metadata from image
	 * @return the value of {@code strip}
	 */
	public Boolean getStrip() {
		return this.strip;
	}

	/**
	 * Set the optional "strip" argument.
	 * <p>
	 * Strip all metadata from image
	 * @param strip the new value of {@code strip}
	 */
	public void setStrip(Boolean strip) {
		this.strip = strip;
	}

	/**
	 * Set the optional "strip" argument.
	 * <p>
	 * Strip all metadata from image
	 * @param strip the new value of {@code strip}
	 * @return this object for chaining
	 */
	public HEIFSaveBufferOptions strip(Boolean strip) {
		setStrip(strip);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Background value
	 * @return the value of {@code background}
	 */
	public PixelPacket getBackground() {
		return this.background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background value
	 * @param background the new value of {@code background}
	 */
	public void setBackground(PixelPacket background) {
		this.background = background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background value
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public HEIFSaveBufferOptions background(PixelPacket background) {
		setBackground(background);
		return this;
	}

	/**
	 * Optional argument: page-height
	 * <p>
	 * Set page height for multipage save
	 * @return the value of {@code pageHeight}
	 */
	public Integer getPageHeight() {
		return this.pageHeight;
	}

	/**
	 * Set the optional "page-height" argument.
	 * <p>
	 * Set page height for multipage save
	 * @param pageHeight the new value of {@code pageHeight}
	 */
	public void setPageHeight(Integer pageHeight) {
		this.pageHeight = pageHeight;
	}

	/**
	 * Set the optional "page-height" argument.
	 * <p>
	 * Set page height for multipage save
	 * @param pageHeight the new value of {@code pageHeight}
	 * @return this object for chaining
	 */
	public HEIFSaveBufferOptions pageHeight(Integer pageHeight) {
		setPageHeight(pageHeight);
		return this;
	}

}
