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
 * Optional arguments for the "gifsave" operation.
 */
public class GIFSaveOptions {

	private Double dither;
	private Integer effort;
	private Integer bitdepth;
	private Double interframeMaxerror;
	private Boolean reoptimise;
	private Double interpaletteMaxerror;
	private Boolean strip;
	private double[] background;
	private PixelPacket backgroundPixelPacket;
	private Integer pageHeight;

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
	public GIFSaveOptions dither(Double dither) {
		setDither(dither);
		return this;
	}

	/**
	 * Optional argument: effort
	 * <p>
	 * Quantisation effort
	 * @return the value of {@code effort}
	 */
	public Integer getEffort() {
		return this.effort;
	}

	/**
	 * Set the optional "effort" argument.
	 * <p>
	 * Quantisation effort
	 * @param effort the new value of {@code effort}
	 */
	public void setEffort(Integer effort) {
		this.effort = effort;
	}

	/**
	 * Set the optional "effort" argument.
	 * <p>
	 * Quantisation effort
	 * @param effort the new value of {@code effort}
	 * @return this object for chaining
	 */
	public GIFSaveOptions effort(Integer effort) {
		setEffort(effort);
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
	public GIFSaveOptions bitdepth(Integer bitdepth) {
		setBitdepth(bitdepth);
		return this;
	}

	/**
	 * Optional argument: interframe-maxerror
	 * <p>
	 * Maximum inter-frame error for transparency
	 * @return the value of {@code interframeMaxerror}
	 */
	public Double getInterframeMaxerror() {
		return this.interframeMaxerror;
	}

	/**
	 * Set the optional "interframe-maxerror" argument.
	 * <p>
	 * Maximum inter-frame error for transparency
	 * @param interframeMaxerror the new value of {@code interframeMaxerror}
	 */
	public void setInterframeMaxerror(Double interframeMaxerror) {
		this.interframeMaxerror = interframeMaxerror;
	}

	/**
	 * Set the optional "interframe-maxerror" argument.
	 * <p>
	 * Maximum inter-frame error for transparency
	 * @param interframeMaxerror the new value of {@code interframeMaxerror}
	 * @return this object for chaining
	 */
	public GIFSaveOptions interframeMaxerror(Double interframeMaxerror) {
		setInterframeMaxerror(interframeMaxerror);
		return this;
	}

	/**
	 * Optional argument: reoptimise
	 * <p>
	 * Reoptimise colour palettes
	 * @return the value of {@code reoptimise}
	 */
	public Boolean getReoptimise() {
		return this.reoptimise;
	}

	/**
	 * Set the optional "reoptimise" argument.
	 * <p>
	 * Reoptimise colour palettes
	 * @param reoptimise the new value of {@code reoptimise}
	 */
	public void setReoptimise(Boolean reoptimise) {
		this.reoptimise = reoptimise;
	}

	/**
	 * Set the optional "reoptimise" argument.
	 * <p>
	 * Reoptimise colour palettes
	 * @param reoptimise the new value of {@code reoptimise}
	 * @return this object for chaining
	 */
	public GIFSaveOptions reoptimise(Boolean reoptimise) {
		setReoptimise(reoptimise);
		return this;
	}

	/**
	 * Optional argument: interpalette-maxerror
	 * <p>
	 * Maximum inter-palette error for palette reusage
	 * @return the value of {@code interpaletteMaxerror}
	 */
	public Double getInterpaletteMaxerror() {
		return this.interpaletteMaxerror;
	}

	/**
	 * Set the optional "interpalette-maxerror" argument.
	 * <p>
	 * Maximum inter-palette error for palette reusage
	 * @param interpaletteMaxerror the new value of {@code interpaletteMaxerror}
	 */
	public void setInterpaletteMaxerror(Double interpaletteMaxerror) {
		this.interpaletteMaxerror = interpaletteMaxerror;
	}

	/**
	 * Set the optional "interpalette-maxerror" argument.
	 * <p>
	 * Maximum inter-palette error for palette reusage
	 * @param interpaletteMaxerror the new value of {@code interpaletteMaxerror}
	 * @return this object for chaining
	 */
	public GIFSaveOptions interpaletteMaxerror(Double interpaletteMaxerror) {
		setInterpaletteMaxerror(interpaletteMaxerror);
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
	public GIFSaveOptions strip(Boolean strip) {
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
	public GIFSaveOptions background(double[] background) {
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
	public GIFSaveOptions backgroundPixelPacket(PixelPacket background) {
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
	public GIFSaveOptions background(java.awt.Color background) {
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
	public GIFSaveOptions pageHeight(Integer pageHeight) {
		setPageHeight(pageHeight);
		return this;
	}

}
