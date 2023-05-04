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

public enum VipsInteresting {

	None(0),
	Centre(1),
	Entropy(2),
	Attention(3),
	Low(4),
	High(5),
	All(6),
	Last(7),
	;

	private int value;
	private static Map<Integer, VipsInteresting> map = new HashMap<>();

	private VipsInteresting(int i) {
		value = i;
	}

	static {
		for (VipsInteresting e : VipsInteresting.values()) {
			map.put(e.value, e);
		}
	}

	public static VipsInteresting valueOf(int i) {
		return map.get(i);
	}

	public int getValue() {
		return value;
	}

}
