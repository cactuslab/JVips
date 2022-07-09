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
 * Optional arguments for the "jpegsave_buffer" operation.
 */
public class JPEGSaveBufferOptions {

	private Integer q;
	private String profile;
	private Boolean optimizeCoding;
	private Boolean interlace;
	private Boolean trellisQuant;
	private Boolean overshootDeringing;
	private Boolean optimizeScans;
	private Integer quantTable;
	private VipsForeignSubsample subsampleMode;
	private Integer restartInterval;
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
	public JPEGSaveBufferOptions q(Integer q) {
		setQ(q);
		return this;
	}

	/**
	 * Optional argument: profile
	 * <p>
	 * ICC profile to embed
	 * @return the value of {@code profile}
	 */
	public String getProfile() {
		return this.profile;
	}

	/**
	 * Set the optional "profile" argument.
	 * <p>
	 * ICC profile to embed
	 * @param profile the new value of {@code profile}
	 */
	public void setProfile(String profile) {
		this.profile = profile;
	}

	/**
	 * Set the optional "profile" argument.
	 * <p>
	 * ICC profile to embed
	 * @param profile the new value of {@code profile}
	 * @return this object for chaining
	 */
	public JPEGSaveBufferOptions profile(String profile) {
		setProfile(profile);
		return this;
	}

	/**
	 * Optional argument: optimize-coding
	 * <p>
	 * Compute optimal Huffman coding tables
	 * @return the value of {@code optimizeCoding}
	 */
	public Boolean getOptimizeCoding() {
		return this.optimizeCoding;
	}

	/**
	 * Set the optional "optimize-coding" argument.
	 * <p>
	 * Compute optimal Huffman coding tables
	 * @param optimizeCoding the new value of {@code optimizeCoding}
	 */
	public void setOptimizeCoding(Boolean optimizeCoding) {
		this.optimizeCoding = optimizeCoding;
	}

	/**
	 * Set the optional "optimize-coding" argument.
	 * <p>
	 * Compute optimal Huffman coding tables
	 * @param optimizeCoding the new value of {@code optimizeCoding}
	 * @return this object for chaining
	 */
	public JPEGSaveBufferOptions optimizeCoding(Boolean optimizeCoding) {
		setOptimizeCoding(optimizeCoding);
		return this;
	}

	/**
	 * Optional argument: interlace
	 * <p>
	 * Generate an interlaced (progressive) jpeg
	 * @return the value of {@code interlace}
	 */
	public Boolean getInterlace() {
		return this.interlace;
	}

	/**
	 * Set the optional "interlace" argument.
	 * <p>
	 * Generate an interlaced (progressive) jpeg
	 * @param interlace the new value of {@code interlace}
	 */
	public void setInterlace(Boolean interlace) {
		this.interlace = interlace;
	}

	/**
	 * Set the optional "interlace" argument.
	 * <p>
	 * Generate an interlaced (progressive) jpeg
	 * @param interlace the new value of {@code interlace}
	 * @return this object for chaining
	 */
	public JPEGSaveBufferOptions interlace(Boolean interlace) {
		setInterlace(interlace);
		return this;
	}

	/**
	 * Optional argument: trellis-quant
	 * <p>
	 * Apply trellis quantisation to each 8x8 block
	 * @return the value of {@code trellisQuant}
	 */
	public Boolean getTrellisQuant() {
		return this.trellisQuant;
	}

	/**
	 * Set the optional "trellis-quant" argument.
	 * <p>
	 * Apply trellis quantisation to each 8x8 block
	 * @param trellisQuant the new value of {@code trellisQuant}
	 */
	public void setTrellisQuant(Boolean trellisQuant) {
		this.trellisQuant = trellisQuant;
	}

	/**
	 * Set the optional "trellis-quant" argument.
	 * <p>
	 * Apply trellis quantisation to each 8x8 block
	 * @param trellisQuant the new value of {@code trellisQuant}
	 * @return this object for chaining
	 */
	public JPEGSaveBufferOptions trellisQuant(Boolean trellisQuant) {
		setTrellisQuant(trellisQuant);
		return this;
	}

	/**
	 * Optional argument: overshoot-deringing
	 * <p>
	 * Apply overshooting to samples with extreme values
	 * @return the value of {@code overshootDeringing}
	 */
	public Boolean getOvershootDeringing() {
		return this.overshootDeringing;
	}

	/**
	 * Set the optional "overshoot-deringing" argument.
	 * <p>
	 * Apply overshooting to samples with extreme values
	 * @param overshootDeringing the new value of {@code overshootDeringing}
	 */
	public void setOvershootDeringing(Boolean overshootDeringing) {
		this.overshootDeringing = overshootDeringing;
	}

	/**
	 * Set the optional "overshoot-deringing" argument.
	 * <p>
	 * Apply overshooting to samples with extreme values
	 * @param overshootDeringing the new value of {@code overshootDeringing}
	 * @return this object for chaining
	 */
	public JPEGSaveBufferOptions overshootDeringing(Boolean overshootDeringing) {
		setOvershootDeringing(overshootDeringing);
		return this;
	}

	/**
	 * Optional argument: optimize-scans
	 * <p>
	 * Split spectrum of DCT coefficients into separate scans
	 * @return the value of {@code optimizeScans}
	 */
	public Boolean getOptimizeScans() {
		return this.optimizeScans;
	}

	/**
	 * Set the optional "optimize-scans" argument.
	 * <p>
	 * Split spectrum of DCT coefficients into separate scans
	 * @param optimizeScans the new value of {@code optimizeScans}
	 */
	public void setOptimizeScans(Boolean optimizeScans) {
		this.optimizeScans = optimizeScans;
	}

	/**
	 * Set the optional "optimize-scans" argument.
	 * <p>
	 * Split spectrum of DCT coefficients into separate scans
	 * @param optimizeScans the new value of {@code optimizeScans}
	 * @return this object for chaining
	 */
	public JPEGSaveBufferOptions optimizeScans(Boolean optimizeScans) {
		setOptimizeScans(optimizeScans);
		return this;
	}

	/**
	 * Optional argument: quant-table
	 * <p>
	 * Use predefined quantization table with given index
	 * @return the value of {@code quantTable}
	 */
	public Integer getQuantTable() {
		return this.quantTable;
	}

	/**
	 * Set the optional "quant-table" argument.
	 * <p>
	 * Use predefined quantization table with given index
	 * @param quantTable the new value of {@code quantTable}
	 */
	public void setQuantTable(Integer quantTable) {
		this.quantTable = quantTable;
	}

	/**
	 * Set the optional "quant-table" argument.
	 * <p>
	 * Use predefined quantization table with given index
	 * @param quantTable the new value of {@code quantTable}
	 * @return this object for chaining
	 */
	public JPEGSaveBufferOptions quantTable(Integer quantTable) {
		setQuantTable(quantTable);
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
	public JPEGSaveBufferOptions subsampleMode(VipsForeignSubsample subsampleMode) {
		setSubsampleMode(subsampleMode);
		return this;
	}

	/**
	 * Optional argument: restart-interval
	 * <p>
	 * Add restart markers every specified number of mcu
	 * @return the value of {@code restartInterval}
	 */
	public Integer getRestartInterval() {
		return this.restartInterval;
	}

	/**
	 * Set the optional "restart-interval" argument.
	 * <p>
	 * Add restart markers every specified number of mcu
	 * @param restartInterval the new value of {@code restartInterval}
	 */
	public void setRestartInterval(Integer restartInterval) {
		this.restartInterval = restartInterval;
	}

	/**
	 * Set the optional "restart-interval" argument.
	 * <p>
	 * Add restart markers every specified number of mcu
	 * @param restartInterval the new value of {@code restartInterval}
	 * @return this object for chaining
	 */
	public JPEGSaveBufferOptions restartInterval(Integer restartInterval) {
		setRestartInterval(restartInterval);
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
	public JPEGSaveBufferOptions strip(Boolean strip) {
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
	public JPEGSaveBufferOptions background(PixelPacket background) {
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
	public JPEGSaveBufferOptions pageHeight(Integer pageHeight) {
		setPageHeight(pageHeight);
		return this;
	}

}
