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

#include "AbstractVipsImage.h"
#include "VipsException.h"

static jfieldID handle_fid = NULL;
static jfieldID buffer_fid = NULL;
static jmethodID ctor_mid = NULL;
static jmethodID booleanValue_mid = NULL;
static jmethodID intValue_mid = NULL;
static jmethodID longValue_mid = NULL;
static jmethodID doubleValue_mid = NULL;
static jclass imageClass = NULL;
static jclass pixelPacketClass = NULL;
static jmethodID pixelPacket_ctor_mid = NULL;

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_initFieldIDs(JNIEnv *env, jobject cls)
{
	handle_fid = (*env)->GetFieldID(env, cls, "vipsImageHandler", "J");
	buffer_fid = (*env)->GetFieldID(env, cls, "bufferHandler", "J");
	
	imageClass = (*env)->FindClass(env, "com/criteo/vips/VipsImage");
	ctor_mid = (*env)->GetMethodID(env, imageClass, "<init>", "(J)V");
	pixelPacketClass = (*env)->FindClass(env, "com/criteo/vips/PixelPacket");
	pixelPacket_ctor_mid = (*env)->GetMethodID(env, pixelPacketClass, "<init>", "([D)V");
	
	jclass booleanClass = (*env)->FindClass(env, "java/lang/Boolean");
	booleanValue_mid = (*env)->GetMethodID(env, booleanClass, "booleanValue", "()Z");
	jclass integerClass = (*env)->FindClass(env, "java/lang/Integer");
	intValue_mid = (*env)->GetMethodID(env, integerClass, "intValue", "()I");
	jclass longClass = (*env)->FindClass(env, "java/lang/Long");
	longValue_mid = (*env)->GetMethodID(env, longClass, "longValue", "()J");
	jclass doubleClass = (*env)->FindClass(env, "java/lang/Double");
	doubleValue_mid = (*env)->GetMethodID(env, doubleClass, "doubleValue", "()D");
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_abs(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("abs");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "abs failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_add(JNIEnv *env, jobject left, jobject right)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("add");

	// left
	if (left != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, left, handle_fid));
		g_object_set_property(G_OBJECT(op), "left", &gvalue);
		g_value_unset(&gvalue);
	}

	// right
	if (right != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, right, handle_fid));
		g_object_set_property(G_OBJECT(op), "right", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "add failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, left, handle_fid));
	(*env)->SetLongField(env, left, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_analyzeLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("analyzeload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "analyzeload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_autorot(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("autorot");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "autorot failed");
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

JNIEXPORT jdouble JNICALL
Java_com_criteo_vips_AbstractVipsImage_avg(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("avg");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "avg failed");
		return 0;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	jdouble out = g_value_get_double(&gvalue);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return out;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_bandbool(JNIEnv *env, jobject in, jobject boolean)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("bandbool");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// boolean
	if (boolean != NULL) {
		jclass booleanCls = (*env)->GetObjectClass(env, boolean);
		jfieldID booleanValueFid = (*env)->GetFieldID(env, booleanCls, "value", "I");
		jint booleanValue = (*env)->GetIntField(env, boolean, booleanValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, booleanValue);
		g_object_set_property(G_OBJECT(op), "boolean", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "bandbool failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_bandfold(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("bandfold");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// factor
		jfieldID factorFid = (*env)->GetFieldID(env, optionsCls, "factor", "Ljava/lang/Integer;");
		jobject factorObjectValue = (*env)->GetObjectField(env, options, factorFid);
		if (factorObjectValue != NULL) {
			jint factor = (*env)->CallIntMethod(env, factorObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, factor);
			g_object_set_property(G_OBJECT(op), "factor", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "bandfold failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_bandjoinConst(JNIEnv *env, jobject in, jobject c)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("bandjoin_const");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// c
	if (c != NULL) {
		jdouble *cElements = (*env)->GetDoubleArrayElements(env, c, NULL);
		jint cLength = (*env)->GetArrayLength(env, c);
		g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
		vips_value_set_array_double(&gvalue, cElements, cLength);
		(*env)->ReleaseDoubleArrayElements(env, c, cElements, 0);
		g_object_set_property(G_OBJECT(op), "c", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "bandjoin_const failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_bandmean(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("bandmean");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "bandmean failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_bandunfold(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("bandunfold");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// factor
		jfieldID factorFid = (*env)->GetFieldID(env, optionsCls, "factor", "Ljava/lang/Integer;");
		jobject factorObjectValue = (*env)->GetObjectField(env, options, factorFid);
		if (factorObjectValue != NULL) {
			jint factor = (*env)->CallIntMethod(env, factorObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, factor);
			g_object_set_property(G_OBJECT(op), "factor", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "bandunfold failed");
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
Java_com_criteo_vips_AbstractVipsImage_black(JNIEnv *env, jclass cls, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("black");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// bands
		jfieldID bandsFid = (*env)->GetFieldID(env, optionsCls, "bands", "Ljava/lang/Integer;");
		jobject bandsObjectValue = (*env)->GetObjectField(env, options, bandsFid);
		if (bandsObjectValue != NULL) {
			jint bands = (*env)->CallIntMethod(env, bandsObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, bands);
			g_object_set_property(G_OBJECT(op), "bands", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "black failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_booleanOp(JNIEnv *env, jobject left, jobject right, jobject boolean)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("boolean");

	// left
	if (left != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, left, handle_fid));
		g_object_set_property(G_OBJECT(op), "left", &gvalue);
		g_value_unset(&gvalue);
	}

	// right
	if (right != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, right, handle_fid));
		g_object_set_property(G_OBJECT(op), "right", &gvalue);
		g_value_unset(&gvalue);
	}

	// boolean
	if (boolean != NULL) {
		jclass booleanCls = (*env)->GetObjectClass(env, boolean);
		jfieldID booleanValueFid = (*env)->GetFieldID(env, booleanCls, "value", "I");
		jint booleanValue = (*env)->GetIntField(env, boolean, booleanValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, booleanValue);
		g_object_set_property(G_OBJECT(op), "boolean", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "boolean failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, left, handle_fid));
	(*env)->SetLongField(env, left, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_booleanConst(JNIEnv *env, jobject in, jobject boolean, jobject c)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("boolean_const");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// boolean
	if (boolean != NULL) {
		jclass booleanCls = (*env)->GetObjectClass(env, boolean);
		jfieldID booleanValueFid = (*env)->GetFieldID(env, booleanCls, "value", "I");
		jint booleanValue = (*env)->GetIntField(env, boolean, booleanValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, booleanValue);
		g_object_set_property(G_OBJECT(op), "boolean", &gvalue);
		g_value_unset(&gvalue);
	}

	// c
	if (c != NULL) {
		jdouble *cElements = (*env)->GetDoubleArrayElements(env, c, NULL);
		jint cLength = (*env)->GetArrayLength(env, c);
		g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
		vips_value_set_array_double(&gvalue, cElements, cLength);
		(*env)->ReleaseDoubleArrayElements(env, c, cElements, 0);
		g_object_set_property(G_OBJECT(op), "c", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "boolean_const failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_buildlut(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("buildlut");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "buildlut failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_byteswap(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("byteswap");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "byteswap failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_cache(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("cache");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// max-tiles
		jfieldID maxTilesFid = (*env)->GetFieldID(env, optionsCls, "maxTiles", "Ljava/lang/Integer;");
		jobject maxTilesObjectValue = (*env)->GetObjectField(env, options, maxTilesFid);
		if (maxTilesObjectValue != NULL) {
			jint maxTiles = (*env)->CallIntMethod(env, maxTilesObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, maxTiles);
			g_object_set_property(G_OBJECT(op), "max-tiles", &gvalue);
			g_value_unset(&gvalue);
		}

		// tile-height
		jfieldID tileHeightFid = (*env)->GetFieldID(env, optionsCls, "tileHeight", "Ljava/lang/Integer;");
		jobject tileHeightObjectValue = (*env)->GetObjectField(env, options, tileHeightFid);
		if (tileHeightObjectValue != NULL) {
			jint tileHeight = (*env)->CallIntMethod(env, tileHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileHeight);
			g_object_set_property(G_OBJECT(op), "tile-height", &gvalue);
			g_value_unset(&gvalue);
		}

		// tile-width
		jfieldID tileWidthFid = (*env)->GetFieldID(env, optionsCls, "tileWidth", "Ljava/lang/Integer;");
		jobject tileWidthObjectValue = (*env)->GetObjectField(env, options, tileWidthFid);
		if (tileWidthObjectValue != NULL) {
			jint tileWidth = (*env)->CallIntMethod(env, tileWidthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileWidth);
			g_object_set_property(G_OBJECT(op), "tile-width", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "cache failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_canny(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("canny");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// sigma
		jfieldID sigmaFid = (*env)->GetFieldID(env, optionsCls, "sigma", "Ljava/lang/Double;");
		jobject sigmaObjectValue = (*env)->GetObjectField(env, options, sigmaFid);
		if (sigmaObjectValue != NULL) {
			jdouble sigma = (*env)->CallDoubleMethod(env, sigmaObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, sigma);
			g_object_set_property(G_OBJECT(op), "sigma", &gvalue);
			g_value_unset(&gvalue);
		}

		// precision
		jfieldID precisionFid = (*env)->GetFieldID(env, optionsCls, "precision", "Lcom/criteo/vips/enums/VipsPrecision;");
		jobject precision = (*env)->GetObjectField(env, options, precisionFid);
		if (precision != NULL) {
			jclass precisionCls = (*env)->GetObjectClass(env, precision);
			jfieldID precisionValueFid = (*env)->GetFieldID(env, precisionCls, "value", "I");
			jint precisionValue = (*env)->GetIntField(env, precision, precisionValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, precisionValue);
			g_object_set_property(G_OBJECT(op), "precision", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "canny failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_cast(JNIEnv *env, jobject in, jobject format, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("cast");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// format
	if (format != NULL) {
		jclass formatCls = (*env)->GetObjectClass(env, format);
		jfieldID formatValueFid = (*env)->GetFieldID(env, formatCls, "value", "I");
		jint formatValue = (*env)->GetIntField(env, format, formatValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, formatValue);
		g_object_set_property(G_OBJECT(op), "format", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// shift
		jfieldID shiftFid = (*env)->GetFieldID(env, optionsCls, "shift", "Ljava/lang/Boolean;");
		jobject shiftObjectValue = (*env)->GetObjectField(env, options, shiftFid);
		if (shiftObjectValue != NULL) {
			jboolean shift = (*env)->CallBooleanMethod(env, shiftObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, shift);
			g_object_set_property(G_OBJECT(op), "shift", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "cast failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_cMC2LCh(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("CMC2LCh");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "CMC2LCh failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_cmyk2xyz(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("CMYK2XYZ");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "CMYK2XYZ failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_colourspace(JNIEnv *env, jobject in, jobject space, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("colourspace");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// space
	if (space != NULL) {
		jclass spaceCls = (*env)->GetObjectClass(env, space);
		jfieldID spaceValueFid = (*env)->GetFieldID(env, spaceCls, "value", "I");
		jint spaceValue = (*env)->GetIntField(env, space, spaceValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, spaceValue);
		g_object_set_property(G_OBJECT(op), "space", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// source-space
		jfieldID sourceSpaceFid = (*env)->GetFieldID(env, optionsCls, "sourceSpace", "Lcom/criteo/vips/enums/VipsInterpretation;");
		jobject sourceSpace = (*env)->GetObjectField(env, options, sourceSpaceFid);
		if (sourceSpace != NULL) {
			jclass sourceSpaceCls = (*env)->GetObjectClass(env, sourceSpace);
			jfieldID sourceSpaceValueFid = (*env)->GetFieldID(env, sourceSpaceCls, "value", "I");
			jint sourceSpaceValue = (*env)->GetIntField(env, sourceSpace, sourceSpaceValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, sourceSpaceValue);
			g_object_set_property(G_OBJECT(op), "source-space", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "colourspace failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_compass(JNIEnv *env, jobject in, jobject mask, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("compass");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// mask
	if (mask != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, mask, handle_fid));
		g_object_set_property(G_OBJECT(op), "mask", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// times
		jfieldID timesFid = (*env)->GetFieldID(env, optionsCls, "times", "Ljava/lang/Integer;");
		jobject timesObjectValue = (*env)->GetObjectField(env, options, timesFid);
		if (timesObjectValue != NULL) {
			jint times = (*env)->CallIntMethod(env, timesObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, times);
			g_object_set_property(G_OBJECT(op), "times", &gvalue);
			g_value_unset(&gvalue);
		}

		// angle
		jfieldID angleFid = (*env)->GetFieldID(env, optionsCls, "angle", "Lcom/criteo/vips/enums/VipsAngle45;");
		jobject angle = (*env)->GetObjectField(env, options, angleFid);
		if (angle != NULL) {
			jclass angleCls = (*env)->GetObjectClass(env, angle);
			jfieldID angleValueFid = (*env)->GetFieldID(env, angleCls, "value", "I");
			jint angleValue = (*env)->GetIntField(env, angle, angleValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, angleValue);
			g_object_set_property(G_OBJECT(op), "angle", &gvalue);
			g_value_unset(&gvalue);
		}

		// combine
		jfieldID combineFid = (*env)->GetFieldID(env, optionsCls, "combine", "Lcom/criteo/vips/enums/VipsCombine;");
		jobject combine = (*env)->GetObjectField(env, options, combineFid);
		if (combine != NULL) {
			jclass combineCls = (*env)->GetObjectClass(env, combine);
			jfieldID combineValueFid = (*env)->GetFieldID(env, combineCls, "value", "I");
			jint combineValue = (*env)->GetIntField(env, combine, combineValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, combineValue);
			g_object_set_property(G_OBJECT(op), "combine", &gvalue);
			g_value_unset(&gvalue);
		}

		// precision
		jfieldID precisionFid = (*env)->GetFieldID(env, optionsCls, "precision", "Lcom/criteo/vips/enums/VipsPrecision;");
		jobject precision = (*env)->GetObjectField(env, options, precisionFid);
		if (precision != NULL) {
			jclass precisionCls = (*env)->GetObjectClass(env, precision);
			jfieldID precisionValueFid = (*env)->GetFieldID(env, precisionCls, "value", "I");
			jint precisionValue = (*env)->GetIntField(env, precision, precisionValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, precisionValue);
			g_object_set_property(G_OBJECT(op), "precision", &gvalue);
			g_value_unset(&gvalue);
		}

		// layers
		jfieldID layersFid = (*env)->GetFieldID(env, optionsCls, "layers", "Ljava/lang/Integer;");
		jobject layersObjectValue = (*env)->GetObjectField(env, options, layersFid);
		if (layersObjectValue != NULL) {
			jint layers = (*env)->CallIntMethod(env, layersObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, layers);
			g_object_set_property(G_OBJECT(op), "layers", &gvalue);
			g_value_unset(&gvalue);
		}

		// cluster
		jfieldID clusterFid = (*env)->GetFieldID(env, optionsCls, "cluster", "Ljava/lang/Integer;");
		jobject clusterObjectValue = (*env)->GetObjectField(env, options, clusterFid);
		if (clusterObjectValue != NULL) {
			jint cluster = (*env)->CallIntMethod(env, clusterObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, cluster);
			g_object_set_property(G_OBJECT(op), "cluster", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "compass failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_complex(JNIEnv *env, jobject in, jobject cmplx)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("complex");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// cmplx
	if (cmplx != NULL) {
		jclass cmplxCls = (*env)->GetObjectClass(env, cmplx);
		jfieldID cmplxValueFid = (*env)->GetFieldID(env, cmplxCls, "value", "I");
		jint cmplxValue = (*env)->GetIntField(env, cmplx, cmplxValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, cmplxValue);
		g_object_set_property(G_OBJECT(op), "cmplx", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "complex failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_complex2(JNIEnv *env, jobject left, jobject right, jobject cmplx)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("complex2");

	// left
	if (left != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, left, handle_fid));
		g_object_set_property(G_OBJECT(op), "left", &gvalue);
		g_value_unset(&gvalue);
	}

	// right
	if (right != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, right, handle_fid));
		g_object_set_property(G_OBJECT(op), "right", &gvalue);
		g_value_unset(&gvalue);
	}

	// cmplx
	if (cmplx != NULL) {
		jclass cmplxCls = (*env)->GetObjectClass(env, cmplx);
		jfieldID cmplxValueFid = (*env)->GetFieldID(env, cmplxCls, "value", "I");
		jint cmplxValue = (*env)->GetIntField(env, cmplx, cmplxValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, cmplxValue);
		g_object_set_property(G_OBJECT(op), "cmplx", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "complex2 failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, left, handle_fid));
	(*env)->SetLongField(env, left, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_complexform(JNIEnv *env, jobject left, jobject right)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("complexform");

	// left
	if (left != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, left, handle_fid));
		g_object_set_property(G_OBJECT(op), "left", &gvalue);
		g_value_unset(&gvalue);
	}

	// right
	if (right != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, right, handle_fid));
		g_object_set_property(G_OBJECT(op), "right", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "complexform failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, left, handle_fid));
	(*env)->SetLongField(env, left, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_complexget(JNIEnv *env, jobject in, jobject get)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("complexget");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// get
	if (get != NULL) {
		jclass getCls = (*env)->GetObjectClass(env, get);
		jfieldID getValueFid = (*env)->GetFieldID(env, getCls, "value", "I");
		jint getValue = (*env)->GetIntField(env, get, getValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, getValue);
		g_object_set_property(G_OBJECT(op), "get", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "complexget failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_composite2(JNIEnv *env, jobject base, jobject overlay, jobject mode, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("composite2");

	// base
	if (base != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, base, handle_fid));
		g_object_set_property(G_OBJECT(op), "base", &gvalue);
		g_value_unset(&gvalue);
	}

	// overlay
	if (overlay != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, overlay, handle_fid));
		g_object_set_property(G_OBJECT(op), "overlay", &gvalue);
		g_value_unset(&gvalue);
	}

	// mode
	if (mode != NULL) {
		jclass modeCls = (*env)->GetObjectClass(env, mode);
		jfieldID modeValueFid = (*env)->GetFieldID(env, modeCls, "value", "I");
		jint modeValue = (*env)->GetIntField(env, mode, modeValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, modeValue);
		g_object_set_property(G_OBJECT(op), "mode", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// x
		jfieldID xFid = (*env)->GetFieldID(env, optionsCls, "x", "Ljava/lang/Integer;");
		jobject xObjectValue = (*env)->GetObjectField(env, options, xFid);
		if (xObjectValue != NULL) {
			jint x = (*env)->CallIntMethod(env, xObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, x);
			g_object_set_property(G_OBJECT(op), "x", &gvalue);
			g_value_unset(&gvalue);
		}

		// y
		jfieldID yFid = (*env)->GetFieldID(env, optionsCls, "y", "Ljava/lang/Integer;");
		jobject yObjectValue = (*env)->GetObjectField(env, options, yFid);
		if (yObjectValue != NULL) {
			jint y = (*env)->CallIntMethod(env, yObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, y);
			g_object_set_property(G_OBJECT(op), "y", &gvalue);
			g_value_unset(&gvalue);
		}

		// compositing-space
		jfieldID compositingSpaceFid = (*env)->GetFieldID(env, optionsCls, "compositingSpace", "Lcom/criteo/vips/enums/VipsInterpretation;");
		jobject compositingSpace = (*env)->GetObjectField(env, options, compositingSpaceFid);
		if (compositingSpace != NULL) {
			jclass compositingSpaceCls = (*env)->GetObjectClass(env, compositingSpace);
			jfieldID compositingSpaceValueFid = (*env)->GetFieldID(env, compositingSpaceCls, "value", "I");
			jint compositingSpaceValue = (*env)->GetIntField(env, compositingSpace, compositingSpaceValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, compositingSpaceValue);
			g_object_set_property(G_OBJECT(op), "compositing-space", &gvalue);
			g_value_unset(&gvalue);
		}

		// premultiplied
		jfieldID premultipliedFid = (*env)->GetFieldID(env, optionsCls, "premultiplied", "Ljava/lang/Boolean;");
		jobject premultipliedObjectValue = (*env)->GetObjectField(env, options, premultipliedFid);
		if (premultipliedObjectValue != NULL) {
			jboolean premultiplied = (*env)->CallBooleanMethod(env, premultipliedObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, premultiplied);
			g_object_set_property(G_OBJECT(op), "premultiplied", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "composite2 failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, base, handle_fid));
	(*env)->SetLongField(env, base, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_conv(JNIEnv *env, jobject in, jobject mask, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("conv");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// mask
	if (mask != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, mask, handle_fid));
		g_object_set_property(G_OBJECT(op), "mask", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// precision
		jfieldID precisionFid = (*env)->GetFieldID(env, optionsCls, "precision", "Lcom/criteo/vips/enums/VipsPrecision;");
		jobject precision = (*env)->GetObjectField(env, options, precisionFid);
		if (precision != NULL) {
			jclass precisionCls = (*env)->GetObjectClass(env, precision);
			jfieldID precisionValueFid = (*env)->GetFieldID(env, precisionCls, "value", "I");
			jint precisionValue = (*env)->GetIntField(env, precision, precisionValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, precisionValue);
			g_object_set_property(G_OBJECT(op), "precision", &gvalue);
			g_value_unset(&gvalue);
		}

		// layers
		jfieldID layersFid = (*env)->GetFieldID(env, optionsCls, "layers", "Ljava/lang/Integer;");
		jobject layersObjectValue = (*env)->GetObjectField(env, options, layersFid);
		if (layersObjectValue != NULL) {
			jint layers = (*env)->CallIntMethod(env, layersObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, layers);
			g_object_set_property(G_OBJECT(op), "layers", &gvalue);
			g_value_unset(&gvalue);
		}

		// cluster
		jfieldID clusterFid = (*env)->GetFieldID(env, optionsCls, "cluster", "Ljava/lang/Integer;");
		jobject clusterObjectValue = (*env)->GetObjectField(env, options, clusterFid);
		if (clusterObjectValue != NULL) {
			jint cluster = (*env)->CallIntMethod(env, clusterObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, cluster);
			g_object_set_property(G_OBJECT(op), "cluster", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "conv failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_conva(JNIEnv *env, jobject in, jobject mask, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("conva");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// mask
	if (mask != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, mask, handle_fid));
		g_object_set_property(G_OBJECT(op), "mask", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// layers
		jfieldID layersFid = (*env)->GetFieldID(env, optionsCls, "layers", "Ljava/lang/Integer;");
		jobject layersObjectValue = (*env)->GetObjectField(env, options, layersFid);
		if (layersObjectValue != NULL) {
			jint layers = (*env)->CallIntMethod(env, layersObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, layers);
			g_object_set_property(G_OBJECT(op), "layers", &gvalue);
			g_value_unset(&gvalue);
		}

		// cluster
		jfieldID clusterFid = (*env)->GetFieldID(env, optionsCls, "cluster", "Ljava/lang/Integer;");
		jobject clusterObjectValue = (*env)->GetObjectField(env, options, clusterFid);
		if (clusterObjectValue != NULL) {
			jint cluster = (*env)->CallIntMethod(env, clusterObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, cluster);
			g_object_set_property(G_OBJECT(op), "cluster", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "conva failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_convasep(JNIEnv *env, jobject in, jobject mask, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("convasep");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// mask
	if (mask != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, mask, handle_fid));
		g_object_set_property(G_OBJECT(op), "mask", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// layers
		jfieldID layersFid = (*env)->GetFieldID(env, optionsCls, "layers", "Ljava/lang/Integer;");
		jobject layersObjectValue = (*env)->GetObjectField(env, options, layersFid);
		if (layersObjectValue != NULL) {
			jint layers = (*env)->CallIntMethod(env, layersObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, layers);
			g_object_set_property(G_OBJECT(op), "layers", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "convasep failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_convf(JNIEnv *env, jobject in, jobject mask)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("convf");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// mask
	if (mask != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, mask, handle_fid));
		g_object_set_property(G_OBJECT(op), "mask", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "convf failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_convi(JNIEnv *env, jobject in, jobject mask)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("convi");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// mask
	if (mask != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, mask, handle_fid));
		g_object_set_property(G_OBJECT(op), "mask", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "convi failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_convsep(JNIEnv *env, jobject in, jobject mask, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("convsep");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// mask
	if (mask != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, mask, handle_fid));
		g_object_set_property(G_OBJECT(op), "mask", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// precision
		jfieldID precisionFid = (*env)->GetFieldID(env, optionsCls, "precision", "Lcom/criteo/vips/enums/VipsPrecision;");
		jobject precision = (*env)->GetObjectField(env, options, precisionFid);
		if (precision != NULL) {
			jclass precisionCls = (*env)->GetObjectClass(env, precision);
			jfieldID precisionValueFid = (*env)->GetFieldID(env, precisionCls, "value", "I");
			jint precisionValue = (*env)->GetIntField(env, precision, precisionValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, precisionValue);
			g_object_set_property(G_OBJECT(op), "precision", &gvalue);
			g_value_unset(&gvalue);
		}

		// layers
		jfieldID layersFid = (*env)->GetFieldID(env, optionsCls, "layers", "Ljava/lang/Integer;");
		jobject layersObjectValue = (*env)->GetObjectField(env, options, layersFid);
		if (layersObjectValue != NULL) {
			jint layers = (*env)->CallIntMethod(env, layersObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, layers);
			g_object_set_property(G_OBJECT(op), "layers", &gvalue);
			g_value_unset(&gvalue);
		}

		// cluster
		jfieldID clusterFid = (*env)->GetFieldID(env, optionsCls, "cluster", "Ljava/lang/Integer;");
		jobject clusterObjectValue = (*env)->GetObjectField(env, options, clusterFid);
		if (clusterObjectValue != NULL) {
			jint cluster = (*env)->CallIntMethod(env, clusterObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, cluster);
			g_object_set_property(G_OBJECT(op), "cluster", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "convsep failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_copy(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("copy");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// width
		jfieldID widthFid = (*env)->GetFieldID(env, optionsCls, "width", "Ljava/lang/Integer;");
		jobject widthObjectValue = (*env)->GetObjectField(env, options, widthFid);
		if (widthObjectValue != NULL) {
			jint width = (*env)->CallIntMethod(env, widthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, width);
			g_object_set_property(G_OBJECT(op), "width", &gvalue);
			g_value_unset(&gvalue);
		}

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

		// bands
		jfieldID bandsFid = (*env)->GetFieldID(env, optionsCls, "bands", "Ljava/lang/Integer;");
		jobject bandsObjectValue = (*env)->GetObjectField(env, options, bandsFid);
		if (bandsObjectValue != NULL) {
			jint bands = (*env)->CallIntMethod(env, bandsObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, bands);
			g_object_set_property(G_OBJECT(op), "bands", &gvalue);
			g_value_unset(&gvalue);
		}

		// format
		jfieldID formatFid = (*env)->GetFieldID(env, optionsCls, "format", "Lcom/criteo/vips/enums/VipsBandFormat;");
		jobject format = (*env)->GetObjectField(env, options, formatFid);
		if (format != NULL) {
			jclass formatCls = (*env)->GetObjectClass(env, format);
			jfieldID formatValueFid = (*env)->GetFieldID(env, formatCls, "value", "I");
			jint formatValue = (*env)->GetIntField(env, format, formatValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, formatValue);
			g_object_set_property(G_OBJECT(op), "format", &gvalue);
			g_value_unset(&gvalue);
		}

		// coding
		jfieldID codingFid = (*env)->GetFieldID(env, optionsCls, "coding", "Lcom/criteo/vips/enums/VipsCoding;");
		jobject coding = (*env)->GetObjectField(env, options, codingFid);
		if (coding != NULL) {
			jclass codingCls = (*env)->GetObjectClass(env, coding);
			jfieldID codingValueFid = (*env)->GetFieldID(env, codingCls, "value", "I");
			jint codingValue = (*env)->GetIntField(env, coding, codingValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, codingValue);
			g_object_set_property(G_OBJECT(op), "coding", &gvalue);
			g_value_unset(&gvalue);
		}

		// interpretation
		jfieldID interpretationFid = (*env)->GetFieldID(env, optionsCls, "interpretation", "Lcom/criteo/vips/enums/VipsInterpretation;");
		jobject interpretation = (*env)->GetObjectField(env, options, interpretationFid);
		if (interpretation != NULL) {
			jclass interpretationCls = (*env)->GetObjectClass(env, interpretation);
			jfieldID interpretationValueFid = (*env)->GetFieldID(env, interpretationCls, "value", "I");
			jint interpretationValue = (*env)->GetIntField(env, interpretation, interpretationValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, interpretationValue);
			g_object_set_property(G_OBJECT(op), "interpretation", &gvalue);
			g_value_unset(&gvalue);
		}

		// xres
		jfieldID xresFid = (*env)->GetFieldID(env, optionsCls, "xres", "Ljava/lang/Double;");
		jobject xresObjectValue = (*env)->GetObjectField(env, options, xresFid);
		if (xresObjectValue != NULL) {
			jdouble xres = (*env)->CallDoubleMethod(env, xresObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, xres);
			g_object_set_property(G_OBJECT(op), "xres", &gvalue);
			g_value_unset(&gvalue);
		}

		// yres
		jfieldID yresFid = (*env)->GetFieldID(env, optionsCls, "yres", "Ljava/lang/Double;");
		jobject yresObjectValue = (*env)->GetObjectField(env, options, yresFid);
		if (yresObjectValue != NULL) {
			jdouble yres = (*env)->CallDoubleMethod(env, yresObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, yres);
			g_object_set_property(G_OBJECT(op), "yres", &gvalue);
			g_value_unset(&gvalue);
		}

		// xoffset
		jfieldID xoffsetFid = (*env)->GetFieldID(env, optionsCls, "xoffset", "Ljava/lang/Integer;");
		jobject xoffsetObjectValue = (*env)->GetObjectField(env, options, xoffsetFid);
		if (xoffsetObjectValue != NULL) {
			jint xoffset = (*env)->CallIntMethod(env, xoffsetObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, xoffset);
			g_object_set_property(G_OBJECT(op), "xoffset", &gvalue);
			g_value_unset(&gvalue);
		}

		// yoffset
		jfieldID yoffsetFid = (*env)->GetFieldID(env, optionsCls, "yoffset", "Ljava/lang/Integer;");
		jobject yoffsetObjectValue = (*env)->GetObjectField(env, options, yoffsetFid);
		if (yoffsetObjectValue != NULL) {
			jint yoffset = (*env)->CallIntMethod(env, yoffsetObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, yoffset);
			g_object_set_property(G_OBJECT(op), "yoffset", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "copy failed");
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

JNIEXPORT jdouble JNICALL
Java_com_criteo_vips_AbstractVipsImage_countlines(JNIEnv *env, jobject in, jobject direction)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("countlines");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// direction
	if (direction != NULL) {
		jclass directionCls = (*env)->GetObjectClass(env, direction);
		jfieldID directionValueFid = (*env)->GetFieldID(env, directionCls, "value", "I");
		jint directionValue = (*env)->GetIntField(env, direction, directionValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, directionValue);
		g_object_set_property(G_OBJECT(op), "direction", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "countlines failed");
		return 0;
	}
	g_object_unref(op);
	op = new_op;

	// nolines
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_object_get_property(G_OBJECT(op), "nolines", &gvalue);
	jdouble nolines = g_value_get_double(&gvalue);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return nolines;
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_csvLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("csvload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// skip
		jfieldID skipFid = (*env)->GetFieldID(env, optionsCls, "skip", "Ljava/lang/Integer;");
		jobject skipObjectValue = (*env)->GetObjectField(env, options, skipFid);
		if (skipObjectValue != NULL) {
			jint skip = (*env)->CallIntMethod(env, skipObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, skip);
			g_object_set_property(G_OBJECT(op), "skip", &gvalue);
			g_value_unset(&gvalue);
		}

		// lines
		jfieldID linesFid = (*env)->GetFieldID(env, optionsCls, "lines", "Ljava/lang/Integer;");
		jobject linesObjectValue = (*env)->GetObjectField(env, options, linesFid);
		if (linesObjectValue != NULL) {
			jint lines = (*env)->CallIntMethod(env, linesObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, lines);
			g_object_set_property(G_OBJECT(op), "lines", &gvalue);
			g_value_unset(&gvalue);
		}

		// whitespace
		jfieldID whitespaceFid = (*env)->GetFieldID(env, optionsCls, "whitespace", "Ljava/lang/String;");
		jstring whitespace = (jstring) (*env)->GetObjectField(env, options, whitespaceFid);
		if (whitespace != NULL) {
			const char *whitespaceChars = (*env)->GetStringUTFChars(env, whitespace, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, whitespaceChars);
			(*env)->ReleaseStringUTFChars(env, whitespace, whitespaceChars);
			g_object_set_property(G_OBJECT(op), "whitespace", &gvalue);
			g_value_unset(&gvalue);
		}

		// separator
		jfieldID separatorFid = (*env)->GetFieldID(env, optionsCls, "separator", "Ljava/lang/String;");
		jstring separator = (jstring) (*env)->GetObjectField(env, options, separatorFid);
		if (separator != NULL) {
			const char *separatorChars = (*env)->GetStringUTFChars(env, separator, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, separatorChars);
			(*env)->ReleaseStringUTFChars(env, separator, separatorChars);
			g_object_set_property(G_OBJECT(op), "separator", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "csvload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_csvSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("csvsave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// separator
		jfieldID separatorFid = (*env)->GetFieldID(env, optionsCls, "separator", "Ljava/lang/String;");
		jstring separator = (jstring) (*env)->GetObjectField(env, options, separatorFid);
		if (separator != NULL) {
			const char *separatorChars = (*env)->GetStringUTFChars(env, separator, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, separatorChars);
			(*env)->ReleaseStringUTFChars(env, separator, separatorChars);
			g_object_set_property(G_OBJECT(op), "separator", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "csvsave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_dE00(JNIEnv *env, jobject left, jobject right)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("dE00");

	// left
	if (left != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, left, handle_fid));
		g_object_set_property(G_OBJECT(op), "left", &gvalue);
		g_value_unset(&gvalue);
	}

	// right
	if (right != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, right, handle_fid));
		g_object_set_property(G_OBJECT(op), "right", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "dE00 failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, left, handle_fid));
	(*env)->SetLongField(env, left, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_dE76(JNIEnv *env, jobject left, jobject right)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("dE76");

	// left
	if (left != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, left, handle_fid));
		g_object_set_property(G_OBJECT(op), "left", &gvalue);
		g_value_unset(&gvalue);
	}

	// right
	if (right != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, right, handle_fid));
		g_object_set_property(G_OBJECT(op), "right", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "dE76 failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, left, handle_fid));
	(*env)->SetLongField(env, left, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_dECMC(JNIEnv *env, jobject left, jobject right)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("dECMC");

	// left
	if (left != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, left, handle_fid));
		g_object_set_property(G_OBJECT(op), "left", &gvalue);
		g_value_unset(&gvalue);
	}

	// right
	if (right != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, right, handle_fid));
		g_object_set_property(G_OBJECT(op), "right", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "dECMC failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, left, handle_fid));
	(*env)->SetLongField(env, left, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jdouble JNICALL
Java_com_criteo_vips_AbstractVipsImage_deviate(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("deviate");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "deviate failed");
		return 0;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	jdouble out = g_value_get_double(&gvalue);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return out;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_divide(JNIEnv *env, jobject left, jobject right)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("divide");

	// left
	if (left != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, left, handle_fid));
		g_object_set_property(G_OBJECT(op), "left", &gvalue);
		g_value_unset(&gvalue);
	}

	// right
	if (right != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, right, handle_fid));
		g_object_set_property(G_OBJECT(op), "right", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "divide failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, left, handle_fid));
	(*env)->SetLongField(env, left, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_drawCircle(JNIEnv *env, jobject image, jobject ink, jint cx, jint cy, jint radius, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("draw_circle");

	// image
	if (image != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, image, handle_fid));
		g_object_set_property(G_OBJECT(op), "image", &gvalue);
		g_value_unset(&gvalue);
	}

	// ink
	if (ink != NULL) {
		jdouble *inkElements = (*env)->GetDoubleArrayElements(env, ink, NULL);
		jint inkLength = (*env)->GetArrayLength(env, ink);
		g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
		vips_value_set_array_double(&gvalue, inkElements, inkLength);
		(*env)->ReleaseDoubleArrayElements(env, ink, inkElements, 0);
		g_object_set_property(G_OBJECT(op), "ink", &gvalue);
		g_value_unset(&gvalue);
	}

	// cx
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, cx);
	g_object_set_property(G_OBJECT(op), "cx", &gvalue);
	g_value_unset(&gvalue);

	// cy
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, cy);
	g_object_set_property(G_OBJECT(op), "cy", &gvalue);
	g_value_unset(&gvalue);

	// radius
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, radius);
	g_object_set_property(G_OBJECT(op), "radius", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// fill
		jfieldID fillFid = (*env)->GetFieldID(env, optionsCls, "fill", "Ljava/lang/Boolean;");
		jobject fillObjectValue = (*env)->GetObjectField(env, options, fillFid);
		if (fillObjectValue != NULL) {
			jboolean fill = (*env)->CallBooleanMethod(env, fillObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, fill);
			g_object_set_property(G_OBJECT(op), "fill", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "draw_circle failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_drawImage(JNIEnv *env, jobject image, jobject sub, jint x, jint y, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("draw_image");

	// image
	if (image != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, image, handle_fid));
		g_object_set_property(G_OBJECT(op), "image", &gvalue);
		g_value_unset(&gvalue);
	}

	// sub
	if (sub != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, sub, handle_fid));
		g_object_set_property(G_OBJECT(op), "sub", &gvalue);
		g_value_unset(&gvalue);
	}

	// x
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, x);
	g_object_set_property(G_OBJECT(op), "x", &gvalue);
	g_value_unset(&gvalue);

	// y
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, y);
	g_object_set_property(G_OBJECT(op), "y", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// mode
		jfieldID modeFid = (*env)->GetFieldID(env, optionsCls, "mode", "Lcom/criteo/vips/enums/VipsCombineMode;");
		jobject mode = (*env)->GetObjectField(env, options, modeFid);
		if (mode != NULL) {
			jclass modeCls = (*env)->GetObjectClass(env, mode);
			jfieldID modeValueFid = (*env)->GetFieldID(env, modeCls, "value", "I");
			jint modeValue = (*env)->GetIntField(env, mode, modeValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, modeValue);
			g_object_set_property(G_OBJECT(op), "mode", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "draw_image failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_drawLine(JNIEnv *env, jobject image, jobject ink, jint x1, jint y1, jint x2, jint y2)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("draw_line");

	// image
	if (image != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, image, handle_fid));
		g_object_set_property(G_OBJECT(op), "image", &gvalue);
		g_value_unset(&gvalue);
	}

	// ink
	if (ink != NULL) {
		jdouble *inkElements = (*env)->GetDoubleArrayElements(env, ink, NULL);
		jint inkLength = (*env)->GetArrayLength(env, ink);
		g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
		vips_value_set_array_double(&gvalue, inkElements, inkLength);
		(*env)->ReleaseDoubleArrayElements(env, ink, inkElements, 0);
		g_object_set_property(G_OBJECT(op), "ink", &gvalue);
		g_value_unset(&gvalue);
	}

	// x1
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, x1);
	g_object_set_property(G_OBJECT(op), "x1", &gvalue);
	g_value_unset(&gvalue);

	// y1
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, y1);
	g_object_set_property(G_OBJECT(op), "y1", &gvalue);
	g_value_unset(&gvalue);

	// x2
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, x2);
	g_object_set_property(G_OBJECT(op), "x2", &gvalue);
	g_value_unset(&gvalue);

	// y2
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, y2);
	g_object_set_property(G_OBJECT(op), "y2", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "draw_line failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_drawMask(JNIEnv *env, jobject image, jobject ink, jobject mask, jint x, jint y)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("draw_mask");

	// image
	if (image != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, image, handle_fid));
		g_object_set_property(G_OBJECT(op), "image", &gvalue);
		g_value_unset(&gvalue);
	}

	// ink
	if (ink != NULL) {
		jdouble *inkElements = (*env)->GetDoubleArrayElements(env, ink, NULL);
		jint inkLength = (*env)->GetArrayLength(env, ink);
		g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
		vips_value_set_array_double(&gvalue, inkElements, inkLength);
		(*env)->ReleaseDoubleArrayElements(env, ink, inkElements, 0);
		g_object_set_property(G_OBJECT(op), "ink", &gvalue);
		g_value_unset(&gvalue);
	}

	// mask
	if (mask != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, mask, handle_fid));
		g_object_set_property(G_OBJECT(op), "mask", &gvalue);
		g_value_unset(&gvalue);
	}

	// x
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, x);
	g_object_set_property(G_OBJECT(op), "x", &gvalue);
	g_value_unset(&gvalue);

	// y
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, y);
	g_object_set_property(G_OBJECT(op), "y", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "draw_mask failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_drawRect(JNIEnv *env, jobject image, jobject ink, jint left, jint top, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("draw_rect");

	// image
	if (image != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, image, handle_fid));
		g_object_set_property(G_OBJECT(op), "image", &gvalue);
		g_value_unset(&gvalue);
	}

	// ink
	if (ink != NULL) {
		jdouble *inkElements = (*env)->GetDoubleArrayElements(env, ink, NULL);
		jint inkLength = (*env)->GetArrayLength(env, ink);
		g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
		vips_value_set_array_double(&gvalue, inkElements, inkLength);
		(*env)->ReleaseDoubleArrayElements(env, ink, inkElements, 0);
		g_object_set_property(G_OBJECT(op), "ink", &gvalue);
		g_value_unset(&gvalue);
	}

	// left
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, left);
	g_object_set_property(G_OBJECT(op), "left", &gvalue);
	g_value_unset(&gvalue);

	// top
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, top);
	g_object_set_property(G_OBJECT(op), "top", &gvalue);
	g_value_unset(&gvalue);

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// fill
		jfieldID fillFid = (*env)->GetFieldID(env, optionsCls, "fill", "Ljava/lang/Boolean;");
		jobject fillObjectValue = (*env)->GetObjectField(env, options, fillFid);
		if (fillObjectValue != NULL) {
			jboolean fill = (*env)->CallBooleanMethod(env, fillObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, fill);
			g_object_set_property(G_OBJECT(op), "fill", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "draw_rect failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_drawSmudge(JNIEnv *env, jobject image, jint left, jint top, jint width, jint height)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("draw_smudge");

	// image
	if (image != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, image, handle_fid));
		g_object_set_property(G_OBJECT(op), "image", &gvalue);
		g_value_unset(&gvalue);
	}

	// left
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, left);
	g_object_set_property(G_OBJECT(op), "left", &gvalue);
	g_value_unset(&gvalue);

	// top
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, top);
	g_object_set_property(G_OBJECT(op), "top", &gvalue);
	g_value_unset(&gvalue);

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "draw_smudge failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_dzSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("dzsave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// basename
		jfieldID basenameFid = (*env)->GetFieldID(env, optionsCls, "basename", "Ljava/lang/String;");
		jstring basename = (jstring) (*env)->GetObjectField(env, options, basenameFid);
		if (basename != NULL) {
			const char *basenameChars = (*env)->GetStringUTFChars(env, basename, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, basenameChars);
			(*env)->ReleaseStringUTFChars(env, basename, basenameChars);
			g_object_set_property(G_OBJECT(op), "basename", &gvalue);
			g_value_unset(&gvalue);
		}

		// layout
		jfieldID layoutFid = (*env)->GetFieldID(env, optionsCls, "layout", "Lcom/criteo/vips/enums/VipsForeignDzLayout;");
		jobject layout = (*env)->GetObjectField(env, options, layoutFid);
		if (layout != NULL) {
			jclass layoutCls = (*env)->GetObjectClass(env, layout);
			jfieldID layoutValueFid = (*env)->GetFieldID(env, layoutCls, "value", "I");
			jint layoutValue = (*env)->GetIntField(env, layout, layoutValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, layoutValue);
			g_object_set_property(G_OBJECT(op), "layout", &gvalue);
			g_value_unset(&gvalue);
		}

		// suffix
		jfieldID suffixFid = (*env)->GetFieldID(env, optionsCls, "suffix", "Ljava/lang/String;");
		jstring suffix = (jstring) (*env)->GetObjectField(env, options, suffixFid);
		if (suffix != NULL) {
			const char *suffixChars = (*env)->GetStringUTFChars(env, suffix, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, suffixChars);
			(*env)->ReleaseStringUTFChars(env, suffix, suffixChars);
			g_object_set_property(G_OBJECT(op), "suffix", &gvalue);
			g_value_unset(&gvalue);
		}

		// overlap
		jfieldID overlapFid = (*env)->GetFieldID(env, optionsCls, "overlap", "Ljava/lang/Integer;");
		jobject overlapObjectValue = (*env)->GetObjectField(env, options, overlapFid);
		if (overlapObjectValue != NULL) {
			jint overlap = (*env)->CallIntMethod(env, overlapObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, overlap);
			g_object_set_property(G_OBJECT(op), "overlap", &gvalue);
			g_value_unset(&gvalue);
		}

		// tile-size
		jfieldID tileSizeFid = (*env)->GetFieldID(env, optionsCls, "tileSize", "Ljava/lang/Integer;");
		jobject tileSizeObjectValue = (*env)->GetObjectField(env, options, tileSizeFid);
		if (tileSizeObjectValue != NULL) {
			jint tileSize = (*env)->CallIntMethod(env, tileSizeObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileSize);
			g_object_set_property(G_OBJECT(op), "tile-size", &gvalue);
			g_value_unset(&gvalue);
		}

		// centre
		jfieldID centreFid = (*env)->GetFieldID(env, optionsCls, "centre", "Ljava/lang/Boolean;");
		jobject centreObjectValue = (*env)->GetObjectField(env, options, centreFid);
		if (centreObjectValue != NULL) {
			jboolean centre = (*env)->CallBooleanMethod(env, centreObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, centre);
			g_object_set_property(G_OBJECT(op), "centre", &gvalue);
			g_value_unset(&gvalue);
		}

		// depth
		jfieldID depthFid = (*env)->GetFieldID(env, optionsCls, "depth", "Lcom/criteo/vips/enums/VipsForeignDzDepth;");
		jobject depth = (*env)->GetObjectField(env, options, depthFid);
		if (depth != NULL) {
			jclass depthCls = (*env)->GetObjectClass(env, depth);
			jfieldID depthValueFid = (*env)->GetFieldID(env, depthCls, "value", "I");
			jint depthValue = (*env)->GetIntField(env, depth, depthValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, depthValue);
			g_object_set_property(G_OBJECT(op), "depth", &gvalue);
			g_value_unset(&gvalue);
		}

		// angle
		jfieldID angleFid = (*env)->GetFieldID(env, optionsCls, "angle", "Lcom/criteo/vips/enums/VipsAngle;");
		jobject angle = (*env)->GetObjectField(env, options, angleFid);
		if (angle != NULL) {
			jclass angleCls = (*env)->GetObjectClass(env, angle);
			jfieldID angleValueFid = (*env)->GetFieldID(env, angleCls, "value", "I");
			jint angleValue = (*env)->GetIntField(env, angle, angleValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, angleValue);
			g_object_set_property(G_OBJECT(op), "angle", &gvalue);
			g_value_unset(&gvalue);
		}

		// container
		jfieldID containerFid = (*env)->GetFieldID(env, optionsCls, "container", "Lcom/criteo/vips/enums/VipsForeignDzContainer;");
		jobject container = (*env)->GetObjectField(env, options, containerFid);
		if (container != NULL) {
			jclass containerCls = (*env)->GetObjectClass(env, container);
			jfieldID containerValueFid = (*env)->GetFieldID(env, containerCls, "value", "I");
			jint containerValue = (*env)->GetIntField(env, container, containerValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, containerValue);
			g_object_set_property(G_OBJECT(op), "container", &gvalue);
			g_value_unset(&gvalue);
		}

		// properties
		jfieldID propertiesFid = (*env)->GetFieldID(env, optionsCls, "properties", "Ljava/lang/Boolean;");
		jobject propertiesObjectValue = (*env)->GetObjectField(env, options, propertiesFid);
		if (propertiesObjectValue != NULL) {
			jboolean properties = (*env)->CallBooleanMethod(env, propertiesObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, properties);
			g_object_set_property(G_OBJECT(op), "properties", &gvalue);
			g_value_unset(&gvalue);
		}

		// compression
		jfieldID compressionFid = (*env)->GetFieldID(env, optionsCls, "compression", "Ljava/lang/Integer;");
		jobject compressionObjectValue = (*env)->GetObjectField(env, options, compressionFid);
		if (compressionObjectValue != NULL) {
			jint compression = (*env)->CallIntMethod(env, compressionObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, compression);
			g_object_set_property(G_OBJECT(op), "compression", &gvalue);
			g_value_unset(&gvalue);
		}

		// region-shrink
		jfieldID regionShrinkFid = (*env)->GetFieldID(env, optionsCls, "regionShrink", "Lcom/criteo/vips/enums/VipsRegionShrink;");
		jobject regionShrink = (*env)->GetObjectField(env, options, regionShrinkFid);
		if (regionShrink != NULL) {
			jclass regionShrinkCls = (*env)->GetObjectClass(env, regionShrink);
			jfieldID regionShrinkValueFid = (*env)->GetFieldID(env, regionShrinkCls, "value", "I");
			jint regionShrinkValue = (*env)->GetIntField(env, regionShrink, regionShrinkValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, regionShrinkValue);
			g_object_set_property(G_OBJECT(op), "region-shrink", &gvalue);
			g_value_unset(&gvalue);
		}

		// skip-blanks
		jfieldID skipBlanksFid = (*env)->GetFieldID(env, optionsCls, "skipBlanks", "Ljava/lang/Integer;");
		jobject skipBlanksObjectValue = (*env)->GetObjectField(env, options, skipBlanksFid);
		if (skipBlanksObjectValue != NULL) {
			jint skipBlanks = (*env)->CallIntMethod(env, skipBlanksObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, skipBlanks);
			g_object_set_property(G_OBJECT(op), "skip-blanks", &gvalue);
			g_value_unset(&gvalue);
		}

		// no-strip
		jfieldID noStripFid = (*env)->GetFieldID(env, optionsCls, "noStrip", "Ljava/lang/Boolean;");
		jobject noStripObjectValue = (*env)->GetObjectField(env, options, noStripFid);
		if (noStripObjectValue != NULL) {
			jboolean noStrip = (*env)->CallBooleanMethod(env, noStripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, noStrip);
			g_object_set_property(G_OBJECT(op), "no-strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// id
		jfieldID idFid = (*env)->GetFieldID(env, optionsCls, "id", "Ljava/lang/String;");
		jstring id = (jstring) (*env)->GetObjectField(env, options, idFid);
		if (id != NULL) {
			const char *idChars = (*env)->GetStringUTFChars(env, id, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, idChars);
			(*env)->ReleaseStringUTFChars(env, id, idChars);
			g_object_set_property(G_OBJECT(op), "id", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "dzsave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_AbstractVipsImage_dzSaveBuffer(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("dzsave_buffer");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// basename
		jfieldID basenameFid = (*env)->GetFieldID(env, optionsCls, "basename", "Ljava/lang/String;");
		jstring basename = (jstring) (*env)->GetObjectField(env, options, basenameFid);
		if (basename != NULL) {
			const char *basenameChars = (*env)->GetStringUTFChars(env, basename, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, basenameChars);
			(*env)->ReleaseStringUTFChars(env, basename, basenameChars);
			g_object_set_property(G_OBJECT(op), "basename", &gvalue);
			g_value_unset(&gvalue);
		}

		// layout
		jfieldID layoutFid = (*env)->GetFieldID(env, optionsCls, "layout", "Lcom/criteo/vips/enums/VipsForeignDzLayout;");
		jobject layout = (*env)->GetObjectField(env, options, layoutFid);
		if (layout != NULL) {
			jclass layoutCls = (*env)->GetObjectClass(env, layout);
			jfieldID layoutValueFid = (*env)->GetFieldID(env, layoutCls, "value", "I");
			jint layoutValue = (*env)->GetIntField(env, layout, layoutValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, layoutValue);
			g_object_set_property(G_OBJECT(op), "layout", &gvalue);
			g_value_unset(&gvalue);
		}

		// suffix
		jfieldID suffixFid = (*env)->GetFieldID(env, optionsCls, "suffix", "Ljava/lang/String;");
		jstring suffix = (jstring) (*env)->GetObjectField(env, options, suffixFid);
		if (suffix != NULL) {
			const char *suffixChars = (*env)->GetStringUTFChars(env, suffix, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, suffixChars);
			(*env)->ReleaseStringUTFChars(env, suffix, suffixChars);
			g_object_set_property(G_OBJECT(op), "suffix", &gvalue);
			g_value_unset(&gvalue);
		}

		// overlap
		jfieldID overlapFid = (*env)->GetFieldID(env, optionsCls, "overlap", "Ljava/lang/Integer;");
		jobject overlapObjectValue = (*env)->GetObjectField(env, options, overlapFid);
		if (overlapObjectValue != NULL) {
			jint overlap = (*env)->CallIntMethod(env, overlapObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, overlap);
			g_object_set_property(G_OBJECT(op), "overlap", &gvalue);
			g_value_unset(&gvalue);
		}

		// tile-size
		jfieldID tileSizeFid = (*env)->GetFieldID(env, optionsCls, "tileSize", "Ljava/lang/Integer;");
		jobject tileSizeObjectValue = (*env)->GetObjectField(env, options, tileSizeFid);
		if (tileSizeObjectValue != NULL) {
			jint tileSize = (*env)->CallIntMethod(env, tileSizeObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileSize);
			g_object_set_property(G_OBJECT(op), "tile-size", &gvalue);
			g_value_unset(&gvalue);
		}

		// centre
		jfieldID centreFid = (*env)->GetFieldID(env, optionsCls, "centre", "Ljava/lang/Boolean;");
		jobject centreObjectValue = (*env)->GetObjectField(env, options, centreFid);
		if (centreObjectValue != NULL) {
			jboolean centre = (*env)->CallBooleanMethod(env, centreObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, centre);
			g_object_set_property(G_OBJECT(op), "centre", &gvalue);
			g_value_unset(&gvalue);
		}

		// depth
		jfieldID depthFid = (*env)->GetFieldID(env, optionsCls, "depth", "Lcom/criteo/vips/enums/VipsForeignDzDepth;");
		jobject depth = (*env)->GetObjectField(env, options, depthFid);
		if (depth != NULL) {
			jclass depthCls = (*env)->GetObjectClass(env, depth);
			jfieldID depthValueFid = (*env)->GetFieldID(env, depthCls, "value", "I");
			jint depthValue = (*env)->GetIntField(env, depth, depthValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, depthValue);
			g_object_set_property(G_OBJECT(op), "depth", &gvalue);
			g_value_unset(&gvalue);
		}

		// angle
		jfieldID angleFid = (*env)->GetFieldID(env, optionsCls, "angle", "Lcom/criteo/vips/enums/VipsAngle;");
		jobject angle = (*env)->GetObjectField(env, options, angleFid);
		if (angle != NULL) {
			jclass angleCls = (*env)->GetObjectClass(env, angle);
			jfieldID angleValueFid = (*env)->GetFieldID(env, angleCls, "value", "I");
			jint angleValue = (*env)->GetIntField(env, angle, angleValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, angleValue);
			g_object_set_property(G_OBJECT(op), "angle", &gvalue);
			g_value_unset(&gvalue);
		}

		// container
		jfieldID containerFid = (*env)->GetFieldID(env, optionsCls, "container", "Lcom/criteo/vips/enums/VipsForeignDzContainer;");
		jobject container = (*env)->GetObjectField(env, options, containerFid);
		if (container != NULL) {
			jclass containerCls = (*env)->GetObjectClass(env, container);
			jfieldID containerValueFid = (*env)->GetFieldID(env, containerCls, "value", "I");
			jint containerValue = (*env)->GetIntField(env, container, containerValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, containerValue);
			g_object_set_property(G_OBJECT(op), "container", &gvalue);
			g_value_unset(&gvalue);
		}

		// properties
		jfieldID propertiesFid = (*env)->GetFieldID(env, optionsCls, "properties", "Ljava/lang/Boolean;");
		jobject propertiesObjectValue = (*env)->GetObjectField(env, options, propertiesFid);
		if (propertiesObjectValue != NULL) {
			jboolean properties = (*env)->CallBooleanMethod(env, propertiesObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, properties);
			g_object_set_property(G_OBJECT(op), "properties", &gvalue);
			g_value_unset(&gvalue);
		}

		// compression
		jfieldID compressionFid = (*env)->GetFieldID(env, optionsCls, "compression", "Ljava/lang/Integer;");
		jobject compressionObjectValue = (*env)->GetObjectField(env, options, compressionFid);
		if (compressionObjectValue != NULL) {
			jint compression = (*env)->CallIntMethod(env, compressionObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, compression);
			g_object_set_property(G_OBJECT(op), "compression", &gvalue);
			g_value_unset(&gvalue);
		}

		// region-shrink
		jfieldID regionShrinkFid = (*env)->GetFieldID(env, optionsCls, "regionShrink", "Lcom/criteo/vips/enums/VipsRegionShrink;");
		jobject regionShrink = (*env)->GetObjectField(env, options, regionShrinkFid);
		if (regionShrink != NULL) {
			jclass regionShrinkCls = (*env)->GetObjectClass(env, regionShrink);
			jfieldID regionShrinkValueFid = (*env)->GetFieldID(env, regionShrinkCls, "value", "I");
			jint regionShrinkValue = (*env)->GetIntField(env, regionShrink, regionShrinkValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, regionShrinkValue);
			g_object_set_property(G_OBJECT(op), "region-shrink", &gvalue);
			g_value_unset(&gvalue);
		}

		// skip-blanks
		jfieldID skipBlanksFid = (*env)->GetFieldID(env, optionsCls, "skipBlanks", "Ljava/lang/Integer;");
		jobject skipBlanksObjectValue = (*env)->GetObjectField(env, options, skipBlanksFid);
		if (skipBlanksObjectValue != NULL) {
			jint skipBlanks = (*env)->CallIntMethod(env, skipBlanksObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, skipBlanks);
			g_object_set_property(G_OBJECT(op), "skip-blanks", &gvalue);
			g_value_unset(&gvalue);
		}

		// no-strip
		jfieldID noStripFid = (*env)->GetFieldID(env, optionsCls, "noStrip", "Ljava/lang/Boolean;");
		jobject noStripObjectValue = (*env)->GetObjectField(env, options, noStripFid);
		if (noStripObjectValue != NULL) {
			jboolean noStrip = (*env)->CallBooleanMethod(env, noStripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, noStrip);
			g_object_set_property(G_OBJECT(op), "no-strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// id
		jfieldID idFid = (*env)->GetFieldID(env, optionsCls, "id", "Ljava/lang/String;");
		jstring id = (jstring) (*env)->GetObjectField(env, options, idFid);
		if (id != NULL) {
			const char *idChars = (*env)->GetStringUTFChars(env, id, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, idChars);
			(*env)->ReleaseStringUTFChars(env, id, idChars);
			g_object_set_property(G_OBJECT(op), "id", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "dzsave_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// buffer
	g_value_init(&gvalue, VIPS_TYPE_BLOB);
	g_object_get_property(G_OBJECT(op), "buffer", &gvalue);
	size_t bufferSize = 0;
	void *bufferData = vips_value_get_blob(&gvalue, &bufferSize);
	jint bufferLength = bufferSize / sizeof(jbyte);
	jbyteArray buffer = (*env)->NewByteArray(env, bufferLength);
	(*env)->SetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return buffer;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_embed(JNIEnv *env, jobject in, jint x, jint y, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("embed");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// x
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, x);
	g_object_set_property(G_OBJECT(op), "x", &gvalue);
	g_value_unset(&gvalue);

	// y
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, y);
	g_object_set_property(G_OBJECT(op), "y", &gvalue);
	g_value_unset(&gvalue);

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// extend
		jfieldID extendFid = (*env)->GetFieldID(env, optionsCls, "extend", "Lcom/criteo/vips/enums/VipsExtend;");
		jobject extend = (*env)->GetObjectField(env, options, extendFid);
		if (extend != NULL) {
			jclass extendCls = (*env)->GetObjectClass(env, extend);
			jfieldID extendValueFid = (*env)->GetFieldID(env, extendCls, "value", "I");
			jint extendValue = (*env)->GetIntField(env, extend, extendValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, extendValue);
			g_object_set_property(G_OBJECT(op), "extend", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "embed failed");
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
Java_com_criteo_vips_AbstractVipsImage_extractArea(JNIEnv *env, jobject input, jint left, jint top, jint width, jint height)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("extract_area");

	// input
	if (input != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, input, handle_fid));
		g_object_set_property(G_OBJECT(op), "input", &gvalue);
		g_value_unset(&gvalue);
	}

	// left
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, left);
	g_object_set_property(G_OBJECT(op), "left", &gvalue);
	g_value_unset(&gvalue);

	// top
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, top);
	g_object_set_property(G_OBJECT(op), "top", &gvalue);
	g_value_unset(&gvalue);

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "extract_area failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, imageClass, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_extractBand(JNIEnv *env, jobject in, jint band, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("extract_band");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// band
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, band);
	g_object_set_property(G_OBJECT(op), "band", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// n
		jfieldID nFid = (*env)->GetFieldID(env, optionsCls, "n", "Ljava/lang/Integer;");
		jobject nObjectValue = (*env)->GetObjectField(env, options, nFid);
		if (nObjectValue != NULL) {
			jint n = (*env)->CallIntMethod(env, nObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, n);
			g_object_set_property(G_OBJECT(op), "n", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "extract_band failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, imageClass, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_eye(JNIEnv *env, jclass cls, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("eye");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

		// factor
		jfieldID factorFid = (*env)->GetFieldID(env, optionsCls, "factor", "Ljava/lang/Double;");
		jobject factorObjectValue = (*env)->GetObjectField(env, options, factorFid);
		if (factorObjectValue != NULL) {
			jdouble factor = (*env)->CallDoubleMethod(env, factorObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, factor);
			g_object_set_property(G_OBJECT(op), "factor", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "eye failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_falsecolour(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("falsecolour");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "falsecolour failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_fastcor(JNIEnv *env, jobject in, jobject ref)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("fastcor");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// ref
	if (ref != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, ref, handle_fid));
		g_object_set_property(G_OBJECT(op), "ref", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "fastcor failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_fillNearest(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("fill_nearest");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "fill_nearest failed");
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
Java_com_criteo_vips_AbstractVipsImage_fitsLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("fitsload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "fitsload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_fitsSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("fitssave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "fitssave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_flatten(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("flatten");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// max-alpha
		jfieldID maxAlphaFid = (*env)->GetFieldID(env, optionsCls, "maxAlpha", "Ljava/lang/Double;");
		jobject maxAlphaObjectValue = (*env)->GetObjectField(env, options, maxAlphaFid);
		if (maxAlphaObjectValue != NULL) {
			jdouble maxAlpha = (*env)->CallDoubleMethod(env, maxAlphaObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, maxAlpha);
			g_object_set_property(G_OBJECT(op), "max-alpha", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "flatten failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_flip(JNIEnv *env, jobject in, jobject direction)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("flip");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// direction
	if (direction != NULL) {
		jclass directionCls = (*env)->GetObjectClass(env, direction);
		jfieldID directionValueFid = (*env)->GetFieldID(env, directionCls, "value", "I");
		jint directionValue = (*env)->GetIntField(env, direction, directionValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, directionValue);
		g_object_set_property(G_OBJECT(op), "direction", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "flip failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_float2rad(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("float2rad");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "float2rad failed");
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
Java_com_criteo_vips_AbstractVipsImage_fractsurf(JNIEnv *env, jclass cls, jint width, jint height, jdouble fractalDimension)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("fractsurf");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// fractal-dimension
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, fractalDimension);
	g_object_set_property(G_OBJECT(op), "fractal-dimension", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "fractsurf failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_freqmult(JNIEnv *env, jobject in, jobject mask)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("freqmult");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// mask
	if (mask != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, mask, handle_fid));
		g_object_set_property(G_OBJECT(op), "mask", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "freqmult failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_fwfft(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("fwfft");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "fwfft failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_gamma(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("gamma");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// exponent
		jfieldID exponentFid = (*env)->GetFieldID(env, optionsCls, "exponent", "Ljava/lang/Double;");
		jobject exponentObjectValue = (*env)->GetObjectField(env, options, exponentFid);
		if (exponentObjectValue != NULL) {
			jdouble exponent = (*env)->CallDoubleMethod(env, exponentObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, exponent);
			g_object_set_property(G_OBJECT(op), "exponent", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "gamma failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_gaussblur(JNIEnv *env, jobject in, jdouble sigma, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("gaussblur");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// sigma
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, sigma);
	g_object_set_property(G_OBJECT(op), "sigma", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// min-ampl
		jfieldID minAmplFid = (*env)->GetFieldID(env, optionsCls, "minAmpl", "Ljava/lang/Double;");
		jobject minAmplObjectValue = (*env)->GetObjectField(env, options, minAmplFid);
		if (minAmplObjectValue != NULL) {
			jdouble minAmpl = (*env)->CallDoubleMethod(env, minAmplObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, minAmpl);
			g_object_set_property(G_OBJECT(op), "min-ampl", &gvalue);
			g_value_unset(&gvalue);
		}

		// precision
		jfieldID precisionFid = (*env)->GetFieldID(env, optionsCls, "precision", "Lcom/criteo/vips/enums/VipsPrecision;");
		jobject precision = (*env)->GetObjectField(env, options, precisionFid);
		if (precision != NULL) {
			jclass precisionCls = (*env)->GetObjectClass(env, precision);
			jfieldID precisionValueFid = (*env)->GetFieldID(env, precisionCls, "value", "I");
			jint precisionValue = (*env)->GetIntField(env, precision, precisionValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, precisionValue);
			g_object_set_property(G_OBJECT(op), "precision", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "gaussblur failed");
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
Java_com_criteo_vips_AbstractVipsImage_gaussmat(JNIEnv *env, jclass cls, jdouble sigma, jdouble minAmpl, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("gaussmat");

	// sigma
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, sigma);
	g_object_set_property(G_OBJECT(op), "sigma", &gvalue);
	g_value_unset(&gvalue);

	// min-ampl
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, minAmpl);
	g_object_set_property(G_OBJECT(op), "min-ampl", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// separable
		jfieldID separableFid = (*env)->GetFieldID(env, optionsCls, "separable", "Ljava/lang/Boolean;");
		jobject separableObjectValue = (*env)->GetObjectField(env, options, separableFid);
		if (separableObjectValue != NULL) {
			jboolean separable = (*env)->CallBooleanMethod(env, separableObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, separable);
			g_object_set_property(G_OBJECT(op), "separable", &gvalue);
			g_value_unset(&gvalue);
		}

		// precision
		jfieldID precisionFid = (*env)->GetFieldID(env, optionsCls, "precision", "Lcom/criteo/vips/enums/VipsPrecision;");
		jobject precision = (*env)->GetObjectField(env, options, precisionFid);
		if (precision != NULL) {
			jclass precisionCls = (*env)->GetObjectClass(env, precision);
			jfieldID precisionValueFid = (*env)->GetFieldID(env, precisionCls, "value", "I");
			jint precisionValue = (*env)->GetIntField(env, precision, precisionValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, precisionValue);
			g_object_set_property(G_OBJECT(op), "precision", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "gaussmat failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_gaussnoise(JNIEnv *env, jclass cls, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("gaussnoise");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// sigma
		jfieldID sigmaFid = (*env)->GetFieldID(env, optionsCls, "sigma", "Ljava/lang/Double;");
		jobject sigmaObjectValue = (*env)->GetObjectField(env, options, sigmaFid);
		if (sigmaObjectValue != NULL) {
			jdouble sigma = (*env)->CallDoubleMethod(env, sigmaObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, sigma);
			g_object_set_property(G_OBJECT(op), "sigma", &gvalue);
			g_value_unset(&gvalue);
		}

		// mean
		jfieldID meanFid = (*env)->GetFieldID(env, optionsCls, "mean", "Ljava/lang/Double;");
		jobject meanObjectValue = (*env)->GetObjectField(env, options, meanFid);
		if (meanObjectValue != NULL) {
			jdouble mean = (*env)->CallDoubleMethod(env, meanObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, mean);
			g_object_set_property(G_OBJECT(op), "mean", &gvalue);
			g_value_unset(&gvalue);
		}

		// seed
		jfieldID seedFid = (*env)->GetFieldID(env, optionsCls, "seed", "Ljava/lang/Integer;");
		jobject seedObjectValue = (*env)->GetObjectField(env, options, seedFid);
		if (seedObjectValue != NULL) {
			jint seed = (*env)->CallIntMethod(env, seedObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, seed);
			g_object_set_property(G_OBJECT(op), "seed", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "gaussnoise failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_getpoint(JNIEnv *env, jobject in, jint x, jint y)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("getpoint");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// x
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, x);
	g_object_set_property(G_OBJECT(op), "x", &gvalue);
	g_value_unset(&gvalue);

	// y
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, y);
	g_object_set_property(G_OBJECT(op), "y", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "getpoint failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out-array
	g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
	g_object_get_property(G_OBJECT(op), "out-array", &gvalue);
	jint outArrayLength = 0;
	jdouble *outArrayElements = vips_value_get_array_double(&gvalue, &outArrayLength);
	jdoubleArray outArrayArray = (*env)->NewDoubleArray(env, outArrayLength);
	(*env)->SetDoubleArrayRegion(env, outArrayArray, 0, outArrayLength, outArrayElements);
	(*env)->ReleaseDoubleArrayElements(env, outArrayArray, outArrayElements, JNI_COMMIT);
	jobject outArray = (*env)->NewObject(env, pixelPacketClass, pixelPacket_ctor_mid, outArrayArray);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return outArray;
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_gifLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("gifload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// n
		jfieldID nFid = (*env)->GetFieldID(env, optionsCls, "n", "Ljava/lang/Integer;");
		jobject nObjectValue = (*env)->GetObjectField(env, options, nFid);
		if (nObjectValue != NULL) {
			jint n = (*env)->CallIntMethod(env, nObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, n);
			g_object_set_property(G_OBJECT(op), "n", &gvalue);
			g_value_unset(&gvalue);
		}

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "gifload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_gifLoadBuffer(JNIEnv *env, jclass cls, jbyteArray buffer, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("gifload_buffer");

	// buffer
	if (buffer != NULL) {
		jint bufferLength = (*env)->GetArrayLength(env, buffer);
		size_t bufferSize = bufferLength * sizeof(jbyte);
		void *bufferData = vips_tracked_malloc(bufferSize);
		if (bufferData == NULL) {
			throwVipsException(env, "Failed to allocate memory for buffer");
		}
		(*env)->GetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
		g_value_init(&gvalue, VIPS_TYPE_BLOB);
		vips_value_set_blob_free(&gvalue, bufferData, bufferSize);
		g_object_set_property(G_OBJECT(op), "buffer", &gvalue);
		g_value_unset(&gvalue);
	
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// n
		jfieldID nFid = (*env)->GetFieldID(env, optionsCls, "n", "Ljava/lang/Integer;");
		jobject nObjectValue = (*env)->GetObjectField(env, options, nFid);
		if (nObjectValue != NULL) {
			jint n = (*env)->CallIntMethod(env, nObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, n);
			g_object_set_property(G_OBJECT(op), "n", &gvalue);
			g_value_unset(&gvalue);
		}

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "gifload_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_gifSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("gifsave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// dither
		jfieldID ditherFid = (*env)->GetFieldID(env, optionsCls, "dither", "Ljava/lang/Double;");
		jobject ditherObjectValue = (*env)->GetObjectField(env, options, ditherFid);
		if (ditherObjectValue != NULL) {
			jdouble dither = (*env)->CallDoubleMethod(env, ditherObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, dither);
			g_object_set_property(G_OBJECT(op), "dither", &gvalue);
			g_value_unset(&gvalue);
		}

		// effort
		jfieldID effortFid = (*env)->GetFieldID(env, optionsCls, "effort", "Ljava/lang/Integer;");
		jobject effortObjectValue = (*env)->GetObjectField(env, options, effortFid);
		if (effortObjectValue != NULL) {
			jint effort = (*env)->CallIntMethod(env, effortObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, effort);
			g_object_set_property(G_OBJECT(op), "effort", &gvalue);
			g_value_unset(&gvalue);
		}

		// bitdepth
		jfieldID bitdepthFid = (*env)->GetFieldID(env, optionsCls, "bitdepth", "Ljava/lang/Integer;");
		jobject bitdepthObjectValue = (*env)->GetObjectField(env, options, bitdepthFid);
		if (bitdepthObjectValue != NULL) {
			jint bitdepth = (*env)->CallIntMethod(env, bitdepthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, bitdepth);
			g_object_set_property(G_OBJECT(op), "bitdepth", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "gifsave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_AbstractVipsImage_gifSaveBuffer(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("gifsave_buffer");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// dither
		jfieldID ditherFid = (*env)->GetFieldID(env, optionsCls, "dither", "Ljava/lang/Double;");
		jobject ditherObjectValue = (*env)->GetObjectField(env, options, ditherFid);
		if (ditherObjectValue != NULL) {
			jdouble dither = (*env)->CallDoubleMethod(env, ditherObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, dither);
			g_object_set_property(G_OBJECT(op), "dither", &gvalue);
			g_value_unset(&gvalue);
		}

		// effort
		jfieldID effortFid = (*env)->GetFieldID(env, optionsCls, "effort", "Ljava/lang/Integer;");
		jobject effortObjectValue = (*env)->GetObjectField(env, options, effortFid);
		if (effortObjectValue != NULL) {
			jint effort = (*env)->CallIntMethod(env, effortObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, effort);
			g_object_set_property(G_OBJECT(op), "effort", &gvalue);
			g_value_unset(&gvalue);
		}

		// bitdepth
		jfieldID bitdepthFid = (*env)->GetFieldID(env, optionsCls, "bitdepth", "Ljava/lang/Integer;");
		jobject bitdepthObjectValue = (*env)->GetObjectField(env, options, bitdepthFid);
		if (bitdepthObjectValue != NULL) {
			jint bitdepth = (*env)->CallIntMethod(env, bitdepthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, bitdepth);
			g_object_set_property(G_OBJECT(op), "bitdepth", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "gifsave_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// buffer
	g_value_init(&gvalue, VIPS_TYPE_BLOB);
	g_object_get_property(G_OBJECT(op), "buffer", &gvalue);
	size_t bufferSize = 0;
	void *bufferData = vips_value_get_blob(&gvalue, &bufferSize);
	jint bufferLength = bufferSize / sizeof(jbyte);
	jbyteArray buffer = (*env)->NewByteArray(env, bufferLength);
	(*env)->SetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return buffer;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_globalbalance(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("globalbalance");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// gamma
		jfieldID gammaFid = (*env)->GetFieldID(env, optionsCls, "gamma", "Ljava/lang/Double;");
		jobject gammaObjectValue = (*env)->GetObjectField(env, options, gammaFid);
		if (gammaObjectValue != NULL) {
			jdouble gamma = (*env)->CallDoubleMethod(env, gammaObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, gamma);
			g_object_set_property(G_OBJECT(op), "gamma", &gvalue);
			g_value_unset(&gvalue);
		}

		// int-output
		jfieldID intOutputFid = (*env)->GetFieldID(env, optionsCls, "intOutput", "Ljava/lang/Boolean;");
		jobject intOutputObjectValue = (*env)->GetObjectField(env, options, intOutputFid);
		if (intOutputObjectValue != NULL) {
			jboolean intOutput = (*env)->CallBooleanMethod(env, intOutputObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, intOutput);
			g_object_set_property(G_OBJECT(op), "int-output", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "globalbalance failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_gravity(JNIEnv *env, jobject in, jobject direction, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("gravity");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// direction
	if (direction != NULL) {
		jclass directionCls = (*env)->GetObjectClass(env, direction);
		jfieldID directionValueFid = (*env)->GetFieldID(env, directionCls, "value", "I");
		jint directionValue = (*env)->GetIntField(env, direction, directionValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, directionValue);
		g_object_set_property(G_OBJECT(op), "direction", &gvalue);
		g_value_unset(&gvalue);
	}

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// extend
		jfieldID extendFid = (*env)->GetFieldID(env, optionsCls, "extend", "Lcom/criteo/vips/enums/VipsExtend;");
		jobject extend = (*env)->GetObjectField(env, options, extendFid);
		if (extend != NULL) {
			jclass extendCls = (*env)->GetObjectClass(env, extend);
			jfieldID extendValueFid = (*env)->GetFieldID(env, extendCls, "value", "I");
			jint extendValue = (*env)->GetIntField(env, extend, extendValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, extendValue);
			g_object_set_property(G_OBJECT(op), "extend", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "gravity failed");
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
Java_com_criteo_vips_AbstractVipsImage_grey(JNIEnv *env, jclass cls, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("grey");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "grey failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_grid(JNIEnv *env, jobject in, jint tileHeight, jint across, jint down)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("grid");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// tile-height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, tileHeight);
	g_object_set_property(G_OBJECT(op), "tile-height", &gvalue);
	g_value_unset(&gvalue);

	// across
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, across);
	g_object_set_property(G_OBJECT(op), "across", &gvalue);
	g_value_unset(&gvalue);

	// down
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, down);
	g_object_set_property(G_OBJECT(op), "down", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "grid failed");
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
Java_com_criteo_vips_AbstractVipsImage_heifLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("heifload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// n
		jfieldID nFid = (*env)->GetFieldID(env, optionsCls, "n", "Ljava/lang/Integer;");
		jobject nObjectValue = (*env)->GetObjectField(env, options, nFid);
		if (nObjectValue != NULL) {
			jint n = (*env)->CallIntMethod(env, nObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, n);
			g_object_set_property(G_OBJECT(op), "n", &gvalue);
			g_value_unset(&gvalue);
		}

		// thumbnail
		jfieldID thumbnailFid = (*env)->GetFieldID(env, optionsCls, "thumbnail", "Ljava/lang/Boolean;");
		jobject thumbnailObjectValue = (*env)->GetObjectField(env, options, thumbnailFid);
		if (thumbnailObjectValue != NULL) {
			jboolean thumbnail = (*env)->CallBooleanMethod(env, thumbnailObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, thumbnail);
			g_object_set_property(G_OBJECT(op), "thumbnail", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "heifload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_heifLoadBuffer(JNIEnv *env, jclass cls, jbyteArray buffer, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("heifload_buffer");

	// buffer
	if (buffer != NULL) {
		jint bufferLength = (*env)->GetArrayLength(env, buffer);
		size_t bufferSize = bufferLength * sizeof(jbyte);
		void *bufferData = vips_tracked_malloc(bufferSize);
		if (bufferData == NULL) {
			throwVipsException(env, "Failed to allocate memory for buffer");
		}
		(*env)->GetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
		g_value_init(&gvalue, VIPS_TYPE_BLOB);
		vips_value_set_blob_free(&gvalue, bufferData, bufferSize);
		g_object_set_property(G_OBJECT(op), "buffer", &gvalue);
		g_value_unset(&gvalue);
	
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// n
		jfieldID nFid = (*env)->GetFieldID(env, optionsCls, "n", "Ljava/lang/Integer;");
		jobject nObjectValue = (*env)->GetObjectField(env, options, nFid);
		if (nObjectValue != NULL) {
			jint n = (*env)->CallIntMethod(env, nObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, n);
			g_object_set_property(G_OBJECT(op), "n", &gvalue);
			g_value_unset(&gvalue);
		}

		// thumbnail
		jfieldID thumbnailFid = (*env)->GetFieldID(env, optionsCls, "thumbnail", "Ljava/lang/Boolean;");
		jobject thumbnailObjectValue = (*env)->GetObjectField(env, options, thumbnailFid);
		if (thumbnailObjectValue != NULL) {
			jboolean thumbnail = (*env)->CallBooleanMethod(env, thumbnailObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, thumbnail);
			g_object_set_property(G_OBJECT(op), "thumbnail", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "heifload_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_heifSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("heifsave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// lossless
		jfieldID losslessFid = (*env)->GetFieldID(env, optionsCls, "lossless", "Ljava/lang/Boolean;");
		jobject losslessObjectValue = (*env)->GetObjectField(env, options, losslessFid);
		if (losslessObjectValue != NULL) {
			jboolean lossless = (*env)->CallBooleanMethod(env, losslessObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, lossless);
			g_object_set_property(G_OBJECT(op), "lossless", &gvalue);
			g_value_unset(&gvalue);
		}

		// compression
		jfieldID compressionFid = (*env)->GetFieldID(env, optionsCls, "compression", "Lcom/criteo/vips/enums/VipsForeignHeifCompression;");
		jobject compression = (*env)->GetObjectField(env, options, compressionFid);
		if (compression != NULL) {
			jclass compressionCls = (*env)->GetObjectClass(env, compression);
			jfieldID compressionValueFid = (*env)->GetFieldID(env, compressionCls, "value", "I");
			jint compressionValue = (*env)->GetIntField(env, compression, compressionValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, compressionValue);
			g_object_set_property(G_OBJECT(op), "compression", &gvalue);
			g_value_unset(&gvalue);
		}

		// effort
		jfieldID effortFid = (*env)->GetFieldID(env, optionsCls, "effort", "Ljava/lang/Integer;");
		jobject effortObjectValue = (*env)->GetObjectField(env, options, effortFid);
		if (effortObjectValue != NULL) {
			jint effort = (*env)->CallIntMethod(env, effortObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, effort);
			g_object_set_property(G_OBJECT(op), "effort", &gvalue);
			g_value_unset(&gvalue);
		}

		// subsample-mode
		jfieldID subsampleModeFid = (*env)->GetFieldID(env, optionsCls, "subsampleMode", "Lcom/criteo/vips/enums/VipsForeignSubsample;");
		jobject subsampleMode = (*env)->GetObjectField(env, options, subsampleModeFid);
		if (subsampleMode != NULL) {
			jclass subsampleModeCls = (*env)->GetObjectClass(env, subsampleMode);
			jfieldID subsampleModeValueFid = (*env)->GetFieldID(env, subsampleModeCls, "value", "I");
			jint subsampleModeValue = (*env)->GetIntField(env, subsampleMode, subsampleModeValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, subsampleModeValue);
			g_object_set_property(G_OBJECT(op), "subsample-mode", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "heifsave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_AbstractVipsImage_heifSaveBuffer(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("heifsave_buffer");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// lossless
		jfieldID losslessFid = (*env)->GetFieldID(env, optionsCls, "lossless", "Ljava/lang/Boolean;");
		jobject losslessObjectValue = (*env)->GetObjectField(env, options, losslessFid);
		if (losslessObjectValue != NULL) {
			jboolean lossless = (*env)->CallBooleanMethod(env, losslessObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, lossless);
			g_object_set_property(G_OBJECT(op), "lossless", &gvalue);
			g_value_unset(&gvalue);
		}

		// compression
		jfieldID compressionFid = (*env)->GetFieldID(env, optionsCls, "compression", "Lcom/criteo/vips/enums/VipsForeignHeifCompression;");
		jobject compression = (*env)->GetObjectField(env, options, compressionFid);
		if (compression != NULL) {
			jclass compressionCls = (*env)->GetObjectClass(env, compression);
			jfieldID compressionValueFid = (*env)->GetFieldID(env, compressionCls, "value", "I");
			jint compressionValue = (*env)->GetIntField(env, compression, compressionValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, compressionValue);
			g_object_set_property(G_OBJECT(op), "compression", &gvalue);
			g_value_unset(&gvalue);
		}

		// effort
		jfieldID effortFid = (*env)->GetFieldID(env, optionsCls, "effort", "Ljava/lang/Integer;");
		jobject effortObjectValue = (*env)->GetObjectField(env, options, effortFid);
		if (effortObjectValue != NULL) {
			jint effort = (*env)->CallIntMethod(env, effortObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, effort);
			g_object_set_property(G_OBJECT(op), "effort", &gvalue);
			g_value_unset(&gvalue);
		}

		// subsample-mode
		jfieldID subsampleModeFid = (*env)->GetFieldID(env, optionsCls, "subsampleMode", "Lcom/criteo/vips/enums/VipsForeignSubsample;");
		jobject subsampleMode = (*env)->GetObjectField(env, options, subsampleModeFid);
		if (subsampleMode != NULL) {
			jclass subsampleModeCls = (*env)->GetObjectClass(env, subsampleMode);
			jfieldID subsampleModeValueFid = (*env)->GetFieldID(env, subsampleModeCls, "value", "I");
			jint subsampleModeValue = (*env)->GetIntField(env, subsampleMode, subsampleModeValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, subsampleModeValue);
			g_object_set_property(G_OBJECT(op), "subsample-mode", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "heifsave_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// buffer
	g_value_init(&gvalue, VIPS_TYPE_BLOB);
	g_object_get_property(G_OBJECT(op), "buffer", &gvalue);
	size_t bufferSize = 0;
	void *bufferData = vips_value_get_blob(&gvalue, &bufferSize);
	jint bufferLength = bufferSize / sizeof(jbyte);
	jbyteArray buffer = (*env)->NewByteArray(env, bufferLength);
	(*env)->SetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return buffer;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_histCum(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("hist_cum");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "hist_cum failed");
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

JNIEXPORT jdouble JNICALL
Java_com_criteo_vips_AbstractVipsImage_histEntropy(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("hist_entropy");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "hist_entropy failed");
		return 0;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	jdouble out = g_value_get_double(&gvalue);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return out;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_histEqual(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("hist_equal");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// band
		jfieldID bandFid = (*env)->GetFieldID(env, optionsCls, "band", "Ljava/lang/Integer;");
		jobject bandObjectValue = (*env)->GetObjectField(env, options, bandFid);
		if (bandObjectValue != NULL) {
			jint band = (*env)->CallIntMethod(env, bandObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, band);
			g_object_set_property(G_OBJECT(op), "band", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "hist_equal failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_histFind(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("hist_find");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// band
		jfieldID bandFid = (*env)->GetFieldID(env, optionsCls, "band", "Ljava/lang/Integer;");
		jobject bandObjectValue = (*env)->GetObjectField(env, options, bandFid);
		if (bandObjectValue != NULL) {
			jint band = (*env)->CallIntMethod(env, bandObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, band);
			g_object_set_property(G_OBJECT(op), "band", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "hist_find failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_histFindIndexed(JNIEnv *env, jobject in, jobject index, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("hist_find_indexed");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// index
	if (index != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, index, handle_fid));
		g_object_set_property(G_OBJECT(op), "index", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// combine
		jfieldID combineFid = (*env)->GetFieldID(env, optionsCls, "combine", "Lcom/criteo/vips/enums/VipsCombine;");
		jobject combine = (*env)->GetObjectField(env, options, combineFid);
		if (combine != NULL) {
			jclass combineCls = (*env)->GetObjectClass(env, combine);
			jfieldID combineValueFid = (*env)->GetFieldID(env, combineCls, "value", "I");
			jint combineValue = (*env)->GetIntField(env, combine, combineValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, combineValue);
			g_object_set_property(G_OBJECT(op), "combine", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "hist_find_indexed failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_histFindNdim(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("hist_find_ndim");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// bins
		jfieldID binsFid = (*env)->GetFieldID(env, optionsCls, "bins", "Ljava/lang/Integer;");
		jobject binsObjectValue = (*env)->GetObjectField(env, options, binsFid);
		if (binsObjectValue != NULL) {
			jint bins = (*env)->CallIntMethod(env, binsObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, bins);
			g_object_set_property(G_OBJECT(op), "bins", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "hist_find_ndim failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_histLocal(JNIEnv *env, jobject in, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("hist_local");

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

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// max-slope
		jfieldID maxSlopeFid = (*env)->GetFieldID(env, optionsCls, "maxSlope", "Ljava/lang/Integer;");
		jobject maxSlopeObjectValue = (*env)->GetObjectField(env, options, maxSlopeFid);
		if (maxSlopeObjectValue != NULL) {
			jint maxSlope = (*env)->CallIntMethod(env, maxSlopeObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, maxSlope);
			g_object_set_property(G_OBJECT(op), "max-slope", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "hist_local failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_histMatch(JNIEnv *env, jobject in, jobject ref)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("hist_match");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// ref
	if (ref != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, ref, handle_fid));
		g_object_set_property(G_OBJECT(op), "ref", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "hist_match failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_histNorm(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("hist_norm");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "hist_norm failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_histPlot(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("hist_plot");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "hist_plot failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_houghCircle(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("hough_circle");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// scale
		jfieldID scaleFid = (*env)->GetFieldID(env, optionsCls, "scale", "Ljava/lang/Integer;");
		jobject scaleObjectValue = (*env)->GetObjectField(env, options, scaleFid);
		if (scaleObjectValue != NULL) {
			jint scale = (*env)->CallIntMethod(env, scaleObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, scale);
			g_object_set_property(G_OBJECT(op), "scale", &gvalue);
			g_value_unset(&gvalue);
		}

		// min-radius
		jfieldID minRadiusFid = (*env)->GetFieldID(env, optionsCls, "minRadius", "Ljava/lang/Integer;");
		jobject minRadiusObjectValue = (*env)->GetObjectField(env, options, minRadiusFid);
		if (minRadiusObjectValue != NULL) {
			jint minRadius = (*env)->CallIntMethod(env, minRadiusObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, minRadius);
			g_object_set_property(G_OBJECT(op), "min-radius", &gvalue);
			g_value_unset(&gvalue);
		}

		// max-radius
		jfieldID maxRadiusFid = (*env)->GetFieldID(env, optionsCls, "maxRadius", "Ljava/lang/Integer;");
		jobject maxRadiusObjectValue = (*env)->GetObjectField(env, options, maxRadiusFid);
		if (maxRadiusObjectValue != NULL) {
			jint maxRadius = (*env)->CallIntMethod(env, maxRadiusObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, maxRadius);
			g_object_set_property(G_OBJECT(op), "max-radius", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "hough_circle failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_houghLine(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("hough_line");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// width
		jfieldID widthFid = (*env)->GetFieldID(env, optionsCls, "width", "Ljava/lang/Integer;");
		jobject widthObjectValue = (*env)->GetObjectField(env, options, widthFid);
		if (widthObjectValue != NULL) {
			jint width = (*env)->CallIntMethod(env, widthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, width);
			g_object_set_property(G_OBJECT(op), "width", &gvalue);
			g_value_unset(&gvalue);
		}

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

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "hough_line failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_hSV2sRGB(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("HSV2sRGB");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "HSV2sRGB failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_iccExport(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("icc_export");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// pcs
		jfieldID pcsFid = (*env)->GetFieldID(env, optionsCls, "pcs", "Lcom/criteo/vips/enums/VipsPCS;");
		jobject pcs = (*env)->GetObjectField(env, options, pcsFid);
		if (pcs != NULL) {
			jclass pcsCls = (*env)->GetObjectClass(env, pcs);
			jfieldID pcsValueFid = (*env)->GetFieldID(env, pcsCls, "value", "I");
			jint pcsValue = (*env)->GetIntField(env, pcs, pcsValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pcsValue);
			g_object_set_property(G_OBJECT(op), "pcs", &gvalue);
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

		// black-point-compensation
		jfieldID blackPointCompensationFid = (*env)->GetFieldID(env, optionsCls, "blackPointCompensation", "Ljava/lang/Boolean;");
		jobject blackPointCompensationObjectValue = (*env)->GetObjectField(env, options, blackPointCompensationFid);
		if (blackPointCompensationObjectValue != NULL) {
			jboolean blackPointCompensation = (*env)->CallBooleanMethod(env, blackPointCompensationObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, blackPointCompensation);
			g_object_set_property(G_OBJECT(op), "black-point-compensation", &gvalue);
			g_value_unset(&gvalue);
		}

		// output-profile
		jfieldID outputProfileFid = (*env)->GetFieldID(env, optionsCls, "outputProfile", "Ljava/lang/String;");
		jstring outputProfile = (jstring) (*env)->GetObjectField(env, options, outputProfileFid);
		if (outputProfile != NULL) {
			const char *outputProfileChars = (*env)->GetStringUTFChars(env, outputProfile, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, outputProfileChars);
			(*env)->ReleaseStringUTFChars(env, outputProfile, outputProfileChars);
			g_object_set_property(G_OBJECT(op), "output-profile", &gvalue);
			g_value_unset(&gvalue);
		}

		// depth
		jfieldID depthFid = (*env)->GetFieldID(env, optionsCls, "depth", "Ljava/lang/Integer;");
		jobject depthObjectValue = (*env)->GetObjectField(env, options, depthFid);
		if (depthObjectValue != NULL) {
			jint depth = (*env)->CallIntMethod(env, depthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, depth);
			g_object_set_property(G_OBJECT(op), "depth", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "icc_export failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_iccImport(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("icc_import");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// pcs
		jfieldID pcsFid = (*env)->GetFieldID(env, optionsCls, "pcs", "Lcom/criteo/vips/enums/VipsPCS;");
		jobject pcs = (*env)->GetObjectField(env, options, pcsFid);
		if (pcs != NULL) {
			jclass pcsCls = (*env)->GetObjectClass(env, pcs);
			jfieldID pcsValueFid = (*env)->GetFieldID(env, pcsCls, "value", "I");
			jint pcsValue = (*env)->GetIntField(env, pcs, pcsValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pcsValue);
			g_object_set_property(G_OBJECT(op), "pcs", &gvalue);
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

		// black-point-compensation
		jfieldID blackPointCompensationFid = (*env)->GetFieldID(env, optionsCls, "blackPointCompensation", "Ljava/lang/Boolean;");
		jobject blackPointCompensationObjectValue = (*env)->GetObjectField(env, options, blackPointCompensationFid);
		if (blackPointCompensationObjectValue != NULL) {
			jboolean blackPointCompensation = (*env)->CallBooleanMethod(env, blackPointCompensationObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, blackPointCompensation);
			g_object_set_property(G_OBJECT(op), "black-point-compensation", &gvalue);
			g_value_unset(&gvalue);
		}

		// embedded
		jfieldID embeddedFid = (*env)->GetFieldID(env, optionsCls, "embedded", "Ljava/lang/Boolean;");
		jobject embeddedObjectValue = (*env)->GetObjectField(env, options, embeddedFid);
		if (embeddedObjectValue != NULL) {
			jboolean embedded = (*env)->CallBooleanMethod(env, embeddedObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, embedded);
			g_object_set_property(G_OBJECT(op), "embedded", &gvalue);
			g_value_unset(&gvalue);
		}

		// input-profile
		jfieldID inputProfileFid = (*env)->GetFieldID(env, optionsCls, "inputProfile", "Ljava/lang/String;");
		jstring inputProfile = (jstring) (*env)->GetObjectField(env, options, inputProfileFid);
		if (inputProfile != NULL) {
			const char *inputProfileChars = (*env)->GetStringUTFChars(env, inputProfile, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, inputProfileChars);
			(*env)->ReleaseStringUTFChars(env, inputProfile, inputProfileChars);
			g_object_set_property(G_OBJECT(op), "input-profile", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "icc_import failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_iccTransform(JNIEnv *env, jobject in, jstring outputProfile, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("icc_transform");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// output-profile
	if (outputProfile != NULL) {
		const char *outputProfileChars = (*env)->GetStringUTFChars(env, outputProfile, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, outputProfileChars);
		(*env)->ReleaseStringUTFChars(env, outputProfile, outputProfileChars);
		g_object_set_property(G_OBJECT(op), "output-profile", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// pcs
		jfieldID pcsFid = (*env)->GetFieldID(env, optionsCls, "pcs", "Lcom/criteo/vips/enums/VipsPCS;");
		jobject pcs = (*env)->GetObjectField(env, options, pcsFid);
		if (pcs != NULL) {
			jclass pcsCls = (*env)->GetObjectClass(env, pcs);
			jfieldID pcsValueFid = (*env)->GetFieldID(env, pcsCls, "value", "I");
			jint pcsValue = (*env)->GetIntField(env, pcs, pcsValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pcsValue);
			g_object_set_property(G_OBJECT(op), "pcs", &gvalue);
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

		// black-point-compensation
		jfieldID blackPointCompensationFid = (*env)->GetFieldID(env, optionsCls, "blackPointCompensation", "Ljava/lang/Boolean;");
		jobject blackPointCompensationObjectValue = (*env)->GetObjectField(env, options, blackPointCompensationFid);
		if (blackPointCompensationObjectValue != NULL) {
			jboolean blackPointCompensation = (*env)->CallBooleanMethod(env, blackPointCompensationObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, blackPointCompensation);
			g_object_set_property(G_OBJECT(op), "black-point-compensation", &gvalue);
			g_value_unset(&gvalue);
		}

		// embedded
		jfieldID embeddedFid = (*env)->GetFieldID(env, optionsCls, "embedded", "Ljava/lang/Boolean;");
		jobject embeddedObjectValue = (*env)->GetObjectField(env, options, embeddedFid);
		if (embeddedObjectValue != NULL) {
			jboolean embedded = (*env)->CallBooleanMethod(env, embeddedObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, embedded);
			g_object_set_property(G_OBJECT(op), "embedded", &gvalue);
			g_value_unset(&gvalue);
		}

		// input-profile
		jfieldID inputProfileFid = (*env)->GetFieldID(env, optionsCls, "inputProfile", "Ljava/lang/String;");
		jstring inputProfile = (jstring) (*env)->GetObjectField(env, options, inputProfileFid);
		if (inputProfile != NULL) {
			const char *inputProfileChars = (*env)->GetStringUTFChars(env, inputProfile, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, inputProfileChars);
			(*env)->ReleaseStringUTFChars(env, inputProfile, inputProfileChars);
			g_object_set_property(G_OBJECT(op), "input-profile", &gvalue);
			g_value_unset(&gvalue);
		}

		// depth
		jfieldID depthFid = (*env)->GetFieldID(env, optionsCls, "depth", "Ljava/lang/Integer;");
		jobject depthObjectValue = (*env)->GetObjectField(env, options, depthFid);
		if (depthObjectValue != NULL) {
			jint depth = (*env)->CallIntMethod(env, depthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, depth);
			g_object_set_property(G_OBJECT(op), "depth", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "icc_transform failed");
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
Java_com_criteo_vips_AbstractVipsImage_identity(JNIEnv *env, jclass cls, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("identity");

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// bands
		jfieldID bandsFid = (*env)->GetFieldID(env, optionsCls, "bands", "Ljava/lang/Integer;");
		jobject bandsObjectValue = (*env)->GetObjectField(env, options, bandsFid);
		if (bandsObjectValue != NULL) {
			jint bands = (*env)->CallIntMethod(env, bandsObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, bands);
			g_object_set_property(G_OBJECT(op), "bands", &gvalue);
			g_value_unset(&gvalue);
		}

		// ushort
		jfieldID ushortFid = (*env)->GetFieldID(env, optionsCls, "ushort", "Ljava/lang/Boolean;");
		jobject ushortObjectValue = (*env)->GetObjectField(env, options, ushortFid);
		if (ushortObjectValue != NULL) {
			jboolean ushort = (*env)->CallBooleanMethod(env, ushortObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, ushort);
			g_object_set_property(G_OBJECT(op), "ushort", &gvalue);
			g_value_unset(&gvalue);
		}

		// size
		jfieldID sizeFid = (*env)->GetFieldID(env, optionsCls, "size", "Ljava/lang/Integer;");
		jobject sizeObjectValue = (*env)->GetObjectField(env, options, sizeFid);
		if (sizeObjectValue != NULL) {
			jint size = (*env)->CallIntMethod(env, sizeObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, size);
			g_object_set_property(G_OBJECT(op), "size", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "identity failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_ifthenelse(JNIEnv *env, jobject cond, jobject in1, jobject in2, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("ifthenelse");

	// cond
	if (cond != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, cond, handle_fid));
		g_object_set_property(G_OBJECT(op), "cond", &gvalue);
		g_value_unset(&gvalue);
	}

	// in1
	if (in1 != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in1, handle_fid));
		g_object_set_property(G_OBJECT(op), "in1", &gvalue);
		g_value_unset(&gvalue);
	}

	// in2
	if (in2 != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in2, handle_fid));
		g_object_set_property(G_OBJECT(op), "in2", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// blend
		jfieldID blendFid = (*env)->GetFieldID(env, optionsCls, "blend", "Ljava/lang/Boolean;");
		jobject blendObjectValue = (*env)->GetObjectField(env, options, blendFid);
		if (blendObjectValue != NULL) {
			jboolean blend = (*env)->CallBooleanMethod(env, blendObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, blend);
			g_object_set_property(G_OBJECT(op), "blend", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "ifthenelse failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, cond, handle_fid));
	(*env)->SetLongField(env, cond, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_insert(JNIEnv *env, jobject main, jobject sub, jint x, jint y, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("insert");

	// main
	if (main != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, main, handle_fid));
		g_object_set_property(G_OBJECT(op), "main", &gvalue);
		g_value_unset(&gvalue);
	}

	// sub
	if (sub != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, sub, handle_fid));
		g_object_set_property(G_OBJECT(op), "sub", &gvalue);
		g_value_unset(&gvalue);
	}

	// x
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, x);
	g_object_set_property(G_OBJECT(op), "x", &gvalue);
	g_value_unset(&gvalue);

	// y
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, y);
	g_object_set_property(G_OBJECT(op), "y", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// expand
		jfieldID expandFid = (*env)->GetFieldID(env, optionsCls, "expand", "Ljava/lang/Boolean;");
		jobject expandObjectValue = (*env)->GetObjectField(env, options, expandFid);
		if (expandObjectValue != NULL) {
			jboolean expand = (*env)->CallBooleanMethod(env, expandObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, expand);
			g_object_set_property(G_OBJECT(op), "expand", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "insert failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, main, handle_fid));
	(*env)->SetLongField(env, main, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_invert(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("invert");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "invert failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_invertlut(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("invertlut");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// size
		jfieldID sizeFid = (*env)->GetFieldID(env, optionsCls, "size", "Ljava/lang/Integer;");
		jobject sizeObjectValue = (*env)->GetObjectField(env, options, sizeFid);
		if (sizeObjectValue != NULL) {
			jint size = (*env)->CallIntMethod(env, sizeObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, size);
			g_object_set_property(G_OBJECT(op), "size", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "invertlut failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_invfft(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("invfft");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// real
		jfieldID realFid = (*env)->GetFieldID(env, optionsCls, "real", "Ljava/lang/Boolean;");
		jobject realObjectValue = (*env)->GetObjectField(env, options, realFid);
		if (realObjectValue != NULL) {
			jboolean real = (*env)->CallBooleanMethod(env, realObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, real);
			g_object_set_property(G_OBJECT(op), "real", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "invfft failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_join(JNIEnv *env, jobject in1, jobject in2, jobject direction, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("join");

	// in1
	if (in1 != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in1, handle_fid));
		g_object_set_property(G_OBJECT(op), "in1", &gvalue);
		g_value_unset(&gvalue);
	}

	// in2
	if (in2 != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in2, handle_fid));
		g_object_set_property(G_OBJECT(op), "in2", &gvalue);
		g_value_unset(&gvalue);
	}

	// direction
	if (direction != NULL) {
		jclass directionCls = (*env)->GetObjectClass(env, direction);
		jfieldID directionValueFid = (*env)->GetFieldID(env, directionCls, "value", "I");
		jint directionValue = (*env)->GetIntField(env, direction, directionValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, directionValue);
		g_object_set_property(G_OBJECT(op), "direction", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// expand
		jfieldID expandFid = (*env)->GetFieldID(env, optionsCls, "expand", "Ljava/lang/Boolean;");
		jobject expandObjectValue = (*env)->GetObjectField(env, options, expandFid);
		if (expandObjectValue != NULL) {
			jboolean expand = (*env)->CallBooleanMethod(env, expandObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, expand);
			g_object_set_property(G_OBJECT(op), "expand", &gvalue);
			g_value_unset(&gvalue);
		}

		// shim
		jfieldID shimFid = (*env)->GetFieldID(env, optionsCls, "shim", "Ljava/lang/Integer;");
		jobject shimObjectValue = (*env)->GetObjectField(env, options, shimFid);
		if (shimObjectValue != NULL) {
			jint shim = (*env)->CallIntMethod(env, shimObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, shim);
			g_object_set_property(G_OBJECT(op), "shim", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// align
		jfieldID alignFid = (*env)->GetFieldID(env, optionsCls, "align", "Lcom/criteo/vips/enums/VipsAlign;");
		jobject align = (*env)->GetObjectField(env, options, alignFid);
		if (align != NULL) {
			jclass alignCls = (*env)->GetObjectClass(env, align);
			jfieldID alignValueFid = (*env)->GetFieldID(env, alignCls, "value", "I");
			jint alignValue = (*env)->GetIntField(env, align, alignValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, alignValue);
			g_object_set_property(G_OBJECT(op), "align", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "join failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, in1, handle_fid));
	(*env)->SetLongField(env, in1, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_jp2kLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("jp2kload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "jp2kload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_jp2kLoadBuffer(JNIEnv *env, jclass cls, jbyteArray buffer, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("jp2kload_buffer");

	// buffer
	if (buffer != NULL) {
		jint bufferLength = (*env)->GetArrayLength(env, buffer);
		size_t bufferSize = bufferLength * sizeof(jbyte);
		void *bufferData = vips_tracked_malloc(bufferSize);
		if (bufferData == NULL) {
			throwVipsException(env, "Failed to allocate memory for buffer");
		}
		(*env)->GetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
		g_value_init(&gvalue, VIPS_TYPE_BLOB);
		vips_value_set_blob_free(&gvalue, bufferData, bufferSize);
		g_object_set_property(G_OBJECT(op), "buffer", &gvalue);
		g_value_unset(&gvalue);
	
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "jp2kload_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_jp2kSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("jp2ksave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// tile-width
		jfieldID tileWidthFid = (*env)->GetFieldID(env, optionsCls, "tileWidth", "Ljava/lang/Integer;");
		jobject tileWidthObjectValue = (*env)->GetObjectField(env, options, tileWidthFid);
		if (tileWidthObjectValue != NULL) {
			jint tileWidth = (*env)->CallIntMethod(env, tileWidthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileWidth);
			g_object_set_property(G_OBJECT(op), "tile-width", &gvalue);
			g_value_unset(&gvalue);
		}

		// tile-height
		jfieldID tileHeightFid = (*env)->GetFieldID(env, optionsCls, "tileHeight", "Ljava/lang/Integer;");
		jobject tileHeightObjectValue = (*env)->GetObjectField(env, options, tileHeightFid);
		if (tileHeightObjectValue != NULL) {
			jint tileHeight = (*env)->CallIntMethod(env, tileHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileHeight);
			g_object_set_property(G_OBJECT(op), "tile-height", &gvalue);
			g_value_unset(&gvalue);
		}

		// lossless
		jfieldID losslessFid = (*env)->GetFieldID(env, optionsCls, "lossless", "Ljava/lang/Boolean;");
		jobject losslessObjectValue = (*env)->GetObjectField(env, options, losslessFid);
		if (losslessObjectValue != NULL) {
			jboolean lossless = (*env)->CallBooleanMethod(env, losslessObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, lossless);
			g_object_set_property(G_OBJECT(op), "lossless", &gvalue);
			g_value_unset(&gvalue);
		}

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// subsample-mode
		jfieldID subsampleModeFid = (*env)->GetFieldID(env, optionsCls, "subsampleMode", "Lcom/criteo/vips/enums/VipsForeignSubsample;");
		jobject subsampleMode = (*env)->GetObjectField(env, options, subsampleModeFid);
		if (subsampleMode != NULL) {
			jclass subsampleModeCls = (*env)->GetObjectClass(env, subsampleMode);
			jfieldID subsampleModeValueFid = (*env)->GetFieldID(env, subsampleModeCls, "value", "I");
			jint subsampleModeValue = (*env)->GetIntField(env, subsampleMode, subsampleModeValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, subsampleModeValue);
			g_object_set_property(G_OBJECT(op), "subsample-mode", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "jp2ksave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_AbstractVipsImage_jp2kSaveBuffer(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("jp2ksave_buffer");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// tile-width
		jfieldID tileWidthFid = (*env)->GetFieldID(env, optionsCls, "tileWidth", "Ljava/lang/Integer;");
		jobject tileWidthObjectValue = (*env)->GetObjectField(env, options, tileWidthFid);
		if (tileWidthObjectValue != NULL) {
			jint tileWidth = (*env)->CallIntMethod(env, tileWidthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileWidth);
			g_object_set_property(G_OBJECT(op), "tile-width", &gvalue);
			g_value_unset(&gvalue);
		}

		// tile-height
		jfieldID tileHeightFid = (*env)->GetFieldID(env, optionsCls, "tileHeight", "Ljava/lang/Integer;");
		jobject tileHeightObjectValue = (*env)->GetObjectField(env, options, tileHeightFid);
		if (tileHeightObjectValue != NULL) {
			jint tileHeight = (*env)->CallIntMethod(env, tileHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileHeight);
			g_object_set_property(G_OBJECT(op), "tile-height", &gvalue);
			g_value_unset(&gvalue);
		}

		// lossless
		jfieldID losslessFid = (*env)->GetFieldID(env, optionsCls, "lossless", "Ljava/lang/Boolean;");
		jobject losslessObjectValue = (*env)->GetObjectField(env, options, losslessFid);
		if (losslessObjectValue != NULL) {
			jboolean lossless = (*env)->CallBooleanMethod(env, losslessObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, lossless);
			g_object_set_property(G_OBJECT(op), "lossless", &gvalue);
			g_value_unset(&gvalue);
		}

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// subsample-mode
		jfieldID subsampleModeFid = (*env)->GetFieldID(env, optionsCls, "subsampleMode", "Lcom/criteo/vips/enums/VipsForeignSubsample;");
		jobject subsampleMode = (*env)->GetObjectField(env, options, subsampleModeFid);
		if (subsampleMode != NULL) {
			jclass subsampleModeCls = (*env)->GetObjectClass(env, subsampleMode);
			jfieldID subsampleModeValueFid = (*env)->GetFieldID(env, subsampleModeCls, "value", "I");
			jint subsampleModeValue = (*env)->GetIntField(env, subsampleMode, subsampleModeValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, subsampleModeValue);
			g_object_set_property(G_OBJECT(op), "subsample-mode", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "jp2ksave_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// buffer
	g_value_init(&gvalue, VIPS_TYPE_BLOB);
	g_object_get_property(G_OBJECT(op), "buffer", &gvalue);
	size_t bufferSize = 0;
	void *bufferData = vips_value_get_blob(&gvalue, &bufferSize);
	jint bufferLength = bufferSize / sizeof(jbyte);
	jbyteArray buffer = (*env)->NewByteArray(env, bufferLength);
	(*env)->SetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return buffer;
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_jpegLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("jpegload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// shrink
		jfieldID shrinkFid = (*env)->GetFieldID(env, optionsCls, "shrink", "Ljava/lang/Integer;");
		jobject shrinkObjectValue = (*env)->GetObjectField(env, options, shrinkFid);
		if (shrinkObjectValue != NULL) {
			jint shrink = (*env)->CallIntMethod(env, shrinkObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, shrink);
			g_object_set_property(G_OBJECT(op), "shrink", &gvalue);
			g_value_unset(&gvalue);
		}

		// autorotate
		jfieldID autorotateFid = (*env)->GetFieldID(env, optionsCls, "autorotate", "Ljava/lang/Boolean;");
		jobject autorotateObjectValue = (*env)->GetObjectField(env, options, autorotateFid);
		if (autorotateObjectValue != NULL) {
			jboolean autorotate = (*env)->CallBooleanMethod(env, autorotateObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, autorotate);
			g_object_set_property(G_OBJECT(op), "autorotate", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "jpegload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_jpegLoadBuffer(JNIEnv *env, jclass cls, jbyteArray buffer, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("jpegload_buffer");

	// buffer
	if (buffer != NULL) {
		jint bufferLength = (*env)->GetArrayLength(env, buffer);
		size_t bufferSize = bufferLength * sizeof(jbyte);
		void *bufferData = vips_tracked_malloc(bufferSize);
		if (bufferData == NULL) {
			throwVipsException(env, "Failed to allocate memory for buffer");
		}
		(*env)->GetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
		g_value_init(&gvalue, VIPS_TYPE_BLOB);
		vips_value_set_blob_free(&gvalue, bufferData, bufferSize);
		g_object_set_property(G_OBJECT(op), "buffer", &gvalue);
		g_value_unset(&gvalue);
	
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// shrink
		jfieldID shrinkFid = (*env)->GetFieldID(env, optionsCls, "shrink", "Ljava/lang/Integer;");
		jobject shrinkObjectValue = (*env)->GetObjectField(env, options, shrinkFid);
		if (shrinkObjectValue != NULL) {
			jint shrink = (*env)->CallIntMethod(env, shrinkObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, shrink);
			g_object_set_property(G_OBJECT(op), "shrink", &gvalue);
			g_value_unset(&gvalue);
		}

		// autorotate
		jfieldID autorotateFid = (*env)->GetFieldID(env, optionsCls, "autorotate", "Ljava/lang/Boolean;");
		jobject autorotateObjectValue = (*env)->GetObjectField(env, options, autorotateFid);
		if (autorotateObjectValue != NULL) {
			jboolean autorotate = (*env)->CallBooleanMethod(env, autorotateObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, autorotate);
			g_object_set_property(G_OBJECT(op), "autorotate", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "jpegload_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_jpegSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("jpegsave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// profile
		jfieldID profileFid = (*env)->GetFieldID(env, optionsCls, "profile", "Ljava/lang/String;");
		jstring profile = (jstring) (*env)->GetObjectField(env, options, profileFid);
		if (profile != NULL) {
			const char *profileChars = (*env)->GetStringUTFChars(env, profile, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, profileChars);
			(*env)->ReleaseStringUTFChars(env, profile, profileChars);
			g_object_set_property(G_OBJECT(op), "profile", &gvalue);
			g_value_unset(&gvalue);
		}

		// optimize-coding
		jfieldID optimizeCodingFid = (*env)->GetFieldID(env, optionsCls, "optimizeCoding", "Ljava/lang/Boolean;");
		jobject optimizeCodingObjectValue = (*env)->GetObjectField(env, options, optimizeCodingFid);
		if (optimizeCodingObjectValue != NULL) {
			jboolean optimizeCoding = (*env)->CallBooleanMethod(env, optimizeCodingObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optimizeCoding);
			g_object_set_property(G_OBJECT(op), "optimize-coding", &gvalue);
			g_value_unset(&gvalue);
		}

		// interlace
		jfieldID interlaceFid = (*env)->GetFieldID(env, optionsCls, "interlace", "Ljava/lang/Boolean;");
		jobject interlaceObjectValue = (*env)->GetObjectField(env, options, interlaceFid);
		if (interlaceObjectValue != NULL) {
			jboolean interlace = (*env)->CallBooleanMethod(env, interlaceObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, interlace);
			g_object_set_property(G_OBJECT(op), "interlace", &gvalue);
			g_value_unset(&gvalue);
		}

		// trellis-quant
		jfieldID trellisQuantFid = (*env)->GetFieldID(env, optionsCls, "trellisQuant", "Ljava/lang/Boolean;");
		jobject trellisQuantObjectValue = (*env)->GetObjectField(env, options, trellisQuantFid);
		if (trellisQuantObjectValue != NULL) {
			jboolean trellisQuant = (*env)->CallBooleanMethod(env, trellisQuantObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, trellisQuant);
			g_object_set_property(G_OBJECT(op), "trellis-quant", &gvalue);
			g_value_unset(&gvalue);
		}

		// overshoot-deringing
		jfieldID overshootDeringingFid = (*env)->GetFieldID(env, optionsCls, "overshootDeringing", "Ljava/lang/Boolean;");
		jobject overshootDeringingObjectValue = (*env)->GetObjectField(env, options, overshootDeringingFid);
		if (overshootDeringingObjectValue != NULL) {
			jboolean overshootDeringing = (*env)->CallBooleanMethod(env, overshootDeringingObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, overshootDeringing);
			g_object_set_property(G_OBJECT(op), "overshoot-deringing", &gvalue);
			g_value_unset(&gvalue);
		}

		// optimize-scans
		jfieldID optimizeScansFid = (*env)->GetFieldID(env, optionsCls, "optimizeScans", "Ljava/lang/Boolean;");
		jobject optimizeScansObjectValue = (*env)->GetObjectField(env, options, optimizeScansFid);
		if (optimizeScansObjectValue != NULL) {
			jboolean optimizeScans = (*env)->CallBooleanMethod(env, optimizeScansObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optimizeScans);
			g_object_set_property(G_OBJECT(op), "optimize-scans", &gvalue);
			g_value_unset(&gvalue);
		}

		// quant-table
		jfieldID quantTableFid = (*env)->GetFieldID(env, optionsCls, "quantTable", "Ljava/lang/Integer;");
		jobject quantTableObjectValue = (*env)->GetObjectField(env, options, quantTableFid);
		if (quantTableObjectValue != NULL) {
			jint quantTable = (*env)->CallIntMethod(env, quantTableObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, quantTable);
			g_object_set_property(G_OBJECT(op), "quant-table", &gvalue);
			g_value_unset(&gvalue);
		}

		// subsample-mode
		jfieldID subsampleModeFid = (*env)->GetFieldID(env, optionsCls, "subsampleMode", "Lcom/criteo/vips/enums/VipsForeignSubsample;");
		jobject subsampleMode = (*env)->GetObjectField(env, options, subsampleModeFid);
		if (subsampleMode != NULL) {
			jclass subsampleModeCls = (*env)->GetObjectClass(env, subsampleMode);
			jfieldID subsampleModeValueFid = (*env)->GetFieldID(env, subsampleModeCls, "value", "I");
			jint subsampleModeValue = (*env)->GetIntField(env, subsampleMode, subsampleModeValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, subsampleModeValue);
			g_object_set_property(G_OBJECT(op), "subsample-mode", &gvalue);
			g_value_unset(&gvalue);
		}

		// restart-interval
		jfieldID restartIntervalFid = (*env)->GetFieldID(env, optionsCls, "restartInterval", "Ljava/lang/Integer;");
		jobject restartIntervalObjectValue = (*env)->GetObjectField(env, options, restartIntervalFid);
		if (restartIntervalObjectValue != NULL) {
			jint restartInterval = (*env)->CallIntMethod(env, restartIntervalObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, restartInterval);
			g_object_set_property(G_OBJECT(op), "restart-interval", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "jpegsave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_AbstractVipsImage_jpegSaveBuffer(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("jpegsave_buffer");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// profile
		jfieldID profileFid = (*env)->GetFieldID(env, optionsCls, "profile", "Ljava/lang/String;");
		jstring profile = (jstring) (*env)->GetObjectField(env, options, profileFid);
		if (profile != NULL) {
			const char *profileChars = (*env)->GetStringUTFChars(env, profile, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, profileChars);
			(*env)->ReleaseStringUTFChars(env, profile, profileChars);
			g_object_set_property(G_OBJECT(op), "profile", &gvalue);
			g_value_unset(&gvalue);
		}

		// optimize-coding
		jfieldID optimizeCodingFid = (*env)->GetFieldID(env, optionsCls, "optimizeCoding", "Ljava/lang/Boolean;");
		jobject optimizeCodingObjectValue = (*env)->GetObjectField(env, options, optimizeCodingFid);
		if (optimizeCodingObjectValue != NULL) {
			jboolean optimizeCoding = (*env)->CallBooleanMethod(env, optimizeCodingObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optimizeCoding);
			g_object_set_property(G_OBJECT(op), "optimize-coding", &gvalue);
			g_value_unset(&gvalue);
		}

		// interlace
		jfieldID interlaceFid = (*env)->GetFieldID(env, optionsCls, "interlace", "Ljava/lang/Boolean;");
		jobject interlaceObjectValue = (*env)->GetObjectField(env, options, interlaceFid);
		if (interlaceObjectValue != NULL) {
			jboolean interlace = (*env)->CallBooleanMethod(env, interlaceObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, interlace);
			g_object_set_property(G_OBJECT(op), "interlace", &gvalue);
			g_value_unset(&gvalue);
		}

		// trellis-quant
		jfieldID trellisQuantFid = (*env)->GetFieldID(env, optionsCls, "trellisQuant", "Ljava/lang/Boolean;");
		jobject trellisQuantObjectValue = (*env)->GetObjectField(env, options, trellisQuantFid);
		if (trellisQuantObjectValue != NULL) {
			jboolean trellisQuant = (*env)->CallBooleanMethod(env, trellisQuantObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, trellisQuant);
			g_object_set_property(G_OBJECT(op), "trellis-quant", &gvalue);
			g_value_unset(&gvalue);
		}

		// overshoot-deringing
		jfieldID overshootDeringingFid = (*env)->GetFieldID(env, optionsCls, "overshootDeringing", "Ljava/lang/Boolean;");
		jobject overshootDeringingObjectValue = (*env)->GetObjectField(env, options, overshootDeringingFid);
		if (overshootDeringingObjectValue != NULL) {
			jboolean overshootDeringing = (*env)->CallBooleanMethod(env, overshootDeringingObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, overshootDeringing);
			g_object_set_property(G_OBJECT(op), "overshoot-deringing", &gvalue);
			g_value_unset(&gvalue);
		}

		// optimize-scans
		jfieldID optimizeScansFid = (*env)->GetFieldID(env, optionsCls, "optimizeScans", "Ljava/lang/Boolean;");
		jobject optimizeScansObjectValue = (*env)->GetObjectField(env, options, optimizeScansFid);
		if (optimizeScansObjectValue != NULL) {
			jboolean optimizeScans = (*env)->CallBooleanMethod(env, optimizeScansObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optimizeScans);
			g_object_set_property(G_OBJECT(op), "optimize-scans", &gvalue);
			g_value_unset(&gvalue);
		}

		// quant-table
		jfieldID quantTableFid = (*env)->GetFieldID(env, optionsCls, "quantTable", "Ljava/lang/Integer;");
		jobject quantTableObjectValue = (*env)->GetObjectField(env, options, quantTableFid);
		if (quantTableObjectValue != NULL) {
			jint quantTable = (*env)->CallIntMethod(env, quantTableObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, quantTable);
			g_object_set_property(G_OBJECT(op), "quant-table", &gvalue);
			g_value_unset(&gvalue);
		}

		// subsample-mode
		jfieldID subsampleModeFid = (*env)->GetFieldID(env, optionsCls, "subsampleMode", "Lcom/criteo/vips/enums/VipsForeignSubsample;");
		jobject subsampleMode = (*env)->GetObjectField(env, options, subsampleModeFid);
		if (subsampleMode != NULL) {
			jclass subsampleModeCls = (*env)->GetObjectClass(env, subsampleMode);
			jfieldID subsampleModeValueFid = (*env)->GetFieldID(env, subsampleModeCls, "value", "I");
			jint subsampleModeValue = (*env)->GetIntField(env, subsampleMode, subsampleModeValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, subsampleModeValue);
			g_object_set_property(G_OBJECT(op), "subsample-mode", &gvalue);
			g_value_unset(&gvalue);
		}

		// restart-interval
		jfieldID restartIntervalFid = (*env)->GetFieldID(env, optionsCls, "restartInterval", "Ljava/lang/Integer;");
		jobject restartIntervalObjectValue = (*env)->GetObjectField(env, options, restartIntervalFid);
		if (restartIntervalObjectValue != NULL) {
			jint restartInterval = (*env)->CallIntMethod(env, restartIntervalObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, restartInterval);
			g_object_set_property(G_OBJECT(op), "restart-interval", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "jpegsave_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// buffer
	g_value_init(&gvalue, VIPS_TYPE_BLOB);
	g_object_get_property(G_OBJECT(op), "buffer", &gvalue);
	size_t bufferSize = 0;
	void *bufferData = vips_value_get_blob(&gvalue, &bufferSize);
	jint bufferLength = bufferSize / sizeof(jbyte);
	jbyteArray buffer = (*env)->NewByteArray(env, bufferLength);
	(*env)->SetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return buffer;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_jpegSaveMime(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("jpegsave_mime");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// profile
		jfieldID profileFid = (*env)->GetFieldID(env, optionsCls, "profile", "Ljava/lang/String;");
		jstring profile = (jstring) (*env)->GetObjectField(env, options, profileFid);
		if (profile != NULL) {
			const char *profileChars = (*env)->GetStringUTFChars(env, profile, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, profileChars);
			(*env)->ReleaseStringUTFChars(env, profile, profileChars);
			g_object_set_property(G_OBJECT(op), "profile", &gvalue);
			g_value_unset(&gvalue);
		}

		// optimize-coding
		jfieldID optimizeCodingFid = (*env)->GetFieldID(env, optionsCls, "optimizeCoding", "Ljava/lang/Boolean;");
		jobject optimizeCodingObjectValue = (*env)->GetObjectField(env, options, optimizeCodingFid);
		if (optimizeCodingObjectValue != NULL) {
			jboolean optimizeCoding = (*env)->CallBooleanMethod(env, optimizeCodingObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optimizeCoding);
			g_object_set_property(G_OBJECT(op), "optimize-coding", &gvalue);
			g_value_unset(&gvalue);
		}

		// interlace
		jfieldID interlaceFid = (*env)->GetFieldID(env, optionsCls, "interlace", "Ljava/lang/Boolean;");
		jobject interlaceObjectValue = (*env)->GetObjectField(env, options, interlaceFid);
		if (interlaceObjectValue != NULL) {
			jboolean interlace = (*env)->CallBooleanMethod(env, interlaceObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, interlace);
			g_object_set_property(G_OBJECT(op), "interlace", &gvalue);
			g_value_unset(&gvalue);
		}

		// trellis-quant
		jfieldID trellisQuantFid = (*env)->GetFieldID(env, optionsCls, "trellisQuant", "Ljava/lang/Boolean;");
		jobject trellisQuantObjectValue = (*env)->GetObjectField(env, options, trellisQuantFid);
		if (trellisQuantObjectValue != NULL) {
			jboolean trellisQuant = (*env)->CallBooleanMethod(env, trellisQuantObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, trellisQuant);
			g_object_set_property(G_OBJECT(op), "trellis-quant", &gvalue);
			g_value_unset(&gvalue);
		}

		// overshoot-deringing
		jfieldID overshootDeringingFid = (*env)->GetFieldID(env, optionsCls, "overshootDeringing", "Ljava/lang/Boolean;");
		jobject overshootDeringingObjectValue = (*env)->GetObjectField(env, options, overshootDeringingFid);
		if (overshootDeringingObjectValue != NULL) {
			jboolean overshootDeringing = (*env)->CallBooleanMethod(env, overshootDeringingObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, overshootDeringing);
			g_object_set_property(G_OBJECT(op), "overshoot-deringing", &gvalue);
			g_value_unset(&gvalue);
		}

		// optimize-scans
		jfieldID optimizeScansFid = (*env)->GetFieldID(env, optionsCls, "optimizeScans", "Ljava/lang/Boolean;");
		jobject optimizeScansObjectValue = (*env)->GetObjectField(env, options, optimizeScansFid);
		if (optimizeScansObjectValue != NULL) {
			jboolean optimizeScans = (*env)->CallBooleanMethod(env, optimizeScansObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optimizeScans);
			g_object_set_property(G_OBJECT(op), "optimize-scans", &gvalue);
			g_value_unset(&gvalue);
		}

		// quant-table
		jfieldID quantTableFid = (*env)->GetFieldID(env, optionsCls, "quantTable", "Ljava/lang/Integer;");
		jobject quantTableObjectValue = (*env)->GetObjectField(env, options, quantTableFid);
		if (quantTableObjectValue != NULL) {
			jint quantTable = (*env)->CallIntMethod(env, quantTableObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, quantTable);
			g_object_set_property(G_OBJECT(op), "quant-table", &gvalue);
			g_value_unset(&gvalue);
		}

		// subsample-mode
		jfieldID subsampleModeFid = (*env)->GetFieldID(env, optionsCls, "subsampleMode", "Lcom/criteo/vips/enums/VipsForeignSubsample;");
		jobject subsampleMode = (*env)->GetObjectField(env, options, subsampleModeFid);
		if (subsampleMode != NULL) {
			jclass subsampleModeCls = (*env)->GetObjectClass(env, subsampleMode);
			jfieldID subsampleModeValueFid = (*env)->GetFieldID(env, subsampleModeCls, "value", "I");
			jint subsampleModeValue = (*env)->GetIntField(env, subsampleMode, subsampleModeValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, subsampleModeValue);
			g_object_set_property(G_OBJECT(op), "subsample-mode", &gvalue);
			g_value_unset(&gvalue);
		}

		// restart-interval
		jfieldID restartIntervalFid = (*env)->GetFieldID(env, optionsCls, "restartInterval", "Ljava/lang/Integer;");
		jobject restartIntervalObjectValue = (*env)->GetObjectField(env, options, restartIntervalFid);
		if (restartIntervalObjectValue != NULL) {
			jint restartInterval = (*env)->CallIntMethod(env, restartIntervalObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, restartInterval);
			g_object_set_property(G_OBJECT(op), "restart-interval", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "jpegsave_mime failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_jxlLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("jxlload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "jxlload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_jxlLoadBuffer(JNIEnv *env, jclass cls, jbyteArray buffer, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("jxlload_buffer");

	// buffer
	if (buffer != NULL) {
		jint bufferLength = (*env)->GetArrayLength(env, buffer);
		size_t bufferSize = bufferLength * sizeof(jbyte);
		void *bufferData = vips_tracked_malloc(bufferSize);
		if (bufferData == NULL) {
			throwVipsException(env, "Failed to allocate memory for buffer");
		}
		(*env)->GetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
		g_value_init(&gvalue, VIPS_TYPE_BLOB);
		vips_value_set_blob_free(&gvalue, bufferData, bufferSize);
		g_object_set_property(G_OBJECT(op), "buffer", &gvalue);
		g_value_unset(&gvalue);
	
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "jxlload_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_jxlSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("jxlsave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// tier
		jfieldID tierFid = (*env)->GetFieldID(env, optionsCls, "tier", "Ljava/lang/Integer;");
		jobject tierObjectValue = (*env)->GetObjectField(env, options, tierFid);
		if (tierObjectValue != NULL) {
			jint tier = (*env)->CallIntMethod(env, tierObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tier);
			g_object_set_property(G_OBJECT(op), "tier", &gvalue);
			g_value_unset(&gvalue);
		}

		// distance
		jfieldID distanceFid = (*env)->GetFieldID(env, optionsCls, "distance", "Ljava/lang/Double;");
		jobject distanceObjectValue = (*env)->GetObjectField(env, options, distanceFid);
		if (distanceObjectValue != NULL) {
			jdouble distance = (*env)->CallDoubleMethod(env, distanceObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, distance);
			g_object_set_property(G_OBJECT(op), "distance", &gvalue);
			g_value_unset(&gvalue);
		}

		// effort
		jfieldID effortFid = (*env)->GetFieldID(env, optionsCls, "effort", "Ljava/lang/Integer;");
		jobject effortObjectValue = (*env)->GetObjectField(env, options, effortFid);
		if (effortObjectValue != NULL) {
			jint effort = (*env)->CallIntMethod(env, effortObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, effort);
			g_object_set_property(G_OBJECT(op), "effort", &gvalue);
			g_value_unset(&gvalue);
		}

		// lossless
		jfieldID losslessFid = (*env)->GetFieldID(env, optionsCls, "lossless", "Ljava/lang/Boolean;");
		jobject losslessObjectValue = (*env)->GetObjectField(env, options, losslessFid);
		if (losslessObjectValue != NULL) {
			jboolean lossless = (*env)->CallBooleanMethod(env, losslessObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, lossless);
			g_object_set_property(G_OBJECT(op), "lossless", &gvalue);
			g_value_unset(&gvalue);
		}

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "jxlsave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_AbstractVipsImage_jxlSaveBuffer(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("jxlsave_buffer");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// tier
		jfieldID tierFid = (*env)->GetFieldID(env, optionsCls, "tier", "Ljava/lang/Integer;");
		jobject tierObjectValue = (*env)->GetObjectField(env, options, tierFid);
		if (tierObjectValue != NULL) {
			jint tier = (*env)->CallIntMethod(env, tierObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tier);
			g_object_set_property(G_OBJECT(op), "tier", &gvalue);
			g_value_unset(&gvalue);
		}

		// distance
		jfieldID distanceFid = (*env)->GetFieldID(env, optionsCls, "distance", "Ljava/lang/Double;");
		jobject distanceObjectValue = (*env)->GetObjectField(env, options, distanceFid);
		if (distanceObjectValue != NULL) {
			jdouble distance = (*env)->CallDoubleMethod(env, distanceObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, distance);
			g_object_set_property(G_OBJECT(op), "distance", &gvalue);
			g_value_unset(&gvalue);
		}

		// effort
		jfieldID effortFid = (*env)->GetFieldID(env, optionsCls, "effort", "Ljava/lang/Integer;");
		jobject effortObjectValue = (*env)->GetObjectField(env, options, effortFid);
		if (effortObjectValue != NULL) {
			jint effort = (*env)->CallIntMethod(env, effortObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, effort);
			g_object_set_property(G_OBJECT(op), "effort", &gvalue);
			g_value_unset(&gvalue);
		}

		// lossless
		jfieldID losslessFid = (*env)->GetFieldID(env, optionsCls, "lossless", "Ljava/lang/Boolean;");
		jobject losslessObjectValue = (*env)->GetObjectField(env, options, losslessFid);
		if (losslessObjectValue != NULL) {
			jboolean lossless = (*env)->CallBooleanMethod(env, losslessObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, lossless);
			g_object_set_property(G_OBJECT(op), "lossless", &gvalue);
			g_value_unset(&gvalue);
		}

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "jxlsave_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// buffer
	g_value_init(&gvalue, VIPS_TYPE_BLOB);
	g_object_get_property(G_OBJECT(op), "buffer", &gvalue);
	size_t bufferSize = 0;
	void *bufferData = vips_value_get_blob(&gvalue, &bufferSize);
	jint bufferLength = bufferSize / sizeof(jbyte);
	jbyteArray buffer = (*env)->NewByteArray(env, bufferLength);
	(*env)->SetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return buffer;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_lab2LabQ(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("Lab2LabQ");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "Lab2LabQ failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_lab2LabS(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("Lab2LabS");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "Lab2LabS failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_lab2LCh(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("Lab2LCh");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "Lab2LCh failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_lab2XYZ(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("Lab2XYZ");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// temp
		jfieldID tempFid = (*env)->GetFieldID(env, optionsCls, "temp", "Lcom/criteo/vips/PixelPacket;");
		jobject temp = (*env)->GetObjectField(env, options, tempFid);
		if (temp != NULL) {
			jdouble *tempElements = (*env)->GetDoubleArrayElements(env, temp, NULL);
			jint tempLength = (*env)->GetArrayLength(env, temp);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, tempElements, tempLength);
			(*env)->ReleaseDoubleArrayElements(env, temp, tempElements, 0);
			g_object_set_property(G_OBJECT(op), "temp", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "Lab2XYZ failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_labelregions(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("labelregions");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "labelregions failed");
		return;
	}
	g_object_unref(op);
	op = new_op;

	// Mutating image result
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "mask", &gvalue);
	VipsImage *_mask = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(_mask); 
	g_value_unset(&gvalue);
	g_object_unref((VipsImage *) (*env)->GetLongField(env, in, handle_fid));
	(*env)->SetLongField(env, in, handle_fid, (jlong) _mask);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_labQ2Lab(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("LabQ2Lab");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "LabQ2Lab failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_labQ2LabS(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("LabQ2LabS");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "LabQ2LabS failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_labQ2sRGB(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("LabQ2sRGB");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "LabQ2sRGB failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_labS2Lab(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("LabS2Lab");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "LabS2Lab failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_labS2LabQ(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("LabS2LabQ");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "LabS2LabQ failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_lCh2CMC(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("LCh2CMC");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "LCh2CMC failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_lCh2Lab(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("LCh2Lab");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "LCh2Lab failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_linear(JNIEnv *env, jobject in, jobject a, jobject b, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("linear");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// a
	if (a != NULL) {
		jdouble *aElements = (*env)->GetDoubleArrayElements(env, a, NULL);
		jint aLength = (*env)->GetArrayLength(env, a);
		g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
		vips_value_set_array_double(&gvalue, aElements, aLength);
		(*env)->ReleaseDoubleArrayElements(env, a, aElements, 0);
		g_object_set_property(G_OBJECT(op), "a", &gvalue);
		g_value_unset(&gvalue);
	}

	// b
	if (b != NULL) {
		jdouble *bElements = (*env)->GetDoubleArrayElements(env, b, NULL);
		jint bLength = (*env)->GetArrayLength(env, b);
		g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
		vips_value_set_array_double(&gvalue, bElements, bLength);
		(*env)->ReleaseDoubleArrayElements(env, b, bElements, 0);
		g_object_set_property(G_OBJECT(op), "b", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "linear failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_linecache(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("linecache");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// tile-height
		jfieldID tileHeightFid = (*env)->GetFieldID(env, optionsCls, "tileHeight", "Ljava/lang/Integer;");
		jobject tileHeightObjectValue = (*env)->GetObjectField(env, options, tileHeightFid);
		if (tileHeightObjectValue != NULL) {
			jint tileHeight = (*env)->CallIntMethod(env, tileHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileHeight);
			g_object_set_property(G_OBJECT(op), "tile-height", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// threaded
		jfieldID threadedFid = (*env)->GetFieldID(env, optionsCls, "threaded", "Ljava/lang/Boolean;");
		jobject threadedObjectValue = (*env)->GetObjectField(env, options, threadedFid);
		if (threadedObjectValue != NULL) {
			jboolean threaded = (*env)->CallBooleanMethod(env, threadedObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, threaded);
			g_object_set_property(G_OBJECT(op), "threaded", &gvalue);
			g_value_unset(&gvalue);
		}

		// persistent
		jfieldID persistentFid = (*env)->GetFieldID(env, optionsCls, "persistent", "Ljava/lang/Boolean;");
		jobject persistentObjectValue = (*env)->GetObjectField(env, options, persistentFid);
		if (persistentObjectValue != NULL) {
			jboolean persistent = (*env)->CallBooleanMethod(env, persistentObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, persistent);
			g_object_set_property(G_OBJECT(op), "persistent", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "linecache failed");
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
Java_com_criteo_vips_AbstractVipsImage_logmat(JNIEnv *env, jclass cls, jdouble sigma, jdouble minAmpl, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("logmat");

	// sigma
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, sigma);
	g_object_set_property(G_OBJECT(op), "sigma", &gvalue);
	g_value_unset(&gvalue);

	// min-ampl
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, minAmpl);
	g_object_set_property(G_OBJECT(op), "min-ampl", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// separable
		jfieldID separableFid = (*env)->GetFieldID(env, optionsCls, "separable", "Ljava/lang/Boolean;");
		jobject separableObjectValue = (*env)->GetObjectField(env, options, separableFid);
		if (separableObjectValue != NULL) {
			jboolean separable = (*env)->CallBooleanMethod(env, separableObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, separable);
			g_object_set_property(G_OBJECT(op), "separable", &gvalue);
			g_value_unset(&gvalue);
		}

		// precision
		jfieldID precisionFid = (*env)->GetFieldID(env, optionsCls, "precision", "Lcom/criteo/vips/enums/VipsPrecision;");
		jobject precision = (*env)->GetObjectField(env, options, precisionFid);
		if (precision != NULL) {
			jclass precisionCls = (*env)->GetObjectClass(env, precision);
			jfieldID precisionValueFid = (*env)->GetFieldID(env, precisionCls, "value", "I");
			jint precisionValue = (*env)->GetIntField(env, precision, precisionValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, precisionValue);
			g_object_set_property(G_OBJECT(op), "precision", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "logmat failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_magickLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("magickload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// density
		jfieldID densityFid = (*env)->GetFieldID(env, optionsCls, "density", "Ljava/lang/String;");
		jstring density = (jstring) (*env)->GetObjectField(env, options, densityFid);
		if (density != NULL) {
			const char *densityChars = (*env)->GetStringUTFChars(env, density, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, densityChars);
			(*env)->ReleaseStringUTFChars(env, density, densityChars);
			g_object_set_property(G_OBJECT(op), "density", &gvalue);
			g_value_unset(&gvalue);
		}

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// n
		jfieldID nFid = (*env)->GetFieldID(env, optionsCls, "n", "Ljava/lang/Integer;");
		jobject nObjectValue = (*env)->GetObjectField(env, options, nFid);
		if (nObjectValue != NULL) {
			jint n = (*env)->CallIntMethod(env, nObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, n);
			g_object_set_property(G_OBJECT(op), "n", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "magickload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_magickLoadBuffer(JNIEnv *env, jclass cls, jbyteArray buffer, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("magickload_buffer");

	// buffer
	if (buffer != NULL) {
		jint bufferLength = (*env)->GetArrayLength(env, buffer);
		size_t bufferSize = bufferLength * sizeof(jbyte);
		void *bufferData = vips_tracked_malloc(bufferSize);
		if (bufferData == NULL) {
			throwVipsException(env, "Failed to allocate memory for buffer");
		}
		(*env)->GetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
		g_value_init(&gvalue, VIPS_TYPE_BLOB);
		vips_value_set_blob_free(&gvalue, bufferData, bufferSize);
		g_object_set_property(G_OBJECT(op), "buffer", &gvalue);
		g_value_unset(&gvalue);
	
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// density
		jfieldID densityFid = (*env)->GetFieldID(env, optionsCls, "density", "Ljava/lang/String;");
		jstring density = (jstring) (*env)->GetObjectField(env, options, densityFid);
		if (density != NULL) {
			const char *densityChars = (*env)->GetStringUTFChars(env, density, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, densityChars);
			(*env)->ReleaseStringUTFChars(env, density, densityChars);
			g_object_set_property(G_OBJECT(op), "density", &gvalue);
			g_value_unset(&gvalue);
		}

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// n
		jfieldID nFid = (*env)->GetFieldID(env, optionsCls, "n", "Ljava/lang/Integer;");
		jobject nObjectValue = (*env)->GetObjectField(env, options, nFid);
		if (nObjectValue != NULL) {
			jint n = (*env)->CallIntMethod(env, nObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, n);
			g_object_set_property(G_OBJECT(op), "n", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "magickload_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_magickSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("magicksave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// format
		jfieldID formatFid = (*env)->GetFieldID(env, optionsCls, "format", "Ljava/lang/String;");
		jstring format = (jstring) (*env)->GetObjectField(env, options, formatFid);
		if (format != NULL) {
			const char *formatChars = (*env)->GetStringUTFChars(env, format, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, formatChars);
			(*env)->ReleaseStringUTFChars(env, format, formatChars);
			g_object_set_property(G_OBJECT(op), "format", &gvalue);
			g_value_unset(&gvalue);
		}

		// quality
		jfieldID qualityFid = (*env)->GetFieldID(env, optionsCls, "quality", "Ljava/lang/Integer;");
		jobject qualityObjectValue = (*env)->GetObjectField(env, options, qualityFid);
		if (qualityObjectValue != NULL) {
			jint quality = (*env)->CallIntMethod(env, qualityObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, quality);
			g_object_set_property(G_OBJECT(op), "quality", &gvalue);
			g_value_unset(&gvalue);
		}

		// optimize-gif-frames
		jfieldID optimizeGifFramesFid = (*env)->GetFieldID(env, optionsCls, "optimizeGifFrames", "Ljava/lang/Boolean;");
		jobject optimizeGifFramesObjectValue = (*env)->GetObjectField(env, options, optimizeGifFramesFid);
		if (optimizeGifFramesObjectValue != NULL) {
			jboolean optimizeGifFrames = (*env)->CallBooleanMethod(env, optimizeGifFramesObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optimizeGifFrames);
			g_object_set_property(G_OBJECT(op), "optimize-gif-frames", &gvalue);
			g_value_unset(&gvalue);
		}

		// optimize-gif-transparency
		jfieldID optimizeGifTransparencyFid = (*env)->GetFieldID(env, optionsCls, "optimizeGifTransparency", "Ljava/lang/Boolean;");
		jobject optimizeGifTransparencyObjectValue = (*env)->GetObjectField(env, options, optimizeGifTransparencyFid);
		if (optimizeGifTransparencyObjectValue != NULL) {
			jboolean optimizeGifTransparency = (*env)->CallBooleanMethod(env, optimizeGifTransparencyObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optimizeGifTransparency);
			g_object_set_property(G_OBJECT(op), "optimize-gif-transparency", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "magicksave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_AbstractVipsImage_magickSaveBuffer(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("magicksave_buffer");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// format
		jfieldID formatFid = (*env)->GetFieldID(env, optionsCls, "format", "Ljava/lang/String;");
		jstring format = (jstring) (*env)->GetObjectField(env, options, formatFid);
		if (format != NULL) {
			const char *formatChars = (*env)->GetStringUTFChars(env, format, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, formatChars);
			(*env)->ReleaseStringUTFChars(env, format, formatChars);
			g_object_set_property(G_OBJECT(op), "format", &gvalue);
			g_value_unset(&gvalue);
		}

		// quality
		jfieldID qualityFid = (*env)->GetFieldID(env, optionsCls, "quality", "Ljava/lang/Integer;");
		jobject qualityObjectValue = (*env)->GetObjectField(env, options, qualityFid);
		if (qualityObjectValue != NULL) {
			jint quality = (*env)->CallIntMethod(env, qualityObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, quality);
			g_object_set_property(G_OBJECT(op), "quality", &gvalue);
			g_value_unset(&gvalue);
		}

		// optimize-gif-frames
		jfieldID optimizeGifFramesFid = (*env)->GetFieldID(env, optionsCls, "optimizeGifFrames", "Ljava/lang/Boolean;");
		jobject optimizeGifFramesObjectValue = (*env)->GetObjectField(env, options, optimizeGifFramesFid);
		if (optimizeGifFramesObjectValue != NULL) {
			jboolean optimizeGifFrames = (*env)->CallBooleanMethod(env, optimizeGifFramesObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optimizeGifFrames);
			g_object_set_property(G_OBJECT(op), "optimize-gif-frames", &gvalue);
			g_value_unset(&gvalue);
		}

		// optimize-gif-transparency
		jfieldID optimizeGifTransparencyFid = (*env)->GetFieldID(env, optionsCls, "optimizeGifTransparency", "Ljava/lang/Boolean;");
		jobject optimizeGifTransparencyObjectValue = (*env)->GetObjectField(env, options, optimizeGifTransparencyFid);
		if (optimizeGifTransparencyObjectValue != NULL) {
			jboolean optimizeGifTransparency = (*env)->CallBooleanMethod(env, optimizeGifTransparencyObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optimizeGifTransparency);
			g_object_set_property(G_OBJECT(op), "optimize-gif-transparency", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "magicksave_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// buffer
	g_value_init(&gvalue, VIPS_TYPE_BLOB);
	g_object_get_property(G_OBJECT(op), "buffer", &gvalue);
	size_t bufferSize = 0;
	void *bufferData = vips_value_get_blob(&gvalue, &bufferSize);
	jint bufferLength = bufferSize / sizeof(jbyte);
	jbyteArray buffer = (*env)->NewByteArray(env, bufferLength);
	(*env)->SetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return buffer;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_maplut(JNIEnv *env, jobject in, jobject lut, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("maplut");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// lut
	if (lut != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, lut, handle_fid));
		g_object_set_property(G_OBJECT(op), "lut", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// band
		jfieldID bandFid = (*env)->GetFieldID(env, optionsCls, "band", "Ljava/lang/Integer;");
		jobject bandObjectValue = (*env)->GetObjectField(env, options, bandFid);
		if (bandObjectValue != NULL) {
			jint band = (*env)->CallIntMethod(env, bandObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, band);
			g_object_set_property(G_OBJECT(op), "band", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "maplut failed");
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
Java_com_criteo_vips_AbstractVipsImage_maskButterworth(JNIEnv *env, jclass cls, jint width, jint height, jdouble order, jdouble frequencyCutoff, jdouble amplitudeCutoff, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("mask_butterworth");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// order
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, order);
	g_object_set_property(G_OBJECT(op), "order", &gvalue);
	g_value_unset(&gvalue);

	// frequency-cutoff
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, frequencyCutoff);
	g_object_set_property(G_OBJECT(op), "frequency-cutoff", &gvalue);
	g_value_unset(&gvalue);

	// amplitude-cutoff
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, amplitudeCutoff);
	g_object_set_property(G_OBJECT(op), "amplitude-cutoff", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

		// nodc
		jfieldID nodcFid = (*env)->GetFieldID(env, optionsCls, "nodc", "Ljava/lang/Boolean;");
		jobject nodcObjectValue = (*env)->GetObjectField(env, options, nodcFid);
		if (nodcObjectValue != NULL) {
			jboolean nodc = (*env)->CallBooleanMethod(env, nodcObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, nodc);
			g_object_set_property(G_OBJECT(op), "nodc", &gvalue);
			g_value_unset(&gvalue);
		}

		// reject
		jfieldID rejectFid = (*env)->GetFieldID(env, optionsCls, "reject", "Ljava/lang/Boolean;");
		jobject rejectObjectValue = (*env)->GetObjectField(env, options, rejectFid);
		if (rejectObjectValue != NULL) {
			jboolean reject = (*env)->CallBooleanMethod(env, rejectObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, reject);
			g_object_set_property(G_OBJECT(op), "reject", &gvalue);
			g_value_unset(&gvalue);
		}

		// optical
		jfieldID opticalFid = (*env)->GetFieldID(env, optionsCls, "optical", "Ljava/lang/Boolean;");
		jobject opticalObjectValue = (*env)->GetObjectField(env, options, opticalFid);
		if (opticalObjectValue != NULL) {
			jboolean optical = (*env)->CallBooleanMethod(env, opticalObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optical);
			g_object_set_property(G_OBJECT(op), "optical", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "mask_butterworth failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_maskButterworthBand(JNIEnv *env, jclass cls, jint width, jint height, jdouble order, jdouble frequencyCutoffX, jdouble frequencyCutoffY, jdouble radius, jdouble amplitudeCutoff, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("mask_butterworth_band");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// order
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, order);
	g_object_set_property(G_OBJECT(op), "order", &gvalue);
	g_value_unset(&gvalue);

	// frequency-cutoff-x
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, frequencyCutoffX);
	g_object_set_property(G_OBJECT(op), "frequency-cutoff-x", &gvalue);
	g_value_unset(&gvalue);

	// frequency-cutoff-y
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, frequencyCutoffY);
	g_object_set_property(G_OBJECT(op), "frequency-cutoff-y", &gvalue);
	g_value_unset(&gvalue);

	// radius
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, radius);
	g_object_set_property(G_OBJECT(op), "radius", &gvalue);
	g_value_unset(&gvalue);

	// amplitude-cutoff
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, amplitudeCutoff);
	g_object_set_property(G_OBJECT(op), "amplitude-cutoff", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

		// nodc
		jfieldID nodcFid = (*env)->GetFieldID(env, optionsCls, "nodc", "Ljava/lang/Boolean;");
		jobject nodcObjectValue = (*env)->GetObjectField(env, options, nodcFid);
		if (nodcObjectValue != NULL) {
			jboolean nodc = (*env)->CallBooleanMethod(env, nodcObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, nodc);
			g_object_set_property(G_OBJECT(op), "nodc", &gvalue);
			g_value_unset(&gvalue);
		}

		// reject
		jfieldID rejectFid = (*env)->GetFieldID(env, optionsCls, "reject", "Ljava/lang/Boolean;");
		jobject rejectObjectValue = (*env)->GetObjectField(env, options, rejectFid);
		if (rejectObjectValue != NULL) {
			jboolean reject = (*env)->CallBooleanMethod(env, rejectObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, reject);
			g_object_set_property(G_OBJECT(op), "reject", &gvalue);
			g_value_unset(&gvalue);
		}

		// optical
		jfieldID opticalFid = (*env)->GetFieldID(env, optionsCls, "optical", "Ljava/lang/Boolean;");
		jobject opticalObjectValue = (*env)->GetObjectField(env, options, opticalFid);
		if (opticalObjectValue != NULL) {
			jboolean optical = (*env)->CallBooleanMethod(env, opticalObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optical);
			g_object_set_property(G_OBJECT(op), "optical", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "mask_butterworth_band failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_maskButterworthRing(JNIEnv *env, jclass cls, jint width, jint height, jdouble order, jdouble frequencyCutoff, jdouble amplitudeCutoff, jdouble ringwidth, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("mask_butterworth_ring");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// order
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, order);
	g_object_set_property(G_OBJECT(op), "order", &gvalue);
	g_value_unset(&gvalue);

	// frequency-cutoff
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, frequencyCutoff);
	g_object_set_property(G_OBJECT(op), "frequency-cutoff", &gvalue);
	g_value_unset(&gvalue);

	// amplitude-cutoff
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, amplitudeCutoff);
	g_object_set_property(G_OBJECT(op), "amplitude-cutoff", &gvalue);
	g_value_unset(&gvalue);

	// ringwidth
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, ringwidth);
	g_object_set_property(G_OBJECT(op), "ringwidth", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

		// nodc
		jfieldID nodcFid = (*env)->GetFieldID(env, optionsCls, "nodc", "Ljava/lang/Boolean;");
		jobject nodcObjectValue = (*env)->GetObjectField(env, options, nodcFid);
		if (nodcObjectValue != NULL) {
			jboolean nodc = (*env)->CallBooleanMethod(env, nodcObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, nodc);
			g_object_set_property(G_OBJECT(op), "nodc", &gvalue);
			g_value_unset(&gvalue);
		}

		// reject
		jfieldID rejectFid = (*env)->GetFieldID(env, optionsCls, "reject", "Ljava/lang/Boolean;");
		jobject rejectObjectValue = (*env)->GetObjectField(env, options, rejectFid);
		if (rejectObjectValue != NULL) {
			jboolean reject = (*env)->CallBooleanMethod(env, rejectObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, reject);
			g_object_set_property(G_OBJECT(op), "reject", &gvalue);
			g_value_unset(&gvalue);
		}

		// optical
		jfieldID opticalFid = (*env)->GetFieldID(env, optionsCls, "optical", "Ljava/lang/Boolean;");
		jobject opticalObjectValue = (*env)->GetObjectField(env, options, opticalFid);
		if (opticalObjectValue != NULL) {
			jboolean optical = (*env)->CallBooleanMethod(env, opticalObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optical);
			g_object_set_property(G_OBJECT(op), "optical", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "mask_butterworth_ring failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_maskFractal(JNIEnv *env, jclass cls, jint width, jint height, jdouble fractalDimension, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("mask_fractal");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// fractal-dimension
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, fractalDimension);
	g_object_set_property(G_OBJECT(op), "fractal-dimension", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

		// nodc
		jfieldID nodcFid = (*env)->GetFieldID(env, optionsCls, "nodc", "Ljava/lang/Boolean;");
		jobject nodcObjectValue = (*env)->GetObjectField(env, options, nodcFid);
		if (nodcObjectValue != NULL) {
			jboolean nodc = (*env)->CallBooleanMethod(env, nodcObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, nodc);
			g_object_set_property(G_OBJECT(op), "nodc", &gvalue);
			g_value_unset(&gvalue);
		}

		// reject
		jfieldID rejectFid = (*env)->GetFieldID(env, optionsCls, "reject", "Ljava/lang/Boolean;");
		jobject rejectObjectValue = (*env)->GetObjectField(env, options, rejectFid);
		if (rejectObjectValue != NULL) {
			jboolean reject = (*env)->CallBooleanMethod(env, rejectObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, reject);
			g_object_set_property(G_OBJECT(op), "reject", &gvalue);
			g_value_unset(&gvalue);
		}

		// optical
		jfieldID opticalFid = (*env)->GetFieldID(env, optionsCls, "optical", "Ljava/lang/Boolean;");
		jobject opticalObjectValue = (*env)->GetObjectField(env, options, opticalFid);
		if (opticalObjectValue != NULL) {
			jboolean optical = (*env)->CallBooleanMethod(env, opticalObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optical);
			g_object_set_property(G_OBJECT(op), "optical", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "mask_fractal failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_maskGaussian(JNIEnv *env, jclass cls, jint width, jint height, jdouble frequencyCutoff, jdouble amplitudeCutoff, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("mask_gaussian");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// frequency-cutoff
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, frequencyCutoff);
	g_object_set_property(G_OBJECT(op), "frequency-cutoff", &gvalue);
	g_value_unset(&gvalue);

	// amplitude-cutoff
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, amplitudeCutoff);
	g_object_set_property(G_OBJECT(op), "amplitude-cutoff", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

		// nodc
		jfieldID nodcFid = (*env)->GetFieldID(env, optionsCls, "nodc", "Ljava/lang/Boolean;");
		jobject nodcObjectValue = (*env)->GetObjectField(env, options, nodcFid);
		if (nodcObjectValue != NULL) {
			jboolean nodc = (*env)->CallBooleanMethod(env, nodcObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, nodc);
			g_object_set_property(G_OBJECT(op), "nodc", &gvalue);
			g_value_unset(&gvalue);
		}

		// reject
		jfieldID rejectFid = (*env)->GetFieldID(env, optionsCls, "reject", "Ljava/lang/Boolean;");
		jobject rejectObjectValue = (*env)->GetObjectField(env, options, rejectFid);
		if (rejectObjectValue != NULL) {
			jboolean reject = (*env)->CallBooleanMethod(env, rejectObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, reject);
			g_object_set_property(G_OBJECT(op), "reject", &gvalue);
			g_value_unset(&gvalue);
		}

		// optical
		jfieldID opticalFid = (*env)->GetFieldID(env, optionsCls, "optical", "Ljava/lang/Boolean;");
		jobject opticalObjectValue = (*env)->GetObjectField(env, options, opticalFid);
		if (opticalObjectValue != NULL) {
			jboolean optical = (*env)->CallBooleanMethod(env, opticalObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optical);
			g_object_set_property(G_OBJECT(op), "optical", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "mask_gaussian failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_maskGaussianBand(JNIEnv *env, jclass cls, jint width, jint height, jdouble frequencyCutoffX, jdouble frequencyCutoffY, jdouble radius, jdouble amplitudeCutoff, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("mask_gaussian_band");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// frequency-cutoff-x
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, frequencyCutoffX);
	g_object_set_property(G_OBJECT(op), "frequency-cutoff-x", &gvalue);
	g_value_unset(&gvalue);

	// frequency-cutoff-y
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, frequencyCutoffY);
	g_object_set_property(G_OBJECT(op), "frequency-cutoff-y", &gvalue);
	g_value_unset(&gvalue);

	// radius
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, radius);
	g_object_set_property(G_OBJECT(op), "radius", &gvalue);
	g_value_unset(&gvalue);

	// amplitude-cutoff
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, amplitudeCutoff);
	g_object_set_property(G_OBJECT(op), "amplitude-cutoff", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

		// nodc
		jfieldID nodcFid = (*env)->GetFieldID(env, optionsCls, "nodc", "Ljava/lang/Boolean;");
		jobject nodcObjectValue = (*env)->GetObjectField(env, options, nodcFid);
		if (nodcObjectValue != NULL) {
			jboolean nodc = (*env)->CallBooleanMethod(env, nodcObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, nodc);
			g_object_set_property(G_OBJECT(op), "nodc", &gvalue);
			g_value_unset(&gvalue);
		}

		// reject
		jfieldID rejectFid = (*env)->GetFieldID(env, optionsCls, "reject", "Ljava/lang/Boolean;");
		jobject rejectObjectValue = (*env)->GetObjectField(env, options, rejectFid);
		if (rejectObjectValue != NULL) {
			jboolean reject = (*env)->CallBooleanMethod(env, rejectObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, reject);
			g_object_set_property(G_OBJECT(op), "reject", &gvalue);
			g_value_unset(&gvalue);
		}

		// optical
		jfieldID opticalFid = (*env)->GetFieldID(env, optionsCls, "optical", "Ljava/lang/Boolean;");
		jobject opticalObjectValue = (*env)->GetObjectField(env, options, opticalFid);
		if (opticalObjectValue != NULL) {
			jboolean optical = (*env)->CallBooleanMethod(env, opticalObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optical);
			g_object_set_property(G_OBJECT(op), "optical", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "mask_gaussian_band failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_maskGaussianRing(JNIEnv *env, jclass cls, jint width, jint height, jdouble frequencyCutoff, jdouble amplitudeCutoff, jdouble ringwidth, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("mask_gaussian_ring");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// frequency-cutoff
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, frequencyCutoff);
	g_object_set_property(G_OBJECT(op), "frequency-cutoff", &gvalue);
	g_value_unset(&gvalue);

	// amplitude-cutoff
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, amplitudeCutoff);
	g_object_set_property(G_OBJECT(op), "amplitude-cutoff", &gvalue);
	g_value_unset(&gvalue);

	// ringwidth
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, ringwidth);
	g_object_set_property(G_OBJECT(op), "ringwidth", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

		// nodc
		jfieldID nodcFid = (*env)->GetFieldID(env, optionsCls, "nodc", "Ljava/lang/Boolean;");
		jobject nodcObjectValue = (*env)->GetObjectField(env, options, nodcFid);
		if (nodcObjectValue != NULL) {
			jboolean nodc = (*env)->CallBooleanMethod(env, nodcObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, nodc);
			g_object_set_property(G_OBJECT(op), "nodc", &gvalue);
			g_value_unset(&gvalue);
		}

		// reject
		jfieldID rejectFid = (*env)->GetFieldID(env, optionsCls, "reject", "Ljava/lang/Boolean;");
		jobject rejectObjectValue = (*env)->GetObjectField(env, options, rejectFid);
		if (rejectObjectValue != NULL) {
			jboolean reject = (*env)->CallBooleanMethod(env, rejectObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, reject);
			g_object_set_property(G_OBJECT(op), "reject", &gvalue);
			g_value_unset(&gvalue);
		}

		// optical
		jfieldID opticalFid = (*env)->GetFieldID(env, optionsCls, "optical", "Ljava/lang/Boolean;");
		jobject opticalObjectValue = (*env)->GetObjectField(env, options, opticalFid);
		if (opticalObjectValue != NULL) {
			jboolean optical = (*env)->CallBooleanMethod(env, opticalObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optical);
			g_object_set_property(G_OBJECT(op), "optical", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "mask_gaussian_ring failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_maskIdeal(JNIEnv *env, jclass cls, jint width, jint height, jdouble frequencyCutoff, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("mask_ideal");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// frequency-cutoff
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, frequencyCutoff);
	g_object_set_property(G_OBJECT(op), "frequency-cutoff", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

		// nodc
		jfieldID nodcFid = (*env)->GetFieldID(env, optionsCls, "nodc", "Ljava/lang/Boolean;");
		jobject nodcObjectValue = (*env)->GetObjectField(env, options, nodcFid);
		if (nodcObjectValue != NULL) {
			jboolean nodc = (*env)->CallBooleanMethod(env, nodcObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, nodc);
			g_object_set_property(G_OBJECT(op), "nodc", &gvalue);
			g_value_unset(&gvalue);
		}

		// reject
		jfieldID rejectFid = (*env)->GetFieldID(env, optionsCls, "reject", "Ljava/lang/Boolean;");
		jobject rejectObjectValue = (*env)->GetObjectField(env, options, rejectFid);
		if (rejectObjectValue != NULL) {
			jboolean reject = (*env)->CallBooleanMethod(env, rejectObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, reject);
			g_object_set_property(G_OBJECT(op), "reject", &gvalue);
			g_value_unset(&gvalue);
		}

		// optical
		jfieldID opticalFid = (*env)->GetFieldID(env, optionsCls, "optical", "Ljava/lang/Boolean;");
		jobject opticalObjectValue = (*env)->GetObjectField(env, options, opticalFid);
		if (opticalObjectValue != NULL) {
			jboolean optical = (*env)->CallBooleanMethod(env, opticalObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optical);
			g_object_set_property(G_OBJECT(op), "optical", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "mask_ideal failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_maskIdealBand(JNIEnv *env, jclass cls, jint width, jint height, jdouble frequencyCutoffX, jdouble frequencyCutoffY, jdouble radius, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("mask_ideal_band");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// frequency-cutoff-x
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, frequencyCutoffX);
	g_object_set_property(G_OBJECT(op), "frequency-cutoff-x", &gvalue);
	g_value_unset(&gvalue);

	// frequency-cutoff-y
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, frequencyCutoffY);
	g_object_set_property(G_OBJECT(op), "frequency-cutoff-y", &gvalue);
	g_value_unset(&gvalue);

	// radius
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, radius);
	g_object_set_property(G_OBJECT(op), "radius", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

		// nodc
		jfieldID nodcFid = (*env)->GetFieldID(env, optionsCls, "nodc", "Ljava/lang/Boolean;");
		jobject nodcObjectValue = (*env)->GetObjectField(env, options, nodcFid);
		if (nodcObjectValue != NULL) {
			jboolean nodc = (*env)->CallBooleanMethod(env, nodcObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, nodc);
			g_object_set_property(G_OBJECT(op), "nodc", &gvalue);
			g_value_unset(&gvalue);
		}

		// reject
		jfieldID rejectFid = (*env)->GetFieldID(env, optionsCls, "reject", "Ljava/lang/Boolean;");
		jobject rejectObjectValue = (*env)->GetObjectField(env, options, rejectFid);
		if (rejectObjectValue != NULL) {
			jboolean reject = (*env)->CallBooleanMethod(env, rejectObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, reject);
			g_object_set_property(G_OBJECT(op), "reject", &gvalue);
			g_value_unset(&gvalue);
		}

		// optical
		jfieldID opticalFid = (*env)->GetFieldID(env, optionsCls, "optical", "Ljava/lang/Boolean;");
		jobject opticalObjectValue = (*env)->GetObjectField(env, options, opticalFid);
		if (opticalObjectValue != NULL) {
			jboolean optical = (*env)->CallBooleanMethod(env, opticalObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optical);
			g_object_set_property(G_OBJECT(op), "optical", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "mask_ideal_band failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_maskIdealRing(JNIEnv *env, jclass cls, jint width, jint height, jdouble frequencyCutoff, jdouble ringwidth, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("mask_ideal_ring");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// frequency-cutoff
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, frequencyCutoff);
	g_object_set_property(G_OBJECT(op), "frequency-cutoff", &gvalue);
	g_value_unset(&gvalue);

	// ringwidth
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, ringwidth);
	g_object_set_property(G_OBJECT(op), "ringwidth", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

		// nodc
		jfieldID nodcFid = (*env)->GetFieldID(env, optionsCls, "nodc", "Ljava/lang/Boolean;");
		jobject nodcObjectValue = (*env)->GetObjectField(env, options, nodcFid);
		if (nodcObjectValue != NULL) {
			jboolean nodc = (*env)->CallBooleanMethod(env, nodcObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, nodc);
			g_object_set_property(G_OBJECT(op), "nodc", &gvalue);
			g_value_unset(&gvalue);
		}

		// reject
		jfieldID rejectFid = (*env)->GetFieldID(env, optionsCls, "reject", "Ljava/lang/Boolean;");
		jobject rejectObjectValue = (*env)->GetObjectField(env, options, rejectFid);
		if (rejectObjectValue != NULL) {
			jboolean reject = (*env)->CallBooleanMethod(env, rejectObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, reject);
			g_object_set_property(G_OBJECT(op), "reject", &gvalue);
			g_value_unset(&gvalue);
		}

		// optical
		jfieldID opticalFid = (*env)->GetFieldID(env, optionsCls, "optical", "Ljava/lang/Boolean;");
		jobject opticalObjectValue = (*env)->GetObjectField(env, options, opticalFid);
		if (opticalObjectValue != NULL) {
			jboolean optical = (*env)->CallBooleanMethod(env, opticalObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, optical);
			g_object_set_property(G_OBJECT(op), "optical", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "mask_ideal_ring failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_math(JNIEnv *env, jobject in, jobject math)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("math");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// math
	if (math != NULL) {
		jclass mathCls = (*env)->GetObjectClass(env, math);
		jfieldID mathValueFid = (*env)->GetFieldID(env, mathCls, "value", "I");
		jint mathValue = (*env)->GetIntField(env, math, mathValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, mathValue);
		g_object_set_property(G_OBJECT(op), "math", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "math failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_math2(JNIEnv *env, jobject left, jobject right, jobject math2)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("math2");

	// left
	if (left != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, left, handle_fid));
		g_object_set_property(G_OBJECT(op), "left", &gvalue);
		g_value_unset(&gvalue);
	}

	// right
	if (right != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, right, handle_fid));
		g_object_set_property(G_OBJECT(op), "right", &gvalue);
		g_value_unset(&gvalue);
	}

	// math2
	if (math2 != NULL) {
		jclass math2Cls = (*env)->GetObjectClass(env, math2);
		jfieldID math2ValueFid = (*env)->GetFieldID(env, math2Cls, "value", "I");
		jint math2Value = (*env)->GetIntField(env, math2, math2ValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, math2Value);
		g_object_set_property(G_OBJECT(op), "math2", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "math2 failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, left, handle_fid));
	(*env)->SetLongField(env, left, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_math2Const(JNIEnv *env, jobject in, jobject math2, jobject c)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("math2_const");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// math2
	if (math2 != NULL) {
		jclass math2Cls = (*env)->GetObjectClass(env, math2);
		jfieldID math2ValueFid = (*env)->GetFieldID(env, math2Cls, "value", "I");
		jint math2Value = (*env)->GetIntField(env, math2, math2ValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, math2Value);
		g_object_set_property(G_OBJECT(op), "math2", &gvalue);
		g_value_unset(&gvalue);
	}

	// c
	if (c != NULL) {
		jdouble *cElements = (*env)->GetDoubleArrayElements(env, c, NULL);
		jint cLength = (*env)->GetArrayLength(env, c);
		g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
		vips_value_set_array_double(&gvalue, cElements, cLength);
		(*env)->ReleaseDoubleArrayElements(env, c, cElements, 0);
		g_object_set_property(G_OBJECT(op), "c", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "math2_const failed");
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
Java_com_criteo_vips_AbstractVipsImage_matLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("matload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "matload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_matrixinvert(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("matrixinvert");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "matrixinvert failed");
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
Java_com_criteo_vips_AbstractVipsImage_matrixLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("matrixload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "matrixload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_matrixprint(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("matrixprint");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "matrixprint failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_matrixSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("matrixsave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "matrixsave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jdouble JNICALL
Java_com_criteo_vips_AbstractVipsImage_max(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("max");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// size
		jfieldID sizeFid = (*env)->GetFieldID(env, optionsCls, "size", "Ljava/lang/Integer;");
		jobject sizeObjectValue = (*env)->GetObjectField(env, options, sizeFid);
		if (sizeObjectValue != NULL) {
			jint size = (*env)->CallIntMethod(env, sizeObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, size);
			g_object_set_property(G_OBJECT(op), "size", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "max failed");
		return 0;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	jdouble out = g_value_get_double(&gvalue);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return out;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_measure(JNIEnv *env, jobject in, jint h, jint v, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("measure");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// h
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, h);
	g_object_set_property(G_OBJECT(op), "h", &gvalue);
	g_value_unset(&gvalue);

	// v
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, v);
	g_object_set_property(G_OBJECT(op), "v", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// left
		jfieldID leftFid = (*env)->GetFieldID(env, optionsCls, "left", "Ljava/lang/Integer;");
		jobject leftObjectValue = (*env)->GetObjectField(env, options, leftFid);
		if (leftObjectValue != NULL) {
			jint left = (*env)->CallIntMethod(env, leftObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, left);
			g_object_set_property(G_OBJECT(op), "left", &gvalue);
			g_value_unset(&gvalue);
		}

		// top
		jfieldID topFid = (*env)->GetFieldID(env, optionsCls, "top", "Ljava/lang/Integer;");
		jobject topObjectValue = (*env)->GetObjectField(env, options, topFid);
		if (topObjectValue != NULL) {
			jint top = (*env)->CallIntMethod(env, topObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, top);
			g_object_set_property(G_OBJECT(op), "top", &gvalue);
			g_value_unset(&gvalue);
		}

		// width
		jfieldID widthFid = (*env)->GetFieldID(env, optionsCls, "width", "Ljava/lang/Integer;");
		jobject widthObjectValue = (*env)->GetObjectField(env, options, widthFid);
		if (widthObjectValue != NULL) {
			jint width = (*env)->CallIntMethod(env, widthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, width);
			g_object_set_property(G_OBJECT(op), "width", &gvalue);
			g_value_unset(&gvalue);
		}

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

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "measure failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_merge(JNIEnv *env, jobject ref, jobject sec, jobject direction, jint dx, jint dy, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("merge");

	// ref
	if (ref != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, ref, handle_fid));
		g_object_set_property(G_OBJECT(op), "ref", &gvalue);
		g_value_unset(&gvalue);
	}

	// sec
	if (sec != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, sec, handle_fid));
		g_object_set_property(G_OBJECT(op), "sec", &gvalue);
		g_value_unset(&gvalue);
	}

	// direction
	if (direction != NULL) {
		jclass directionCls = (*env)->GetObjectClass(env, direction);
		jfieldID directionValueFid = (*env)->GetFieldID(env, directionCls, "value", "I");
		jint directionValue = (*env)->GetIntField(env, direction, directionValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, directionValue);
		g_object_set_property(G_OBJECT(op), "direction", &gvalue);
		g_value_unset(&gvalue);
	}

	// dx
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, dx);
	g_object_set_property(G_OBJECT(op), "dx", &gvalue);
	g_value_unset(&gvalue);

	// dy
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, dy);
	g_object_set_property(G_OBJECT(op), "dy", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// mblend
		jfieldID mblendFid = (*env)->GetFieldID(env, optionsCls, "mblend", "Ljava/lang/Integer;");
		jobject mblendObjectValue = (*env)->GetObjectField(env, options, mblendFid);
		if (mblendObjectValue != NULL) {
			jint mblend = (*env)->CallIntMethod(env, mblendObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, mblend);
			g_object_set_property(G_OBJECT(op), "mblend", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "merge failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, ref, handle_fid));
	(*env)->SetLongField(env, ref, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jdouble JNICALL
Java_com_criteo_vips_AbstractVipsImage_min(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("min");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// size
		jfieldID sizeFid = (*env)->GetFieldID(env, optionsCls, "size", "Ljava/lang/Integer;");
		jobject sizeObjectValue = (*env)->GetObjectField(env, options, sizeFid);
		if (sizeObjectValue != NULL) {
			jint size = (*env)->CallIntMethod(env, sizeObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, size);
			g_object_set_property(G_OBJECT(op), "size", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "min failed");
		return 0;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	jdouble out = g_value_get_double(&gvalue);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return out;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_morph(JNIEnv *env, jobject in, jobject mask, jobject morph)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("morph");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// mask
	if (mask != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, mask, handle_fid));
		g_object_set_property(G_OBJECT(op), "mask", &gvalue);
		g_value_unset(&gvalue);
	}

	// morph
	if (morph != NULL) {
		jclass morphCls = (*env)->GetObjectClass(env, morph);
		jfieldID morphValueFid = (*env)->GetFieldID(env, morphCls, "value", "I");
		jint morphValue = (*env)->GetIntField(env, morph, morphValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, morphValue);
		g_object_set_property(G_OBJECT(op), "morph", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "morph failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_mosaic(JNIEnv *env, jobject ref, jobject sec, jobject direction, jint xref, jint yref, jint xsec, jint ysec, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("mosaic");

	// ref
	if (ref != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, ref, handle_fid));
		g_object_set_property(G_OBJECT(op), "ref", &gvalue);
		g_value_unset(&gvalue);
	}

	// sec
	if (sec != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, sec, handle_fid));
		g_object_set_property(G_OBJECT(op), "sec", &gvalue);
		g_value_unset(&gvalue);
	}

	// direction
	if (direction != NULL) {
		jclass directionCls = (*env)->GetObjectClass(env, direction);
		jfieldID directionValueFid = (*env)->GetFieldID(env, directionCls, "value", "I");
		jint directionValue = (*env)->GetIntField(env, direction, directionValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, directionValue);
		g_object_set_property(G_OBJECT(op), "direction", &gvalue);
		g_value_unset(&gvalue);
	}

	// xref
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, xref);
	g_object_set_property(G_OBJECT(op), "xref", &gvalue);
	g_value_unset(&gvalue);

	// yref
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, yref);
	g_object_set_property(G_OBJECT(op), "yref", &gvalue);
	g_value_unset(&gvalue);

	// xsec
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, xsec);
	g_object_set_property(G_OBJECT(op), "xsec", &gvalue);
	g_value_unset(&gvalue);

	// ysec
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, ysec);
	g_object_set_property(G_OBJECT(op), "ysec", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// hwindow
		jfieldID hwindowFid = (*env)->GetFieldID(env, optionsCls, "hwindow", "Ljava/lang/Integer;");
		jobject hwindowObjectValue = (*env)->GetObjectField(env, options, hwindowFid);
		if (hwindowObjectValue != NULL) {
			jint hwindow = (*env)->CallIntMethod(env, hwindowObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, hwindow);
			g_object_set_property(G_OBJECT(op), "hwindow", &gvalue);
			g_value_unset(&gvalue);
		}

		// harea
		jfieldID hareaFid = (*env)->GetFieldID(env, optionsCls, "harea", "Ljava/lang/Integer;");
		jobject hareaObjectValue = (*env)->GetObjectField(env, options, hareaFid);
		if (hareaObjectValue != NULL) {
			jint harea = (*env)->CallIntMethod(env, hareaObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, harea);
			g_object_set_property(G_OBJECT(op), "harea", &gvalue);
			g_value_unset(&gvalue);
		}

		// mblend
		jfieldID mblendFid = (*env)->GetFieldID(env, optionsCls, "mblend", "Ljava/lang/Integer;");
		jobject mblendObjectValue = (*env)->GetObjectField(env, options, mblendFid);
		if (mblendObjectValue != NULL) {
			jint mblend = (*env)->CallIntMethod(env, mblendObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, mblend);
			g_object_set_property(G_OBJECT(op), "mblend", &gvalue);
			g_value_unset(&gvalue);
		}

		// bandno
		jfieldID bandnoFid = (*env)->GetFieldID(env, optionsCls, "bandno", "Ljava/lang/Integer;");
		jobject bandnoObjectValue = (*env)->GetObjectField(env, options, bandnoFid);
		if (bandnoObjectValue != NULL) {
			jint bandno = (*env)->CallIntMethod(env, bandnoObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, bandno);
			g_object_set_property(G_OBJECT(op), "bandno", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "mosaic failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, ref, handle_fid));
	(*env)->SetLongField(env, ref, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_msb(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("msb");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// band
		jfieldID bandFid = (*env)->GetFieldID(env, optionsCls, "band", "Ljava/lang/Integer;");
		jobject bandObjectValue = (*env)->GetObjectField(env, options, bandFid);
		if (bandObjectValue != NULL) {
			jint band = (*env)->CallIntMethod(env, bandObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, band);
			g_object_set_property(G_OBJECT(op), "band", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "msb failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_multiply(JNIEnv *env, jobject left, jobject right)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("multiply");

	// left
	if (left != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, left, handle_fid));
		g_object_set_property(G_OBJECT(op), "left", &gvalue);
		g_value_unset(&gvalue);
	}

	// right
	if (right != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, right, handle_fid));
		g_object_set_property(G_OBJECT(op), "right", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "multiply failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, left, handle_fid));
	(*env)->SetLongField(env, left, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_openexrLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("openexrload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "openexrload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_openslideLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("openslideload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// attach-associated
		jfieldID attachAssociatedFid = (*env)->GetFieldID(env, optionsCls, "attachAssociated", "Ljava/lang/Boolean;");
		jobject attachAssociatedObjectValue = (*env)->GetObjectField(env, options, attachAssociatedFid);
		if (attachAssociatedObjectValue != NULL) {
			jboolean attachAssociated = (*env)->CallBooleanMethod(env, attachAssociatedObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, attachAssociated);
			g_object_set_property(G_OBJECT(op), "attach-associated", &gvalue);
			g_value_unset(&gvalue);
		}

		// level
		jfieldID levelFid = (*env)->GetFieldID(env, optionsCls, "level", "Ljava/lang/Integer;");
		jobject levelObjectValue = (*env)->GetObjectField(env, options, levelFid);
		if (levelObjectValue != NULL) {
			jint level = (*env)->CallIntMethod(env, levelObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, level);
			g_object_set_property(G_OBJECT(op), "level", &gvalue);
			g_value_unset(&gvalue);
		}

		// autocrop
		jfieldID autocropFid = (*env)->GetFieldID(env, optionsCls, "autocrop", "Ljava/lang/Boolean;");
		jobject autocropObjectValue = (*env)->GetObjectField(env, options, autocropFid);
		if (autocropObjectValue != NULL) {
			jboolean autocrop = (*env)->CallBooleanMethod(env, autocropObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, autocrop);
			g_object_set_property(G_OBJECT(op), "autocrop", &gvalue);
			g_value_unset(&gvalue);
		}

		// associated
		jfieldID associatedFid = (*env)->GetFieldID(env, optionsCls, "associated", "Ljava/lang/String;");
		jstring associated = (jstring) (*env)->GetObjectField(env, options, associatedFid);
		if (associated != NULL) {
			const char *associatedChars = (*env)->GetStringUTFChars(env, associated, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, associatedChars);
			(*env)->ReleaseStringUTFChars(env, associated, associatedChars);
			g_object_set_property(G_OBJECT(op), "associated", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "openslideload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_pdfLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("pdfload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// n
		jfieldID nFid = (*env)->GetFieldID(env, optionsCls, "n", "Ljava/lang/Integer;");
		jobject nObjectValue = (*env)->GetObjectField(env, options, nFid);
		if (nObjectValue != NULL) {
			jint n = (*env)->CallIntMethod(env, nObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, n);
			g_object_set_property(G_OBJECT(op), "n", &gvalue);
			g_value_unset(&gvalue);
		}

		// dpi
		jfieldID dpiFid = (*env)->GetFieldID(env, optionsCls, "dpi", "Ljava/lang/Double;");
		jobject dpiObjectValue = (*env)->GetObjectField(env, options, dpiFid);
		if (dpiObjectValue != NULL) {
			jdouble dpi = (*env)->CallDoubleMethod(env, dpiObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, dpi);
			g_object_set_property(G_OBJECT(op), "dpi", &gvalue);
			g_value_unset(&gvalue);
		}

		// scale
		jfieldID scaleFid = (*env)->GetFieldID(env, optionsCls, "scale", "Ljava/lang/Double;");
		jobject scaleObjectValue = (*env)->GetObjectField(env, options, scaleFid);
		if (scaleObjectValue != NULL) {
			jdouble scale = (*env)->CallDoubleMethod(env, scaleObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, scale);
			g_object_set_property(G_OBJECT(op), "scale", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "pdfload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_pdfLoadBuffer(JNIEnv *env, jclass cls, jbyteArray buffer, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("pdfload_buffer");

	// buffer
	if (buffer != NULL) {
		jint bufferLength = (*env)->GetArrayLength(env, buffer);
		size_t bufferSize = bufferLength * sizeof(jbyte);
		void *bufferData = vips_tracked_malloc(bufferSize);
		if (bufferData == NULL) {
			throwVipsException(env, "Failed to allocate memory for buffer");
		}
		(*env)->GetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
		g_value_init(&gvalue, VIPS_TYPE_BLOB);
		vips_value_set_blob_free(&gvalue, bufferData, bufferSize);
		g_object_set_property(G_OBJECT(op), "buffer", &gvalue);
		g_value_unset(&gvalue);
	
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// n
		jfieldID nFid = (*env)->GetFieldID(env, optionsCls, "n", "Ljava/lang/Integer;");
		jobject nObjectValue = (*env)->GetObjectField(env, options, nFid);
		if (nObjectValue != NULL) {
			jint n = (*env)->CallIntMethod(env, nObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, n);
			g_object_set_property(G_OBJECT(op), "n", &gvalue);
			g_value_unset(&gvalue);
		}

		// dpi
		jfieldID dpiFid = (*env)->GetFieldID(env, optionsCls, "dpi", "Ljava/lang/Double;");
		jobject dpiObjectValue = (*env)->GetObjectField(env, options, dpiFid);
		if (dpiObjectValue != NULL) {
			jdouble dpi = (*env)->CallDoubleMethod(env, dpiObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, dpi);
			g_object_set_property(G_OBJECT(op), "dpi", &gvalue);
			g_value_unset(&gvalue);
		}

		// scale
		jfieldID scaleFid = (*env)->GetFieldID(env, optionsCls, "scale", "Ljava/lang/Double;");
		jobject scaleObjectValue = (*env)->GetObjectField(env, options, scaleFid);
		if (scaleObjectValue != NULL) {
			jdouble scale = (*env)->CallDoubleMethod(env, scaleObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, scale);
			g_object_set_property(G_OBJECT(op), "scale", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "pdfload_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jint JNICALL
Java_com_criteo_vips_AbstractVipsImage_percent(JNIEnv *env, jobject in, jdouble percent)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("percent");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// percent
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, percent);
	g_object_set_property(G_OBJECT(op), "percent", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "percent failed");
		return 0;
	}
	g_object_unref(op);
	op = new_op;

	// threshold
	g_value_init(&gvalue, G_TYPE_INT);
	g_object_get_property(G_OBJECT(op), "threshold", &gvalue);
	jint threshold = g_value_get_int(&gvalue);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return threshold;
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_perlin(JNIEnv *env, jclass cls, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("perlin");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// cell-size
		jfieldID cellSizeFid = (*env)->GetFieldID(env, optionsCls, "cellSize", "Ljava/lang/Integer;");
		jobject cellSizeObjectValue = (*env)->GetObjectField(env, options, cellSizeFid);
		if (cellSizeObjectValue != NULL) {
			jint cellSize = (*env)->CallIntMethod(env, cellSizeObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, cellSize);
			g_object_set_property(G_OBJECT(op), "cell-size", &gvalue);
			g_value_unset(&gvalue);
		}

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

		// seed
		jfieldID seedFid = (*env)->GetFieldID(env, optionsCls, "seed", "Ljava/lang/Integer;");
		jobject seedObjectValue = (*env)->GetObjectField(env, options, seedFid);
		if (seedObjectValue != NULL) {
			jint seed = (*env)->CallIntMethod(env, seedObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, seed);
			g_object_set_property(G_OBJECT(op), "seed", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "perlin failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_phasecor(JNIEnv *env, jobject in, jobject in2)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("phasecor");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// in2
	if (in2 != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in2, handle_fid));
		g_object_set_property(G_OBJECT(op), "in2", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "phasecor failed");
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
Java_com_criteo_vips_AbstractVipsImage_pngLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("pngload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// unlimited
		jfieldID unlimitedFid = (*env)->GetFieldID(env, optionsCls, "unlimited", "Ljava/lang/Boolean;");
		jobject unlimitedObjectValue = (*env)->GetObjectField(env, options, unlimitedFid);
		if (unlimitedObjectValue != NULL) {
			jboolean unlimited = (*env)->CallBooleanMethod(env, unlimitedObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, unlimited);
			g_object_set_property(G_OBJECT(op), "unlimited", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "pngload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_pngLoadBuffer(JNIEnv *env, jclass cls, jbyteArray buffer, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("pngload_buffer");

	// buffer
	if (buffer != NULL) {
		jint bufferLength = (*env)->GetArrayLength(env, buffer);
		size_t bufferSize = bufferLength * sizeof(jbyte);
		void *bufferData = vips_tracked_malloc(bufferSize);
		if (bufferData == NULL) {
			throwVipsException(env, "Failed to allocate memory for buffer");
		}
		(*env)->GetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
		g_value_init(&gvalue, VIPS_TYPE_BLOB);
		vips_value_set_blob_free(&gvalue, bufferData, bufferSize);
		g_object_set_property(G_OBJECT(op), "buffer", &gvalue);
		g_value_unset(&gvalue);
	
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// unlimited
		jfieldID unlimitedFid = (*env)->GetFieldID(env, optionsCls, "unlimited", "Ljava/lang/Boolean;");
		jobject unlimitedObjectValue = (*env)->GetObjectField(env, options, unlimitedFid);
		if (unlimitedObjectValue != NULL) {
			jboolean unlimited = (*env)->CallBooleanMethod(env, unlimitedObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, unlimited);
			g_object_set_property(G_OBJECT(op), "unlimited", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "pngload_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_pngSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("pngsave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// compression
		jfieldID compressionFid = (*env)->GetFieldID(env, optionsCls, "compression", "Ljava/lang/Integer;");
		jobject compressionObjectValue = (*env)->GetObjectField(env, options, compressionFid);
		if (compressionObjectValue != NULL) {
			jint compression = (*env)->CallIntMethod(env, compressionObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, compression);
			g_object_set_property(G_OBJECT(op), "compression", &gvalue);
			g_value_unset(&gvalue);
		}

		// interlace
		jfieldID interlaceFid = (*env)->GetFieldID(env, optionsCls, "interlace", "Ljava/lang/Boolean;");
		jobject interlaceObjectValue = (*env)->GetObjectField(env, options, interlaceFid);
		if (interlaceObjectValue != NULL) {
			jboolean interlace = (*env)->CallBooleanMethod(env, interlaceObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, interlace);
			g_object_set_property(G_OBJECT(op), "interlace", &gvalue);
			g_value_unset(&gvalue);
		}

		// profile
		jfieldID profileFid = (*env)->GetFieldID(env, optionsCls, "profile", "Ljava/lang/String;");
		jstring profile = (jstring) (*env)->GetObjectField(env, options, profileFid);
		if (profile != NULL) {
			const char *profileChars = (*env)->GetStringUTFChars(env, profile, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, profileChars);
			(*env)->ReleaseStringUTFChars(env, profile, profileChars);
			g_object_set_property(G_OBJECT(op), "profile", &gvalue);
			g_value_unset(&gvalue);
		}

		// filter
		jfieldID filterFid = (*env)->GetFieldID(env, optionsCls, "filter", "Lcom/criteo/vips/enums/VipsForeignPngFilter;");
		jobject filter = (*env)->GetObjectField(env, options, filterFid);
		if (filter != NULL) {
			jclass filterCls = (*env)->GetObjectClass(env, filter);
			jfieldID filterValueFid = (*env)->GetFieldID(env, filterCls, "value", "I");
			jint filterValue = (*env)->GetIntField(env, filter, filterValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, filterValue);
			g_object_set_property(G_OBJECT(op), "filter", &gvalue);
			g_value_unset(&gvalue);
		}

		// palette
		jfieldID paletteFid = (*env)->GetFieldID(env, optionsCls, "palette", "Ljava/lang/Boolean;");
		jobject paletteObjectValue = (*env)->GetObjectField(env, options, paletteFid);
		if (paletteObjectValue != NULL) {
			jboolean palette = (*env)->CallBooleanMethod(env, paletteObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, palette);
			g_object_set_property(G_OBJECT(op), "palette", &gvalue);
			g_value_unset(&gvalue);
		}

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// dither
		jfieldID ditherFid = (*env)->GetFieldID(env, optionsCls, "dither", "Ljava/lang/Double;");
		jobject ditherObjectValue = (*env)->GetObjectField(env, options, ditherFid);
		if (ditherObjectValue != NULL) {
			jdouble dither = (*env)->CallDoubleMethod(env, ditherObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, dither);
			g_object_set_property(G_OBJECT(op), "dither", &gvalue);
			g_value_unset(&gvalue);
		}

		// bitdepth
		jfieldID bitdepthFid = (*env)->GetFieldID(env, optionsCls, "bitdepth", "Ljava/lang/Integer;");
		jobject bitdepthObjectValue = (*env)->GetObjectField(env, options, bitdepthFid);
		if (bitdepthObjectValue != NULL) {
			jint bitdepth = (*env)->CallIntMethod(env, bitdepthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, bitdepth);
			g_object_set_property(G_OBJECT(op), "bitdepth", &gvalue);
			g_value_unset(&gvalue);
		}

		// effort
		jfieldID effortFid = (*env)->GetFieldID(env, optionsCls, "effort", "Ljava/lang/Integer;");
		jobject effortObjectValue = (*env)->GetObjectField(env, options, effortFid);
		if (effortObjectValue != NULL) {
			jint effort = (*env)->CallIntMethod(env, effortObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, effort);
			g_object_set_property(G_OBJECT(op), "effort", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "pngsave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_AbstractVipsImage_pngSaveBuffer(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("pngsave_buffer");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// compression
		jfieldID compressionFid = (*env)->GetFieldID(env, optionsCls, "compression", "Ljava/lang/Integer;");
		jobject compressionObjectValue = (*env)->GetObjectField(env, options, compressionFid);
		if (compressionObjectValue != NULL) {
			jint compression = (*env)->CallIntMethod(env, compressionObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, compression);
			g_object_set_property(G_OBJECT(op), "compression", &gvalue);
			g_value_unset(&gvalue);
		}

		// interlace
		jfieldID interlaceFid = (*env)->GetFieldID(env, optionsCls, "interlace", "Ljava/lang/Boolean;");
		jobject interlaceObjectValue = (*env)->GetObjectField(env, options, interlaceFid);
		if (interlaceObjectValue != NULL) {
			jboolean interlace = (*env)->CallBooleanMethod(env, interlaceObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, interlace);
			g_object_set_property(G_OBJECT(op), "interlace", &gvalue);
			g_value_unset(&gvalue);
		}

		// profile
		jfieldID profileFid = (*env)->GetFieldID(env, optionsCls, "profile", "Ljava/lang/String;");
		jstring profile = (jstring) (*env)->GetObjectField(env, options, profileFid);
		if (profile != NULL) {
			const char *profileChars = (*env)->GetStringUTFChars(env, profile, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, profileChars);
			(*env)->ReleaseStringUTFChars(env, profile, profileChars);
			g_object_set_property(G_OBJECT(op), "profile", &gvalue);
			g_value_unset(&gvalue);
		}

		// filter
		jfieldID filterFid = (*env)->GetFieldID(env, optionsCls, "filter", "Lcom/criteo/vips/enums/VipsForeignPngFilter;");
		jobject filter = (*env)->GetObjectField(env, options, filterFid);
		if (filter != NULL) {
			jclass filterCls = (*env)->GetObjectClass(env, filter);
			jfieldID filterValueFid = (*env)->GetFieldID(env, filterCls, "value", "I");
			jint filterValue = (*env)->GetIntField(env, filter, filterValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, filterValue);
			g_object_set_property(G_OBJECT(op), "filter", &gvalue);
			g_value_unset(&gvalue);
		}

		// palette
		jfieldID paletteFid = (*env)->GetFieldID(env, optionsCls, "palette", "Ljava/lang/Boolean;");
		jobject paletteObjectValue = (*env)->GetObjectField(env, options, paletteFid);
		if (paletteObjectValue != NULL) {
			jboolean palette = (*env)->CallBooleanMethod(env, paletteObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, palette);
			g_object_set_property(G_OBJECT(op), "palette", &gvalue);
			g_value_unset(&gvalue);
		}

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// dither
		jfieldID ditherFid = (*env)->GetFieldID(env, optionsCls, "dither", "Ljava/lang/Double;");
		jobject ditherObjectValue = (*env)->GetObjectField(env, options, ditherFid);
		if (ditherObjectValue != NULL) {
			jdouble dither = (*env)->CallDoubleMethod(env, ditherObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, dither);
			g_object_set_property(G_OBJECT(op), "dither", &gvalue);
			g_value_unset(&gvalue);
		}

		// bitdepth
		jfieldID bitdepthFid = (*env)->GetFieldID(env, optionsCls, "bitdepth", "Ljava/lang/Integer;");
		jobject bitdepthObjectValue = (*env)->GetObjectField(env, options, bitdepthFid);
		if (bitdepthObjectValue != NULL) {
			jint bitdepth = (*env)->CallIntMethod(env, bitdepthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, bitdepth);
			g_object_set_property(G_OBJECT(op), "bitdepth", &gvalue);
			g_value_unset(&gvalue);
		}

		// effort
		jfieldID effortFid = (*env)->GetFieldID(env, optionsCls, "effort", "Ljava/lang/Integer;");
		jobject effortObjectValue = (*env)->GetObjectField(env, options, effortFid);
		if (effortObjectValue != NULL) {
			jint effort = (*env)->CallIntMethod(env, effortObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, effort);
			g_object_set_property(G_OBJECT(op), "effort", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "pngsave_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// buffer
	g_value_init(&gvalue, VIPS_TYPE_BLOB);
	g_object_get_property(G_OBJECT(op), "buffer", &gvalue);
	size_t bufferSize = 0;
	void *bufferData = vips_value_get_blob(&gvalue, &bufferSize);
	jint bufferLength = bufferSize / sizeof(jbyte);
	jbyteArray buffer = (*env)->NewByteArray(env, bufferLength);
	(*env)->SetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return buffer;
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_ppmLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("ppmload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "ppmload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_ppmSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("ppmsave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// format
		jfieldID formatFid = (*env)->GetFieldID(env, optionsCls, "format", "Lcom/criteo/vips/enums/VipsForeignPpmFormat;");
		jobject format = (*env)->GetObjectField(env, options, formatFid);
		if (format != NULL) {
			jclass formatCls = (*env)->GetObjectClass(env, format);
			jfieldID formatValueFid = (*env)->GetFieldID(env, formatCls, "value", "I");
			jint formatValue = (*env)->GetIntField(env, format, formatValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, formatValue);
			g_object_set_property(G_OBJECT(op), "format", &gvalue);
			g_value_unset(&gvalue);
		}

		// ascii
		jfieldID asciiFid = (*env)->GetFieldID(env, optionsCls, "ascii", "Ljava/lang/Boolean;");
		jobject asciiObjectValue = (*env)->GetObjectField(env, options, asciiFid);
		if (asciiObjectValue != NULL) {
			jboolean ascii = (*env)->CallBooleanMethod(env, asciiObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, ascii);
			g_object_set_property(G_OBJECT(op), "ascii", &gvalue);
			g_value_unset(&gvalue);
		}

		// bitdepth
		jfieldID bitdepthFid = (*env)->GetFieldID(env, optionsCls, "bitdepth", "Ljava/lang/Integer;");
		jobject bitdepthObjectValue = (*env)->GetObjectField(env, options, bitdepthFid);
		if (bitdepthObjectValue != NULL) {
			jint bitdepth = (*env)->CallIntMethod(env, bitdepthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, bitdepth);
			g_object_set_property(G_OBJECT(op), "bitdepth", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "ppmsave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_premultiply(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("premultiply");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// max-alpha
		jfieldID maxAlphaFid = (*env)->GetFieldID(env, optionsCls, "maxAlpha", "Ljava/lang/Double;");
		jobject maxAlphaObjectValue = (*env)->GetObjectField(env, options, maxAlphaFid);
		if (maxAlphaObjectValue != NULL) {
			jdouble maxAlpha = (*env)->CallDoubleMethod(env, maxAlphaObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, maxAlpha);
			g_object_set_property(G_OBJECT(op), "max-alpha", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "premultiply failed");
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
Java_com_criteo_vips_AbstractVipsImage_profile(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("profile");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "profile failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// Mutating image result
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "columns", &gvalue);
	VipsImage *_columns = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(_columns); 
	g_value_unset(&gvalue);
	g_object_unref((VipsImage *) (*env)->GetLongField(env, in, handle_fid));
	(*env)->SetLongField(env, in, handle_fid, (jlong) _columns);
	// rows
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "rows", &gvalue);
	VipsImage *rows = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(rows);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, imageClass, ctor_mid, (jlong) rows);
}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_AbstractVipsImage_profileLoad(JNIEnv *env, jclass cls, jstring name)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("profile_load");

	// name
	if (name != NULL) {
		const char *nameChars = (*env)->GetStringUTFChars(env, name, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, nameChars);
		(*env)->ReleaseStringUTFChars(env, name, nameChars);
		g_object_set_property(G_OBJECT(op), "name", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "profile_load failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// profile
	g_value_init(&gvalue, VIPS_TYPE_BLOB);
	g_object_get_property(G_OBJECT(op), "profile", &gvalue);
	size_t profileSize = 0;
	void *profileData = vips_value_get_blob(&gvalue, &profileSize);
	jint profileLength = profileSize / sizeof(jbyte);
	jbyteArray profile = (*env)->NewByteArray(env, profileLength);
	(*env)->SetByteArrayRegion(env, profile, 0, profileLength, profileData);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return profile;
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_project(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("project");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "project failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// Mutating image result
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "columns", &gvalue);
	VipsImage *_columns = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(_columns); 
	g_value_unset(&gvalue);
	g_object_unref((VipsImage *) (*env)->GetLongField(env, in, handle_fid));
	(*env)->SetLongField(env, in, handle_fid, (jlong) _columns);
	// rows
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "rows", &gvalue);
	VipsImage *rows = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(rows);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, imageClass, ctor_mid, (jlong) rows);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_rad2float(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("rad2float");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "rad2float failed");
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
Java_com_criteo_vips_AbstractVipsImage_radLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("radload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "radload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_radLoadBuffer(JNIEnv *env, jclass cls, jbyteArray buffer, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("radload_buffer");

	// buffer
	if (buffer != NULL) {
		jint bufferLength = (*env)->GetArrayLength(env, buffer);
		size_t bufferSize = bufferLength * sizeof(jbyte);
		void *bufferData = vips_tracked_malloc(bufferSize);
		if (bufferData == NULL) {
			throwVipsException(env, "Failed to allocate memory for buffer");
		}
		(*env)->GetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
		g_value_init(&gvalue, VIPS_TYPE_BLOB);
		vips_value_set_blob_free(&gvalue, bufferData, bufferSize);
		g_object_set_property(G_OBJECT(op), "buffer", &gvalue);
		g_value_unset(&gvalue);
	
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "radload_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_radSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("radsave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "radsave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_AbstractVipsImage_radSaveBuffer(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("radsave_buffer");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "radsave_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// buffer
	g_value_init(&gvalue, VIPS_TYPE_BLOB);
	g_object_get_property(G_OBJECT(op), "buffer", &gvalue);
	size_t bufferSize = 0;
	void *bufferData = vips_value_get_blob(&gvalue, &bufferSize);
	jint bufferLength = bufferSize / sizeof(jbyte);
	jbyteArray buffer = (*env)->NewByteArray(env, bufferLength);
	(*env)->SetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return buffer;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_rank(JNIEnv *env, jobject in, jint width, jint height, jint index)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("rank");

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

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// index
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, index);
	g_object_set_property(G_OBJECT(op), "index", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "rank failed");
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
Java_com_criteo_vips_AbstractVipsImage_rawLoad(JNIEnv *env, jclass cls, jstring filename, jint width, jint height, jint bands, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("rawload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// bands
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, bands);
	g_object_set_property(G_OBJECT(op), "bands", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// offset
		jfieldID offsetFid = (*env)->GetFieldID(env, optionsCls, "offset", "Ljava/lang/Long;");
		jobject offsetObjectValue = (*env)->GetObjectField(env, options, offsetFid);
		if (offsetObjectValue != NULL) {
			jlong offset = (*env)->CallLongMethod(env, offsetObjectValue, longValue_mid);
			g_value_init(&gvalue, G_TYPE_UINT64);
			g_value_set_uint64(&gvalue, offset);
			g_object_set_property(G_OBJECT(op), "offset", &gvalue);
			g_value_unset(&gvalue);
		}

		// format
		jfieldID formatFid = (*env)->GetFieldID(env, optionsCls, "format", "Lcom/criteo/vips/enums/VipsBandFormat;");
		jobject format = (*env)->GetObjectField(env, options, formatFid);
		if (format != NULL) {
			jclass formatCls = (*env)->GetObjectClass(env, format);
			jfieldID formatValueFid = (*env)->GetFieldID(env, formatCls, "value", "I");
			jint formatValue = (*env)->GetIntField(env, format, formatValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, formatValue);
			g_object_set_property(G_OBJECT(op), "format", &gvalue);
			g_value_unset(&gvalue);
		}

		// interpretation
		jfieldID interpretationFid = (*env)->GetFieldID(env, optionsCls, "interpretation", "Lcom/criteo/vips/enums/VipsInterpretation;");
		jobject interpretation = (*env)->GetObjectField(env, options, interpretationFid);
		if (interpretation != NULL) {
			jclass interpretationCls = (*env)->GetObjectClass(env, interpretation);
			jfieldID interpretationValueFid = (*env)->GetFieldID(env, interpretationCls, "value", "I");
			jint interpretationValue = (*env)->GetIntField(env, interpretation, interpretationValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, interpretationValue);
			g_object_set_property(G_OBJECT(op), "interpretation", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "rawload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_rawSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("rawsave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "rawsave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_rawSaveFd(JNIEnv *env, jobject in, jint fd, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("rawsave_fd");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// fd
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, fd);
	g_object_set_property(G_OBJECT(op), "fd", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "rawsave_fd failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_recomb(JNIEnv *env, jobject in, jobject m)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("recomb");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// m
	if (m != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, m, handle_fid));
		g_object_set_property(G_OBJECT(op), "m", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "recomb failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_reduce(JNIEnv *env, jobject in, jdouble hshrink, jdouble vshrink, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("reduce");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// hshrink
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, hshrink);
	g_object_set_property(G_OBJECT(op), "hshrink", &gvalue);
	g_value_unset(&gvalue);

	// vshrink
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, vshrink);
	g_object_set_property(G_OBJECT(op), "vshrink", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// kernel
		jfieldID kernelFid = (*env)->GetFieldID(env, optionsCls, "kernel", "Lcom/criteo/vips/enums/VipsKernel;");
		jobject kernel = (*env)->GetObjectField(env, options, kernelFid);
		if (kernel != NULL) {
			jclass kernelCls = (*env)->GetObjectClass(env, kernel);
			jfieldID kernelValueFid = (*env)->GetFieldID(env, kernelCls, "value", "I");
			jint kernelValue = (*env)->GetIntField(env, kernel, kernelValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, kernelValue);
			g_object_set_property(G_OBJECT(op), "kernel", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "reduce failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_reduceh(JNIEnv *env, jobject in, jdouble hshrink, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("reduceh");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// hshrink
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, hshrink);
	g_object_set_property(G_OBJECT(op), "hshrink", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// kernel
		jfieldID kernelFid = (*env)->GetFieldID(env, optionsCls, "kernel", "Lcom/criteo/vips/enums/VipsKernel;");
		jobject kernel = (*env)->GetObjectField(env, options, kernelFid);
		if (kernel != NULL) {
			jclass kernelCls = (*env)->GetObjectClass(env, kernel);
			jfieldID kernelValueFid = (*env)->GetFieldID(env, kernelCls, "value", "I");
			jint kernelValue = (*env)->GetIntField(env, kernel, kernelValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, kernelValue);
			g_object_set_property(G_OBJECT(op), "kernel", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "reduceh failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_reducev(JNIEnv *env, jobject in, jdouble vshrink, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("reducev");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// vshrink
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, vshrink);
	g_object_set_property(G_OBJECT(op), "vshrink", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// kernel
		jfieldID kernelFid = (*env)->GetFieldID(env, optionsCls, "kernel", "Lcom/criteo/vips/enums/VipsKernel;");
		jobject kernel = (*env)->GetObjectField(env, options, kernelFid);
		if (kernel != NULL) {
			jclass kernelCls = (*env)->GetObjectClass(env, kernel);
			jfieldID kernelValueFid = (*env)->GetFieldID(env, kernelCls, "value", "I");
			jint kernelValue = (*env)->GetIntField(env, kernel, kernelValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, kernelValue);
			g_object_set_property(G_OBJECT(op), "kernel", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "reducev failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_relational(JNIEnv *env, jobject left, jobject right, jobject relational)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("relational");

	// left
	if (left != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, left, handle_fid));
		g_object_set_property(G_OBJECT(op), "left", &gvalue);
		g_value_unset(&gvalue);
	}

	// right
	if (right != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, right, handle_fid));
		g_object_set_property(G_OBJECT(op), "right", &gvalue);
		g_value_unset(&gvalue);
	}

	// relational
	if (relational != NULL) {
		jclass relationalCls = (*env)->GetObjectClass(env, relational);
		jfieldID relationalValueFid = (*env)->GetFieldID(env, relationalCls, "value", "I");
		jint relationalValue = (*env)->GetIntField(env, relational, relationalValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, relationalValue);
		g_object_set_property(G_OBJECT(op), "relational", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "relational failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, left, handle_fid));
	(*env)->SetLongField(env, left, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_relationalConst(JNIEnv *env, jobject in, jobject relational, jobject c)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("relational_const");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// relational
	if (relational != NULL) {
		jclass relationalCls = (*env)->GetObjectClass(env, relational);
		jfieldID relationalValueFid = (*env)->GetFieldID(env, relationalCls, "value", "I");
		jint relationalValue = (*env)->GetIntField(env, relational, relationalValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, relationalValue);
		g_object_set_property(G_OBJECT(op), "relational", &gvalue);
		g_value_unset(&gvalue);
	}

	// c
	if (c != NULL) {
		jdouble *cElements = (*env)->GetDoubleArrayElements(env, c, NULL);
		jint cLength = (*env)->GetArrayLength(env, c);
		g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
		vips_value_set_array_double(&gvalue, cElements, cLength);
		(*env)->ReleaseDoubleArrayElements(env, c, cElements, 0);
		g_object_set_property(G_OBJECT(op), "c", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "relational_const failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_remainder(JNIEnv *env, jobject left, jobject right)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("remainder");

	// left
	if (left != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, left, handle_fid));
		g_object_set_property(G_OBJECT(op), "left", &gvalue);
		g_value_unset(&gvalue);
	}

	// right
	if (right != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, right, handle_fid));
		g_object_set_property(G_OBJECT(op), "right", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "remainder failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, left, handle_fid));
	(*env)->SetLongField(env, left, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_remainderConst(JNIEnv *env, jobject in, jobject c)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("remainder_const");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// c
	if (c != NULL) {
		jdouble *cElements = (*env)->GetDoubleArrayElements(env, c, NULL);
		jint cLength = (*env)->GetArrayLength(env, c);
		g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
		vips_value_set_array_double(&gvalue, cElements, cLength);
		(*env)->ReleaseDoubleArrayElements(env, c, cElements, 0);
		g_object_set_property(G_OBJECT(op), "c", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "remainder_const failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_replicate(JNIEnv *env, jobject in, jint across, jint down)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("replicate");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// across
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, across);
	g_object_set_property(G_OBJECT(op), "across", &gvalue);
	g_value_unset(&gvalue);

	// down
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, down);
	g_object_set_property(G_OBJECT(op), "down", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "replicate failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_resize(JNIEnv *env, jobject in, jdouble scale, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("resize");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// scale
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, scale);
	g_object_set_property(G_OBJECT(op), "scale", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// kernel
		jfieldID kernelFid = (*env)->GetFieldID(env, optionsCls, "kernel", "Lcom/criteo/vips/enums/VipsKernel;");
		jobject kernel = (*env)->GetObjectField(env, options, kernelFid);
		if (kernel != NULL) {
			jclass kernelCls = (*env)->GetObjectClass(env, kernel);
			jfieldID kernelValueFid = (*env)->GetFieldID(env, kernelCls, "value", "I");
			jint kernelValue = (*env)->GetIntField(env, kernel, kernelValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, kernelValue);
			g_object_set_property(G_OBJECT(op), "kernel", &gvalue);
			g_value_unset(&gvalue);
		}

		// vscale
		jfieldID vscaleFid = (*env)->GetFieldID(env, optionsCls, "vscale", "Ljava/lang/Double;");
		jobject vscaleObjectValue = (*env)->GetObjectField(env, options, vscaleFid);
		if (vscaleObjectValue != NULL) {
			jdouble vscale = (*env)->CallDoubleMethod(env, vscaleObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, vscale);
			g_object_set_property(G_OBJECT(op), "vscale", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "resize failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_rot(JNIEnv *env, jobject in, jobject angle)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("rot");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// angle
	if (angle != NULL) {
		jclass angleCls = (*env)->GetObjectClass(env, angle);
		jfieldID angleValueFid = (*env)->GetFieldID(env, angleCls, "value", "I");
		jint angleValue = (*env)->GetIntField(env, angle, angleValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, angleValue);
		g_object_set_property(G_OBJECT(op), "angle", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "rot failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_rot45(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("rot45");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// angle
		jfieldID angleFid = (*env)->GetFieldID(env, optionsCls, "angle", "Lcom/criteo/vips/enums/VipsAngle45;");
		jobject angle = (*env)->GetObjectField(env, options, angleFid);
		if (angle != NULL) {
			jclass angleCls = (*env)->GetObjectClass(env, angle);
			jfieldID angleValueFid = (*env)->GetFieldID(env, angleCls, "value", "I");
			jint angleValue = (*env)->GetIntField(env, angle, angleValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, angleValue);
			g_object_set_property(G_OBJECT(op), "angle", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "rot45 failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_round(JNIEnv *env, jobject in, jobject round)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("round");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// round
	if (round != NULL) {
		jclass roundCls = (*env)->GetObjectClass(env, round);
		jfieldID roundValueFid = (*env)->GetFieldID(env, roundCls, "value", "I");
		jint roundValue = (*env)->GetIntField(env, round, roundValueFid);
		g_value_init(&gvalue, G_TYPE_INT);
		g_value_set_int(&gvalue, roundValue);
		g_object_set_property(G_OBJECT(op), "round", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "round failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_scale(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("scale");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// exp
		jfieldID expFid = (*env)->GetFieldID(env, optionsCls, "exp", "Ljava/lang/Double;");
		jobject expObjectValue = (*env)->GetObjectField(env, options, expFid);
		if (expObjectValue != NULL) {
			jdouble exp = (*env)->CallDoubleMethod(env, expObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, exp);
			g_object_set_property(G_OBJECT(op), "exp", &gvalue);
			g_value_unset(&gvalue);
		}

		// log
		jfieldID logFid = (*env)->GetFieldID(env, optionsCls, "log", "Ljava/lang/Boolean;");
		jobject logObjectValue = (*env)->GetObjectField(env, options, logFid);
		if (logObjectValue != NULL) {
			jboolean log = (*env)->CallBooleanMethod(env, logObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, log);
			g_object_set_property(G_OBJECT(op), "log", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "scale failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_scRGB2BW(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("scRGB2BW");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// depth
		jfieldID depthFid = (*env)->GetFieldID(env, optionsCls, "depth", "Ljava/lang/Integer;");
		jobject depthObjectValue = (*env)->GetObjectField(env, options, depthFid);
		if (depthObjectValue != NULL) {
			jint depth = (*env)->CallIntMethod(env, depthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, depth);
			g_object_set_property(G_OBJECT(op), "depth", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "scRGB2BW failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_scRGB2sRGB(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("scRGB2sRGB");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// depth
		jfieldID depthFid = (*env)->GetFieldID(env, optionsCls, "depth", "Ljava/lang/Integer;");
		jobject depthObjectValue = (*env)->GetObjectField(env, options, depthFid);
		if (depthObjectValue != NULL) {
			jint depth = (*env)->CallIntMethod(env, depthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, depth);
			g_object_set_property(G_OBJECT(op), "depth", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "scRGB2sRGB failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_scRGB2XYZ(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("scRGB2XYZ");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "scRGB2XYZ failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_sequential(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("sequential");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// tile-height
		jfieldID tileHeightFid = (*env)->GetFieldID(env, optionsCls, "tileHeight", "Ljava/lang/Integer;");
		jobject tileHeightObjectValue = (*env)->GetObjectField(env, options, tileHeightFid);
		if (tileHeightObjectValue != NULL) {
			jint tileHeight = (*env)->CallIntMethod(env, tileHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileHeight);
			g_object_set_property(G_OBJECT(op), "tile-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "sequential failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_sharpen(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("sharpen");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// sigma
		jfieldID sigmaFid = (*env)->GetFieldID(env, optionsCls, "sigma", "Ljava/lang/Double;");
		jobject sigmaObjectValue = (*env)->GetObjectField(env, options, sigmaFid);
		if (sigmaObjectValue != NULL) {
			jdouble sigma = (*env)->CallDoubleMethod(env, sigmaObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, sigma);
			g_object_set_property(G_OBJECT(op), "sigma", &gvalue);
			g_value_unset(&gvalue);
		}

		// x1
		jfieldID x1Fid = (*env)->GetFieldID(env, optionsCls, "x1", "Ljava/lang/Double;");
		jobject x1ObjectValue = (*env)->GetObjectField(env, options, x1Fid);
		if (x1ObjectValue != NULL) {
			jdouble x1 = (*env)->CallDoubleMethod(env, x1ObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, x1);
			g_object_set_property(G_OBJECT(op), "x1", &gvalue);
			g_value_unset(&gvalue);
		}

		// y2
		jfieldID y2Fid = (*env)->GetFieldID(env, optionsCls, "y2", "Ljava/lang/Double;");
		jobject y2ObjectValue = (*env)->GetObjectField(env, options, y2Fid);
		if (y2ObjectValue != NULL) {
			jdouble y2 = (*env)->CallDoubleMethod(env, y2ObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, y2);
			g_object_set_property(G_OBJECT(op), "y2", &gvalue);
			g_value_unset(&gvalue);
		}

		// y3
		jfieldID y3Fid = (*env)->GetFieldID(env, optionsCls, "y3", "Ljava/lang/Double;");
		jobject y3ObjectValue = (*env)->GetObjectField(env, options, y3Fid);
		if (y3ObjectValue != NULL) {
			jdouble y3 = (*env)->CallDoubleMethod(env, y3ObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, y3);
			g_object_set_property(G_OBJECT(op), "y3", &gvalue);
			g_value_unset(&gvalue);
		}

		// m1
		jfieldID m1Fid = (*env)->GetFieldID(env, optionsCls, "m1", "Ljava/lang/Double;");
		jobject m1ObjectValue = (*env)->GetObjectField(env, options, m1Fid);
		if (m1ObjectValue != NULL) {
			jdouble m1 = (*env)->CallDoubleMethod(env, m1ObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, m1);
			g_object_set_property(G_OBJECT(op), "m1", &gvalue);
			g_value_unset(&gvalue);
		}

		// m2
		jfieldID m2Fid = (*env)->GetFieldID(env, optionsCls, "m2", "Ljava/lang/Double;");
		jobject m2ObjectValue = (*env)->GetObjectField(env, options, m2Fid);
		if (m2ObjectValue != NULL) {
			jdouble m2 = (*env)->CallDoubleMethod(env, m2ObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, m2);
			g_object_set_property(G_OBJECT(op), "m2", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "sharpen failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_shrink(JNIEnv *env, jobject in, jdouble hshrink, jdouble vshrink)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("shrink");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// hshrink
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, hshrink);
	g_object_set_property(G_OBJECT(op), "hshrink", &gvalue);
	g_value_unset(&gvalue);

	// vshrink
	g_value_init(&gvalue, G_TYPE_DOUBLE);
	g_value_set_double(&gvalue, vshrink);
	g_object_set_property(G_OBJECT(op), "vshrink", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "shrink failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_shrinkh(JNIEnv *env, jobject in, jint hshrink)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("shrinkh");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// hshrink
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, hshrink);
	g_object_set_property(G_OBJECT(op), "hshrink", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "shrinkh failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_shrinkv(JNIEnv *env, jobject in, jint vshrink)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("shrinkv");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// vshrink
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, vshrink);
	g_object_set_property(G_OBJECT(op), "vshrink", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "shrinkv failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_sign(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("sign");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "sign failed");
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
Java_com_criteo_vips_AbstractVipsImage_sines(JNIEnv *env, jclass cls, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("sines");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

		// hfreq
		jfieldID hfreqFid = (*env)->GetFieldID(env, optionsCls, "hfreq", "Ljava/lang/Double;");
		jobject hfreqObjectValue = (*env)->GetObjectField(env, options, hfreqFid);
		if (hfreqObjectValue != NULL) {
			jdouble hfreq = (*env)->CallDoubleMethod(env, hfreqObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, hfreq);
			g_object_set_property(G_OBJECT(op), "hfreq", &gvalue);
			g_value_unset(&gvalue);
		}

		// vfreq
		jfieldID vfreqFid = (*env)->GetFieldID(env, optionsCls, "vfreq", "Ljava/lang/Double;");
		jobject vfreqObjectValue = (*env)->GetObjectField(env, options, vfreqFid);
		if (vfreqObjectValue != NULL) {
			jdouble vfreq = (*env)->CallDoubleMethod(env, vfreqObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, vfreq);
			g_object_set_property(G_OBJECT(op), "vfreq", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "sines failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_smartcrop(JNIEnv *env, jobject input, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("smartcrop");

	// input
	if (input != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, input, handle_fid));
		g_object_set_property(G_OBJECT(op), "input", &gvalue);
		g_value_unset(&gvalue);
	}

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// interesting
		jfieldID interestingFid = (*env)->GetFieldID(env, optionsCls, "interesting", "Lcom/criteo/vips/enums/VipsInteresting;");
		jobject interesting = (*env)->GetObjectField(env, options, interestingFid);
		if (interesting != NULL) {
			jclass interestingCls = (*env)->GetObjectClass(env, interesting);
			jfieldID interestingValueFid = (*env)->GetFieldID(env, interestingCls, "value", "I");
			jint interestingValue = (*env)->GetIntField(env, interesting, interestingValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, interestingValue);
			g_object_set_property(G_OBJECT(op), "interesting", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "smartcrop failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, input, handle_fid));
	(*env)->SetLongField(env, input, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_sobel(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("sobel");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "sobel failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_spcor(JNIEnv *env, jobject in, jobject ref)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("spcor");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// ref
	if (ref != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, ref, handle_fid));
		g_object_set_property(G_OBJECT(op), "ref", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "spcor failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_spectrum(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("spectrum");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "spectrum failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_sRGB2HSV(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("sRGB2HSV");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "sRGB2HSV failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_sRGB2scRGB(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("sRGB2scRGB");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "sRGB2scRGB failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_stats(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("stats");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "stats failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_stdif(JNIEnv *env, jobject in, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("stdif");

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

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// s0
		jfieldID s0Fid = (*env)->GetFieldID(env, optionsCls, "s0", "Ljava/lang/Double;");
		jobject s0ObjectValue = (*env)->GetObjectField(env, options, s0Fid);
		if (s0ObjectValue != NULL) {
			jdouble s0 = (*env)->CallDoubleMethod(env, s0ObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, s0);
			g_object_set_property(G_OBJECT(op), "s0", &gvalue);
			g_value_unset(&gvalue);
		}

		// b
		jfieldID bFid = (*env)->GetFieldID(env, optionsCls, "b", "Ljava/lang/Double;");
		jobject bObjectValue = (*env)->GetObjectField(env, options, bFid);
		if (bObjectValue != NULL) {
			jdouble b = (*env)->CallDoubleMethod(env, bObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, b);
			g_object_set_property(G_OBJECT(op), "b", &gvalue);
			g_value_unset(&gvalue);
		}

		// m0
		jfieldID m0Fid = (*env)->GetFieldID(env, optionsCls, "m0", "Ljava/lang/Double;");
		jobject m0ObjectValue = (*env)->GetObjectField(env, options, m0Fid);
		if (m0ObjectValue != NULL) {
			jdouble m0 = (*env)->CallDoubleMethod(env, m0ObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, m0);
			g_object_set_property(G_OBJECT(op), "m0", &gvalue);
			g_value_unset(&gvalue);
		}

		// a
		jfieldID aFid = (*env)->GetFieldID(env, optionsCls, "a", "Ljava/lang/Double;");
		jobject aObjectValue = (*env)->GetObjectField(env, options, aFid);
		if (aObjectValue != NULL) {
			jdouble a = (*env)->CallDoubleMethod(env, aObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, a);
			g_object_set_property(G_OBJECT(op), "a", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "stdif failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_subsample(JNIEnv *env, jobject input, jint xfac, jint yfac, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("subsample");

	// input
	if (input != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, input, handle_fid));
		g_object_set_property(G_OBJECT(op), "input", &gvalue);
		g_value_unset(&gvalue);
	}

	// xfac
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, xfac);
	g_object_set_property(G_OBJECT(op), "xfac", &gvalue);
	g_value_unset(&gvalue);

	// yfac
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, yfac);
	g_object_set_property(G_OBJECT(op), "yfac", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// point
		jfieldID pointFid = (*env)->GetFieldID(env, optionsCls, "point", "Ljava/lang/Boolean;");
		jobject pointObjectValue = (*env)->GetObjectField(env, options, pointFid);
		if (pointObjectValue != NULL) {
			jboolean point = (*env)->CallBooleanMethod(env, pointObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, point);
			g_object_set_property(G_OBJECT(op), "point", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "subsample failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, input, handle_fid));
	(*env)->SetLongField(env, input, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_subtract(JNIEnv *env, jobject left, jobject right)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("subtract");

	// left
	if (left != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, left, handle_fid));
		g_object_set_property(G_OBJECT(op), "left", &gvalue);
		g_value_unset(&gvalue);
	}

	// right
	if (right != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, right, handle_fid));
		g_object_set_property(G_OBJECT(op), "right", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "subtract failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, left, handle_fid));
	(*env)->SetLongField(env, left, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_svgLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("svgload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// dpi
		jfieldID dpiFid = (*env)->GetFieldID(env, optionsCls, "dpi", "Ljava/lang/Double;");
		jobject dpiObjectValue = (*env)->GetObjectField(env, options, dpiFid);
		if (dpiObjectValue != NULL) {
			jdouble dpi = (*env)->CallDoubleMethod(env, dpiObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, dpi);
			g_object_set_property(G_OBJECT(op), "dpi", &gvalue);
			g_value_unset(&gvalue);
		}

		// scale
		jfieldID scaleFid = (*env)->GetFieldID(env, optionsCls, "scale", "Ljava/lang/Double;");
		jobject scaleObjectValue = (*env)->GetObjectField(env, options, scaleFid);
		if (scaleObjectValue != NULL) {
			jdouble scale = (*env)->CallDoubleMethod(env, scaleObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, scale);
			g_object_set_property(G_OBJECT(op), "scale", &gvalue);
			g_value_unset(&gvalue);
		}

		// unlimited
		jfieldID unlimitedFid = (*env)->GetFieldID(env, optionsCls, "unlimited", "Ljava/lang/Boolean;");
		jobject unlimitedObjectValue = (*env)->GetObjectField(env, options, unlimitedFid);
		if (unlimitedObjectValue != NULL) {
			jboolean unlimited = (*env)->CallBooleanMethod(env, unlimitedObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, unlimited);
			g_object_set_property(G_OBJECT(op), "unlimited", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "svgload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_svgLoadBuffer(JNIEnv *env, jclass cls, jbyteArray buffer, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("svgload_buffer");

	// buffer
	if (buffer != NULL) {
		jint bufferLength = (*env)->GetArrayLength(env, buffer);
		size_t bufferSize = bufferLength * sizeof(jbyte);
		void *bufferData = vips_tracked_malloc(bufferSize);
		if (bufferData == NULL) {
			throwVipsException(env, "Failed to allocate memory for buffer");
		}
		(*env)->GetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
		g_value_init(&gvalue, VIPS_TYPE_BLOB);
		vips_value_set_blob_free(&gvalue, bufferData, bufferSize);
		g_object_set_property(G_OBJECT(op), "buffer", &gvalue);
		g_value_unset(&gvalue);
	
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// dpi
		jfieldID dpiFid = (*env)->GetFieldID(env, optionsCls, "dpi", "Ljava/lang/Double;");
		jobject dpiObjectValue = (*env)->GetObjectField(env, options, dpiFid);
		if (dpiObjectValue != NULL) {
			jdouble dpi = (*env)->CallDoubleMethod(env, dpiObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, dpi);
			g_object_set_property(G_OBJECT(op), "dpi", &gvalue);
			g_value_unset(&gvalue);
		}

		// scale
		jfieldID scaleFid = (*env)->GetFieldID(env, optionsCls, "scale", "Ljava/lang/Double;");
		jobject scaleObjectValue = (*env)->GetObjectField(env, options, scaleFid);
		if (scaleObjectValue != NULL) {
			jdouble scale = (*env)->CallDoubleMethod(env, scaleObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, scale);
			g_object_set_property(G_OBJECT(op), "scale", &gvalue);
			g_value_unset(&gvalue);
		}

		// unlimited
		jfieldID unlimitedFid = (*env)->GetFieldID(env, optionsCls, "unlimited", "Ljava/lang/Boolean;");
		jobject unlimitedObjectValue = (*env)->GetObjectField(env, options, unlimitedFid);
		if (unlimitedObjectValue != NULL) {
			jboolean unlimited = (*env)->CallBooleanMethod(env, unlimitedObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, unlimited);
			g_object_set_property(G_OBJECT(op), "unlimited", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "svgload_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_text(JNIEnv *env, jclass cls, jstring text, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("text");

	// text
	if (text != NULL) {
		const char *textChars = (*env)->GetStringUTFChars(env, text, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, textChars);
		(*env)->ReleaseStringUTFChars(env, text, textChars);
		g_object_set_property(G_OBJECT(op), "text", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// font
		jfieldID fontFid = (*env)->GetFieldID(env, optionsCls, "font", "Ljava/lang/String;");
		jstring font = (jstring) (*env)->GetObjectField(env, options, fontFid);
		if (font != NULL) {
			const char *fontChars = (*env)->GetStringUTFChars(env, font, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, fontChars);
			(*env)->ReleaseStringUTFChars(env, font, fontChars);
			g_object_set_property(G_OBJECT(op), "font", &gvalue);
			g_value_unset(&gvalue);
		}

		// width
		jfieldID widthFid = (*env)->GetFieldID(env, optionsCls, "width", "Ljava/lang/Integer;");
		jobject widthObjectValue = (*env)->GetObjectField(env, options, widthFid);
		if (widthObjectValue != NULL) {
			jint width = (*env)->CallIntMethod(env, widthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, width);
			g_object_set_property(G_OBJECT(op), "width", &gvalue);
			g_value_unset(&gvalue);
		}

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

		// align
		jfieldID alignFid = (*env)->GetFieldID(env, optionsCls, "align", "Lcom/criteo/vips/enums/VipsAlign;");
		jobject align = (*env)->GetObjectField(env, options, alignFid);
		if (align != NULL) {
			jclass alignCls = (*env)->GetObjectClass(env, align);
			jfieldID alignValueFid = (*env)->GetFieldID(env, alignCls, "value", "I");
			jint alignValue = (*env)->GetIntField(env, align, alignValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, alignValue);
			g_object_set_property(G_OBJECT(op), "align", &gvalue);
			g_value_unset(&gvalue);
		}

		// rgba
		jfieldID rgbaFid = (*env)->GetFieldID(env, optionsCls, "rgba", "Ljava/lang/Boolean;");
		jobject rgbaObjectValue = (*env)->GetObjectField(env, options, rgbaFid);
		if (rgbaObjectValue != NULL) {
			jboolean rgba = (*env)->CallBooleanMethod(env, rgbaObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, rgba);
			g_object_set_property(G_OBJECT(op), "rgba", &gvalue);
			g_value_unset(&gvalue);
		}

		// dpi
		jfieldID dpiFid = (*env)->GetFieldID(env, optionsCls, "dpi", "Ljava/lang/Integer;");
		jobject dpiObjectValue = (*env)->GetObjectField(env, options, dpiFid);
		if (dpiObjectValue != NULL) {
			jint dpi = (*env)->CallIntMethod(env, dpiObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, dpi);
			g_object_set_property(G_OBJECT(op), "dpi", &gvalue);
			g_value_unset(&gvalue);
		}

		// justify
		jfieldID justifyFid = (*env)->GetFieldID(env, optionsCls, "justify", "Ljava/lang/Boolean;");
		jobject justifyObjectValue = (*env)->GetObjectField(env, options, justifyFid);
		if (justifyObjectValue != NULL) {
			jboolean justify = (*env)->CallBooleanMethod(env, justifyObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, justify);
			g_object_set_property(G_OBJECT(op), "justify", &gvalue);
			g_value_unset(&gvalue);
		}

		// spacing
		jfieldID spacingFid = (*env)->GetFieldID(env, optionsCls, "spacing", "Ljava/lang/Integer;");
		jobject spacingObjectValue = (*env)->GetObjectField(env, options, spacingFid);
		if (spacingObjectValue != NULL) {
			jint spacing = (*env)->CallIntMethod(env, spacingObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, spacing);
			g_object_set_property(G_OBJECT(op), "spacing", &gvalue);
			g_value_unset(&gvalue);
		}

		// fontfile
		jfieldID fontfileFid = (*env)->GetFieldID(env, optionsCls, "fontfile", "Ljava/lang/String;");
		jstring fontfile = (jstring) (*env)->GetObjectField(env, options, fontfileFid);
		if (fontfile != NULL) {
			const char *fontfileChars = (*env)->GetStringUTFChars(env, fontfile, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, fontfileChars);
			(*env)->ReleaseStringUTFChars(env, fontfile, fontfileChars);
			g_object_set_property(G_OBJECT(op), "fontfile", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "text failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_thumbnail(JNIEnv *env, jclass cls, jstring filename, jint width, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("thumbnail");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
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
		throwVipsException(env, "thumbnail failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_thumbnailBuffer(JNIEnv *env, jclass cls, jbyteArray buffer, jint width, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("thumbnail_buffer");

	// buffer
	if (buffer != NULL) {
		jint bufferLength = (*env)->GetArrayLength(env, buffer);
		size_t bufferSize = bufferLength * sizeof(jbyte);
		void *bufferData = vips_tracked_malloc(bufferSize);
		if (bufferData == NULL) {
			throwVipsException(env, "Failed to allocate memory for buffer");
		}
		(*env)->GetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
		g_value_init(&gvalue, VIPS_TYPE_BLOB);
		vips_value_set_blob_free(&gvalue, bufferData, bufferSize);
		g_object_set_property(G_OBJECT(op), "buffer", &gvalue);
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

		// option-string
		jfieldID optionStringFid = (*env)->GetFieldID(env, optionsCls, "optionString", "Ljava/lang/String;");
		jstring optionString = (jstring) (*env)->GetObjectField(env, options, optionStringFid);
		if (optionString != NULL) {
			const char *optionStringChars = (*env)->GetStringUTFChars(env, optionString, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, optionStringChars);
			(*env)->ReleaseStringUTFChars(env, optionString, optionStringChars);
			g_object_set_property(G_OBJECT(op), "option-string", &gvalue);
			g_value_unset(&gvalue);
		}

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
		throwVipsException(env, "thumbnail_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_thumbnailImage(JNIEnv *env, jobject in, jint width, jobject options)
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
Java_com_criteo_vips_AbstractVipsImage_tiffLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("tiffload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// subifd
		jfieldID subifdFid = (*env)->GetFieldID(env, optionsCls, "subifd", "Ljava/lang/Integer;");
		jobject subifdObjectValue = (*env)->GetObjectField(env, options, subifdFid);
		if (subifdObjectValue != NULL) {
			jint subifd = (*env)->CallIntMethod(env, subifdObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, subifd);
			g_object_set_property(G_OBJECT(op), "subifd", &gvalue);
			g_value_unset(&gvalue);
		}

		// n
		jfieldID nFid = (*env)->GetFieldID(env, optionsCls, "n", "Ljava/lang/Integer;");
		jobject nObjectValue = (*env)->GetObjectField(env, options, nFid);
		if (nObjectValue != NULL) {
			jint n = (*env)->CallIntMethod(env, nObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, n);
			g_object_set_property(G_OBJECT(op), "n", &gvalue);
			g_value_unset(&gvalue);
		}

		// autorotate
		jfieldID autorotateFid = (*env)->GetFieldID(env, optionsCls, "autorotate", "Ljava/lang/Boolean;");
		jobject autorotateObjectValue = (*env)->GetObjectField(env, options, autorotateFid);
		if (autorotateObjectValue != NULL) {
			jboolean autorotate = (*env)->CallBooleanMethod(env, autorotateObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, autorotate);
			g_object_set_property(G_OBJECT(op), "autorotate", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "tiffload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_tiffLoadBuffer(JNIEnv *env, jclass cls, jbyteArray buffer, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("tiffload_buffer");

	// buffer
	if (buffer != NULL) {
		jint bufferLength = (*env)->GetArrayLength(env, buffer);
		size_t bufferSize = bufferLength * sizeof(jbyte);
		void *bufferData = vips_tracked_malloc(bufferSize);
		if (bufferData == NULL) {
			throwVipsException(env, "Failed to allocate memory for buffer");
		}
		(*env)->GetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
		g_value_init(&gvalue, VIPS_TYPE_BLOB);
		vips_value_set_blob_free(&gvalue, bufferData, bufferSize);
		g_object_set_property(G_OBJECT(op), "buffer", &gvalue);
		g_value_unset(&gvalue);
	
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// subifd
		jfieldID subifdFid = (*env)->GetFieldID(env, optionsCls, "subifd", "Ljava/lang/Integer;");
		jobject subifdObjectValue = (*env)->GetObjectField(env, options, subifdFid);
		if (subifdObjectValue != NULL) {
			jint subifd = (*env)->CallIntMethod(env, subifdObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, subifd);
			g_object_set_property(G_OBJECT(op), "subifd", &gvalue);
			g_value_unset(&gvalue);
		}

		// n
		jfieldID nFid = (*env)->GetFieldID(env, optionsCls, "n", "Ljava/lang/Integer;");
		jobject nObjectValue = (*env)->GetObjectField(env, options, nFid);
		if (nObjectValue != NULL) {
			jint n = (*env)->CallIntMethod(env, nObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, n);
			g_object_set_property(G_OBJECT(op), "n", &gvalue);
			g_value_unset(&gvalue);
		}

		// autorotate
		jfieldID autorotateFid = (*env)->GetFieldID(env, optionsCls, "autorotate", "Ljava/lang/Boolean;");
		jobject autorotateObjectValue = (*env)->GetObjectField(env, options, autorotateFid);
		if (autorotateObjectValue != NULL) {
			jboolean autorotate = (*env)->CallBooleanMethod(env, autorotateObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, autorotate);
			g_object_set_property(G_OBJECT(op), "autorotate", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "tiffload_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_tiffSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("tiffsave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// compression
		jfieldID compressionFid = (*env)->GetFieldID(env, optionsCls, "compression", "Lcom/criteo/vips/enums/VipsForeignTiffCompression;");
		jobject compression = (*env)->GetObjectField(env, options, compressionFid);
		if (compression != NULL) {
			jclass compressionCls = (*env)->GetObjectClass(env, compression);
			jfieldID compressionValueFid = (*env)->GetFieldID(env, compressionCls, "value", "I");
			jint compressionValue = (*env)->GetIntField(env, compression, compressionValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, compressionValue);
			g_object_set_property(G_OBJECT(op), "compression", &gvalue);
			g_value_unset(&gvalue);
		}

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// predictor
		jfieldID predictorFid = (*env)->GetFieldID(env, optionsCls, "predictor", "Lcom/criteo/vips/enums/VipsForeignTiffPredictor;");
		jobject predictor = (*env)->GetObjectField(env, options, predictorFid);
		if (predictor != NULL) {
			jclass predictorCls = (*env)->GetObjectClass(env, predictor);
			jfieldID predictorValueFid = (*env)->GetFieldID(env, predictorCls, "value", "I");
			jint predictorValue = (*env)->GetIntField(env, predictor, predictorValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, predictorValue);
			g_object_set_property(G_OBJECT(op), "predictor", &gvalue);
			g_value_unset(&gvalue);
		}

		// profile
		jfieldID profileFid = (*env)->GetFieldID(env, optionsCls, "profile", "Ljava/lang/String;");
		jstring profile = (jstring) (*env)->GetObjectField(env, options, profileFid);
		if (profile != NULL) {
			const char *profileChars = (*env)->GetStringUTFChars(env, profile, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, profileChars);
			(*env)->ReleaseStringUTFChars(env, profile, profileChars);
			g_object_set_property(G_OBJECT(op), "profile", &gvalue);
			g_value_unset(&gvalue);
		}

		// tile
		jfieldID tileFid = (*env)->GetFieldID(env, optionsCls, "tile", "Ljava/lang/Boolean;");
		jobject tileObjectValue = (*env)->GetObjectField(env, options, tileFid);
		if (tileObjectValue != NULL) {
			jboolean tile = (*env)->CallBooleanMethod(env, tileObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, tile);
			g_object_set_property(G_OBJECT(op), "tile", &gvalue);
			g_value_unset(&gvalue);
		}

		// tile-width
		jfieldID tileWidthFid = (*env)->GetFieldID(env, optionsCls, "tileWidth", "Ljava/lang/Integer;");
		jobject tileWidthObjectValue = (*env)->GetObjectField(env, options, tileWidthFid);
		if (tileWidthObjectValue != NULL) {
			jint tileWidth = (*env)->CallIntMethod(env, tileWidthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileWidth);
			g_object_set_property(G_OBJECT(op), "tile-width", &gvalue);
			g_value_unset(&gvalue);
		}

		// tile-height
		jfieldID tileHeightFid = (*env)->GetFieldID(env, optionsCls, "tileHeight", "Ljava/lang/Integer;");
		jobject tileHeightObjectValue = (*env)->GetObjectField(env, options, tileHeightFid);
		if (tileHeightObjectValue != NULL) {
			jint tileHeight = (*env)->CallIntMethod(env, tileHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileHeight);
			g_object_set_property(G_OBJECT(op), "tile-height", &gvalue);
			g_value_unset(&gvalue);
		}

		// pyramid
		jfieldID pyramidFid = (*env)->GetFieldID(env, optionsCls, "pyramid", "Ljava/lang/Boolean;");
		jobject pyramidObjectValue = (*env)->GetObjectField(env, options, pyramidFid);
		if (pyramidObjectValue != NULL) {
			jboolean pyramid = (*env)->CallBooleanMethod(env, pyramidObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, pyramid);
			g_object_set_property(G_OBJECT(op), "pyramid", &gvalue);
			g_value_unset(&gvalue);
		}

		// miniswhite
		jfieldID miniswhiteFid = (*env)->GetFieldID(env, optionsCls, "miniswhite", "Ljava/lang/Boolean;");
		jobject miniswhiteObjectValue = (*env)->GetObjectField(env, options, miniswhiteFid);
		if (miniswhiteObjectValue != NULL) {
			jboolean miniswhite = (*env)->CallBooleanMethod(env, miniswhiteObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, miniswhite);
			g_object_set_property(G_OBJECT(op), "miniswhite", &gvalue);
			g_value_unset(&gvalue);
		}

		// bitdepth
		jfieldID bitdepthFid = (*env)->GetFieldID(env, optionsCls, "bitdepth", "Ljava/lang/Integer;");
		jobject bitdepthObjectValue = (*env)->GetObjectField(env, options, bitdepthFid);
		if (bitdepthObjectValue != NULL) {
			jint bitdepth = (*env)->CallIntMethod(env, bitdepthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, bitdepth);
			g_object_set_property(G_OBJECT(op), "bitdepth", &gvalue);
			g_value_unset(&gvalue);
		}

		// resunit
		jfieldID resunitFid = (*env)->GetFieldID(env, optionsCls, "resunit", "Lcom/criteo/vips/enums/VipsForeignTiffResunit;");
		jobject resunit = (*env)->GetObjectField(env, options, resunitFid);
		if (resunit != NULL) {
			jclass resunitCls = (*env)->GetObjectClass(env, resunit);
			jfieldID resunitValueFid = (*env)->GetFieldID(env, resunitCls, "value", "I");
			jint resunitValue = (*env)->GetIntField(env, resunit, resunitValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, resunitValue);
			g_object_set_property(G_OBJECT(op), "resunit", &gvalue);
			g_value_unset(&gvalue);
		}

		// xres
		jfieldID xresFid = (*env)->GetFieldID(env, optionsCls, "xres", "Ljava/lang/Double;");
		jobject xresObjectValue = (*env)->GetObjectField(env, options, xresFid);
		if (xresObjectValue != NULL) {
			jdouble xres = (*env)->CallDoubleMethod(env, xresObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, xres);
			g_object_set_property(G_OBJECT(op), "xres", &gvalue);
			g_value_unset(&gvalue);
		}

		// yres
		jfieldID yresFid = (*env)->GetFieldID(env, optionsCls, "yres", "Ljava/lang/Double;");
		jobject yresObjectValue = (*env)->GetObjectField(env, options, yresFid);
		if (yresObjectValue != NULL) {
			jdouble yres = (*env)->CallDoubleMethod(env, yresObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, yres);
			g_object_set_property(G_OBJECT(op), "yres", &gvalue);
			g_value_unset(&gvalue);
		}

		// bigtiff
		jfieldID bigtiffFid = (*env)->GetFieldID(env, optionsCls, "bigtiff", "Ljava/lang/Boolean;");
		jobject bigtiffObjectValue = (*env)->GetObjectField(env, options, bigtiffFid);
		if (bigtiffObjectValue != NULL) {
			jboolean bigtiff = (*env)->CallBooleanMethod(env, bigtiffObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, bigtiff);
			g_object_set_property(G_OBJECT(op), "bigtiff", &gvalue);
			g_value_unset(&gvalue);
		}

		// properties
		jfieldID propertiesFid = (*env)->GetFieldID(env, optionsCls, "properties", "Ljava/lang/Boolean;");
		jobject propertiesObjectValue = (*env)->GetObjectField(env, options, propertiesFid);
		if (propertiesObjectValue != NULL) {
			jboolean properties = (*env)->CallBooleanMethod(env, propertiesObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, properties);
			g_object_set_property(G_OBJECT(op), "properties", &gvalue);
			g_value_unset(&gvalue);
		}

		// region-shrink
		jfieldID regionShrinkFid = (*env)->GetFieldID(env, optionsCls, "regionShrink", "Lcom/criteo/vips/enums/VipsRegionShrink;");
		jobject regionShrink = (*env)->GetObjectField(env, options, regionShrinkFid);
		if (regionShrink != NULL) {
			jclass regionShrinkCls = (*env)->GetObjectClass(env, regionShrink);
			jfieldID regionShrinkValueFid = (*env)->GetFieldID(env, regionShrinkCls, "value", "I");
			jint regionShrinkValue = (*env)->GetIntField(env, regionShrink, regionShrinkValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, regionShrinkValue);
			g_object_set_property(G_OBJECT(op), "region-shrink", &gvalue);
			g_value_unset(&gvalue);
		}

		// level
		jfieldID levelFid = (*env)->GetFieldID(env, optionsCls, "level", "Ljava/lang/Integer;");
		jobject levelObjectValue = (*env)->GetObjectField(env, options, levelFid);
		if (levelObjectValue != NULL) {
			jint level = (*env)->CallIntMethod(env, levelObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, level);
			g_object_set_property(G_OBJECT(op), "level", &gvalue);
			g_value_unset(&gvalue);
		}

		// lossless
		jfieldID losslessFid = (*env)->GetFieldID(env, optionsCls, "lossless", "Ljava/lang/Boolean;");
		jobject losslessObjectValue = (*env)->GetObjectField(env, options, losslessFid);
		if (losslessObjectValue != NULL) {
			jboolean lossless = (*env)->CallBooleanMethod(env, losslessObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, lossless);
			g_object_set_property(G_OBJECT(op), "lossless", &gvalue);
			g_value_unset(&gvalue);
		}

		// depth
		jfieldID depthFid = (*env)->GetFieldID(env, optionsCls, "depth", "Lcom/criteo/vips/enums/VipsForeignDzDepth;");
		jobject depth = (*env)->GetObjectField(env, options, depthFid);
		if (depth != NULL) {
			jclass depthCls = (*env)->GetObjectClass(env, depth);
			jfieldID depthValueFid = (*env)->GetFieldID(env, depthCls, "value", "I");
			jint depthValue = (*env)->GetIntField(env, depth, depthValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, depthValue);
			g_object_set_property(G_OBJECT(op), "depth", &gvalue);
			g_value_unset(&gvalue);
		}

		// subifd
		jfieldID subifdFid = (*env)->GetFieldID(env, optionsCls, "subifd", "Ljava/lang/Boolean;");
		jobject subifdObjectValue = (*env)->GetObjectField(env, options, subifdFid);
		if (subifdObjectValue != NULL) {
			jboolean subifd = (*env)->CallBooleanMethod(env, subifdObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, subifd);
			g_object_set_property(G_OBJECT(op), "subifd", &gvalue);
			g_value_unset(&gvalue);
		}

		// premultiply
		jfieldID premultiplyFid = (*env)->GetFieldID(env, optionsCls, "premultiply", "Ljava/lang/Boolean;");
		jobject premultiplyObjectValue = (*env)->GetObjectField(env, options, premultiplyFid);
		if (premultiplyObjectValue != NULL) {
			jboolean premultiply = (*env)->CallBooleanMethod(env, premultiplyObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, premultiply);
			g_object_set_property(G_OBJECT(op), "premultiply", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "tiffsave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_AbstractVipsImage_tiffSaveBuffer(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("tiffsave_buffer");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// compression
		jfieldID compressionFid = (*env)->GetFieldID(env, optionsCls, "compression", "Lcom/criteo/vips/enums/VipsForeignTiffCompression;");
		jobject compression = (*env)->GetObjectField(env, options, compressionFid);
		if (compression != NULL) {
			jclass compressionCls = (*env)->GetObjectClass(env, compression);
			jfieldID compressionValueFid = (*env)->GetFieldID(env, compressionCls, "value", "I");
			jint compressionValue = (*env)->GetIntField(env, compression, compressionValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, compressionValue);
			g_object_set_property(G_OBJECT(op), "compression", &gvalue);
			g_value_unset(&gvalue);
		}

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// predictor
		jfieldID predictorFid = (*env)->GetFieldID(env, optionsCls, "predictor", "Lcom/criteo/vips/enums/VipsForeignTiffPredictor;");
		jobject predictor = (*env)->GetObjectField(env, options, predictorFid);
		if (predictor != NULL) {
			jclass predictorCls = (*env)->GetObjectClass(env, predictor);
			jfieldID predictorValueFid = (*env)->GetFieldID(env, predictorCls, "value", "I");
			jint predictorValue = (*env)->GetIntField(env, predictor, predictorValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, predictorValue);
			g_object_set_property(G_OBJECT(op), "predictor", &gvalue);
			g_value_unset(&gvalue);
		}

		// profile
		jfieldID profileFid = (*env)->GetFieldID(env, optionsCls, "profile", "Ljava/lang/String;");
		jstring profile = (jstring) (*env)->GetObjectField(env, options, profileFid);
		if (profile != NULL) {
			const char *profileChars = (*env)->GetStringUTFChars(env, profile, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, profileChars);
			(*env)->ReleaseStringUTFChars(env, profile, profileChars);
			g_object_set_property(G_OBJECT(op), "profile", &gvalue);
			g_value_unset(&gvalue);
		}

		// tile
		jfieldID tileFid = (*env)->GetFieldID(env, optionsCls, "tile", "Ljava/lang/Boolean;");
		jobject tileObjectValue = (*env)->GetObjectField(env, options, tileFid);
		if (tileObjectValue != NULL) {
			jboolean tile = (*env)->CallBooleanMethod(env, tileObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, tile);
			g_object_set_property(G_OBJECT(op), "tile", &gvalue);
			g_value_unset(&gvalue);
		}

		// tile-width
		jfieldID tileWidthFid = (*env)->GetFieldID(env, optionsCls, "tileWidth", "Ljava/lang/Integer;");
		jobject tileWidthObjectValue = (*env)->GetObjectField(env, options, tileWidthFid);
		if (tileWidthObjectValue != NULL) {
			jint tileWidth = (*env)->CallIntMethod(env, tileWidthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileWidth);
			g_object_set_property(G_OBJECT(op), "tile-width", &gvalue);
			g_value_unset(&gvalue);
		}

		// tile-height
		jfieldID tileHeightFid = (*env)->GetFieldID(env, optionsCls, "tileHeight", "Ljava/lang/Integer;");
		jobject tileHeightObjectValue = (*env)->GetObjectField(env, options, tileHeightFid);
		if (tileHeightObjectValue != NULL) {
			jint tileHeight = (*env)->CallIntMethod(env, tileHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileHeight);
			g_object_set_property(G_OBJECT(op), "tile-height", &gvalue);
			g_value_unset(&gvalue);
		}

		// pyramid
		jfieldID pyramidFid = (*env)->GetFieldID(env, optionsCls, "pyramid", "Ljava/lang/Boolean;");
		jobject pyramidObjectValue = (*env)->GetObjectField(env, options, pyramidFid);
		if (pyramidObjectValue != NULL) {
			jboolean pyramid = (*env)->CallBooleanMethod(env, pyramidObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, pyramid);
			g_object_set_property(G_OBJECT(op), "pyramid", &gvalue);
			g_value_unset(&gvalue);
		}

		// miniswhite
		jfieldID miniswhiteFid = (*env)->GetFieldID(env, optionsCls, "miniswhite", "Ljava/lang/Boolean;");
		jobject miniswhiteObjectValue = (*env)->GetObjectField(env, options, miniswhiteFid);
		if (miniswhiteObjectValue != NULL) {
			jboolean miniswhite = (*env)->CallBooleanMethod(env, miniswhiteObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, miniswhite);
			g_object_set_property(G_OBJECT(op), "miniswhite", &gvalue);
			g_value_unset(&gvalue);
		}

		// bitdepth
		jfieldID bitdepthFid = (*env)->GetFieldID(env, optionsCls, "bitdepth", "Ljava/lang/Integer;");
		jobject bitdepthObjectValue = (*env)->GetObjectField(env, options, bitdepthFid);
		if (bitdepthObjectValue != NULL) {
			jint bitdepth = (*env)->CallIntMethod(env, bitdepthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, bitdepth);
			g_object_set_property(G_OBJECT(op), "bitdepth", &gvalue);
			g_value_unset(&gvalue);
		}

		// resunit
		jfieldID resunitFid = (*env)->GetFieldID(env, optionsCls, "resunit", "Lcom/criteo/vips/enums/VipsForeignTiffResunit;");
		jobject resunit = (*env)->GetObjectField(env, options, resunitFid);
		if (resunit != NULL) {
			jclass resunitCls = (*env)->GetObjectClass(env, resunit);
			jfieldID resunitValueFid = (*env)->GetFieldID(env, resunitCls, "value", "I");
			jint resunitValue = (*env)->GetIntField(env, resunit, resunitValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, resunitValue);
			g_object_set_property(G_OBJECT(op), "resunit", &gvalue);
			g_value_unset(&gvalue);
		}

		// xres
		jfieldID xresFid = (*env)->GetFieldID(env, optionsCls, "xres", "Ljava/lang/Double;");
		jobject xresObjectValue = (*env)->GetObjectField(env, options, xresFid);
		if (xresObjectValue != NULL) {
			jdouble xres = (*env)->CallDoubleMethod(env, xresObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, xres);
			g_object_set_property(G_OBJECT(op), "xres", &gvalue);
			g_value_unset(&gvalue);
		}

		// yres
		jfieldID yresFid = (*env)->GetFieldID(env, optionsCls, "yres", "Ljava/lang/Double;");
		jobject yresObjectValue = (*env)->GetObjectField(env, options, yresFid);
		if (yresObjectValue != NULL) {
			jdouble yres = (*env)->CallDoubleMethod(env, yresObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, yres);
			g_object_set_property(G_OBJECT(op), "yres", &gvalue);
			g_value_unset(&gvalue);
		}

		// bigtiff
		jfieldID bigtiffFid = (*env)->GetFieldID(env, optionsCls, "bigtiff", "Ljava/lang/Boolean;");
		jobject bigtiffObjectValue = (*env)->GetObjectField(env, options, bigtiffFid);
		if (bigtiffObjectValue != NULL) {
			jboolean bigtiff = (*env)->CallBooleanMethod(env, bigtiffObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, bigtiff);
			g_object_set_property(G_OBJECT(op), "bigtiff", &gvalue);
			g_value_unset(&gvalue);
		}

		// properties
		jfieldID propertiesFid = (*env)->GetFieldID(env, optionsCls, "properties", "Ljava/lang/Boolean;");
		jobject propertiesObjectValue = (*env)->GetObjectField(env, options, propertiesFid);
		if (propertiesObjectValue != NULL) {
			jboolean properties = (*env)->CallBooleanMethod(env, propertiesObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, properties);
			g_object_set_property(G_OBJECT(op), "properties", &gvalue);
			g_value_unset(&gvalue);
		}

		// region-shrink
		jfieldID regionShrinkFid = (*env)->GetFieldID(env, optionsCls, "regionShrink", "Lcom/criteo/vips/enums/VipsRegionShrink;");
		jobject regionShrink = (*env)->GetObjectField(env, options, regionShrinkFid);
		if (regionShrink != NULL) {
			jclass regionShrinkCls = (*env)->GetObjectClass(env, regionShrink);
			jfieldID regionShrinkValueFid = (*env)->GetFieldID(env, regionShrinkCls, "value", "I");
			jint regionShrinkValue = (*env)->GetIntField(env, regionShrink, regionShrinkValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, regionShrinkValue);
			g_object_set_property(G_OBJECT(op), "region-shrink", &gvalue);
			g_value_unset(&gvalue);
		}

		// level
		jfieldID levelFid = (*env)->GetFieldID(env, optionsCls, "level", "Ljava/lang/Integer;");
		jobject levelObjectValue = (*env)->GetObjectField(env, options, levelFid);
		if (levelObjectValue != NULL) {
			jint level = (*env)->CallIntMethod(env, levelObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, level);
			g_object_set_property(G_OBJECT(op), "level", &gvalue);
			g_value_unset(&gvalue);
		}

		// lossless
		jfieldID losslessFid = (*env)->GetFieldID(env, optionsCls, "lossless", "Ljava/lang/Boolean;");
		jobject losslessObjectValue = (*env)->GetObjectField(env, options, losslessFid);
		if (losslessObjectValue != NULL) {
			jboolean lossless = (*env)->CallBooleanMethod(env, losslessObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, lossless);
			g_object_set_property(G_OBJECT(op), "lossless", &gvalue);
			g_value_unset(&gvalue);
		}

		// depth
		jfieldID depthFid = (*env)->GetFieldID(env, optionsCls, "depth", "Lcom/criteo/vips/enums/VipsForeignDzDepth;");
		jobject depth = (*env)->GetObjectField(env, options, depthFid);
		if (depth != NULL) {
			jclass depthCls = (*env)->GetObjectClass(env, depth);
			jfieldID depthValueFid = (*env)->GetFieldID(env, depthCls, "value", "I");
			jint depthValue = (*env)->GetIntField(env, depth, depthValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, depthValue);
			g_object_set_property(G_OBJECT(op), "depth", &gvalue);
			g_value_unset(&gvalue);
		}

		// subifd
		jfieldID subifdFid = (*env)->GetFieldID(env, optionsCls, "subifd", "Ljava/lang/Boolean;");
		jobject subifdObjectValue = (*env)->GetObjectField(env, options, subifdFid);
		if (subifdObjectValue != NULL) {
			jboolean subifd = (*env)->CallBooleanMethod(env, subifdObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, subifd);
			g_object_set_property(G_OBJECT(op), "subifd", &gvalue);
			g_value_unset(&gvalue);
		}

		// premultiply
		jfieldID premultiplyFid = (*env)->GetFieldID(env, optionsCls, "premultiply", "Ljava/lang/Boolean;");
		jobject premultiplyObjectValue = (*env)->GetObjectField(env, options, premultiplyFid);
		if (premultiplyObjectValue != NULL) {
			jboolean premultiply = (*env)->CallBooleanMethod(env, premultiplyObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, premultiply);
			g_object_set_property(G_OBJECT(op), "premultiply", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "tiffsave_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// buffer
	g_value_init(&gvalue, VIPS_TYPE_BLOB);
	g_object_get_property(G_OBJECT(op), "buffer", &gvalue);
	size_t bufferSize = 0;
	void *bufferData = vips_value_get_blob(&gvalue, &bufferSize);
	jint bufferLength = bufferSize / sizeof(jbyte);
	jbyteArray buffer = (*env)->NewByteArray(env, bufferLength);
	(*env)->SetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return buffer;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_tilecache(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("tilecache");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// tile-width
		jfieldID tileWidthFid = (*env)->GetFieldID(env, optionsCls, "tileWidth", "Ljava/lang/Integer;");
		jobject tileWidthObjectValue = (*env)->GetObjectField(env, options, tileWidthFid);
		if (tileWidthObjectValue != NULL) {
			jint tileWidth = (*env)->CallIntMethod(env, tileWidthObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileWidth);
			g_object_set_property(G_OBJECT(op), "tile-width", &gvalue);
			g_value_unset(&gvalue);
		}

		// tile-height
		jfieldID tileHeightFid = (*env)->GetFieldID(env, optionsCls, "tileHeight", "Ljava/lang/Integer;");
		jobject tileHeightObjectValue = (*env)->GetObjectField(env, options, tileHeightFid);
		if (tileHeightObjectValue != NULL) {
			jint tileHeight = (*env)->CallIntMethod(env, tileHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, tileHeight);
			g_object_set_property(G_OBJECT(op), "tile-height", &gvalue);
			g_value_unset(&gvalue);
		}

		// max-tiles
		jfieldID maxTilesFid = (*env)->GetFieldID(env, optionsCls, "maxTiles", "Ljava/lang/Integer;");
		jobject maxTilesObjectValue = (*env)->GetObjectField(env, options, maxTilesFid);
		if (maxTilesObjectValue != NULL) {
			jint maxTiles = (*env)->CallIntMethod(env, maxTilesObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, maxTiles);
			g_object_set_property(G_OBJECT(op), "max-tiles", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// threaded
		jfieldID threadedFid = (*env)->GetFieldID(env, optionsCls, "threaded", "Ljava/lang/Boolean;");
		jobject threadedObjectValue = (*env)->GetObjectField(env, options, threadedFid);
		if (threadedObjectValue != NULL) {
			jboolean threaded = (*env)->CallBooleanMethod(env, threadedObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, threaded);
			g_object_set_property(G_OBJECT(op), "threaded", &gvalue);
			g_value_unset(&gvalue);
		}

		// persistent
		jfieldID persistentFid = (*env)->GetFieldID(env, optionsCls, "persistent", "Ljava/lang/Boolean;");
		jobject persistentObjectValue = (*env)->GetObjectField(env, options, persistentFid);
		if (persistentObjectValue != NULL) {
			jboolean persistent = (*env)->CallBooleanMethod(env, persistentObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, persistent);
			g_object_set_property(G_OBJECT(op), "persistent", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "tilecache failed");
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
Java_com_criteo_vips_AbstractVipsImage_tonelut(JNIEnv *env, jclass cls, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("tonelut");

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// in-max
		jfieldID inMaxFid = (*env)->GetFieldID(env, optionsCls, "inMax", "Ljava/lang/Integer;");
		jobject inMaxObjectValue = (*env)->GetObjectField(env, options, inMaxFid);
		if (inMaxObjectValue != NULL) {
			jint inMax = (*env)->CallIntMethod(env, inMaxObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, inMax);
			g_object_set_property(G_OBJECT(op), "in-max", &gvalue);
			g_value_unset(&gvalue);
		}

		// out-max
		jfieldID outMaxFid = (*env)->GetFieldID(env, optionsCls, "outMax", "Ljava/lang/Integer;");
		jobject outMaxObjectValue = (*env)->GetObjectField(env, options, outMaxFid);
		if (outMaxObjectValue != NULL) {
			jint outMax = (*env)->CallIntMethod(env, outMaxObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, outMax);
			g_object_set_property(G_OBJECT(op), "out-max", &gvalue);
			g_value_unset(&gvalue);
		}

		// Lb
		jfieldID lbFid = (*env)->GetFieldID(env, optionsCls, "lb", "Ljava/lang/Double;");
		jobject lbObjectValue = (*env)->GetObjectField(env, options, lbFid);
		if (lbObjectValue != NULL) {
			jdouble lb = (*env)->CallDoubleMethod(env, lbObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, lb);
			g_object_set_property(G_OBJECT(op), "Lb", &gvalue);
			g_value_unset(&gvalue);
		}

		// Lw
		jfieldID lwFid = (*env)->GetFieldID(env, optionsCls, "lw", "Ljava/lang/Double;");
		jobject lwObjectValue = (*env)->GetObjectField(env, options, lwFid);
		if (lwObjectValue != NULL) {
			jdouble lw = (*env)->CallDoubleMethod(env, lwObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, lw);
			g_object_set_property(G_OBJECT(op), "Lw", &gvalue);
			g_value_unset(&gvalue);
		}

		// Ps
		jfieldID psFid = (*env)->GetFieldID(env, optionsCls, "ps", "Ljava/lang/Double;");
		jobject psObjectValue = (*env)->GetObjectField(env, options, psFid);
		if (psObjectValue != NULL) {
			jdouble ps = (*env)->CallDoubleMethod(env, psObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, ps);
			g_object_set_property(G_OBJECT(op), "Ps", &gvalue);
			g_value_unset(&gvalue);
		}

		// Pm
		jfieldID pmFid = (*env)->GetFieldID(env, optionsCls, "pm", "Ljava/lang/Double;");
		jobject pmObjectValue = (*env)->GetObjectField(env, options, pmFid);
		if (pmObjectValue != NULL) {
			jdouble pm = (*env)->CallDoubleMethod(env, pmObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, pm);
			g_object_set_property(G_OBJECT(op), "Pm", &gvalue);
			g_value_unset(&gvalue);
		}

		// Ph
		jfieldID phFid = (*env)->GetFieldID(env, optionsCls, "ph", "Ljava/lang/Double;");
		jobject phObjectValue = (*env)->GetObjectField(env, options, phFid);
		if (phObjectValue != NULL) {
			jdouble ph = (*env)->CallDoubleMethod(env, phObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, ph);
			g_object_set_property(G_OBJECT(op), "Ph", &gvalue);
			g_value_unset(&gvalue);
		}

		// S
		jfieldID sFid = (*env)->GetFieldID(env, optionsCls, "s", "Ljava/lang/Double;");
		jobject sObjectValue = (*env)->GetObjectField(env, options, sFid);
		if (sObjectValue != NULL) {
			jdouble s = (*env)->CallDoubleMethod(env, sObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, s);
			g_object_set_property(G_OBJECT(op), "S", &gvalue);
			g_value_unset(&gvalue);
		}

		// M
		jfieldID mFid = (*env)->GetFieldID(env, optionsCls, "m", "Ljava/lang/Double;");
		jobject mObjectValue = (*env)->GetObjectField(env, options, mFid);
		if (mObjectValue != NULL) {
			jdouble m = (*env)->CallDoubleMethod(env, mObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, m);
			g_object_set_property(G_OBJECT(op), "M", &gvalue);
			g_value_unset(&gvalue);
		}

		// H
		jfieldID hFid = (*env)->GetFieldID(env, optionsCls, "h", "Ljava/lang/Double;");
		jobject hObjectValue = (*env)->GetObjectField(env, options, hFid);
		if (hObjectValue != NULL) {
			jdouble h = (*env)->CallDoubleMethod(env, hObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, h);
			g_object_set_property(G_OBJECT(op), "H", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "tonelut failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_transpose3d(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("transpose3d");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "transpose3d failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_unpremultiply(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("unpremultiply");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// max-alpha
		jfieldID maxAlphaFid = (*env)->GetFieldID(env, optionsCls, "maxAlpha", "Ljava/lang/Double;");
		jobject maxAlphaObjectValue = (*env)->GetObjectField(env, options, maxAlphaFid);
		if (maxAlphaObjectValue != NULL) {
			jdouble maxAlpha = (*env)->CallDoubleMethod(env, maxAlphaObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, maxAlpha);
			g_object_set_property(G_OBJECT(op), "max-alpha", &gvalue);
			g_value_unset(&gvalue);
		}

		// alpha-band
		jfieldID alphaBandFid = (*env)->GetFieldID(env, optionsCls, "alphaBand", "Ljava/lang/Integer;");
		jobject alphaBandObjectValue = (*env)->GetObjectField(env, options, alphaBandFid);
		if (alphaBandObjectValue != NULL) {
			jint alphaBand = (*env)->CallIntMethod(env, alphaBandObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, alphaBand);
			g_object_set_property(G_OBJECT(op), "alpha-band", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "unpremultiply failed");
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
Java_com_criteo_vips_AbstractVipsImage_vipsLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("vipsload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "vipsload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_vipsSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("vipssave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "vipssave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_webpLoad(JNIEnv *env, jclass cls, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("webpload");

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// n
		jfieldID nFid = (*env)->GetFieldID(env, optionsCls, "n", "Ljava/lang/Integer;");
		jobject nObjectValue = (*env)->GetObjectField(env, options, nFid);
		if (nObjectValue != NULL) {
			jint n = (*env)->CallIntMethod(env, nObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, n);
			g_object_set_property(G_OBJECT(op), "n", &gvalue);
			g_value_unset(&gvalue);
		}

		// scale
		jfieldID scaleFid = (*env)->GetFieldID(env, optionsCls, "scale", "Ljava/lang/Double;");
		jobject scaleObjectValue = (*env)->GetObjectField(env, options, scaleFid);
		if (scaleObjectValue != NULL) {
			jdouble scale = (*env)->CallDoubleMethod(env, scaleObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, scale);
			g_object_set_property(G_OBJECT(op), "scale", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "webpload failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_webpLoadBuffer(JNIEnv *env, jclass cls, jbyteArray buffer, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("webpload_buffer");

	// buffer
	if (buffer != NULL) {
		jint bufferLength = (*env)->GetArrayLength(env, buffer);
		size_t bufferSize = bufferLength * sizeof(jbyte);
		void *bufferData = vips_tracked_malloc(bufferSize);
		if (bufferData == NULL) {
			throwVipsException(env, "Failed to allocate memory for buffer");
		}
		(*env)->GetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
		g_value_init(&gvalue, VIPS_TYPE_BLOB);
		vips_value_set_blob_free(&gvalue, bufferData, bufferSize);
		g_object_set_property(G_OBJECT(op), "buffer", &gvalue);
		g_value_unset(&gvalue);
	
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// page
		jfieldID pageFid = (*env)->GetFieldID(env, optionsCls, "page", "Ljava/lang/Integer;");
		jobject pageObjectValue = (*env)->GetObjectField(env, options, pageFid);
		if (pageObjectValue != NULL) {
			jint page = (*env)->CallIntMethod(env, pageObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, page);
			g_object_set_property(G_OBJECT(op), "page", &gvalue);
			g_value_unset(&gvalue);
		}

		// n
		jfieldID nFid = (*env)->GetFieldID(env, optionsCls, "n", "Ljava/lang/Integer;");
		jobject nObjectValue = (*env)->GetObjectField(env, options, nFid);
		if (nObjectValue != NULL) {
			jint n = (*env)->CallIntMethod(env, nObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, n);
			g_object_set_property(G_OBJECT(op), "n", &gvalue);
			g_value_unset(&gvalue);
		}

		// scale
		jfieldID scaleFid = (*env)->GetFieldID(env, optionsCls, "scale", "Ljava/lang/Double;");
		jobject scaleObjectValue = (*env)->GetObjectField(env, options, scaleFid);
		if (scaleObjectValue != NULL) {
			jdouble scale = (*env)->CallDoubleMethod(env, scaleObjectValue, doubleValue_mid);
			g_value_init(&gvalue, G_TYPE_DOUBLE);
			g_value_set_double(&gvalue, scale);
			g_object_set_property(G_OBJECT(op), "scale", &gvalue);
			g_value_unset(&gvalue);
		}

		// memory
		jfieldID memoryFid = (*env)->GetFieldID(env, optionsCls, "memory", "Ljava/lang/Boolean;");
		jobject memoryObjectValue = (*env)->GetObjectField(env, options, memoryFid);
		if (memoryObjectValue != NULL) {
			jboolean memory = (*env)->CallBooleanMethod(env, memoryObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, memory);
			g_object_set_property(G_OBJECT(op), "memory", &gvalue);
			g_value_unset(&gvalue);
		}

		// access
		jfieldID accessFid = (*env)->GetFieldID(env, optionsCls, "access", "Lcom/criteo/vips/enums/VipsAccess;");
		jobject access = (*env)->GetObjectField(env, options, accessFid);
		if (access != NULL) {
			jclass accessCls = (*env)->GetObjectClass(env, access);
			jfieldID accessValueFid = (*env)->GetFieldID(env, accessCls, "value", "I");
			jint accessValue = (*env)->GetIntField(env, access, accessValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, accessValue);
			g_object_set_property(G_OBJECT(op), "access", &gvalue);
			g_value_unset(&gvalue);
		}

		// fail-on
		jfieldID failOnFid = (*env)->GetFieldID(env, optionsCls, "failOn", "Lcom/criteo/vips/enums/VipsFailOn;");
		jobject failOn = (*env)->GetObjectField(env, options, failOnFid);
		if (failOn != NULL) {
			jclass failOnCls = (*env)->GetObjectClass(env, failOn);
			jfieldID failOnValueFid = (*env)->GetFieldID(env, failOnCls, "value", "I");
			jint failOnValue = (*env)->GetIntField(env, failOn, failOnValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, failOnValue);
			g_object_set_property(G_OBJECT(op), "fail-on", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "webpload_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_webpSave(JNIEnv *env, jobject in, jstring filename, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("webpsave");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// filename
	if (filename != NULL) {
		const char *filenameChars = (*env)->GetStringUTFChars(env, filename, NULL);
		g_value_init(&gvalue, G_TYPE_STRING);
		g_value_set_string(&gvalue, filenameChars);
		(*env)->ReleaseStringUTFChars(env, filename, filenameChars);
		g_object_set_property(G_OBJECT(op), "filename", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// lossless
		jfieldID losslessFid = (*env)->GetFieldID(env, optionsCls, "lossless", "Ljava/lang/Boolean;");
		jobject losslessObjectValue = (*env)->GetObjectField(env, options, losslessFid);
		if (losslessObjectValue != NULL) {
			jboolean lossless = (*env)->CallBooleanMethod(env, losslessObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, lossless);
			g_object_set_property(G_OBJECT(op), "lossless", &gvalue);
			g_value_unset(&gvalue);
		}

		// preset
		jfieldID presetFid = (*env)->GetFieldID(env, optionsCls, "preset", "Lcom/criteo/vips/enums/VipsForeignWebpPreset;");
		jobject preset = (*env)->GetObjectField(env, options, presetFid);
		if (preset != NULL) {
			jclass presetCls = (*env)->GetObjectClass(env, preset);
			jfieldID presetValueFid = (*env)->GetFieldID(env, presetCls, "value", "I");
			jint presetValue = (*env)->GetIntField(env, preset, presetValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, presetValue);
			g_object_set_property(G_OBJECT(op), "preset", &gvalue);
			g_value_unset(&gvalue);
		}

		// smart-subsample
		jfieldID smartSubsampleFid = (*env)->GetFieldID(env, optionsCls, "smartSubsample", "Ljava/lang/Boolean;");
		jobject smartSubsampleObjectValue = (*env)->GetObjectField(env, options, smartSubsampleFid);
		if (smartSubsampleObjectValue != NULL) {
			jboolean smartSubsample = (*env)->CallBooleanMethod(env, smartSubsampleObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, smartSubsample);
			g_object_set_property(G_OBJECT(op), "smart-subsample", &gvalue);
			g_value_unset(&gvalue);
		}

		// near-lossless
		jfieldID nearLosslessFid = (*env)->GetFieldID(env, optionsCls, "nearLossless", "Ljava/lang/Boolean;");
		jobject nearLosslessObjectValue = (*env)->GetObjectField(env, options, nearLosslessFid);
		if (nearLosslessObjectValue != NULL) {
			jboolean nearLossless = (*env)->CallBooleanMethod(env, nearLosslessObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, nearLossless);
			g_object_set_property(G_OBJECT(op), "near-lossless", &gvalue);
			g_value_unset(&gvalue);
		}

		// alpha-q
		jfieldID alphaQFid = (*env)->GetFieldID(env, optionsCls, "alphaQ", "Ljava/lang/Integer;");
		jobject alphaQObjectValue = (*env)->GetObjectField(env, options, alphaQFid);
		if (alphaQObjectValue != NULL) {
			jint alphaQ = (*env)->CallIntMethod(env, alphaQObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, alphaQ);
			g_object_set_property(G_OBJECT(op), "alpha-q", &gvalue);
			g_value_unset(&gvalue);
		}

		// min-size
		jfieldID minSizeFid = (*env)->GetFieldID(env, optionsCls, "minSize", "Ljava/lang/Boolean;");
		jobject minSizeObjectValue = (*env)->GetObjectField(env, options, minSizeFid);
		if (minSizeObjectValue != NULL) {
			jboolean minSize = (*env)->CallBooleanMethod(env, minSizeObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, minSize);
			g_object_set_property(G_OBJECT(op), "min-size", &gvalue);
			g_value_unset(&gvalue);
		}

		// kmin
		jfieldID kminFid = (*env)->GetFieldID(env, optionsCls, "kmin", "Ljava/lang/Integer;");
		jobject kminObjectValue = (*env)->GetObjectField(env, options, kminFid);
		if (kminObjectValue != NULL) {
			jint kmin = (*env)->CallIntMethod(env, kminObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, kmin);
			g_object_set_property(G_OBJECT(op), "kmin", &gvalue);
			g_value_unset(&gvalue);
		}

		// kmax
		jfieldID kmaxFid = (*env)->GetFieldID(env, optionsCls, "kmax", "Ljava/lang/Integer;");
		jobject kmaxObjectValue = (*env)->GetObjectField(env, options, kmaxFid);
		if (kmaxObjectValue != NULL) {
			jint kmax = (*env)->CallIntMethod(env, kmaxObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, kmax);
			g_object_set_property(G_OBJECT(op), "kmax", &gvalue);
			g_value_unset(&gvalue);
		}

		// effort
		jfieldID effortFid = (*env)->GetFieldID(env, optionsCls, "effort", "Ljava/lang/Integer;");
		jobject effortObjectValue = (*env)->GetObjectField(env, options, effortFid);
		if (effortObjectValue != NULL) {
			jint effort = (*env)->CallIntMethod(env, effortObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, effort);
			g_object_set_property(G_OBJECT(op), "effort", &gvalue);
			g_value_unset(&gvalue);
		}

		// profile
		jfieldID profileFid = (*env)->GetFieldID(env, optionsCls, "profile", "Ljava/lang/String;");
		jstring profile = (jstring) (*env)->GetObjectField(env, options, profileFid);
		if (profile != NULL) {
			const char *profileChars = (*env)->GetStringUTFChars(env, profile, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, profileChars);
			(*env)->ReleaseStringUTFChars(env, profile, profileChars);
			g_object_set_property(G_OBJECT(op), "profile", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "webpsave failed");
		return;
	}
	g_object_unref(op);
	op = new_op;


	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}

JNIEXPORT jbyteArray JNICALL
Java_com_criteo_vips_AbstractVipsImage_webpSaveBuffer(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("webpsave_buffer");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// Q
		jfieldID qFid = (*env)->GetFieldID(env, optionsCls, "q", "Ljava/lang/Integer;");
		jobject qObjectValue = (*env)->GetObjectField(env, options, qFid);
		if (qObjectValue != NULL) {
			jint q = (*env)->CallIntMethod(env, qObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, q);
			g_object_set_property(G_OBJECT(op), "Q", &gvalue);
			g_value_unset(&gvalue);
		}

		// lossless
		jfieldID losslessFid = (*env)->GetFieldID(env, optionsCls, "lossless", "Ljava/lang/Boolean;");
		jobject losslessObjectValue = (*env)->GetObjectField(env, options, losslessFid);
		if (losslessObjectValue != NULL) {
			jboolean lossless = (*env)->CallBooleanMethod(env, losslessObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, lossless);
			g_object_set_property(G_OBJECT(op), "lossless", &gvalue);
			g_value_unset(&gvalue);
		}

		// preset
		jfieldID presetFid = (*env)->GetFieldID(env, optionsCls, "preset", "Lcom/criteo/vips/enums/VipsForeignWebpPreset;");
		jobject preset = (*env)->GetObjectField(env, options, presetFid);
		if (preset != NULL) {
			jclass presetCls = (*env)->GetObjectClass(env, preset);
			jfieldID presetValueFid = (*env)->GetFieldID(env, presetCls, "value", "I");
			jint presetValue = (*env)->GetIntField(env, preset, presetValueFid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, presetValue);
			g_object_set_property(G_OBJECT(op), "preset", &gvalue);
			g_value_unset(&gvalue);
		}

		// smart-subsample
		jfieldID smartSubsampleFid = (*env)->GetFieldID(env, optionsCls, "smartSubsample", "Ljava/lang/Boolean;");
		jobject smartSubsampleObjectValue = (*env)->GetObjectField(env, options, smartSubsampleFid);
		if (smartSubsampleObjectValue != NULL) {
			jboolean smartSubsample = (*env)->CallBooleanMethod(env, smartSubsampleObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, smartSubsample);
			g_object_set_property(G_OBJECT(op), "smart-subsample", &gvalue);
			g_value_unset(&gvalue);
		}

		// near-lossless
		jfieldID nearLosslessFid = (*env)->GetFieldID(env, optionsCls, "nearLossless", "Ljava/lang/Boolean;");
		jobject nearLosslessObjectValue = (*env)->GetObjectField(env, options, nearLosslessFid);
		if (nearLosslessObjectValue != NULL) {
			jboolean nearLossless = (*env)->CallBooleanMethod(env, nearLosslessObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, nearLossless);
			g_object_set_property(G_OBJECT(op), "near-lossless", &gvalue);
			g_value_unset(&gvalue);
		}

		// alpha-q
		jfieldID alphaQFid = (*env)->GetFieldID(env, optionsCls, "alphaQ", "Ljava/lang/Integer;");
		jobject alphaQObjectValue = (*env)->GetObjectField(env, options, alphaQFid);
		if (alphaQObjectValue != NULL) {
			jint alphaQ = (*env)->CallIntMethod(env, alphaQObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, alphaQ);
			g_object_set_property(G_OBJECT(op), "alpha-q", &gvalue);
			g_value_unset(&gvalue);
		}

		// min-size
		jfieldID minSizeFid = (*env)->GetFieldID(env, optionsCls, "minSize", "Ljava/lang/Boolean;");
		jobject minSizeObjectValue = (*env)->GetObjectField(env, options, minSizeFid);
		if (minSizeObjectValue != NULL) {
			jboolean minSize = (*env)->CallBooleanMethod(env, minSizeObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, minSize);
			g_object_set_property(G_OBJECT(op), "min-size", &gvalue);
			g_value_unset(&gvalue);
		}

		// kmin
		jfieldID kminFid = (*env)->GetFieldID(env, optionsCls, "kmin", "Ljava/lang/Integer;");
		jobject kminObjectValue = (*env)->GetObjectField(env, options, kminFid);
		if (kminObjectValue != NULL) {
			jint kmin = (*env)->CallIntMethod(env, kminObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, kmin);
			g_object_set_property(G_OBJECT(op), "kmin", &gvalue);
			g_value_unset(&gvalue);
		}

		// kmax
		jfieldID kmaxFid = (*env)->GetFieldID(env, optionsCls, "kmax", "Ljava/lang/Integer;");
		jobject kmaxObjectValue = (*env)->GetObjectField(env, options, kmaxFid);
		if (kmaxObjectValue != NULL) {
			jint kmax = (*env)->CallIntMethod(env, kmaxObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, kmax);
			g_object_set_property(G_OBJECT(op), "kmax", &gvalue);
			g_value_unset(&gvalue);
		}

		// effort
		jfieldID effortFid = (*env)->GetFieldID(env, optionsCls, "effort", "Ljava/lang/Integer;");
		jobject effortObjectValue = (*env)->GetObjectField(env, options, effortFid);
		if (effortObjectValue != NULL) {
			jint effort = (*env)->CallIntMethod(env, effortObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, effort);
			g_object_set_property(G_OBJECT(op), "effort", &gvalue);
			g_value_unset(&gvalue);
		}

		// profile
		jfieldID profileFid = (*env)->GetFieldID(env, optionsCls, "profile", "Ljava/lang/String;");
		jstring profile = (jstring) (*env)->GetObjectField(env, options, profileFid);
		if (profile != NULL) {
			const char *profileChars = (*env)->GetStringUTFChars(env, profile, NULL);
			g_value_init(&gvalue, G_TYPE_STRING);
			g_value_set_string(&gvalue, profileChars);
			(*env)->ReleaseStringUTFChars(env, profile, profileChars);
			g_object_set_property(G_OBJECT(op), "profile", &gvalue);
			g_value_unset(&gvalue);
		}

		// strip
		jfieldID stripFid = (*env)->GetFieldID(env, optionsCls, "strip", "Ljava/lang/Boolean;");
		jobject stripObjectValue = (*env)->GetObjectField(env, options, stripFid);
		if (stripObjectValue != NULL) {
			jboolean strip = (*env)->CallBooleanMethod(env, stripObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, strip);
			g_object_set_property(G_OBJECT(op), "strip", &gvalue);
			g_value_unset(&gvalue);
		}

		// background
		jfieldID backgroundFid = (*env)->GetFieldID(env, optionsCls, "background", "Lcom/criteo/vips/PixelPacket;");
		jobject background = (*env)->GetObjectField(env, options, backgroundFid);
		if (background != NULL) {
			jdouble *backgroundElements = (*env)->GetDoubleArrayElements(env, background, NULL);
			jint backgroundLength = (*env)->GetArrayLength(env, background);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, backgroundElements, backgroundLength);
			(*env)->ReleaseDoubleArrayElements(env, background, backgroundElements, 0);
			g_object_set_property(G_OBJECT(op), "background", &gvalue);
			g_value_unset(&gvalue);
		}

		// page-height
		jfieldID pageHeightFid = (*env)->GetFieldID(env, optionsCls, "pageHeight", "Ljava/lang/Integer;");
		jobject pageHeightObjectValue = (*env)->GetObjectField(env, options, pageHeightFid);
		if (pageHeightObjectValue != NULL) {
			jint pageHeight = (*env)->CallIntMethod(env, pageHeightObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, pageHeight);
			g_object_set_property(G_OBJECT(op), "page-height", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "webpsave_buffer failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// buffer
	g_value_init(&gvalue, VIPS_TYPE_BLOB);
	g_object_get_property(G_OBJECT(op), "buffer", &gvalue);
	size_t bufferSize = 0;
	void *bufferData = vips_value_get_blob(&gvalue, &bufferSize);
	jint bufferLength = bufferSize / sizeof(jbyte);
	jbyteArray buffer = (*env)->NewByteArray(env, bufferLength);
	(*env)->SetByteArrayRegion(env, buffer, 0, bufferLength, bufferData);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return buffer;
}

JNIEXPORT jobject JNICALL
Java_com_criteo_vips_AbstractVipsImage_worley(JNIEnv *env, jclass cls, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("worley");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// cell-size
		jfieldID cellSizeFid = (*env)->GetFieldID(env, optionsCls, "cellSize", "Ljava/lang/Integer;");
		jobject cellSizeObjectValue = (*env)->GetObjectField(env, options, cellSizeFid);
		if (cellSizeObjectValue != NULL) {
			jint cellSize = (*env)->CallIntMethod(env, cellSizeObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, cellSize);
			g_object_set_property(G_OBJECT(op), "cell-size", &gvalue);
			g_value_unset(&gvalue);
		}

		// seed
		jfieldID seedFid = (*env)->GetFieldID(env, optionsCls, "seed", "Ljava/lang/Integer;");
		jobject seedObjectValue = (*env)->GetObjectField(env, options, seedFid);
		if (seedObjectValue != NULL) {
			jint seed = (*env)->CallIntMethod(env, seedObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, seed);
			g_object_set_property(G_OBJECT(op), "seed", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "worley failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_wrap(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("wrap");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// x
		jfieldID xFid = (*env)->GetFieldID(env, optionsCls, "x", "Ljava/lang/Integer;");
		jobject xObjectValue = (*env)->GetObjectField(env, options, xFid);
		if (xObjectValue != NULL) {
			jint x = (*env)->CallIntMethod(env, xObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, x);
			g_object_set_property(G_OBJECT(op), "x", &gvalue);
			g_value_unset(&gvalue);
		}

		// y
		jfieldID yFid = (*env)->GetFieldID(env, optionsCls, "y", "Ljava/lang/Integer;");
		jobject yObjectValue = (*env)->GetObjectField(env, options, yFid);
		if (yObjectValue != NULL) {
			jint y = (*env)->CallIntMethod(env, yObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, y);
			g_object_set_property(G_OBJECT(op), "y", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "wrap failed");
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
Java_com_criteo_vips_AbstractVipsImage_xyz(JNIEnv *env, jclass cls, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("xyz");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// csize
		jfieldID csizeFid = (*env)->GetFieldID(env, optionsCls, "csize", "Ljava/lang/Integer;");
		jobject csizeObjectValue = (*env)->GetObjectField(env, options, csizeFid);
		if (csizeObjectValue != NULL) {
			jint csize = (*env)->CallIntMethod(env, csizeObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, csize);
			g_object_set_property(G_OBJECT(op), "csize", &gvalue);
			g_value_unset(&gvalue);
		}

		// dsize
		jfieldID dsizeFid = (*env)->GetFieldID(env, optionsCls, "dsize", "Ljava/lang/Integer;");
		jobject dsizeObjectValue = (*env)->GetObjectField(env, options, dsizeFid);
		if (dsizeObjectValue != NULL) {
			jint dsize = (*env)->CallIntMethod(env, dsizeObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, dsize);
			g_object_set_property(G_OBJECT(op), "dsize", &gvalue);
			g_value_unset(&gvalue);
		}

		// esize
		jfieldID esizeFid = (*env)->GetFieldID(env, optionsCls, "esize", "Ljava/lang/Integer;");
		jobject esizeObjectValue = (*env)->GetObjectField(env, options, esizeFid);
		if (esizeObjectValue != NULL) {
			jint esize = (*env)->CallIntMethod(env, esizeObjectValue, intValue_mid);
			g_value_init(&gvalue, G_TYPE_INT);
			g_value_set_int(&gvalue, esize);
			g_object_set_property(G_OBJECT(op), "esize", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "xyz failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_xyz2cmyk(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("XYZ2CMYK");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "XYZ2CMYK failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_xYZ2Lab(JNIEnv *env, jobject in, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("XYZ2Lab");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// temp
		jfieldID tempFid = (*env)->GetFieldID(env, optionsCls, "temp", "Lcom/criteo/vips/PixelPacket;");
		jobject temp = (*env)->GetObjectField(env, options, tempFid);
		if (temp != NULL) {
			jdouble *tempElements = (*env)->GetDoubleArrayElements(env, temp, NULL);
			jint tempLength = (*env)->GetArrayLength(env, temp);
			g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
			vips_value_set_array_double(&gvalue, tempElements, tempLength);
			(*env)->ReleaseDoubleArrayElements(env, temp, tempElements, 0);
			g_object_set_property(G_OBJECT(op), "temp", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "XYZ2Lab failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_xYZ2scRGB(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("XYZ2scRGB");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "XYZ2scRGB failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_xYZ2Yxy(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("XYZ2Yxy");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "XYZ2Yxy failed");
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

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_yxy2XYZ(JNIEnv *env, jobject in)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("Yxy2XYZ");

	// in
	if (in != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, in, handle_fid));
		g_object_set_property(G_OBJECT(op), "in", &gvalue);
		g_value_unset(&gvalue);
	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "Yxy2XYZ failed");
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
Java_com_criteo_vips_AbstractVipsImage_zone(JNIEnv *env, jclass cls, jint width, jint height, jobject options)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("zone");

	// width
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, width);
	g_object_set_property(G_OBJECT(op), "width", &gvalue);
	g_value_unset(&gvalue);

	// height
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, height);
	g_object_set_property(G_OBJECT(op), "height", &gvalue);
	g_value_unset(&gvalue);

	// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

		// uchar
		jfieldID ucharFid = (*env)->GetFieldID(env, optionsCls, "uchar", "Ljava/lang/Boolean;");
		jobject ucharObjectValue = (*env)->GetObjectField(env, options, ucharFid);
		if (ucharObjectValue != NULL) {
			jboolean uchar = (*env)->CallBooleanMethod(env, ucharObjectValue, booleanValue_mid);
			g_value_init(&gvalue, G_TYPE_BOOLEAN);
			g_value_set_boolean(&gvalue, uchar);
			g_object_set_property(G_OBJECT(op), "uchar", &gvalue);
			g_value_unset(&gvalue);
		}

	}

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "zone failed");
		return NULL;
	}
	g_object_unref(op);
	op = new_op;

	// out
	g_value_init(&gvalue, VIPS_TYPE_IMAGE);
	g_object_get_property(G_OBJECT(op), "out", &gvalue);
	VipsImage *out = VIPS_IMAGE(g_value_get_object(&gvalue));
	g_object_ref(out);
	g_value_unset(&gvalue);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

	// Output
	return (*env)->NewObject(env, cls, ctor_mid, (jlong) out);
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_zoom(JNIEnv *env, jobject input, jint xfac, jint yfac)
{
	GValue gvalue = { 0 };

	VipsOperation *op = vips_operation_new("zoom");

	// input
	if (input != NULL) {
		g_value_init(&gvalue, VIPS_TYPE_IMAGE);
		g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, input, handle_fid));
		g_object_set_property(G_OBJECT(op), "input", &gvalue);
		g_value_unset(&gvalue);
	}

	// xfac
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, xfac);
	g_object_set_property(G_OBJECT(op), "xfac", &gvalue);
	g_value_unset(&gvalue);

	// yfac
	g_value_init(&gvalue, G_TYPE_INT);
	g_value_set_int(&gvalue, yfac);
	g_object_set_property(G_OBJECT(op), "yfac", &gvalue);
	g_value_unset(&gvalue);

	// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "zoom failed");
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
	g_object_unref((VipsImage *) (*env)->GetLongField(env, input, handle_fid));
	(*env)->SetLongField(env, input, handle_fid, (jlong) _out);

	// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

}
