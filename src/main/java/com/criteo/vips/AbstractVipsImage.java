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

package com.criteo.vips;

import java.awt.Rectangle;

import javax.annotation.Generated;

@Generated(value = "")
abstract class AbstractVipsImage extends Vips {

	// Per instance memory pointer used by the C code to retrieve the image data (Don't remove!)
	protected long vipsImageHandler = 0;

	// VipsImage is created with vips_image_new_from_buffer, we are responsible to free allocated buffer.
	// We don't want to pass pointer to jbytearray because it will be never garbage collected (Don't remove!)
	// TODO: Try to create a global ref to jbytearray and delete the ref in release()
	protected long bufferHandler = 0;

	static {
		initFieldIDs();
	}

	private static native void initFieldIDs();

	/**
	 * VipsAbs (abs): absolute value of an image
	 * Mutates the image inplace.
	 */
	public native void applyAbs() throws VipsException;
	
	
	/**
	 * VipsAbs (abs): absolute value of an image
	 * Returns a new image.
	 */
	public native VipsImage abs() throws VipsException;
	
	/**
	 * VipsAdd (add): add two images
	 * Mutates the image inplace.
	 * @param right Right-hand image argument
	 */
	public native void applyAdd(com.criteo.vips.Image right) throws VipsException;
	
	
	/**
	 * VipsAdd (add): add two images
	 * Returns a new image.
	 * @param right Right-hand image argument
	 */
	public native VipsImage add(com.criteo.vips.Image right) throws VipsException;
	
	/**
	 * VipsForeignLoadAnalyze (analyzeload): load an Analyze6 image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage analyzeLoad(String filename, com.criteo.vips.options.AnalyzeLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadAnalyze (analyzeload): load an Analyze6 image
	 * @param filename Filename to load from
	 */
	public static VipsImage analyzeLoad(String filename) throws VipsException {
		return analyzeLoad(filename, null);
	}
	
	/**
	 * VipsArrayjoin (arrayjoin): join an array of images
	 * @param in Array of input images
	 * @param options optional arguments
	 */
	public static native VipsImage arrayjoin(com.criteo.vips.Image[] in, com.criteo.vips.options.ArrayjoinOptions options) throws VipsException;
	
	/**
	 * VipsArrayjoin (arrayjoin): join an array of images
	 * @param in Array of input images
	 */
	public static VipsImage arrayjoin(com.criteo.vips.Image[] in) throws VipsException {
		return arrayjoin(in, null);
	}
	
	/**
	 * VipsAutorot (autorot): autorotate image by exif tag
	 * Mutates the image inplace.
	 */
	public native void applyAutorot() throws VipsException;
	
	
	/**
	 * VipsAutorot (autorot): autorotate image by exif tag
	 * Returns a new image.
	 */
	public native VipsImage autorot() throws VipsException;
	
	/**
	 * VipsAvg (avg): find image average
	 */
	public native double avg() throws VipsException;
	
	/**
	 * VipsBandbool (bandbool): boolean operation across image bands
	 * Mutates the image inplace.
	 * @param booleanParam Boolean to perform
	 */
	public native void applyBandbool(com.criteo.vips.enums.VipsOperationBoolean booleanParam) throws VipsException;
	
	
	/**
	 * VipsBandbool (bandbool): boolean operation across image bands
	 * Returns a new image.
	 * @param booleanParam Boolean to perform
	 */
	public native VipsImage bandbool(com.criteo.vips.enums.VipsOperationBoolean booleanParam) throws VipsException;
	
	/**
	 * VipsBandfold (bandfold): fold up x axis into bands
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyBandfold(com.criteo.vips.options.BandfoldOptions options) throws VipsException;
	
	/**
	 * VipsBandfold (bandfold): fold up x axis into bands
	 * Mutates the image inplace.
	 */
	public void applyBandfold() throws VipsException {
		applyBandfold(null);
	}
	
	
	/**
	 * VipsBandfold (bandfold): fold up x axis into bands
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage bandfold(com.criteo.vips.options.BandfoldOptions options) throws VipsException;
	
	/**
	 * VipsBandfold (bandfold): fold up x axis into bands
	 * Returns a new image.
	 */
	public VipsImage bandfold() throws VipsException {
		return bandfold(null);
	}
	
	/**
	 * VipsBandjoin (bandjoin): bandwise join a set of images
	 * @param in Array of input images
	 */
	public static native VipsImage bandjoin(com.criteo.vips.Image[] in) throws VipsException;
	
	/**
	 * VipsBandjoinConst (bandjoin_const): append a constant band to an image
	 * Mutates the image inplace.
	 * @param c Array of constants to add
	 */
	public native void applyBandjoinConst(double[] c) throws VipsException;
	
	
	/**
	 * VipsBandjoinConst (bandjoin_const): append a constant band to an image
	 * Returns a new image.
	 * @param c Array of constants to add
	 */
	public native VipsImage bandjoinConst(double[] c) throws VipsException;
	
	/**
	 * VipsBandmean (bandmean): band-wise average
	 * Mutates the image inplace.
	 */
	public native void applyBandmean() throws VipsException;
	
	
	/**
	 * VipsBandmean (bandmean): band-wise average
	 * Returns a new image.
	 */
	public native VipsImage bandmean() throws VipsException;
	
	/**
	 * VipsBandrank (bandrank): band-wise rank of a set of images
	 * @param in Array of input images
	 * @param options optional arguments
	 */
	public static native VipsImage bandrank(com.criteo.vips.Image[] in, com.criteo.vips.options.BandrankOptions options) throws VipsException;
	
	/**
	 * VipsBandrank (bandrank): band-wise rank of a set of images
	 * @param in Array of input images
	 */
	public static VipsImage bandrank(com.criteo.vips.Image[] in) throws VipsException {
		return bandrank(in, null);
	}
	
	/**
	 * VipsBandunfold (bandunfold): unfold image bands into x axis
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyBandunfold(com.criteo.vips.options.BandunfoldOptions options) throws VipsException;
	
	/**
	 * VipsBandunfold (bandunfold): unfold image bands into x axis
	 * Mutates the image inplace.
	 */
	public void applyBandunfold() throws VipsException {
		applyBandunfold(null);
	}
	
	
	/**
	 * VipsBandunfold (bandunfold): unfold image bands into x axis
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage bandunfold(com.criteo.vips.options.BandunfoldOptions options) throws VipsException;
	
	/**
	 * VipsBandunfold (bandunfold): unfold image bands into x axis
	 * Returns a new image.
	 */
	public VipsImage bandunfold() throws VipsException {
		return bandunfold(null);
	}
	
	/**
	 * VipsBlack (black): make a black image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage black(int width, int height, com.criteo.vips.options.BlackOptions options) throws VipsException;
	
	/**
	 * VipsBlack (black): make a black image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage black(int width, int height) throws VipsException {
		return black(width, height, null);
	}
	
	/**
	 * VipsBoolean (boolean): boolean operation on two images
	 * Mutates the image inplace.
	 * @param right Right-hand image argument
	 * @param booleanParam Boolean to perform
	 */
	public native void applyBoolean(com.criteo.vips.Image right, com.criteo.vips.enums.VipsOperationBoolean booleanParam) throws VipsException;
	
	
	/**
	 * VipsBoolean (boolean): boolean operation on two images
	 * Returns a new image.
	 * @param right Right-hand image argument
	 * @param booleanParam Boolean to perform
	 */
	public native VipsImage booleanOp(com.criteo.vips.Image right, com.criteo.vips.enums.VipsOperationBoolean booleanParam) throws VipsException;
	
	/**
	 * VipsBooleanConst (boolean_const): boolean operations against a constant
	 * Mutates the image inplace.
	 * @param booleanParam Boolean to perform
	 * @param c Array of constants
	 */
	public native void applyBooleanConst(com.criteo.vips.enums.VipsOperationBoolean booleanParam, double[] c) throws VipsException;
	
	
	/**
	 * VipsBooleanConst (boolean_const): boolean operations against a constant
	 * Returns a new image.
	 * @param booleanParam Boolean to perform
	 * @param c Array of constants
	 */
	public native VipsImage booleanConst(com.criteo.vips.enums.VipsOperationBoolean booleanParam, double[] c) throws VipsException;
	
	/**
	 * VipsBuildlut (buildlut): build a look-up table
	 * Mutates the image inplace.
	 */
	public native void applyBuildlut() throws VipsException;
	
	
	/**
	 * VipsBuildlut (buildlut): build a look-up table
	 * Returns a new image.
	 */
	public native VipsImage buildlut() throws VipsException;
	
	/**
	 * VipsByteswap (byteswap): byteswap an image
	 * Mutates the image inplace.
	 */
	public native void applyByteswap() throws VipsException;
	
	
	/**
	 * VipsByteswap (byteswap): byteswap an image
	 * Returns a new image.
	 */
	public native VipsImage byteswap() throws VipsException;
	
	/**
	 * VipsCache (cache): cache an image
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyCache(com.criteo.vips.options.CacheOptions options) throws VipsException;
	
	/**
	 * VipsCache (cache): cache an image
	 * Mutates the image inplace.
	 */
	public void applyCache() throws VipsException {
		applyCache(null);
	}
	
	
	/**
	 * VipsCache (cache): cache an image
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage cache(com.criteo.vips.options.CacheOptions options) throws VipsException;
	
	/**
	 * VipsCache (cache): cache an image
	 * Returns a new image.
	 */
	public VipsImage cache() throws VipsException {
		return cache(null);
	}
	
	/**
	 * VipsCanny (canny): Canny edge detector
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyCanny(com.criteo.vips.options.CannyOptions options) throws VipsException;
	
	/**
	 * VipsCanny (canny): Canny edge detector
	 * Mutates the image inplace.
	 */
	public void applyCanny() throws VipsException {
		applyCanny(null);
	}
	
	
	/**
	 * VipsCanny (canny): Canny edge detector
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage canny(com.criteo.vips.options.CannyOptions options) throws VipsException;
	
	/**
	 * VipsCanny (canny): Canny edge detector
	 * Returns a new image.
	 */
	public VipsImage canny() throws VipsException {
		return canny(null);
	}
	
	/**
	 * VipsCase (case): use pixel values to pick cases from an array of images
	 * Mutates the image inplace.
	 * @param cases Array of case images
	 */
	public native void applyCase(com.criteo.vips.Image[] cases) throws VipsException;
	
	
	/**
	 * VipsCase (case): use pixel values to pick cases from an array of images
	 * Returns a new image.
	 * @param cases Array of case images
	 */
	public native VipsImage caseOp(com.criteo.vips.Image[] cases) throws VipsException;
	
	/**
	 * VipsCast (cast): cast an image
	 * Mutates the image inplace.
	 * @param format Format to cast to
	 * @param options optional arguments
	 */
	public native void applyCast(com.criteo.vips.enums.VipsBandFormat format, com.criteo.vips.options.CastOptions options) throws VipsException;
	
	/**
	 * VipsCast (cast): cast an image
	 * Mutates the image inplace.
	 * @param format Format to cast to
	 */
	public void applyCast(com.criteo.vips.enums.VipsBandFormat format) throws VipsException {
		applyCast(format, null);
	}
	
	
	/**
	 * VipsCast (cast): cast an image
	 * Returns a new image.
	 * @param format Format to cast to
	 * @param options optional arguments
	 */
	public native VipsImage cast(com.criteo.vips.enums.VipsBandFormat format, com.criteo.vips.options.CastOptions options) throws VipsException;
	
	/**
	 * VipsCast (cast): cast an image
	 * Returns a new image.
	 * @param format Format to cast to
	 */
	public VipsImage cast(com.criteo.vips.enums.VipsBandFormat format) throws VipsException {
		return cast(format, null);
	}
	
	/**
	 * VipsCMC2LCh (CMC2LCh): transform LCh to CMC
	 * Mutates the image inplace.
	 */
	public native void applyCMC2LCh() throws VipsException;
	
	
	/**
	 * VipsCMC2LCh (CMC2LCh): transform LCh to CMC
	 * Returns a new image.
	 */
	public native VipsImage cMC2LCh() throws VipsException;
	
	/**
	 * VipsCMYK2XYZ (CMYK2XYZ): transform CMYK to XYZ
	 * Mutates the image inplace.
	 */
	public native void applyCMYK2XYZ() throws VipsException;
	
	
	/**
	 * VipsCMYK2XYZ (CMYK2XYZ): transform CMYK to XYZ
	 * Returns a new image.
	 */
	public native VipsImage cmyk2xyz() throws VipsException;
	
	/**
	 * VipsColourspace (colourspace): convert to a new colorspace
	 * Mutates the image inplace.
	 * @param space Destination color space
	 * @param options optional arguments
	 */
	public native void applyColourspace(com.criteo.vips.enums.VipsInterpretation space, com.criteo.vips.options.ColourspaceOptions options) throws VipsException;
	
	/**
	 * VipsColourspace (colourspace): convert to a new colorspace
	 * Mutates the image inplace.
	 * @param space Destination color space
	 */
	public void applyColourspace(com.criteo.vips.enums.VipsInterpretation space) throws VipsException {
		applyColourspace(space, null);
	}
	
	
	/**
	 * VipsColourspace (colourspace): convert to a new colorspace
	 * Returns a new image.
	 * @param space Destination color space
	 * @param options optional arguments
	 */
	public native VipsImage colourspace(com.criteo.vips.enums.VipsInterpretation space, com.criteo.vips.options.ColourspaceOptions options) throws VipsException;
	
	/**
	 * VipsColourspace (colourspace): convert to a new colorspace
	 * Returns a new image.
	 * @param space Destination color space
	 */
	public VipsImage colourspace(com.criteo.vips.enums.VipsInterpretation space) throws VipsException {
		return colourspace(space, null);
	}
	
	/**
	 * VipsCompass (compass): convolve with rotating mask
	 * Mutates the image inplace.
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void applyCompass(com.criteo.vips.Image mask, com.criteo.vips.options.CompassOptions options) throws VipsException;
	
	/**
	 * VipsCompass (compass): convolve with rotating mask
	 * Mutates the image inplace.
	 * @param mask Input matrix image
	 */
	public void applyCompass(com.criteo.vips.Image mask) throws VipsException {
		applyCompass(mask, null);
	}
	
	
	/**
	 * VipsCompass (compass): convolve with rotating mask
	 * Returns a new image.
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native VipsImage compass(com.criteo.vips.Image mask, com.criteo.vips.options.CompassOptions options) throws VipsException;
	
	/**
	 * VipsCompass (compass): convolve with rotating mask
	 * Returns a new image.
	 * @param mask Input matrix image
	 */
	public VipsImage compass(com.criteo.vips.Image mask) throws VipsException {
		return compass(mask, null);
	}
	
	/**
	 * VipsComplex (complex): perform a complex operation on an image
	 * Mutates the image inplace.
	 * @param cmplx Complex to perform
	 */
	public native void applyComplex(com.criteo.vips.enums.VipsOperationComplex cmplx) throws VipsException;
	
	
	/**
	 * VipsComplex (complex): perform a complex operation on an image
	 * Returns a new image.
	 * @param cmplx Complex to perform
	 */
	public native VipsImage complex(com.criteo.vips.enums.VipsOperationComplex cmplx) throws VipsException;
	
	/**
	 * VipsComplex2 (complex2): complex binary operations on two images
	 * Mutates the image inplace.
	 * @param right Right-hand image argument
	 * @param cmplx Binary complex operation to perform
	 */
	public native void applyComplex2(com.criteo.vips.Image right, com.criteo.vips.enums.VipsOperationComplex2 cmplx) throws VipsException;
	
	
	/**
	 * VipsComplex2 (complex2): complex binary operations on two images
	 * Returns a new image.
	 * @param right Right-hand image argument
	 * @param cmplx Binary complex operation to perform
	 */
	public native VipsImage complex2(com.criteo.vips.Image right, com.criteo.vips.enums.VipsOperationComplex2 cmplx) throws VipsException;
	
	/**
	 * VipsComplexform (complexform): form a complex image from two real images
	 * Mutates the image inplace.
	 * @param right Right-hand image argument
	 */
	public native void applyComplexform(com.criteo.vips.Image right) throws VipsException;
	
	
	/**
	 * VipsComplexform (complexform): form a complex image from two real images
	 * Returns a new image.
	 * @param right Right-hand image argument
	 */
	public native VipsImage complexform(com.criteo.vips.Image right) throws VipsException;
	
	/**
	 * VipsComplexget (complexget): get a component from a complex image
	 * Mutates the image inplace.
	 * @param get Complex to perform
	 */
	public native void applyComplexget(com.criteo.vips.enums.VipsOperationComplexget get) throws VipsException;
	
	
	/**
	 * VipsComplexget (complexget): get a component from a complex image
	 * Returns a new image.
	 * @param get Complex to perform
	 */
	public native VipsImage complexget(com.criteo.vips.enums.VipsOperationComplexget get) throws VipsException;
	
	/**
	 * VipsComposite (composite): blend an array of images with an array of blend modes
	 * @param in Array of input images
	 * @param mode Array of VipsBlendMode to join with
	 * @param options optional arguments
	 */
	public static native VipsImage composite(com.criteo.vips.Image[] in, int[] mode, com.criteo.vips.options.CompositeOptions options) throws VipsException;
	
	/**
	 * VipsComposite (composite): blend an array of images with an array of blend modes
	 * @param in Array of input images
	 * @param mode Array of VipsBlendMode to join with
	 */
	public static VipsImage composite(com.criteo.vips.Image[] in, int[] mode) throws VipsException {
		return composite(in, mode, null);
	}
	
	/**
	 * VipsComposite2 (composite2): blend a pair of images with a blend mode
	 * Mutates the image inplace.
	 * @param overlay Overlay image
	 * @param mode VipsBlendMode to join with
	 * @param options optional arguments
	 */
	public native void applyComposite2(com.criteo.vips.Image overlay, com.criteo.vips.enums.VipsBlendMode mode, com.criteo.vips.options.Composite2Options options) throws VipsException;
	
	/**
	 * VipsComposite2 (composite2): blend a pair of images with a blend mode
	 * Mutates the image inplace.
	 * @param overlay Overlay image
	 * @param mode VipsBlendMode to join with
	 */
	public void applyComposite2(com.criteo.vips.Image overlay, com.criteo.vips.enums.VipsBlendMode mode) throws VipsException {
		applyComposite2(overlay, mode, null);
	}
	
	
	/**
	 * VipsComposite2 (composite2): blend a pair of images with a blend mode
	 * Returns a new image.
	 * @param overlay Overlay image
	 * @param mode VipsBlendMode to join with
	 * @param options optional arguments
	 */
	public native VipsImage composite2(com.criteo.vips.Image overlay, com.criteo.vips.enums.VipsBlendMode mode, com.criteo.vips.options.Composite2Options options) throws VipsException;
	
	/**
	 * VipsComposite2 (composite2): blend a pair of images with a blend mode
	 * Returns a new image.
	 * @param overlay Overlay image
	 * @param mode VipsBlendMode to join with
	 */
	public VipsImage composite2(com.criteo.vips.Image overlay, com.criteo.vips.enums.VipsBlendMode mode) throws VipsException {
		return composite2(overlay, mode, null);
	}
	
	/**
	 * VipsConv (conv): convolution operation
	 * Mutates the image inplace.
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void applyConv(com.criteo.vips.Image mask, com.criteo.vips.options.ConvOptions options) throws VipsException;
	
	/**
	 * VipsConv (conv): convolution operation
	 * Mutates the image inplace.
	 * @param mask Input matrix image
	 */
	public void applyConv(com.criteo.vips.Image mask) throws VipsException {
		applyConv(mask, null);
	}
	
	
	/**
	 * VipsConv (conv): convolution operation
	 * Returns a new image.
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native VipsImage conv(com.criteo.vips.Image mask, com.criteo.vips.options.ConvOptions options) throws VipsException;
	
	/**
	 * VipsConv (conv): convolution operation
	 * Returns a new image.
	 * @param mask Input matrix image
	 */
	public VipsImage conv(com.criteo.vips.Image mask) throws VipsException {
		return conv(mask, null);
	}
	
	/**
	 * VipsConva (conva): approximate integer convolution
	 * Mutates the image inplace.
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void applyConva(com.criteo.vips.Image mask, com.criteo.vips.options.ConvaOptions options) throws VipsException;
	
	/**
	 * VipsConva (conva): approximate integer convolution
	 * Mutates the image inplace.
	 * @param mask Input matrix image
	 */
	public void applyConva(com.criteo.vips.Image mask) throws VipsException {
		applyConva(mask, null);
	}
	
	
	/**
	 * VipsConva (conva): approximate integer convolution
	 * Returns a new image.
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native VipsImage conva(com.criteo.vips.Image mask, com.criteo.vips.options.ConvaOptions options) throws VipsException;
	
	/**
	 * VipsConva (conva): approximate integer convolution
	 * Returns a new image.
	 * @param mask Input matrix image
	 */
	public VipsImage conva(com.criteo.vips.Image mask) throws VipsException {
		return conva(mask, null);
	}
	
	/**
	 * VipsConvasep (convasep): approximate separable integer convolution
	 * Mutates the image inplace.
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void applyConvasep(com.criteo.vips.Image mask, com.criteo.vips.options.ConvasepOptions options) throws VipsException;
	
	/**
	 * VipsConvasep (convasep): approximate separable integer convolution
	 * Mutates the image inplace.
	 * @param mask Input matrix image
	 */
	public void applyConvasep(com.criteo.vips.Image mask) throws VipsException {
		applyConvasep(mask, null);
	}
	
	
	/**
	 * VipsConvasep (convasep): approximate separable integer convolution
	 * Returns a new image.
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native VipsImage convasep(com.criteo.vips.Image mask, com.criteo.vips.options.ConvasepOptions options) throws VipsException;
	
	/**
	 * VipsConvasep (convasep): approximate separable integer convolution
	 * Returns a new image.
	 * @param mask Input matrix image
	 */
	public VipsImage convasep(com.criteo.vips.Image mask) throws VipsException {
		return convasep(mask, null);
	}
	
	/**
	 * VipsConvf (convf): float convolution operation
	 * Mutates the image inplace.
	 * @param mask Input matrix image
	 */
	public native void applyConvf(com.criteo.vips.Image mask) throws VipsException;
	
	
	/**
	 * VipsConvf (convf): float convolution operation
	 * Returns a new image.
	 * @param mask Input matrix image
	 */
	public native VipsImage convf(com.criteo.vips.Image mask) throws VipsException;
	
	/**
	 * VipsConvi (convi): int convolution operation
	 * Mutates the image inplace.
	 * @param mask Input matrix image
	 */
	public native void applyConvi(com.criteo.vips.Image mask) throws VipsException;
	
	
	/**
	 * VipsConvi (convi): int convolution operation
	 * Returns a new image.
	 * @param mask Input matrix image
	 */
	public native VipsImage convi(com.criteo.vips.Image mask) throws VipsException;
	
	/**
	 * VipsConvsep (convsep): seperable convolution operation
	 * Mutates the image inplace.
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void applyConvsep(com.criteo.vips.Image mask, com.criteo.vips.options.ConvsepOptions options) throws VipsException;
	
	/**
	 * VipsConvsep (convsep): seperable convolution operation
	 * Mutates the image inplace.
	 * @param mask Input matrix image
	 */
	public void applyConvsep(com.criteo.vips.Image mask) throws VipsException {
		applyConvsep(mask, null);
	}
	
	
	/**
	 * VipsConvsep (convsep): seperable convolution operation
	 * Returns a new image.
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native VipsImage convsep(com.criteo.vips.Image mask, com.criteo.vips.options.ConvsepOptions options) throws VipsException;
	
	/**
	 * VipsConvsep (convsep): seperable convolution operation
	 * Returns a new image.
	 * @param mask Input matrix image
	 */
	public VipsImage convsep(com.criteo.vips.Image mask) throws VipsException {
		return convsep(mask, null);
	}
	
	/**
	 * VipsCopy (copy): copy an image
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyCopy(com.criteo.vips.options.CopyOptions options) throws VipsException;
	
	/**
	 * VipsCopy (copy): copy an image
	 * Mutates the image inplace.
	 */
	public void applyCopy() throws VipsException {
		applyCopy(null);
	}
	
	
	/**
	 * VipsCopy (copy): copy an image
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage copy(com.criteo.vips.options.CopyOptions options) throws VipsException;
	
	/**
	 * VipsCopy (copy): copy an image
	 * Returns a new image.
	 */
	public VipsImage copy() throws VipsException {
		return copy(null);
	}
	
	/**
	 * VipsCountlines (countlines): count lines in an image
	 * @param direction Countlines left-right or up-down
	 */
	public native double countlines(com.criteo.vips.enums.VipsDirection direction) throws VipsException;
	
	/**
	 * VipsForeignLoadCsvFile (csvload): load csv
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage csvLoad(String filename, com.criteo.vips.options.CSVLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadCsvFile (csvload): load csv
	 * @param filename Filename to load from
	 */
	public static VipsImage csvLoad(String filename) throws VipsException {
		return csvLoad(filename, null);
	}
	
	/**
	 * VipsForeignSaveCsvFile (csvsave): save image to csv
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void csvSave(String filename, com.criteo.vips.options.CSVSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveCsvFile (csvsave): save image to csv
	 * @param filename Filename to save to
	 */
	public void csvSave(String filename) throws VipsException {
		csvSave(filename, null);
	}
	
	/**
	 * VipsdE00 (dE00): calculate dE00
	 * Mutates the image inplace.
	 * @param right Right-hand input image
	 */
	public native void applyDE00(com.criteo.vips.Image right) throws VipsException;
	
	
	/**
	 * VipsdE00 (dE00): calculate dE00
	 * Returns a new image.
	 * @param right Right-hand input image
	 */
	public native VipsImage dE00(com.criteo.vips.Image right) throws VipsException;
	
	/**
	 * VipsdE76 (dE76): calculate dE76
	 * Mutates the image inplace.
	 * @param right Right-hand input image
	 */
	public native void applyDE76(com.criteo.vips.Image right) throws VipsException;
	
	
	/**
	 * VipsdE76 (dE76): calculate dE76
	 * Returns a new image.
	 * @param right Right-hand input image
	 */
	public native VipsImage dE76(com.criteo.vips.Image right) throws VipsException;
	
	/**
	 * VipsdECMC (dECMC): calculate dECMC
	 * Mutates the image inplace.
	 * @param right Right-hand input image
	 */
	public native void applyDECMC(com.criteo.vips.Image right) throws VipsException;
	
	
	/**
	 * VipsdECMC (dECMC): calculate dECMC
	 * Returns a new image.
	 * @param right Right-hand input image
	 */
	public native VipsImage dECMC(com.criteo.vips.Image right) throws VipsException;
	
	/**
	 * VipsDeviate (deviate): find image standard deviation
	 */
	public native double deviate() throws VipsException;
	
	/**
	 * VipsDivide (divide): divide two images
	 * Mutates the image inplace.
	 * @param right Right-hand image argument
	 */
	public native void applyDivide(com.criteo.vips.Image right) throws VipsException;
	
	
	/**
	 * VipsDivide (divide): divide two images
	 * Returns a new image.
	 * @param right Right-hand image argument
	 */
	public native VipsImage divide(com.criteo.vips.Image right) throws VipsException;
	
	/**
	 * VipsDrawCircle (draw_circle): draw a circle on an image
	 * @param ink Color for pixels
	 * @param cx Centre of draw_circle
	 * @param cy Centre of draw_circle
	 * @param radius Radius in pixels
	 * @param options optional arguments
	 */
	public native void drawCircle(double[] ink, int cx, int cy, int radius, com.criteo.vips.options.DrawCircleOptions options) throws VipsException;
	
	/**
	 * VipsDrawCircle (draw_circle): draw a circle on an image
	 * @param ink Color for pixels
	 * @param cx Centre of draw_circle
	 * @param cy Centre of draw_circle
	 * @param radius Radius in pixels
	 */
	public void drawCircle(double[] ink, int cx, int cy, int radius) throws VipsException {
		drawCircle(ink, cx, cy, radius, null);
	}
	
	/**
	 * VipsDrawFlood (draw_flood): flood-fill an area
	 * @param ink Color for pixels
	 * @param x DrawFlood start point
	 * @param y DrawFlood start point
	 * @param options optional arguments
	 */
	public native void drawFlood(double[] ink, int x, int y, com.criteo.vips.options.DrawFloodOptions options) throws VipsException;
	
	/**
	 * VipsDrawFlood (draw_flood): flood-fill an area
	 * @param ink Color for pixels
	 * @param x DrawFlood start point
	 * @param y DrawFlood start point
	 */
	public void drawFlood(double[] ink, int x, int y) throws VipsException {
		drawFlood(ink, x, y, null);
	}
	
	/**
	 * VipsDrawImage (draw_image): paint an image into another image
	 * @param sub Sub-image to insert into main image
	 * @param x Draw image here
	 * @param y Draw image here
	 * @param options optional arguments
	 */
	public native void drawImage(com.criteo.vips.Image sub, int x, int y, com.criteo.vips.options.DrawImageOptions options) throws VipsException;
	
	/**
	 * VipsDrawImage (draw_image): paint an image into another image
	 * @param sub Sub-image to insert into main image
	 * @param x Draw image here
	 * @param y Draw image here
	 */
	public void drawImage(com.criteo.vips.Image sub, int x, int y) throws VipsException {
		drawImage(sub, x, y, null);
	}
	
	/**
	 * VipsDrawLine (draw_line): draw a line on an image
	 * @param ink Color for pixels
	 * @param x1 Start of draw_line
	 * @param y1 Start of draw_line
	 * @param x2 End of draw_line
	 * @param y2 End of draw_line
	 */
	public native void drawLine(double[] ink, int x1, int y1, int x2, int y2) throws VipsException;
	
	/**
	 * VipsDrawMask (draw_mask): draw a mask on an image
	 * @param ink Color for pixels
	 * @param mask Mask of pixels to draw
	 * @param x Draw mask here
	 * @param y Draw mask here
	 */
	public native void drawMask(double[] ink, com.criteo.vips.Image mask, int x, int y) throws VipsException;
	
	/**
	 * VipsDrawRect (draw_rect): paint a rectangle on an image
	 * @param ink Color for pixels
	 * @param left Rect to fill
	 * @param top Rect to fill
	 * @param width Rect to fill
	 * @param height Rect to fill
	 * @param options optional arguments
	 */
	public native void drawRect(double[] ink, int left, int top, int width, int height, com.criteo.vips.options.DrawRectOptions options) throws VipsException;
	
	/**
	 * VipsDrawRect (draw_rect): paint a rectangle on an image
	 * @param ink Color for pixels
	 * @param left Rect to fill
	 * @param top Rect to fill
	 * @param width Rect to fill
	 * @param height Rect to fill
	 */
	public void drawRect(double[] ink, int left, int top, int width, int height) throws VipsException {
		drawRect(ink, left, top, width, height, null);
	}
	
	/**
	 * VipsDrawSmudge (draw_smudge): blur a rectangle on an image
	 * @param left Rect to fill
	 * @param top Rect to fill
	 * @param width Rect to fill
	 * @param height Rect to fill
	 */
	public native void drawSmudge(int left, int top, int width, int height) throws VipsException;
	
	/**
	 * VipsForeignSaveDzFile (dzsave): save image to deepzoom file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void dzSave(String filename, com.criteo.vips.options.DZSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveDzFile (dzsave): save image to deepzoom file
	 * @param filename Filename to save to
	 */
	public void dzSave(String filename) throws VipsException {
		dzSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveDzBuffer (dzsave_buffer): save image to dz buffer
	 * @param options optional arguments
	 */
	public native byte[] dzSaveBuffer(com.criteo.vips.options.DZSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveDzBuffer (dzsave_buffer): save image to dz buffer
	 */
	public byte[] dzSaveBuffer() throws VipsException {
		return dzSaveBuffer(null);
	}
	
	/**
	 * VipsEmbed (embed): embed an image in a larger image
	 * Mutates the image inplace.
	 * @param x Left edge of input in output
	 * @param y Top edge of input in output
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public native void applyEmbed(int x, int y, int width, int height, com.criteo.vips.options.EmbedOptions options) throws VipsException;
	
	/**
	 * VipsEmbed (embed): embed an image in a larger image
	 * Mutates the image inplace.
	 * @param x Left edge of input in output
	 * @param y Top edge of input in output
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public void applyEmbed(int x, int y, int width, int height) throws VipsException {
		applyEmbed(x, y, width, height, null);
	}
	
	
	/**
	 * VipsEmbed (embed): embed an image in a larger image
	 * Returns a new image.
	 * @param x Left edge of input in output
	 * @param y Top edge of input in output
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public native VipsImage embed(int x, int y, int width, int height, com.criteo.vips.options.EmbedOptions options) throws VipsException;
	
	/**
	 * VipsEmbed (embed): embed an image in a larger image
	 * Returns a new image.
	 * @param x Left edge of input in output
	 * @param y Top edge of input in output
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public VipsImage embed(int x, int y, int width, int height) throws VipsException {
		return embed(x, y, width, height, null);
	}
	
	/**
	 * VipsExtractArea (extract_area): extract an area from an image
	 * Mutates the image inplace.
	 * @param left Left edge of extract area
	 * @param top Top edge of extract area
	 * @param width Width of extract area
	 * @param height Height of extract area
	 */
	public native void applyExtractArea(int left, int top, int width, int height) throws VipsException;
	
	
	/**
	 * VipsExtractArea (extract_area): extract an area from an image
	 * Returns a new image.
	 * @param left Left edge of extract area
	 * @param top Top edge of extract area
	 * @param width Width of extract area
	 * @param height Height of extract area
	 */
	public native VipsImage extractArea(int left, int top, int width, int height) throws VipsException;
	
	/**
	 * VipsExtractBand (extract_band): extract band from an image
	 * Mutates the image inplace.
	 * @param band Band to extract
	 * @param options optional arguments
	 */
	public native void applyExtractBand(int band, com.criteo.vips.options.ExtractBandOptions options) throws VipsException;
	
	/**
	 * VipsExtractBand (extract_band): extract band from an image
	 * Mutates the image inplace.
	 * @param band Band to extract
	 */
	public void applyExtractBand(int band) throws VipsException {
		applyExtractBand(band, null);
	}
	
	
	/**
	 * VipsExtractBand (extract_band): extract band from an image
	 * Returns a new image.
	 * @param band Band to extract
	 * @param options optional arguments
	 */
	public native VipsImage extractBand(int band, com.criteo.vips.options.ExtractBandOptions options) throws VipsException;
	
	/**
	 * VipsExtractBand (extract_band): extract band from an image
	 * Returns a new image.
	 * @param band Band to extract
	 */
	public VipsImage extractBand(int band) throws VipsException {
		return extractBand(band, null);
	}
	
	/**
	 * VipsEye (eye): make an image showing the eye's spatial response
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage eye(int width, int height, com.criteo.vips.options.EyeOptions options) throws VipsException;
	
	/**
	 * VipsEye (eye): make an image showing the eye's spatial response
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage eye(int width, int height) throws VipsException {
		return eye(width, height, null);
	}
	
	/**
	 * VipsFalsecolour (falsecolour): false-color an image
	 * Mutates the image inplace.
	 */
	public native void applyFalsecolour() throws VipsException;
	
	
	/**
	 * VipsFalsecolour (falsecolour): false-color an image
	 * Returns a new image.
	 */
	public native VipsImage falsecolour() throws VipsException;
	
	/**
	 * VipsFastcor (fastcor): fast correlation
	 * Mutates the image inplace.
	 * @param ref Input reference image
	 */
	public native void applyFastcor(com.criteo.vips.Image ref) throws VipsException;
	
	
	/**
	 * VipsFastcor (fastcor): fast correlation
	 * Returns a new image.
	 * @param ref Input reference image
	 */
	public native VipsImage fastcor(com.criteo.vips.Image ref) throws VipsException;
	
	/**
	 * VipsFillNearest (fill_nearest): fill image zeros with nearest non-zero pixel
	 * Mutates the image inplace.
	 */
	public native void applyFillNearest() throws VipsException;
	
	
	/**
	 * VipsFillNearest (fill_nearest): fill image zeros with nearest non-zero pixel
	 * Returns a new image.
	 */
	public native VipsImage fillNearest() throws VipsException;
	
	/**
	 * VipsFindTrim (find_trim): search an image for non-edge areas
	 * @param options optional arguments
	 */
	public native Rectangle findTrim(com.criteo.vips.options.FindTrimOptions options) throws VipsException;
	
	/**
	 * VipsFindTrim (find_trim): search an image for non-edge areas
	 */
	public Rectangle findTrim() throws VipsException {
		return findTrim(null);
	}
	
	/**
	 * VipsForeignLoadFitsFile (fitsload): load a FITS image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage fitsLoad(String filename, com.criteo.vips.options.FITSLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadFitsFile (fitsload): load a FITS image
	 * @param filename Filename to load from
	 */
	public static VipsImage fitsLoad(String filename) throws VipsException {
		return fitsLoad(filename, null);
	}
	
	/**
	 * VipsForeignSaveFits (fitssave): save image to fits file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void fitsSave(String filename, com.criteo.vips.options.FITSSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveFits (fitssave): save image to fits file
	 * @param filename Filename to save to
	 */
	public void fitsSave(String filename) throws VipsException {
		fitsSave(filename, null);
	}
	
	/**
	 * VipsFlatten (flatten): flatten alpha out of an image
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyFlatten(com.criteo.vips.options.FlattenOptions options) throws VipsException;
	
	/**
	 * VipsFlatten (flatten): flatten alpha out of an image
	 * Mutates the image inplace.
	 */
	public void applyFlatten() throws VipsException {
		applyFlatten(null);
	}
	
	
	/**
	 * VipsFlatten (flatten): flatten alpha out of an image
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage flatten(com.criteo.vips.options.FlattenOptions options) throws VipsException;
	
	/**
	 * VipsFlatten (flatten): flatten alpha out of an image
	 * Returns a new image.
	 */
	public VipsImage flatten() throws VipsException {
		return flatten(null);
	}
	
	/**
	 * VipsFlip (flip): flip an image
	 * Mutates the image inplace.
	 * @param direction Direction to flip image
	 */
	public native void applyFlip(com.criteo.vips.enums.VipsDirection direction) throws VipsException;
	
	
	/**
	 * VipsFlip (flip): flip an image
	 * Returns a new image.
	 * @param direction Direction to flip image
	 */
	public native VipsImage flip(com.criteo.vips.enums.VipsDirection direction) throws VipsException;
	
	/**
	 * VipsFloat2rad (float2rad): transform float RGB to Radiance coding
	 * Mutates the image inplace.
	 */
	public native void applyFloat2rad() throws VipsException;
	
	
	/**
	 * VipsFloat2rad (float2rad): transform float RGB to Radiance coding
	 * Returns a new image.
	 */
	public native VipsImage float2rad() throws VipsException;
	
	/**
	 * VipsFractsurf (fractsurf): make a fractal surface
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param fractalDimension Fractal dimension
	 */
	public static native VipsImage fractsurf(int width, int height, double fractalDimension) throws VipsException;
	
	/**
	 * VipsFreqmult (freqmult): frequency-domain filtering
	 * Mutates the image inplace.
	 * @param mask Input mask image
	 */
	public native void applyFreqmult(com.criteo.vips.Image mask) throws VipsException;
	
	
	/**
	 * VipsFreqmult (freqmult): frequency-domain filtering
	 * Returns a new image.
	 * @param mask Input mask image
	 */
	public native VipsImage freqmult(com.criteo.vips.Image mask) throws VipsException;
	
	/**
	 * VipsFwfft (fwfft): forward FFT
	 * Mutates the image inplace.
	 */
	public native void applyFwfft() throws VipsException;
	
	
	/**
	 * VipsFwfft (fwfft): forward FFT
	 * Returns a new image.
	 */
	public native VipsImage fwfft() throws VipsException;
	
	/**
	 * VipsGamma (gamma): gamma an image
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyGamma(com.criteo.vips.options.GammaOptions options) throws VipsException;
	
	/**
	 * VipsGamma (gamma): gamma an image
	 * Mutates the image inplace.
	 */
	public void applyGamma() throws VipsException {
		applyGamma(null);
	}
	
	
	/**
	 * VipsGamma (gamma): gamma an image
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage gamma(com.criteo.vips.options.GammaOptions options) throws VipsException;
	
	/**
	 * VipsGamma (gamma): gamma an image
	 * Returns a new image.
	 */
	public VipsImage gamma() throws VipsException {
		return gamma(null);
	}
	
	/**
	 * VipsGaussblur (gaussblur): gaussian blur
	 * Mutates the image inplace.
	 * @param sigma Sigma of Gaussian
	 * @param options optional arguments
	 */
	public native void applyGaussBlur(double sigma, com.criteo.vips.options.GaussBlurOptions options) throws VipsException;
	
	/**
	 * VipsGaussblur (gaussblur): gaussian blur
	 * Mutates the image inplace.
	 * @param sigma Sigma of Gaussian
	 */
	public void applyGaussBlur(double sigma) throws VipsException {
		applyGaussBlur(sigma, null);
	}
	
	
	/**
	 * VipsGaussblur (gaussblur): gaussian blur
	 * Returns a new image.
	 * @param sigma Sigma of Gaussian
	 * @param options optional arguments
	 */
	public native VipsImage gaussBlur(double sigma, com.criteo.vips.options.GaussBlurOptions options) throws VipsException;
	
	/**
	 * VipsGaussblur (gaussblur): gaussian blur
	 * Returns a new image.
	 * @param sigma Sigma of Gaussian
	 */
	public VipsImage gaussBlur(double sigma) throws VipsException {
		return gaussBlur(sigma, null);
	}
	
	/**
	 * VipsGaussmat (gaussmat): make a gaussian image
	 * @param sigma Sigma of Gaussian
	 * @param minAmpl Minimum amplitude of Gaussian
	 * @param options optional arguments
	 */
	public static native VipsImage gaussMat(double sigma, double minAmpl, com.criteo.vips.options.GaussMatOptions options) throws VipsException;
	
	/**
	 * VipsGaussmat (gaussmat): make a gaussian image
	 * @param sigma Sigma of Gaussian
	 * @param minAmpl Minimum amplitude of Gaussian
	 */
	public static VipsImage gaussMat(double sigma, double minAmpl) throws VipsException {
		return gaussMat(sigma, minAmpl, null);
	}
	
	/**
	 * VipsGaussnoise (gaussnoise): make a gaussnoise image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage gaussNoise(int width, int height, com.criteo.vips.options.GaussNoiseOptions options) throws VipsException;
	
	/**
	 * VipsGaussnoise (gaussnoise): make a gaussnoise image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage gaussNoise(int width, int height) throws VipsException {
		return gaussNoise(width, height, null);
	}
	
	/**
	 * VipsGetpoint (getpoint): read a point from an image
	 * @param x Point to read
	 * @param y Point to read
	 */
	public native double[] getPoint(int x, int y) throws VipsException;
	
	/**
	 * VipsForeignLoadNsgifFile (gifload): load GIF with libnsgif
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage gifLoad(String filename, com.criteo.vips.options.GIFLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadNsgifFile (gifload): load GIF with libnsgif
	 * @param filename Filename to load from
	 */
	public static VipsImage gifLoad(String filename) throws VipsException {
		return gifLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadNsgifBuffer (gifload_buffer): load GIF with libnsgif
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage gifLoadBuffer(byte[] buffer, com.criteo.vips.options.GIFLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadNsgifBuffer (gifload_buffer): load GIF with libnsgif
	 * @param buffer Buffer to load from
	 */
	public static VipsImage gifLoadBuffer(byte[] buffer) throws VipsException {
		return gifLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveCgifFile (gifsave): save as gif
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void gifSave(String filename, com.criteo.vips.options.GIFSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveCgifFile (gifsave): save as gif
	 * @param filename Filename to save to
	 */
	public void gifSave(String filename) throws VipsException {
		gifSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveCgifBuffer (gifsave_buffer): save as gif
	 * @param options optional arguments
	 */
	public native byte[] gifSaveBuffer(com.criteo.vips.options.GIFSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveCgifBuffer (gifsave_buffer): save as gif
	 */
	public byte[] gifSaveBuffer() throws VipsException {
		return gifSaveBuffer(null);
	}
	
	/**
	 * VipsGlobalbalance (globalbalance): global balance an image mosaic
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyGlobalbalance(com.criteo.vips.options.GlobalbalanceOptions options) throws VipsException;
	
	/**
	 * VipsGlobalbalance (globalbalance): global balance an image mosaic
	 * Mutates the image inplace.
	 */
	public void applyGlobalbalance() throws VipsException {
		applyGlobalbalance(null);
	}
	
	
	/**
	 * VipsGlobalbalance (globalbalance): global balance an image mosaic
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage globalbalance(com.criteo.vips.options.GlobalbalanceOptions options) throws VipsException;
	
	/**
	 * VipsGlobalbalance (globalbalance): global balance an image mosaic
	 * Returns a new image.
	 */
	public VipsImage globalbalance() throws VipsException {
		return globalbalance(null);
	}
	
	/**
	 * VipsGravity (gravity): place an image within a larger image with a certain gravity
	 * Mutates the image inplace.
	 * @param direction Direction to place image within width/height
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public native void applyGravity(com.criteo.vips.enums.VipsCompassDirection direction, int width, int height, com.criteo.vips.options.GravityOptions options) throws VipsException;
	
	/**
	 * VipsGravity (gravity): place an image within a larger image with a certain gravity
	 * Mutates the image inplace.
	 * @param direction Direction to place image within width/height
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public void applyGravity(com.criteo.vips.enums.VipsCompassDirection direction, int width, int height) throws VipsException {
		applyGravity(direction, width, height, null);
	}
	
	
	/**
	 * VipsGravity (gravity): place an image within a larger image with a certain gravity
	 * Returns a new image.
	 * @param direction Direction to place image within width/height
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public native VipsImage gravity(com.criteo.vips.enums.VipsCompassDirection direction, int width, int height, com.criteo.vips.options.GravityOptions options) throws VipsException;
	
	/**
	 * VipsGravity (gravity): place an image within a larger image with a certain gravity
	 * Returns a new image.
	 * @param direction Direction to place image within width/height
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public VipsImage gravity(com.criteo.vips.enums.VipsCompassDirection direction, int width, int height) throws VipsException {
		return gravity(direction, width, height, null);
	}
	
	/**
	 * VipsGrey (grey): make a grey ramp image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage grey(int width, int height, com.criteo.vips.options.GreyOptions options) throws VipsException;
	
	/**
	 * VipsGrey (grey): make a grey ramp image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage grey(int width, int height) throws VipsException {
		return grey(width, height, null);
	}
	
	/**
	 * VipsGrid (grid): grid an image
	 * Mutates the image inplace.
	 * @param tileHeight Chop into tiles this high
	 * @param across Number of tiles across
	 * @param down Number of tiles down
	 */
	public native void applyGrid(int tileHeight, int across, int down) throws VipsException;
	
	
	/**
	 * VipsGrid (grid): grid an image
	 * Returns a new image.
	 * @param tileHeight Chop into tiles this high
	 * @param across Number of tiles across
	 * @param down Number of tiles down
	 */
	public native VipsImage grid(int tileHeight, int across, int down) throws VipsException;
	
	/**
	 * VipsForeignLoadHeifFile (heifload): load a HEIF image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage heifLoad(String filename, com.criteo.vips.options.HEIFLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadHeifFile (heifload): load a HEIF image
	 * @param filename Filename to load from
	 */
	public static VipsImage heifLoad(String filename) throws VipsException {
		return heifLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadHeifBuffer (heifload_buffer): load a HEIF image
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage heifLoadBuffer(byte[] buffer, com.criteo.vips.options.HEIFLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadHeifBuffer (heifload_buffer): load a HEIF image
	 * @param buffer Buffer to load from
	 */
	public static VipsImage heifLoadBuffer(byte[] buffer) throws VipsException {
		return heifLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveHeifFile (heifsave): save image in HEIF format
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void heifSave(String filename, com.criteo.vips.options.HEIFSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveHeifFile (heifsave): save image in HEIF format
	 * @param filename Filename to save to
	 */
	public void heifSave(String filename) throws VipsException {
		heifSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveHeifBuffer (heifsave_buffer): save image in HEIF format
	 * @param options optional arguments
	 */
	public native byte[] heifSaveBuffer(com.criteo.vips.options.HEIFSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveHeifBuffer (heifsave_buffer): save image in HEIF format
	 */
	public byte[] heifSaveBuffer() throws VipsException {
		return heifSaveBuffer(null);
	}
	
	/**
	 * VipsHistCum (hist_cum): form cumulative histogram
	 * Mutates the image inplace.
	 */
	public native void applyHistCum() throws VipsException;
	
	
	/**
	 * VipsHistCum (hist_cum): form cumulative histogram
	 * Returns a new image.
	 */
	public native VipsImage histCum() throws VipsException;
	
	/**
	 * VipsHistEntropy (hist_entropy): estimate image entropy
	 */
	public native double histEntropy() throws VipsException;
	
	/**
	 * VipsHistEqual (hist_equal): histogram equalisation
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyHistEqual(com.criteo.vips.options.HistEqualOptions options) throws VipsException;
	
	/**
	 * VipsHistEqual (hist_equal): histogram equalisation
	 * Mutates the image inplace.
	 */
	public void applyHistEqual() throws VipsException {
		applyHistEqual(null);
	}
	
	
	/**
	 * VipsHistEqual (hist_equal): histogram equalisation
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage histEqual(com.criteo.vips.options.HistEqualOptions options) throws VipsException;
	
	/**
	 * VipsHistEqual (hist_equal): histogram equalisation
	 * Returns a new image.
	 */
	public VipsImage histEqual() throws VipsException {
		return histEqual(null);
	}
	
	/**
	 * VipsHistFind (hist_find): find image histogram
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyHistFind(com.criteo.vips.options.HistFindOptions options) throws VipsException;
	
	/**
	 * VipsHistFind (hist_find): find image histogram
	 * Mutates the image inplace.
	 */
	public void applyHistFind() throws VipsException {
		applyHistFind(null);
	}
	
	
	/**
	 * VipsHistFind (hist_find): find image histogram
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage histFind(com.criteo.vips.options.HistFindOptions options) throws VipsException;
	
	/**
	 * VipsHistFind (hist_find): find image histogram
	 * Returns a new image.
	 */
	public VipsImage histFind() throws VipsException {
		return histFind(null);
	}
	
	/**
	 * VipsHistFindIndexed (hist_find_indexed): find indexed image histogram
	 * Mutates the image inplace.
	 * @param index Index image
	 * @param options optional arguments
	 */
	public native void applyHistFindIndexed(com.criteo.vips.Image index, com.criteo.vips.options.HistFindIndexedOptions options) throws VipsException;
	
	/**
	 * VipsHistFindIndexed (hist_find_indexed): find indexed image histogram
	 * Mutates the image inplace.
	 * @param index Index image
	 */
	public void applyHistFindIndexed(com.criteo.vips.Image index) throws VipsException {
		applyHistFindIndexed(index, null);
	}
	
	
	/**
	 * VipsHistFindIndexed (hist_find_indexed): find indexed image histogram
	 * Returns a new image.
	 * @param index Index image
	 * @param options optional arguments
	 */
	public native VipsImage histFindIndexed(com.criteo.vips.Image index, com.criteo.vips.options.HistFindIndexedOptions options) throws VipsException;
	
	/**
	 * VipsHistFindIndexed (hist_find_indexed): find indexed image histogram
	 * Returns a new image.
	 * @param index Index image
	 */
	public VipsImage histFindIndexed(com.criteo.vips.Image index) throws VipsException {
		return histFindIndexed(index, null);
	}
	
	/**
	 * VipsHistFindNDim (hist_find_ndim): find n-dimensional image histogram
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyHistFindNdim(com.criteo.vips.options.HistFindNdimOptions options) throws VipsException;
	
	/**
	 * VipsHistFindNDim (hist_find_ndim): find n-dimensional image histogram
	 * Mutates the image inplace.
	 */
	public void applyHistFindNdim() throws VipsException {
		applyHistFindNdim(null);
	}
	
	
	/**
	 * VipsHistFindNDim (hist_find_ndim): find n-dimensional image histogram
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage histFindNdim(com.criteo.vips.options.HistFindNdimOptions options) throws VipsException;
	
	/**
	 * VipsHistFindNDim (hist_find_ndim): find n-dimensional image histogram
	 * Returns a new image.
	 */
	public VipsImage histFindNdim() throws VipsException {
		return histFindNdim(null);
	}
	
	/**
	 * VipsHistIsmonotonic (hist_ismonotonic): test for monotonicity
	 */
	public native boolean histIsmonotonic() throws VipsException;
	
	/**
	 * VipsHistLocal (hist_local): local histogram equalisation
	 * Mutates the image inplace.
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 * @param options optional arguments
	 */
	public native void applyHistLocal(int width, int height, com.criteo.vips.options.HistLocalOptions options) throws VipsException;
	
	/**
	 * VipsHistLocal (hist_local): local histogram equalisation
	 * Mutates the image inplace.
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 */
	public void applyHistLocal(int width, int height) throws VipsException {
		applyHistLocal(width, height, null);
	}
	
	
	/**
	 * VipsHistLocal (hist_local): local histogram equalisation
	 * Returns a new image.
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 * @param options optional arguments
	 */
	public native VipsImage histLocal(int width, int height, com.criteo.vips.options.HistLocalOptions options) throws VipsException;
	
	/**
	 * VipsHistLocal (hist_local): local histogram equalisation
	 * Returns a new image.
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 */
	public VipsImage histLocal(int width, int height) throws VipsException {
		return histLocal(width, height, null);
	}
	
	/**
	 * VipsHistMatch (hist_match): match two histograms
	 * Mutates the image inplace.
	 * @param ref Reference histogram
	 */
	public native void applyHistMatch(com.criteo.vips.Image ref) throws VipsException;
	
	
	/**
	 * VipsHistMatch (hist_match): match two histograms
	 * Returns a new image.
	 * @param ref Reference histogram
	 */
	public native VipsImage histMatch(com.criteo.vips.Image ref) throws VipsException;
	
	/**
	 * VipsHistNorm (hist_norm): normalise histogram
	 * Mutates the image inplace.
	 */
	public native void applyHistNorm() throws VipsException;
	
	
	/**
	 * VipsHistNorm (hist_norm): normalise histogram
	 * Returns a new image.
	 */
	public native VipsImage histNorm() throws VipsException;
	
	/**
	 * VipsHistPlot (hist_plot): plot histogram
	 * Mutates the image inplace.
	 */
	public native void applyHistPlot() throws VipsException;
	
	
	/**
	 * VipsHistPlot (hist_plot): plot histogram
	 * Returns a new image.
	 */
	public native VipsImage histPlot() throws VipsException;
	
	/**
	 * VipsHoughCircle (hough_circle): find hough circle transform
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyHoughCircle(com.criteo.vips.options.HoughCircleOptions options) throws VipsException;
	
	/**
	 * VipsHoughCircle (hough_circle): find hough circle transform
	 * Mutates the image inplace.
	 */
	public void applyHoughCircle() throws VipsException {
		applyHoughCircle(null);
	}
	
	
	/**
	 * VipsHoughCircle (hough_circle): find hough circle transform
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage houghCircle(com.criteo.vips.options.HoughCircleOptions options) throws VipsException;
	
	/**
	 * VipsHoughCircle (hough_circle): find hough circle transform
	 * Returns a new image.
	 */
	public VipsImage houghCircle() throws VipsException {
		return houghCircle(null);
	}
	
	/**
	 * VipsHoughLine (hough_line): find hough line transform
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyHoughLine(com.criteo.vips.options.HoughLineOptions options) throws VipsException;
	
	/**
	 * VipsHoughLine (hough_line): find hough line transform
	 * Mutates the image inplace.
	 */
	public void applyHoughLine() throws VipsException {
		applyHoughLine(null);
	}
	
	
	/**
	 * VipsHoughLine (hough_line): find hough line transform
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage houghLine(com.criteo.vips.options.HoughLineOptions options) throws VipsException;
	
	/**
	 * VipsHoughLine (hough_line): find hough line transform
	 * Returns a new image.
	 */
	public VipsImage houghLine() throws VipsException {
		return houghLine(null);
	}
	
	/**
	 * VipsHSV2sRGB (HSV2sRGB): transform HSV to sRGB
	 * Mutates the image inplace.
	 */
	public native void applyHSV2sRGB() throws VipsException;
	
	
	/**
	 * VipsHSV2sRGB (HSV2sRGB): transform HSV to sRGB
	 * Returns a new image.
	 */
	public native VipsImage hSV2sRGB() throws VipsException;
	
	/**
	 * VipsIccExport (icc_export): output to device with ICC profile
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyIccExport(com.criteo.vips.options.ICCExportOptions options) throws VipsException;
	
	/**
	 * VipsIccExport (icc_export): output to device with ICC profile
	 * Mutates the image inplace.
	 */
	public void applyIccExport() throws VipsException {
		applyIccExport(null);
	}
	
	
	/**
	 * VipsIccExport (icc_export): output to device with ICC profile
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage iccExport(com.criteo.vips.options.ICCExportOptions options) throws VipsException;
	
	/**
	 * VipsIccExport (icc_export): output to device with ICC profile
	 * Returns a new image.
	 */
	public VipsImage iccExport() throws VipsException {
		return iccExport(null);
	}
	
	/**
	 * VipsIccImport (icc_import): import from device with ICC profile
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyIccImport(com.criteo.vips.options.ICCImportOptions options) throws VipsException;
	
	/**
	 * VipsIccImport (icc_import): import from device with ICC profile
	 * Mutates the image inplace.
	 */
	public void applyIccImport() throws VipsException {
		applyIccImport(null);
	}
	
	
	/**
	 * VipsIccImport (icc_import): import from device with ICC profile
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage iccImport(com.criteo.vips.options.ICCImportOptions options) throws VipsException;
	
	/**
	 * VipsIccImport (icc_import): import from device with ICC profile
	 * Returns a new image.
	 */
	public VipsImage iccImport() throws VipsException {
		return iccImport(null);
	}
	
	/**
	 * VipsIccTransform (icc_transform): transform between devices with ICC profiles
	 * Mutates the image inplace.
	 * @param outputProfile Filename to load output profile from
	 * @param options optional arguments
	 */
	public native void applyIccTransform(String outputProfile, com.criteo.vips.options.ICCTransformOptions options) throws VipsException;
	
	/**
	 * VipsIccTransform (icc_transform): transform between devices with ICC profiles
	 * Mutates the image inplace.
	 * @param outputProfile Filename to load output profile from
	 */
	public void applyIccTransform(String outputProfile) throws VipsException {
		applyIccTransform(outputProfile, null);
	}
	
	
	/**
	 * VipsIccTransform (icc_transform): transform between devices with ICC profiles
	 * Returns a new image.
	 * @param outputProfile Filename to load output profile from
	 * @param options optional arguments
	 */
	public native VipsImage iccTransform(String outputProfile, com.criteo.vips.options.ICCTransformOptions options) throws VipsException;
	
	/**
	 * VipsIccTransform (icc_transform): transform between devices with ICC profiles
	 * Returns a new image.
	 * @param outputProfile Filename to load output profile from
	 */
	public VipsImage iccTransform(String outputProfile) throws VipsException {
		return iccTransform(outputProfile, null);
	}
	
	/**
	 * VipsIdentity (identity): make a 1D image where pixel values are indexes
	 * @param options optional arguments
	 */
	public static native VipsImage identity(com.criteo.vips.options.IdentityOptions options) throws VipsException;
	
	/**
	 * VipsIdentity (identity): make a 1D image where pixel values are indexes
	 */
	public static VipsImage identity() throws VipsException {
		return identity(null);
	}
	
	/**
	 * VipsIfthenelse (ifthenelse): ifthenelse an image
	 * Mutates the image inplace.
	 * @param in1 Source for TRUE pixels
	 * @param in2 Source for FALSE pixels
	 * @param options optional arguments
	 */
	public native void applyIfthenelse(com.criteo.vips.Image in1, com.criteo.vips.Image in2, com.criteo.vips.options.IfthenelseOptions options) throws VipsException;
	
	/**
	 * VipsIfthenelse (ifthenelse): ifthenelse an image
	 * Mutates the image inplace.
	 * @param in1 Source for TRUE pixels
	 * @param in2 Source for FALSE pixels
	 */
	public void applyIfthenelse(com.criteo.vips.Image in1, com.criteo.vips.Image in2) throws VipsException {
		applyIfthenelse(in1, in2, null);
	}
	
	
	/**
	 * VipsIfthenelse (ifthenelse): ifthenelse an image
	 * Returns a new image.
	 * @param in1 Source for TRUE pixels
	 * @param in2 Source for FALSE pixels
	 * @param options optional arguments
	 */
	public native VipsImage ifthenelse(com.criteo.vips.Image in1, com.criteo.vips.Image in2, com.criteo.vips.options.IfthenelseOptions options) throws VipsException;
	
	/**
	 * VipsIfthenelse (ifthenelse): ifthenelse an image
	 * Returns a new image.
	 * @param in1 Source for TRUE pixels
	 * @param in2 Source for FALSE pixels
	 */
	public VipsImage ifthenelse(com.criteo.vips.Image in1, com.criteo.vips.Image in2) throws VipsException {
		return ifthenelse(in1, in2, null);
	}
	
	/**
	 * VipsInsert (insert): insert image @sub into @main at @x, @y
	 * Mutates the image inplace.
	 * @param sub Sub-image to insert into main image
	 * @param x Left edge of sub in main
	 * @param y Top edge of sub in main
	 * @param options optional arguments
	 */
	public native void applyInsert(com.criteo.vips.Image sub, int x, int y, com.criteo.vips.options.InsertOptions options) throws VipsException;
	
	/**
	 * VipsInsert (insert): insert image @sub into @main at @x, @y
	 * Mutates the image inplace.
	 * @param sub Sub-image to insert into main image
	 * @param x Left edge of sub in main
	 * @param y Top edge of sub in main
	 */
	public void applyInsert(com.criteo.vips.Image sub, int x, int y) throws VipsException {
		applyInsert(sub, x, y, null);
	}
	
	
	/**
	 * VipsInsert (insert): insert image @sub into @main at @x, @y
	 * Returns a new image.
	 * @param sub Sub-image to insert into main image
	 * @param x Left edge of sub in main
	 * @param y Top edge of sub in main
	 * @param options optional arguments
	 */
	public native VipsImage insert(com.criteo.vips.Image sub, int x, int y, com.criteo.vips.options.InsertOptions options) throws VipsException;
	
	/**
	 * VipsInsert (insert): insert image @sub into @main at @x, @y
	 * Returns a new image.
	 * @param sub Sub-image to insert into main image
	 * @param x Left edge of sub in main
	 * @param y Top edge of sub in main
	 */
	public VipsImage insert(com.criteo.vips.Image sub, int x, int y) throws VipsException {
		return insert(sub, x, y, null);
	}
	
	/**
	 * VipsInvert (invert): invert an image
	 * Mutates the image inplace.
	 */
	public native void applyInvert() throws VipsException;
	
	
	/**
	 * VipsInvert (invert): invert an image
	 * Returns a new image.
	 */
	public native VipsImage invert() throws VipsException;
	
	/**
	 * VipsInvertlut (invertlut): build an inverted look-up table
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyInvertlut(com.criteo.vips.options.InvertLUTOptions options) throws VipsException;
	
	/**
	 * VipsInvertlut (invertlut): build an inverted look-up table
	 * Mutates the image inplace.
	 */
	public void applyInvertlut() throws VipsException {
		applyInvertlut(null);
	}
	
	
	/**
	 * VipsInvertlut (invertlut): build an inverted look-up table
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage invertlut(com.criteo.vips.options.InvertLUTOptions options) throws VipsException;
	
	/**
	 * VipsInvertlut (invertlut): build an inverted look-up table
	 * Returns a new image.
	 */
	public VipsImage invertlut() throws VipsException {
		return invertlut(null);
	}
	
	/**
	 * VipsInvfft (invfft): inverse FFT
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyInvfft(com.criteo.vips.options.InvFFTOptions options) throws VipsException;
	
	/**
	 * VipsInvfft (invfft): inverse FFT
	 * Mutates the image inplace.
	 */
	public void applyInvfft() throws VipsException {
		applyInvfft(null);
	}
	
	
	/**
	 * VipsInvfft (invfft): inverse FFT
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage invfft(com.criteo.vips.options.InvFFTOptions options) throws VipsException;
	
	/**
	 * VipsInvfft (invfft): inverse FFT
	 * Returns a new image.
	 */
	public VipsImage invfft() throws VipsException {
		return invfft(null);
	}
	
	/**
	 * VipsJoin (join): join a pair of images
	 * Mutates the image inplace.
	 * @param in2 Second input image
	 * @param direction Join left-right or up-down
	 * @param options optional arguments
	 */
	public native void applyJoin(com.criteo.vips.Image in2, com.criteo.vips.enums.VipsDirection direction, com.criteo.vips.options.JoinOptions options) throws VipsException;
	
	/**
	 * VipsJoin (join): join a pair of images
	 * Mutates the image inplace.
	 * @param in2 Second input image
	 * @param direction Join left-right or up-down
	 */
	public void applyJoin(com.criteo.vips.Image in2, com.criteo.vips.enums.VipsDirection direction) throws VipsException {
		applyJoin(in2, direction, null);
	}
	
	
	/**
	 * VipsJoin (join): join a pair of images
	 * Returns a new image.
	 * @param in2 Second input image
	 * @param direction Join left-right or up-down
	 * @param options optional arguments
	 */
	public native VipsImage join(com.criteo.vips.Image in2, com.criteo.vips.enums.VipsDirection direction, com.criteo.vips.options.JoinOptions options) throws VipsException;
	
	/**
	 * VipsJoin (join): join a pair of images
	 * Returns a new image.
	 * @param in2 Second input image
	 * @param direction Join left-right or up-down
	 */
	public VipsImage join(com.criteo.vips.Image in2, com.criteo.vips.enums.VipsDirection direction) throws VipsException {
		return join(in2, direction, null);
	}
	
	/**
	 * VipsForeignLoadJp2kFile (jp2kload): load JPEG2000 image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage jp2kLoad(String filename, com.criteo.vips.options.JP2KLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadJp2kFile (jp2kload): load JPEG2000 image
	 * @param filename Filename to load from
	 */
	public static VipsImage jp2kLoad(String filename) throws VipsException {
		return jp2kLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadJp2kBuffer (jp2kload_buffer): load JPEG2000 image
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage jp2kLoadBuffer(byte[] buffer, com.criteo.vips.options.JP2KLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadJp2kBuffer (jp2kload_buffer): load JPEG2000 image
	 * @param buffer Buffer to load from
	 */
	public static VipsImage jp2kLoadBuffer(byte[] buffer) throws VipsException {
		return jp2kLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveJp2kFile (jp2ksave): save image in JPEG2000 format
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public native void jp2kSave(String filename, com.criteo.vips.options.JP2KSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveJp2kFile (jp2ksave): save image in JPEG2000 format
	 * @param filename Filename to load from
	 */
	public void jp2kSave(String filename) throws VipsException {
		jp2kSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveJp2kBuffer (jp2ksave_buffer): save image in JPEG2000 format
	 * @param options optional arguments
	 */
	public native byte[] jp2kSaveBuffer(com.criteo.vips.options.JP2KSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveJp2kBuffer (jp2ksave_buffer): save image in JPEG2000 format
	 */
	public byte[] jp2kSaveBuffer() throws VipsException {
		return jp2kSaveBuffer(null);
	}
	
	/**
	 * VipsForeignLoadJpegFile (jpegload): load jpeg from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage jpegLoad(String filename, com.criteo.vips.options.JPEGLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadJpegFile (jpegload): load jpeg from file
	 * @param filename Filename to load from
	 */
	public static VipsImage jpegLoad(String filename) throws VipsException {
		return jpegLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadJpegBuffer (jpegload_buffer): load jpeg from buffer
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage jpegLoadBuffer(byte[] buffer, com.criteo.vips.options.JPEGLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadJpegBuffer (jpegload_buffer): load jpeg from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage jpegLoadBuffer(byte[] buffer) throws VipsException {
		return jpegLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveJpegFile (jpegsave): save image to jpeg file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void jpegSave(String filename, com.criteo.vips.options.JPEGSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveJpegFile (jpegsave): save image to jpeg file
	 * @param filename Filename to save to
	 */
	public void jpegSave(String filename) throws VipsException {
		jpegSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveJpegBuffer (jpegsave_buffer): save image to jpeg buffer
	 * @param options optional arguments
	 */
	public native byte[] jpegSaveBuffer(com.criteo.vips.options.JPEGSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveJpegBuffer (jpegsave_buffer): save image to jpeg buffer
	 */
	public byte[] jpegSaveBuffer() throws VipsException {
		return jpegSaveBuffer(null);
	}
	
	/**
	 * VipsForeignSaveJpegMime (jpegsave_mime): save image to jpeg mime
	 * @param options optional arguments
	 */
	public native void jpegSaveMime(com.criteo.vips.options.JPEGSaveMimeOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveJpegMime (jpegsave_mime): save image to jpeg mime
	 */
	public void jpegSaveMime() throws VipsException {
		jpegSaveMime(null);
	}
	
	/**
	 * VipsForeignLoadJxlFile (jxlload): load JPEG-XL image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage jxlLoad(String filename, com.criteo.vips.options.JXLLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadJxlFile (jxlload): load JPEG-XL image
	 * @param filename Filename to load from
	 */
	public static VipsImage jxlLoad(String filename) throws VipsException {
		return jxlLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadJxlBuffer (jxlload_buffer): load JPEG-XL image
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage jxlLoadBuffer(byte[] buffer, com.criteo.vips.options.JXLLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadJxlBuffer (jxlload_buffer): load JPEG-XL image
	 * @param buffer Buffer to load from
	 */
	public static VipsImage jxlLoadBuffer(byte[] buffer) throws VipsException {
		return jxlLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveJxlFile (jxlsave): save image in JPEG-XL format
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public native void jxlSave(String filename, com.criteo.vips.options.JXLSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveJxlFile (jxlsave): save image in JPEG-XL format
	 * @param filename Filename to load from
	 */
	public void jxlSave(String filename) throws VipsException {
		jxlSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveJxlBuffer (jxlsave_buffer): save image in JPEG-XL format
	 * @param options optional arguments
	 */
	public native byte[] jxlSaveBuffer(com.criteo.vips.options.JXLSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveJxlBuffer (jxlsave_buffer): save image in JPEG-XL format
	 */
	public byte[] jxlSaveBuffer() throws VipsException {
		return jxlSaveBuffer(null);
	}
	
	/**
	 * VipsLab2LabQ (Lab2LabQ): transform float Lab to LabQ coding
	 * Mutates the image inplace.
	 */
	public native void applyLab2LabQ() throws VipsException;
	
	
	/**
	 * VipsLab2LabQ (Lab2LabQ): transform float Lab to LabQ coding
	 * Returns a new image.
	 */
	public native VipsImage lab2LabQ() throws VipsException;
	
	/**
	 * VipsLab2LabS (Lab2LabS): transform float Lab to signed short
	 * Mutates the image inplace.
	 */
	public native void applyLab2LabS() throws VipsException;
	
	
	/**
	 * VipsLab2LabS (Lab2LabS): transform float Lab to signed short
	 * Returns a new image.
	 */
	public native VipsImage lab2LabS() throws VipsException;
	
	/**
	 * VipsLab2LCh (Lab2LCh): transform Lab to LCh
	 * Mutates the image inplace.
	 */
	public native void applyLab2LCh() throws VipsException;
	
	
	/**
	 * VipsLab2LCh (Lab2LCh): transform Lab to LCh
	 * Returns a new image.
	 */
	public native VipsImage lab2LCh() throws VipsException;
	
	/**
	 * VipsLab2XYZ (Lab2XYZ): transform CIELAB to XYZ
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyLab2XYZ(com.criteo.vips.options.LAB2XYZOptions options) throws VipsException;
	
	/**
	 * VipsLab2XYZ (Lab2XYZ): transform CIELAB to XYZ
	 * Mutates the image inplace.
	 */
	public void applyLab2XYZ() throws VipsException {
		applyLab2XYZ(null);
	}
	
	
	/**
	 * VipsLab2XYZ (Lab2XYZ): transform CIELAB to XYZ
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage lab2XYZ(com.criteo.vips.options.LAB2XYZOptions options) throws VipsException;
	
	/**
	 * VipsLab2XYZ (Lab2XYZ): transform CIELAB to XYZ
	 * Returns a new image.
	 */
	public VipsImage lab2XYZ() throws VipsException {
		return lab2XYZ(null);
	}
	
	/**
	 * VipsLabelregions (labelregions): label regions in an image
	 * Mutates the image inplace.
	 */
	public native void applyLabelregions() throws VipsException;
	
	
	/**
	 * VipsLabelregions (labelregions): label regions in an image
	 * Returns a new image.
	 */
	public native VipsImage labelregions() throws VipsException;
	
	/**
	 * VipsLabQ2Lab (LabQ2Lab): unpack a LabQ image to float Lab
	 * Mutates the image inplace.
	 */
	public native void applyLabQ2Lab() throws VipsException;
	
	
	/**
	 * VipsLabQ2Lab (LabQ2Lab): unpack a LabQ image to float Lab
	 * Returns a new image.
	 */
	public native VipsImage labQ2Lab() throws VipsException;
	
	/**
	 * VipsLabQ2LabS (LabQ2LabS): unpack a LabQ image to short Lab
	 * Mutates the image inplace.
	 */
	public native void applyLabQ2LabS() throws VipsException;
	
	
	/**
	 * VipsLabQ2LabS (LabQ2LabS): unpack a LabQ image to short Lab
	 * Returns a new image.
	 */
	public native VipsImage labQ2LabS() throws VipsException;
	
	/**
	 * VipsLabQ2sRGB (LabQ2sRGB): convert a LabQ image to sRGB
	 * Mutates the image inplace.
	 */
	public native void applyLabQ2sRGB() throws VipsException;
	
	
	/**
	 * VipsLabQ2sRGB (LabQ2sRGB): convert a LabQ image to sRGB
	 * Returns a new image.
	 */
	public native VipsImage labQ2sRGB() throws VipsException;
	
	/**
	 * VipsLabS2Lab (LabS2Lab): transform signed short Lab to float
	 * Mutates the image inplace.
	 */
	public native void applyLabS2Lab() throws VipsException;
	
	
	/**
	 * VipsLabS2Lab (LabS2Lab): transform signed short Lab to float
	 * Returns a new image.
	 */
	public native VipsImage labS2Lab() throws VipsException;
	
	/**
	 * VipsLabS2LabQ (LabS2LabQ): transform short Lab to LabQ coding
	 * Mutates the image inplace.
	 */
	public native void applyLabS2LabQ() throws VipsException;
	
	
	/**
	 * VipsLabS2LabQ (LabS2LabQ): transform short Lab to LabQ coding
	 * Returns a new image.
	 */
	public native VipsImage labS2LabQ() throws VipsException;
	
	/**
	 * VipsLCh2CMC (LCh2CMC): transform LCh to CMC
	 * Mutates the image inplace.
	 */
	public native void applyLCh2CMC() throws VipsException;
	
	
	/**
	 * VipsLCh2CMC (LCh2CMC): transform LCh to CMC
	 * Returns a new image.
	 */
	public native VipsImage lCh2CMC() throws VipsException;
	
	/**
	 * VipsLCh2Lab (LCh2Lab): transform LCh to Lab
	 * Mutates the image inplace.
	 */
	public native void applyLCh2Lab() throws VipsException;
	
	
	/**
	 * VipsLCh2Lab (LCh2Lab): transform LCh to Lab
	 * Returns a new image.
	 */
	public native VipsImage lCh2Lab() throws VipsException;
	
	/**
	 * VipsLinear (linear): calculate (a * in + b)
	 * Mutates the image inplace.
	 * @param a Multiply by this
	 * @param b Add this
	 * @param options optional arguments
	 */
	public native void applyLinear(double[] a, double[] b, com.criteo.vips.options.LinearOptions options) throws VipsException;
	
	/**
	 * VipsLinear (linear): calculate (a * in + b)
	 * Mutates the image inplace.
	 * @param a Multiply by this
	 * @param b Add this
	 */
	public void applyLinear(double[] a, double[] b) throws VipsException {
		applyLinear(a, b, null);
	}
	
	
	/**
	 * VipsLinear (linear): calculate (a * in + b)
	 * Returns a new image.
	 * @param a Multiply by this
	 * @param b Add this
	 * @param options optional arguments
	 */
	public native VipsImage linear(double[] a, double[] b, com.criteo.vips.options.LinearOptions options) throws VipsException;
	
	/**
	 * VipsLinear (linear): calculate (a * in + b)
	 * Returns a new image.
	 * @param a Multiply by this
	 * @param b Add this
	 */
	public VipsImage linear(double[] a, double[] b) throws VipsException {
		return linear(a, b, null);
	}
	
	/**
	 * VipsLineCache (linecache): cache an image as a set of lines
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyLinecache(com.criteo.vips.options.LinecacheOptions options) throws VipsException;
	
	/**
	 * VipsLineCache (linecache): cache an image as a set of lines
	 * Mutates the image inplace.
	 */
	public void applyLinecache() throws VipsException {
		applyLinecache(null);
	}
	
	
	/**
	 * VipsLineCache (linecache): cache an image as a set of lines
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage linecache(com.criteo.vips.options.LinecacheOptions options) throws VipsException;
	
	/**
	 * VipsLineCache (linecache): cache an image as a set of lines
	 * Returns a new image.
	 */
	public VipsImage linecache() throws VipsException {
		return linecache(null);
	}
	
	/**
	 * VipsLogmat (logmat): make a Laplacian of Gaussian image
	 * @param sigma Radius of Gaussian
	 * @param minAmpl Minimum amplitude of Gaussian
	 * @param options optional arguments
	 */
	public static native VipsImage logmat(double sigma, double minAmpl, com.criteo.vips.options.LogmatOptions options) throws VipsException;
	
	/**
	 * VipsLogmat (logmat): make a Laplacian of Gaussian image
	 * @param sigma Radius of Gaussian
	 * @param minAmpl Minimum amplitude of Gaussian
	 */
	public static VipsImage logmat(double sigma, double minAmpl) throws VipsException {
		return logmat(sigma, minAmpl, null);
	}
	
	/**
	 * VipsForeignLoadMagick7File (magickload): load file with ImageMagick7
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage magickLoad(String filename, com.criteo.vips.options.MagickLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadMagick7File (magickload): load file with ImageMagick7
	 * @param filename Filename to load from
	 */
	public static VipsImage magickLoad(String filename) throws VipsException {
		return magickLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadMagick7Buffer (magickload_buffer): load buffer with ImageMagick7
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage magickLoadBuffer(byte[] buffer, com.criteo.vips.options.MagickLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadMagick7Buffer (magickload_buffer): load buffer with ImageMagick7
	 * @param buffer Buffer to load from
	 */
	public static VipsImage magickLoadBuffer(byte[] buffer) throws VipsException {
		return magickLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveMagickFile (magicksave): save file with ImageMagick
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void magickSave(String filename, com.criteo.vips.options.MagickSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveMagickFile (magicksave): save file with ImageMagick
	 * @param filename Filename to save to
	 */
	public void magickSave(String filename) throws VipsException {
		magickSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveMagickBuffer (magicksave_buffer): save image to magick buffer
	 * @param options optional arguments
	 */
	public native byte[] magickSaveBuffer(com.criteo.vips.options.MagickSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveMagickBuffer (magicksave_buffer): save image to magick buffer
	 */
	public byte[] magickSaveBuffer() throws VipsException {
		return magickSaveBuffer(null);
	}
	
	/**
	 * VipsMaplut (maplut): map an image though a lut
	 * Mutates the image inplace.
	 * @param lut Look-up table image
	 * @param options optional arguments
	 */
	public native void applyMaplut(com.criteo.vips.Image lut, com.criteo.vips.options.MapLUTOptions options) throws VipsException;
	
	/**
	 * VipsMaplut (maplut): map an image though a lut
	 * Mutates the image inplace.
	 * @param lut Look-up table image
	 */
	public void applyMaplut(com.criteo.vips.Image lut) throws VipsException {
		applyMaplut(lut, null);
	}
	
	
	/**
	 * VipsMaplut (maplut): map an image though a lut
	 * Returns a new image.
	 * @param lut Look-up table image
	 * @param options optional arguments
	 */
	public native VipsImage maplut(com.criteo.vips.Image lut, com.criteo.vips.options.MapLUTOptions options) throws VipsException;
	
	/**
	 * VipsMaplut (maplut): map an image though a lut
	 * Returns a new image.
	 * @param lut Look-up table image
	 */
	public VipsImage maplut(com.criteo.vips.Image lut) throws VipsException {
		return maplut(lut, null);
	}
	
	/**
	 * VipsMaskButterworth (mask_butterworth): make a butterworth filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param order Filter order
	 * @param frequencyCutoff Frequency cutoff
	 * @param amplitudeCutoff Amplitude cutoff
	 * @param options optional arguments
	 */
	public static native VipsImage maskButterworth(int width, int height, double order, double frequencyCutoff, double amplitudeCutoff, com.criteo.vips.options.MaskButterworthOptions options) throws VipsException;
	
	/**
	 * VipsMaskButterworth (mask_butterworth): make a butterworth filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param order Filter order
	 * @param frequencyCutoff Frequency cutoff
	 * @param amplitudeCutoff Amplitude cutoff
	 */
	public static VipsImage maskButterworth(int width, int height, double order, double frequencyCutoff, double amplitudeCutoff) throws VipsException {
		return maskButterworth(width, height, order, frequencyCutoff, amplitudeCutoff, null);
	}
	
	/**
	 * VipsMaskButterworthBand (mask_butterworth_band): make a butterworth_band filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param order Filter order
	 * @param frequencyCutoffX Frequency cutoff x
	 * @param frequencyCutoffY Frequency cutoff y
	 * @param radius Radius of circle
	 * @param amplitudeCutoff Amplitude cutoff
	 * @param options optional arguments
	 */
	public static native VipsImage maskButterworthBand(int width, int height, double order, double frequencyCutoffX, double frequencyCutoffY, double radius, double amplitudeCutoff, com.criteo.vips.options.MaskButterworthBandOptions options) throws VipsException;
	
	/**
	 * VipsMaskButterworthBand (mask_butterworth_band): make a butterworth_band filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param order Filter order
	 * @param frequencyCutoffX Frequency cutoff x
	 * @param frequencyCutoffY Frequency cutoff y
	 * @param radius Radius of circle
	 * @param amplitudeCutoff Amplitude cutoff
	 */
	public static VipsImage maskButterworthBand(int width, int height, double order, double frequencyCutoffX, double frequencyCutoffY, double radius, double amplitudeCutoff) throws VipsException {
		return maskButterworthBand(width, height, order, frequencyCutoffX, frequencyCutoffY, radius, amplitudeCutoff, null);
	}
	
	/**
	 * VipsMaskButterworthRing (mask_butterworth_ring): make a butterworth ring filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param order Filter order
	 * @param frequencyCutoff Frequency cutoff
	 * @param amplitudeCutoff Amplitude cutoff
	 * @param ringwidth Ringwidth
	 * @param options optional arguments
	 */
	public static native VipsImage maskButterworthRing(int width, int height, double order, double frequencyCutoff, double amplitudeCutoff, double ringwidth, com.criteo.vips.options.MaskButterworthRingOptions options) throws VipsException;
	
	/**
	 * VipsMaskButterworthRing (mask_butterworth_ring): make a butterworth ring filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param order Filter order
	 * @param frequencyCutoff Frequency cutoff
	 * @param amplitudeCutoff Amplitude cutoff
	 * @param ringwidth Ringwidth
	 */
	public static VipsImage maskButterworthRing(int width, int height, double order, double frequencyCutoff, double amplitudeCutoff, double ringwidth) throws VipsException {
		return maskButterworthRing(width, height, order, frequencyCutoff, amplitudeCutoff, ringwidth, null);
	}
	
	/**
	 * VipsMaskFractal (mask_fractal): make fractal filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param fractalDimension Fractal dimension
	 * @param options optional arguments
	 */
	public static native VipsImage maskFractal(int width, int height, double fractalDimension, com.criteo.vips.options.MaskFractalOptions options) throws VipsException;
	
	/**
	 * VipsMaskFractal (mask_fractal): make fractal filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param fractalDimension Fractal dimension
	 */
	public static VipsImage maskFractal(int width, int height, double fractalDimension) throws VipsException {
		return maskFractal(width, height, fractalDimension, null);
	}
	
	/**
	 * VipsMaskGaussian (mask_gaussian): make a gaussian filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoff Frequency cutoff
	 * @param amplitudeCutoff Amplitude cutoff
	 * @param options optional arguments
	 */
	public static native VipsImage maskGaussian(int width, int height, double frequencyCutoff, double amplitudeCutoff, com.criteo.vips.options.MaskGaussianOptions options) throws VipsException;
	
	/**
	 * VipsMaskGaussian (mask_gaussian): make a gaussian filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoff Frequency cutoff
	 * @param amplitudeCutoff Amplitude cutoff
	 */
	public static VipsImage maskGaussian(int width, int height, double frequencyCutoff, double amplitudeCutoff) throws VipsException {
		return maskGaussian(width, height, frequencyCutoff, amplitudeCutoff, null);
	}
	
	/**
	 * VipsMaskGaussianBand (mask_gaussian_band): make a gaussian filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoffX Frequency cutoff x
	 * @param frequencyCutoffY Frequency cutoff y
	 * @param radius Radius of circle
	 * @param amplitudeCutoff Amplitude cutoff
	 * @param options optional arguments
	 */
	public static native VipsImage maskGaussianBand(int width, int height, double frequencyCutoffX, double frequencyCutoffY, double radius, double amplitudeCutoff, com.criteo.vips.options.MaskGaussianBandOptions options) throws VipsException;
	
	/**
	 * VipsMaskGaussianBand (mask_gaussian_band): make a gaussian filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoffX Frequency cutoff x
	 * @param frequencyCutoffY Frequency cutoff y
	 * @param radius Radius of circle
	 * @param amplitudeCutoff Amplitude cutoff
	 */
	public static VipsImage maskGaussianBand(int width, int height, double frequencyCutoffX, double frequencyCutoffY, double radius, double amplitudeCutoff) throws VipsException {
		return maskGaussianBand(width, height, frequencyCutoffX, frequencyCutoffY, radius, amplitudeCutoff, null);
	}
	
	/**
	 * VipsMaskGaussianRing (mask_gaussian_ring): make a gaussian ring filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoff Frequency cutoff
	 * @param amplitudeCutoff Amplitude cutoff
	 * @param ringwidth Ringwidth
	 * @param options optional arguments
	 */
	public static native VipsImage maskGaussianRing(int width, int height, double frequencyCutoff, double amplitudeCutoff, double ringwidth, com.criteo.vips.options.MaskGaussianRingOptions options) throws VipsException;
	
	/**
	 * VipsMaskGaussianRing (mask_gaussian_ring): make a gaussian ring filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoff Frequency cutoff
	 * @param amplitudeCutoff Amplitude cutoff
	 * @param ringwidth Ringwidth
	 */
	public static VipsImage maskGaussianRing(int width, int height, double frequencyCutoff, double amplitudeCutoff, double ringwidth) throws VipsException {
		return maskGaussianRing(width, height, frequencyCutoff, amplitudeCutoff, ringwidth, null);
	}
	
	/**
	 * VipsMaskIdeal (mask_ideal): make an ideal filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoff Frequency cutoff
	 * @param options optional arguments
	 */
	public static native VipsImage maskIdeal(int width, int height, double frequencyCutoff, com.criteo.vips.options.MaskIdealOptions options) throws VipsException;
	
	/**
	 * VipsMaskIdeal (mask_ideal): make an ideal filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoff Frequency cutoff
	 */
	public static VipsImage maskIdeal(int width, int height, double frequencyCutoff) throws VipsException {
		return maskIdeal(width, height, frequencyCutoff, null);
	}
	
	/**
	 * VipsMaskIdealBand (mask_ideal_band): make an ideal band filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoffX Frequency cutoff x
	 * @param frequencyCutoffY Frequency cutoff y
	 * @param radius Radius of circle
	 * @param options optional arguments
	 */
	public static native VipsImage maskIdealBand(int width, int height, double frequencyCutoffX, double frequencyCutoffY, double radius, com.criteo.vips.options.MaskIdealBandOptions options) throws VipsException;
	
	/**
	 * VipsMaskIdealBand (mask_ideal_band): make an ideal band filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoffX Frequency cutoff x
	 * @param frequencyCutoffY Frequency cutoff y
	 * @param radius Radius of circle
	 */
	public static VipsImage maskIdealBand(int width, int height, double frequencyCutoffX, double frequencyCutoffY, double radius) throws VipsException {
		return maskIdealBand(width, height, frequencyCutoffX, frequencyCutoffY, radius, null);
	}
	
	/**
	 * VipsMaskIdealRing (mask_ideal_ring): make an ideal ring filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoff Frequency cutoff
	 * @param ringwidth Ringwidth
	 * @param options optional arguments
	 */
	public static native VipsImage maskIdealRing(int width, int height, double frequencyCutoff, double ringwidth, com.criteo.vips.options.MaskIdealRingOptions options) throws VipsException;
	
	/**
	 * VipsMaskIdealRing (mask_ideal_ring): make an ideal ring filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoff Frequency cutoff
	 * @param ringwidth Ringwidth
	 */
	public static VipsImage maskIdealRing(int width, int height, double frequencyCutoff, double ringwidth) throws VipsException {
		return maskIdealRing(width, height, frequencyCutoff, ringwidth, null);
	}
	
	/**
	 * VipsMath (math): apply a math operation to an image
	 * Mutates the image inplace.
	 * @param math Math to perform
	 */
	public native void applyMath(com.criteo.vips.enums.VipsOperationMath math) throws VipsException;
	
	
	/**
	 * VipsMath (math): apply a math operation to an image
	 * Returns a new image.
	 * @param math Math to perform
	 */
	public native VipsImage math(com.criteo.vips.enums.VipsOperationMath math) throws VipsException;
	
	/**
	 * VipsMath2 (math2): binary math operations
	 * Mutates the image inplace.
	 * @param right Right-hand image argument
	 * @param math2 Math to perform
	 */
	public native void applyMath2(com.criteo.vips.Image right, com.criteo.vips.enums.VipsOperationMath2 math2) throws VipsException;
	
	
	/**
	 * VipsMath2 (math2): binary math operations
	 * Returns a new image.
	 * @param right Right-hand image argument
	 * @param math2 Math to perform
	 */
	public native VipsImage math2(com.criteo.vips.Image right, com.criteo.vips.enums.VipsOperationMath2 math2) throws VipsException;
	
	/**
	 * VipsMath2Const (math2_const): binary math operations with a constant
	 * Mutates the image inplace.
	 * @param math2 Math to perform
	 * @param c Array of constants
	 */
	public native void applyMath2Const(com.criteo.vips.enums.VipsOperationMath2 math2, double[] c) throws VipsException;
	
	
	/**
	 * VipsMath2Const (math2_const): binary math operations with a constant
	 * Returns a new image.
	 * @param math2 Math to perform
	 * @param c Array of constants
	 */
	public native VipsImage math2Const(com.criteo.vips.enums.VipsOperationMath2 math2, double[] c) throws VipsException;
	
	/**
	 * VipsForeignLoadMat (matload): load mat from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage matLoad(String filename, com.criteo.vips.options.MatLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadMat (matload): load mat from file
	 * @param filename Filename to load from
	 */
	public static VipsImage matLoad(String filename) throws VipsException {
		return matLoad(filename, null);
	}
	
	/**
	 * VipsMatrixinvert (matrixinvert): invert an matrix
	 * Mutates the image inplace.
	 */
	public native void applyMatrixinvert() throws VipsException;
	
	
	/**
	 * VipsMatrixinvert (matrixinvert): invert an matrix
	 * Returns a new image.
	 */
	public native VipsImage matrixinvert() throws VipsException;
	
	/**
	 * VipsForeignLoadMatrixFile (matrixload): load matrix
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage matrixLoad(String filename, com.criteo.vips.options.MatrixLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadMatrixFile (matrixload): load matrix
	 * @param filename Filename to load from
	 */
	public static VipsImage matrixLoad(String filename) throws VipsException {
		return matrixLoad(filename, null);
	}
	
	/**
	 * VipsForeignPrintMatrix (matrixprint): print matrix
	 * @param options optional arguments
	 */
	public native void matrixprint(com.criteo.vips.options.MatrixprintOptions options) throws VipsException;
	
	/**
	 * VipsForeignPrintMatrix (matrixprint): print matrix
	 */
	public void matrixprint() throws VipsException {
		matrixprint(null);
	}
	
	/**
	 * VipsForeignSaveMatrixFile (matrixsave): save image to matrix
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void matrixSave(String filename, com.criteo.vips.options.MatrixSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveMatrixFile (matrixsave): save image to matrix
	 * @param filename Filename to save to
	 */
	public void matrixSave(String filename) throws VipsException {
		matrixSave(filename, null);
	}
	
	/**
	 * VipsMax (max): find image maximum
	 * @param options optional arguments
	 */
	public native double max(com.criteo.vips.options.MaxOptions options) throws VipsException;
	
	/**
	 * VipsMax (max): find image maximum
	 */
	public double max() throws VipsException {
		return max(null);
	}
	
	/**
	 * VipsMeasure (measure): measure a set of patches on a color chart
	 * Mutates the image inplace.
	 * @param h Number of patches across chart
	 * @param v Number of patches down chart
	 * @param options optional arguments
	 */
	public native void applyMeasure(int h, int v, com.criteo.vips.options.MeasureOptions options) throws VipsException;
	
	/**
	 * VipsMeasure (measure): measure a set of patches on a color chart
	 * Mutates the image inplace.
	 * @param h Number of patches across chart
	 * @param v Number of patches down chart
	 */
	public void applyMeasure(int h, int v) throws VipsException {
		applyMeasure(h, v, null);
	}
	
	
	/**
	 * VipsMeasure (measure): measure a set of patches on a color chart
	 * Returns a new image.
	 * @param h Number of patches across chart
	 * @param v Number of patches down chart
	 * @param options optional arguments
	 */
	public native VipsImage measure(int h, int v, com.criteo.vips.options.MeasureOptions options) throws VipsException;
	
	/**
	 * VipsMeasure (measure): measure a set of patches on a color chart
	 * Returns a new image.
	 * @param h Number of patches across chart
	 * @param v Number of patches down chart
	 */
	public VipsImage measure(int h, int v) throws VipsException {
		return measure(h, v, null);
	}
	
	/**
	 * VipsMerge (merge): merge two images
	 * Mutates the image inplace.
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical merge
	 * @param dx Horizontal displacement from sec to ref
	 * @param dy Vertical displacement from sec to ref
	 * @param options optional arguments
	 */
	public native void applyMerge(com.criteo.vips.Image sec, com.criteo.vips.enums.VipsDirection direction, int dx, int dy, com.criteo.vips.options.MergeOptions options) throws VipsException;
	
	/**
	 * VipsMerge (merge): merge two images
	 * Mutates the image inplace.
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical merge
	 * @param dx Horizontal displacement from sec to ref
	 * @param dy Vertical displacement from sec to ref
	 */
	public void applyMerge(com.criteo.vips.Image sec, com.criteo.vips.enums.VipsDirection direction, int dx, int dy) throws VipsException {
		applyMerge(sec, direction, dx, dy, null);
	}
	
	
	/**
	 * VipsMerge (merge): merge two images
	 * Returns a new image.
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical merge
	 * @param dx Horizontal displacement from sec to ref
	 * @param dy Vertical displacement from sec to ref
	 * @param options optional arguments
	 */
	public native VipsImage merge(com.criteo.vips.Image sec, com.criteo.vips.enums.VipsDirection direction, int dx, int dy, com.criteo.vips.options.MergeOptions options) throws VipsException;
	
	/**
	 * VipsMerge (merge): merge two images
	 * Returns a new image.
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical merge
	 * @param dx Horizontal displacement from sec to ref
	 * @param dy Vertical displacement from sec to ref
	 */
	public VipsImage merge(com.criteo.vips.Image sec, com.criteo.vips.enums.VipsDirection direction, int dx, int dy) throws VipsException {
		return merge(sec, direction, dx, dy, null);
	}
	
	/**
	 * VipsMin (min): find image minimum
	 * @param options optional arguments
	 */
	public native double min(com.criteo.vips.options.MinOptions options) throws VipsException;
	
	/**
	 * VipsMin (min): find image minimum
	 */
	public double min() throws VipsException {
		return min(null);
	}
	
	/**
	 * VipsMorph (morph): morphology operation
	 * Mutates the image inplace.
	 * @param mask Input matrix image
	 * @param morph Morphological operation to perform
	 */
	public native void applyMorph(com.criteo.vips.Image mask, com.criteo.vips.enums.VipsOperationMorphology morph) throws VipsException;
	
	
	/**
	 * VipsMorph (morph): morphology operation
	 * Returns a new image.
	 * @param mask Input matrix image
	 * @param morph Morphological operation to perform
	 */
	public native VipsImage morph(com.criteo.vips.Image mask, com.criteo.vips.enums.VipsOperationMorphology morph) throws VipsException;
	
	/**
	 * VipsMosaic (mosaic): mosaic two images
	 * Mutates the image inplace.
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical mosaic
	 * @param xref Position of reference tie-point
	 * @param yref Position of reference tie-point
	 * @param xsec Position of secondary tie-point
	 * @param ysec Position of secondary tie-point
	 * @param options optional arguments
	 */
	public native void applyMosaic(com.criteo.vips.Image sec, com.criteo.vips.enums.VipsDirection direction, int xref, int yref, int xsec, int ysec, com.criteo.vips.options.MosaicOptions options) throws VipsException;
	
	/**
	 * VipsMosaic (mosaic): mosaic two images
	 * Mutates the image inplace.
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical mosaic
	 * @param xref Position of reference tie-point
	 * @param yref Position of reference tie-point
	 * @param xsec Position of secondary tie-point
	 * @param ysec Position of secondary tie-point
	 */
	public void applyMosaic(com.criteo.vips.Image sec, com.criteo.vips.enums.VipsDirection direction, int xref, int yref, int xsec, int ysec) throws VipsException {
		applyMosaic(sec, direction, xref, yref, xsec, ysec, null);
	}
	
	
	/**
	 * VipsMosaic (mosaic): mosaic two images
	 * Returns a new image.
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical mosaic
	 * @param xref Position of reference tie-point
	 * @param yref Position of reference tie-point
	 * @param xsec Position of secondary tie-point
	 * @param ysec Position of secondary tie-point
	 * @param options optional arguments
	 */
	public native VipsImage mosaic(com.criteo.vips.Image sec, com.criteo.vips.enums.VipsDirection direction, int xref, int yref, int xsec, int ysec, com.criteo.vips.options.MosaicOptions options) throws VipsException;
	
	/**
	 * VipsMosaic (mosaic): mosaic two images
	 * Returns a new image.
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical mosaic
	 * @param xref Position of reference tie-point
	 * @param yref Position of reference tie-point
	 * @param xsec Position of secondary tie-point
	 * @param ysec Position of secondary tie-point
	 */
	public VipsImage mosaic(com.criteo.vips.Image sec, com.criteo.vips.enums.VipsDirection direction, int xref, int yref, int xsec, int ysec) throws VipsException {
		return mosaic(sec, direction, xref, yref, xsec, ysec, null);
	}
	
	/**
	 * VipsMsb (msb): pick most-significant byte from an image
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyMsb(com.criteo.vips.options.MsbOptions options) throws VipsException;
	
	/**
	 * VipsMsb (msb): pick most-significant byte from an image
	 * Mutates the image inplace.
	 */
	public void applyMsb() throws VipsException {
		applyMsb(null);
	}
	
	
	/**
	 * VipsMsb (msb): pick most-significant byte from an image
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage msb(com.criteo.vips.options.MsbOptions options) throws VipsException;
	
	/**
	 * VipsMsb (msb): pick most-significant byte from an image
	 * Returns a new image.
	 */
	public VipsImage msb() throws VipsException {
		return msb(null);
	}
	
	/**
	 * VipsMultiply (multiply): multiply two images
	 * Mutates the image inplace.
	 * @param right Right-hand image argument
	 */
	public native void applyMultiply(com.criteo.vips.Image right) throws VipsException;
	
	
	/**
	 * VipsMultiply (multiply): multiply two images
	 * Returns a new image.
	 * @param right Right-hand image argument
	 */
	public native VipsImage multiply(com.criteo.vips.Image right) throws VipsException;
	
	/**
	 * VipsForeignLoadOpenexr (openexrload): load an OpenEXR image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage openexrLoad(String filename, com.criteo.vips.options.OpenexrLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadOpenexr (openexrload): load an OpenEXR image
	 * @param filename Filename to load from
	 */
	public static VipsImage openexrLoad(String filename) throws VipsException {
		return openexrLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadOpenslideFile (openslideload): load file with OpenSlide
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage openslideLoad(String filename, com.criteo.vips.options.OpenslideLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadOpenslideFile (openslideload): load file with OpenSlide
	 * @param filename Filename to load from
	 */
	public static VipsImage openslideLoad(String filename) throws VipsException {
		return openslideLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadPdfFile (pdfload): load PDF from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage pdfLoad(String filename, com.criteo.vips.options.PDFLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadPdfFile (pdfload): load PDF from file
	 * @param filename Filename to load from
	 */
	public static VipsImage pdfLoad(String filename) throws VipsException {
		return pdfLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadPdfBuffer (pdfload_buffer): load PDF from buffer
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage pdfLoadBuffer(byte[] buffer, com.criteo.vips.options.PDFLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadPdfBuffer (pdfload_buffer): load PDF from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage pdfLoadBuffer(byte[] buffer) throws VipsException {
		return pdfLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsPercent (percent): find threshold for percent of pixels
	 * @param percent Percent of pixels
	 */
	public native int percent(double percent) throws VipsException;
	
	/**
	 * VipsPerlin (perlin): make a perlin noise image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage perlin(int width, int height, com.criteo.vips.options.PerlinOptions options) throws VipsException;
	
	/**
	 * VipsPerlin (perlin): make a perlin noise image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage perlin(int width, int height) throws VipsException {
		return perlin(width, height, null);
	}
	
	/**
	 * VipsPhasecor (phasecor): calculate phase correlation
	 * Mutates the image inplace.
	 * @param in2 Second input image
	 */
	public native void applyPhasecor(com.criteo.vips.Image in2) throws VipsException;
	
	
	/**
	 * VipsPhasecor (phasecor): calculate phase correlation
	 * Returns a new image.
	 * @param in2 Second input image
	 */
	public native VipsImage phasecor(com.criteo.vips.Image in2) throws VipsException;
	
	/**
	 * VipsForeignLoadPngFile (pngload): load png from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage pngLoad(String filename, com.criteo.vips.options.PNGLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadPngFile (pngload): load png from file
	 * @param filename Filename to load from
	 */
	public static VipsImage pngLoad(String filename) throws VipsException {
		return pngLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadPngBuffer (pngload_buffer): load png from buffer
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage pngLoadBuffer(byte[] buffer, com.criteo.vips.options.PNGLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadPngBuffer (pngload_buffer): load png from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage pngLoadBuffer(byte[] buffer) throws VipsException {
		return pngLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveSpngFile (pngsave): save image to file as PNG
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void pngSave(String filename, com.criteo.vips.options.PNGSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveSpngFile (pngsave): save image to file as PNG
	 * @param filename Filename to save to
	 */
	public void pngSave(String filename) throws VipsException {
		pngSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveSpngBuffer (pngsave_buffer): save image to buffer as PNG
	 * @param options optional arguments
	 */
	public native byte[] pngSaveBuffer(com.criteo.vips.options.PNGSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveSpngBuffer (pngsave_buffer): save image to buffer as PNG
	 */
	public byte[] pngSaveBuffer() throws VipsException {
		return pngSaveBuffer(null);
	}
	
	/**
	 * VipsForeignLoadPpmFile (ppmload): load ppm from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage ppmLoad(String filename, com.criteo.vips.options.PPMLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadPpmFile (ppmload): load ppm from file
	 * @param filename Filename to load from
	 */
	public static VipsImage ppmLoad(String filename) throws VipsException {
		return ppmLoad(filename, null);
	}
	
	/**
	 * VipsForeignSavePpmFile (ppmsave): save image to ppm file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void ppmSave(String filename, com.criteo.vips.options.PPMSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSavePpmFile (ppmsave): save image to ppm file
	 * @param filename Filename to save to
	 */
	public void ppmSave(String filename) throws VipsException {
		ppmSave(filename, null);
	}
	
	/**
	 * VipsPremultiply (premultiply): premultiply image alpha
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyPremultiply(com.criteo.vips.options.PremultiplyOptions options) throws VipsException;
	
	/**
	 * VipsPremultiply (premultiply): premultiply image alpha
	 * Mutates the image inplace.
	 */
	public void applyPremultiply() throws VipsException {
		applyPremultiply(null);
	}
	
	
	/**
	 * VipsPremultiply (premultiply): premultiply image alpha
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage premultiply(com.criteo.vips.options.PremultiplyOptions options) throws VipsException;
	
	/**
	 * VipsPremultiply (premultiply): premultiply image alpha
	 * Returns a new image.
	 */
	public VipsImage premultiply() throws VipsException {
		return premultiply(null);
	}
	
	/**
	 * VipsProfileLoad (profile_load): load named ICC profile
	 * @param name Profile name
	 */
	public static native byte[] profileLoad(String name) throws VipsException;
	
	/**
	 * VipsRad2float (rad2float): unpack Radiance coding to float RGB
	 * Mutates the image inplace.
	 */
	public native void applyRad2float() throws VipsException;
	
	
	/**
	 * VipsRad2float (rad2float): unpack Radiance coding to float RGB
	 * Returns a new image.
	 */
	public native VipsImage rad2float() throws VipsException;
	
	/**
	 * VipsForeignLoadRadFile (radload): load a Radiance image from a file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage radLoad(String filename, com.criteo.vips.options.RadLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadRadFile (radload): load a Radiance image from a file
	 * @param filename Filename to load from
	 */
	public static VipsImage radLoad(String filename) throws VipsException {
		return radLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadRadBuffer (radload_buffer): load rad from buffer
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage radLoadBuffer(byte[] buffer, com.criteo.vips.options.RadLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadRadBuffer (radload_buffer): load rad from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage radLoadBuffer(byte[] buffer) throws VipsException {
		return radLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveRadFile (radsave): save image to Radiance file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void radSave(String filename, com.criteo.vips.options.RadSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveRadFile (radsave): save image to Radiance file
	 * @param filename Filename to save to
	 */
	public void radSave(String filename) throws VipsException {
		radSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveRadBuffer (radsave_buffer): save image to Radiance buffer
	 * @param options optional arguments
	 */
	public native byte[] radSaveBuffer(com.criteo.vips.options.RadSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveRadBuffer (radsave_buffer): save image to Radiance buffer
	 */
	public byte[] radSaveBuffer() throws VipsException {
		return radSaveBuffer(null);
	}
	
	/**
	 * VipsRank (rank): rank filter
	 * Mutates the image inplace.
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 * @param index Select pixel at index
	 */
	public native void applyRank(int width, int height, int index) throws VipsException;
	
	
	/**
	 * VipsRank (rank): rank filter
	 * Returns a new image.
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 * @param index Select pixel at index
	 */
	public native VipsImage rank(int width, int height, int index) throws VipsException;
	
	/**
	 * VipsForeignLoadRaw (rawload): load raw data from a file
	 * @param filename Filename to load from
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param bands Number of bands in image
	 * @param options optional arguments
	 */
	public static native VipsImage rawLoad(String filename, int width, int height, int bands, com.criteo.vips.options.RawLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadRaw (rawload): load raw data from a file
	 * @param filename Filename to load from
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param bands Number of bands in image
	 */
	public static VipsImage rawLoad(String filename, int width, int height, int bands) throws VipsException {
		return rawLoad(filename, width, height, bands, null);
	}
	
	/**
	 * VipsForeignSaveRaw (rawsave): save image to raw file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void rawSave(String filename, com.criteo.vips.options.RawSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveRaw (rawsave): save image to raw file
	 * @param filename Filename to save to
	 */
	public void rawSave(String filename) throws VipsException {
		rawSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveRawFd (rawsave_fd): write raw image to file descriptor
	 * @param fd File descriptor to write to
	 * @param options optional arguments
	 */
	public native void rawSaveFd(int fd, com.criteo.vips.options.RawSaveFdOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveRawFd (rawsave_fd): write raw image to file descriptor
	 * @param fd File descriptor to write to
	 */
	public void rawSaveFd(int fd) throws VipsException {
		rawSaveFd(fd, null);
	}
	
	/**
	 * VipsRecomb (recomb): linear recombination with matrix
	 * Mutates the image inplace.
	 * @param m Matrix of coefficients
	 */
	public native void applyRecomb(com.criteo.vips.Image m) throws VipsException;
	
	
	/**
	 * VipsRecomb (recomb): linear recombination with matrix
	 * Returns a new image.
	 * @param m Matrix of coefficients
	 */
	public native VipsImage recomb(com.criteo.vips.Image m) throws VipsException;
	
	/**
	 * VipsReduce (reduce): reduce an image
	 * Mutates the image inplace.
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 * @param options optional arguments
	 */
	public native void applyReduce(double hshrink, double vshrink, com.criteo.vips.options.ReduceOptions options) throws VipsException;
	
	/**
	 * VipsReduce (reduce): reduce an image
	 * Mutates the image inplace.
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 */
	public void applyReduce(double hshrink, double vshrink) throws VipsException {
		applyReduce(hshrink, vshrink, null);
	}
	
	
	/**
	 * VipsReduce (reduce): reduce an image
	 * Returns a new image.
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 * @param options optional arguments
	 */
	public native VipsImage reduce(double hshrink, double vshrink, com.criteo.vips.options.ReduceOptions options) throws VipsException;
	
	/**
	 * VipsReduce (reduce): reduce an image
	 * Returns a new image.
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 */
	public VipsImage reduce(double hshrink, double vshrink) throws VipsException {
		return reduce(hshrink, vshrink, null);
	}
	
	/**
	 * VipsReduceh (reduceh): shrink an image horizontally
	 * Mutates the image inplace.
	 * @param hshrink Horizontal shrink factor
	 * @param options optional arguments
	 */
	public native void applyReduceh(double hshrink, com.criteo.vips.options.ReducehOptions options) throws VipsException;
	
	/**
	 * VipsReduceh (reduceh): shrink an image horizontally
	 * Mutates the image inplace.
	 * @param hshrink Horizontal shrink factor
	 */
	public void applyReduceh(double hshrink) throws VipsException {
		applyReduceh(hshrink, null);
	}
	
	
	/**
	 * VipsReduceh (reduceh): shrink an image horizontally
	 * Returns a new image.
	 * @param hshrink Horizontal shrink factor
	 * @param options optional arguments
	 */
	public native VipsImage reduceh(double hshrink, com.criteo.vips.options.ReducehOptions options) throws VipsException;
	
	/**
	 * VipsReduceh (reduceh): shrink an image horizontally
	 * Returns a new image.
	 * @param hshrink Horizontal shrink factor
	 */
	public VipsImage reduceh(double hshrink) throws VipsException {
		return reduceh(hshrink, null);
	}
	
	/**
	 * VipsReducev (reducev): shrink an image vertically
	 * Mutates the image inplace.
	 * @param vshrink Vertical shrink factor
	 * @param options optional arguments
	 */
	public native void applyReducev(double vshrink, com.criteo.vips.options.ReducevOptions options) throws VipsException;
	
	/**
	 * VipsReducev (reducev): shrink an image vertically
	 * Mutates the image inplace.
	 * @param vshrink Vertical shrink factor
	 */
	public void applyReducev(double vshrink) throws VipsException {
		applyReducev(vshrink, null);
	}
	
	
	/**
	 * VipsReducev (reducev): shrink an image vertically
	 * Returns a new image.
	 * @param vshrink Vertical shrink factor
	 * @param options optional arguments
	 */
	public native VipsImage reducev(double vshrink, com.criteo.vips.options.ReducevOptions options) throws VipsException;
	
	/**
	 * VipsReducev (reducev): shrink an image vertically
	 * Returns a new image.
	 * @param vshrink Vertical shrink factor
	 */
	public VipsImage reducev(double vshrink) throws VipsException {
		return reducev(vshrink, null);
	}
	
	/**
	 * VipsRelational (relational): relational operation on two images
	 * Mutates the image inplace.
	 * @param right Right-hand image argument
	 * @param relational Relational to perform
	 */
	public native void applyRelational(com.criteo.vips.Image right, com.criteo.vips.enums.VipsOperationRelational relational) throws VipsException;
	
	
	/**
	 * VipsRelational (relational): relational operation on two images
	 * Returns a new image.
	 * @param right Right-hand image argument
	 * @param relational Relational to perform
	 */
	public native VipsImage relational(com.criteo.vips.Image right, com.criteo.vips.enums.VipsOperationRelational relational) throws VipsException;
	
	/**
	 * VipsRelationalConst (relational_const): relational operations against a constant
	 * Mutates the image inplace.
	 * @param relational Relational to perform
	 * @param c Array of constants
	 */
	public native void applyRelationalConst(com.criteo.vips.enums.VipsOperationRelational relational, double[] c) throws VipsException;
	
	
	/**
	 * VipsRelationalConst (relational_const): relational operations against a constant
	 * Returns a new image.
	 * @param relational Relational to perform
	 * @param c Array of constants
	 */
	public native VipsImage relationalConst(com.criteo.vips.enums.VipsOperationRelational relational, double[] c) throws VipsException;
	
	/**
	 * VipsRemainder (remainder): remainder after integer division of two images
	 * Mutates the image inplace.
	 * @param right Right-hand image argument
	 */
	public native void applyRemainder(com.criteo.vips.Image right) throws VipsException;
	
	
	/**
	 * VipsRemainder (remainder): remainder after integer division of two images
	 * Returns a new image.
	 * @param right Right-hand image argument
	 */
	public native VipsImage remainder(com.criteo.vips.Image right) throws VipsException;
	
	/**
	 * VipsRemainderConst (remainder_const): remainder after integer division of an image and a constant
	 * Mutates the image inplace.
	 * @param c Array of constants
	 */
	public native void applyRemainderConst(double[] c) throws VipsException;
	
	
	/**
	 * VipsRemainderConst (remainder_const): remainder after integer division of an image and a constant
	 * Returns a new image.
	 * @param c Array of constants
	 */
	public native VipsImage remainderConst(double[] c) throws VipsException;
	
	/**
	 * VipsReplicate (replicate): replicate an image
	 * Mutates the image inplace.
	 * @param across Repeat this many times horizontally
	 * @param down Repeat this many times vertically
	 */
	public native void applyReplicate(int across, int down) throws VipsException;
	
	
	/**
	 * VipsReplicate (replicate): replicate an image
	 * Returns a new image.
	 * @param across Repeat this many times horizontally
	 * @param down Repeat this many times vertically
	 */
	public native VipsImage replicate(int across, int down) throws VipsException;
	
	/**
	 * VipsResize (resize): resize an image
	 * Mutates the image inplace.
	 * @param scale Scale image by this factor
	 * @param options optional arguments
	 */
	public native void applyResize(double scale, com.criteo.vips.options.ResizeOptions options) throws VipsException;
	
	/**
	 * VipsResize (resize): resize an image
	 * Mutates the image inplace.
	 * @param scale Scale image by this factor
	 */
	public void applyResize(double scale) throws VipsException {
		applyResize(scale, null);
	}
	
	
	/**
	 * VipsResize (resize): resize an image
	 * Returns a new image.
	 * @param scale Scale image by this factor
	 * @param options optional arguments
	 */
	public native VipsImage resize(double scale, com.criteo.vips.options.ResizeOptions options) throws VipsException;
	
	/**
	 * VipsResize (resize): resize an image
	 * Returns a new image.
	 * @param scale Scale image by this factor
	 */
	public VipsImage resize(double scale) throws VipsException {
		return resize(scale, null);
	}
	
	/**
	 * VipsRot (rot): rotate an image
	 * Mutates the image inplace.
	 * @param angle Angle to rotate image
	 */
	public native void applyRot(com.criteo.vips.enums.VipsAngle angle) throws VipsException;
	
	
	/**
	 * VipsRot (rot): rotate an image
	 * Returns a new image.
	 * @param angle Angle to rotate image
	 */
	public native VipsImage rot(com.criteo.vips.enums.VipsAngle angle) throws VipsException;
	
	/**
	 * VipsRot45 (rot45): rotate an image
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyRot45(com.criteo.vips.options.Rot45Options options) throws VipsException;
	
	/**
	 * VipsRot45 (rot45): rotate an image
	 * Mutates the image inplace.
	 */
	public void applyRot45() throws VipsException {
		applyRot45(null);
	}
	
	
	/**
	 * VipsRot45 (rot45): rotate an image
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage rot45(com.criteo.vips.options.Rot45Options options) throws VipsException;
	
	/**
	 * VipsRot45 (rot45): rotate an image
	 * Returns a new image.
	 */
	public VipsImage rot45() throws VipsException {
		return rot45(null);
	}
	
	/**
	 * VipsRound (round): perform a round function on an image
	 * Mutates the image inplace.
	 * @param round Rounding operation to perform
	 */
	public native void applyRound(com.criteo.vips.enums.VipsOperationRound round) throws VipsException;
	
	
	/**
	 * VipsRound (round): perform a round function on an image
	 * Returns a new image.
	 * @param round Rounding operation to perform
	 */
	public native VipsImage round(com.criteo.vips.enums.VipsOperationRound round) throws VipsException;
	
	/**
	 * VipsScale (scale): scale an image to uchar
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyScale(com.criteo.vips.options.ScaleOptions options) throws VipsException;
	
	/**
	 * VipsScale (scale): scale an image to uchar
	 * Mutates the image inplace.
	 */
	public void applyScale() throws VipsException {
		applyScale(null);
	}
	
	
	/**
	 * VipsScale (scale): scale an image to uchar
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage scale(com.criteo.vips.options.ScaleOptions options) throws VipsException;
	
	/**
	 * VipsScale (scale): scale an image to uchar
	 * Returns a new image.
	 */
	public VipsImage scale() throws VipsException {
		return scale(null);
	}
	
	/**
	 * VipsscRGB2BW (scRGB2BW): convert scRGB to BW
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyScRGB2BW(com.criteo.vips.options.ScRGB2BWOptions options) throws VipsException;
	
	/**
	 * VipsscRGB2BW (scRGB2BW): convert scRGB to BW
	 * Mutates the image inplace.
	 */
	public void applyScRGB2BW() throws VipsException {
		applyScRGB2BW(null);
	}
	
	
	/**
	 * VipsscRGB2BW (scRGB2BW): convert scRGB to BW
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage scRGB2BW(com.criteo.vips.options.ScRGB2BWOptions options) throws VipsException;
	
	/**
	 * VipsscRGB2BW (scRGB2BW): convert scRGB to BW
	 * Returns a new image.
	 */
	public VipsImage scRGB2BW() throws VipsException {
		return scRGB2BW(null);
	}
	
	/**
	 * VipsscRGB2sRGB (scRGB2sRGB): convert an scRGB image to sRGB
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyScRGB2sRGB(com.criteo.vips.options.ScRGB2sRGBOptions options) throws VipsException;
	
	/**
	 * VipsscRGB2sRGB (scRGB2sRGB): convert an scRGB image to sRGB
	 * Mutates the image inplace.
	 */
	public void applyScRGB2sRGB() throws VipsException {
		applyScRGB2sRGB(null);
	}
	
	
	/**
	 * VipsscRGB2sRGB (scRGB2sRGB): convert an scRGB image to sRGB
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage scRGB2sRGB(com.criteo.vips.options.ScRGB2sRGBOptions options) throws VipsException;
	
	/**
	 * VipsscRGB2sRGB (scRGB2sRGB): convert an scRGB image to sRGB
	 * Returns a new image.
	 */
	public VipsImage scRGB2sRGB() throws VipsException {
		return scRGB2sRGB(null);
	}
	
	/**
	 * VipsscRGB2XYZ (scRGB2XYZ): transform scRGB to XYZ
	 * Mutates the image inplace.
	 */
	public native void applyScRGB2XYZ() throws VipsException;
	
	
	/**
	 * VipsscRGB2XYZ (scRGB2XYZ): transform scRGB to XYZ
	 * Returns a new image.
	 */
	public native VipsImage scRGB2XYZ() throws VipsException;
	
	/**
	 * VipsSequential (sequential): check sequential access
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applySequential(com.criteo.vips.options.SequentialOptions options) throws VipsException;
	
	/**
	 * VipsSequential (sequential): check sequential access
	 * Mutates the image inplace.
	 */
	public void applySequential() throws VipsException {
		applySequential(null);
	}
	
	
	/**
	 * VipsSequential (sequential): check sequential access
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage sequential(com.criteo.vips.options.SequentialOptions options) throws VipsException;
	
	/**
	 * VipsSequential (sequential): check sequential access
	 * Returns a new image.
	 */
	public VipsImage sequential() throws VipsException {
		return sequential(null);
	}
	
	/**
	 * VipsSharpen (sharpen): unsharp masking for print
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applySharpen(com.criteo.vips.options.SharpenOptions options) throws VipsException;
	
	/**
	 * VipsSharpen (sharpen): unsharp masking for print
	 * Mutates the image inplace.
	 */
	public void applySharpen() throws VipsException {
		applySharpen(null);
	}
	
	
	/**
	 * VipsSharpen (sharpen): unsharp masking for print
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage sharpen(com.criteo.vips.options.SharpenOptions options) throws VipsException;
	
	/**
	 * VipsSharpen (sharpen): unsharp masking for print
	 * Returns a new image.
	 */
	public VipsImage sharpen() throws VipsException {
		return sharpen(null);
	}
	
	/**
	 * VipsShrink (shrink): shrink an image
	 * Mutates the image inplace.
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 * @param options optional arguments
	 */
	public native void applyShrink(double hshrink, double vshrink, com.criteo.vips.options.ShrinkOptions options) throws VipsException;
	
	/**
	 * VipsShrink (shrink): shrink an image
	 * Mutates the image inplace.
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 */
	public void applyShrink(double hshrink, double vshrink) throws VipsException {
		applyShrink(hshrink, vshrink, null);
	}
	
	
	/**
	 * VipsShrink (shrink): shrink an image
	 * Returns a new image.
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 * @param options optional arguments
	 */
	public native VipsImage shrink(double hshrink, double vshrink, com.criteo.vips.options.ShrinkOptions options) throws VipsException;
	
	/**
	 * VipsShrink (shrink): shrink an image
	 * Returns a new image.
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 */
	public VipsImage shrink(double hshrink, double vshrink) throws VipsException {
		return shrink(hshrink, vshrink, null);
	}
	
	/**
	 * VipsShrinkh (shrinkh): shrink an image horizontally
	 * Mutates the image inplace.
	 * @param hshrink Horizontal shrink factor
	 * @param options optional arguments
	 */
	public native void applyShrinkh(int hshrink, com.criteo.vips.options.ShrinkhOptions options) throws VipsException;
	
	/**
	 * VipsShrinkh (shrinkh): shrink an image horizontally
	 * Mutates the image inplace.
	 * @param hshrink Horizontal shrink factor
	 */
	public void applyShrinkh(int hshrink) throws VipsException {
		applyShrinkh(hshrink, null);
	}
	
	
	/**
	 * VipsShrinkh (shrinkh): shrink an image horizontally
	 * Returns a new image.
	 * @param hshrink Horizontal shrink factor
	 * @param options optional arguments
	 */
	public native VipsImage shrinkh(int hshrink, com.criteo.vips.options.ShrinkhOptions options) throws VipsException;
	
	/**
	 * VipsShrinkh (shrinkh): shrink an image horizontally
	 * Returns a new image.
	 * @param hshrink Horizontal shrink factor
	 */
	public VipsImage shrinkh(int hshrink) throws VipsException {
		return shrinkh(hshrink, null);
	}
	
	/**
	 * VipsShrinkv (shrinkv): shrink an image vertically
	 * Mutates the image inplace.
	 * @param vshrink Vertical shrink factor
	 * @param options optional arguments
	 */
	public native void applyShrinkv(int vshrink, com.criteo.vips.options.ShrinkvOptions options) throws VipsException;
	
	/**
	 * VipsShrinkv (shrinkv): shrink an image vertically
	 * Mutates the image inplace.
	 * @param vshrink Vertical shrink factor
	 */
	public void applyShrinkv(int vshrink) throws VipsException {
		applyShrinkv(vshrink, null);
	}
	
	
	/**
	 * VipsShrinkv (shrinkv): shrink an image vertically
	 * Returns a new image.
	 * @param vshrink Vertical shrink factor
	 * @param options optional arguments
	 */
	public native VipsImage shrinkv(int vshrink, com.criteo.vips.options.ShrinkvOptions options) throws VipsException;
	
	/**
	 * VipsShrinkv (shrinkv): shrink an image vertically
	 * Returns a new image.
	 * @param vshrink Vertical shrink factor
	 */
	public VipsImage shrinkv(int vshrink) throws VipsException {
		return shrinkv(vshrink, null);
	}
	
	/**
	 * VipsSign (sign): unit vector of pixel
	 * Mutates the image inplace.
	 */
	public native void applySign() throws VipsException;
	
	
	/**
	 * VipsSign (sign): unit vector of pixel
	 * Returns a new image.
	 */
	public native VipsImage sign() throws VipsException;
	
	/**
	 * VipsSines (sines): make a 2D sine wave
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage sines(int width, int height, com.criteo.vips.options.SinesOptions options) throws VipsException;
	
	/**
	 * VipsSines (sines): make a 2D sine wave
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage sines(int width, int height) throws VipsException {
		return sines(width, height, null);
	}
	
	/**
	 * VipsSmartcrop (smartcrop): extract an area from an image
	 * Mutates the image inplace.
	 * @param width Width of extract area
	 * @param height Height of extract area
	 * @param options optional arguments
	 */
	public native void applySmartcrop(int width, int height, com.criteo.vips.options.SmartcropOptions options) throws VipsException;
	
	/**
	 * VipsSmartcrop (smartcrop): extract an area from an image
	 * Mutates the image inplace.
	 * @param width Width of extract area
	 * @param height Height of extract area
	 */
	public void applySmartcrop(int width, int height) throws VipsException {
		applySmartcrop(width, height, null);
	}
	
	
	/**
	 * VipsSmartcrop (smartcrop): extract an area from an image
	 * Returns a new image.
	 * @param width Width of extract area
	 * @param height Height of extract area
	 * @param options optional arguments
	 */
	public native VipsImage smartcrop(int width, int height, com.criteo.vips.options.SmartcropOptions options) throws VipsException;
	
	/**
	 * VipsSmartcrop (smartcrop): extract an area from an image
	 * Returns a new image.
	 * @param width Width of extract area
	 * @param height Height of extract area
	 */
	public VipsImage smartcrop(int width, int height) throws VipsException {
		return smartcrop(width, height, null);
	}
	
	/**
	 * VipsSobel (sobel): Sobel edge detector
	 * Mutates the image inplace.
	 */
	public native void applySobel() throws VipsException;
	
	
	/**
	 * VipsSobel (sobel): Sobel edge detector
	 * Returns a new image.
	 */
	public native VipsImage sobel() throws VipsException;
	
	/**
	 * VipsSpcor (spcor): spatial correlation
	 * Mutates the image inplace.
	 * @param ref Input reference image
	 */
	public native void applySpcor(com.criteo.vips.Image ref) throws VipsException;
	
	
	/**
	 * VipsSpcor (spcor): spatial correlation
	 * Returns a new image.
	 * @param ref Input reference image
	 */
	public native VipsImage spcor(com.criteo.vips.Image ref) throws VipsException;
	
	/**
	 * VipsSpectrum (spectrum): make displayable power spectrum
	 * Mutates the image inplace.
	 */
	public native void applySpectrum() throws VipsException;
	
	
	/**
	 * VipsSpectrum (spectrum): make displayable power spectrum
	 * Returns a new image.
	 */
	public native VipsImage spectrum() throws VipsException;
	
	/**
	 * VipssRGB2HSV (sRGB2HSV): transform sRGB to HSV
	 * Mutates the image inplace.
	 */
	public native void applySRGB2HSV() throws VipsException;
	
	
	/**
	 * VipssRGB2HSV (sRGB2HSV): transform sRGB to HSV
	 * Returns a new image.
	 */
	public native VipsImage sRGB2HSV() throws VipsException;
	
	/**
	 * VipssRGB2scRGB (sRGB2scRGB): convert an sRGB image to scRGB
	 * Mutates the image inplace.
	 */
	public native void applySRGB2scRGB() throws VipsException;
	
	
	/**
	 * VipssRGB2scRGB (sRGB2scRGB): convert an sRGB image to scRGB
	 * Returns a new image.
	 */
	public native VipsImage sRGB2scRGB() throws VipsException;
	
	/**
	 * VipsStats (stats): find many image stats
	 * Mutates the image inplace.
	 */
	public native void applyStats() throws VipsException;
	
	
	/**
	 * VipsStats (stats): find many image stats
	 * Returns a new image.
	 */
	public native VipsImage stats() throws VipsException;
	
	/**
	 * VipsStdif (stdif): statistical difference
	 * Mutates the image inplace.
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 * @param options optional arguments
	 */
	public native void applyStdif(int width, int height, com.criteo.vips.options.StdifOptions options) throws VipsException;
	
	/**
	 * VipsStdif (stdif): statistical difference
	 * Mutates the image inplace.
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 */
	public void applyStdif(int width, int height) throws VipsException {
		applyStdif(width, height, null);
	}
	
	
	/**
	 * VipsStdif (stdif): statistical difference
	 * Returns a new image.
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 * @param options optional arguments
	 */
	public native VipsImage stdif(int width, int height, com.criteo.vips.options.StdifOptions options) throws VipsException;
	
	/**
	 * VipsStdif (stdif): statistical difference
	 * Returns a new image.
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 */
	public VipsImage stdif(int width, int height) throws VipsException {
		return stdif(width, height, null);
	}
	
	/**
	 * VipsSubsample (subsample): subsample an image
	 * Mutates the image inplace.
	 * @param xfac Horizontal subsample factor
	 * @param yfac Vertical subsample factor
	 * @param options optional arguments
	 */
	public native void applySubsample(int xfac, int yfac, com.criteo.vips.options.SubsampleOptions options) throws VipsException;
	
	/**
	 * VipsSubsample (subsample): subsample an image
	 * Mutates the image inplace.
	 * @param xfac Horizontal subsample factor
	 * @param yfac Vertical subsample factor
	 */
	public void applySubsample(int xfac, int yfac) throws VipsException {
		applySubsample(xfac, yfac, null);
	}
	
	
	/**
	 * VipsSubsample (subsample): subsample an image
	 * Returns a new image.
	 * @param xfac Horizontal subsample factor
	 * @param yfac Vertical subsample factor
	 * @param options optional arguments
	 */
	public native VipsImage subsample(int xfac, int yfac, com.criteo.vips.options.SubsampleOptions options) throws VipsException;
	
	/**
	 * VipsSubsample (subsample): subsample an image
	 * Returns a new image.
	 * @param xfac Horizontal subsample factor
	 * @param yfac Vertical subsample factor
	 */
	public VipsImage subsample(int xfac, int yfac) throws VipsException {
		return subsample(xfac, yfac, null);
	}
	
	/**
	 * VipsSubtract (subtract): subtract two images
	 * Mutates the image inplace.
	 * @param right Right-hand image argument
	 */
	public native void applySubtract(com.criteo.vips.Image right) throws VipsException;
	
	
	/**
	 * VipsSubtract (subtract): subtract two images
	 * Returns a new image.
	 * @param right Right-hand image argument
	 */
	public native VipsImage subtract(com.criteo.vips.Image right) throws VipsException;
	
	/**
	 * VipsSum (sum): sum an array of images
	 * @param in Array of input images
	 */
	public static native VipsImage sum(com.criteo.vips.Image[] in) throws VipsException;
	
	/**
	 * VipsForeignLoadSvgFile (svgload): load SVG with rsvg
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage svgLoad(String filename, com.criteo.vips.options.SvgLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadSvgFile (svgload): load SVG with rsvg
	 * @param filename Filename to load from
	 */
	public static VipsImage svgLoad(String filename) throws VipsException {
		return svgLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadSvgBuffer (svgload_buffer): load SVG with rsvg
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage svgLoadBuffer(byte[] buffer, com.criteo.vips.options.SvgLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadSvgBuffer (svgload_buffer): load SVG with rsvg
	 * @param buffer Buffer to load from
	 */
	public static VipsImage svgLoadBuffer(byte[] buffer) throws VipsException {
		return svgLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsSwitch (switch): find the index of the first non-zero pixel in tests
	 * @param tests Table of images to test
	 */
	public static native VipsImage switchOp(com.criteo.vips.Image[] tests) throws VipsException;
	
	/**
	 * VipsSystem (system): run an external command
	 * @param cmdFormat Command to run
	 * @param options optional arguments
	 */
	public static native void system(String cmdFormat, com.criteo.vips.options.SystemOptions options) throws VipsException;
	
	/**
	 * VipsSystem (system): run an external command
	 * @param cmdFormat Command to run
	 */
	public static void system(String cmdFormat) throws VipsException {
		system(cmdFormat, null);
	}
	
	/**
	 * VipsText (text): make a text image
	 * @param text Text to render
	 * @param options optional arguments
	 */
	public static native VipsImage text(String text, com.criteo.vips.options.TextOptions options) throws VipsException;
	
	/**
	 * VipsText (text): make a text image
	 * @param text Text to render
	 */
	public static VipsImage text(String text) throws VipsException {
		return text(text, null);
	}
	
	/**
	 * VipsThumbnailFile (thumbnail): generate thumbnail from file
	 * @param filename Filename to read from
	 * @param width Size to this width
	 * @param options optional arguments
	 */
	public static native VipsImage thumbnail(String filename, int width, com.criteo.vips.options.ThumbnailOptions options) throws VipsException;
	
	/**
	 * VipsThumbnailFile (thumbnail): generate thumbnail from file
	 * @param filename Filename to read from
	 * @param width Size to this width
	 */
	public static VipsImage thumbnail(String filename, int width) throws VipsException {
		return thumbnail(filename, width, null);
	}
	
	/**
	 * VipsThumbnailBuffer (thumbnail_buffer): generate thumbnail from buffer
	 * @param buffer Buffer to load from
	 * @param width Size to this width
	 * @param options optional arguments
	 */
	public static native VipsImage thumbnailBuffer(byte[] buffer, int width, com.criteo.vips.options.ThumbnailBufferOptions options) throws VipsException;
	
	/**
	 * VipsThumbnailBuffer (thumbnail_buffer): generate thumbnail from buffer
	 * @param buffer Buffer to load from
	 * @param width Size to this width
	 */
	public static VipsImage thumbnailBuffer(byte[] buffer, int width) throws VipsException {
		return thumbnailBuffer(buffer, width, null);
	}
	
	/**
	 * VipsThumbnailImage (thumbnail_image): generate thumbnail from image
	 * Mutates the image inplace.
	 * @param width Size to this width
	 * @param options optional arguments
	 */
	public native void applyThumbnailImage(int width, com.criteo.vips.options.ThumbnailImageOptions options) throws VipsException;
	
	/**
	 * VipsThumbnailImage (thumbnail_image): generate thumbnail from image
	 * Mutates the image inplace.
	 * @param width Size to this width
	 */
	public void applyThumbnailImage(int width) throws VipsException {
		applyThumbnailImage(width, null);
	}
	
	
	/**
	 * VipsThumbnailImage (thumbnail_image): generate thumbnail from image
	 * Returns a new image.
	 * @param width Size to this width
	 * @param options optional arguments
	 */
	public native VipsImage thumbnailImage(int width, com.criteo.vips.options.ThumbnailImageOptions options) throws VipsException;
	
	/**
	 * VipsThumbnailImage (thumbnail_image): generate thumbnail from image
	 * Returns a new image.
	 * @param width Size to this width
	 */
	public VipsImage thumbnailImage(int width) throws VipsException {
		return thumbnailImage(width, null);
	}
	
	/**
	 * VipsForeignLoadTiffFile (tiffload): load tiff from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage tiffLoad(String filename, com.criteo.vips.options.TIFFLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadTiffFile (tiffload): load tiff from file
	 * @param filename Filename to load from
	 */
	public static VipsImage tiffLoad(String filename) throws VipsException {
		return tiffLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadTiffBuffer (tiffload_buffer): load tiff from buffer
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage tiffLoadBuffer(byte[] buffer, com.criteo.vips.options.TIFFLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadTiffBuffer (tiffload_buffer): load tiff from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage tiffLoadBuffer(byte[] buffer) throws VipsException {
		return tiffLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveTiffFile (tiffsave): save image to tiff file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void tiffSave(String filename, com.criteo.vips.options.TIFFSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveTiffFile (tiffsave): save image to tiff file
	 * @param filename Filename to save to
	 */
	public void tiffSave(String filename) throws VipsException {
		tiffSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveTiffBuffer (tiffsave_buffer): save image to tiff buffer
	 * @param options optional arguments
	 */
	public native byte[] tiffSaveBuffer(com.criteo.vips.options.TIFFSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveTiffBuffer (tiffsave_buffer): save image to tiff buffer
	 */
	public byte[] tiffSaveBuffer() throws VipsException {
		return tiffSaveBuffer(null);
	}
	
	/**
	 * VipsTileCache (tilecache): cache an image as a set of tiles
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyTilecache(com.criteo.vips.options.TilecacheOptions options) throws VipsException;
	
	/**
	 * VipsTileCache (tilecache): cache an image as a set of tiles
	 * Mutates the image inplace.
	 */
	public void applyTilecache() throws VipsException {
		applyTilecache(null);
	}
	
	
	/**
	 * VipsTileCache (tilecache): cache an image as a set of tiles
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage tilecache(com.criteo.vips.options.TilecacheOptions options) throws VipsException;
	
	/**
	 * VipsTileCache (tilecache): cache an image as a set of tiles
	 * Returns a new image.
	 */
	public VipsImage tilecache() throws VipsException {
		return tilecache(null);
	}
	
	/**
	 * VipsTonelut (tonelut): build a look-up table
	 * @param options optional arguments
	 */
	public static native VipsImage tonelut(com.criteo.vips.options.ToneLUTOptions options) throws VipsException;
	
	/**
	 * VipsTonelut (tonelut): build a look-up table
	 */
	public static VipsImage tonelut() throws VipsException {
		return tonelut(null);
	}
	
	/**
	 * VipsTranspose3d (transpose3d): transpose3d an image
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyTranspose3d(com.criteo.vips.options.Transpose3dOptions options) throws VipsException;
	
	/**
	 * VipsTranspose3d (transpose3d): transpose3d an image
	 * Mutates the image inplace.
	 */
	public void applyTranspose3d() throws VipsException {
		applyTranspose3d(null);
	}
	
	
	/**
	 * VipsTranspose3d (transpose3d): transpose3d an image
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage transpose3d(com.criteo.vips.options.Transpose3dOptions options) throws VipsException;
	
	/**
	 * VipsTranspose3d (transpose3d): transpose3d an image
	 * Returns a new image.
	 */
	public VipsImage transpose3d() throws VipsException {
		return transpose3d(null);
	}
	
	/**
	 * VipsUnpremultiply (unpremultiply): unpremultiply image alpha
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyUnpremultiply(com.criteo.vips.options.UnpremultiplyOptions options) throws VipsException;
	
	/**
	 * VipsUnpremultiply (unpremultiply): unpremultiply image alpha
	 * Mutates the image inplace.
	 */
	public void applyUnpremultiply() throws VipsException {
		applyUnpremultiply(null);
	}
	
	
	/**
	 * VipsUnpremultiply (unpremultiply): unpremultiply image alpha
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage unpremultiply(com.criteo.vips.options.UnpremultiplyOptions options) throws VipsException;
	
	/**
	 * VipsUnpremultiply (unpremultiply): unpremultiply image alpha
	 * Returns a new image.
	 */
	public VipsImage unpremultiply() throws VipsException {
		return unpremultiply(null);
	}
	
	/**
	 * VipsForeignLoadVipsFile (vipsload): load vips from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage vipsLoad(String filename, com.criteo.vips.options.VipsLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadVipsFile (vipsload): load vips from file
	 * @param filename Filename to load from
	 */
	public static VipsImage vipsLoad(String filename) throws VipsException {
		return vipsLoad(filename, null);
	}
	
	/**
	 * VipsForeignSaveVipsFile (vipssave): save image to file in vips format
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void vipsSave(String filename, com.criteo.vips.options.VipsSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveVipsFile (vipssave): save image to file in vips format
	 * @param filename Filename to save to
	 */
	public void vipsSave(String filename) throws VipsException {
		vipsSave(filename, null);
	}
	
	/**
	 * VipsForeignLoadWebpFile (webpload): load webp from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage webpLoad(String filename, com.criteo.vips.options.WebpLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadWebpFile (webpload): load webp from file
	 * @param filename Filename to load from
	 */
	public static VipsImage webpLoad(String filename) throws VipsException {
		return webpLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadWebpBuffer (webpload_buffer): load webp from buffer
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage webpLoadBuffer(byte[] buffer, com.criteo.vips.options.WebpLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadWebpBuffer (webpload_buffer): load webp from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage webpLoadBuffer(byte[] buffer) throws VipsException {
		return webpLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveWebpFile (webpsave): save as WebP
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void webpSave(String filename, com.criteo.vips.options.WebpSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveWebpFile (webpsave): save as WebP
	 * @param filename Filename to save to
	 */
	public void webpSave(String filename) throws VipsException {
		webpSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveWebpBuffer (webpsave_buffer): save as WebP
	 * @param options optional arguments
	 */
	public native byte[] webpSaveBuffer(com.criteo.vips.options.WebpSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveWebpBuffer (webpsave_buffer): save as WebP
	 */
	public byte[] webpSaveBuffer() throws VipsException {
		return webpSaveBuffer(null);
	}
	
	/**
	 * VipsForeignSaveWebpMime (webpsave_mime): save image to webp mime
	 * @param options optional arguments
	 */
	public native void webpSaveMime(com.criteo.vips.options.WebpSaveMimeOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveWebpMime (webpsave_mime): save image to webp mime
	 */
	public void webpSaveMime() throws VipsException {
		webpSaveMime(null);
	}
	
	/**
	 * VipsWorley (worley): make a worley noise image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage worley(int width, int height, com.criteo.vips.options.WorleyOptions options) throws VipsException;
	
	/**
	 * VipsWorley (worley): make a worley noise image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage worley(int width, int height) throws VipsException {
		return worley(width, height, null);
	}
	
	/**
	 * VipsWrap (wrap): wrap image origin
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyWrap(com.criteo.vips.options.WrapOptions options) throws VipsException;
	
	/**
	 * VipsWrap (wrap): wrap image origin
	 * Mutates the image inplace.
	 */
	public void applyWrap() throws VipsException {
		applyWrap(null);
	}
	
	
	/**
	 * VipsWrap (wrap): wrap image origin
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage wrap(com.criteo.vips.options.WrapOptions options) throws VipsException;
	
	/**
	 * VipsWrap (wrap): wrap image origin
	 * Returns a new image.
	 */
	public VipsImage wrap() throws VipsException {
		return wrap(null);
	}
	
	/**
	 * VipsXyz (xyz): make an image where pixel values are coordinates
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage xyz(int width, int height, com.criteo.vips.options.XYZOptions options) throws VipsException;
	
	/**
	 * VipsXyz (xyz): make an image where pixel values are coordinates
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage xyz(int width, int height) throws VipsException {
		return xyz(width, height, null);
	}
	
	/**
	 * VipsXYZ2CMYK (XYZ2CMYK): transform XYZ to CMYK
	 * Mutates the image inplace.
	 */
	public native void applyXYZ2CMYK() throws VipsException;
	
	
	/**
	 * VipsXYZ2CMYK (XYZ2CMYK): transform XYZ to CMYK
	 * Returns a new image.
	 */
	public native VipsImage xyz2cmyk() throws VipsException;
	
	/**
	 * VipsXYZ2Lab (XYZ2Lab): transform XYZ to Lab
	 * Mutates the image inplace.
	 * @param options optional arguments
	 */
	public native void applyXYZ2Lab(com.criteo.vips.options.XYZ2LabOptions options) throws VipsException;
	
	/**
	 * VipsXYZ2Lab (XYZ2Lab): transform XYZ to Lab
	 * Mutates the image inplace.
	 */
	public void applyXYZ2Lab() throws VipsException {
		applyXYZ2Lab(null);
	}
	
	
	/**
	 * VipsXYZ2Lab (XYZ2Lab): transform XYZ to Lab
	 * Returns a new image.
	 * @param options optional arguments
	 */
	public native VipsImage xYZ2Lab(com.criteo.vips.options.XYZ2LabOptions options) throws VipsException;
	
	/**
	 * VipsXYZ2Lab (XYZ2Lab): transform XYZ to Lab
	 * Returns a new image.
	 */
	public VipsImage xYZ2Lab() throws VipsException {
		return xYZ2Lab(null);
	}
	
	/**
	 * VipsXYZ2scRGB (XYZ2scRGB): transform XYZ to scRGB
	 * Mutates the image inplace.
	 */
	public native void applyXYZ2scRGB() throws VipsException;
	
	
	/**
	 * VipsXYZ2scRGB (XYZ2scRGB): transform XYZ to scRGB
	 * Returns a new image.
	 */
	public native VipsImage xYZ2scRGB() throws VipsException;
	
	/**
	 * VipsXYZ2Yxy (XYZ2Yxy): transform XYZ to Yxy
	 * Mutates the image inplace.
	 */
	public native void applyXYZ2Yxy() throws VipsException;
	
	
	/**
	 * VipsXYZ2Yxy (XYZ2Yxy): transform XYZ to Yxy
	 * Returns a new image.
	 */
	public native VipsImage xYZ2Yxy() throws VipsException;
	
	/**
	 * VipsYxy2XYZ (Yxy2XYZ): transform Yxy to XYZ
	 * Mutates the image inplace.
	 */
	public native void applyYxy2XYZ() throws VipsException;
	
	
	/**
	 * VipsYxy2XYZ (Yxy2XYZ): transform Yxy to XYZ
	 * Returns a new image.
	 */
	public native VipsImage yxy2XYZ() throws VipsException;
	
	/**
	 * VipsZone (zone): make a zone plate
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage zone(int width, int height, com.criteo.vips.options.ZoneOptions options) throws VipsException;
	
	/**
	 * VipsZone (zone): make a zone plate
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage zone(int width, int height) throws VipsException {
		return zone(width, height, null);
	}
	
	/**
	 * VipsZoom (zoom): zoom an image
	 * Mutates the image inplace.
	 * @param xfac Horizontal zoom factor
	 * @param yfac Vertical zoom factor
	 */
	public native void applyZoom(int xfac, int yfac) throws VipsException;
	
	
	/**
	 * VipsZoom (zoom): zoom an image
	 * Returns a new image.
	 * @param xfac Horizontal zoom factor
	 * @param yfac Vertical zoom factor
	 */
	public native VipsImage zoom(int xfac, int yfac) throws VipsException;
	
}
