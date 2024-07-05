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
 * Optional arguments for the "pngsave_buffer" operation.
 */
public class PNGSaveBufferOptions {

	private Integer compression;
	private Boolean interlace;
	private com.criteo.vips.enums.VipsForeignPngFilter filter;
	private Boolean palette;
	private Integer q;
	private Double dither;
	private Integer bitdepth;
	private Integer effort;
	private com.criteo.vips.enums.VipsForeignKeep keep;
	private double[] background;
	private com.criteo.vips.PixelPacket backgroundPixelPacket;
	private Integer pageHeight;
	private String profile;

	/**
	 * Optional argument: compression
	 * <p>
	 * Compression factor
	 * @return the value of {@code compression}
	 */
	public Integer getCompression() {
		return this.compression;
	}

	/**
	 * Set the optional "compression" argument.
	 * <p>
	 * Compression factor
	 * @param compression the new value of {@code compression}
	 */
	public void setCompression(Integer compression) {
		this.compression = compression;
	}

	/**
	 * Set the optional "compression" argument.
	 * <p>
	 * Compression factor
	 * @param compression the new value of {@code compression}
	 * @return this object for chaining
	 */
	public PNGSaveBufferOptions compression(Integer compression) {
		setCompression(compression);
		return this;
	}

	/**
	 * Optional argument: interlace
	 * <p>
	 * Interlace image
	 * @return the value of {@code interlace}
	 */
	public Boolean getInterlace() {
		return this.interlace;
	}

	/**
	 * Set the optional "interlace" argument.
	 * <p>
	 * Interlace image
	 * @param interlace the new value of {@code interlace}
	 */
	public void setInterlace(Boolean interlace) {
		this.interlace = interlace;
	}

	/**
	 * Set the optional "interlace" argument.
	 * <p>
	 * Interlace image
	 * @param interlace the new value of {@code interlace}
	 * @return this object for chaining
	 */
	public PNGSaveBufferOptions interlace(Boolean interlace) {
		setInterlace(interlace);
		return this;
	}

	/**
	 * Optional argument: filter
	 * <p>
	 * libspng row filter flag(s)
	 * @return the value of {@code filter}
	 */
	public com.criteo.vips.enums.VipsForeignPngFilter getFilter() {
		return this.filter;
	}

	/**
	 * Set the optional "filter" argument.
	 * <p>
	 * libspng row filter flag(s)
	 * @param filter the new value of {@code filter}
	 */
	public void setFilter(com.criteo.vips.enums.VipsForeignPngFilter filter) {
		this.filter = filter;
	}

	/**
	 * Set the optional "filter" argument.
	 * <p>
	 * libspng row filter flag(s)
	 * @param filter the new value of {@code filter}
	 * @return this object for chaining
	 */
	public PNGSaveBufferOptions filter(com.criteo.vips.enums.VipsForeignPngFilter filter) {
		setFilter(filter);
		return this;
	}

	/**
	 * Optional argument: palette
	 * <p>
	 * Quantise to 8bpp palette
	 * @return the value of {@code palette}
	 */
	public Boolean getPalette() {
		return this.palette;
	}

	/**
	 * Set the optional "palette" argument.
	 * <p>
	 * Quantise to 8bpp palette
	 * @param palette the new value of {@code palette}
	 */
	public void setPalette(Boolean palette) {
		this.palette = palette;
	}

	/**
	 * Set the optional "palette" argument.
	 * <p>
	 * Quantise to 8bpp palette
	 * @param palette the new value of {@code palette}
	 * @return this object for chaining
	 */
	public PNGSaveBufferOptions palette(Boolean palette) {
		setPalette(palette);
		return this;
	}

	/**
	 * Optional argument: Q
	 * <p>
	 * Quantisation quality
	 * @return the value of {@code q}
	 */
	public Integer getQ() {
		return this.q;
	}

	/**
	 * Set the optional "Q" argument.
	 * <p>
	 * Quantisation quality
	 * @param q the new value of {@code q}
	 */
	public void setQ(Integer q) {
		this.q = q;
	}

	/**
	 * Set the optional "Q" argument.
	 * <p>
	 * Quantisation quality
	 * @param q the new value of {@code q}
	 * @return this object for chaining
	 */
	public PNGSaveBufferOptions q(Integer q) {
		setQ(q);
		return this;
	}

	/**
	 * Optional argument: dither
	 * <p>
	 * Amount of dithering
	 * @return the value of {@code dither}
	 */
	public Double getDither() {
		return this.dither;
	}

	/**
	 * Set the optional "dither" argument.
	 * <p>
	 * Amount of dithering
	 * @param dither the new value of {@code dither}
	 */
	public void setDither(Double dither) {
		this.dither = dither;
	}

	/**
	 * Set the optional "dither" argument.
	 * <p>
	 * Amount of dithering
	 * @param dither the new value of {@code dither}
	 * @return this object for chaining
	 */
	public PNGSaveBufferOptions dither(Double dither) {
		setDither(dither);
		return this;
	}

	/**
	 * Optional argument: bitdepth
	 * <p>
	 * Write as a 1, 2, 4, 8 or 16 bit image
	 * @return the value of {@code bitdepth}
	 */
	public Integer getBitdepth() {
		return this.bitdepth;
	}

	/**
	 * Set the optional "bitdepth" argument.
	 * <p>
	 * Write as a 1, 2, 4, 8 or 16 bit image
	 * @param bitdepth the new value of {@code bitdepth}
	 */
	public void setBitdepth(Integer bitdepth) {
		this.bitdepth = bitdepth;
	}

	/**
	 * Set the optional "bitdepth" argument.
	 * <p>
	 * Write as a 1, 2, 4, 8 or 16 bit image
	 * @param bitdepth the new value of {@code bitdepth}
	 * @return this object for chaining
	 */
	public PNGSaveBufferOptions bitdepth(Integer bitdepth) {
		setBitdepth(bitdepth);
		return this;
	}

	/**
	 * Optional argument: effort
	 * <p>
	 * Quantisation CPU effort
	 * @return the value of {@code effort}
	 */
	public Integer getEffort() {
		return this.effort;
	}

	/**
	 * Set the optional "effort" argument.
	 * <p>
	 * Quantisation CPU effort
	 * @param effort the new value of {@code effort}
	 */
	public void setEffort(Integer effort) {
		this.effort = effort;
	}

	/**
	 * Set the optional "effort" argument.
	 * <p>
	 * Quantisation CPU effort
	 * @param effort the new value of {@code effort}
	 * @return this object for chaining
	 */
	public PNGSaveBufferOptions effort(Integer effort) {
		setEffort(effort);
		return this;
	}

	/**
	 * Optional argument: keep
	 * <p>
	 * Which metadata to retain
	 * @return the value of {@code keep}
	 */
	public com.criteo.vips.enums.VipsForeignKeep getKeep() {
		return this.keep;
	}

	/**
	 * Set the optional "keep" argument.
	 * <p>
	 * Which metadata to retain
	 * @param keep the new value of {@code keep}
	 */
	public void setKeep(com.criteo.vips.enums.VipsForeignKeep keep) {
		this.keep = keep;
	}

	/**
	 * Set the optional "keep" argument.
	 * <p>
	 * Which metadata to retain
	 * @param keep the new value of {@code keep}
	 * @return this object for chaining
	 */
	public PNGSaveBufferOptions keep(com.criteo.vips.enums.VipsForeignKeep keep) {
		setKeep(keep);
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
	public PNGSaveBufferOptions background(double[] background) {
		setBackground(background);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Background value
	 * @return the value of {@code background}
	 */
	public com.criteo.vips.PixelPacket getBackgroundPixelPacket() {
		return this.backgroundPixelPacket;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background value
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
	 * Background value
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public PNGSaveBufferOptions backgroundPixelPacket(com.criteo.vips.PixelPacket background) {
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
			com.criteo.vips.PixelPacket pixelPacket = new com.criteo.vips.PixelPacket(background.getRed(), background.getGreen(), background.getBlue(), background.getAlpha());
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
	public PNGSaveBufferOptions background(java.awt.Color background) {
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
	public PNGSaveBufferOptions pageHeight(Integer pageHeight) {
		setPageHeight(pageHeight);
		return this;
	}

	/**
	 * Optional argument: profile
	 * <p>
	 * Filename of ICC profile to embed
	 * @return the value of {@code profile}
	 */
	public String getProfile() {
		return this.profile;
	}

	/**
	 * Set the optional "profile" argument.
	 * <p>
	 * Filename of ICC profile to embed
	 * @param profile the new value of {@code profile}
	 */
	public void setProfile(String profile) {
		this.profile = profile;
	}

	/**
	 * Set the optional "profile" argument.
	 * <p>
	 * Filename of ICC profile to embed
	 * @param profile the new value of {@code profile}
	 * @return this object for chaining
	 */
	public PNGSaveBufferOptions profile(String profile) {
		setProfile(profile);
		return this;
	}

}
