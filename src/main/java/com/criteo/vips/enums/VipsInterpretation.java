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

public enum VipsInterpretation {

	Error(-1),
	Multiband(0),
	BW(1),
	Histogram(10),
	Xyz(12),
	Lab(13),
	Cmyk(15),
	Labq(16),
	Rgb(17),
	Cmc(18),
	Lch(19),
	Labs(21),
	Srgb(22),
	Yxy(23),
	Fourier(24),
	Rgb16(25),
	Grey16(26),
	Matrix(27),
	Scrgb(28),
	Hsv(29),
	Last(30),
	;

	private int value;
	private static Map<Integer, VipsInterpretation> map = new HashMap<>();

	private VipsInterpretation(int i) {
		value = i;
	}

	static {
		for (VipsInterpretation e : VipsInterpretation.values()) {
			map.put(e.value, e);
		}
	}

	public static VipsInterpretation valueOf(int i) {
		return map.get(i);
	}

	public int getValue() {
		return value;
	}

}
