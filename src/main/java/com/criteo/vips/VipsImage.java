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

import com.criteo.vips.enums.*;
import com.criteo.vips.options.CastOptions;
import com.criteo.vips.options.ColourspaceOptions;
import com.criteo.vips.options.FindTrimOptions;
import com.criteo.vips.options.FlattenOptions;
import com.criteo.vips.options.GaussBlurOptions;
import com.criteo.vips.options.GravityOptions;
import com.criteo.vips.options.HEIFSaveBufferOptions;
import com.criteo.vips.options.HistFindNdimOptions;
import com.criteo.vips.options.JPEGSaveBufferOptions;
import com.criteo.vips.options.JPEGSaveOptions;
import com.criteo.vips.options.LinearOptions;
import com.criteo.vips.options.PNGSaveBufferOptions;
import com.criteo.vips.options.PNGSaveOptions;
import com.criteo.vips.options.ResizeOptions;
import com.criteo.vips.options.ThumbnailImageOptions;
import com.criteo.vips.options.ThumbnailOptions;
import com.criteo.vips.options.WebpSaveBufferOptions;

import java.awt.*;
import java.nio.ByteBuffer;

/**
 * Operation on image is not thread safe.
 */
public class VipsImage extends AbstractVipsImage implements Image {
    public static int JPGQuality = 80;

    static {
        initFieldIDs();
    }

    private static native void initFieldIDs();

    private native void newFromByteBuffer(ByteBuffer buffer, int length) throws VipsException;

    private native void newFromByteBuffer(ByteBuffer buffer, int length, String options) throws VipsException;

    private native void newFromBuffer(byte[] buffer, int length) throws VipsException;

    private native void newFromBuffer(byte[] buffer, int length, String options) throws VipsException;

    private native void newFromFile(String filename) throws VipsException;

    private native void newFromFile(String filename, VipsAccess access) throws VipsException;

    public VipsImage(ByteBuffer buffer, int length) throws VipsException {
        newFromByteBuffer(buffer, length);
    }

    public VipsImage(ByteBuffer buffer, int length, String options) throws VipsException {
        newFromByteBuffer(buffer, length, options);
    }

    public VipsImage(byte[] buffer, int length) throws VipsException {
        newFromBuffer(buffer, length);
    }

    public VipsImage(byte[] buffer, int length, String options) throws VipsException {
        newFromBuffer(buffer, length, options);
    }

    public VipsImage(VipsImage image, PixelPacket color) throws VipsException {
        newFromImage(image, color);
    }

    public VipsImage(String filename) throws VipsException {
        newFromFile(filename);
    }

    public VipsImage(String filename, VipsAccess access) throws VipsException {
        newFromFile(filename, access);
    }

    private VipsImage() {
        // you must call a native method before using this object
    }

    private VipsImage(long handle) {
        this.vipsImageHandler = handle;
    }

    private void newFromImage(Image image, PixelPacket c) throws VipsException {
        double[] color = {c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha()};
        newFromImageNative(image, color);
    }

    private native void newFromImageNative(Image image, double[] c) throws VipsException;

    public VipsBandFormat imageGetFormat() {
        return VipsBandFormat.valueOf(imageGetFormatNative());
    }

    private native int imageGetFormatNative();

    public void applyCastUchar() throws VipsException {
        applyCast(VipsBandFormat.FormatUchar);
    }

    public void applyCastUchar(boolean shift) throws VipsException {
        applyCast(VipsBandFormat.FormatUchar, new CastOptions().shift(shift));
    }

    public void applyCast(VipsBandFormat format, boolean shift) throws VipsException {
        applyCast(format, new CastOptions().shift(shift));
    }

    public VipsInterpretation imageGetInterpretation() {
        return VipsInterpretation.valueOf(imageGetInterpretationNative());
    }

    private native int imageGetInterpretationNative();

    public void applyColourspace(VipsInterpretation space, VipsInterpretation source_space) throws VipsException {
        applyColourspace(space, new ColourspaceOptions().sourceSpace(source_space));
    }

    public void applyHistFindNdim(int bins) throws VipsException {
        applyHistFindNdim(new HistFindNdimOptions().bins(bins));
    }

    public void applyThumbnailImage(Dimension dimension, boolean scale) throws VipsException {
        applyThumbnailImage(dimension.width, dimension.height, scale);
    }

    public void applyThumbnailImage(int width, int height, boolean scale) throws VipsException {
        applyThumbnailImage(width, new ThumbnailImageOptions().height(height).size(scale ? VipsSize.Force : VipsSize.Both));
    }

    public static VipsImage thumbnail(String filename, Dimension dimension, boolean scale) throws VipsException {
        return thumbnail(filename, dimension.width, new ThumbnailOptions().height(dimension.height).size(scale ? VipsSize.Force : VipsSize.Both));
    }

    /**
     * Make a thumbnail from a file with new target dimension
     *
     * @param filename name of the file to load
     * @param width  Target width
     * @param height Target height
     * @param scale  If scale is enabled, force to resize ignoring aspect ratio
     * @throws VipsException if error
     */
    public static VipsImage thumbnail(String filename, int width, int height, boolean scale) throws VipsException {
        return thumbnail(filename, width, new ThumbnailOptions().height(height).size(scale ? VipsSize.Force : VipsSize.Both));
    }

    /**
     * @deprecated Use {@link #applyThumbnailImage(Dimension, boolean)} instead.
     */
    @Deprecated
    public void applyResize(Dimension dimension, boolean scale) throws VipsException {
        applyThumbnailImage(dimension.width, dimension.height, scale);
    }

    /**
     * @deprecated Use {@link #applyThumbnailImage(int, int, boolean)} instead.
     */
    @Deprecated
    public void resize(int width, int height, boolean scale) throws VipsException {
        applyThumbnailImage(width, height, scale);
    }

    public void applyResize(double hscale, double vscale, VipsKernel kernel) throws VipsException {
        applyResize(hscale, new ResizeOptions().vscale(vscale).kernel(kernel));
    }

    public Max1Result max1() throws VipsException {
        Max1Result r = new Max1Result();
        max1Native(r);
        return r;
    }

    private native void max1Native(Max1Result r) throws VipsException;

    public void applyPad(Dimension dimension, PixelPacket background, VipsCompassDirection gravity) throws VipsException {
        applyGravity(gravity, dimension.width, dimension.height, new GravityOptions()
            .backgroundPixelPacket(background)
            .extend(VipsExtend.Background)
        );
    }

    public void applyCrop(Rectangle rectangle) throws VipsException {
        applyExtractArea(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
    }

    public Rectangle findTrim(double threshold, PixelPacket background) throws VipsException {
        return findTrim(new FindTrimOptions().threshold(threshold).backgroundPixelPacket(background));
    }

    public void applyCompose(Image sub) throws VipsException {
        applyComposite2(sub, VipsBlendMode.Over);
    }

    public void applyFlatten(PixelPacket background) throws VipsException {
        applyFlatten(new FlattenOptions().backgroundPixelPacket(background));
    }

    public byte[] writeToArray(VipsImageFormat imageFormat, boolean strip) throws VipsException {
        // Set quality to -1 and let default vips value
        return writeToArray(imageFormat, -1, strip);
    }

    public byte[] writeToArray(VipsImageFormat imageFormat, int quality, boolean strip) throws VipsException {
        return writeToArrayNative(imageFormat.getFileExtension(), quality, strip);
    }

    private native byte[] writeToArrayNative(String extension, int quality, boolean strip) throws VipsException;

    private int colorsToBitdepth(int colors) {
        return (int) (Math.log(colors) / Math.log(2));
    }

    public byte[] writePNGToArray(int compression, boolean palette, int colors, boolean strip) throws VipsException {
        return pngSaveBuffer(new PNGSaveBufferOptions().compression(compression).palette(palette).bitdepth(colorsToBitdepth(colors)).strip(strip));
    }

    @Override
    public void writePNGToFile(String name, int compression, boolean palette, int colors, boolean strip) throws VipsException {
       writePNGToFile(name, new PNGSaveOptions().compression(compression).palette(palette).bitdepth(colorsToBitdepth(colors)).strip(strip));
    }

    @Override
    public void writePNGToFile(String name, PNGSaveOptions options) throws VipsException {
        pngSave(name, options);
    }

    public byte[] writeJPEGToArray(int quality, boolean strip) throws VipsException {
        return jpegSaveBuffer(new JPEGSaveBufferOptions().q(quality).strip(strip));
    }

    @Override
    public void writeJPEGToFile(String name, int quality, boolean strip) throws VipsException {
        jpegSave(name, new JPEGSaveOptions().q(quality).strip(strip));
    }

    @Override
    public void writeJPEGToFile(String name, JPEGSaveOptions options) throws VipsException {
        jpegSave(name, options);
    }

    public byte[] writeAVIFToArray(int Q, boolean lossless, int speed) throws VipsException {
        return heifSaveBuffer(new HEIFSaveBufferOptions().q(Q).lossless(lossless).compression(VipsForeignHeifCompression.Av1).effort(speed));
    }

    public byte[] writeWEBPToArray(int Q, boolean lossless, boolean strip) throws VipsException {
        return webpSaveBuffer(new WebpSaveBufferOptions().q(Q).lossless(lossless).strip(strip));
    }

    public native void writeToFile(String name) throws VipsException;

    public void writeToFile(String name, boolean strip, PixelPacket background, int pageHeight) {
        writeToFileNative(name, strip, background != null ? background.getComponents() : null, pageHeight);
    }

    private native void writeToFileNative(String name, boolean strip, double[] background, int pageHeight);

    public native int getWidth();

    public native int getHeight();

    public native int getBands();

    public PixelPacket getPointPixelPacket(Point point) throws VipsException {
        return new PixelPacket(getPointPixelPacketNative(point.x, point.y));
    }

    public PixelPacket getPointPixelPacket(int x, int y) throws VipsException {
        return new PixelPacket(getPointPixelPacketNative(x, y));
    }

    private native double[] getPointPixelPacketNative(int x, int y) throws VipsException;

    public native boolean hasAlpha();

    public void applyLinear(double[] a, double[] b, boolean uchar) throws VipsException {
        applyLinear(a, b, new LinearOptions().uchar(uchar));
    }

    public void applyLinear(double[] a, double[] b) throws VipsException {
        applyLinear(a, b, false);
    }

    public VipsInterpretation getInterpretation() {
        /**
         * The name of the function in libvips is vips_image_get_interpretation
         * so the Java method should be called imageGetInterpretation.  Just
         * the correctly named function here.
         */
        return imageGetInterpretation();
    }

    @Override
    public void applyGaussBlur(double sigma, double minAmpl) throws VipsException {
        applyGaussBlur(sigma, new GaussBlurOptions().minAmpl(minAmpl));
    }

    public native void applyConvertTosRGB() throws VipsException;

    public native int getNbFrame();

    public native void applyRemoveAutorotAngle();

    public native VipsImage clone() throws VipsException;

    public native void release();

    /**
     * Join in1 and in2 together, left-right or up-down depending on the value of direction
     *
     * @param in1 left image
     * @param in2 right image
     * @param direction left-right or up-down depending on the value of direction
     * @return Concat image
     * @throws VipsException
     */
    public static VipsImage join(VipsImage in1, VipsImage in2, VipsDirection direction) throws VipsException {
        return in1.join(in2,  direction);
    }

}
