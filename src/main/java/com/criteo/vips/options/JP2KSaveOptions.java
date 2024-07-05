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
 * Optional arguments for the "jp2ksave" operation.
 */
public class JP2KSaveOptions {

	private Integer tileWidth;
	private Integer tileHeight;
	private Boolean lossless;
	private Integer q;
	private com.criteo.vips.enums.VipsForeignSubsample subsampleMode;
	private com.criteo.vips.enums.VipsForeignKeep keep;
	private double[] background;
	private com.criteo.vips.PixelPacket backgroundPixelPacket;
	private Integer pageHeight;
	private String profile;

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
	public JP2KSaveOptions tileWidth(Integer tileWidth) {
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
	public JP2KSaveOptions tileHeight(Integer tileHeight) {
		setTileHeight(tileHeight);
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
	public JP2KSaveOptions lossless(Boolean lossless) {
		setLossless(lossless);
		return this;
	}

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
	public JP2KSaveOptions q(Integer q) {
		setQ(q);
		return this;
	}

	/**
	 * Optional argument: subsample-mode
	 * <p>
	 * Select chroma subsample operation mode
	 * @return the value of {@code subsampleMode}
	 */
	public com.criteo.vips.enums.VipsForeignSubsample getSubsampleMode() {
		return this.subsampleMode;
	}

	/**
	 * Set the optional "subsample-mode" argument.
	 * <p>
	 * Select chroma subsample operation mode
	 * @param subsampleMode the new value of {@code subsampleMode}
	 */
	public void setSubsampleMode(com.criteo.vips.enums.VipsForeignSubsample subsampleMode) {
		this.subsampleMode = subsampleMode;
	}

	/**
	 * Set the optional "subsample-mode" argument.
	 * <p>
	 * Select chroma subsample operation mode
	 * @param subsampleMode the new value of {@code subsampleMode}
	 * @return this object for chaining
	 */
	public JP2KSaveOptions subsampleMode(com.criteo.vips.enums.VipsForeignSubsample subsampleMode) {
		setSubsampleMode(subsampleMode);
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
	public JP2KSaveOptions keep(com.criteo.vips.enums.VipsForeignKeep keep) {
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
	public JP2KSaveOptions background(double[] background) {
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
	public JP2KSaveOptions backgroundPixelPacket(com.criteo.vips.PixelPacket background) {
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
	public JP2KSaveOptions background(java.awt.Color background) {
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
	public JP2KSaveOptions pageHeight(Integer pageHeight) {
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
	public JP2KSaveOptions profile(String profile) {
		setProfile(profile);
		return this;
	}

}
