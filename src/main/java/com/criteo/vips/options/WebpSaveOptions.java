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
 * Optional arguments for the "webpsave" operation.
 */
public class WebpSaveOptions {

	private Integer q;
	private Boolean lossless;
	private VipsForeignWebpPreset preset;
	private Boolean smartSubsample;
	private Boolean nearLossless;
	private Integer alphaQ;
	private Boolean minSize;
	private Integer kmin;
	private Integer kmax;
	private Integer effort;
	private String profile;
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
	public WebpSaveOptions q(Integer q) {
		setQ(q);
		return this;
	}

	/**
	 * Optional argument: lossless
	 * <p>
	 * enable lossless compression
	 * @return the value of {@code lossless}
	 */
	public Boolean getLossless() {
		return this.lossless;
	}

	/**
	 * Set the optional "lossless" argument.
	 * <p>
	 * enable lossless compression
	 * @param lossless the new value of {@code lossless}
	 */
	public void setLossless(Boolean lossless) {
		this.lossless = lossless;
	}

	/**
	 * Set the optional "lossless" argument.
	 * <p>
	 * enable lossless compression
	 * @param lossless the new value of {@code lossless}
	 * @return this object for chaining
	 */
	public WebpSaveOptions lossless(Boolean lossless) {
		setLossless(lossless);
		return this;
	}

	/**
	 * Optional argument: preset
	 * <p>
	 * Preset for lossy compression
	 * @return the value of {@code preset}
	 */
	public VipsForeignWebpPreset getPreset() {
		return this.preset;
	}

	/**
	 * Set the optional "preset" argument.
	 * <p>
	 * Preset for lossy compression
	 * @param preset the new value of {@code preset}
	 */
	public void setPreset(VipsForeignWebpPreset preset) {
		this.preset = preset;
	}

	/**
	 * Set the optional "preset" argument.
	 * <p>
	 * Preset for lossy compression
	 * @param preset the new value of {@code preset}
	 * @return this object for chaining
	 */
	public WebpSaveOptions preset(VipsForeignWebpPreset preset) {
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
	public WebpSaveOptions smartSubsample(Boolean smartSubsample) {
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
	public WebpSaveOptions nearLossless(Boolean nearLossless) {
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
	public WebpSaveOptions alphaQ(Integer alphaQ) {
		setAlphaQ(alphaQ);
		return this;
	}

	/**
	 * Optional argument: min-size
	 * <p>
	 * Optimise for minium size
	 * @return the value of {@code minSize}
	 */
	public Boolean getMinSize() {
		return this.minSize;
	}

	/**
	 * Set the optional "min-size" argument.
	 * <p>
	 * Optimise for minium size
	 * @param minSize the new value of {@code minSize}
	 */
	public void setMinSize(Boolean minSize) {
		this.minSize = minSize;
	}

	/**
	 * Set the optional "min-size" argument.
	 * <p>
	 * Optimise for minium size
	 * @param minSize the new value of {@code minSize}
	 * @return this object for chaining
	 */
	public WebpSaveOptions minSize(Boolean minSize) {
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
	public WebpSaveOptions kmin(Integer kmin) {
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
	public WebpSaveOptions kmax(Integer kmax) {
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
	public WebpSaveOptions effort(Integer effort) {
		setEffort(effort);
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
	public WebpSaveOptions profile(String profile) {
		setProfile(profile);
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
	public WebpSaveOptions strip(Boolean strip) {
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
	public WebpSaveOptions background(PixelPacket background) {
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
	public WebpSaveOptions pageHeight(Integer pageHeight) {
		setPageHeight(pageHeight);
		return this;
	}

}
