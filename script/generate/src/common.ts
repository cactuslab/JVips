import { VipsOperation, VipsOperationInfo } from "./type";

interface Options {
	dontRemoveInstanceMethodFromIns?: boolean
}

export function operationInfo(op: VipsOperation, options?: Options): VipsOperationInfo {
	const ins = op.parameters.filter(p => p.direction === 'input' && p.required)
	const optionals = op.parameters.filter(p => p.direction === 'input' && !p.required)
	const outs = op.parameters.filter(p => p.direction === 'output' && p.required)
	// TODO optional outputs

	if (outs.length === 4 && outs[0].name === 'left' && outs[1].name === 'top' && outs[2].name === 'width' && outs[3].name === 'height') {
		/* Special support for find_trim which returns a rectangle */
		outs.splice(0, 4, {
			name: 'out',
			description: outs[0].description.replace(/Left edge/, 'Edges'),
			direction: 'output',
			required: true,
			type: 'Rectangle',
			properties: {},
		})
	}

	const instanceMethod = ins.length > 0 && ins[0].direction === 'input' && ins[0].type === 'VipsImage' ? ins[0] : undefined
	const mutatingInstanceMethod = instanceMethod && outs.length && outs[0].type === 'VipsImage' && !op.alias.startsWith('extract') && !op.alias.startsWith('join') ? outs[0] : undefined

	if (instanceMethod && !options?.dontRemoveInstanceMethodFromIns) {
		ins.splice(ins.indexOf(instanceMethod), 1)
	}

	if (mutatingInstanceMethod) {
		/* Remove the out parameter that is our instance mutator */
		outs.splice(outs.indexOf(mutatingInstanceMethod), 1)
	}

	return {
		ins,
		optionals,
		outs,
		instanceMethod,
		mutatingInstanceMethod,
	}
}
