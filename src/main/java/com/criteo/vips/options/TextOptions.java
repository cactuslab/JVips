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
 * Optional arguments for the "text" operation.
 */
public class TextOptions {

	private String font;
	private Integer width;
	private Integer height;
	private com.criteo.vips.enums.VipsAlign align;
	private Boolean justify;
	private Integer dpi;
	private Integer spacing;
	private String fontfile;
	private Boolean rgba;
	private com.criteo.vips.enums.VipsTextWrap wrap;

	/**
	 * Optional argument: font
	 * <p>
	 * Font to render with
	 * @return the value of {@code font}
	 */
	public String getFont() {
		return this.font;
	}

	/**
	 * Set the optional "font" argument.
	 * <p>
	 * Font to render with
	 * @param font the new value of {@code font}
	 */
	public void setFont(String font) {
		this.font = font;
	}

	/**
	 * Set the optional "font" argument.
	 * <p>
	 * Font to render with
	 * @param font the new value of {@code font}
	 * @return this object for chaining
	 */
	public TextOptions font(String font) {
		setFont(font);
		return this;
	}

	/**
	 * Optional argument: width
	 * <p>
	 * Maximum image width in pixels
	 * @return the value of {@code width}
	 */
	public Integer getWidth() {
		return this.width;
	}

	/**
	 * Set the optional "width" argument.
	 * <p>
	 * Maximum image width in pixels
	 * @param width the new value of {@code width}
	 */
	public void setWidth(Integer width) {
		this.width = width;
	}

	/**
	 * Set the optional "width" argument.
	 * <p>
	 * Maximum image width in pixels
	 * @param width the new value of {@code width}
	 * @return this object for chaining
	 */
	public TextOptions width(Integer width) {
		setWidth(width);
		return this;
	}

	/**
	 * Optional argument: height
	 * <p>
	 * Maximum image height in pixels
	 * @return the value of {@code height}
	 */
	public Integer getHeight() {
		return this.height;
	}

	/**
	 * Set the optional "height" argument.
	 * <p>
	 * Maximum image height in pixels
	 * @param height the new value of {@code height}
	 */
	public void setHeight(Integer height) {
		this.height = height;
	}

	/**
	 * Set the optional "height" argument.
	 * <p>
	 * Maximum image height in pixels
	 * @param height the new value of {@code height}
	 * @return this object for chaining
	 */
	public TextOptions height(Integer height) {
		setHeight(height);
		return this;
	}

	/**
	 * Optional argument: align
	 * <p>
	 * Align on the low, centre or high edge
	 * @return the value of {@code align}
	 */
	public com.criteo.vips.enums.VipsAlign getAlign() {
		return this.align;
	}

	/**
	 * Set the optional "align" argument.
	 * <p>
	 * Align on the low, centre or high edge
	 * @param align the new value of {@code align}
	 */
	public void setAlign(com.criteo.vips.enums.VipsAlign align) {
		this.align = align;
	}

	/**
	 * Set the optional "align" argument.
	 * <p>
	 * Align on the low, centre or high edge
	 * @param align the new value of {@code align}
	 * @return this object for chaining
	 */
	public TextOptions align(com.criteo.vips.enums.VipsAlign align) {
		setAlign(align);
		return this;
	}

	/**
	 * Optional argument: justify
	 * <p>
	 * Justify lines
	 * @return the value of {@code justify}
	 */
	public Boolean getJustify() {
		return this.justify;
	}

	/**
	 * Set the optional "justify" argument.
	 * <p>
	 * Justify lines
	 * @param justify the new value of {@code justify}
	 */
	public void setJustify(Boolean justify) {
		this.justify = justify;
	}

	/**
	 * Set the optional "justify" argument.
	 * <p>
	 * Justify lines
	 * @param justify the new value of {@code justify}
	 * @return this object for chaining
	 */
	public TextOptions justify(Boolean justify) {
		setJustify(justify);
		return this;
	}

	/**
	 * Optional argument: dpi
	 * <p>
	 * DPI to render at
	 * @return the value of {@code dpi}
	 */
	public Integer getDpi() {
		return this.dpi;
	}

	/**
	 * Set the optional "dpi" argument.
	 * <p>
	 * DPI to render at
	 * @param dpi the new value of {@code dpi}
	 */
	public void setDpi(Integer dpi) {
		this.dpi = dpi;
	}

	/**
	 * Set the optional "dpi" argument.
	 * <p>
	 * DPI to render at
	 * @param dpi the new value of {@code dpi}
	 * @return this object for chaining
	 */
	public TextOptions dpi(Integer dpi) {
		setDpi(dpi);
		return this;
	}

	/**
	 * Optional argument: spacing
	 * <p>
	 * Line spacing
	 * @return the value of {@code spacing}
	 */
	public Integer getSpacing() {
		return this.spacing;
	}

	/**
	 * Set the optional "spacing" argument.
	 * <p>
	 * Line spacing
	 * @param spacing the new value of {@code spacing}
	 */
	public void setSpacing(Integer spacing) {
		this.spacing = spacing;
	}

	/**
	 * Set the optional "spacing" argument.
	 * <p>
	 * Line spacing
	 * @param spacing the new value of {@code spacing}
	 * @return this object for chaining
	 */
	public TextOptions spacing(Integer spacing) {
		setSpacing(spacing);
		return this;
	}

	/**
	 * Optional argument: fontfile
	 * <p>
	 * Load this font file
	 * @return the value of {@code fontfile}
	 */
	public String getFontfile() {
		return this.fontfile;
	}

	/**
	 * Set the optional "fontfile" argument.
	 * <p>
	 * Load this font file
	 * @param fontfile the new value of {@code fontfile}
	 */
	public void setFontfile(String fontfile) {
		this.fontfile = fontfile;
	}

	/**
	 * Set the optional "fontfile" argument.
	 * <p>
	 * Load this font file
	 * @param fontfile the new value of {@code fontfile}
	 * @return this object for chaining
	 */
	public TextOptions fontfile(String fontfile) {
		setFontfile(fontfile);
		return this;
	}

	/**
	 * Optional argument: rgba
	 * <p>
	 * Enable RGBA output
	 * @return the value of {@code rgba}
	 */
	public Boolean getRgba() {
		return this.rgba;
	}

	/**
	 * Set the optional "rgba" argument.
	 * <p>
	 * Enable RGBA output
	 * @param rgba the new value of {@code rgba}
	 */
	public void setRgba(Boolean rgba) {
		this.rgba = rgba;
	}

	/**
	 * Set the optional "rgba" argument.
	 * <p>
	 * Enable RGBA output
	 * @param rgba the new value of {@code rgba}
	 * @return this object for chaining
	 */
	public TextOptions rgba(Boolean rgba) {
		setRgba(rgba);
		return this;
	}

	/**
	 * Optional argument: wrap
	 * <p>
	 * Wrap lines on word or character boundaries
	 * @return the value of {@code wrap}
	 */
	public com.criteo.vips.enums.VipsTextWrap getWrap() {
		return this.wrap;
	}

	/**
	 * Set the optional "wrap" argument.
	 * <p>
	 * Wrap lines on word or character boundaries
	 * @param wrap the new value of {@code wrap}
	 */
	public void setWrap(com.criteo.vips.enums.VipsTextWrap wrap) {
		this.wrap = wrap;
	}

	/**
	 * Set the optional "wrap" argument.
	 * <p>
	 * Wrap lines on word or character boundaries
	 * @param wrap the new value of {@code wrap}
	 * @return this object for chaining
	 */
	public TextOptions wrap(com.criteo.vips.enums.VipsTextWrap wrap) {
		setWrap(wrap);
		return this;
	}

}
