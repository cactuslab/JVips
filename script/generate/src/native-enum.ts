import { COPYRIGHT } from "./constants"
import { VipsEnum } from "./type"

export function nativeEnumTest(enums: VipsEnum[]): string {
	let result = `${COPYRIGHT}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <jni.h>
#include <vips/vips.h>

#include "VipsException.h"
#include "com_criteo_vips_VipsEnumTest.h"

#define BUF_SIZE 4096

static void
assertEqualsNativeEnumValue(JNIEnv *env, const int expected, const char *className, const char *name)
{
    char sig[BUF_SIZE] = { 0 };
    sprintf(sig, "L%s;", className);
    jclass cls = (*env)->FindClass(env, className);
    jfieldID id = (*env)->GetStaticFieldID(env, cls , name, sig);
    jobject obj = (*env)->GetStaticObjectField(env, cls, id);
    jmethodID mid = (*env)->GetMethodID(env, cls , "getValue", "()I");
    jint actual = (*env)->CallIntMethod(env, obj, mid);

    if (expected != actual)
    {
        char msg[BUF_SIZE] = { 0 };
        sprintf(msg, "%s:%s is not equal to expected value (%d vs %d)", className, name, actual, expected);
        throwVipsException(env, msg);
    }
    return;
}

JNIEXPORT void JNICALL
Java_com_criteo_vips_VipsEnumTest_TestNativeEnums(JNIEnv *env, jclass c)
{
    if (VIPS_INIT("java") != 0) {
        throwVipsException(env, "Unable to init vips");
    }
`
	for (const anEnum of enums) {
		/* Skip deprecated enums that don't match */
		if (anEnum.name === 'VipsSaveable') {
			continue
		}

		result += `
	// ${anEnum.name}
`
		for (const member of anEnum.members) {
			if (member.name !== 'Last') { /* We don't test Last, as that moves between versions when more enums are added and we may test with a newer version of Vips than we build with (e.g. between macOS and Linux) */
			    result += `\tassertEqualsNativeEnumValue(env, ${member.nativeName}, "com/criteo/vips/enums/${anEnum.name}", "${member.name}");\n`
			}
		}
	}
	result += `
}
`
	return result
}
