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
 * Optional arguments for the "magicksave_buffer" operation.
 */
public class MagickSaveBufferOptions {

	private String format;
	private Integer quality;
	private Boolean optimizeGifFrames;
	private Boolean optimizeGifTransparency;
	private Integer bitdepth;
	private Boolean strip;
	private double[] background;
	private com.criteo.vips.PixelPacket backgroundPixelPacket;
	private Integer pageHeight;

	/**
	 * Optional argument: format
	 * <p>
	 * Format to save in
	 * @return the value of {@code format}
	 */
	public String getFormat() {
		return this.format;
	}

	/**
	 * Set the optional "format" argument.
	 * <p>
	 * Format to save in
	 * @param format the new value of {@code format}
	 */
	public void setFormat(String format) {
		this.format = format;
	}

	/**
	 * Set the optional "format" argument.
	 * <p>
	 * Format to save in
	 * @param format the new value of {@code format}
	 * @return this object for chaining
	 */
	public MagickSaveBufferOptions format(String format) {
		setFormat(format);
		return this;
	}

	/**
	 * Optional argument: quality
	 * <p>
	 * Quality to use
	 * @return the value of {@code quality}
	 */
	public Integer getQuality() {
		return this.quality;
	}

	/**
	 * Set the optional "quality" argument.
	 * <p>
	 * Quality to use
	 * @param quality the new value of {@code quality}
	 */
	public void setQuality(Integer quality) {
		this.quality = quality;
	}

	/**
	 * Set the optional "quality" argument.
	 * <p>
	 * Quality to use
	 * @param quality the new value of {@code quality}
	 * @return this object for chaining
	 */
	public MagickSaveBufferOptions quality(Integer quality) {
		setQuality(quality);
		return this;
	}

	/**
	 * Optional argument: optimize-gif-frames
	 * <p>
	 * Apply GIF frames optimization
	 * @return the value of {@code optimizeGifFrames}
	 */
	public Boolean getOptimizeGifFrames() {
		return this.optimizeGifFrames;
	}

	/**
	 * Set the optional "optimize-gif-frames" argument.
	 * <p>
	 * Apply GIF frames optimization
	 * @param optimizeGifFrames the new value of {@code optimizeGifFrames}
	 */
	public void setOptimizeGifFrames(Boolean optimizeGifFrames) {
		this.optimizeGifFrames = optimizeGifFrames;
	}

	/**
	 * Set the optional "optimize-gif-frames" argument.
	 * <p>
	 * Apply GIF frames optimization
	 * @param optimizeGifFrames the new value of {@code optimizeGifFrames}
	 * @return this object for chaining
	 */
	public MagickSaveBufferOptions optimizeGifFrames(Boolean optimizeGifFrames) {
		setOptimizeGifFrames(optimizeGifFrames);
		return this;
	}

	/**
	 * Optional argument: optimize-gif-transparency
	 * <p>
	 * Apply GIF transparency optimization
	 * @return the value of {@code optimizeGifTransparency}
	 */
	public Boolean getOptimizeGifTransparency() {
		return this.optimizeGifTransparency;
	}

	/**
	 * Set the optional "optimize-gif-transparency" argument.
	 * <p>
	 * Apply GIF transparency optimization
	 * @param optimizeGifTransparency the new value of {@code optimizeGifTransparency}
	 */
	public void setOptimizeGifTransparency(Boolean optimizeGifTransparency) {
		this.optimizeGifTransparency = optimizeGifTransparency;
	}

	/**
	 * Set the optional "optimize-gif-transparency" argument.
	 * <p>
	 * Apply GIF transparency optimization
	 * @param optimizeGifTransparency the new value of {@code optimizeGifTransparency}
	 * @return this object for chaining
	 */
	public MagickSaveBufferOptions optimizeGifTransparency(Boolean optimizeGifTransparency) {
		setOptimizeGifTransparency(optimizeGifTransparency);
		return this;
	}

	/**
	 * Optional argument: bitdepth
	 * <p>
	 * Number of bits per pixel
	 * @return the value of {@code bitdepth}
	 */
	public Integer getBitdepth() {
		return this.bitdepth;
	}

	/**
	 * Set the optional "bitdepth" argument.
	 * <p>
	 * Number of bits per pixel
	 * @param bitdepth the new value of {@code bitdepth}
	 */
	public void setBitdepth(Integer bitdepth) {
		this.bitdepth = bitdepth;
	}

	/**
	 * Set the optional "bitdepth" argument.
	 * <p>
	 * Number of bits per pixel
	 * @param bitdepth the new value of {@code bitdepth}
	 * @return this object for chaining
	 */
	public MagickSaveBufferOptions bitdepth(Integer bitdepth) {
		setBitdepth(bitdepth);
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
	public MagickSaveBufferOptions strip(Boolean strip) {
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
	public MagickSaveBufferOptions background(double[] background) {
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
	public MagickSaveBufferOptions backgroundPixelPacket(com.criteo.vips.PixelPacket background) {
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
	public MagickSaveBufferOptions background(java.awt.Color background) {
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
	public MagickSaveBufferOptions pageHeight(Integer pageHeight) {
		setPageHeight(pageHeight);
		return this;
	}

}
