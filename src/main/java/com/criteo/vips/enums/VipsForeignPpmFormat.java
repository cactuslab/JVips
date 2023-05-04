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

public enum VipsForeignPpmFormat {

	Pbm(0),
	Pgm(1),
	Ppm(2),
	Pfm(3),
	Pnm(4),
	Last(5),
	;

	private int value;
	private static Map<Integer, VipsForeignPpmFormat> map = new HashMap<>();

	private VipsForeignPpmFormat(int i) {
		value = i;
	}

	static {
		for (VipsForeignPpmFormat e : VipsForeignPpmFormat.values()) {
			map.put(e.value, e);
		}
	}

	public static VipsForeignPpmFormat valueOf(int i) {
		return map.get(i);
	}

	public int getValue() {
		return value;
	}

}
