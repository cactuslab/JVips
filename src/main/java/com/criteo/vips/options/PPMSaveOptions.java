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
import com.criteo.vips.enums.*;

/**
 * Optional arguments for the "ppmsave" operation.
 */
public class PPMSaveOptions {

	private VipsForeignPpmFormat format;
	private Boolean ascii;
	private Integer bitdepth;
	private Boolean strip;
	private double[] background;
	private Integer pageHeight;

	/**
	 * Optional argument: format
	 * <p>
	 * Format to save in
	 * @return the value of {@code format}
	 */
	public VipsForeignPpmFormat getFormat() {
		return this.format;
	}

	/**
	 * Set the optional "format" argument.
	 * <p>
	 * Format to save in
	 * @param format the new value of {@code format}
	 */
	public void setFormat(VipsForeignPpmFormat format) {
		this.format = format;
	}

	/**
	 * Set the optional "format" argument.
	 * <p>
	 * Format to save in
	 * @param format the new value of {@code format}
	 * @return this object for chaining
	 */
	public PPMSaveOptions format(VipsForeignPpmFormat format) {
		setFormat(format);
		return this;
	}

	/**
	 * Optional argument: ascii
	 * <p>
	 * save as ascii
	 * @return the value of {@code ascii}
	 */
	public Boolean getAscii() {
		return this.ascii;
	}

	/**
	 * Set the optional "ascii" argument.
	 * <p>
	 * save as ascii
	 * @param ascii the new value of {@code ascii}
	 */
	public void setAscii(Boolean ascii) {
		this.ascii = ascii;
	}

	/**
	 * Set the optional "ascii" argument.
	 * <p>
	 * save as ascii
	 * @param ascii the new value of {@code ascii}
	 * @return this object for chaining
	 */
	public PPMSaveOptions ascii(Boolean ascii) {
		setAscii(ascii);
		return this;
	}

	/**
	 * Optional argument: bitdepth
	 * <p>
	 * set to 1 to write as a 1 bit image
	 * @return the value of {@code bitdepth}
	 */
	public Integer getBitdepth() {
		return this.bitdepth;
	}

	/**
	 * Set the optional "bitdepth" argument.
	 * <p>
	 * set to 1 to write as a 1 bit image
	 * @param bitdepth the new value of {@code bitdepth}
	 */
	public void setBitdepth(Integer bitdepth) {
		this.bitdepth = bitdepth;
	}

	/**
	 * Set the optional "bitdepth" argument.
	 * <p>
	 * set to 1 to write as a 1 bit image
	 * @param bitdepth the new value of {@code bitdepth}
	 * @return this object for chaining
	 */
	public PPMSaveOptions bitdepth(Integer bitdepth) {
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
	public PPMSaveOptions strip(Boolean strip) {
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
	public PPMSaveOptions background(double[] background) {
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
	public PPMSaveOptions pageHeight(Integer pageHeight) {
		setPageHeight(pageHeight);
		return this;
	}

}
