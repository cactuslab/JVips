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

public enum VipsAngle45 {

	D0(0),
	D45(1),
	D90(2),
	D135(3),
	D180(4),
	D225(5),
	D270(6),
	D315(7),
	Last(8),
	;

	private int value;
	private static Map<Integer, VipsAngle45> map = new HashMap<>();

	private VipsAngle45(int i) {
		value = i;
	}

	static {
		for (VipsAngle45 e : VipsAngle45.values()) {
			map.put(e.value, e);
		}
	}

	public static VipsAngle45 valueOf(int i) {
		return map.get(i);
	}

	public int getValue() {
		return value;
	}

}
