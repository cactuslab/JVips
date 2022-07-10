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

import com.criteo.vips.enums.*;
import com.criteo.vips.options.*;

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
	 */
	public native void abs() throws VipsException;
	
	/**
	 * VipsAdd (add): add two images
	 * @param right Right-hand image argument
	 */
	public native void add(Image right) throws VipsException;
	
	/**
	 * VipsForeignLoadAnalyze (analyzeload): load an Analyze6 image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage analyzeLoad(String filename, AnalyzeLoadOptions options) throws VipsException;
	
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
	public static native VipsImage arrayjoin(Image[] in, ArrayjoinOptions options) throws VipsException;
	
	/**
	 * VipsArrayjoin (arrayjoin): join an array of images
	 * @param in Array of input images
	 */
	public static VipsImage arrayjoin(Image[] in) throws VipsException {
		return arrayjoin(in, null);
	}
	
	/**
	 * VipsAutorot (autorot): autorotate image by exif tag
	 */
	public native void autorot() throws VipsException;
	
	/**
	 * VipsAvg (avg): find image average
	 */
	public native double avg() throws VipsException;
	
	/**
	 * VipsBandbool (bandbool): boolean operation across image bands
	 * @param booleanParam boolean to perform
	 */
	public native void bandbool(VipsOperationBoolean booleanParam) throws VipsException;
	
	/**
	 * VipsBandfold (bandfold): fold up x axis into bands
	 * @param options optional arguments
	 */
	public native void bandfold(BandfoldOptions options) throws VipsException;
	
	/**
	 * VipsBandfold (bandfold): fold up x axis into bands
	 */
	public void bandfold() throws VipsException {
		bandfold(null);
	}
	
	/**
	 * VipsBandjoin (bandjoin): bandwise join a set of images
	 * @param in Array of input images
	 */
	public static native VipsImage bandjoin(Image[] in) throws VipsException;
	
	/**
	 * VipsBandjoinConst (bandjoin_const): append a constant band to an image
	 * @param c Array of constants to add
	 */
	public native void bandjoinConst(double[] c) throws VipsException;
	
	/**
	 * VipsBandmean (bandmean): band-wise average
	 */
	public native void bandmean() throws VipsException;
	
	/**
	 * VipsBandrank (bandrank): band-wise rank of a set of images
	 * @param in Array of input images
	 * @param options optional arguments
	 */
	public static native VipsImage bandrank(Image[] in, BandrankOptions options) throws VipsException;
	
	/**
	 * VipsBandrank (bandrank): band-wise rank of a set of images
	 * @param in Array of input images
	 */
	public static VipsImage bandrank(Image[] in) throws VipsException {
		return bandrank(in, null);
	}
	
	/**
	 * VipsBandunfold (bandunfold): unfold image bands into x axis
	 * @param options optional arguments
	 */
	public native void bandunfold(BandunfoldOptions options) throws VipsException;
	
	/**
	 * VipsBandunfold (bandunfold): unfold image bands into x axis
	 */
	public void bandunfold() throws VipsException {
		bandunfold(null);
	}
	
	/**
	 * VipsBlack (black): make a black image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage black(int width, int height, BlackOptions options) throws VipsException;
	
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
	 * @param right Right-hand image argument
	 * @param booleanParam boolean to perform
	 */
	public native void booleanOp(Image right, VipsOperationBoolean booleanParam) throws VipsException;
	
	/**
	 * VipsBooleanConst (boolean_const): boolean operations against a constant
	 * @param booleanParam boolean to perform
	 * @param c Array of constants
	 */
	public native void booleanConst(VipsOperationBoolean booleanParam, double[] c) throws VipsException;
	
	/**
	 * VipsBuildlut (buildlut): build a look-up table
	 */
	public native void buildlut() throws VipsException;
	
	/**
	 * VipsByteswap (byteswap): byteswap an image
	 */
	public native void byteswap() throws VipsException;
	
	/**
	 * VipsCache (cache): cache an image
	 * @param options optional arguments
	 */
	public native void cache(CacheOptions options) throws VipsException;
	
	/**
	 * VipsCache (cache): cache an image
	 */
	public void cache() throws VipsException {
		cache(null);
	}
	
	/**
	 * VipsCanny (canny): Canny edge detector
	 * @param options optional arguments
	 */
	public native void canny(CannyOptions options) throws VipsException;
	
	/**
	 * VipsCanny (canny): Canny edge detector
	 */
	public void canny() throws VipsException {
		canny(null);
	}
	
	/**
	 * VipsCase (case): use pixel values to pick cases from an array of images
	 * @param cases Array of case images
	 */
	public native void caseOp(Image[] cases) throws VipsException;
	
	/**
	 * VipsCast (cast): cast an image
	 * @param format Format to cast to
	 * @param options optional arguments
	 */
	public native void cast(VipsBandFormat format, CastOptions options) throws VipsException;
	
	/**
	 * VipsCast (cast): cast an image
	 * @param format Format to cast to
	 */
	public void cast(VipsBandFormat format) throws VipsException {
		cast(format, null);
	}
	
	/**
	 * VipsCMC2LCh (CMC2LCh): transform LCh to CMC
	 */
	public native void cMC2LCh() throws VipsException;
	
	/**
	 * VipsCMYK2XYZ (CMYK2XYZ): transform CMYK to XYZ
	 */
	public native void cmyk2xyz() throws VipsException;
	
	/**
	 * VipsColourspace (colourspace): convert to a new colourspace
	 * @param space Destination colour space
	 * @param options optional arguments
	 */
	public native void colourspace(VipsInterpretation space, ColourspaceOptions options) throws VipsException;
	
	/**
	 * VipsColourspace (colourspace): convert to a new colourspace
	 * @param space Destination colour space
	 */
	public void colourspace(VipsInterpretation space) throws VipsException {
		colourspace(space, null);
	}
	
	/**
	 * VipsCompass (compass): convolve with rotating mask
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void compass(Image mask, CompassOptions options) throws VipsException;
	
	/**
	 * VipsCompass (compass): convolve with rotating mask
	 * @param mask Input matrix image
	 */
	public void compass(Image mask) throws VipsException {
		compass(mask, null);
	}
	
	/**
	 * VipsComplex (complex): perform a complex operation on an image
	 * @param cmplx complex to perform
	 */
	public native void complex(VipsOperationComplex cmplx) throws VipsException;
	
	/**
	 * VipsComplex2 (complex2): complex binary operations on two images
	 * @param right Right-hand image argument
	 * @param cmplx binary complex operation to perform
	 */
	public native void complex2(Image right, VipsOperationComplex2 cmplx) throws VipsException;
	
	/**
	 * VipsComplexform (complexform): form a complex image from two real images
	 * @param right Right-hand image argument
	 */
	public native void complexform(Image right) throws VipsException;
	
	/**
	 * VipsComplexget (complexget): get a component from a complex image
	 * @param get complex to perform
	 */
	public native void complexget(VipsOperationComplexget get) throws VipsException;
	
	/**
	 * VipsComposite (composite): blend an array of images with an array of blend modes
	 * @param in Array of input images
	 * @param mode Array of VipsBlendMode to join with
	 * @param options optional arguments
	 */
	public static native VipsImage composite(Image[] in, int[] mode, CompositeOptions options) throws VipsException;
	
	/**
	 * VipsComposite (composite): blend an array of images with an array of blend modes
	 * @param in Array of input images
	 * @param mode Array of VipsBlendMode to join with
	 */
	public static VipsImage composite(Image[] in, int[] mode) throws VipsException {
		return composite(in, mode, null);
	}
	
	/**
	 * VipsComposite2 (composite2): blend a pair of images with a blend mode
	 * @param overlay Overlay image
	 * @param mode VipsBlendMode to join with
	 * @param options optional arguments
	 */
	public native void composite2(Image overlay, VipsBlendMode mode, Composite2Options options) throws VipsException;
	
	/**
	 * VipsComposite2 (composite2): blend a pair of images with a blend mode
	 * @param overlay Overlay image
	 * @param mode VipsBlendMode to join with
	 */
	public void composite2(Image overlay, VipsBlendMode mode) throws VipsException {
		composite2(overlay, mode, null);
	}
	
	/**
	 * VipsConv (conv): convolution operation
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void conv(Image mask, ConvOptions options) throws VipsException;
	
	/**
	 * VipsConv (conv): convolution operation
	 * @param mask Input matrix image
	 */
	public void conv(Image mask) throws VipsException {
		conv(mask, null);
	}
	
	/**
	 * VipsConva (conva): approximate integer convolution
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void conva(Image mask, ConvaOptions options) throws VipsException;
	
	/**
	 * VipsConva (conva): approximate integer convolution
	 * @param mask Input matrix image
	 */
	public void conva(Image mask) throws VipsException {
		conva(mask, null);
	}
	
	/**
	 * VipsConvasep (convasep): approximate separable integer convolution
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void convasep(Image mask, ConvasepOptions options) throws VipsException;
	
	/**
	 * VipsConvasep (convasep): approximate separable integer convolution
	 * @param mask Input matrix image
	 */
	public void convasep(Image mask) throws VipsException {
		convasep(mask, null);
	}
	
	/**
	 * VipsConvf (convf): float convolution operation
	 * @param mask Input matrix image
	 */
	public native void convf(Image mask) throws VipsException;
	
	/**
	 * VipsConvi (convi): int convolution operation
	 * @param mask Input matrix image
	 */
	public native void convi(Image mask) throws VipsException;
	
	/**
	 * VipsConvsep (convsep): seperable convolution operation
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void convsep(Image mask, ConvsepOptions options) throws VipsException;
	
	/**
	 * VipsConvsep (convsep): seperable convolution operation
	 * @param mask Input matrix image
	 */
	public void convsep(Image mask) throws VipsException {
		convsep(mask, null);
	}
	
	/**
	 * VipsCopy (copy): copy an image
	 * @param options optional arguments
	 */
	public native void copy(CopyOptions options) throws VipsException;
	
	/**
	 * VipsCopy (copy): copy an image
	 */
	public void copy() throws VipsException {
		copy(null);
	}
	
	/**
	 * VipsCountlines (countlines): count lines in an image
	 * @param direction Countlines left-right or up-down
	 */
	public native double countlines(VipsDirection direction) throws VipsException;
	
	/**
	 * VipsForeignLoadCsvFile (csvload): load csv
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage csvLoad(String filename, CSVLoadOptions options) throws VipsException;
	
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
	public native void csvSave(String filename, CSVSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveCsvFile (csvsave): save image to csv
	 * @param filename Filename to save to
	 */
	public void csvSave(String filename) throws VipsException {
		csvSave(filename, null);
	}
	
	/**
	 * VipsdE00 (dE00): calculate dE00
	 * @param right Right-hand input image
	 */
	public native void dE00(Image right) throws VipsException;
	
	/**
	 * VipsdE76 (dE76): calculate dE76
	 * @param right Right-hand input image
	 */
	public native void dE76(Image right) throws VipsException;
	
	/**
	 * VipsdECMC (dECMC): calculate dECMC
	 * @param right Right-hand input image
	 */
	public native void dECMC(Image right) throws VipsException;
	
	/**
	 * VipsDeviate (deviate): find image standard deviation
	 */
	public native double deviate() throws VipsException;
	
	/**
	 * VipsDivide (divide): divide two images
	 * @param right Right-hand image argument
	 */
	public native void divide(Image right) throws VipsException;
	
	/**
	 * VipsDrawCircle (draw_circle): draw a circle on an image
	 * @param ink Color for pixels
	 * @param cx Centre of draw_circle
	 * @param cy Centre of draw_circle
	 * @param radius Radius in pixels
	 * @param options optional arguments
	 */
	public native void drawCircle(double[] ink, int cx, int cy, int radius, DrawCircleOptions options) throws VipsException;
	
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
	public native void drawFlood(double[] ink, int x, int y, DrawFloodOptions options) throws VipsException;
	
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
	public native void drawImage(Image sub, int x, int y, DrawImageOptions options) throws VipsException;
	
	/**
	 * VipsDrawImage (draw_image): paint an image into another image
	 * @param sub Sub-image to insert into main image
	 * @param x Draw image here
	 * @param y Draw image here
	 */
	public void drawImage(Image sub, int x, int y) throws VipsException {
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
	public native void drawMask(double[] ink, Image mask, int x, int y) throws VipsException;
	
	/**
	 * VipsDrawRect (draw_rect): paint a rectangle on an image
	 * @param ink Color for pixels
	 * @param left Rect to fill
	 * @param top Rect to fill
	 * @param width Rect to fill
	 * @param height Rect to fill
	 * @param options optional arguments
	 */
	public native void drawRect(double[] ink, int left, int top, int width, int height, DrawRectOptions options) throws VipsException;
	
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
	public native void dzSave(String filename, DZSaveOptions options) throws VipsException;
	
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
	public native byte[] dzSaveBuffer(DZSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveDzBuffer (dzsave_buffer): save image to dz buffer
	 */
	public byte[] dzSaveBuffer() throws VipsException {
		return dzSaveBuffer(null);
	}
	
	/**
	 * VipsEmbed (embed): embed an image in a larger image
	 * @param x Left edge of input in output
	 * @param y Top edge of input in output
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public native void embed(int x, int y, int width, int height, EmbedOptions options) throws VipsException;
	
	/**
	 * VipsEmbed (embed): embed an image in a larger image
	 * @param x Left edge of input in output
	 * @param y Top edge of input in output
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public void embed(int x, int y, int width, int height) throws VipsException {
		embed(x, y, width, height, null);
	}
	
	/**
	 * VipsExtractArea (extract_area): extract an area from an image
	 * @param left Left edge of extract area
	 * @param top Top edge of extract area
	 * @param width Width of extract area
	 * @param height Height of extract area
	 */
	public native VipsImage extractArea(int left, int top, int width, int height) throws VipsException;
	
	/**
	 * VipsExtractBand (extract_band): extract band from an image
	 * @param band Band to extract
	 * @param options optional arguments
	 */
	public native VipsImage extractBand(int band, ExtractBandOptions options) throws VipsException;
	
	/**
	 * VipsExtractBand (extract_band): extract band from an image
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
	public static native VipsImage eye(int width, int height, EyeOptions options) throws VipsException;
	
	/**
	 * VipsEye (eye): make an image showing the eye's spatial response
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage eye(int width, int height) throws VipsException {
		return eye(width, height, null);
	}
	
	/**
	 * VipsFalsecolour (falsecolour): false-colour an image
	 */
	public native void falsecolour() throws VipsException;
	
	/**
	 * VipsFastcor (fastcor): fast correlation
	 * @param ref Input reference image
	 */
	public native void fastcor(Image ref) throws VipsException;
	
	/**
	 * VipsFillNearest (fill_nearest): fill image zeros with nearest non-zero pixel
	 */
	public native void fillNearest() throws VipsException;
	
	/**
	 * VipsFindTrim (find_trim): search an image for non-edge areas
	 * @param options optional arguments
	 */
	public native Rectangle findTrim(FindTrimOptions options) throws VipsException;
	
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
	public static native VipsImage fitsLoad(String filename, FITSLoadOptions options) throws VipsException;
	
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
	public native void fitsSave(String filename, FITSSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveFits (fitssave): save image to fits file
	 * @param filename Filename to save to
	 */
	public void fitsSave(String filename) throws VipsException {
		fitsSave(filename, null);
	}
	
	/**
	 * VipsFlatten (flatten): flatten alpha out of an image
	 * @param options optional arguments
	 */
	public native void flatten(FlattenOptions options) throws VipsException;
	
	/**
	 * VipsFlatten (flatten): flatten alpha out of an image
	 */
	public void flatten() throws VipsException {
		flatten(null);
	}
	
	/**
	 * VipsFlip (flip): flip an image
	 * @param direction Direction to flip image
	 */
	public native void flip(VipsDirection direction) throws VipsException;
	
	/**
	 * VipsFloat2rad (float2rad): transform float RGB to Radiance coding
	 */
	public native void float2rad() throws VipsException;
	
	/**
	 * VipsFractsurf (fractsurf): make a fractal surface
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param fractalDimension Fractal dimension
	 */
	public static native VipsImage fractsurf(int width, int height, double fractalDimension) throws VipsException;
	
	/**
	 * VipsFreqmult (freqmult): frequency-domain filtering
	 * @param mask Input mask image
	 */
	public native void freqmult(Image mask) throws VipsException;
	
	/**
	 * VipsFwfft (fwfft): forward FFT
	 */
	public native void fwfft() throws VipsException;
	
	/**
	 * VipsGamma (gamma): gamma an image
	 * @param options optional arguments
	 */
	public native void gamma(GammaOptions options) throws VipsException;
	
	/**
	 * VipsGamma (gamma): gamma an image
	 */
	public void gamma() throws VipsException {
		gamma(null);
	}
	
	/**
	 * VipsGaussblur (gaussblur): gaussian blur
	 * @param sigma Sigma of Gaussian
	 * @param options optional arguments
	 */
	public native void gaussBlur(double sigma, GaussBlurOptions options) throws VipsException;
	
	/**
	 * VipsGaussblur (gaussblur): gaussian blur
	 * @param sigma Sigma of Gaussian
	 */
	public void gaussBlur(double sigma) throws VipsException {
		gaussBlur(sigma, null);
	}
	
	/**
	 * VipsGaussmat (gaussmat): make a gaussian image
	 * @param sigma Sigma of Gaussian
	 * @param minAmpl Minimum amplitude of Gaussian
	 * @param options optional arguments
	 */
	public static native VipsImage gaussMat(double sigma, double minAmpl, GaussMatOptions options) throws VipsException;
	
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
	public static native VipsImage gaussNoise(int width, int height, GaussNoiseOptions options) throws VipsException;
	
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
	public static native VipsImage gifLoad(String filename, GIFLoadOptions options) throws VipsException;
	
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
	public static native VipsImage gifLoadBuffer(byte[] buffer, GIFLoadBufferOptions options) throws VipsException;
	
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
	public native void gifSave(String filename, GIFSaveOptions options) throws VipsException;
	
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
	public native byte[] gifSaveBuffer(GIFSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveCgifBuffer (gifsave_buffer): save as gif
	 */
	public byte[] gifSaveBuffer() throws VipsException {
		return gifSaveBuffer(null);
	}
	
	/**
	 * VipsGlobalbalance (globalbalance): global balance an image mosaic
	 * @param options optional arguments
	 */
	public native void globalbalance(GlobalbalanceOptions options) throws VipsException;
	
	/**
	 * VipsGlobalbalance (globalbalance): global balance an image mosaic
	 */
	public void globalbalance() throws VipsException {
		globalbalance(null);
	}
	
	/**
	 * VipsGravity (gravity): place an image within a larger image with a certain gravity
	 * @param direction direction to place image within width/height
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public native void gravity(VipsCompassDirection direction, int width, int height, GravityOptions options) throws VipsException;
	
	/**
	 * VipsGravity (gravity): place an image within a larger image with a certain gravity
	 * @param direction direction to place image within width/height
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public void gravity(VipsCompassDirection direction, int width, int height) throws VipsException {
		gravity(direction, width, height, null);
	}
	
	/**
	 * VipsGrey (grey): make a grey ramp image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage grey(int width, int height, GreyOptions options) throws VipsException;
	
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
	 * @param tileHeight chop into tiles this high
	 * @param across number of tiles across
	 * @param down number of tiles down
	 */
	public native void grid(int tileHeight, int across, int down) throws VipsException;
	
	/**
	 * VipsForeignLoadHeifFile (heifload): load a HEIF image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage heifLoad(String filename, HEIFLoadOptions options) throws VipsException;
	
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
	public static native VipsImage heifLoadBuffer(byte[] buffer, HEIFLoadBufferOptions options) throws VipsException;
	
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
	public native void heifSave(String filename, HEIFSaveOptions options) throws VipsException;
	
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
	public native byte[] heifSaveBuffer(HEIFSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveHeifBuffer (heifsave_buffer): save image in HEIF format
	 */
	public byte[] heifSaveBuffer() throws VipsException {
		return heifSaveBuffer(null);
	}
	
	/**
	 * VipsHistCum (hist_cum): form cumulative histogram
	 */
	public native void histCum() throws VipsException;
	
	/**
	 * VipsHistEntropy (hist_entropy): estimate image entropy
	 */
	public native double histEntropy() throws VipsException;
	
	/**
	 * VipsHistEqual (hist_equal): histogram equalisation
	 * @param options optional arguments
	 */
	public native void histEqual(HistEqualOptions options) throws VipsException;
	
	/**
	 * VipsHistEqual (hist_equal): histogram equalisation
	 */
	public void histEqual() throws VipsException {
		histEqual(null);
	}
	
	/**
	 * VipsHistFind (hist_find): find image histogram
	 * @param options optional arguments
	 */
	public native void histFind(HistFindOptions options) throws VipsException;
	
	/**
	 * VipsHistFind (hist_find): find image histogram
	 */
	public void histFind() throws VipsException {
		histFind(null);
	}
	
	/**
	 * VipsHistFindIndexed (hist_find_indexed): find indexed image histogram
	 * @param index Index image
	 * @param options optional arguments
	 */
	public native void histFindIndexed(Image index, HistFindIndexedOptions options) throws VipsException;
	
	/**
	 * VipsHistFindIndexed (hist_find_indexed): find indexed image histogram
	 * @param index Index image
	 */
	public void histFindIndexed(Image index) throws VipsException {
		histFindIndexed(index, null);
	}
	
	/**
	 * VipsHistFindNDim (hist_find_ndim): find n-dimensional image histogram
	 * @param options optional arguments
	 */
	public native void histFindNdim(HistFindNdimOptions options) throws VipsException;
	
	/**
	 * VipsHistFindNDim (hist_find_ndim): find n-dimensional image histogram
	 */
	public void histFindNdim() throws VipsException {
		histFindNdim(null);
	}
	
	/**
	 * VipsHistIsmonotonic (hist_ismonotonic): test for monotonicity
	 */
	public native boolean histIsmonotonic() throws VipsException;
	
	/**
	 * VipsHistLocal (hist_local): local histogram equalisation
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 * @param options optional arguments
	 */
	public native void histLocal(int width, int height, HistLocalOptions options) throws VipsException;
	
	/**
	 * VipsHistLocal (hist_local): local histogram equalisation
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 */
	public void histLocal(int width, int height) throws VipsException {
		histLocal(width, height, null);
	}
	
	/**
	 * VipsHistMatch (hist_match): match two histograms
	 * @param ref Reference histogram
	 */
	public native void histMatch(Image ref) throws VipsException;
	
	/**
	 * VipsHistNorm (hist_norm): normalise histogram
	 */
	public native void histNorm() throws VipsException;
	
	/**
	 * VipsHistPlot (hist_plot): plot histogram
	 */
	public native void histPlot() throws VipsException;
	
	/**
	 * VipsHoughCircle (hough_circle): find hough circle transform
	 * @param options optional arguments
	 */
	public native void houghCircle(HoughCircleOptions options) throws VipsException;
	
	/**
	 * VipsHoughCircle (hough_circle): find hough circle transform
	 */
	public void houghCircle() throws VipsException {
		houghCircle(null);
	}
	
	/**
	 * VipsHoughLine (hough_line): find hough line transform
	 * @param options optional arguments
	 */
	public native void houghLine(HoughLineOptions options) throws VipsException;
	
	/**
	 * VipsHoughLine (hough_line): find hough line transform
	 */
	public void houghLine() throws VipsException {
		houghLine(null);
	}
	
	/**
	 * VipsHSV2sRGB (HSV2sRGB): transform HSV to sRGB
	 */
	public native void hSV2sRGB() throws VipsException;
	
	/**
	 * VipsIccExport (icc_export): output to device with ICC profile
	 * @param options optional arguments
	 */
	public native void iccExport(ICCExportOptions options) throws VipsException;
	
	/**
	 * VipsIccExport (icc_export): output to device with ICC profile
	 */
	public void iccExport() throws VipsException {
		iccExport(null);
	}
	
	/**
	 * VipsIccImport (icc_import): import from device with ICC profile
	 * @param options optional arguments
	 */
	public native void iccImport(ICCImportOptions options) throws VipsException;
	
	/**
	 * VipsIccImport (icc_import): import from device with ICC profile
	 */
	public void iccImport() throws VipsException {
		iccImport(null);
	}
	
	/**
	 * VipsIccTransform (icc_transform): transform between devices with ICC profiles
	 * @param outputProfile Filename to load output profile from
	 * @param options optional arguments
	 */
	public native void iccTransform(String outputProfile, ICCTransformOptions options) throws VipsException;
	
	/**
	 * VipsIccTransform (icc_transform): transform between devices with ICC profiles
	 * @param outputProfile Filename to load output profile from
	 */
	public void iccTransform(String outputProfile) throws VipsException {
		iccTransform(outputProfile, null);
	}
	
	/**
	 * VipsIdentity (identity): make a 1D image where pixel values are indexes
	 * @param options optional arguments
	 */
	public static native VipsImage identity(IdentityOptions options) throws VipsException;
	
	/**
	 * VipsIdentity (identity): make a 1D image where pixel values are indexes
	 */
	public static VipsImage identity() throws VipsException {
		return identity(null);
	}
	
	/**
	 * VipsIfthenelse (ifthenelse): ifthenelse an image
	 * @param in1 Source for TRUE pixels
	 * @param in2 Source for FALSE pixels
	 * @param options optional arguments
	 */
	public native void ifthenelse(Image in1, Image in2, IfthenelseOptions options) throws VipsException;
	
	/**
	 * VipsIfthenelse (ifthenelse): ifthenelse an image
	 * @param in1 Source for TRUE pixels
	 * @param in2 Source for FALSE pixels
	 */
	public void ifthenelse(Image in1, Image in2) throws VipsException {
		ifthenelse(in1, in2, null);
	}
	
	/**
	 * VipsInsert (insert): insert image @sub into @main at @x, @y
	 * @param sub Sub-image to insert into main image
	 * @param x Left edge of sub in main
	 * @param y Top edge of sub in main
	 * @param options optional arguments
	 */
	public native void insert(Image sub, int x, int y, InsertOptions options) throws VipsException;
	
	/**
	 * VipsInsert (insert): insert image @sub into @main at @x, @y
	 * @param sub Sub-image to insert into main image
	 * @param x Left edge of sub in main
	 * @param y Top edge of sub in main
	 */
	public void insert(Image sub, int x, int y) throws VipsException {
		insert(sub, x, y, null);
	}
	
	/**
	 * VipsInvert (invert): invert an image
	 */
	public native void invert() throws VipsException;
	
	/**
	 * VipsInvertlut (invertlut): build an inverted look-up table
	 * @param options optional arguments
	 */
	public native void invertlut(InvertLUTOptions options) throws VipsException;
	
	/**
	 * VipsInvertlut (invertlut): build an inverted look-up table
	 */
	public void invertlut() throws VipsException {
		invertlut(null);
	}
	
	/**
	 * VipsInvfft (invfft): inverse FFT
	 * @param options optional arguments
	 */
	public native void invfft(InvFFTOptions options) throws VipsException;
	
	/**
	 * VipsInvfft (invfft): inverse FFT
	 */
	public void invfft() throws VipsException {
		invfft(null);
	}
	
	/**
	 * VipsJoin (join): join a pair of images
	 * @param in2 Second input image
	 * @param direction Join left-right or up-down
	 * @param options optional arguments
	 */
	public native VipsImage join(Image in2, VipsDirection direction, JoinOptions options) throws VipsException;
	
	/**
	 * VipsJoin (join): join a pair of images
	 * @param in2 Second input image
	 * @param direction Join left-right or up-down
	 */
	public VipsImage join(Image in2, VipsDirection direction) throws VipsException {
		return join(in2, direction, null);
	}
	
	/**
	 * VipsForeignLoadJp2kFile (jp2kload): load JPEG2000 image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage jp2kLoad(String filename, JP2KLoadOptions options) throws VipsException;
	
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
	public static native VipsImage jp2kLoadBuffer(byte[] buffer, JP2KLoadBufferOptions options) throws VipsException;
	
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
	public native void jp2kSave(String filename, JP2KSaveOptions options) throws VipsException;
	
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
	public native byte[] jp2kSaveBuffer(JP2KSaveBufferOptions options) throws VipsException;
	
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
	public static native VipsImage jpegLoad(String filename, JPEGLoadOptions options) throws VipsException;
	
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
	public static native VipsImage jpegLoadBuffer(byte[] buffer, JPEGLoadBufferOptions options) throws VipsException;
	
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
	public native void jpegSave(String filename, JPEGSaveOptions options) throws VipsException;
	
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
	public native byte[] jpegSaveBuffer(JPEGSaveBufferOptions options) throws VipsException;
	
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
	public native void jpegSaveMime(JPEGSaveMimeOptions options) throws VipsException;
	
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
	public static native VipsImage jxlLoad(String filename, JXLLoadOptions options) throws VipsException;
	
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
	public static native VipsImage jxlLoadBuffer(byte[] buffer, JXLLoadBufferOptions options) throws VipsException;
	
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
	public native void jxlSave(String filename, JXLSaveOptions options) throws VipsException;
	
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
	public native byte[] jxlSaveBuffer(JXLSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveJxlBuffer (jxlsave_buffer): save image in JPEG-XL format
	 */
	public byte[] jxlSaveBuffer() throws VipsException {
		return jxlSaveBuffer(null);
	}
	
	/**
	 * VipsLab2LabQ (Lab2LabQ): transform float Lab to LabQ coding
	 */
	public native void lab2LabQ() throws VipsException;
	
	/**
	 * VipsLab2LabS (Lab2LabS): transform float Lab to signed short
	 */
	public native void lab2LabS() throws VipsException;
	
	/**
	 * VipsLab2LCh (Lab2LCh): transform Lab to LCh
	 */
	public native void lab2LCh() throws VipsException;
	
	/**
	 * VipsLab2XYZ (Lab2XYZ): transform CIELAB to XYZ
	 * @param options optional arguments
	 */
	public native void lab2XYZ(LAB2XYZOptions options) throws VipsException;
	
	/**
	 * VipsLab2XYZ (Lab2XYZ): transform CIELAB to XYZ
	 */
	public void lab2XYZ() throws VipsException {
		lab2XYZ(null);
	}
	
	/**
	 * VipsLabelregions (labelregions): label regions in an image
	 */
	public native void labelregions() throws VipsException;
	
	/**
	 * VipsLabQ2Lab (LabQ2Lab): unpack a LabQ image to float Lab
	 */
	public native void labQ2Lab() throws VipsException;
	
	/**
	 * VipsLabQ2LabS (LabQ2LabS): unpack a LabQ image to short Lab
	 */
	public native void labQ2LabS() throws VipsException;
	
	/**
	 * VipsLabQ2sRGB (LabQ2sRGB): convert a LabQ image to sRGB
	 */
	public native void labQ2sRGB() throws VipsException;
	
	/**
	 * VipsLabS2Lab (LabS2Lab): transform signed short Lab to float
	 */
	public native void labS2Lab() throws VipsException;
	
	/**
	 * VipsLabS2LabQ (LabS2LabQ): transform short Lab to LabQ coding
	 */
	public native void labS2LabQ() throws VipsException;
	
	/**
	 * VipsLCh2CMC (LCh2CMC): transform LCh to CMC
	 */
	public native void lCh2CMC() throws VipsException;
	
	/**
	 * VipsLCh2Lab (LCh2Lab): transform LCh to Lab
	 */
	public native void lCh2Lab() throws VipsException;
	
	/**
	 * VipsLinear (linear): calculate (a * in + b)
	 * @param a Multiply by this
	 * @param b Add this
	 * @param options optional arguments
	 */
	public native void linear(double[] a, double[] b, LinearOptions options) throws VipsException;
	
	/**
	 * VipsLinear (linear): calculate (a * in + b)
	 * @param a Multiply by this
	 * @param b Add this
	 */
	public void linear(double[] a, double[] b) throws VipsException {
		linear(a, b, null);
	}
	
	/**
	 * VipsLineCache (linecache): cache an image as a set of lines
	 * @param options optional arguments
	 */
	public native void linecache(LinecacheOptions options) throws VipsException;
	
	/**
	 * VipsLineCache (linecache): cache an image as a set of lines
	 */
	public void linecache() throws VipsException {
		linecache(null);
	}
	
	/**
	 * VipsLogmat (logmat): make a Laplacian of Gaussian image
	 * @param sigma Radius of Gaussian
	 * @param minAmpl Minimum amplitude of Gaussian
	 * @param options optional arguments
	 */
	public static native VipsImage logmat(double sigma, double minAmpl, LogmatOptions options) throws VipsException;
	
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
	public static native VipsImage magickLoad(String filename, MagickLoadOptions options) throws VipsException;
	
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
	public static native VipsImage magickLoadBuffer(byte[] buffer, MagickLoadBufferOptions options) throws VipsException;
	
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
	public native void magickSave(String filename, MagickSaveOptions options) throws VipsException;
	
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
	public native byte[] magickSaveBuffer(MagickSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveMagickBuffer (magicksave_buffer): save image to magick buffer
	 */
	public byte[] magickSaveBuffer() throws VipsException {
		return magickSaveBuffer(null);
	}
	
	/**
	 * VipsMaplut (maplut): map an image though a lut
	 * @param lut Look-up table image
	 * @param options optional arguments
	 */
	public native void maplut(Image lut, MapLUTOptions options) throws VipsException;
	
	/**
	 * VipsMaplut (maplut): map an image though a lut
	 * @param lut Look-up table image
	 */
	public void maplut(Image lut) throws VipsException {
		maplut(lut, null);
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
	public static native VipsImage maskButterworth(int width, int height, double order, double frequencyCutoff, double amplitudeCutoff, MaskButterworthOptions options) throws VipsException;
	
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
	 * @param radius radius of circle
	 * @param amplitudeCutoff Amplitude cutoff
	 * @param options optional arguments
	 */
	public static native VipsImage maskButterworthBand(int width, int height, double order, double frequencyCutoffX, double frequencyCutoffY, double radius, double amplitudeCutoff, MaskButterworthBandOptions options) throws VipsException;
	
	/**
	 * VipsMaskButterworthBand (mask_butterworth_band): make a butterworth_band filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param order Filter order
	 * @param frequencyCutoffX Frequency cutoff x
	 * @param frequencyCutoffY Frequency cutoff y
	 * @param radius radius of circle
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
	public static native VipsImage maskButterworthRing(int width, int height, double order, double frequencyCutoff, double amplitudeCutoff, double ringwidth, MaskButterworthRingOptions options) throws VipsException;
	
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
	public static native VipsImage maskFractal(int width, int height, double fractalDimension, MaskFractalOptions options) throws VipsException;
	
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
	public static native VipsImage maskGaussian(int width, int height, double frequencyCutoff, double amplitudeCutoff, MaskGaussianOptions options) throws VipsException;
	
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
	 * @param radius radius of circle
	 * @param amplitudeCutoff Amplitude cutoff
	 * @param options optional arguments
	 */
	public static native VipsImage maskGaussianBand(int width, int height, double frequencyCutoffX, double frequencyCutoffY, double radius, double amplitudeCutoff, MaskGaussianBandOptions options) throws VipsException;
	
	/**
	 * VipsMaskGaussianBand (mask_gaussian_band): make a gaussian filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoffX Frequency cutoff x
	 * @param frequencyCutoffY Frequency cutoff y
	 * @param radius radius of circle
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
	public static native VipsImage maskGaussianRing(int width, int height, double frequencyCutoff, double amplitudeCutoff, double ringwidth, MaskGaussianRingOptions options) throws VipsException;
	
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
	public static native VipsImage maskIdeal(int width, int height, double frequencyCutoff, MaskIdealOptions options) throws VipsException;
	
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
	 * @param radius radius of circle
	 * @param options optional arguments
	 */
	public static native VipsImage maskIdealBand(int width, int height, double frequencyCutoffX, double frequencyCutoffY, double radius, MaskIdealBandOptions options) throws VipsException;
	
	/**
	 * VipsMaskIdealBand (mask_ideal_band): make an ideal band filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoffX Frequency cutoff x
	 * @param frequencyCutoffY Frequency cutoff y
	 * @param radius radius of circle
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
	public static native VipsImage maskIdealRing(int width, int height, double frequencyCutoff, double ringwidth, MaskIdealRingOptions options) throws VipsException;
	
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
	 * @param math math to perform
	 */
	public native void math(VipsOperationMath math) throws VipsException;
	
	/**
	 * VipsMath2 (math2): binary math operations
	 * @param right Right-hand image argument
	 * @param math2 math to perform
	 */
	public native void math2(Image right, VipsOperationMath2 math2) throws VipsException;
	
	/**
	 * VipsMath2Const (math2_const): binary math operations with a constant
	 * @param math2 math to perform
	 * @param c Array of constants
	 */
	public native void math2Const(VipsOperationMath2 math2, double[] c) throws VipsException;
	
	/**
	 * VipsForeignLoadMat (matload): load mat from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage matLoad(String filename, MatLoadOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadMat (matload): load mat from file
	 * @param filename Filename to load from
	 */
	public static VipsImage matLoad(String filename) throws VipsException {
		return matLoad(filename, null);
	}
	
	/**
	 * VipsMatrixinvert (matrixinvert): invert an matrix
	 */
	public native void matrixinvert() throws VipsException;
	
	/**
	 * VipsForeignLoadMatrixFile (matrixload): load matrix
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage matrixLoad(String filename, MatrixLoadOptions options) throws VipsException;
	
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
	public native void matrixprint(MatrixprintOptions options) throws VipsException;
	
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
	public native void matrixSave(String filename, MatrixSaveOptions options) throws VipsException;
	
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
	public native double max(MaxOptions options) throws VipsException;
	
	/**
	 * VipsMax (max): find image maximum
	 */
	public double max() throws VipsException {
		return max(null);
	}
	
	/**
	 * VipsMeasure (measure): measure a set of patches on a colour chart
	 * @param h Number of patches across chart
	 * @param v Number of patches down chart
	 * @param options optional arguments
	 */
	public native void measure(int h, int v, MeasureOptions options) throws VipsException;
	
	/**
	 * VipsMeasure (measure): measure a set of patches on a colour chart
	 * @param h Number of patches across chart
	 * @param v Number of patches down chart
	 */
	public void measure(int h, int v) throws VipsException {
		measure(h, v, null);
	}
	
	/**
	 * VipsMerge (merge): merge two images
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical merge
	 * @param dx Horizontal displacement from sec to ref
	 * @param dy Vertical displacement from sec to ref
	 * @param options optional arguments
	 */
	public native void merge(Image sec, VipsDirection direction, int dx, int dy, MergeOptions options) throws VipsException;
	
	/**
	 * VipsMerge (merge): merge two images
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical merge
	 * @param dx Horizontal displacement from sec to ref
	 * @param dy Vertical displacement from sec to ref
	 */
	public void merge(Image sec, VipsDirection direction, int dx, int dy) throws VipsException {
		merge(sec, direction, dx, dy, null);
	}
	
	/**
	 * VipsMin (min): find image minimum
	 * @param options optional arguments
	 */
	public native double min(MinOptions options) throws VipsException;
	
	/**
	 * VipsMin (min): find image minimum
	 */
	public double min() throws VipsException {
		return min(null);
	}
	
	/**
	 * VipsMorph (morph): morphology operation
	 * @param mask Input matrix image
	 * @param morph Morphological operation to perform
	 */
	public native void morph(Image mask, VipsOperationMorphology morph) throws VipsException;
	
	/**
	 * VipsMosaic (mosaic): mosaic two images
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical mosaic
	 * @param xref Position of reference tie-point
	 * @param yref Position of reference tie-point
	 * @param xsec Position of secondary tie-point
	 * @param ysec Position of secondary tie-point
	 * @param options optional arguments
	 */
	public native void mosaic(Image sec, VipsDirection direction, int xref, int yref, int xsec, int ysec, MosaicOptions options) throws VipsException;
	
	/**
	 * VipsMosaic (mosaic): mosaic two images
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical mosaic
	 * @param xref Position of reference tie-point
	 * @param yref Position of reference tie-point
	 * @param xsec Position of secondary tie-point
	 * @param ysec Position of secondary tie-point
	 */
	public void mosaic(Image sec, VipsDirection direction, int xref, int yref, int xsec, int ysec) throws VipsException {
		mosaic(sec, direction, xref, yref, xsec, ysec, null);
	}
	
	/**
	 * VipsMsb (msb): pick most-significant byte from an image
	 * @param options optional arguments
	 */
	public native void msb(MsbOptions options) throws VipsException;
	
	/**
	 * VipsMsb (msb): pick most-significant byte from an image
	 */
	public void msb() throws VipsException {
		msb(null);
	}
	
	/**
	 * VipsMultiply (multiply): multiply two images
	 * @param right Right-hand image argument
	 */
	public native void multiply(Image right) throws VipsException;
	
	/**
	 * VipsForeignLoadOpenexr (openexrload): load an OpenEXR image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage openexrLoad(String filename, OpenexrLoadOptions options) throws VipsException;
	
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
	public static native VipsImage openslideLoad(String filename, OpenslideLoadOptions options) throws VipsException;
	
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
	public static native VipsImage pdfLoad(String filename, PDFLoadOptions options) throws VipsException;
	
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
	public static native VipsImage pdfLoadBuffer(byte[] buffer, PDFLoadBufferOptions options) throws VipsException;
	
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
	public static native VipsImage perlin(int width, int height, PerlinOptions options) throws VipsException;
	
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
	 * @param in2 Second input image
	 */
	public native void phasecor(Image in2) throws VipsException;
	
	/**
	 * VipsForeignLoadPngFile (pngload): load png from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage pngLoad(String filename, PNGLoadOptions options) throws VipsException;
	
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
	public static native VipsImage pngLoadBuffer(byte[] buffer, PNGLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadPngBuffer (pngload_buffer): load png from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage pngLoadBuffer(byte[] buffer) throws VipsException {
		return pngLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSavePngFile (pngsave): save image to png file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void pngSave(String filename, PNGSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSavePngFile (pngsave): save image to png file
	 * @param filename Filename to save to
	 */
	public void pngSave(String filename) throws VipsException {
		pngSave(filename, null);
	}
	
	/**
	 * VipsForeignSavePngBuffer (pngsave_buffer): save image to png buffer
	 * @param options optional arguments
	 */
	public native byte[] pngSaveBuffer(PNGSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSavePngBuffer (pngsave_buffer): save image to png buffer
	 */
	public byte[] pngSaveBuffer() throws VipsException {
		return pngSaveBuffer(null);
	}
	
	/**
	 * VipsForeignLoadPpmFile (ppmload): load ppm from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage ppmLoad(String filename, PPMLoadOptions options) throws VipsException;
	
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
	public native void ppmSave(String filename, PPMSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSavePpmFile (ppmsave): save image to ppm file
	 * @param filename Filename to save to
	 */
	public void ppmSave(String filename) throws VipsException {
		ppmSave(filename, null);
	}
	
	/**
	 * VipsPremultiply (premultiply): premultiply image alpha
	 * @param options optional arguments
	 */
	public native void premultiply(PremultiplyOptions options) throws VipsException;
	
	/**
	 * VipsPremultiply (premultiply): premultiply image alpha
	 */
	public void premultiply() throws VipsException {
		premultiply(null);
	}
	
	/**
	 * VipsProfile (profile): find image profiles
	 */
	public native VipsImage profile() throws VipsException;
	
	/**
	 * VipsProfileLoad (profile_load): load named ICC profile
	 * @param name Profile name
	 */
	public static native byte[] profileLoad(String name) throws VipsException;
	
	/**
	 * VipsProject (project): find image projections
	 */
	public native VipsImage project() throws VipsException;
	
	/**
	 * VipsRad2float (rad2float): unpack Radiance coding to float RGB
	 */
	public native void rad2float() throws VipsException;
	
	/**
	 * VipsForeignLoadRadFile (radload): load a Radiance image from a file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage radLoad(String filename, RadLoadOptions options) throws VipsException;
	
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
	public static native VipsImage radLoadBuffer(byte[] buffer, RadLoadBufferOptions options) throws VipsException;
	
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
	public native void radSave(String filename, RadSaveOptions options) throws VipsException;
	
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
	public native byte[] radSaveBuffer(RadSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveRadBuffer (radsave_buffer): save image to Radiance buffer
	 */
	public byte[] radSaveBuffer() throws VipsException {
		return radSaveBuffer(null);
	}
	
	/**
	 * VipsRank (rank): rank filter
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 * @param index Select pixel at index
	 */
	public native void rank(int width, int height, int index) throws VipsException;
	
	/**
	 * VipsForeignLoadRaw (rawload): load raw data from a file
	 * @param filename Filename to load from
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param bands Number of bands in image
	 * @param options optional arguments
	 */
	public static native VipsImage rawLoad(String filename, int width, int height, int bands, RawLoadOptions options) throws VipsException;
	
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
	public native void rawSave(String filename, RawSaveOptions options) throws VipsException;
	
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
	public native void rawSaveFd(int fd, RawSaveFdOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveRawFd (rawsave_fd): write raw image to file descriptor
	 * @param fd File descriptor to write to
	 */
	public void rawSaveFd(int fd) throws VipsException {
		rawSaveFd(fd, null);
	}
	
	/**
	 * VipsRecomb (recomb): linear recombination with matrix
	 * @param m matrix of coefficients
	 */
	public native void recomb(Image m) throws VipsException;
	
	/**
	 * VipsReduce (reduce): reduce an image
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 * @param options optional arguments
	 */
	public native void reduce(double hshrink, double vshrink, ReduceOptions options) throws VipsException;
	
	/**
	 * VipsReduce (reduce): reduce an image
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 */
	public void reduce(double hshrink, double vshrink) throws VipsException {
		reduce(hshrink, vshrink, null);
	}
	
	/**
	 * VipsReduceh (reduceh): shrink an image horizontally
	 * @param hshrink Horizontal shrink factor
	 * @param options optional arguments
	 */
	public native void reduceh(double hshrink, ReducehOptions options) throws VipsException;
	
	/**
	 * VipsReduceh (reduceh): shrink an image horizontally
	 * @param hshrink Horizontal shrink factor
	 */
	public void reduceh(double hshrink) throws VipsException {
		reduceh(hshrink, null);
	}
	
	/**
	 * VipsReducev (reducev): shrink an image vertically
	 * @param vshrink Vertical shrink factor
	 * @param options optional arguments
	 */
	public native void reducev(double vshrink, ReducevOptions options) throws VipsException;
	
	/**
	 * VipsReducev (reducev): shrink an image vertically
	 * @param vshrink Vertical shrink factor
	 */
	public void reducev(double vshrink) throws VipsException {
		reducev(vshrink, null);
	}
	
	/**
	 * VipsRelational (relational): relational operation on two images
	 * @param right Right-hand image argument
	 * @param relational relational to perform
	 */
	public native void relational(Image right, VipsOperationRelational relational) throws VipsException;
	
	/**
	 * VipsRelationalConst (relational_const): relational operations against a constant
	 * @param relational relational to perform
	 * @param c Array of constants
	 */
	public native void relationalConst(VipsOperationRelational relational, double[] c) throws VipsException;
	
	/**
	 * VipsRemainder (remainder): remainder after integer division of two images
	 * @param right Right-hand image argument
	 */
	public native void remainder(Image right) throws VipsException;
	
	/**
	 * VipsRemainderConst (remainder_const): remainder after integer division of an image and a constant
	 * @param c Array of constants
	 */
	public native void remainderConst(double[] c) throws VipsException;
	
	/**
	 * VipsReplicate (replicate): replicate an image
	 * @param across Repeat this many times horizontally
	 * @param down Repeat this many times vertically
	 */
	public native void replicate(int across, int down) throws VipsException;
	
	/**
	 * VipsResize (resize): resize an image
	 * @param scale Scale image by this factor
	 * @param options optional arguments
	 */
	public native void resize(double scale, ResizeOptions options) throws VipsException;
	
	/**
	 * VipsResize (resize): resize an image
	 * @param scale Scale image by this factor
	 */
	public void resize(double scale) throws VipsException {
		resize(scale, null);
	}
	
	/**
	 * VipsRot (rot): rotate an image
	 * @param angle Angle to rotate image
	 */
	public native void rot(VipsAngle angle) throws VipsException;
	
	/**
	 * VipsRot45 (rot45): rotate an image
	 * @param options optional arguments
	 */
	public native void rot45(Rot45Options options) throws VipsException;
	
	/**
	 * VipsRot45 (rot45): rotate an image
	 */
	public void rot45() throws VipsException {
		rot45(null);
	}
	
	/**
	 * VipsRound (round): perform a round function on an image
	 * @param round rounding operation to perform
	 */
	public native void round(VipsOperationRound round) throws VipsException;
	
	/**
	 * VipsScale (scale): scale an image to uchar
	 * @param options optional arguments
	 */
	public native void scale(ScaleOptions options) throws VipsException;
	
	/**
	 * VipsScale (scale): scale an image to uchar
	 */
	public void scale() throws VipsException {
		scale(null);
	}
	
	/**
	 * VipsscRGB2BW (scRGB2BW): convert scRGB to BW
	 * @param options optional arguments
	 */
	public native void scRGB2BW(ScRGB2BWOptions options) throws VipsException;
	
	/**
	 * VipsscRGB2BW (scRGB2BW): convert scRGB to BW
	 */
	public void scRGB2BW() throws VipsException {
		scRGB2BW(null);
	}
	
	/**
	 * VipsscRGB2sRGB (scRGB2sRGB): convert an scRGB image to sRGB
	 * @param options optional arguments
	 */
	public native void scRGB2sRGB(ScRGB2sRGBOptions options) throws VipsException;
	
	/**
	 * VipsscRGB2sRGB (scRGB2sRGB): convert an scRGB image to sRGB
	 */
	public void scRGB2sRGB() throws VipsException {
		scRGB2sRGB(null);
	}
	
	/**
	 * VipsscRGB2XYZ (scRGB2XYZ): transform scRGB to XYZ
	 */
	public native void scRGB2XYZ() throws VipsException;
	
	/**
	 * VipsSequential (sequential): check sequential access
	 * @param options optional arguments
	 */
	public native void sequential(SequentialOptions options) throws VipsException;
	
	/**
	 * VipsSequential (sequential): check sequential access
	 */
	public void sequential() throws VipsException {
		sequential(null);
	}
	
	/**
	 * VipsSharpen (sharpen): unsharp masking for print
	 * @param options optional arguments
	 */
	public native void sharpen(SharpenOptions options) throws VipsException;
	
	/**
	 * VipsSharpen (sharpen): unsharp masking for print
	 */
	public void sharpen() throws VipsException {
		sharpen(null);
	}
	
	/**
	 * VipsShrink (shrink): shrink an image
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 */
	public native void shrink(double hshrink, double vshrink) throws VipsException;
	
	/**
	 * VipsShrinkh (shrinkh): shrink an image horizontally
	 * @param hshrink Horizontal shrink factor
	 */
	public native void shrinkh(int hshrink) throws VipsException;
	
	/**
	 * VipsShrinkv (shrinkv): shrink an image vertically
	 * @param vshrink Vertical shrink factor
	 */
	public native void shrinkv(int vshrink) throws VipsException;
	
	/**
	 * VipsSign (sign): unit vector of pixel
	 */
	public native void sign() throws VipsException;
	
	/**
	 * VipsSines (sines): make a 2D sine wave
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage sines(int width, int height, SinesOptions options) throws VipsException;
	
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
	 * @param width Width of extract area
	 * @param height Height of extract area
	 * @param options optional arguments
	 */
	public native void smartcrop(int width, int height, SmartcropOptions options) throws VipsException;
	
	/**
	 * VipsSmartcrop (smartcrop): extract an area from an image
	 * @param width Width of extract area
	 * @param height Height of extract area
	 */
	public void smartcrop(int width, int height) throws VipsException {
		smartcrop(width, height, null);
	}
	
	/**
	 * VipsSobel (sobel): Sobel edge detector
	 */
	public native void sobel() throws VipsException;
	
	/**
	 * VipsSpcor (spcor): spatial correlation
	 * @param ref Input reference image
	 */
	public native void spcor(Image ref) throws VipsException;
	
	/**
	 * VipsSpectrum (spectrum): make displayable power spectrum
	 */
	public native void spectrum() throws VipsException;
	
	/**
	 * VipssRGB2HSV (sRGB2HSV): transform sRGB to HSV
	 */
	public native void sRGB2HSV() throws VipsException;
	
	/**
	 * VipssRGB2scRGB (sRGB2scRGB): convert an sRGB image to scRGB
	 */
	public native void sRGB2scRGB() throws VipsException;
	
	/**
	 * VipsStats (stats): find many image stats
	 */
	public native void stats() throws VipsException;
	
	/**
	 * VipsStdif (stdif): statistical difference
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 * @param options optional arguments
	 */
	public native void stdif(int width, int height, StdifOptions options) throws VipsException;
	
	/**
	 * VipsStdif (stdif): statistical difference
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 */
	public void stdif(int width, int height) throws VipsException {
		stdif(width, height, null);
	}
	
	/**
	 * VipsSubsample (subsample): subsample an image
	 * @param xfac Horizontal subsample factor
	 * @param yfac Vertical subsample factor
	 * @param options optional arguments
	 */
	public native void subsample(int xfac, int yfac, SubsampleOptions options) throws VipsException;
	
	/**
	 * VipsSubsample (subsample): subsample an image
	 * @param xfac Horizontal subsample factor
	 * @param yfac Vertical subsample factor
	 */
	public void subsample(int xfac, int yfac) throws VipsException {
		subsample(xfac, yfac, null);
	}
	
	/**
	 * VipsSubtract (subtract): subtract two images
	 * @param right Right-hand image argument
	 */
	public native void subtract(Image right) throws VipsException;
	
	/**
	 * VipsSum (sum): sum an array of images
	 * @param in Array of input images
	 */
	public static native VipsImage sum(Image[] in) throws VipsException;
	
	/**
	 * VipsForeignLoadSvgFile (svgload): load SVG with rsvg
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage svgLoad(String filename, SvgLoadOptions options) throws VipsException;
	
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
	public static native VipsImage svgLoadBuffer(byte[] buffer, SvgLoadBufferOptions options) throws VipsException;
	
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
	public static native VipsImage switchOp(Image[] tests) throws VipsException;
	
	/**
	 * VipsSystem (system): run an external command
	 * @param cmdFormat Command to run
	 * @param options optional arguments
	 */
	public static native void system(String cmdFormat, SystemOptions options) throws VipsException;
	
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
	public static native VipsImage text(String text, TextOptions options) throws VipsException;
	
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
	public static native VipsImage thumbnail(String filename, int width, ThumbnailOptions options) throws VipsException;
	
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
	public static native VipsImage thumbnailBuffer(byte[] buffer, int width, ThumbnailBufferOptions options) throws VipsException;
	
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
	 * @param width Size to this width
	 * @param options optional arguments
	 */
	public native void thumbnailImage(int width, ThumbnailImageOptions options) throws VipsException;
	
	/**
	 * VipsThumbnailImage (thumbnail_image): generate thumbnail from image
	 * @param width Size to this width
	 */
	public void thumbnailImage(int width) throws VipsException {
		thumbnailImage(width, null);
	}
	
	/**
	 * VipsForeignLoadTiffFile (tiffload): load tiff from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage tiffLoad(String filename, TIFFLoadOptions options) throws VipsException;
	
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
	public static native VipsImage tiffLoadBuffer(byte[] buffer, TIFFLoadBufferOptions options) throws VipsException;
	
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
	public native void tiffSave(String filename, TIFFSaveOptions options) throws VipsException;
	
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
	public native byte[] tiffSaveBuffer(TIFFSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveTiffBuffer (tiffsave_buffer): save image to tiff buffer
	 */
	public byte[] tiffSaveBuffer() throws VipsException {
		return tiffSaveBuffer(null);
	}
	
	/**
	 * VipsTileCache (tilecache): cache an image as a set of tiles
	 * @param options optional arguments
	 */
	public native void tilecache(TilecacheOptions options) throws VipsException;
	
	/**
	 * VipsTileCache (tilecache): cache an image as a set of tiles
	 */
	public void tilecache() throws VipsException {
		tilecache(null);
	}
	
	/**
	 * VipsTonelut (tonelut): build a look-up table
	 * @param options optional arguments
	 */
	public static native VipsImage tonelut(ToneLUTOptions options) throws VipsException;
	
	/**
	 * VipsTonelut (tonelut): build a look-up table
	 */
	public static VipsImage tonelut() throws VipsException {
		return tonelut(null);
	}
	
	/**
	 * VipsTranspose3d (transpose3d): transpose3d an image
	 * @param options optional arguments
	 */
	public native void transpose3d(Transpose3dOptions options) throws VipsException;
	
	/**
	 * VipsTranspose3d (transpose3d): transpose3d an image
	 */
	public void transpose3d() throws VipsException {
		transpose3d(null);
	}
	
	/**
	 * VipsUnpremultiply (unpremultiply): unpremultiply image alpha
	 * @param options optional arguments
	 */
	public native void unpremultiply(UnpremultiplyOptions options) throws VipsException;
	
	/**
	 * VipsUnpremultiply (unpremultiply): unpremultiply image alpha
	 */
	public void unpremultiply() throws VipsException {
		unpremultiply(null);
	}
	
	/**
	 * VipsForeignLoadVipsFile (vipsload): load vips from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage vipsLoad(String filename, VipsLoadOptions options) throws VipsException;
	
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
	public native void vipsSave(String filename, VipsSaveOptions options) throws VipsException;
	
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
	public static native VipsImage webpLoad(String filename, WebpLoadOptions options) throws VipsException;
	
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
	public static native VipsImage webpLoadBuffer(byte[] buffer, WebpLoadBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignLoadWebpBuffer (webpload_buffer): load webp from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage webpLoadBuffer(byte[] buffer) throws VipsException {
		return webpLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveWebpFile (webpsave): save image to webp file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void webpSave(String filename, WebpSaveOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveWebpFile (webpsave): save image to webp file
	 * @param filename Filename to save to
	 */
	public void webpSave(String filename) throws VipsException {
		webpSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveWebpBuffer (webpsave_buffer): save image to webp buffer
	 * @param options optional arguments
	 */
	public native byte[] webpSaveBuffer(WebpSaveBufferOptions options) throws VipsException;
	
	/**
	 * VipsForeignSaveWebpBuffer (webpsave_buffer): save image to webp buffer
	 */
	public byte[] webpSaveBuffer() throws VipsException {
		return webpSaveBuffer(null);
	}
	
	/**
	 * VipsWorley (worley): make a worley noise image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage worley(int width, int height, WorleyOptions options) throws VipsException;
	
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
	 * @param options optional arguments
	 */
	public native void wrap(WrapOptions options) throws VipsException;
	
	/**
	 * VipsWrap (wrap): wrap image origin
	 */
	public void wrap() throws VipsException {
		wrap(null);
	}
	
	/**
	 * VipsXyz (xyz): make an image where pixel values are coordinates
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage xyz(int width, int height, XYZOptions options) throws VipsException;
	
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
	 */
	public native void xyz2cmyk() throws VipsException;
	
	/**
	 * VipsXYZ2Lab (XYZ2Lab): transform XYZ to Lab
	 * @param options optional arguments
	 */
	public native void xYZ2Lab(XYZ2LabOptions options) throws VipsException;
	
	/**
	 * VipsXYZ2Lab (XYZ2Lab): transform XYZ to Lab
	 */
	public void xYZ2Lab() throws VipsException {
		xYZ2Lab(null);
	}
	
	/**
	 * VipsXYZ2scRGB (XYZ2scRGB): transform XYZ to scRGB
	 */
	public native void xYZ2scRGB() throws VipsException;
	
	/**
	 * VipsXYZ2Yxy (XYZ2Yxy): transform XYZ to Yxy
	 */
	public native void xYZ2Yxy() throws VipsException;
	
	/**
	 * VipsYxy2XYZ (Yxy2XYZ): transform Yxy to XYZ
	 */
	public native void yxy2XYZ() throws VipsException;
	
	/**
	 * VipsZone (zone): make a zone plate
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage zone(int width, int height, ZoneOptions options) throws VipsException;
	
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
	 * @param xfac Horizontal zoom factor
	 * @param yfac Vertical zoom factor
	 */
	public native void zoom(int xfac, int yfac) throws VipsException;
	
}
