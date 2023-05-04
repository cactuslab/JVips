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

public enum VipsBlendMode {

	Clear(0),
	Source(1),
	Over(2),
	In(3),
	Out(4),
	Atop(5),
	Dest(6),
	DestOver(7),
	DestIn(8),
	DestOut(9),
	DestAtop(10),
	Xor(11),
	Add(12),
	Saturate(13),
	Multiply(14),
	Screen(15),
	Overlay(16),
	Darken(17),
	Lighten(18),
	ColourDodge(19),
	ColourBurn(20),
	HardLight(21),
	SoftLight(22),
	Difference(23),
	Exclusion(24),
	Last(25),
	;

	private int value;
	private static Map<Integer, VipsBlendMode> map = new HashMap<>();

	private VipsBlendMode(int i) {
		value = i;
	}

	static {
		for (VipsBlendMode e : VipsBlendMode.values()) {
			map.put(e.value, e);
		}
	}

	public static VipsBlendMode valueOf(int i) {
		return map.get(i);
	}

	public int getValue() {
		return value;
	}

}
