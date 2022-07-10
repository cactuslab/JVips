import { operationInfo } from "./common"
import { COPYRIGHT } from "./constants"
import { VipsOperation, VipsOperationParameter } from "./type"
import { isEnum, camelCase, pascalCase, capitalize } from "./utils"

const RESERVED_WORDS = [
	'abstract', 'assert', 'boolean', 'break', 'byte', 'case',
	'catch', 'char', 'class', 'const', 'continue', 'default',
	'double', 'do', 'else', 'enum', 'extends', 'false',
	'final', 'finally', 'float', 'for', 'goto', 'if',
	'implements', 'import', 'instanceof', 'int', 'interface', 'long',
	'native', 'new', 'null', 'package', 'private', 'protected',
	'public', 'return', 'short', 'static', 'strictfp', 'super',
	'switch', 'synchronized', 'this', 'throw', 'throws', 'transient',
	'true', 'try', 'void', 'volatile', 'while',
]

function javaTypeForType(p: VipsOperationParameter, required: boolean = true): string {
	if (isEnum(p)) {
		return p.type
	}

	switch (p.type) {
		case 'gboolean': return required ? 'boolean' : 'Boolean'
		case 'gint': return required ? 'int' : 'Integer'
		case 'gdouble': return required ? 'double' : 'Double'
		case 'guint64': return required ? 'long' : 'Long' // TODO longs are uint64 they're int64
		case 'gchararray': return 'String'
		case 'VipsImage': return 'VipsImage'
		case 'VipsArrayDouble': return 'PixelPacket' // TODO are they all PixelPackets?
		case 'VipsBlob': return 'byte[]'
	}
	throw new Error(`Unsupported Java parameter type '${p.type} for parameter '${p.name}'`)
}

export function javaParameterIdentifier(p: VipsOperationParameter): string {
	const result = camelCase(p.name)
	if (RESERVED_WORDS.indexOf(result) !== -1) {
		return `${result}Param`
	} else {
		return result
	}
}

const OPERATION_NAMES = ['Load', 'Save']

export function javaOperationIdentifier(op: VipsOperation): string {
	let result = camelCase(op.alias)
	for (const opName of OPERATION_NAMES) {
		result = result.replace(opName.toLowerCase(), opName)
	}
	if (RESERVED_WORDS.indexOf(result) !== -1) {
		return `${result}Op`
	} else {
		return result
	}
}

const FILE_TYPES = ['PNG', 'JPEG', 'TIFF', 'PDF', 'JXL', 'JP2K', 'ICC', 'HEIF', 'GIF', 'CSV', 'DZ', 'XYZ', 'FFT', 'LUT', 'PPM', 'FITS', 'LAB']

/**
 * Create a Java class name for a Vips operation.
 * Performs some transformations to produce 
 * @param op 
 * @returns 
 */
export function javaOperationClassName(op: VipsOperation): string {
	let alias = op.alias
	for(const allCap of FILE_TYPES) {
		alias = alias.replace(allCap.toLowerCase(), `_${allCap}_`)
	}
	if (alias.endsWith('_')) {
		alias = alias.substring(0, alias.length - 1)
	}
	let result = pascalCase(alias)
	for (const opName of OPERATION_NAMES) {
		result = result.replace(opName.toLowerCase(), opName)
	}
	return result
}

export function javaNativeStub(op: VipsOperation): string {
	let result = ''
	const { ins, optionals, outs, instanceMethod } = operationInfo(op)

	if (outs.length > 1) {
		throw new Error(`Multiple outputs for ${op.alias}: ${outs.map(p => p.name)}`)
	}

	result += javadoc(true)

	result += `public `
	if (!instanceMethod) {
		result += 'static '
	}
	result += `native `

	result += methodSignature(true)
	result += ';\n\n'

	if (optionals.length) {
		result += javadoc(false)
		result += `public `
		if (!instanceMethod) {
			result += 'static '
		}
		result += methodSignature(false)
		result += ` {
	${outs.length ? 'return ' : ''}${javaOperationIdentifier(op)}(${ins.map(p => javaParameterIdentifier(p)).join(', ')}${ins.length ? ', ' : ''}null);
}\n\n`
	}

	return result

	function methodSignature(withOptionals: boolean) {
		let result = ''
		if (outs.length) {
			result += `${javaTypeForType(outs[0])} `
		} else {
			result += 'void '
		}
		result += `${javaOperationIdentifier(op)}(`

		let first = true
		for (const p of ins) {
			if (first) {
				first = false
			} else {
				result += ', '
			}

			result += `${javaTypeForType(p)} ${javaParameterIdentifier(p)}`
		}

		if (withOptionals && optionals.length) {
			if (!first) {
				result += ', '
			}
			result += `${javaOperationClassName(op)}Options options`
		}

		result += `)`
		return result
	}

	function javadoc(withOptionals: boolean) {
		let result = `/**
 * ${op.name} (${op.alias}): ${op.description}
`
		for (const p of ins) {
			result += ` * @param ${javaParameterIdentifier(p)} ${p.description}\n`
		}
		if (withOptionals && optionals.length) {
			result += ` * @param options optional arguments\n`
		}
		result += ` */\n`
		return result
	}
}

export function optionsClass(op: VipsOperation): string | undefined {
	const optionals = op.parameters.filter(p => p.direction === 'input' && !p.required)
	if (!optionals.length) {
		return undefined
	}

	let result = optionsFileHeader(op)
	
	/* Fields */
	for (const p of optionals) {
		result += `\tprivate ${javaTypeForType(p, false)} ${javaParameterIdentifier(p)};\n`
	}

	const className = `${javaOperationClassName(op)}Options`

	/* Properties */
	for (const p of optionals) {
		const javaType = javaTypeForType(p, false)
		const identifier = javaParameterIdentifier(p)
		result += `
	/**
	 * Optional argument: ${p.name}
	 * <p>
	 * ${p.description}
	 * @return the value of {@code ${identifier}}
	 */
	public ${javaType} ${javaType === 'boolean' ? 'is' : 'get'}${capitalize(identifier)}() {
		return this.${identifier};
	}

	/**
	 * Set the optional "${p.name}" argument.
	 * <p>
	 * ${p.description}
	 * @param ${identifier} the new value of {@code ${identifier}}
	 */
	public void set${capitalize(identifier)}(${javaType} ${identifier}) {
		this.${identifier} = ${identifier};
	}

	/**
	 * Set the optional "${p.name}" argument.
	 * <p>
	 * ${p.description}
	 * @param ${identifier} the new value of {@code ${identifier}}
	 * @return this object for chaining
	 */
	public ${className} ${identifier}(${javaType} ${identifier}) {
		set${capitalize(identifier)}(${identifier});
		return this;
	}
`
	}

	result += '\n'
	result += optionsFileFooter()
	return result
}

export function javaFileHeader(): string {
	return `${COPYRIGHT}

package com.criteo.vips;

import javax.annotation.Generated;

import com.criteo.vips.enums.*;
import com.criteo.vips.options.*;

@Generated(value = "")
abstract class AbstractVipsImage extends Vips {

	// Per instance memory pointer used by the C code to retrieve the image data (Don't remove!)
	protected long vipsImageHandler = 0;

	// VipsImage is created with vips_image_new_from_buffer, we are responsible to free allocated buffer.
	// We don't want to pass pointer to jbytearray because it will be never garbage collected (Don't remove!)
	// TODO: Try to create a global ref to jbytearray and delete the ref in release()
	protected long bufferHandler = 0;

	static {
		initFieldIDs();
	}

	private static native void initFieldIDs();

`
}

export function javaFileFooter(): string {
	return `}
`
}

function optionsFileHeader(op: VipsOperation): string {
	return `${COPYRIGHT}

package com.criteo.vips.options;

import com.criteo.vips.enums.*;
import com.criteo.vips.PixelPacket;

/**
 * Optional arguments for the "${op.alias}" operation.
 */
public class ${javaOperationClassName(op)}Options {

`
}

function optionsFileFooter(): string {
	return `}
`
}
