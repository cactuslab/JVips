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

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_colourspaceNative__I(JNIEnv *env, jobject obj, int space)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    VipsImage *out = NULL;

    if (vips_colourspace(im, &out, space, NULL))
    {
        throwVipsException(env, "Unable to convert colour space I");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    g_object_unref(im);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_colourspaceNative__II(JNIEnv *env, jobject obj, int space, int source_space)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    VipsImage *out = NULL;

    if (vips_colourspace(im, &out, space, "source_space", source_space, NULL))
    {
        throwVipsException(env, "Unable to convert colour space II");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    g_object_unref(im);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_thumbnailImageNative(JNIEnv *env, jobject obj, jint width, jint height, jboolean scale)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    VipsImage *out = NULL;
    VipsSize vipsSize = scale ? VIPS_SIZE_FORCE : VIPS_SIZE_BOTH;

    if (vips_thumbnail_image(im, &out, width, "height", height, "size", vipsSize, NULL))
    {
        throwVipsException(env, "Unable to make thumbnail image");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    g_object_unref(im);
}

// JNIEXPORT void JNICALL
// Java_com_criteo_vips_VipsImage_thumbnailImageWithOptionsNative(JNIEnv *env, jobject obj, jint width, jint height, jobject options)
// {
//     VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
//     VipsImage *out = NULL;

//     jclass optionsCls = (*env)->GetObjectClass(env, options);
//     jfieldID sizeFid = (*env)->GetFieldID(env, optionsCls, "size", "I");
//     jfieldID noRotateFid = (*env)->GetFieldID(env, optionsCls, "noRotate", "Z");
//     jfieldID cropFid = (*env)->GetFieldID(env, optionsCls, "crop", "I");
//     jfieldID linearFid = (*env)->GetFieldID(env, optionsCls, "linear", "Z");
//     jfieldID importProfileFid = (*env)->GetFieldID(env, optionsCls, "importProfile", "Ljava/lang/String;");
//     jfieldID exportProfileFid = (*env)->GetFieldID(env, optionsCls, "exportProfile", "Ljava/lang/String;");
//     jfieldID intentFid = (*env)->GetFieldID(env, optionsCls, "intent", "I");

//     jint size = (*env)->GetIntField(env, options, sizeFid);
//     jboolean noRotate = (*env)->GetBooleanField(env, options, noRotateFid);
//     jint crop = (*env)->GetIntField(env, options, cropFid);
//     jboolean linear = (*env)->GetBooleanField(env, options, linearFid);
//     jstring importProfile = (jstring) (*env)->GetObjectField(env, options, importProfileFid); // TODO how to pass if set, as there is no default
//     jstring exportProfile = (jstring) (*env)->GetObjectField(env, options, exportProfileFid); // TODO how to pass if set, as there is no default
//     jint intent = (*env)->GetIntField(env, options, intentFid);

//     VipsSize vipsSize = size != -1 ? size : VIPS_SIZE_BOTH;
//     VipsInteresting vipsCrop = crop != -1 ? crop : VIPS_INTERESTING_NONE;
//     VipsIntent vipsIntent = intent != -1 ? intent : VIPS_INTENT_RELATIVE;

//     if (vips_thumbnail_image(im, &out, width, "height", height, "size", vipsSize, "no-rotate", noRotate, "crop", vipsCrop, "linear", linear, "intent", intent, NULL))
//     {
//         throwVipsException(env, "Unable to make thumbnail image");
//         return;
//     }
//     (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
//     g_object_unref(im);
// }

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_thumbnailImageWithOptionsNative(JNIEnv *env, jobject in, jint width, jobject options)
{
        GValue gvalue = { 0 };

        VipsOperation *op = vips_operation_new("thumbnail_image");

        // in
        if (in != NULL) {
                g_value_init(&gvalue, VIPS_TYPE_IMAGE);
                g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
                g_object_set_property(G_OBJECT(op), "in", &gvalue);
                g_value_unset(&gvalue);
        }

        // width
        g_value_init(&gvalue, G_TYPE_INT);
        g_value_set_int(&gvalue, width);
        g_object_set_property(G_OBJECT(op), "width", &gvalue);
        g_value_unset(&gvalue);

        // Optionals
        if (options != NULL) {
                jclass optionsCls = (*env)->GetObjectClass(env, options);
                // height
                jfieldID heightFid = (*env)->GetFieldID(env, optionsCls, "height", "Ljava/lang/Integer;");
                jobject heightObjectValue = (*env)->GetObjectField(env, options, heightFid);
                if (heightObjectValue != NULL) {
                        jint height = (*env)->CallIntMethod(env, heightObjectValue, intValue_mid);
                        g_value_init(&gvalue, G_TYPE_INT);
                        g_value_set_int(&gvalue, height);
                        g_object_set_property(G_OBJECT(op), "height", &gvalue);
                        g_value_unset(&gvalue);
                }

                // size
                jfieldID sizeFid = (*env)->GetFieldID(env, optionsCls, "size", "Lcom/criteo/vips/enums/VipsSize;");
                jobject size = (*env)->GetObjectField(env, options, sizeFid);
                if (size != NULL) {
                        jclass sizeCls = (*env)->GetObjectClass(env, size);
                        jfieldID sizeValueFid = (*env)->GetFieldID(env, sizeCls, "value", "I");
                        jint sizeValue = (*env)->GetIntField(env, size, sizeValueFid);
                        g_value_init(&gvalue, G_TYPE_INT);
                        g_value_set_int(&gvalue, sizeValue);
                        g_object_set_property(G_OBJECT(op), "size", &gvalue);
                        g_value_unset(&gvalue);
                }

                // no-rotate
                jfieldID noRotateFid = (*env)->GetFieldID(env, optionsCls, "noRotate", "Ljava/lang/Boolean;");
                jobject noRotateObjectValue = (*env)->GetObjectField(env, options, noRotateFid);
                if (noRotateObjectValue != NULL) {
                        jboolean noRotate = (*env)->CallBooleanMethod(env, noRotateObjectValue, booleanValue_mid);
                        g_value_init(&gvalue, G_TYPE_BOOLEAN);
                        g_value_set_boolean(&gvalue, noRotate);
                        g_object_set_property(G_OBJECT(op), "no-rotate", &gvalue);
                        g_value_unset(&gvalue);
                }

                // crop
                jfieldID cropFid = (*env)->GetFieldID(env, optionsCls, "crop", "Lcom/criteo/vips/enums/VipsInteresting;");
                jobject crop = (*env)->GetObjectField(env, options, cropFid);
                if (crop != NULL) {
                        jclass cropCls = (*env)->GetObjectClass(env, crop);
                        jfieldID cropValueFid = (*env)->GetFieldID(env, cropCls, "value", "I");
                        jint cropValue = (*env)->GetIntField(env, crop, cropValueFid);
                        g_value_init(&gvalue, G_TYPE_INT);
                        g_value_set_int(&gvalue, cropValue);
                        g_object_set_property(G_OBJECT(op), "crop", &gvalue);
                        g_value_unset(&gvalue);
                }

                // linear
                jfieldID linearFid = (*env)->GetFieldID(env, optionsCls, "linear", "Ljava/lang/Boolean;");
                jobject linearObjectValue = (*env)->GetObjectField(env, options, linearFid);
                if (linearObjectValue != NULL) {
                        jboolean linear = (*env)->CallBooleanMethod(env, linearObjectValue, booleanValue_mid);
                        g_value_init(&gvalue, G_TYPE_BOOLEAN);
                        g_value_set_boolean(&gvalue, linear);
                        g_object_set_property(G_OBJECT(op), "linear", &gvalue);
                        g_value_unset(&gvalue);
                }

                // import-profile
                jfieldID importProfileFid = (*env)->GetFieldID(env, optionsCls, "importProfile", "Ljava/lang/String;");
                jstring importProfile = (jstring) (*env)->GetObjectField(env, options, importProfileFid);
                if (importProfile != NULL) {
                        const char *importProfileChars = (*env)->GetStringUTFChars(env, importProfile, NULL);
                        g_value_init(&gvalue, G_TYPE_STRING);
                        g_value_set_string(&gvalue, importProfileChars);
                        (*env)->ReleaseStringUTFChars(env, importProfile, importProfileChars);
                        g_object_set_property(G_OBJECT(op), "import-profile", &gvalue);
                        g_value_unset(&gvalue);
                }

                // export-profile
                jfieldID exportProfileFid = (*env)->GetFieldID(env, optionsCls, "exportProfile", "Ljava/lang/String;");
                jstring exportProfile = (jstring) (*env)->GetObjectField(env, options, exportProfileFid);
                if (exportProfile != NULL) {
                        const char *exportProfileChars = (*env)->GetStringUTFChars(env, exportProfile, NULL);
                        g_value_init(&gvalue, G_TYPE_STRING);
                        g_value_set_string(&gvalue, exportProfileChars);
                        (*env)->ReleaseStringUTFChars(env, exportProfile, exportProfileChars);
                        g_object_set_property(G_OBJECT(op), "export-profile", &gvalue);
                        g_value_unset(&gvalue);
                }

                // intent
                jfieldID intentFid = (*env)->GetFieldID(env, optionsCls, "intent", "Lcom/criteo/vips/enums/VipsIntent;");
                jobject intent = (*env)->GetObjectField(env, options, intentFid);
                if (intent != NULL) {
                        jclass intentCls = (*env)->GetObjectClass(env, intent);
                        jfieldID intentValueFid = (*env)->GetFieldID(env, intentCls, "value", "I");
                        jint intentValue = (*env)->GetIntField(env, intent, intentValueFid);
                        g_value_init(&gvalue, G_TYPE_INT);
                        g_value_set_int(&gvalue, intentValue);
                        g_object_set_property(G_OBJECT(op), "intent", &gvalue);
                        g_value_unset(&gvalue);
                }

        }
        // Operation
        VipsOperation *new_op;
        if (!(new_op = vips_cache_operation_build(op))) {
                g_object_unref(op);
                throwVipsException(env, "thumbnail_image failed");
                return;
        }
        g_object_unref(op);
        op = new_op;

        // Mutating image result
        g_value_init(&gvalue, VIPS_TYPE_IMAGE);
        g_object_get_property(G_OBJECT(op), "out", &gvalue);
        VipsImage *_out = VIPS_IMAGE(g_value_get_object(&gvalue));
        g_object_ref(_out); 
        g_value_unset(&gvalue);
        g_object_unref((VipsImage *) (*env)->GetLongField(env, in, handle_fid));
        (*env)->SetLongField(env, in, handle_fid, (jlong) _out);

        // Free the operation
        vips_object_unref_outputs(VIPS_OBJECT(op)); 
        g_object_unref(op);

}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_VipsImage_thumbnailNative(JNIEnv *env, jclass cls, jstring filename, jint width, jint height, jboolean scale)
{
    VipsImage *out = NULL;
    const char *name = (*env)->GetStringUTFChars(env, filename, NULL);
    VipsSize vipsSize = scale ? VIPS_SIZE_FORCE : VIPS_SIZE_BOTH;

    if (vips_thumbnail(name, &out, width, "height", height, "size", vipsSize, NULL))
    {
        throwVipsException(env, "Unable to make thumbnail");
    }
    (*env)->ReleaseStringUTFChars(env, filename, name);
    return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_VipsImage_thumbnailWithImageNative(JNIEnv *env, jclass cls, jstring filename, jint width, jint height, jobject options)
{
    VipsImage *out = NULL;
    const char *name = (*env)->GetStringUTFChars(env, filename, NULL);

    jclass optionsCls = (*env)->GetObjectClass(env, options);
    jfieldID sizeFid = (*env)->GetFieldID(env, optionsCls, "size", "I");
    jfieldID noRotateFid = (*env)->GetFieldID(env, optionsCls, "noRotate", "Z");
    jfieldID cropFid = (*env)->GetFieldID(env, optionsCls, "crop", "I");
    jfieldID linearFid = (*env)->GetFieldID(env, optionsCls, "linear", "Z");
    jfieldID importProfileFid = (*env)->GetFieldID(env, optionsCls, "importProfile", "Ljava/lang/String;");
    jfieldID exportProfileFid = (*env)->GetFieldID(env, optionsCls, "exportProfile", "Ljava/lang/String;");
    jfieldID intentFid = (*env)->GetFieldID(env, optionsCls, "intent", "I");

    jint size = (*env)->GetIntField(env, options, sizeFid);
    jboolean noRotate = (*env)->GetBooleanField(env, options, noRotateFid);
    jint crop = (*env)->GetIntField(env, options, cropFid);
    jboolean linear = (*env)->GetBooleanField(env, options, linearFid);
    jstring importProfile = (jstring) (*env)->GetObjectField(env, options, importProfileFid); // TODO how to pass if set, as there is no default
    jstring exportProfile = (jstring) (*env)->GetObjectField(env, options, exportProfileFid); // TODO how to pass if set, as there is no default
    jint intent = (*env)->GetIntField(env, options, intentFid);

    VipsSize vipsSize = size != -1 ? size : VIPS_SIZE_BOTH;
    VipsInteresting vipsCrop = crop != -1 ? crop : VIPS_INTERESTING_NONE;
    VipsIntent vipsIntent = intent != -1 ? intent : VIPS_INTENT_RELATIVE;

    if (vips_thumbnail(name, &out, width, "height", height, "size", vipsSize, "no-rotate", noRotate, "crop", vipsCrop, "linear", linear, "intent", intent, NULL))
    {
        throwVipsException(env, "Unable to make thumbnail");
    }
    (*env)->ReleaseStringUTFChars(env, filename, name);
    return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_resizeNative(JNIEnv *env, jobject obj, jdouble hscale, jdouble vscale, jint kernel)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    VipsImage *out = NULL;

    if (vips_resize(im, &out, hscale, "vscale", vscale, "kernel", kernel, NULL))
    {
        throwVipsException(env, "Unable to resize image");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    g_object_unref(im);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_padNative(JNIEnv *env, jobject obj, jint width, jint height, jdoubleArray background, jint gravity)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    VipsImage *out = NULL;
    jint length = (*env)->GetArrayLength(env, background);
    jdouble background_array[MAX_CHANNEL_SIZE] = { 0 };
    VipsArrayDouble *bg_pixel = NULL;
    VipsCompassDirection direction = gravity;

    if (im->Bands > length && length != 1)
    {
        throwVipsException(env, "Invalid background pixel size");
        return;
    }
    length = im->Bands;
    (*env)->GetDoubleArrayRegion(env, background, 0, length, background_array);
    bg_pixel = vips_array_double_new(background_array, length);
    if (vips_gravity(im, &out, direction, width, height, "extend", VIPS_EXTEND_BACKGROUND, "background", bg_pixel, NULL))
    {
        throwVipsException(env, "Unable to pad image");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    vips_area_unref((VipsArea *) bg_pixel);
    g_object_unref(im);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_cropNative(JNIEnv *env, jobject obj, jint left, jint top, jint width, jint height)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    int w = vips_image_get_width(im);
    int h = vips_image_get_height(im);
    VipsImage *out = NULL;

    if (vips_crop(im, &out, left, top, width, height, NULL))
    {
        throwVipsException(env, "Unable to crop image");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    g_object_unref(im);
}

JNIEXPORT jintArray JNICALL
Java_com_criteo_vips_VipsImage_findTrimNative(JNIEnv *env, jobject obj, jdouble threshold, jdoubleArray background)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    jintArray ret;
    jint length = (*env)->GetArrayLength(env, background);
    jdouble background_array[MAX_CHANNEL_SIZE] = { 0 };
    int buffer[4] = { 0 }; /* top, left, width, height */
    VipsArrayDouble *bg_pixel = NULL;

    if (im->Bands > length && length != 1)
    {
        throwVipsException(env, "Invalid background pixel size");
        return ret;
    }
    length = im->Bands;
    /**
    * vips_find_trim() handles transparency by flatting transparent pixels with background pixel.
    * Then, it finds trim according to background pixel.
    * The solution is to remove the alpha channel assuming that it is the last channel.
    */
    if (vips_image_hasalpha(im))
        length = im->Bands - 1;
    (*env)->GetDoubleArrayRegion(env, background, 0, length, background_array);
    bg_pixel = vips_array_double_new(background_array, length);
    if (vips_find_trim(im, buffer, buffer + 1, buffer + 2, buffer + 3, "threshold", threshold, "background", bg_pixel, NULL))
    {
        throwVipsException(env, "Unable to find image trim");
        return ret;
    }
    ret = (*env)->NewIntArray(env, 4);
    (*env)->SetIntArrayRegion(env, ret, 0, 4, buffer);
    (*env)->ReleaseIntArrayElements(env, ret, buffer, JNI_COMMIT);
    vips_area_unref((VipsArea *) bg_pixel);
    return ret;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_compose(JNIEnv *env, jobject obj, jobject sub)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    VipsImage *overlay = (VipsImage *) (*env)->GetLongField(env, sub, handle_fid);
    VipsImage *out = NULL;

    if (vips_composite2(im, overlay, &out, VIPS_BLEND_MODE_OVER, NULL))
    {
        throwVipsException(env, "Unable to compose image");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    g_object_unref(im);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_insert(JNIEnv *env, jobject obj, jobject sub, jint x, jint y)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    VipsImage *im2 = (VipsImage *) (*env)->GetLongField(env, sub, handle_fid);
    VipsImage *out = NULL;
    
    if (vips_insert(im, im2, &out, x, y, NULL))
    {
        throwVipsException(env, "Unable to insert image");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    g_object_unref(im);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_flattenNative(JNIEnv *env, jobject obj, jdoubleArray background)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    jint length = (*env)->GetArrayLength(env, background);
    jdouble background_array[MAX_CHANNEL_SIZE] = { 0 };
    VipsArrayDouble *bg_pixel = NULL;
    VipsImage *out = NULL;

    // vector must have 1 or 3 elements
    length = 3;
    (*env)->GetDoubleArrayRegion(env, background, 0, length, background_array);
    bg_pixel = vips_array_double_new(background_array, length);
    if (vips_flatten(im, &out, "background", bg_pixel, NULL))
    {
        throwVipsException(env, "Unable to flat image");
        return;
    }

    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    g_object_unref(im);
    vips_area_unref((VipsArea *) bg_pixel);
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

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_VipsImage_writePNGToArrayNative(JNIEnv *env, jobject obj, jint compression, jboolean palette, jint colors, jboolean strip)
{
    jbyteArray ret;
    void *buffer = NULL;
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    size_t result_length = 0;

    if (vips_pngsave_buffer(im, &buffer, &result_length,
                            "compression", compression,
                            "palette", palette,
                            "colours", colors,
                            "strip", strip,
                            NULL))
    {
        throwVipsException(env, "Unable to write PNG image buffer");
        return ret;
    }
    ret = (*env)->NewByteArray(env, result_length);
    (*env)->SetByteArrayRegion(env, ret, 0, result_length * sizeof (jbyte), buffer);
    g_free(buffer);
    return ret;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_writePNGToFileNative(JNIEnv *env, jobject obj, jstring name, jint compression, jboolean palette, jint colors, jboolean strip)
{
    const char *filename = (*env)->GetStringUTFChars(env, name, NULL);
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);

    if (vips_pngsave(im, filename,
                            "compression", compression,
                            "palette", palette,
                            "colours", colors,
                            "strip", strip,
                            NULL))
    {
        throwVipsException(env, "Unable to write PNG to file");
        return;
    }

    (*env)->ReleaseStringUTFChars(env, name, filename);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_writePNGToFileWithOptionsNative(JNIEnv *env, jobject obj, jstring name, jobject options)
{
    const char *filename = (*env)->GetStringUTFChars(env, name, NULL);
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);

    jclass optionsCls = (*env)->GetObjectClass(env, options);
    jfieldID compressionFid = (*env)->GetFieldID(env, optionsCls, "compression", "I");
    jfieldID interlaceFid = (*env)->GetFieldID(env, optionsCls, "interlace", "Z");
    jfieldID paletteFid = (*env)->GetFieldID(env, optionsCls, "palette", "Z");
    jfieldID bitdepthFid = (*env)->GetFieldID(env, optionsCls, "bitdepth", "I");
    jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Z");

    jint compression = (*env)->GetIntField(env, options, compressionFid);
    jboolean interlace = (*env)->GetBooleanField(env, options, interlaceFid);
    jboolean palette = (*env)->GetBooleanField(env, options, paletteFid);
    jint bitdepth = (*env)->GetIntField(env, options, bitdepthFid);
    jboolean strip = (*env)->GetBooleanField(env, options, stripFid);

    if (vips_pngsave(im, filename,
                            "compression", compression != -1 ? compression : 6,
                            "interlace", interlace,
                            "palette", palette,
                            "bitdepth", bitdepth != -1 ? bitdepth : 0,
                            "strip", strip,
                            NULL))
    {
        throwVipsException(env, "Unable to write PNG to file");
        return;
    }

    (*env)->ReleaseStringUTFChars(env, name, filename);
}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_VipsImage_writeJPEGToArrayNative(JNIEnv *env, jobject obj, jint q, jboolean strip)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);

    void *buffer;
    size_t buffer_size;

    if (vips_jpegsave_buffer(im, &buffer, &buffer_size, "Q", q, "strip", strip, NULL))
    {
        throwVipsException(env, "Unable to write JPEG image buffer");
        return NULL;
    }

    jbyteArray ret = (*env)->NewByteArray(env, buffer_size);
    (*env)->SetByteArrayRegion(env, ret, 0, buffer_size, buffer);
    g_free(buffer);
    return ret;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_writeJPEGToFileNative(JNIEnv *env, jobject obj, jstring name, jint q, jboolean strip)
{
    const char *filename = (*env)->GetStringUTFChars(env, name, NULL);
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);

    if (vips_jpegsave(im, filename, "Q", q, "strip", strip, NULL))
    {
        throwVipsException(env, "Unable to write JPEG to file");
        return;
    }

    (*env)->ReleaseStringUTFChars(env, name, filename);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_writeJPEGToFileWithOptionsNative(JNIEnv *env, jobject obj, jstring name, jobject options)
{
    const char *filename = (*env)->GetStringUTFChars(env, name, NULL);
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);

    jclass optionsCls = (*env)->GetObjectClass(env, options);
    jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "I");
    jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Z");

    jint q = (*env)->GetIntField(env, options, qFid);
    jboolean strip = (*env)->GetBooleanField(env, options, stripFid);

    if (vips_jpegsave(im, filename, "Q", q, "strip", strip, NULL))
    {
        throwVipsException(env, "Unable to write JPEG to file");
        return;
    }

    (*env)->ReleaseStringUTFChars(env, name, filename);
}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_VipsImage_writeAVIFToArrayNative(JNIEnv *env, jobject obj, jint q, jboolean lossless, jint speed)
{
    jbyteArray ret;
    void *buffer = NULL;
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    size_t result_length = 0;

    if (vips_heifsave_buffer(im, &buffer, &result_length,
                            "Q", q,
                            "lossless", lossless,
                            "compression", VIPS_FOREIGN_HEIF_COMPRESSION_AV1,
                            "speed", speed,
                            NULL))
    {
        throwVipsException(env, "Unable to write AVIF image buffer");
        return ret;
    }
    ret = (*env)->NewByteArray(env, result_length);
    (*env)->SetByteArrayRegion(env, ret, 0, result_length * sizeof (jbyte), buffer);
    g_free(buffer);
    return ret;
}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_VipsImage_writeWEBPToArrayNative(JNIEnv *env, jobject obj, jint q, jboolean lossless, jboolean strip)
{
    jbyteArray ret;
    void *buffer = NULL;
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    size_t result_length = 0;

    if (vips_webpsave_buffer(im, &buffer, &result_length,
                            "Q", q,
                            "lossless", lossless,
                            "strip", strip,
                            NULL))
    {
        throwVipsException(env, "Unable to write WEBP image buffer");
        return ret;
    }
    ret = (*env)->NewByteArray(env, result_length);
    (*env)->SetByteArrayRegion(env, ret, 0, result_length * sizeof (jbyte), buffer);
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

JNIEXPORT void JNICALL Java_com_criteo_vips_VipsImage_castUcharNative(JNIEnv *env, jobject obj, jboolean shift)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    VipsImage *out = NULL;

    if (vips_cast_uchar(im, &out, "shift", shift, NULL))
    {
        throwVipsException(env, "Unable to cast image to uchar");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    g_object_unref(im);
}

JNIEXPORT void JNICALL Java_com_criteo_vips_VipsImage_castNative(JNIEnv *env, jobject obj, jint format, jboolean shift)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    VipsImage *out = NULL;

    if (vips_cast(im, &out, format, "shift", shift, NULL))
    {
        throwVipsException(env, "Unable to cast image");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    g_object_unref(im);
}

JNIEXPORT void JNICALL Java_com_criteo_vips_VipsImage_histFindNdimNative(JNIEnv *env, jobject obj, jint bins)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, obj, handle_fid);
    VipsImage *out = NULL;

    if (vips_hist_find_ndim(im, &out, "bins", bins, NULL))
    {
        throwVipsException(env, "vips_hist_find_ndim(bins) failed");
        return;
    }
    (*env)->SetLongField(env, obj, handle_fid, (jlong) out);
    g_object_unref(im);
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

JNIEXPORT jdoubleArray JNICALL
Java_com_criteo_vips_VipsImage_getPoint(JNIEnv *env, jobject image_obj, jint x, jint y)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, image_obj, handle_fid);
    double *vector;
    int n;
    jdoubleArray ret;

    if (vips_getpoint(im, &vector, &n, x, y, NULL))
    {
        throwVipsException(env, "vips_getpoint failed");
        return NULL;
    }
    ret = (*env)->NewDoubleArray(env, n);
    (*env)->SetDoubleArrayRegion(env, ret, 0, n, vector);
    (*env)->ReleaseDoubleArrayElements(env, ret, vector, JNI_COMMIT);
    g_free(vector);
    return ret;
}

JNIEXPORT void
JNICALL Java_com_criteo_vips_VipsImage_linearNative(JNIEnv *env, jobject image_obj, jdoubleArray a, jdoubleArray b, jboolean uchar)
{
    jint length = (*env)->GetArrayLength(env, a);

    if ((*env)->GetArrayLength(env, b) != length)
        throwVipsException(env, "vips_linear requires arrays of the same length");
    else
    {
        VipsImage *im = (VipsImage *) (*env)->GetLongField(env, image_obj, handle_fid);
        VipsImage *out = NULL;
        jdouble *a_values = (*env)->GetDoubleArrayElements(env, a, 0);
        jdouble *b_values = (*env)->GetDoubleArrayElements(env, b, 0);

        int errcode = vips_linear(im, &out, a_values, b_values, length, "uchar", uchar, NULL);
        (*env)->ReleaseDoubleArrayElements(env, a, a_values, 0);
        (*env)->ReleaseDoubleArrayElements(env, b, b_values, 0);

        if (errcode)
            throwVipsException(env, "vips_linear failed");
        else
        {
            (*env)->SetLongField(env, image_obj, handle_fid, (jlong) out);
            g_object_unref(im);
        }
    }
}

JNIEXPORT void
JNICALL Java_com_criteo_vips_VipsImage_gaussblur(JNIEnv *env, jobject image_obj, jdouble sigma, jdouble min_ampl)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, image_obj, handle_fid);
    VipsImage *out = NULL;

    if (vips_gaussblur(im, &out, sigma, "min_ampl", min_ampl, NULL))
    {
        throwVipsException(env, "Unable to apply gaussian blur");
        return;
    }
    (*env)->SetLongField(env, image_obj, handle_fid, (jlong) out);
    g_object_unref(im);
}

JNIEXPORT jobject
JNICALL Java_com_criteo_vips_VipsImage_extractArea(JNIEnv *env, jobject image_obj, jint left, jint top, jint width, jint height)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, image_obj, handle_fid);
    VipsImage *out = NULL;
    jobject cls = (*env)->FindClass(env, "com/criteo/vips/VipsImage");

    if (vips_extract_area(im, &out, left, top, width, height, NULL))
    {
        throwVipsException(env, "Unable to extract image area");
    }
    return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void
JNICALL Java_com_criteo_vips_VipsImage_autorot(JNIEnv *env, jobject image_obj)
{
    VipsImage *im = (VipsImage *) (*env)->GetLongField(env, image_obj, handle_fid);
    VipsImage *out = NULL;

    if (vips_autorot(im, &out, NULL))
    {
        throwVipsException(env, "Unable to auto rotate image");
        return;
    }
    (*env)->SetLongField(env, image_obj, handle_fid, (jlong) out);
    g_object_unref(im);
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


JNIEXPORT jobject
JNICALL Java_com_criteo_vips_VipsImage_joinNative(JNIEnv *env, jclass cls, jobject in1, jobject in2, jint direction)
{
    VipsImage *im1 = (VipsImage *) (*env)->GetLongField(env, in1, handle_fid);
    VipsImage *im2 = (VipsImage *) (*env)->GetLongField(env, in2, handle_fid);
    VipsImage *out = NULL;

    if (vips_join(im1, im2, &out, direction, NULL))
    {
        throwVipsException(env, "Unable to join image");
    }
    return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsImage_embed(JNIEnv *env, jobject in, jint x, jint y, jint width, jint height, jobject options)
{
        GValue gvalue = { 0 };

        VipsOperation *op = vips_operation_new("embed");

        // in
        g_value_init( &gvalue, VIPS_TYPE_IMAGE );
        g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
        g_object_set_property(G_OBJECT(op), "in", &gvalue);
        g_value_unset(&gvalue);

        // x
        g_value_init(&gvalue, G_TYPE_INT );
        g_value_set_int(&gvalue, x);
        g_object_set_property(G_OBJECT(op), "x", &gvalue);
        g_value_unset(&gvalue);

        // y
        g_value_init(&gvalue, G_TYPE_INT );
        g_value_set_int(&gvalue, y);
        g_object_set_property(G_OBJECT(op), "y", &gvalue);
        g_value_unset(&gvalue);

        // width
        g_value_init(&gvalue, G_TYPE_INT );
        g_value_set_int(&gvalue, width);
        g_object_set_property(G_OBJECT(op), "width", &gvalue);
        g_value_unset(&gvalue);

        // height
        g_value_init(&gvalue, G_TYPE_INT );
        g_value_set_int(&gvalue, height);
        g_object_set_property(G_OBJECT(op), "height", &gvalue);
        g_value_unset(&gvalue);

        // Operation
        VipsOperation *new_op;
        if (!(new_op = vips_cache_operation_build(op))) {
                g_object_unref(op);
                vips_error_exit(NULL); 
        }
        g_object_unref(op);
        op = new_op;

        // Image result
        g_value_init(&gvalue, VIPS_TYPE_IMAGE);
        g_object_get_property(G_OBJECT(op), "out", &gvalue);
        VipsImage *_out = VIPS_IMAGE(g_value_get_object(&gvalue));
        g_object_ref(_out); 
        g_value_unset(&gvalue);
        g_object_unref((VipsImage *) (*env)->GetLongField(env, in, handle_fid));
        (*env)->SetLongField(env, in, handle_fid, (jlong) _out);

        // Free the operation
        vips_object_unref_outputs(VIPS_OBJECT(op)); 
        g_object_unref(op);

}
