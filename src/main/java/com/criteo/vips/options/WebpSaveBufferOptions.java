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
 * Optional arguments for the "webpsave_buffer" operation.
 */
public class WebpSaveBufferOptions {

	private Integer q;
	private Boolean lossless;
	private com.criteo.vips.enums.VipsForeignWebpPreset preset;
	private Boolean smartSubsample;
	private Boolean nearLossless;
	private Integer alphaQ;
	private Boolean minSize;
	private Integer kmin;
	private Integer kmax;
	private Integer effort;
	private Boolean mixed;
	private com.criteo.vips.enums.VipsForeignKeep keep;
	private double[] background;
	private com.criteo.vips.PixelPacket backgroundPixelPacket;
	private Integer pageHeight;
	private String profile;

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
	public WebpSaveBufferOptions q(Integer q) {
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
	public WebpSaveBufferOptions lossless(Boolean lossless) {
		setLossless(lossless);
		return this;
	}

	/**
	 * Optional argument: preset
	 * <p>
	 * Preset for lossy compression
	 * @return the value of {@code preset}
	 */
	public com.criteo.vips.enums.VipsForeignWebpPreset getPreset() {
		return this.preset;
	}

	/**
	 * Set the optional "preset" argument.
	 * <p>
	 * Preset for lossy compression
	 * @param preset the new value of {@code preset}
	 */
	public void setPreset(com.criteo.vips.enums.VipsForeignWebpPreset preset) {
		this.preset = preset;
	}

	/**
	 * Set the optional "preset" argument.
	 * <p>
	 * Preset for lossy compression
	 * @param preset the new value of {@code preset}
	 * @return this object for chaining
	 */
	public WebpSaveBufferOptions preset(com.criteo.vips.enums.VipsForeignWebpPreset preset) {
		setPreset(preset);
		return this;
	}

	/**
	 * Optional argument: smart-subsample
	 * <p>
	 * Enable high quality chroma subsampling
	 * @return the value of {@code smartSubsample}
	 */
	public Boolean getSmartSubsample() {
		return this.smartSubsample;
	}

	/**
	 * Set the optional "smart-subsample" argument.
	 * <p>
	 * Enable high quality chroma subsampling
	 * @param smartSubsample the new value of {@code smartSubsample}
	 */
	public void setSmartSubsample(Boolean smartSubsample) {
		this.smartSubsample = smartSubsample;
	}

	/**
	 * Set the optional "smart-subsample" argument.
	 * <p>
	 * Enable high quality chroma subsampling
	 * @param smartSubsample the new value of {@code smartSubsample}
	 * @return this object for chaining
	 */
	public WebpSaveBufferOptions smartSubsample(Boolean smartSubsample) {
		setSmartSubsample(smartSubsample);
		return this;
	}

	/**
	 * Optional argument: near-lossless
	 * <p>
	 * Enable preprocessing in lossless mode (uses Q)
	 * @return the value of {@code nearLossless}
	 */
	public Boolean getNearLossless() {
		return this.nearLossless;
	}

	/**
	 * Set the optional "near-lossless" argument.
	 * <p>
	 * Enable preprocessing in lossless mode (uses Q)
	 * @param nearLossless the new value of {@code nearLossless}
	 */
	public void setNearLossless(Boolean nearLossless) {
		this.nearLossless = nearLossless;
	}

	/**
	 * Set the optional "near-lossless" argument.
	 * <p>
	 * Enable preprocessing in lossless mode (uses Q)
	 * @param nearLossless the new value of {@code nearLossless}
	 * @return this object for chaining
	 */
	public WebpSaveBufferOptions nearLossless(Boolean nearLossless) {
		setNearLossless(nearLossless);
		return this;
	}

	/**
	 * Optional argument: alpha-q
	 * <p>
	 * Change alpha plane fidelity for lossy compression
	 * @return the value of {@code alphaQ}
	 */
	public Integer getAlphaQ() {
		return this.alphaQ;
	}

	/**
	 * Set the optional "alpha-q" argument.
	 * <p>
	 * Change alpha plane fidelity for lossy compression
	 * @param alphaQ the new value of {@code alphaQ}
	 */
	public void setAlphaQ(Integer alphaQ) {
		this.alphaQ = alphaQ;
	}

	/**
	 * Set the optional "alpha-q" argument.
	 * <p>
	 * Change alpha plane fidelity for lossy compression
	 * @param alphaQ the new value of {@code alphaQ}
	 * @return this object for chaining
	 */
	public WebpSaveBufferOptions alphaQ(Integer alphaQ) {
		setAlphaQ(alphaQ);
		return this;
	}

	/**
	 * Optional argument: min-size
	 * <p>
	 * Optimise for minimum size
	 * @return the value of {@code minSize}
	 */
	public Boolean getMinSize() {
		return this.minSize;
	}

	/**
	 * Set the optional "min-size" argument.
	 * <p>
	 * Optimise for minimum size
	 * @param minSize the new value of {@code minSize}
	 */
	public void setMinSize(Boolean minSize) {
		this.minSize = minSize;
	}

	/**
	 * Set the optional "min-size" argument.
	 * <p>
	 * Optimise for minimum size
	 * @param minSize the new value of {@code minSize}
	 * @return this object for chaining
	 */
	public WebpSaveBufferOptions minSize(Boolean minSize) {
		setMinSize(minSize);
		return this;
	}

	/**
	 * Optional argument: kmin
	 * <p>
	 * Minimum number of frames between key frames
	 * @return the value of {@code kmin}
	 */
	public Integer getKmin() {
		return this.kmin;
	}

	/**
	 * Set the optional "kmin" argument.
	 * <p>
	 * Minimum number of frames between key frames
	 * @param kmin the new value of {@code kmin}
	 */
	public void setKmin(Integer kmin) {
		this.kmin = kmin;
	}

	/**
	 * Set the optional "kmin" argument.
	 * <p>
	 * Minimum number of frames between key frames
	 * @param kmin the new value of {@code kmin}
	 * @return this object for chaining
	 */
	public WebpSaveBufferOptions kmin(Integer kmin) {
		setKmin(kmin);
		return this;
	}

	/**
	 * Optional argument: kmax
	 * <p>
	 * Maximum number of frames between key frames
	 * @return the value of {@code kmax}
	 */
	public Integer getKmax() {
		return this.kmax;
	}

	/**
	 * Set the optional "kmax" argument.
	 * <p>
	 * Maximum number of frames between key frames
	 * @param kmax the new value of {@code kmax}
	 */
	public void setKmax(Integer kmax) {
		this.kmax = kmax;
	}

	/**
	 * Set the optional "kmax" argument.
	 * <p>
	 * Maximum number of frames between key frames
	 * @param kmax the new value of {@code kmax}
	 * @return this object for chaining
	 */
	public WebpSaveBufferOptions kmax(Integer kmax) {
		setKmax(kmax);
		return this;
	}

	/**
	 * Optional argument: effort
	 * <p>
	 * Level of CPU effort to reduce file size
	 * @return the value of {@code effort}
	 */
	public Integer getEffort() {
		return this.effort;
	}

	/**
	 * Set the optional "effort" argument.
	 * <p>
	 * Level of CPU effort to reduce file size
	 * @param effort the new value of {@code effort}
	 */
	public void setEffort(Integer effort) {
		this.effort = effort;
	}

	/**
	 * Set the optional "effort" argument.
	 * <p>
	 * Level of CPU effort to reduce file size
	 * @param effort the new value of {@code effort}
	 * @return this object for chaining
	 */
	public WebpSaveBufferOptions effort(Integer effort) {
		setEffort(effort);
		return this;
	}

	/**
	 * Optional argument: mixed
	 * <p>
	 * Allow mixed encoding (might reduce file size)
	 * @return the value of {@code mixed}
	 */
	public Boolean getMixed() {
		return this.mixed;
	}

	/**
	 * Set the optional "mixed" argument.
	 * <p>
	 * Allow mixed encoding (might reduce file size)
	 * @param mixed the new value of {@code mixed}
	 */
	public void setMixed(Boolean mixed) {
		this.mixed = mixed;
	}

	/**
	 * Set the optional "mixed" argument.
	 * <p>
	 * Allow mixed encoding (might reduce file size)
	 * @param mixed the new value of {@code mixed}
	 * @return this object for chaining
	 */
	public WebpSaveBufferOptions mixed(Boolean mixed) {
		setMixed(mixed);
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
	public WebpSaveBufferOptions keep(com.criteo.vips.enums.VipsForeignKeep keep) {
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
	public WebpSaveBufferOptions background(double[] background) {
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
	public WebpSaveBufferOptions backgroundPixelPacket(com.criteo.vips.PixelPacket background) {
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
	public WebpSaveBufferOptions background(java.awt.Color background) {
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
	public WebpSaveBufferOptions pageHeight(Integer pageHeight) {
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
	public WebpSaveBufferOptions profile(String profile) {
		setProfile(profile);
		return this;
	}

}
