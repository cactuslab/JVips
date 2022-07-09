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
 * Optional arguments for the "copy" operation.
 */
public class CopyOptions {

	private Integer width;
	private Integer height;
	private Integer bands;
	private VipsBandFormat format;
	private VipsCoding coding;
	private VipsInterpretation interpretation;
	private Double xres;
	private Double yres;
	private Integer xoffset;
	private Integer yoffset;

	/**
	 * Optional argument: width
	 * <p>
	 * Image width in pixels
	 * @return the value of {@code width}
	 */
	public Integer getWidth() {
		return this.width;
	}

	/**
	 * Set the optional "width" argument.
	 * <p>
	 * Image width in pixels
	 * @param width the new value of {@code width}
	 */
	public void setWidth(Integer width) {
		this.width = width;
	}

	/**
	 * Set the optional "width" argument.
	 * <p>
	 * Image width in pixels
	 * @param width the new value of {@code width}
	 * @return this object for chaining
	 */
	public CopyOptions width(Integer width) {
		setWidth(width);
		return this;
	}

	/**
	 * Optional argument: height
	 * <p>
	 * Image height in pixels
	 * @return the value of {@code height}
	 */
	public Integer getHeight() {
		return this.height;
	}

	/**
	 * Set the optional "height" argument.
	 * <p>
	 * Image height in pixels
	 * @param height the new value of {@code height}
	 */
	public void setHeight(Integer height) {
		this.height = height;
	}

	/**
	 * Set the optional "height" argument.
	 * <p>
	 * Image height in pixels
	 * @param height the new value of {@code height}
	 * @return this object for chaining
	 */
	public CopyOptions height(Integer height) {
		setHeight(height);
		return this;
	}

	/**
	 * Optional argument: bands
	 * <p>
	 * Number of bands in image
	 * @return the value of {@code bands}
	 */
	public Integer getBands() {
		return this.bands;
	}

	/**
	 * Set the optional "bands" argument.
	 * <p>
	 * Number of bands in image
	 * @param bands the new value of {@code bands}
	 */
	public void setBands(Integer bands) {
		this.bands = bands;
	}

	/**
	 * Set the optional "bands" argument.
	 * <p>
	 * Number of bands in image
	 * @param bands the new value of {@code bands}
	 * @return this object for chaining
	 */
	public CopyOptions bands(Integer bands) {
		setBands(bands);
		return this;
	}

	/**
	 * Optional argument: format
	 * <p>
	 * Pixel format in image
	 * @return the value of {@code format}
	 */
	public VipsBandFormat getFormat() {
		return this.format;
	}

	/**
	 * Set the optional "format" argument.
	 * <p>
	 * Pixel format in image
	 * @param format the new value of {@code format}
	 */
	public void setFormat(VipsBandFormat format) {
		this.format = format;
	}

	/**
	 * Set the optional "format" argument.
	 * <p>
	 * Pixel format in image
	 * @param format the new value of {@code format}
	 * @return this object for chaining
	 */
	public CopyOptions format(VipsBandFormat format) {
		setFormat(format);
		return this;
	}

	/**
	 * Optional argument: coding
	 * <p>
	 * Pixel coding
	 * @return the value of {@code coding}
	 */
	public VipsCoding getCoding() {
		return this.coding;
	}

	/**
	 * Set the optional "coding" argument.
	 * <p>
	 * Pixel coding
	 * @param coding the new value of {@code coding}
	 */
	public void setCoding(VipsCoding coding) {
		this.coding = coding;
	}

	/**
	 * Set the optional "coding" argument.
	 * <p>
	 * Pixel coding
	 * @param coding the new value of {@code coding}
	 * @return this object for chaining
	 */
	public CopyOptions coding(VipsCoding coding) {
		setCoding(coding);
		return this;
	}

	/**
	 * Optional argument: interpretation
	 * <p>
	 * Pixel interpretation
	 * @return the value of {@code interpretation}
	 */
	public VipsInterpretation getInterpretation() {
		return this.interpretation;
	}

	/**
	 * Set the optional "interpretation" argument.
	 * <p>
	 * Pixel interpretation
	 * @param interpretation the new value of {@code interpretation}
	 */
	public void setInterpretation(VipsInterpretation interpretation) {
		this.interpretation = interpretation;
	}

	/**
	 * Set the optional "interpretation" argument.
	 * <p>
	 * Pixel interpretation
	 * @param interpretation the new value of {@code interpretation}
	 * @return this object for chaining
	 */
	public CopyOptions interpretation(VipsInterpretation interpretation) {
		setInterpretation(interpretation);
		return this;
	}

	/**
	 * Optional argument: xres
	 * <p>
	 * Horizontal resolution in pixels/mm
	 * @return the value of {@code xres}
	 */
	public Double getXres() {
		return this.xres;
	}

	/**
	 * Set the optional "xres" argument.
	 * <p>
	 * Horizontal resolution in pixels/mm
	 * @param xres the new value of {@code xres}
	 */
	public void setXres(Double xres) {
		this.xres = xres;
	}

	/**
	 * Set the optional "xres" argument.
	 * <p>
	 * Horizontal resolution in pixels/mm
	 * @param xres the new value of {@code xres}
	 * @return this object for chaining
	 */
	public CopyOptions xres(Double xres) {
		setXres(xres);
		return this;
	}

	/**
	 * Optional argument: yres
	 * <p>
	 * Vertical resolution in pixels/mm
	 * @return the value of {@code yres}
	 */
	public Double getYres() {
		return this.yres;
	}

	/**
	 * Set the optional "yres" argument.
	 * <p>
	 * Vertical resolution in pixels/mm
	 * @param yres the new value of {@code yres}
	 */
	public void setYres(Double yres) {
		this.yres = yres;
	}

	/**
	 * Set the optional "yres" argument.
	 * <p>
	 * Vertical resolution in pixels/mm
	 * @param yres the new value of {@code yres}
	 * @return this object for chaining
	 */
	public CopyOptions yres(Double yres) {
		setYres(yres);
		return this;
	}

	/**
	 * Optional argument: xoffset
	 * <p>
	 * Horizontal offset of origin
	 * @return the value of {@code xoffset}
	 */
	public Integer getXoffset() {
		return this.xoffset;
	}

	/**
	 * Set the optional "xoffset" argument.
	 * <p>
	 * Horizontal offset of origin
	 * @param xoffset the new value of {@code xoffset}
	 */
	public void setXoffset(Integer xoffset) {
		this.xoffset = xoffset;
	}

	/**
	 * Set the optional "xoffset" argument.
	 * <p>
	 * Horizontal offset of origin
	 * @param xoffset the new value of {@code xoffset}
	 * @return this object for chaining
	 */
	public CopyOptions xoffset(Integer xoffset) {
		setXoffset(xoffset);
		return this;
	}

	/**
	 * Optional argument: yoffset
	 * <p>
	 * Vertical offset of origin
	 * @return the value of {@code yoffset}
	 */
	public Integer getYoffset() {
		return this.yoffset;
	}

	/**
	 * Set the optional "yoffset" argument.
	 * <p>
	 * Vertical offset of origin
	 * @param yoffset the new value of {@code yoffset}
	 */
	public void setYoffset(Integer yoffset) {
		this.yoffset = yoffset;
	}

	/**
	 * Set the optional "yoffset" argument.
	 * <p>
	 * Vertical offset of origin
	 * @param yoffset the new value of {@code yoffset}
	 * @return this object for chaining
	 */
	public CopyOptions yoffset(Integer yoffset) {
		setYoffset(yoffset);
		return this;
	}

}
