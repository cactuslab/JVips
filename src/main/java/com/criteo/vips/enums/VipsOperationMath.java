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

package com.criteo.vips.enums;

import java.util.HashMap;
import java.util.Map;

public enum VipsOperationMath {

	Sin(0),
	Cos(1),
	Tan(2),
	Asin(3),
	Acos(4),
	Atan(5),
	Log(6),
	Log10(7),
	Exp(8),
	Exp10(9),
	Sinh(10),
	Cosh(11),
	Tanh(12),
	Asinh(13),
	Acosh(14),
	Atanh(15),
	Last(16),
	;

	private int value;
	private static Map<Integer, VipsOperationMath> map = new HashMap<>();

	private VipsOperationMath(int i) {
		value = i;
	}

	static {
		for (VipsOperationMath e : VipsOperationMath.values()) {
			map.put(e.value, e);
		}
	}

	public static VipsOperationMath valueOf(int i) {
		return map.get(i);
	}

	public int getValue() {
		return value;
	}

}
