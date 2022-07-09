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
	public native void abs();
	
	/**
	 * VipsAdd (add): add two images
	 * @param right Right-hand image argument
	 */
	public native void add(VipsImage right);
	
	/**
	 * VipsForeignLoadAnalyze (analyzeload): load an Analyze6 image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage analyzeLoad(String filename, AnalyzeLoadOptions options);
	
	/**
	 * VipsForeignLoadAnalyze (analyzeload): load an Analyze6 image
	 * @param filename Filename to load from
	 */
	public static VipsImage analyzeLoad(String filename) {
		return analyzeLoad(filename, null);
	}
	
	/**
	 * VipsAutorot (autorot): autorotate image by exif tag
	 */
	public native void autorot();
	
	/**
	 * VipsAvg (avg): find image average
	 */
	public native double avg();
	
	/**
	 * VipsBandbool (bandbool): boolean operation across image bands
	 * @param booleanParam boolean to perform
	 */
	public native void bandbool(VipsOperationBoolean booleanParam);
	
	/**
	 * VipsBandfold (bandfold): fold up x axis into bands
	 * @param options optional arguments
	 */
	public native void bandfold(BandfoldOptions options);
	
	/**
	 * VipsBandfold (bandfold): fold up x axis into bands
	 */
	public void bandfold() {
		bandfold(null);
	}
	
	/**
	 * VipsBandjoinConst (bandjoin_const): append a constant band to an image
	 * @param c Array of constants to add
	 */
	public native void bandjoinConst(PixelPacket c);
	
	/**
	 * VipsBandmean (bandmean): band-wise average
	 */
	public native void bandmean();
	
	/**
	 * VipsBandunfold (bandunfold): unfold image bands into x axis
	 * @param options optional arguments
	 */
	public native void bandunfold(BandunfoldOptions options);
	
	/**
	 * VipsBandunfold (bandunfold): unfold image bands into x axis
	 */
	public void bandunfold() {
		bandunfold(null);
	}
	
	/**
	 * VipsBlack (black): make a black image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage black(int width, int height, BlackOptions options);
	
	/**
	 * VipsBlack (black): make a black image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage black(int width, int height) {
		return black(width, height, null);
	}
	
	/**
	 * VipsBoolean (boolean): boolean operation on two images
	 * @param right Right-hand image argument
	 * @param booleanParam boolean to perform
	 */
	public native void booleanOp(VipsImage right, VipsOperationBoolean booleanParam);
	
	/**
	 * VipsBooleanConst (boolean_const): boolean operations against a constant
	 * @param booleanParam boolean to perform
	 * @param c Array of constants
	 */
	public native void booleanConst(VipsOperationBoolean booleanParam, PixelPacket c);
	
	/**
	 * VipsBuildlut (buildlut): build a look-up table
	 */
	public native void buildlut();
	
	/**
	 * VipsByteswap (byteswap): byteswap an image
	 */
	public native void byteswap();
	
	/**
	 * VipsCache (cache): cache an image
	 * @param options optional arguments
	 */
	public native void cache(CacheOptions options);
	
	/**
	 * VipsCache (cache): cache an image
	 */
	public void cache() {
		cache(null);
	}
	
	/**
	 * VipsCanny (canny): Canny edge detector
	 * @param options optional arguments
	 */
	public native void canny(CannyOptions options);
	
	/**
	 * VipsCanny (canny): Canny edge detector
	 */
	public void canny() {
		canny(null);
	}
	
	/**
	 * VipsCast (cast): cast an image
	 * @param format Format to cast to
	 * @param options optional arguments
	 */
	public native void cast(VipsBandFormat format, CastOptions options);
	
	/**
	 * VipsCast (cast): cast an image
	 * @param format Format to cast to
	 */
	public void cast(VipsBandFormat format) {
		cast(format, null);
	}
	
	/**
	 * VipsCMC2LCh (CMC2LCh): transform LCh to CMC
	 */
	public native void cMC2LCh();
	
	/**
	 * VipsCMYK2XYZ (CMYK2XYZ): transform CMYK to XYZ
	 */
	public native void cmyk2xyz();
	
	/**
	 * VipsColourspace (colourspace): convert to a new colourspace
	 * @param space Destination colour space
	 * @param options optional arguments
	 */
	public native void colourspace(VipsInterpretation space, ColourspaceOptions options);
	
	/**
	 * VipsColourspace (colourspace): convert to a new colourspace
	 * @param space Destination colour space
	 */
	public void colourspace(VipsInterpretation space) {
		colourspace(space, null);
	}
	
	/**
	 * VipsCompass (compass): convolve with rotating mask
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void compass(VipsImage mask, CompassOptions options);
	
	/**
	 * VipsCompass (compass): convolve with rotating mask
	 * @param mask Input matrix image
	 */
	public void compass(VipsImage mask) {
		compass(mask, null);
	}
	
	/**
	 * VipsComplex (complex): perform a complex operation on an image
	 * @param cmplx complex to perform
	 */
	public native void complex(VipsOperationComplex cmplx);
	
	/**
	 * VipsComplex2 (complex2): complex binary operations on two images
	 * @param right Right-hand image argument
	 * @param cmplx binary complex operation to perform
	 */
	public native void complex2(VipsImage right, VipsOperationComplex2 cmplx);
	
	/**
	 * VipsComplexform (complexform): form a complex image from two real images
	 * @param right Right-hand image argument
	 */
	public native void complexform(VipsImage right);
	
	/**
	 * VipsComplexget (complexget): get a component from a complex image
	 * @param get complex to perform
	 */
	public native void complexget(VipsOperationComplexget get);
	
	/**
	 * VipsComposite2 (composite2): blend a pair of images with a blend mode
	 * @param overlay Overlay image
	 * @param mode VipsBlendMode to join with
	 * @param options optional arguments
	 */
	public native void composite2(VipsImage overlay, VipsBlendMode mode, Composite2Options options);
	
	/**
	 * VipsComposite2 (composite2): blend a pair of images with a blend mode
	 * @param overlay Overlay image
	 * @param mode VipsBlendMode to join with
	 */
	public void composite2(VipsImage overlay, VipsBlendMode mode) {
		composite2(overlay, mode, null);
	}
	
	/**
	 * VipsConv (conv): convolution operation
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void conv(VipsImage mask, ConvOptions options);
	
	/**
	 * VipsConv (conv): convolution operation
	 * @param mask Input matrix image
	 */
	public void conv(VipsImage mask) {
		conv(mask, null);
	}
	
	/**
	 * VipsConva (conva): approximate integer convolution
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void conva(VipsImage mask, ConvaOptions options);
	
	/**
	 * VipsConva (conva): approximate integer convolution
	 * @param mask Input matrix image
	 */
	public void conva(VipsImage mask) {
		conva(mask, null);
	}
	
	/**
	 * VipsConvasep (convasep): approximate separable integer convolution
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void convasep(VipsImage mask, ConvasepOptions options);
	
	/**
	 * VipsConvasep (convasep): approximate separable integer convolution
	 * @param mask Input matrix image
	 */
	public void convasep(VipsImage mask) {
		convasep(mask, null);
	}
	
	/**
	 * VipsConvf (convf): float convolution operation
	 * @param mask Input matrix image
	 */
	public native void convf(VipsImage mask);
	
	/**
	 * VipsConvi (convi): int convolution operation
	 * @param mask Input matrix image
	 */
	public native void convi(VipsImage mask);
	
	/**
	 * VipsConvsep (convsep): seperable convolution operation
	 * @param mask Input matrix image
	 * @param options optional arguments
	 */
	public native void convsep(VipsImage mask, ConvsepOptions options);
	
	/**
	 * VipsConvsep (convsep): seperable convolution operation
	 * @param mask Input matrix image
	 */
	public void convsep(VipsImage mask) {
		convsep(mask, null);
	}
	
	/**
	 * VipsCopy (copy): copy an image
	 * @param options optional arguments
	 */
	public native void copy(CopyOptions options);
	
	/**
	 * VipsCopy (copy): copy an image
	 */
	public void copy() {
		copy(null);
	}
	
	/**
	 * VipsCountlines (countlines): count lines in an image
	 * @param direction Countlines left-right or up-down
	 */
	public native double countlines(VipsDirection direction);
	
	/**
	 * VipsForeignLoadCsvFile (csvload): load csv
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage csvLoad(String filename, CSVLoadOptions options);
	
	/**
	 * VipsForeignLoadCsvFile (csvload): load csv
	 * @param filename Filename to load from
	 */
	public static VipsImage csvLoad(String filename) {
		return csvLoad(filename, null);
	}
	
	/**
	 * VipsForeignSaveCsvFile (csvsave): save image to csv
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void csvSave(String filename, CSVSaveOptions options);
	
	/**
	 * VipsForeignSaveCsvFile (csvsave): save image to csv
	 * @param filename Filename to save to
	 */
	public void csvSave(String filename) {
		csvSave(filename, null);
	}
	
	/**
	 * VipsdE00 (dE00): calculate dE00
	 * @param right Right-hand input image
	 */
	public native void dE00(VipsImage right);
	
	/**
	 * VipsdE76 (dE76): calculate dE76
	 * @param right Right-hand input image
	 */
	public native void dE76(VipsImage right);
	
	/**
	 * VipsdECMC (dECMC): calculate dECMC
	 * @param right Right-hand input image
	 */
	public native void dECMC(VipsImage right);
	
	/**
	 * VipsDeviate (deviate): find image standard deviation
	 */
	public native double deviate();
	
	/**
	 * VipsDivide (divide): divide two images
	 * @param right Right-hand image argument
	 */
	public native void divide(VipsImage right);
	
	/**
	 * VipsDrawCircle (draw_circle): draw a circle on an image
	 * @param ink Color for pixels
	 * @param cx Centre of draw_circle
	 * @param cy Centre of draw_circle
	 * @param radius Radius in pixels
	 * @param options optional arguments
	 */
	public native void drawCircle(PixelPacket ink, int cx, int cy, int radius, DrawCircleOptions options);
	
	/**
	 * VipsDrawCircle (draw_circle): draw a circle on an image
	 * @param ink Color for pixels
	 * @param cx Centre of draw_circle
	 * @param cy Centre of draw_circle
	 * @param radius Radius in pixels
	 */
	public void drawCircle(PixelPacket ink, int cx, int cy, int radius) {
		drawCircle(ink, cx, cy, radius, null);
	}
	
	/**
	 * VipsDrawImage (draw_image): paint an image into another image
	 * @param sub Sub-image to insert into main image
	 * @param x Draw image here
	 * @param y Draw image here
	 * @param options optional arguments
	 */
	public native void drawImage(VipsImage sub, int x, int y, DrawImageOptions options);
	
	/**
	 * VipsDrawImage (draw_image): paint an image into another image
	 * @param sub Sub-image to insert into main image
	 * @param x Draw image here
	 * @param y Draw image here
	 */
	public void drawImage(VipsImage sub, int x, int y) {
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
	public native void drawLine(PixelPacket ink, int x1, int y1, int x2, int y2);
	
	/**
	 * VipsDrawMask (draw_mask): draw a mask on an image
	 * @param ink Color for pixels
	 * @param mask Mask of pixels to draw
	 * @param x Draw mask here
	 * @param y Draw mask here
	 */
	public native void drawMask(PixelPacket ink, VipsImage mask, int x, int y);
	
	/**
	 * VipsDrawRect (draw_rect): paint a rectangle on an image
	 * @param ink Color for pixels
	 * @param left Rect to fill
	 * @param top Rect to fill
	 * @param width Rect to fill
	 * @param height Rect to fill
	 * @param options optional arguments
	 */
	public native void drawRect(PixelPacket ink, int left, int top, int width, int height, DrawRectOptions options);
	
	/**
	 * VipsDrawRect (draw_rect): paint a rectangle on an image
	 * @param ink Color for pixels
	 * @param left Rect to fill
	 * @param top Rect to fill
	 * @param width Rect to fill
	 * @param height Rect to fill
	 */
	public void drawRect(PixelPacket ink, int left, int top, int width, int height) {
		drawRect(ink, left, top, width, height, null);
	}
	
	/**
	 * VipsDrawSmudge (draw_smudge): blur a rectangle on an image
	 * @param left Rect to fill
	 * @param top Rect to fill
	 * @param width Rect to fill
	 * @param height Rect to fill
	 */
	public native void drawSmudge(int left, int top, int width, int height);
	
	/**
	 * VipsForeignSaveDzFile (dzsave): save image to deepzoom file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void dzSave(String filename, DZSaveOptions options);
	
	/**
	 * VipsForeignSaveDzFile (dzsave): save image to deepzoom file
	 * @param filename Filename to save to
	 */
	public void dzSave(String filename) {
		dzSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveDzBuffer (dzsave_buffer): save image to dz buffer
	 * @param options optional arguments
	 */
	public native byte[] dzSaveBuffer(DZSaveBufferOptions options);
	
	/**
	 * VipsForeignSaveDzBuffer (dzsave_buffer): save image to dz buffer
	 */
	public byte[] dzSaveBuffer() {
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
	public native void embed(int x, int y, int width, int height, EmbedOptions options);
	
	/**
	 * VipsEmbed (embed): embed an image in a larger image
	 * @param x Left edge of input in output
	 * @param y Top edge of input in output
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public void embed(int x, int y, int width, int height) {
		embed(x, y, width, height, null);
	}
	
	/**
	 * VipsExtractArea (extract_area): extract an area from an image
	 * @param left Left edge of extract area
	 * @param top Top edge of extract area
	 * @param width Width of extract area
	 * @param height Height of extract area
	 */
	public native VipsImage extractArea(int left, int top, int width, int height);
	
	/**
	 * VipsExtractBand (extract_band): extract band from an image
	 * @param band Band to extract
	 * @param options optional arguments
	 */
	public native VipsImage extractBand(int band, ExtractBandOptions options);
	
	/**
	 * VipsExtractBand (extract_band): extract band from an image
	 * @param band Band to extract
	 */
	public VipsImage extractBand(int band) {
		return extractBand(band, null);
	}
	
	/**
	 * VipsEye (eye): make an image showing the eye's spatial response
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage eye(int width, int height, EyeOptions options);
	
	/**
	 * VipsEye (eye): make an image showing the eye's spatial response
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage eye(int width, int height) {
		return eye(width, height, null);
	}
	
	/**
	 * VipsFalsecolour (falsecolour): false-colour an image
	 */
	public native void falsecolour();
	
	/**
	 * VipsFastcor (fastcor): fast correlation
	 * @param ref Input reference image
	 */
	public native void fastcor(VipsImage ref);
	
	/**
	 * VipsFillNearest (fill_nearest): fill image zeros with nearest non-zero pixel
	 */
	public native void fillNearest();
	
	/**
	 * VipsForeignLoadFitsFile (fitsload): load a FITS image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage fitsLoad(String filename, FITSLoadOptions options);
	
	/**
	 * VipsForeignLoadFitsFile (fitsload): load a FITS image
	 * @param filename Filename to load from
	 */
	public static VipsImage fitsLoad(String filename) {
		return fitsLoad(filename, null);
	}
	
	/**
	 * VipsForeignSaveFits (fitssave): save image to fits file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void fitsSave(String filename, FITSSaveOptions options);
	
	/**
	 * VipsForeignSaveFits (fitssave): save image to fits file
	 * @param filename Filename to save to
	 */
	public void fitsSave(String filename) {
		fitsSave(filename, null);
	}
	
	/**
	 * VipsFlatten (flatten): flatten alpha out of an image
	 * @param options optional arguments
	 */
	public native void flatten(FlattenOptions options);
	
	/**
	 * VipsFlatten (flatten): flatten alpha out of an image
	 */
	public void flatten() {
		flatten(null);
	}
	
	/**
	 * VipsFlip (flip): flip an image
	 * @param direction Direction to flip image
	 */
	public native void flip(VipsDirection direction);
	
	/**
	 * VipsFloat2rad (float2rad): transform float RGB to Radiance coding
	 */
	public native void float2rad();
	
	/**
	 * VipsFractsurf (fractsurf): make a fractal surface
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param fractalDimension Fractal dimension
	 */
	public static native VipsImage fractsurf(int width, int height, double fractalDimension);
	
	/**
	 * VipsFreqmult (freqmult): frequency-domain filtering
	 * @param mask Input mask image
	 */
	public native void freqmult(VipsImage mask);
	
	/**
	 * VipsFwfft (fwfft): forward FFT
	 */
	public native void fwfft();
	
	/**
	 * VipsGamma (gamma): gamma an image
	 * @param options optional arguments
	 */
	public native void gamma(GammaOptions options);
	
	/**
	 * VipsGamma (gamma): gamma an image
	 */
	public void gamma() {
		gamma(null);
	}
	
	/**
	 * VipsGaussblur (gaussblur): gaussian blur
	 * @param sigma Sigma of Gaussian
	 * @param options optional arguments
	 */
	public native void gaussblur(double sigma, GaussblurOptions options);
	
	/**
	 * VipsGaussblur (gaussblur): gaussian blur
	 * @param sigma Sigma of Gaussian
	 */
	public void gaussblur(double sigma) {
		gaussblur(sigma, null);
	}
	
	/**
	 * VipsGaussmat (gaussmat): make a gaussian image
	 * @param sigma Sigma of Gaussian
	 * @param minAmpl Minimum amplitude of Gaussian
	 * @param options optional arguments
	 */
	public static native VipsImage gaussmat(double sigma, double minAmpl, GaussmatOptions options);
	
	/**
	 * VipsGaussmat (gaussmat): make a gaussian image
	 * @param sigma Sigma of Gaussian
	 * @param minAmpl Minimum amplitude of Gaussian
	 */
	public static VipsImage gaussmat(double sigma, double minAmpl) {
		return gaussmat(sigma, minAmpl, null);
	}
	
	/**
	 * VipsGaussnoise (gaussnoise): make a gaussnoise image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage gaussnoise(int width, int height, GaussnoiseOptions options);
	
	/**
	 * VipsGaussnoise (gaussnoise): make a gaussnoise image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage gaussnoise(int width, int height) {
		return gaussnoise(width, height, null);
	}
	
	/**
	 * VipsGetpoint (getpoint): read a point from an image
	 * @param x Point to read
	 * @param y Point to read
	 */
	public native PixelPacket getpoint(int x, int y);
	
	/**
	 * VipsForeignLoadNsgifFile (gifload): load GIF with libnsgif
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage gifLoad(String filename, GIFLoadOptions options);
	
	/**
	 * VipsForeignLoadNsgifFile (gifload): load GIF with libnsgif
	 * @param filename Filename to load from
	 */
	public static VipsImage gifLoad(String filename) {
		return gifLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadNsgifBuffer (gifload_buffer): load GIF with libnsgif
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage gifLoadBuffer(byte[] buffer, GIFLoadBufferOptions options);
	
	/**
	 * VipsForeignLoadNsgifBuffer (gifload_buffer): load GIF with libnsgif
	 * @param buffer Buffer to load from
	 */
	public static VipsImage gifLoadBuffer(byte[] buffer) {
		return gifLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveCgifFile (gifsave): save as gif
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void gifSave(String filename, GIFSaveOptions options);
	
	/**
	 * VipsForeignSaveCgifFile (gifsave): save as gif
	 * @param filename Filename to save to
	 */
	public void gifSave(String filename) {
		gifSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveCgifBuffer (gifsave_buffer): save as gif
	 * @param options optional arguments
	 */
	public native byte[] gifSaveBuffer(GIFSaveBufferOptions options);
	
	/**
	 * VipsForeignSaveCgifBuffer (gifsave_buffer): save as gif
	 */
	public byte[] gifSaveBuffer() {
		return gifSaveBuffer(null);
	}
	
	/**
	 * VipsGlobalbalance (globalbalance): global balance an image mosaic
	 * @param options optional arguments
	 */
	public native void globalbalance(GlobalbalanceOptions options);
	
	/**
	 * VipsGlobalbalance (globalbalance): global balance an image mosaic
	 */
	public void globalbalance() {
		globalbalance(null);
	}
	
	/**
	 * VipsGravity (gravity): place an image within a larger image with a certain gravity
	 * @param direction direction to place image within width/height
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public native void gravity(VipsCompassDirection direction, int width, int height, GravityOptions options);
	
	/**
	 * VipsGravity (gravity): place an image within a larger image with a certain gravity
	 * @param direction direction to place image within width/height
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public void gravity(VipsCompassDirection direction, int width, int height) {
		gravity(direction, width, height, null);
	}
	
	/**
	 * VipsGrey (grey): make a grey ramp image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage grey(int width, int height, GreyOptions options);
	
	/**
	 * VipsGrey (grey): make a grey ramp image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage grey(int width, int height) {
		return grey(width, height, null);
	}
	
	/**
	 * VipsGrid (grid): grid an image
	 * @param tileHeight chop into tiles this high
	 * @param across number of tiles across
	 * @param down number of tiles down
	 */
	public native void grid(int tileHeight, int across, int down);
	
	/**
	 * VipsForeignLoadHeifFile (heifload): load a HEIF image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage heifLoad(String filename, HEIFLoadOptions options);
	
	/**
	 * VipsForeignLoadHeifFile (heifload): load a HEIF image
	 * @param filename Filename to load from
	 */
	public static VipsImage heifLoad(String filename) {
		return heifLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadHeifBuffer (heifload_buffer): load a HEIF image
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage heifLoadBuffer(byte[] buffer, HEIFLoadBufferOptions options);
	
	/**
	 * VipsForeignLoadHeifBuffer (heifload_buffer): load a HEIF image
	 * @param buffer Buffer to load from
	 */
	public static VipsImage heifLoadBuffer(byte[] buffer) {
		return heifLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveHeifFile (heifsave): save image in HEIF format
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void heifSave(String filename, HEIFSaveOptions options);
	
	/**
	 * VipsForeignSaveHeifFile (heifsave): save image in HEIF format
	 * @param filename Filename to save to
	 */
	public void heifSave(String filename) {
		heifSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveHeifBuffer (heifsave_buffer): save image in HEIF format
	 * @param options optional arguments
	 */
	public native byte[] heifSaveBuffer(HEIFSaveBufferOptions options);
	
	/**
	 * VipsForeignSaveHeifBuffer (heifsave_buffer): save image in HEIF format
	 */
	public byte[] heifSaveBuffer() {
		return heifSaveBuffer(null);
	}
	
	/**
	 * VipsHistCum (hist_cum): form cumulative histogram
	 */
	public native void histCum();
	
	/**
	 * VipsHistEntropy (hist_entropy): estimate image entropy
	 */
	public native double histEntropy();
	
	/**
	 * VipsHistEqual (hist_equal): histogram equalisation
	 * @param options optional arguments
	 */
	public native void histEqual(HistEqualOptions options);
	
	/**
	 * VipsHistEqual (hist_equal): histogram equalisation
	 */
	public void histEqual() {
		histEqual(null);
	}
	
	/**
	 * VipsHistFind (hist_find): find image histogram
	 * @param options optional arguments
	 */
	public native void histFind(HistFindOptions options);
	
	/**
	 * VipsHistFind (hist_find): find image histogram
	 */
	public void histFind() {
		histFind(null);
	}
	
	/**
	 * VipsHistFindIndexed (hist_find_indexed): find indexed image histogram
	 * @param index Index image
	 * @param options optional arguments
	 */
	public native void histFindIndexed(VipsImage index, HistFindIndexedOptions options);
	
	/**
	 * VipsHistFindIndexed (hist_find_indexed): find indexed image histogram
	 * @param index Index image
	 */
	public void histFindIndexed(VipsImage index) {
		histFindIndexed(index, null);
	}
	
	/**
	 * VipsHistFindNDim (hist_find_ndim): find n-dimensional image histogram
	 * @param options optional arguments
	 */
	public native void histFindNdim(HistFindNdimOptions options);
	
	/**
	 * VipsHistFindNDim (hist_find_ndim): find n-dimensional image histogram
	 */
	public void histFindNdim() {
		histFindNdim(null);
	}
	
	/**
	 * VipsHistLocal (hist_local): local histogram equalisation
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 * @param options optional arguments
	 */
	public native void histLocal(int width, int height, HistLocalOptions options);
	
	/**
	 * VipsHistLocal (hist_local): local histogram equalisation
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 */
	public void histLocal(int width, int height) {
		histLocal(width, height, null);
	}
	
	/**
	 * VipsHistMatch (hist_match): match two histograms
	 * @param ref Reference histogram
	 */
	public native void histMatch(VipsImage ref);
	
	/**
	 * VipsHistNorm (hist_norm): normalise histogram
	 */
	public native void histNorm();
	
	/**
	 * VipsHistPlot (hist_plot): plot histogram
	 */
	public native void histPlot();
	
	/**
	 * VipsHoughCircle (hough_circle): find hough circle transform
	 * @param options optional arguments
	 */
	public native void houghCircle(HoughCircleOptions options);
	
	/**
	 * VipsHoughCircle (hough_circle): find hough circle transform
	 */
	public void houghCircle() {
		houghCircle(null);
	}
	
	/**
	 * VipsHoughLine (hough_line): find hough line transform
	 * @param options optional arguments
	 */
	public native void houghLine(HoughLineOptions options);
	
	/**
	 * VipsHoughLine (hough_line): find hough line transform
	 */
	public void houghLine() {
		houghLine(null);
	}
	
	/**
	 * VipsHSV2sRGB (HSV2sRGB): transform HSV to sRGB
	 */
	public native void hSV2sRGB();
	
	/**
	 * VipsIccExport (icc_export): output to device with ICC profile
	 * @param options optional arguments
	 */
	public native void iccExport(ICCExportOptions options);
	
	/**
	 * VipsIccExport (icc_export): output to device with ICC profile
	 */
	public void iccExport() {
		iccExport(null);
	}
	
	/**
	 * VipsIccImport (icc_import): import from device with ICC profile
	 * @param options optional arguments
	 */
	public native void iccImport(ICCImportOptions options);
	
	/**
	 * VipsIccImport (icc_import): import from device with ICC profile
	 */
	public void iccImport() {
		iccImport(null);
	}
	
	/**
	 * VipsIccTransform (icc_transform): transform between devices with ICC profiles
	 * @param outputProfile Filename to load output profile from
	 * @param options optional arguments
	 */
	public native void iccTransform(String outputProfile, ICCTransformOptions options);
	
	/**
	 * VipsIccTransform (icc_transform): transform between devices with ICC profiles
	 * @param outputProfile Filename to load output profile from
	 */
	public void iccTransform(String outputProfile) {
		iccTransform(outputProfile, null);
	}
	
	/**
	 * VipsIdentity (identity): make a 1D image where pixel values are indexes
	 * @param options optional arguments
	 */
	public static native VipsImage identity(IdentityOptions options);
	
	/**
	 * VipsIdentity (identity): make a 1D image where pixel values are indexes
	 */
	public static VipsImage identity() {
		return identity(null);
	}
	
	/**
	 * VipsIfthenelse (ifthenelse): ifthenelse an image
	 * @param in1 Source for TRUE pixels
	 * @param in2 Source for FALSE pixels
	 * @param options optional arguments
	 */
	public native void ifthenelse(VipsImage in1, VipsImage in2, IfthenelseOptions options);
	
	/**
	 * VipsIfthenelse (ifthenelse): ifthenelse an image
	 * @param in1 Source for TRUE pixels
	 * @param in2 Source for FALSE pixels
	 */
	public void ifthenelse(VipsImage in1, VipsImage in2) {
		ifthenelse(in1, in2, null);
	}
	
	/**
	 * VipsInsert (insert): insert image @sub into @main at @x, @y
	 * @param sub Sub-image to insert into main image
	 * @param x Left edge of sub in main
	 * @param y Top edge of sub in main
	 * @param options optional arguments
	 */
	public native void insert(VipsImage sub, int x, int y, InsertOptions options);
	
	/**
	 * VipsInsert (insert): insert image @sub into @main at @x, @y
	 * @param sub Sub-image to insert into main image
	 * @param x Left edge of sub in main
	 * @param y Top edge of sub in main
	 */
	public void insert(VipsImage sub, int x, int y) {
		insert(sub, x, y, null);
	}
	
	/**
	 * VipsInvert (invert): invert an image
	 */
	public native void invert();
	
	/**
	 * VipsInvertlut (invertlut): build an inverted look-up table
	 * @param options optional arguments
	 */
	public native void invertlut(InvertLUTOptions options);
	
	/**
	 * VipsInvertlut (invertlut): build an inverted look-up table
	 */
	public void invertlut() {
		invertlut(null);
	}
	
	/**
	 * VipsInvfft (invfft): inverse FFT
	 * @param options optional arguments
	 */
	public native void invfft(InvFFTOptions options);
	
	/**
	 * VipsInvfft (invfft): inverse FFT
	 */
	public void invfft() {
		invfft(null);
	}
	
	/**
	 * VipsJoin (join): join a pair of images
	 * @param in2 Second input image
	 * @param direction Join left-right or up-down
	 * @param options optional arguments
	 */
	public native void join(VipsImage in2, VipsDirection direction, JoinOptions options);
	
	/**
	 * VipsJoin (join): join a pair of images
	 * @param in2 Second input image
	 * @param direction Join left-right or up-down
	 */
	public void join(VipsImage in2, VipsDirection direction) {
		join(in2, direction, null);
	}
	
	/**
	 * VipsForeignLoadJp2kFile (jp2kload): load JPEG2000 image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage jp2kLoad(String filename, JP2KLoadOptions options);
	
	/**
	 * VipsForeignLoadJp2kFile (jp2kload): load JPEG2000 image
	 * @param filename Filename to load from
	 */
	public static VipsImage jp2kLoad(String filename) {
		return jp2kLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadJp2kBuffer (jp2kload_buffer): load JPEG2000 image
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage jp2kLoadBuffer(byte[] buffer, JP2KLoadBufferOptions options);
	
	/**
	 * VipsForeignLoadJp2kBuffer (jp2kload_buffer): load JPEG2000 image
	 * @param buffer Buffer to load from
	 */
	public static VipsImage jp2kLoadBuffer(byte[] buffer) {
		return jp2kLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveJp2kFile (jp2ksave): save image in JPEG2000 format
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public native void jp2kSave(String filename, JP2KSaveOptions options);
	
	/**
	 * VipsForeignSaveJp2kFile (jp2ksave): save image in JPEG2000 format
	 * @param filename Filename to load from
	 */
	public void jp2kSave(String filename) {
		jp2kSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveJp2kBuffer (jp2ksave_buffer): save image in JPEG2000 format
	 * @param options optional arguments
	 */
	public native byte[] jp2kSaveBuffer(JP2KSaveBufferOptions options);
	
	/**
	 * VipsForeignSaveJp2kBuffer (jp2ksave_buffer): save image in JPEG2000 format
	 */
	public byte[] jp2kSaveBuffer() {
		return jp2kSaveBuffer(null);
	}
	
	/**
	 * VipsForeignLoadJpegFile (jpegload): load jpeg from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage jpegLoad(String filename, JPEGLoadOptions options);
	
	/**
	 * VipsForeignLoadJpegFile (jpegload): load jpeg from file
	 * @param filename Filename to load from
	 */
	public static VipsImage jpegLoad(String filename) {
		return jpegLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadJpegBuffer (jpegload_buffer): load jpeg from buffer
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage jpegLoadBuffer(byte[] buffer, JPEGLoadBufferOptions options);
	
	/**
	 * VipsForeignLoadJpegBuffer (jpegload_buffer): load jpeg from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage jpegLoadBuffer(byte[] buffer) {
		return jpegLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveJpegFile (jpegsave): save image to jpeg file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void jpegSave(String filename, JPEGSaveOptions options);
	
	/**
	 * VipsForeignSaveJpegFile (jpegsave): save image to jpeg file
	 * @param filename Filename to save to
	 */
	public void jpegSave(String filename) {
		jpegSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveJpegBuffer (jpegsave_buffer): save image to jpeg buffer
	 * @param options optional arguments
	 */
	public native byte[] jpegSaveBuffer(JPEGSaveBufferOptions options);
	
	/**
	 * VipsForeignSaveJpegBuffer (jpegsave_buffer): save image to jpeg buffer
	 */
	public byte[] jpegSaveBuffer() {
		return jpegSaveBuffer(null);
	}
	
	/**
	 * VipsForeignSaveJpegMime (jpegsave_mime): save image to jpeg mime
	 * @param options optional arguments
	 */
	public native void jpegSaveMime(JPEGSaveMimeOptions options);
	
	/**
	 * VipsForeignSaveJpegMime (jpegsave_mime): save image to jpeg mime
	 */
	public void jpegSaveMime() {
		jpegSaveMime(null);
	}
	
	/**
	 * VipsForeignLoadJxlFile (jxlload): load JPEG-XL image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage jxlLoad(String filename, JXLLoadOptions options);
	
	/**
	 * VipsForeignLoadJxlFile (jxlload): load JPEG-XL image
	 * @param filename Filename to load from
	 */
	public static VipsImage jxlLoad(String filename) {
		return jxlLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadJxlBuffer (jxlload_buffer): load JPEG-XL image
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage jxlLoadBuffer(byte[] buffer, JXLLoadBufferOptions options);
	
	/**
	 * VipsForeignLoadJxlBuffer (jxlload_buffer): load JPEG-XL image
	 * @param buffer Buffer to load from
	 */
	public static VipsImage jxlLoadBuffer(byte[] buffer) {
		return jxlLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveJxlFile (jxlsave): save image in JPEG-XL format
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public native void jxlSave(String filename, JXLSaveOptions options);
	
	/**
	 * VipsForeignSaveJxlFile (jxlsave): save image in JPEG-XL format
	 * @param filename Filename to load from
	 */
	public void jxlSave(String filename) {
		jxlSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveJxlBuffer (jxlsave_buffer): save image in JPEG-XL format
	 * @param options optional arguments
	 */
	public native byte[] jxlSaveBuffer(JXLSaveBufferOptions options);
	
	/**
	 * VipsForeignSaveJxlBuffer (jxlsave_buffer): save image in JPEG-XL format
	 */
	public byte[] jxlSaveBuffer() {
		return jxlSaveBuffer(null);
	}
	
	/**
	 * VipsLab2LabQ (Lab2LabQ): transform float Lab to LabQ coding
	 */
	public native void lab2LabQ();
	
	/**
	 * VipsLab2LabS (Lab2LabS): transform float Lab to signed short
	 */
	public native void lab2LabS();
	
	/**
	 * VipsLab2LCh (Lab2LCh): transform Lab to LCh
	 */
	public native void lab2LCh();
	
	/**
	 * VipsLab2XYZ (Lab2XYZ): transform CIELAB to XYZ
	 * @param options optional arguments
	 */
	public native void lab2XYZ(Lab2XYZOptions options);
	
	/**
	 * VipsLab2XYZ (Lab2XYZ): transform CIELAB to XYZ
	 */
	public void lab2XYZ() {
		lab2XYZ(null);
	}
	
	/**
	 * VipsLabelregions (labelregions): label regions in an image
	 */
	public native void labelregions();
	
	/**
	 * VipsLabQ2Lab (LabQ2Lab): unpack a LabQ image to float Lab
	 */
	public native void labQ2Lab();
	
	/**
	 * VipsLabQ2LabS (LabQ2LabS): unpack a LabQ image to short Lab
	 */
	public native void labQ2LabS();
	
	/**
	 * VipsLabQ2sRGB (LabQ2sRGB): convert a LabQ image to sRGB
	 */
	public native void labQ2sRGB();
	
	/**
	 * VipsLabS2Lab (LabS2Lab): transform signed short Lab to float
	 */
	public native void labS2Lab();
	
	/**
	 * VipsLabS2LabQ (LabS2LabQ): transform short Lab to LabQ coding
	 */
	public native void labS2LabQ();
	
	/**
	 * VipsLCh2CMC (LCh2CMC): transform LCh to CMC
	 */
	public native void lCh2CMC();
	
	/**
	 * VipsLCh2Lab (LCh2Lab): transform LCh to Lab
	 */
	public native void lCh2Lab();
	
	/**
	 * VipsLinear (linear): calculate (a * in + b)
	 * @param a Multiply by this
	 * @param b Add this
	 * @param options optional arguments
	 */
	public native void linear(PixelPacket a, PixelPacket b, LinearOptions options);
	
	/**
	 * VipsLinear (linear): calculate (a * in + b)
	 * @param a Multiply by this
	 * @param b Add this
	 */
	public void linear(PixelPacket a, PixelPacket b) {
		linear(a, b, null);
	}
	
	/**
	 * VipsLineCache (linecache): cache an image as a set of lines
	 * @param options optional arguments
	 */
	public native void linecache(LinecacheOptions options);
	
	/**
	 * VipsLineCache (linecache): cache an image as a set of lines
	 */
	public void linecache() {
		linecache(null);
	}
	
	/**
	 * VipsLogmat (logmat): make a Laplacian of Gaussian image
	 * @param sigma Radius of Gaussian
	 * @param minAmpl Minimum amplitude of Gaussian
	 * @param options optional arguments
	 */
	public static native VipsImage logmat(double sigma, double minAmpl, LogmatOptions options);
	
	/**
	 * VipsLogmat (logmat): make a Laplacian of Gaussian image
	 * @param sigma Radius of Gaussian
	 * @param minAmpl Minimum amplitude of Gaussian
	 */
	public static VipsImage logmat(double sigma, double minAmpl) {
		return logmat(sigma, minAmpl, null);
	}
	
	/**
	 * VipsForeignLoadMagick7File (magickload): load file with ImageMagick7
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage magickLoad(String filename, MagickLoadOptions options);
	
	/**
	 * VipsForeignLoadMagick7File (magickload): load file with ImageMagick7
	 * @param filename Filename to load from
	 */
	public static VipsImage magickLoad(String filename) {
		return magickLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadMagick7Buffer (magickload_buffer): load buffer with ImageMagick7
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage magickLoadBuffer(byte[] buffer, MagickLoadBufferOptions options);
	
	/**
	 * VipsForeignLoadMagick7Buffer (magickload_buffer): load buffer with ImageMagick7
	 * @param buffer Buffer to load from
	 */
	public static VipsImage magickLoadBuffer(byte[] buffer) {
		return magickLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveMagickFile (magicksave): save file with ImageMagick
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void magickSave(String filename, MagickSaveOptions options);
	
	/**
	 * VipsForeignSaveMagickFile (magicksave): save file with ImageMagick
	 * @param filename Filename to save to
	 */
	public void magickSave(String filename) {
		magickSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveMagickBuffer (magicksave_buffer): save image to magick buffer
	 * @param options optional arguments
	 */
	public native byte[] magickSaveBuffer(MagickSaveBufferOptions options);
	
	/**
	 * VipsForeignSaveMagickBuffer (magicksave_buffer): save image to magick buffer
	 */
	public byte[] magickSaveBuffer() {
		return magickSaveBuffer(null);
	}
	
	/**
	 * VipsMaplut (maplut): map an image though a lut
	 * @param lut Look-up table image
	 * @param options optional arguments
	 */
	public native void maplut(VipsImage lut, MapLUTOptions options);
	
	/**
	 * VipsMaplut (maplut): map an image though a lut
	 * @param lut Look-up table image
	 */
	public void maplut(VipsImage lut) {
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
	public static native VipsImage maskButterworth(int width, int height, double order, double frequencyCutoff, double amplitudeCutoff, MaskButterworthOptions options);
	
	/**
	 * VipsMaskButterworth (mask_butterworth): make a butterworth filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param order Filter order
	 * @param frequencyCutoff Frequency cutoff
	 * @param amplitudeCutoff Amplitude cutoff
	 */
	public static VipsImage maskButterworth(int width, int height, double order, double frequencyCutoff, double amplitudeCutoff) {
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
	public static native VipsImage maskButterworthBand(int width, int height, double order, double frequencyCutoffX, double frequencyCutoffY, double radius, double amplitudeCutoff, MaskButterworthBandOptions options);
	
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
	public static VipsImage maskButterworthBand(int width, int height, double order, double frequencyCutoffX, double frequencyCutoffY, double radius, double amplitudeCutoff) {
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
	public static native VipsImage maskButterworthRing(int width, int height, double order, double frequencyCutoff, double amplitudeCutoff, double ringwidth, MaskButterworthRingOptions options);
	
	/**
	 * VipsMaskButterworthRing (mask_butterworth_ring): make a butterworth ring filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param order Filter order
	 * @param frequencyCutoff Frequency cutoff
	 * @param amplitudeCutoff Amplitude cutoff
	 * @param ringwidth Ringwidth
	 */
	public static VipsImage maskButterworthRing(int width, int height, double order, double frequencyCutoff, double amplitudeCutoff, double ringwidth) {
		return maskButterworthRing(width, height, order, frequencyCutoff, amplitudeCutoff, ringwidth, null);
	}
	
	/**
	 * VipsMaskFractal (mask_fractal): make fractal filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param fractalDimension Fractal dimension
	 * @param options optional arguments
	 */
	public static native VipsImage maskFractal(int width, int height, double fractalDimension, MaskFractalOptions options);
	
	/**
	 * VipsMaskFractal (mask_fractal): make fractal filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param fractalDimension Fractal dimension
	 */
	public static VipsImage maskFractal(int width, int height, double fractalDimension) {
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
	public static native VipsImage maskGaussian(int width, int height, double frequencyCutoff, double amplitudeCutoff, MaskGaussianOptions options);
	
	/**
	 * VipsMaskGaussian (mask_gaussian): make a gaussian filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoff Frequency cutoff
	 * @param amplitudeCutoff Amplitude cutoff
	 */
	public static VipsImage maskGaussian(int width, int height, double frequencyCutoff, double amplitudeCutoff) {
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
	public static native VipsImage maskGaussianBand(int width, int height, double frequencyCutoffX, double frequencyCutoffY, double radius, double amplitudeCutoff, MaskGaussianBandOptions options);
	
	/**
	 * VipsMaskGaussianBand (mask_gaussian_band): make a gaussian filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoffX Frequency cutoff x
	 * @param frequencyCutoffY Frequency cutoff y
	 * @param radius radius of circle
	 * @param amplitudeCutoff Amplitude cutoff
	 */
	public static VipsImage maskGaussianBand(int width, int height, double frequencyCutoffX, double frequencyCutoffY, double radius, double amplitudeCutoff) {
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
	public static native VipsImage maskGaussianRing(int width, int height, double frequencyCutoff, double amplitudeCutoff, double ringwidth, MaskGaussianRingOptions options);
	
	/**
	 * VipsMaskGaussianRing (mask_gaussian_ring): make a gaussian ring filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoff Frequency cutoff
	 * @param amplitudeCutoff Amplitude cutoff
	 * @param ringwidth Ringwidth
	 */
	public static VipsImage maskGaussianRing(int width, int height, double frequencyCutoff, double amplitudeCutoff, double ringwidth) {
		return maskGaussianRing(width, height, frequencyCutoff, amplitudeCutoff, ringwidth, null);
	}
	
	/**
	 * VipsMaskIdeal (mask_ideal): make an ideal filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoff Frequency cutoff
	 * @param options optional arguments
	 */
	public static native VipsImage maskIdeal(int width, int height, double frequencyCutoff, MaskIdealOptions options);
	
	/**
	 * VipsMaskIdeal (mask_ideal): make an ideal filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoff Frequency cutoff
	 */
	public static VipsImage maskIdeal(int width, int height, double frequencyCutoff) {
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
	public static native VipsImage maskIdealBand(int width, int height, double frequencyCutoffX, double frequencyCutoffY, double radius, MaskIdealBandOptions options);
	
	/**
	 * VipsMaskIdealBand (mask_ideal_band): make an ideal band filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoffX Frequency cutoff x
	 * @param frequencyCutoffY Frequency cutoff y
	 * @param radius radius of circle
	 */
	public static VipsImage maskIdealBand(int width, int height, double frequencyCutoffX, double frequencyCutoffY, double radius) {
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
	public static native VipsImage maskIdealRing(int width, int height, double frequencyCutoff, double ringwidth, MaskIdealRingOptions options);
	
	/**
	 * VipsMaskIdealRing (mask_ideal_ring): make an ideal ring filter
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param frequencyCutoff Frequency cutoff
	 * @param ringwidth Ringwidth
	 */
	public static VipsImage maskIdealRing(int width, int height, double frequencyCutoff, double ringwidth) {
		return maskIdealRing(width, height, frequencyCutoff, ringwidth, null);
	}
	
	/**
	 * VipsMath (math): apply a math operation to an image
	 * @param math math to perform
	 */
	public native void math(VipsOperationMath math);
	
	/**
	 * VipsMath2 (math2): binary math operations
	 * @param right Right-hand image argument
	 * @param math2 math to perform
	 */
	public native void math2(VipsImage right, VipsOperationMath2 math2);
	
	/**
	 * VipsMath2Const (math2_const): binary math operations with a constant
	 * @param math2 math to perform
	 * @param c Array of constants
	 */
	public native void math2Const(VipsOperationMath2 math2, PixelPacket c);
	
	/**
	 * VipsForeignLoadMat (matload): load mat from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage matLoad(String filename, MatLoadOptions options);
	
	/**
	 * VipsForeignLoadMat (matload): load mat from file
	 * @param filename Filename to load from
	 */
	public static VipsImage matLoad(String filename) {
		return matLoad(filename, null);
	}
	
	/**
	 * VipsMatrixinvert (matrixinvert): invert an matrix
	 */
	public native void matrixinvert();
	
	/**
	 * VipsForeignLoadMatrixFile (matrixload): load matrix
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage matrixLoad(String filename, MatrixLoadOptions options);
	
	/**
	 * VipsForeignLoadMatrixFile (matrixload): load matrix
	 * @param filename Filename to load from
	 */
	public static VipsImage matrixLoad(String filename) {
		return matrixLoad(filename, null);
	}
	
	/**
	 * VipsForeignPrintMatrix (matrixprint): print matrix
	 * @param options optional arguments
	 */
	public native void matrixprint(MatrixprintOptions options);
	
	/**
	 * VipsForeignPrintMatrix (matrixprint): print matrix
	 */
	public void matrixprint() {
		matrixprint(null);
	}
	
	/**
	 * VipsForeignSaveMatrixFile (matrixsave): save image to matrix
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void matrixSave(String filename, MatrixSaveOptions options);
	
	/**
	 * VipsForeignSaveMatrixFile (matrixsave): save image to matrix
	 * @param filename Filename to save to
	 */
	public void matrixSave(String filename) {
		matrixSave(filename, null);
	}
	
	/**
	 * VipsMax (max): find image maximum
	 * @param options optional arguments
	 */
	public native double max(MaxOptions options);
	
	/**
	 * VipsMax (max): find image maximum
	 */
	public double max() {
		return max(null);
	}
	
	/**
	 * VipsMeasure (measure): measure a set of patches on a colour chart
	 * @param h Number of patches across chart
	 * @param v Number of patches down chart
	 * @param options optional arguments
	 */
	public native void measure(int h, int v, MeasureOptions options);
	
	/**
	 * VipsMeasure (measure): measure a set of patches on a colour chart
	 * @param h Number of patches across chart
	 * @param v Number of patches down chart
	 */
	public void measure(int h, int v) {
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
	public native void merge(VipsImage sec, VipsDirection direction, int dx, int dy, MergeOptions options);
	
	/**
	 * VipsMerge (merge): merge two images
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical merge
	 * @param dx Horizontal displacement from sec to ref
	 * @param dy Vertical displacement from sec to ref
	 */
	public void merge(VipsImage sec, VipsDirection direction, int dx, int dy) {
		merge(sec, direction, dx, dy, null);
	}
	
	/**
	 * VipsMin (min): find image minimum
	 * @param options optional arguments
	 */
	public native double min(MinOptions options);
	
	/**
	 * VipsMin (min): find image minimum
	 */
	public double min() {
		return min(null);
	}
	
	/**
	 * VipsMorph (morph): morphology operation
	 * @param mask Input matrix image
	 * @param morph Morphological operation to perform
	 */
	public native void morph(VipsImage mask, VipsOperationMorphology morph);
	
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
	public native void mosaic(VipsImage sec, VipsDirection direction, int xref, int yref, int xsec, int ysec, MosaicOptions options);
	
	/**
	 * VipsMosaic (mosaic): mosaic two images
	 * @param sec Secondary image
	 * @param direction Horizontal or vertical mosaic
	 * @param xref Position of reference tie-point
	 * @param yref Position of reference tie-point
	 * @param xsec Position of secondary tie-point
	 * @param ysec Position of secondary tie-point
	 */
	public void mosaic(VipsImage sec, VipsDirection direction, int xref, int yref, int xsec, int ysec) {
		mosaic(sec, direction, xref, yref, xsec, ysec, null);
	}
	
	/**
	 * VipsMsb (msb): pick most-significant byte from an image
	 * @param options optional arguments
	 */
	public native void msb(MsbOptions options);
	
	/**
	 * VipsMsb (msb): pick most-significant byte from an image
	 */
	public void msb() {
		msb(null);
	}
	
	/**
	 * VipsMultiply (multiply): multiply two images
	 * @param right Right-hand image argument
	 */
	public native void multiply(VipsImage right);
	
	/**
	 * VipsForeignLoadOpenexr (openexrload): load an OpenEXR image
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage openexrLoad(String filename, OpenexrLoadOptions options);
	
	/**
	 * VipsForeignLoadOpenexr (openexrload): load an OpenEXR image
	 * @param filename Filename to load from
	 */
	public static VipsImage openexrLoad(String filename) {
		return openexrLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadOpenslideFile (openslideload): load file with OpenSlide
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage openslideLoad(String filename, OpenslideLoadOptions options);
	
	/**
	 * VipsForeignLoadOpenslideFile (openslideload): load file with OpenSlide
	 * @param filename Filename to load from
	 */
	public static VipsImage openslideLoad(String filename) {
		return openslideLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadPdfFile (pdfload): load PDF from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage pdfLoad(String filename, PDFLoadOptions options);
	
	/**
	 * VipsForeignLoadPdfFile (pdfload): load PDF from file
	 * @param filename Filename to load from
	 */
	public static VipsImage pdfLoad(String filename) {
		return pdfLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadPdfBuffer (pdfload_buffer): load PDF from buffer
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage pdfLoadBuffer(byte[] buffer, PDFLoadBufferOptions options);
	
	/**
	 * VipsForeignLoadPdfBuffer (pdfload_buffer): load PDF from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage pdfLoadBuffer(byte[] buffer) {
		return pdfLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsPercent (percent): find threshold for percent of pixels
	 * @param percent Percent of pixels
	 */
	public native int percent(double percent);
	
	/**
	 * VipsPerlin (perlin): make a perlin noise image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage perlin(int width, int height, PerlinOptions options);
	
	/**
	 * VipsPerlin (perlin): make a perlin noise image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage perlin(int width, int height) {
		return perlin(width, height, null);
	}
	
	/**
	 * VipsPhasecor (phasecor): calculate phase correlation
	 * @param in2 Second input image
	 */
	public native void phasecor(VipsImage in2);
	
	/**
	 * VipsForeignLoadPngFile (pngload): load png from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage pngLoad(String filename, PNGLoadOptions options);
	
	/**
	 * VipsForeignLoadPngFile (pngload): load png from file
	 * @param filename Filename to load from
	 */
	public static VipsImage pngLoad(String filename) {
		return pngLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadPngBuffer (pngload_buffer): load png from buffer
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage pngLoadBuffer(byte[] buffer, PNGLoadBufferOptions options);
	
	/**
	 * VipsForeignLoadPngBuffer (pngload_buffer): load png from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage pngLoadBuffer(byte[] buffer) {
		return pngLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSavePngFile (pngsave): save image to png file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void pngSave(String filename, PNGSaveOptions options);
	
	/**
	 * VipsForeignSavePngFile (pngsave): save image to png file
	 * @param filename Filename to save to
	 */
	public void pngSave(String filename) {
		pngSave(filename, null);
	}
	
	/**
	 * VipsForeignSavePngBuffer (pngsave_buffer): save image to png buffer
	 * @param options optional arguments
	 */
	public native byte[] pngSaveBuffer(PNGSaveBufferOptions options);
	
	/**
	 * VipsForeignSavePngBuffer (pngsave_buffer): save image to png buffer
	 */
	public byte[] pngSaveBuffer() {
		return pngSaveBuffer(null);
	}
	
	/**
	 * VipsForeignLoadPpmFile (ppmload): load ppm from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage ppmLoad(String filename, PPMLoadOptions options);
	
	/**
	 * VipsForeignLoadPpmFile (ppmload): load ppm from file
	 * @param filename Filename to load from
	 */
	public static VipsImage ppmLoad(String filename) {
		return ppmLoad(filename, null);
	}
	
	/**
	 * VipsForeignSavePpmFile (ppmsave): save image to ppm file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void ppmSave(String filename, PPMSaveOptions options);
	
	/**
	 * VipsForeignSavePpmFile (ppmsave): save image to ppm file
	 * @param filename Filename to save to
	 */
	public void ppmSave(String filename) {
		ppmSave(filename, null);
	}
	
	/**
	 * VipsPremultiply (premultiply): premultiply image alpha
	 * @param options optional arguments
	 */
	public native void premultiply(PremultiplyOptions options);
	
	/**
	 * VipsPremultiply (premultiply): premultiply image alpha
	 */
	public void premultiply() {
		premultiply(null);
	}
	
	/**
	 * VipsProfile (profile): find image profiles
	 */
	public native VipsImage profile();
	
	/**
	 * VipsProfileLoad (profile_load): load named ICC profile
	 * @param name Profile name
	 */
	public static native byte[] profileLoad(String name);
	
	/**
	 * VipsProject (project): find image projections
	 */
	public native VipsImage project();
	
	/**
	 * VipsRad2float (rad2float): unpack Radiance coding to float RGB
	 */
	public native void rad2float();
	
	/**
	 * VipsForeignLoadRadFile (radload): load a Radiance image from a file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage radLoad(String filename, RadLoadOptions options);
	
	/**
	 * VipsForeignLoadRadFile (radload): load a Radiance image from a file
	 * @param filename Filename to load from
	 */
	public static VipsImage radLoad(String filename) {
		return radLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadRadBuffer (radload_buffer): load rad from buffer
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage radLoadBuffer(byte[] buffer, RadLoadBufferOptions options);
	
	/**
	 * VipsForeignLoadRadBuffer (radload_buffer): load rad from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage radLoadBuffer(byte[] buffer) {
		return radLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveRadFile (radsave): save image to Radiance file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void radSave(String filename, RadSaveOptions options);
	
	/**
	 * VipsForeignSaveRadFile (radsave): save image to Radiance file
	 * @param filename Filename to save to
	 */
	public void radSave(String filename) {
		radSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveRadBuffer (radsave_buffer): save image to Radiance buffer
	 * @param options optional arguments
	 */
	public native byte[] radSaveBuffer(RadSaveBufferOptions options);
	
	/**
	 * VipsForeignSaveRadBuffer (radsave_buffer): save image to Radiance buffer
	 */
	public byte[] radSaveBuffer() {
		return radSaveBuffer(null);
	}
	
	/**
	 * VipsRank (rank): rank filter
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 * @param index Select pixel at index
	 */
	public native void rank(int width, int height, int index);
	
	/**
	 * VipsForeignLoadRaw (rawload): load raw data from a file
	 * @param filename Filename to load from
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param bands Number of bands in image
	 * @param options optional arguments
	 */
	public static native VipsImage rawLoad(String filename, int width, int height, int bands, RawLoadOptions options);
	
	/**
	 * VipsForeignLoadRaw (rawload): load raw data from a file
	 * @param filename Filename to load from
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param bands Number of bands in image
	 */
	public static VipsImage rawLoad(String filename, int width, int height, int bands) {
		return rawLoad(filename, width, height, bands, null);
	}
	
	/**
	 * VipsForeignSaveRaw (rawsave): save image to raw file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void rawSave(String filename, RawSaveOptions options);
	
	/**
	 * VipsForeignSaveRaw (rawsave): save image to raw file
	 * @param filename Filename to save to
	 */
	public void rawSave(String filename) {
		rawSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveRawFd (rawsave_fd): write raw image to file descriptor
	 * @param fd File descriptor to write to
	 * @param options optional arguments
	 */
	public native void rawSaveFd(int fd, RawSaveFdOptions options);
	
	/**
	 * VipsForeignSaveRawFd (rawsave_fd): write raw image to file descriptor
	 * @param fd File descriptor to write to
	 */
	public void rawSaveFd(int fd) {
		rawSaveFd(fd, null);
	}
	
	/**
	 * VipsRecomb (recomb): linear recombination with matrix
	 * @param m matrix of coefficients
	 */
	public native void recomb(VipsImage m);
	
	/**
	 * VipsReduce (reduce): reduce an image
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 * @param options optional arguments
	 */
	public native void reduce(double hshrink, double vshrink, ReduceOptions options);
	
	/**
	 * VipsReduce (reduce): reduce an image
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 */
	public void reduce(double hshrink, double vshrink) {
		reduce(hshrink, vshrink, null);
	}
	
	/**
	 * VipsReduceh (reduceh): shrink an image horizontally
	 * @param hshrink Horizontal shrink factor
	 * @param options optional arguments
	 */
	public native void reduceh(double hshrink, ReducehOptions options);
	
	/**
	 * VipsReduceh (reduceh): shrink an image horizontally
	 * @param hshrink Horizontal shrink factor
	 */
	public void reduceh(double hshrink) {
		reduceh(hshrink, null);
	}
	
	/**
	 * VipsReducev (reducev): shrink an image vertically
	 * @param vshrink Vertical shrink factor
	 * @param options optional arguments
	 */
	public native void reducev(double vshrink, ReducevOptions options);
	
	/**
	 * VipsReducev (reducev): shrink an image vertically
	 * @param vshrink Vertical shrink factor
	 */
	public void reducev(double vshrink) {
		reducev(vshrink, null);
	}
	
	/**
	 * VipsRelational (relational): relational operation on two images
	 * @param right Right-hand image argument
	 * @param relational relational to perform
	 */
	public native void relational(VipsImage right, VipsOperationRelational relational);
	
	/**
	 * VipsRelationalConst (relational_const): relational operations against a constant
	 * @param relational relational to perform
	 * @param c Array of constants
	 */
	public native void relationalConst(VipsOperationRelational relational, PixelPacket c);
	
	/**
	 * VipsRemainder (remainder): remainder after integer division of two images
	 * @param right Right-hand image argument
	 */
	public native void remainder(VipsImage right);
	
	/**
	 * VipsRemainderConst (remainder_const): remainder after integer division of an image and a constant
	 * @param c Array of constants
	 */
	public native void remainderConst(PixelPacket c);
	
	/**
	 * VipsReplicate (replicate): replicate an image
	 * @param across Repeat this many times horizontally
	 * @param down Repeat this many times vertically
	 */
	public native void replicate(int across, int down);
	
	/**
	 * VipsResize (resize): resize an image
	 * @param scale Scale image by this factor
	 * @param options optional arguments
	 */
	public native void resize(double scale, ResizeOptions options);
	
	/**
	 * VipsResize (resize): resize an image
	 * @param scale Scale image by this factor
	 */
	public void resize(double scale) {
		resize(scale, null);
	}
	
	/**
	 * VipsRot (rot): rotate an image
	 * @param angle Angle to rotate image
	 */
	public native void rot(VipsAngle angle);
	
	/**
	 * VipsRot45 (rot45): rotate an image
	 * @param options optional arguments
	 */
	public native void rot45(Rot45Options options);
	
	/**
	 * VipsRot45 (rot45): rotate an image
	 */
	public void rot45() {
		rot45(null);
	}
	
	/**
	 * VipsRound (round): perform a round function on an image
	 * @param round rounding operation to perform
	 */
	public native void round(VipsOperationRound round);
	
	/**
	 * VipsScale (scale): scale an image to uchar
	 * @param options optional arguments
	 */
	public native void scale(ScaleOptions options);
	
	/**
	 * VipsScale (scale): scale an image to uchar
	 */
	public void scale() {
		scale(null);
	}
	
	/**
	 * VipsscRGB2BW (scRGB2BW): convert scRGB to BW
	 * @param options optional arguments
	 */
	public native void scRGB2BW(ScRGB2BWOptions options);
	
	/**
	 * VipsscRGB2BW (scRGB2BW): convert scRGB to BW
	 */
	public void scRGB2BW() {
		scRGB2BW(null);
	}
	
	/**
	 * VipsscRGB2sRGB (scRGB2sRGB): convert an scRGB image to sRGB
	 * @param options optional arguments
	 */
	public native void scRGB2sRGB(ScRGB2sRGBOptions options);
	
	/**
	 * VipsscRGB2sRGB (scRGB2sRGB): convert an scRGB image to sRGB
	 */
	public void scRGB2sRGB() {
		scRGB2sRGB(null);
	}
	
	/**
	 * VipsscRGB2XYZ (scRGB2XYZ): transform scRGB to XYZ
	 */
	public native void scRGB2XYZ();
	
	/**
	 * VipsSequential (sequential): check sequential access
	 * @param options optional arguments
	 */
	public native void sequential(SequentialOptions options);
	
	/**
	 * VipsSequential (sequential): check sequential access
	 */
	public void sequential() {
		sequential(null);
	}
	
	/**
	 * VipsSharpen (sharpen): unsharp masking for print
	 * @param options optional arguments
	 */
	public native void sharpen(SharpenOptions options);
	
	/**
	 * VipsSharpen (sharpen): unsharp masking for print
	 */
	public void sharpen() {
		sharpen(null);
	}
	
	/**
	 * VipsShrink (shrink): shrink an image
	 * @param hshrink Horizontal shrink factor
	 * @param vshrink Vertical shrink factor
	 */
	public native void shrink(double hshrink, double vshrink);
	
	/**
	 * VipsShrinkh (shrinkh): shrink an image horizontally
	 * @param hshrink Horizontal shrink factor
	 */
	public native void shrinkh(int hshrink);
	
	/**
	 * VipsShrinkv (shrinkv): shrink an image vertically
	 * @param vshrink Vertical shrink factor
	 */
	public native void shrinkv(int vshrink);
	
	/**
	 * VipsSign (sign): unit vector of pixel
	 */
	public native void sign();
	
	/**
	 * VipsSines (sines): make a 2D sine wave
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage sines(int width, int height, SinesOptions options);
	
	/**
	 * VipsSines (sines): make a 2D sine wave
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage sines(int width, int height) {
		return sines(width, height, null);
	}
	
	/**
	 * VipsSmartcrop (smartcrop): extract an area from an image
	 * @param width Width of extract area
	 * @param height Height of extract area
	 * @param options optional arguments
	 */
	public native void smartcrop(int width, int height, SmartcropOptions options);
	
	/**
	 * VipsSmartcrop (smartcrop): extract an area from an image
	 * @param width Width of extract area
	 * @param height Height of extract area
	 */
	public void smartcrop(int width, int height) {
		smartcrop(width, height, null);
	}
	
	/**
	 * VipsSobel (sobel): Sobel edge detector
	 */
	public native void sobel();
	
	/**
	 * VipsSpcor (spcor): spatial correlation
	 * @param ref Input reference image
	 */
	public native void spcor(VipsImage ref);
	
	/**
	 * VipsSpectrum (spectrum): make displayable power spectrum
	 */
	public native void spectrum();
	
	/**
	 * VipssRGB2HSV (sRGB2HSV): transform sRGB to HSV
	 */
	public native void sRGB2HSV();
	
	/**
	 * VipssRGB2scRGB (sRGB2scRGB): convert an sRGB image to scRGB
	 */
	public native void sRGB2scRGB();
	
	/**
	 * VipsStats (stats): find many image stats
	 */
	public native void stats();
	
	/**
	 * VipsStdif (stdif): statistical difference
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 * @param options optional arguments
	 */
	public native void stdif(int width, int height, StdifOptions options);
	
	/**
	 * VipsStdif (stdif): statistical difference
	 * @param width Window width in pixels
	 * @param height Window height in pixels
	 */
	public void stdif(int width, int height) {
		stdif(width, height, null);
	}
	
	/**
	 * VipsSubsample (subsample): subsample an image
	 * @param xfac Horizontal subsample factor
	 * @param yfac Vertical subsample factor
	 * @param options optional arguments
	 */
	public native void subsample(int xfac, int yfac, SubsampleOptions options);
	
	/**
	 * VipsSubsample (subsample): subsample an image
	 * @param xfac Horizontal subsample factor
	 * @param yfac Vertical subsample factor
	 */
	public void subsample(int xfac, int yfac) {
		subsample(xfac, yfac, null);
	}
	
	/**
	 * VipsSubtract (subtract): subtract two images
	 * @param right Right-hand image argument
	 */
	public native void subtract(VipsImage right);
	
	/**
	 * VipsForeignLoadSvgFile (svgload): load SVG with rsvg
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage svgLoad(String filename, SvgLoadOptions options);
	
	/**
	 * VipsForeignLoadSvgFile (svgload): load SVG with rsvg
	 * @param filename Filename to load from
	 */
	public static VipsImage svgLoad(String filename) {
		return svgLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadSvgBuffer (svgload_buffer): load SVG with rsvg
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage svgLoadBuffer(byte[] buffer, SvgLoadBufferOptions options);
	
	/**
	 * VipsForeignLoadSvgBuffer (svgload_buffer): load SVG with rsvg
	 * @param buffer Buffer to load from
	 */
	public static VipsImage svgLoadBuffer(byte[] buffer) {
		return svgLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsText (text): make a text image
	 * @param text Text to render
	 * @param options optional arguments
	 */
	public static native VipsImage text(String text, TextOptions options);
	
	/**
	 * VipsText (text): make a text image
	 * @param text Text to render
	 */
	public static VipsImage text(String text) {
		return text(text, null);
	}
	
	/**
	 * VipsThumbnailFile (thumbnail): generate thumbnail from file
	 * @param filename Filename to read from
	 * @param width Size to this width
	 * @param options optional arguments
	 */
	public static native VipsImage thumbnail(String filename, int width, ThumbnailOptions options);
	
	/**
	 * VipsThumbnailFile (thumbnail): generate thumbnail from file
	 * @param filename Filename to read from
	 * @param width Size to this width
	 */
	public static VipsImage thumbnail(String filename, int width) {
		return thumbnail(filename, width, null);
	}
	
	/**
	 * VipsThumbnailBuffer (thumbnail_buffer): generate thumbnail from buffer
	 * @param buffer Buffer to load from
	 * @param width Size to this width
	 * @param options optional arguments
	 */
	public static native VipsImage thumbnailBuffer(byte[] buffer, int width, ThumbnailBufferOptions options);
	
	/**
	 * VipsThumbnailBuffer (thumbnail_buffer): generate thumbnail from buffer
	 * @param buffer Buffer to load from
	 * @param width Size to this width
	 */
	public static VipsImage thumbnailBuffer(byte[] buffer, int width) {
		return thumbnailBuffer(buffer, width, null);
	}
	
	/**
	 * VipsThumbnailImage (thumbnail_image): generate thumbnail from image
	 * @param width Size to this width
	 * @param options optional arguments
	 */
	public native void thumbnailImage(int width, ThumbnailImageOptions options);
	
	/**
	 * VipsThumbnailImage (thumbnail_image): generate thumbnail from image
	 * @param width Size to this width
	 */
	public void thumbnailImage(int width) {
		thumbnailImage(width, null);
	}
	
	/**
	 * VipsForeignLoadTiffFile (tiffload): load tiff from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage tiffLoad(String filename, TIFFLoadOptions options);
	
	/**
	 * VipsForeignLoadTiffFile (tiffload): load tiff from file
	 * @param filename Filename to load from
	 */
	public static VipsImage tiffLoad(String filename) {
		return tiffLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadTiffBuffer (tiffload_buffer): load tiff from buffer
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage tiffLoadBuffer(byte[] buffer, TIFFLoadBufferOptions options);
	
	/**
	 * VipsForeignLoadTiffBuffer (tiffload_buffer): load tiff from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage tiffLoadBuffer(byte[] buffer) {
		return tiffLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveTiffFile (tiffsave): save image to tiff file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void tiffSave(String filename, TIFFSaveOptions options);
	
	/**
	 * VipsForeignSaveTiffFile (tiffsave): save image to tiff file
	 * @param filename Filename to save to
	 */
	public void tiffSave(String filename) {
		tiffSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveTiffBuffer (tiffsave_buffer): save image to tiff buffer
	 * @param options optional arguments
	 */
	public native byte[] tiffSaveBuffer(TIFFSaveBufferOptions options);
	
	/**
	 * VipsForeignSaveTiffBuffer (tiffsave_buffer): save image to tiff buffer
	 */
	public byte[] tiffSaveBuffer() {
		return tiffSaveBuffer(null);
	}
	
	/**
	 * VipsTileCache (tilecache): cache an image as a set of tiles
	 * @param options optional arguments
	 */
	public native void tilecache(TilecacheOptions options);
	
	/**
	 * VipsTileCache (tilecache): cache an image as a set of tiles
	 */
	public void tilecache() {
		tilecache(null);
	}
	
	/**
	 * VipsTonelut (tonelut): build a look-up table
	 * @param options optional arguments
	 */
	public static native VipsImage tonelut(ToneLUTOptions options);
	
	/**
	 * VipsTonelut (tonelut): build a look-up table
	 */
	public static VipsImage tonelut() {
		return tonelut(null);
	}
	
	/**
	 * VipsTranspose3d (transpose3d): transpose3d an image
	 * @param options optional arguments
	 */
	public native void transpose3d(Transpose3dOptions options);
	
	/**
	 * VipsTranspose3d (transpose3d): transpose3d an image
	 */
	public void transpose3d() {
		transpose3d(null);
	}
	
	/**
	 * VipsUnpremultiply (unpremultiply): unpremultiply image alpha
	 * @param options optional arguments
	 */
	public native void unpremultiply(UnpremultiplyOptions options);
	
	/**
	 * VipsUnpremultiply (unpremultiply): unpremultiply image alpha
	 */
	public void unpremultiply() {
		unpremultiply(null);
	}
	
	/**
	 * VipsForeignLoadVipsFile (vipsload): load vips from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage vipsLoad(String filename, VipsLoadOptions options);
	
	/**
	 * VipsForeignLoadVipsFile (vipsload): load vips from file
	 * @param filename Filename to load from
	 */
	public static VipsImage vipsLoad(String filename) {
		return vipsLoad(filename, null);
	}
	
	/**
	 * VipsForeignSaveVipsFile (vipssave): save image to file in vips format
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void vipsSave(String filename, VipsSaveOptions options);
	
	/**
	 * VipsForeignSaveVipsFile (vipssave): save image to file in vips format
	 * @param filename Filename to save to
	 */
	public void vipsSave(String filename) {
		vipsSave(filename, null);
	}
	
	/**
	 * VipsForeignLoadWebpFile (webpload): load webp from file
	 * @param filename Filename to load from
	 * @param options optional arguments
	 */
	public static native VipsImage webpLoad(String filename, WebpLoadOptions options);
	
	/**
	 * VipsForeignLoadWebpFile (webpload): load webp from file
	 * @param filename Filename to load from
	 */
	public static VipsImage webpLoad(String filename) {
		return webpLoad(filename, null);
	}
	
	/**
	 * VipsForeignLoadWebpBuffer (webpload_buffer): load webp from buffer
	 * @param buffer Buffer to load from
	 * @param options optional arguments
	 */
	public static native VipsImage webpLoadBuffer(byte[] buffer, WebpLoadBufferOptions options);
	
	/**
	 * VipsForeignLoadWebpBuffer (webpload_buffer): load webp from buffer
	 * @param buffer Buffer to load from
	 */
	public static VipsImage webpLoadBuffer(byte[] buffer) {
		return webpLoadBuffer(buffer, null);
	}
	
	/**
	 * VipsForeignSaveWebpFile (webpsave): save image to webp file
	 * @param filename Filename to save to
	 * @param options optional arguments
	 */
	public native void webpSave(String filename, WebpSaveOptions options);
	
	/**
	 * VipsForeignSaveWebpFile (webpsave): save image to webp file
	 * @param filename Filename to save to
	 */
	public void webpSave(String filename) {
		webpSave(filename, null);
	}
	
	/**
	 * VipsForeignSaveWebpBuffer (webpsave_buffer): save image to webp buffer
	 * @param options optional arguments
	 */
	public native byte[] webpSaveBuffer(WebpSaveBufferOptions options);
	
	/**
	 * VipsForeignSaveWebpBuffer (webpsave_buffer): save image to webp buffer
	 */
	public byte[] webpSaveBuffer() {
		return webpSaveBuffer(null);
	}
	
	/**
	 * VipsWorley (worley): make a worley noise image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage worley(int width, int height, WorleyOptions options);
	
	/**
	 * VipsWorley (worley): make a worley noise image
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage worley(int width, int height) {
		return worley(width, height, null);
	}
	
	/**
	 * VipsWrap (wrap): wrap image origin
	 * @param options optional arguments
	 */
	public native void wrap(WrapOptions options);
	
	/**
	 * VipsWrap (wrap): wrap image origin
	 */
	public void wrap() {
		wrap(null);
	}
	
	/**
	 * VipsXyz (xyz): make an image where pixel values are coordinates
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage xyz(int width, int height, XYZOptions options);
	
	/**
	 * VipsXyz (xyz): make an image where pixel values are coordinates
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage xyz(int width, int height) {
		return xyz(width, height, null);
	}
	
	/**
	 * VipsXYZ2CMYK (XYZ2CMYK): transform XYZ to CMYK
	 */
	public native void xyz2cmyk();
	
	/**
	 * VipsXYZ2Lab (XYZ2Lab): transform XYZ to Lab
	 * @param options optional arguments
	 */
	public native void xYZ2Lab(XYZ2LabOptions options);
	
	/**
	 * VipsXYZ2Lab (XYZ2Lab): transform XYZ to Lab
	 */
	public void xYZ2Lab() {
		xYZ2Lab(null);
	}
	
	/**
	 * VipsXYZ2scRGB (XYZ2scRGB): transform XYZ to scRGB
	 */
	public native void xYZ2scRGB();
	
	/**
	 * VipsXYZ2Yxy (XYZ2Yxy): transform XYZ to Yxy
	 */
	public native void xYZ2Yxy();
	
	/**
	 * VipsYxy2XYZ (Yxy2XYZ): transform Yxy to XYZ
	 */
	public native void yxy2XYZ();
	
	/**
	 * VipsZone (zone): make a zone plate
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 * @param options optional arguments
	 */
	public static native VipsImage zone(int width, int height, ZoneOptions options);
	
	/**
	 * VipsZone (zone): make a zone plate
	 * @param width Image width in pixels
	 * @param height Image height in pixels
	 */
	public static VipsImage zone(int width, int height) {
		return zone(width, height, null);
	}
	
	/**
	 * VipsZoom (zoom): zoom an image
	 * @param xfac Horizontal zoom factor
	 * @param yfac Vertical zoom factor
	 */
	public native void zoom(int xfac, int yfac);
	
}
