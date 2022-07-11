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
 * Optional arguments for the "pngsave" operation.
 */
public class PNGSaveOptions {

	private Integer compression;
	private Boolean interlace;
	private String profile;
	private VipsForeignPngFilter filter;
	private Boolean palette;
	private Integer q;
	private Double dither;
	private Integer bitdepth;
	private Integer effort;
	private Boolean strip;
	private double[] background;
	private PixelPacket backgroundPixelPacket;
	private Integer pageHeight;

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
	public PNGSaveOptions compression(Integer compression) {
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
	public PNGSaveOptions interlace(Boolean interlace) {
		setInterlace(interlace);
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
	public PNGSaveOptions profile(String profile) {
		setProfile(profile);
		return this;
	}

	/**
	 * Optional argument: filter
	 * <p>
	 * libpng row filter flag(s)
	 * @return the value of {@code filter}
	 */
	public VipsForeignPngFilter getFilter() {
		return this.filter;
	}

	/**
	 * Set the optional "filter" argument.
	 * <p>
	 * libpng row filter flag(s)
	 * @param filter the new value of {@code filter}
	 */
	public void setFilter(VipsForeignPngFilter filter) {
		this.filter = filter;
	}

	/**
	 * Set the optional "filter" argument.
	 * <p>
	 * libpng row filter flag(s)
	 * @param filter the new value of {@code filter}
	 * @return this object for chaining
	 */
	public PNGSaveOptions filter(VipsForeignPngFilter filter) {
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
	public PNGSaveOptions palette(Boolean palette) {
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
	public PNGSaveOptions q(Integer q) {
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
	public PNGSaveOptions dither(Double dither) {
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
	public PNGSaveOptions bitdepth(Integer bitdepth) {
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
	public PNGSaveOptions effort(Integer effort) {
		setEffort(effort);
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
	public PNGSaveOptions strip(Boolean strip) {
		setStrip(strip);
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
	public PNGSaveOptions background(double[] background) {
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
	public PNGSaveOptions backgroundPixelPacket(PixelPacket background) {
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
	public PNGSaveOptions background(java.awt.Color background) {
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
	public PNGSaveOptions pageHeight(Integer pageHeight) {
		setPageHeight(pageHeight);
		return this;
	}

}
