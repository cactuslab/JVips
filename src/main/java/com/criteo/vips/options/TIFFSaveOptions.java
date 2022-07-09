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
 * Optional arguments for the "tiffsave" operation.
 */
public class TIFFSaveOptions {

	private VipsForeignTiffCompression compression;
	private Integer q;
	private VipsForeignTiffPredictor predictor;
	private String profile;
	private Boolean tile;
	private Integer tileWidth;
	private Integer tileHeight;
	private Boolean pyramid;
	private Boolean miniswhite;
	private Integer bitdepth;
	private VipsForeignTiffResunit resunit;
	private Double xres;
	private Double yres;
	private Boolean bigtiff;
	private Boolean properties;
	private VipsRegionShrink regionShrink;
	private Integer level;
	private Boolean lossless;
	private VipsForeignDzDepth depth;
	private Boolean subifd;
	private Boolean premultiply;
	private Boolean strip;
	private PixelPacket background;
	private Integer pageHeight;

	/**
	 * Optional argument: compression
	 * <p>
	 * Compression for this file
	 * @return the value of {@code compression}
	 */
	public VipsForeignTiffCompression getCompression() {
		return this.compression;
	}

	/**
	 * Set the optional "compression" argument.
	 * <p>
	 * Compression for this file
	 * @param compression the new value of {@code compression}
	 */
	public void setCompression(VipsForeignTiffCompression compression) {
		this.compression = compression;
	}

	/**
	 * Set the optional "compression" argument.
	 * <p>
	 * Compression for this file
	 * @param compression the new value of {@code compression}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions compression(VipsForeignTiffCompression compression) {
		setCompression(compression);
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
	public TIFFSaveOptions q(Integer q) {
		setQ(q);
		return this;
	}

	/**
	 * Optional argument: predictor
	 * <p>
	 * Compression prediction
	 * @return the value of {@code predictor}
	 */
	public VipsForeignTiffPredictor getPredictor() {
		return this.predictor;
	}

	/**
	 * Set the optional "predictor" argument.
	 * <p>
	 * Compression prediction
	 * @param predictor the new value of {@code predictor}
	 */
	public void setPredictor(VipsForeignTiffPredictor predictor) {
		this.predictor = predictor;
	}

	/**
	 * Set the optional "predictor" argument.
	 * <p>
	 * Compression prediction
	 * @param predictor the new value of {@code predictor}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions predictor(VipsForeignTiffPredictor predictor) {
		setPredictor(predictor);
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
	public TIFFSaveOptions profile(String profile) {
		setProfile(profile);
		return this;
	}

	/**
	 * Optional argument: tile
	 * <p>
	 * Write a tiled tiff
	 * @return the value of {@code tile}
	 */
	public Boolean getTile() {
		return this.tile;
	}

	/**
	 * Set the optional "tile" argument.
	 * <p>
	 * Write a tiled tiff
	 * @param tile the new value of {@code tile}
	 */
	public void setTile(Boolean tile) {
		this.tile = tile;
	}

	/**
	 * Set the optional "tile" argument.
	 * <p>
	 * Write a tiled tiff
	 * @param tile the new value of {@code tile}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions tile(Boolean tile) {
		setTile(tile);
		return this;
	}

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
	public TIFFSaveOptions tileWidth(Integer tileWidth) {
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
	public TIFFSaveOptions tileHeight(Integer tileHeight) {
		setTileHeight(tileHeight);
		return this;
	}

	/**
	 * Optional argument: pyramid
	 * <p>
	 * Write a pyramidal tiff
	 * @return the value of {@code pyramid}
	 */
	public Boolean getPyramid() {
		return this.pyramid;
	}

	/**
	 * Set the optional "pyramid" argument.
	 * <p>
	 * Write a pyramidal tiff
	 * @param pyramid the new value of {@code pyramid}
	 */
	public void setPyramid(Boolean pyramid) {
		this.pyramid = pyramid;
	}

	/**
	 * Set the optional "pyramid" argument.
	 * <p>
	 * Write a pyramidal tiff
	 * @param pyramid the new value of {@code pyramid}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions pyramid(Boolean pyramid) {
		setPyramid(pyramid);
		return this;
	}

	/**
	 * Optional argument: miniswhite
	 * <p>
	 * Use 0 for white in 1-bit images
	 * @return the value of {@code miniswhite}
	 */
	public Boolean getMiniswhite() {
		return this.miniswhite;
	}

	/**
	 * Set the optional "miniswhite" argument.
	 * <p>
	 * Use 0 for white in 1-bit images
	 * @param miniswhite the new value of {@code miniswhite}
	 */
	public void setMiniswhite(Boolean miniswhite) {
		this.miniswhite = miniswhite;
	}

	/**
	 * Set the optional "miniswhite" argument.
	 * <p>
	 * Use 0 for white in 1-bit images
	 * @param miniswhite the new value of {@code miniswhite}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions miniswhite(Boolean miniswhite) {
		setMiniswhite(miniswhite);
		return this;
	}

	/**
	 * Optional argument: bitdepth
	 * <p>
	 * Write as a 1, 2, 4 or 8 bit image
	 * @return the value of {@code bitdepth}
	 */
	public Integer getBitdepth() {
		return this.bitdepth;
	}

	/**
	 * Set the optional "bitdepth" argument.
	 * <p>
	 * Write as a 1, 2, 4 or 8 bit image
	 * @param bitdepth the new value of {@code bitdepth}
	 */
	public void setBitdepth(Integer bitdepth) {
		this.bitdepth = bitdepth;
	}

	/**
	 * Set the optional "bitdepth" argument.
	 * <p>
	 * Write as a 1, 2, 4 or 8 bit image
	 * @param bitdepth the new value of {@code bitdepth}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions bitdepth(Integer bitdepth) {
		setBitdepth(bitdepth);
		return this;
	}

	/**
	 * Optional argument: resunit
	 * <p>
	 * Resolution unit
	 * @return the value of {@code resunit}
	 */
	public VipsForeignTiffResunit getResunit() {
		return this.resunit;
	}

	/**
	 * Set the optional "resunit" argument.
	 * <p>
	 * Resolution unit
	 * @param resunit the new value of {@code resunit}
	 */
	public void setResunit(VipsForeignTiffResunit resunit) {
		this.resunit = resunit;
	}

	/**
	 * Set the optional "resunit" argument.
	 * <p>
	 * Resolution unit
	 * @param resunit the new value of {@code resunit}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions resunit(VipsForeignTiffResunit resunit) {
		setResunit(resunit);
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
	public TIFFSaveOptions xres(Double xres) {
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
	public TIFFSaveOptions yres(Double yres) {
		setYres(yres);
		return this;
	}

	/**
	 * Optional argument: bigtiff
	 * <p>
	 * Write a bigtiff image
	 * @return the value of {@code bigtiff}
	 */
	public Boolean getBigtiff() {
		return this.bigtiff;
	}

	/**
	 * Set the optional "bigtiff" argument.
	 * <p>
	 * Write a bigtiff image
	 * @param bigtiff the new value of {@code bigtiff}
	 */
	public void setBigtiff(Boolean bigtiff) {
		this.bigtiff = bigtiff;
	}

	/**
	 * Set the optional "bigtiff" argument.
	 * <p>
	 * Write a bigtiff image
	 * @param bigtiff the new value of {@code bigtiff}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions bigtiff(Boolean bigtiff) {
		setBigtiff(bigtiff);
		return this;
	}

	/**
	 * Optional argument: properties
	 * <p>
	 * Write a properties document to IMAGEDESCRIPTION
	 * @return the value of {@code properties}
	 */
	public Boolean getProperties() {
		return this.properties;
	}

	/**
	 * Set the optional "properties" argument.
	 * <p>
	 * Write a properties document to IMAGEDESCRIPTION
	 * @param properties the new value of {@code properties}
	 */
	public void setProperties(Boolean properties) {
		this.properties = properties;
	}

	/**
	 * Set the optional "properties" argument.
	 * <p>
	 * Write a properties document to IMAGEDESCRIPTION
	 * @param properties the new value of {@code properties}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions properties(Boolean properties) {
		setProperties(properties);
		return this;
	}

	/**
	 * Optional argument: region-shrink
	 * <p>
	 * Method to shrink regions
	 * @return the value of {@code regionShrink}
	 */
	public VipsRegionShrink getRegionShrink() {
		return this.regionShrink;
	}

	/**
	 * Set the optional "region-shrink" argument.
	 * <p>
	 * Method to shrink regions
	 * @param regionShrink the new value of {@code regionShrink}
	 */
	public void setRegionShrink(VipsRegionShrink regionShrink) {
		this.regionShrink = regionShrink;
	}

	/**
	 * Set the optional "region-shrink" argument.
	 * <p>
	 * Method to shrink regions
	 * @param regionShrink the new value of {@code regionShrink}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions regionShrink(VipsRegionShrink regionShrink) {
		setRegionShrink(regionShrink);
		return this;
	}

	/**
	 * Optional argument: level
	 * <p>
	 * ZSTD compression level
	 * @return the value of {@code level}
	 */
	public Integer getLevel() {
		return this.level;
	}

	/**
	 * Set the optional "level" argument.
	 * <p>
	 * ZSTD compression level
	 * @param level the new value of {@code level}
	 */
	public void setLevel(Integer level) {
		this.level = level;
	}

	/**
	 * Set the optional "level" argument.
	 * <p>
	 * ZSTD compression level
	 * @param level the new value of {@code level}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions level(Integer level) {
		setLevel(level);
		return this;
	}

	/**
	 * Optional argument: lossless
	 * <p>
	 * Enable WEBP lossless mode
	 * @return the value of {@code lossless}
	 */
	public Boolean getLossless() {
		return this.lossless;
	}

	/**
	 * Set the optional "lossless" argument.
	 * <p>
	 * Enable WEBP lossless mode
	 * @param lossless the new value of {@code lossless}
	 */
	public void setLossless(Boolean lossless) {
		this.lossless = lossless;
	}

	/**
	 * Set the optional "lossless" argument.
	 * <p>
	 * Enable WEBP lossless mode
	 * @param lossless the new value of {@code lossless}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions lossless(Boolean lossless) {
		setLossless(lossless);
		return this;
	}

	/**
	 * Optional argument: depth
	 * <p>
	 * Pyramid depth
	 * @return the value of {@code depth}
	 */
	public VipsForeignDzDepth getDepth() {
		return this.depth;
	}

	/**
	 * Set the optional "depth" argument.
	 * <p>
	 * Pyramid depth
	 * @param depth the new value of {@code depth}
	 */
	public void setDepth(VipsForeignDzDepth depth) {
		this.depth = depth;
	}

	/**
	 * Set the optional "depth" argument.
	 * <p>
	 * Pyramid depth
	 * @param depth the new value of {@code depth}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions depth(VipsForeignDzDepth depth) {
		setDepth(depth);
		return this;
	}

	/**
	 * Optional argument: subifd
	 * <p>
	 * Save pyr layers as sub-IFDs
	 * @return the value of {@code subifd}
	 */
	public Boolean getSubifd() {
		return this.subifd;
	}

	/**
	 * Set the optional "subifd" argument.
	 * <p>
	 * Save pyr layers as sub-IFDs
	 * @param subifd the new value of {@code subifd}
	 */
	public void setSubifd(Boolean subifd) {
		this.subifd = subifd;
	}

	/**
	 * Set the optional "subifd" argument.
	 * <p>
	 * Save pyr layers as sub-IFDs
	 * @param subifd the new value of {@code subifd}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions subifd(Boolean subifd) {
		setSubifd(subifd);
		return this;
	}

	/**
	 * Optional argument: premultiply
	 * <p>
	 * Save with premultiplied alpha
	 * @return the value of {@code premultiply}
	 */
	public Boolean getPremultiply() {
		return this.premultiply;
	}

	/**
	 * Set the optional "premultiply" argument.
	 * <p>
	 * Save with premultiplied alpha
	 * @param premultiply the new value of {@code premultiply}
	 */
	public void setPremultiply(Boolean premultiply) {
		this.premultiply = premultiply;
	}

	/**
	 * Set the optional "premultiply" argument.
	 * <p>
	 * Save with premultiplied alpha
	 * @param premultiply the new value of {@code premultiply}
	 * @return this object for chaining
	 */
	public TIFFSaveOptions premultiply(Boolean premultiply) {
		setPremultiply(premultiply);
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
	public TIFFSaveOptions strip(Boolean strip) {
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
	public TIFFSaveOptions background(PixelPacket background) {
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
	public TIFFSaveOptions pageHeight(Integer pageHeight) {
		setPageHeight(pageHeight);
		return this;
	}

}
