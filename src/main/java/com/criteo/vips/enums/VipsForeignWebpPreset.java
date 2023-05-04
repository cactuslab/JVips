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

public enum VipsForeignWebpPreset {

	Default(0),
	Picture(1),
	Photo(2),
	Drawing(3),
	Icon(4),
	Text(5),
	Last(6),
	;

	private int value;
	private static Map<Integer, VipsForeignWebpPreset> map = new HashMap<>();

	private VipsForeignWebpPreset(int i) {
		value = i;
	}

	static {
		for (VipsForeignWebpPreset e : VipsForeignWebpPreset.values()) {
			map.put(e.value, e);
		}
	}

	public static VipsForeignWebpPreset valueOf(int i) {
		return map.get(i);
	}

	public int getValue() {
		return value;
	}

}
