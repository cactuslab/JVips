/*
  Copyright (c) 2019 Criteo

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

#include <jni.h>
#include <vips/vips.h>

#include "Vips.h"
#include "VipsException.h"

JNIEXPORT void JNICALL
Java_com_criteo_vips_Vips_init(__attribute__((unused)) JNIEnv *env, __attribute__((unused)) jobject obj)
{
  if (VIPS_INIT("java") != 0)
    throwVipsException(env, "Unable to init vips");
}
