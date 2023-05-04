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
 * Optional arguments for the "dzsave_buffer" operation.
 */
public class DZSaveBufferOptions {

	private String basename;
	private com.criteo.vips.enums.VipsForeignDzLayout layout;
	private String suffix;
	private Integer overlap;
	private Integer tileSize;
	private Boolean centre;
	private com.criteo.vips.enums.VipsForeignDzDepth depth;
	private com.criteo.vips.enums.VipsAngle angle;
	private com.criteo.vips.enums.VipsForeignDzContainer container;
	private Integer compression;
	private com.criteo.vips.enums.VipsRegionShrink regionShrink;
	private Integer skipBlanks;
	private Boolean noStrip;
	private String id;
	private Boolean strip;
	private double[] background;
	private com.criteo.vips.PixelPacket backgroundPixelPacket;
	private Integer pageHeight;

	/**
	 * Optional argument: basename
	 * <p>
	 * Base name to save to
	 * @return the value of {@code basename}
	 */
	public String getBasename() {
		return this.basename;
	}

	/**
	 * Set the optional "basename" argument.
	 * <p>
	 * Base name to save to
	 * @param basename the new value of {@code basename}
	 */
	public void setBasename(String basename) {
		this.basename = basename;
	}

	/**
	 * Set the optional "basename" argument.
	 * <p>
	 * Base name to save to
	 * @param basename the new value of {@code basename}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions basename(String basename) {
		setBasename(basename);
		return this;
	}

	/**
	 * Optional argument: layout
	 * <p>
	 * Directory layout
	 * @return the value of {@code layout}
	 */
	public com.criteo.vips.enums.VipsForeignDzLayout getLayout() {
		return this.layout;
	}

	/**
	 * Set the optional "layout" argument.
	 * <p>
	 * Directory layout
	 * @param layout the new value of {@code layout}
	 */
	public void setLayout(com.criteo.vips.enums.VipsForeignDzLayout layout) {
		this.layout = layout;
	}

	/**
	 * Set the optional "layout" argument.
	 * <p>
	 * Directory layout
	 * @param layout the new value of {@code layout}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions layout(com.criteo.vips.enums.VipsForeignDzLayout layout) {
		setLayout(layout);
		return this;
	}

	/**
	 * Optional argument: suffix
	 * <p>
	 * Filename suffix for tiles
	 * @return the value of {@code suffix}
	 */
	public String getSuffix() {
		return this.suffix;
	}

	/**
	 * Set the optional "suffix" argument.
	 * <p>
	 * Filename suffix for tiles
	 * @param suffix the new value of {@code suffix}
	 */
	public void setSuffix(String suffix) {
		this.suffix = suffix;
	}

	/**
	 * Set the optional "suffix" argument.
	 * <p>
	 * Filename suffix for tiles
	 * @param suffix the new value of {@code suffix}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions suffix(String suffix) {
		setSuffix(suffix);
		return this;
	}

	/**
	 * Optional argument: overlap
	 * <p>
	 * Tile overlap in pixels
	 * @return the value of {@code overlap}
	 */
	public Integer getOverlap() {
		return this.overlap;
	}

	/**
	 * Set the optional "overlap" argument.
	 * <p>
	 * Tile overlap in pixels
	 * @param overlap the new value of {@code overlap}
	 */
	public void setOverlap(Integer overlap) {
		this.overlap = overlap;
	}

	/**
	 * Set the optional "overlap" argument.
	 * <p>
	 * Tile overlap in pixels
	 * @param overlap the new value of {@code overlap}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions overlap(Integer overlap) {
		setOverlap(overlap);
		return this;
	}

	/**
	 * Optional argument: tile-size
	 * <p>
	 * Tile size in pixels
	 * @return the value of {@code tileSize}
	 */
	public Integer getTileSize() {
		return this.tileSize;
	}

	/**
	 * Set the optional "tile-size" argument.
	 * <p>
	 * Tile size in pixels
	 * @param tileSize the new value of {@code tileSize}
	 */
	public void setTileSize(Integer tileSize) {
		this.tileSize = tileSize;
	}

	/**
	 * Set the optional "tile-size" argument.
	 * <p>
	 * Tile size in pixels
	 * @param tileSize the new value of {@code tileSize}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions tileSize(Integer tileSize) {
		setTileSize(tileSize);
		return this;
	}

	/**
	 * Optional argument: centre
	 * <p>
	 * Center image in tile
	 * @return the value of {@code centre}
	 */
	public Boolean getCentre() {
		return this.centre;
	}

	/**
	 * Set the optional "centre" argument.
	 * <p>
	 * Center image in tile
	 * @param centre the new value of {@code centre}
	 */
	public void setCentre(Boolean centre) {
		this.centre = centre;
	}

	/**
	 * Set the optional "centre" argument.
	 * <p>
	 * Center image in tile
	 * @param centre the new value of {@code centre}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions centre(Boolean centre) {
		setCentre(centre);
		return this;
	}

	/**
	 * Optional argument: depth
	 * <p>
	 * Pyramid depth
	 * @return the value of {@code depth}
	 */
	public com.criteo.vips.enums.VipsForeignDzDepth getDepth() {
		return this.depth;
	}

	/**
	 * Set the optional "depth" argument.
	 * <p>
	 * Pyramid depth
	 * @param depth the new value of {@code depth}
	 */
	public void setDepth(com.criteo.vips.enums.VipsForeignDzDepth depth) {
		this.depth = depth;
	}

	/**
	 * Set the optional "depth" argument.
	 * <p>
	 * Pyramid depth
	 * @param depth the new value of {@code depth}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions depth(com.criteo.vips.enums.VipsForeignDzDepth depth) {
		setDepth(depth);
		return this;
	}

	/**
	 * Optional argument: angle
	 * <p>
	 * Rotate image during save
	 * @return the value of {@code angle}
	 */
	public com.criteo.vips.enums.VipsAngle getAngle() {
		return this.angle;
	}

	/**
	 * Set the optional "angle" argument.
	 * <p>
	 * Rotate image during save
	 * @param angle the new value of {@code angle}
	 */
	public void setAngle(com.criteo.vips.enums.VipsAngle angle) {
		this.angle = angle;
	}

	/**
	 * Set the optional "angle" argument.
	 * <p>
	 * Rotate image during save
	 * @param angle the new value of {@code angle}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions angle(com.criteo.vips.enums.VipsAngle angle) {
		setAngle(angle);
		return this;
	}

	/**
	 * Optional argument: container
	 * <p>
	 * Pyramid container type
	 * @return the value of {@code container}
	 */
	public com.criteo.vips.enums.VipsForeignDzContainer getContainer() {
		return this.container;
	}

	/**
	 * Set the optional "container" argument.
	 * <p>
	 * Pyramid container type
	 * @param container the new value of {@code container}
	 */
	public void setContainer(com.criteo.vips.enums.VipsForeignDzContainer container) {
		this.container = container;
	}

	/**
	 * Set the optional "container" argument.
	 * <p>
	 * Pyramid container type
	 * @param container the new value of {@code container}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions container(com.criteo.vips.enums.VipsForeignDzContainer container) {
		setContainer(container);
		return this;
	}

	/**
	 * Optional argument: compression
	 * <p>
	 * ZIP deflate compression level
	 * @return the value of {@code compression}
	 */
	public Integer getCompression() {
		return this.compression;
	}

	/**
	 * Set the optional "compression" argument.
	 * <p>
	 * ZIP deflate compression level
	 * @param compression the new value of {@code compression}
	 */
	public void setCompression(Integer compression) {
		this.compression = compression;
	}

	/**
	 * Set the optional "compression" argument.
	 * <p>
	 * ZIP deflate compression level
	 * @param compression the new value of {@code compression}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions compression(Integer compression) {
		setCompression(compression);
		return this;
	}

	/**
	 * Optional argument: region-shrink
	 * <p>
	 * Method to shrink regions
	 * @return the value of {@code regionShrink}
	 */
	public com.criteo.vips.enums.VipsRegionShrink getRegionShrink() {
		return this.regionShrink;
	}

	/**
	 * Set the optional "region-shrink" argument.
	 * <p>
	 * Method to shrink regions
	 * @param regionShrink the new value of {@code regionShrink}
	 */
	public void setRegionShrink(com.criteo.vips.enums.VipsRegionShrink regionShrink) {
		this.regionShrink = regionShrink;
	}

	/**
	 * Set the optional "region-shrink" argument.
	 * <p>
	 * Method to shrink regions
	 * @param regionShrink the new value of {@code regionShrink}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions regionShrink(com.criteo.vips.enums.VipsRegionShrink regionShrink) {
		setRegionShrink(regionShrink);
		return this;
	}

	/**
	 * Optional argument: skip-blanks
	 * <p>
	 * Skip tiles which are nearly equal to the background
	 * @return the value of {@code skipBlanks}
	 */
	public Integer getSkipBlanks() {
		return this.skipBlanks;
	}

	/**
	 * Set the optional "skip-blanks" argument.
	 * <p>
	 * Skip tiles which are nearly equal to the background
	 * @param skipBlanks the new value of {@code skipBlanks}
	 */
	public void setSkipBlanks(Integer skipBlanks) {
		this.skipBlanks = skipBlanks;
	}

	/**
	 * Set the optional "skip-blanks" argument.
	 * <p>
	 * Skip tiles which are nearly equal to the background
	 * @param skipBlanks the new value of {@code skipBlanks}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions skipBlanks(Integer skipBlanks) {
		setSkipBlanks(skipBlanks);
		return this;
	}

	/**
	 * Optional argument: no-strip
	 * <p>
	 * Don't strip tile metadata
	 * @return the value of {@code noStrip}
	 */
	public Boolean getNoStrip() {
		return this.noStrip;
	}

	/**
	 * Set the optional "no-strip" argument.
	 * <p>
	 * Don't strip tile metadata
	 * @param noStrip the new value of {@code noStrip}
	 */
	public void setNoStrip(Boolean noStrip) {
		this.noStrip = noStrip;
	}

	/**
	 * Set the optional "no-strip" argument.
	 * <p>
	 * Don't strip tile metadata
	 * @param noStrip the new value of {@code noStrip}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions noStrip(Boolean noStrip) {
		setNoStrip(noStrip);
		return this;
	}

	/**
	 * Optional argument: id
	 * <p>
	 * Resource ID
	 * @return the value of {@code id}
	 */
	public String getId() {
		return this.id;
	}

	/**
	 * Set the optional "id" argument.
	 * <p>
	 * Resource ID
	 * @param id the new value of {@code id}
	 */
	public void setId(String id) {
		this.id = id;
	}

	/**
	 * Set the optional "id" argument.
	 * <p>
	 * Resource ID
	 * @param id the new value of {@code id}
	 * @return this object for chaining
	 */
	public DZSaveBufferOptions id(String id) {
		setId(id);
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
	public DZSaveBufferOptions strip(Boolean strip) {
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
	public DZSaveBufferOptions background(double[] background) {
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
	public DZSaveBufferOptions backgroundPixelPacket(com.criteo.vips.PixelPacket background) {
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
	public DZSaveBufferOptions background(java.awt.Color background) {
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
	public DZSaveBufferOptions pageHeight(Integer pageHeight) {
		setPageHeight(pageHeight);
		return this;
	}

}
