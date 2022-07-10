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

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <jni.h>
#include <vips/vips.h>

#include "VipsImage.h"
#include "VipsException.h"
#include "JniFieldsIDs.h"

#define MAX_CHANNEL_SIZE 4

jfieldID handle_fid = NULL;
jfieldID buffer_fid = NULL;
jmethodID ctor_mid = NULL;
jmethodID booleanValue_mid = NULL;
jmethodID intValue_mid = NULL;

static VipsImage *
new_from_buffer(JNIEnv *env, void *buffer, int length)
{
    VipsImage *im = NULL;
    if ((im = vips_image_new_from_buffer(buffer, length, NULL, NULL)) == NULL)
    {
        throwVipsException(env, "Unable to decode image buffer");
        return NULL;
    }
    return im;
}

static VipsImage *
new_from_buffer_with_options(JNIEnv *env, void *buffer, int length, jstring options)
{
    const char *options_str = (*env)->GetStringUTFChars(env, options, NULL);
    VipsImage *im = NULL;
    if ((im = vips_image_new_from_buffer(buffer, length, options_str, NULL)) == NULL)
    {
        (*env)->ReleaseStringUTFChars(env, options, options_str);
        throwVipsException(env, "Unable to decode image buffer");
        return NULL;
    }
    (*env)->ReleaseStringUTFChars(env, options, options_str);
    return im;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_blackNative(JNIEnv *env, jobject obj, jint width, jint height)
{
    VipsImage *out = NULL;
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);

    if (vips_black(&out, width, height, NULL))
    {
        throwVipsException(env, "vips_black failed");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    (*env)->SetLongField(env, obj, buffer_fid, (jlong) NULL);
    g_object_unref(im);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_newFromImageNative(JNIEnv *env, jobject obj, jobject image, jdoubleArray background)
{
    VipsImage *src = (VipsImage *) (*env)->GetLongField(env, image, handle_fid);
    VipsImage *im = NULL;
    jint length = (*env)->GetArrayLength(env, background);
    jdouble background_array[MAX_CHANNEL_SIZE] = { 0 };

    (*env)->GetDoubleArrayRegion(env, background, 0, length, background_array);
    if ((im = vips_image_new_from_image(src, background_array, length)) == NULL)
    {
        throwVipsException(env, "Unable to decode image buffer");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) im);
    (*env)->SetLongField(env, obj, buffer_fid, (jlong) NULL);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_initFieldIDs(JNIEnv *env, jobject cls)
{
    handle_fid = (*env)->GetFieldID(env, cls, "vipsImageHandler", "J");
    buffer_fid = (*env)->GetFieldID(env, cls, "bufferHandler", "J");
    ctor_mid = (*env)->GetMethodID(env, cls, "<init>", "(J)V");
    jclass booleanClass = (*env)->FindClass(env, "java/lang/Boolean");
    booleanValue_mid = (*env)->GetMethodID(env, booleanClass, "booleanValue", "()Z");
    jclass integerClass = (*env)->FindClass(env, "java/lang/Integer");
    intValue_mid = (*env)->GetMethodID(env, integerClass, "intValue", "()I");
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_newFromByteBuffer__Ljava_nio_ByteBuffer_2I(JNIEnv *env, jobject obj, jobject buffer, jint length)
{
    void *buf = (*env)->GetDirectBufferAddress(env, buffer);

    (*env)->SetLongField(env, obj, handle_fid, (jlong) new_from_buffer(env, buf, length));
    (*env)->SetLongField(env, obj, buffer_fid, (jlong) NULL);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_newFromByteBuffer__Ljava_nio_ByteBuffer_2ILjava_lang_String_2(JNIEnv *env, jobject obj, jobject buffer, jint length, jstring options)
{
    void *buf = (*env)->GetDirectBufferAddress(env, buffer);

    (*env)->SetLongField(env, obj, handle_fid, (jlong) new_from_buffer_with_options(env, buf, length, options));
    (*env)->SetLongField(env, obj, buffer_fid, (jlong) NULL);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_newFromBuffer___3BI(JNIEnv *env, jobject obj, jbyteArray buffer, jint length)
{
    void *internal_buffer = NULL;
    VipsImage* im = NULL;
    size_t len = length * sizeof(jbyte);

    if ((internal_buffer = vips_tracked_malloc(len)) == NULL)
    {
        (*env)->SetLongField(env, obj, handle_fid, (jlong) NULL);
        (*env)->SetLongField(env, obj, buffer_fid, (jlong) NULL);
        throwVipsException(env, "Unable to allocate memory");
        return;
    }
    (*env)->GetByteArrayRegion(env, buffer, 0, len, internal_buffer);
    im = new_from_buffer(env, internal_buffer, length);
    (*env)->SetLongField(env, obj, handle_fid, (jlong) im);
    (*env)->SetLongField(env, obj, buffer_fid, (jlong) internal_buffer);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_newFromBuffer___3BILjava_lang_String_2(JNIEnv *env, jobject obj, jbyteArray buffer, jint length, jstring options)
{
    void *internal_buffer = NULL;
    VipsImage* im = NULL;
    size_t len = length * sizeof(jbyte);

    if ((internal_buffer = vips_tracked_malloc(len)) == NULL)
    {
        (*env)->SetLongField(env, obj, handle_fid, (jlong) NULL);
        (*env)->SetLongField(env, obj, buffer_fid, (jlong) NULL);
        throwVipsException(env, "Unable to allocate memory");
        return;
    }
    (*env)->GetByteArrayRegion(env, buffer, 0, len, internal_buffer);
    im = new_from_buffer_with_options(env, internal_buffer, length, options);
    (*env)->SetLongField(env, obj, handle_fid, (jlong) im);
    (*env)->SetLongField(env, obj, buffer_fid, (jlong) internal_buffer);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_newFromFile(JNIEnv *env, jobject obj, jstring filename)
{
    const char *str = (*env)->GetStringUTFChars(env, filename, NULL);
    VipsImage* im = vips_image_new_from_file(str, NULL);

    if (im == NULL)
    {
        (*env)->SetLongField(env, obj, handle_fid, (jlong) NULL);
        (*env)->SetLongField(env, obj, buffer_fid, (jlong) NULL);
        (*env)->ReleaseStringUTFChars(env, filename, str);
        throwVipsException(env, "Unable to create an image from file");
        return;
    }
    (*env)->ReleaseStringUTFChars(env, filename, str);
    (*env)->SetLongField(env, obj, handle_fid, (jlong) im);
    (*env)->SetLongField(env, obj, buffer_fid, (jlong) NULL);
}

JNIEXPORT int JNICALL Java_com_criteo_vips_VipsImage_imageGetInterpretationNative(JNIEnv *env, jobject obj)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    return vips_image_get_interpretation(im);
}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_VipsImage_writeToArrayNative(JNIEnv *env, jobject obj, jstring extension, jint quality, jboolean strip)
{
    jbyteArray ret;
    const char *ext = (*env)->GetStringUTFChars(env, extension, NULL);
    void *buffer = NULL;
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    size_t result_length = 0;
    int status = 0;

    if (strcmp(ext, ".avif") == 0) {
        if (quality < 0)
            status = vips_heifsave_buffer(im, &buffer, &result_length, "Q", quality, "compression", VIPS_FOREIGN_HEIF_COMPRESSION_AV1, NULL);
        else
            status = vips_heifsave_buffer(im, &buffer, &result_length, "compression", VIPS_FOREIGN_HEIF_COMPRESSION_AV1, NULL);
    } else {
        if (quality < 0)
            status = vips_image_write_to_buffer(im, ext, &buffer, &result_length, "strip", strip, NULL);
        else
            status = vips_image_write_to_buffer(im, ext, &buffer, &result_length, "strip", strip, "Q", quality, NULL);
    }
    if (status)
    {
        (*env)->ReleaseStringUTFChars(env, extension, ext);
        throwVipsException(env, "Unable to write image buffer");
        return ret;
    }
    ret = (*env)->NewByteArray(env, result_length);
    (*env)->SetByteArrayRegion(env, ret, 0, result_length * sizeof (jbyte), buffer);
    (*env)->ReleaseStringUTFChars(env, extension, ext);
    g_free(buffer);
    return ret;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_writeToFile(JNIEnv *env, jobject obj, jstring name)
{
    const char *filename = (*env)->GetStringUTFChars(env, name, NULL);
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);

    if (vips_image_write_to_file(im, filename, NULL))
    {
        throwVipsException(env, "Unable to write to file");
    }
    (*env)->ReleaseStringUTFChars(env, name, filename);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_writeToFileNative(JNIEnv *env, jobject obj, jstring name, jboolean strip, jdoubleArray background, jint pageHeight)
{
    const char *filename = (*env)->GetStringUTFChars(env, name, NULL);
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    
    VipsArrayDouble *bg_pixel;
    if (background != NULL) {
        jdouble *background_values = (*env)->GetDoubleArrayElements(env, background, NULL);
        jint length = (*env)->GetArrayLength(env, background);

        bg_pixel = vips_array_double_new(background_values, length);
        (*env)->ReleaseDoubleArrayElements(env, background, background_values, 0);
    } else {
        bg_pixel = NULL;
    }

    if (
        bg_pixel != NULL
        ? vips_image_write_to_file(im, filename, "strip", strip, "background", bg_pixel, "page-height", pageHeight != -1 ? pageHeight : 0, NULL)
        : vips_image_write_to_file(im, filename, "strip", strip, "page-height", pageHeight != -1 ? pageHeight : 0, NULL)
    ) {
        throwVipsException(env, "Unable to write to file");
    }
    if (bg_pixel != NULL) {
        vips_area_unref((VipsArea *) bg_pixel);
    }
    (*env)->ReleaseStringUTFChars(env, name, filename);
}

JNIEXPORT jint JNICALL
Java_com_criteo_vips_VipsImage_getWidth(JNIEnv *env, jobject obj)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    return vips_image_get_width(im);
}

JNIEXPORT jint JNICALL
Java_com_criteo_vips_VipsImage_getHeight(JNIEnv *env, jobject obj)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    return vips_image_get_height(im);
}

JNIEXPORT jint JNICALL
Java_com_criteo_vips_VipsImage_getBands(JNIEnv *env, jobject obj)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    return im->Bands;
}

JNIEXPORT jdoubleArray JNICALL
Java_com_criteo_vips_VipsImage_getPointPixelPacketNative(JNIEnv *env, jobject obj, jint x, jint y)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    double *pixel = NULL;
    int result_length = 0;
    jdoubleArray ret;

    if (vips_getpoint(im, &pixel, &result_length, x, y, NULL) < 0)
    {
        throwVipsException(env, "Unable to get image point");
        g_free(pixel);
        return ret;
    }
    // Convert to uchar
    for (int i = 0; i < result_length; ++i)
        // Left shift of image channel bits - target channel bits (8 bits)
        pixel[i] = ((int)pixel[i]) >> ((VIPS_IMAGE_SIZEOF_ELEMENT(im) * 8) - 8);
    ret = (*env)->NewDoubleArray(env, result_length);
    (*env)->SetDoubleArrayRegion(env, ret, 0, result_length, pixel);
    (*env)->ReleaseDoubleArrayElements(env, ret, pixel, JNI_COMMIT);
    g_free(pixel);
    return ret;
}

JNIEXPORT jboolean JNICALL
Java_com_criteo_vips_VipsImage_hasAlpha(JNIEnv *env, jobject obj)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    return vips_image_hasalpha(im);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_convertTosRGB(JNIEnv *env, jobject obj)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    VipsImage *out = NULL;
    VipsInterpretation source_space = vips_image_guess_interpretation(im);

    if (vips_colourspace(im, &out, VIPS_INTERPRETATION_sRGB, "source_space", source_space, NULL))
    {
        throwVipsException(env, "Unable to convert image");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    g_object_unref(im);
}

JNIEXPORT jint JNICALL
Java_com_criteo_vips_VipsImage_getNbFrame(JNIEnv *env, jobject obj)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    int n_pages = 0;

    if (vips_image_get_int(im, VIPS_META_N_PAGES, &n_pages))
    {
        // VIPS_META_N_PAGES may be missing.
        // Assume there is only one image.
        return 1;
    }
    return n_pages;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_release(JNIEnv *env, jobject obj)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    void *buffer = (void *) (*env)->GetLongField(env, obj, buffer_fid);

    if (im)
    {
        g_object_unref(im);
        im = NULL;
        (*env)->SetLongField(env, obj, handle_fid, (jlong) im);
    }
    if (buffer)
    {
        vips_tracked_free(buffer);
        buffer = NULL;
        (*env)->SetLongField(env, obj, buffer_fid, (jlong) buffer);
    }
}

JNIEXPORT jint JNICALL Java_com_criteo_vips_VipsImage_imageGetFormatNative(JNIEnv *env, jobject obj)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    return vips_image_get_format(im);
}

JNIEXPORT void JNICALL Java_com_criteo_vips_VipsImage_max1Native(JNIEnv * env, jobject image_obj, jobject result_obj)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, image_obj, handle_fid);
    double out;
    int x;
    int y;

    if (vips_max(im, &out, "x", &x, "y", &y, NULL))
    {
        throwVipsException(env, "max(x, y) failed");
        return;
    }
    (*env)->SetDoubleField(env, result_obj, field_Max1Result_out, out);
    (*env)->SetIntField(env, result_obj, field_Max1Result_x, x);
    (*env)->SetIntField(env, result_obj, field_Max1Result_y, y);
}

JNIEXPORT jobject
JNICALL Java_com_criteo_vips_VipsImage_clone(JNIEnv *env, jobject image_obj)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, image_obj, handle_fid);
    VipsImage *out = NULL;
    jobject cls = (*env)->FindClass(env, "com/criteo/vips/VipsImage");

    if (vips_copy(im, &out, NULL))
    {
        throwVipsException(env, "Unable to copy image");
    }
    return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void
JNICALL Java_com_criteo_vips_VipsImage_removeAutorotAngle(JNIEnv *env, jobject image_obj)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, image_obj, handle_fid);
    vips_autorot_remove_angle(im);
}
