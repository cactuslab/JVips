import { operationInfo } from "./common"
import { COPYRIGHT } from "./constants"
import { javaOperationIdentifier, javaParameterIdentifier } from "./java"
import { VipsOperation, VipsOperationInfo, VipsOperationOptions, VipsOperationParameter } from "./type"
import { indent, isEnum, camelCase } from "./utils"

function jniTypeForParameter(p: VipsOperationParameter): string {
	if (isEnum(p)) {
		return 'jobject'
	}

	switch (p.type) {
		case 'gboolean': return 'jboolean'
		case 'gint': return 'jint'
		case 'gdouble': return 'jdouble'
		case 'guint64': return 'jlong' // TODO longs are uint64 they're int64
		case 'gchararray': return 'jstring'
		case 'VipsImage': return 'jobject'
		case 'VipsArrayInt': return 'jintArray'
		case 'VipsArrayDouble': return 'jdoubleArray'
		case 'VipsArrayImage': return 'jobjectArray'
		case 'VipsBlob': return 'jbyteArray'
		case 'Rectangle': return 'jobject' /* A special handling for find_trim, which returns a Rectangle */
	}
	throw new Error(`Unsupported JNI parameter type '${p.type}' for parameter '${p.name}'`)
}

function wrappedJniTypeCodeForParameter(p: VipsOperationParameter): string {
	if (isEnum(p)) {
		return `Lcom/criteo/vips/enums/${p.type};`
	}

	switch (p.type) {
		case 'gboolean': return 'Ljava/lang/Boolean;'
		case 'gint': return 'Ljava/lang/Integer;'
		case 'gdouble': return 'Ljava/lang/Double;'
		case 'guint64': return 'Ljava/lang/Long;' // TODO longs are uint64 they're int64
		case 'gchararray': return 'Ljava/lang/String;'
		case 'VipsImage': return 'Lcom/criteo/vips/VipsImage;'
		case 'VipsArrayInt': return '[I'
		case 'VipsArrayDouble': return '[D'
		case 'VipsArrayImage': return '[Lcom/criteo/vips/Image;'
	}
	throw new Error(`Unsupported JNI wrapping parameter type '${p.type}' for parameter '${p.name}'`)
}

function isObjectType(p: VipsOperationParameter) {
	const jniType = jniTypeForParameter(p)
	return jniType === 'jobject' || jniType === 'jstring' || jniType.endsWith('Array')
}

function applyParameter(p: VipsOperationParameter): string {
	if (isObjectType(p)) {
		return `if (${camelCase(p.name)} != NULL) {
${indent(applyParameterInternal(), '\t')}
}`
	} else {
		return applyParameterInternal()
	}

	function applyParameterInternal() {
		if (isEnum(p)) {
			return `jclass ${camelCase(p.name)}Cls = (*env)->GetObjectClass(env, ${camelCase(p.name)});
jfieldID ${camelCase(p.name)}ValueFid = (*env)->GetFieldID(env, ${camelCase(p.name)}Cls, "value", "I");
jint ${camelCase(p.name)}Value = (*env)->GetIntField(env, ${camelCase(p.name)}, ${camelCase(p.name)}ValueFid);
g_value_init(&gvalue, G_TYPE_INT);
g_value_set_int(&gvalue, ${camelCase(p.name)}Value);
g_object_set_property(G_OBJECT(op), "${p.name}", &gvalue);
g_value_unset(&gvalue);`
		}

		/*
		Reference VImage.cpp for G_TYPEs etc
		*/
		switch (p.type) {
			case 'VipsImage':
				return `g_value_init(&gvalue, VIPS_TYPE_IMAGE);
g_value_set_object(&gvalue, (VipsImage *) (*env)->GetLongField(env, ${camelCase(p.name)}, handle_fid));
g_object_set_property(G_OBJECT(op), "${p.name}", &gvalue);
g_value_unset(&gvalue);`
			case 'gint':
				return applyPrimitiveParameter(p, 'G_TYPE_INT', 'g_value_set_int')
			case 'gdouble':
				return applyPrimitiveParameter(p, 'G_TYPE_DOUBLE', 'g_value_set_double')
			case 'guint64':
				return applyPrimitiveParameter(p, 'G_TYPE_UINT64', 'g_value_set_uint64')
			case 'gboolean':
				return applyPrimitiveParameter(p, 'G_TYPE_BOOLEAN', 'g_value_set_boolean')
			case 'gchararray':
				return `const char *${camelCase(p.name)}Chars = (*env)->GetStringUTFChars(env, ${camelCase(p.name)}, NULL);
g_value_init(&gvalue, G_TYPE_STRING);
g_value_set_string(&gvalue, ${camelCase(p.name)}Chars);
(*env)->ReleaseStringUTFChars(env, ${camelCase(p.name)}, ${camelCase(p.name)}Chars);
g_object_set_property(G_OBJECT(op), "${p.name}", &gvalue);
g_value_unset(&gvalue);`
			case 'VipsArrayInt':
				return `jint *${camelCase(p.name)}Elements = (*env)->GetIntArrayElements(env, ${camelCase(p.name)}, NULL);
jint ${camelCase(p.name)}Length = (*env)->GetArrayLength(env, ${camelCase(p.name)});
g_value_init(&gvalue, VIPS_TYPE_ARRAY_INT);
vips_value_set_array_int(&gvalue, ${camelCase(p.name)}Elements, ${camelCase(p.name)}Length);
(*env)->ReleaseIntArrayElements(env, ${camelCase(p.name)}, ${camelCase(p.name)}Elements, 0);
g_object_set_property(G_OBJECT(op), "${p.name}", &gvalue);
g_value_unset(&gvalue);`
			case 'VipsArrayDouble':
				return `jdouble *${camelCase(p.name)}Elements = (*env)->GetDoubleArrayElements(env, ${camelCase(p.name)}, NULL);
jint ${camelCase(p.name)}Length = (*env)->GetArrayLength(env, ${camelCase(p.name)});
g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
vips_value_set_array_double(&gvalue, ${camelCase(p.name)}Elements, ${camelCase(p.name)}Length);
(*env)->ReleaseDoubleArrayElements(env, ${camelCase(p.name)}, ${camelCase(p.name)}Elements, 0);
g_object_set_property(G_OBJECT(op), "${p.name}", &gvalue);
g_value_unset(&gvalue);`
			case 'VipsArrayImage':
				return `jint ${camelCase(p.name)}Length = (*env)->GetArrayLength(env, ${camelCase(p.name)});
g_value_init(&gvalue, VIPS_TYPE_ARRAY_IMAGE);
vips_value_set_array_image(&gvalue, ${camelCase(p.name)}Length);
VipsImage **${camelCase(p.name)}Images = vips_value_get_array_image(&gvalue, NULL);
for (jint i = 0; i < ${camelCase(p.name)}Length; i++) {
	${camelCase(p.name)}Images[i] = (VipsImage *) (*env)->GetLongField(env, (*env)->GetObjectArrayElement(env, ${camelCase(p.name)}, i), handle_fid);
}
g_object_set_property(G_OBJECT(op), "${p.name}", &gvalue);
g_value_unset(&gvalue);`
			case 'VipsBlob':
				return `jint ${camelCase(p.name)}Length = (*env)->GetArrayLength(env, ${camelCase(p.name)});
size_t ${camelCase(p.name)}Size = ${camelCase(p.name)}Length * sizeof(jbyte);
void *${camelCase(p.name)}Data = vips_tracked_malloc(${camelCase(p.name)}Size);
if (${camelCase(p.name)}Data == NULL) {
	throwVipsException(env, "Failed to allocate memory for buffer");
}
(*env)->GetByteArrayRegion(env, ${camelCase(p.name)}, 0, ${camelCase(p.name)}Length, ${camelCase(p.name)}Data);
g_value_init(&gvalue, VIPS_TYPE_BLOB);
vips_value_set_blob_free(&gvalue, ${camelCase(p.name)}Data, ${camelCase(p.name)}Size);
g_object_set_property(G_OBJECT(op), "${p.name}", &gvalue);
g_value_unset(&gvalue);
`
			default:
				throw new Error(`Unsupported JNI input parameter type '${p.type}' for parameter '${p.name}'`)
		}
	}
}

function applyOptionalParameter(p: VipsOperationParameter): string {
	/* All optional parameters must be nullable so we can tell if they're set or not */
	let result = `jfieldID ${camelCase(p.name)}Fid = (*env)->GetFieldID(env, optionsCls, "${javaParameterIdentifier(p)}", "${wrappedJniTypeCodeForParameter(p)}");
`
	if (isObjectType(p)) {
		const jniType = jniTypeForParameter(p)
		result += `${jniType} ${camelCase(p.name)} = ${jniType !== 'jobject' ? `(${jniType}) `: ''}(*env)->GetObjectField(env, options, ${camelCase(p.name)}Fid);
${applyParameter(p)}`
	} else {
		result += `jobject ${camelCase(p.name)}ObjectValue = (*env)->GetObjectField(env, options, ${camelCase(p.name)}Fid);
if (${camelCase(p.name)}ObjectValue != NULL) {
	${extractWrappedValue()}
${indent(applyParameter(p), '\t')}
}`
	}
	return result

	function extractWrappedValue() {
		switch (jniTypeForParameter(p)) {
			case 'jboolean':
				return `jboolean ${camelCase(p.name)} = (*env)->CallBooleanMethod(env, ${camelCase(p.name)}ObjectValue, booleanValue_mid);`
			case 'jint':
				return `jint ${camelCase(p.name)} = (*env)->CallIntMethod(env, ${camelCase(p.name)}ObjectValue, intValue_mid);`
			case 'jlong':
				return `jlong ${camelCase(p.name)} = (*env)->CallLongMethod(env, ${camelCase(p.name)}ObjectValue, longValue_mid);`
			case 'jdouble':
				return `jdouble ${camelCase(p.name)} = (*env)->CallDoubleMethod(env, ${camelCase(p.name)}ObjectValue, doubleValue_mid);`
			default:
				throw new Error(`Unsupported optional parameter type for extract '${p.type}'`)
		}
	}
}

function declareFields(): string {
	return `static jfieldID handle_fid = NULL;
static jfieldID buffer_fid = NULL;
static jmethodID ctor_mid = NULL;
static jmethodID booleanValue_mid = NULL;
static jmethodID intValue_mid = NULL;
static jmethodID longValue_mid = NULL;
static jmethodID doubleValue_mid = NULL;
static jclass rectangleClass = NULL;
static jmethodID rectangle_ctor_mid = NULL;`
}

function initFields(): string {
	return `handle_fid = (*env)->GetFieldID(env, cls, "vipsImageHandler", "J");
buffer_fid = (*env)->GetFieldID(env, cls, "bufferHandler", "J");

jclass imageClass = (*env)->FindClass(env, "com/criteo/vips/VipsImage");
ctor_mid = (*env)->GetMethodID(env, imageClass, "<init>", "(J)V");

jclass booleanClass = (*env)->FindClass(env, "java/lang/Boolean");
booleanValue_mid = (*env)->GetMethodID(env, booleanClass, "booleanValue", "()Z");
jclass integerClass = (*env)->FindClass(env, "java/lang/Integer");
intValue_mid = (*env)->GetMethodID(env, integerClass, "intValue", "()I");
jclass longClass = (*env)->FindClass(env, "java/lang/Long");
longValue_mid = (*env)->GetMethodID(env, longClass, "longValue", "()J");
jclass doubleClass = (*env)->FindClass(env, "java/lang/Double");
doubleValue_mid = (*env)->GetMethodID(env, doubleClass, "doubleValue", "()D");
rectangleClass = (*env)->FindClass(env, "java/awt/Rectangle");
rectangle_ctor_mid = (*env)->GetMethodID(env, rectangleClass, "<init>", "(IIII)V");`
}

function applyPrimitiveParameter(p: VipsOperationParameter, vipsType: string, vipsValueSetFunction: string) {
	return `g_value_init(&gvalue, ${vipsType});
${vipsValueSetFunction}(&gvalue, ${camelCase(p.name)});
g_object_set_property(G_OBJECT(op), "${p.name}", &gvalue);
g_value_unset(&gvalue);`
}

function applyOutParameter(p: VipsOperationParameter): string {
	switch (p.type) {
		case 'VipsImage':
			return `
g_value_init(&gvalue, VIPS_TYPE_IMAGE);
g_object_get_property(G_OBJECT(op), "${p.name}", &gvalue);
VipsImage *${camelCase(p.name)} = VIPS_IMAGE(g_value_get_object(&gvalue));
g_object_ref(${camelCase(p.name)});
g_value_unset(&gvalue);
`
		case 'gboolean':
			return `
g_value_init(&gvalue, G_TYPE_BOOLEAN);
g_object_get_property(G_OBJECT(op), "${p.name}", &gvalue);
jboolean ${camelCase(p.name)} = g_value_get_boolean(&gvalue);
g_value_unset(&gvalue);
`
		case 'gint':
			return `
g_value_init(&gvalue, G_TYPE_INT);
g_object_get_property(G_OBJECT(op), "${p.name}", &gvalue);
jint ${camelCase(p.name)} = g_value_get_int(&gvalue);
g_value_unset(&gvalue);
`
		case 'gdouble':
			return `
g_value_init(&gvalue, G_TYPE_DOUBLE);
g_object_get_property(G_OBJECT(op), "${p.name}", &gvalue);
jdouble ${camelCase(p.name)} = g_value_get_double(&gvalue);
g_value_unset(&gvalue);
`
		case 'VipsArrayDouble':
			return `
g_value_init(&gvalue, VIPS_TYPE_ARRAY_DOUBLE);
g_object_get_property(G_OBJECT(op), "${p.name}", &gvalue);
jint ${camelCase(p.name)}Length = 0;
jdouble *${camelCase(p.name)}Elements = vips_value_get_array_double(&gvalue, &${camelCase(p.name)}Length);
jdoubleArray ${camelCase(p.name)} = (*env)->NewDoubleArray(env, ${camelCase(p.name)}Length);
(*env)->SetDoubleArrayRegion(env, ${camelCase(p.name)}, 0, ${camelCase(p.name)}Length, ${camelCase(p.name)}Elements);
g_value_unset(&gvalue);
`
		case 'VipsBlob':
			return `
g_value_init(&gvalue, VIPS_TYPE_BLOB);
g_object_get_property(G_OBJECT(op), "${p.name}", &gvalue);
size_t ${camelCase(p.name)}Size = 0;
void *${camelCase(p.name)}Data = vips_value_get_blob(&gvalue, &${camelCase(p.name)}Size);
jint ${camelCase(p.name)}Length = ${camelCase(p.name)}Size / sizeof(jbyte);
jbyteArray ${camelCase(p.name)} = (*env)->NewByteArray(env, ${camelCase(p.name)}Length);
(*env)->SetByteArrayRegion(env, ${camelCase(p.name)}, 0, ${camelCase(p.name)}Length, ${camelCase(p.name)}Data);
g_value_unset(&gvalue);
`
		case 'Rectangle':
			return `
	g_value_init(&gvalue, G_TYPE_INT);
	g_object_get_property(G_OBJECT(op), "left", &gvalue);
	jint ${camelCase(p.name)}Left = g_value_get_int(&gvalue);
	g_object_get_property(G_OBJECT(op), "top", &gvalue);
	jint ${camelCase(p.name)}Top = g_value_get_int(&gvalue);
	g_object_get_property(G_OBJECT(op), "width", &gvalue);
	jint ${camelCase(p.name)}Width = g_value_get_int(&gvalue);
	g_object_get_property(G_OBJECT(op), "height", &gvalue);
	jint ${camelCase(p.name)}Height = g_value_get_int(&gvalue);
	jobject ${camelCase(p.name)} = (*env)->NewObject(env, rectangleClass, rectangle_ctor_mid, ${camelCase(p.name)}Left, ${camelCase(p.name)}Top, ${camelCase(p.name)}Width, ${camelCase(p.name)}Height);
	g_value_unset(&gvalue);
`
		default:
			throw new Error(`Unsupported output parameter type '${p.type}'`)
	}
}
export function nativeMethod(op: VipsOperation): string {
	const info = operationInfo(op, { dontRemoveInstanceMethodFromIns: true })

	let result = ''
	if (info.mutatingInstanceMethod) {
		result += internalNativeMethod(op, info, { mode: 'mutating' }) + '\n'

		const nonMutatingInfo = operationInfo(op, { noMutatingInstanceMethods: true, dontRemoveInstanceMethodFromIns: true })
		result += internalNativeMethod(op, nonMutatingInfo, { mode: 'nonmutating' })
	} else {
		result += internalNativeMethod(op, info)
	}

	return result
}

function internalNativeMethod(op: VipsOperation, info: VipsOperationInfo, options?: VipsOperationOptions): string {
	let result = ''
	const { ins, optionals, outs, instanceMethod, mutatingInstanceMethod } = info

	if (outs.length > 1) {
		throw new Error(`Multiple outputs for ${op.alias}: ${outs.map(p => p.name)}`)
	}
	if (outs.length) {
		result += `JNIEXPORT ${jniTypeForParameter(outs[0])} JNICALL\n`
	} else {
		result += 'JNIEXPORT void JNICALL\n'
	}

	if (instanceMethod) {
		result += `Java_com_criteo_vips_AbstractVipsImage_${javaOperationIdentifier(op, options)}(JNIEnv *env`
	} else {
		result += `Java_com_criteo_vips_AbstractVipsImage_${javaOperationIdentifier(op, options)}(JNIEnv *env, jclass cls`
	}

	for (const p of ins) {
		result += `, ${jniTypeForParameter(p)} ${camelCase(p.name)}`
	}

	if (optionals.length) {
		result += ', jobject options'
	}
	result += `)
{
	GValue gvalue = { 0 };

`

	result += `\tVipsOperation *op = vips_operation_new("${op.alias}");\n\n`

	for (const p of ins) {
		result += `\t// ${p.name}\n`
		result += indent(applyParameter(p), '\t') + '\n\n'
	}
	if (optionals.length) {
		result += `\t// Optionals
	if (options != NULL) {
		jclass optionsCls = (*env)->GetObjectClass(env, options);

`
		for (const p of optionals) {
			result += `\t\t// ${p.name}\n`
			result += indent(applyOptionalParameter(p), '\t\t') + '\n\n'
		}
		result += `\t}

`
	}

	result += `\t// Operation
	VipsOperation *new_op;
	if (!(new_op = vips_cache_operation_build(op))) {
		g_object_unref(op);
		throwVipsException(env, "${op.alias} failed");
		`
	if (outs.length) {
		const out = outs[0]
		switch (out.type) {
			case 'gint':
			case 'gdouble':
			case 'guint64':
			case 'gboolean':
				result += 'return 0;'
				break
			default:
				result += 'return NULL;'
				break
		}
	} else {
		result += 'return;'
	}
	result += `
	}
	g_object_unref(op);
	op = new_op;

`

	if (mutatingInstanceMethod) {
		result += `\t// ${mutatingInstanceMethod.name}`
		result += indent(applyOutParameter(mutatingInstanceMethod), '\t') + '\n'
	}

	for (const p of outs) {
		result += `\t// ${p.name}`
		result += indent(applyOutParameter(p), '\t') + '\n'
	}

	result += `\t// Free the operation
	vips_object_unref_outputs(VIPS_OBJECT(op)); 
	g_object_unref(op);

`

	if (instanceMethod && mutatingInstanceMethod) {
		result += `\t// Mutating image result
	g_object_unref((VipsImage *) (*env)->GetLongField(env, ${instanceMethod.name}, handle_fid));
	(*env)->SetLongField(env, ${instanceMethod.name}, handle_fid, (jlong) ${mutatingInstanceMethod.name});
`
	}

	for (const p of outs) {
		result += `\t// Output
`
		switch (p.type) {
			case 'VipsImage':
				result += `\tjclass imageClass = (*env)->FindClass(env, "com/criteo/vips/VipsImage");
	return (*env)->NewObject(env, imageClass, ctor_mid, (jlong) ${camelCase(p.name)});\n`
				break
			default:
				result += `\treturn ${camelCase(p.name)};\n`
		}
	}

	result += `}

`
	return result
}

export function nativeFileHeader(): string {
	return `${COPYRIGHT}

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <jni.h>
#include <vips/vips.h>

#include "AbstractVipsImage.h"
#include "VipsException.h"

${declareFields()}

JNIEXPORT void JNICALL
Java_com_criteo_vips_AbstractVipsImage_initFieldIDs(JNIEnv *env, jobject cls)
{
${indent(initFields(), '\t')}
}

`
}