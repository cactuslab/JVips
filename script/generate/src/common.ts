import { VipsOperation, VipsOperationInfo } from "./type";

interface Options {
	dontRemoveInstanceMethodFromIns?: boolean
}

export function operationInfo(op: VipsOperation, options?: Options): VipsOperationInfo {
	const ins = op.parameters.filter(p => p.direction === 'input' && p.required)
	const optionals = op.parameters.filter(p => p.direction === 'input' && !p.required)
	const outs = op.parameters.filter(p => p.direction === 'output' && p.required)
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
