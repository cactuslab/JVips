import { COPYRIGHT } from "./constants"
import { VipsEnum } from "./type"

export function javaEnum(anEnum: VipsEnum): string {
	let result = eunmFileHeader(anEnum)

	for (const member of anEnum.members) {
		if (member.comment) {
			result += `\t/** ${member.comment} */\n`
		}
		result += `\t${member.name}(${member.value}),\n`
	}

	result += enumFileFooter(anEnum)
	return result
}

function eunmFileHeader(anEnum: VipsEnum): string {
	return `${COPYRIGHT}

package com.criteo.vips.enums;

import java.util.HashMap;
import java.util.Map;

public enum ${anEnum.name} {

`
}

function enumFileFooter(anEnum: VipsEnum): string {
	return `	;

	private int value;
	private static Map<Integer, ${anEnum.name}> map = new HashMap<>();

	private ${anEnum.name}(int i) {
		value = i;
	}

	static {
		for (${anEnum.name} e : ${anEnum.name}.values()) {
			map.put(e.value, e);
		}
	}

	public static ${anEnum.name} valueOf(int i) {
		return map.get(i);
	}

	public int getValue() {
		return value;
	}

}
`
}
