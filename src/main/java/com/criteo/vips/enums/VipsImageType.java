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

public enum VipsImageType {

	Error(-1),
	/** no type set */
	None(0),
	/** malloced memory array */
	Setbuf(1),
	/** memory array, don't free on close */
	SetbufForeign(2),
	/** input from fd with a window */
	Openin(3),
	/** memory mapped input file */
	Mmapin(4),
	/** memory mapped read/write file */
	Mmapinrw(5),
	/** output to fd */
	Openout(6),
	/** partial image */
	Partial(7),
	;

	private int value;
	private static Map<Integer, VipsImageType> map = new HashMap<>();

	private VipsImageType(int i) {
		value = i;
	}

	static {
		for (VipsImageType e : VipsImageType.values()) {
			map.put(e.value, e);
		}
	}

	public static VipsImageType valueOf(int i) {
		return map.get(i);
	}

	public int getValue() {
		return value;
	}

}
