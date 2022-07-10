export interface VipsOperation {
	name: string
	alias: string
	summary: string
	description?: string

	parameters: VipsOperationParameter[]
}

export interface VipsOperationParameter {
	name: string
	description: string
	direction: 'input' | 'output'
	required: boolean
	type: string
	properties: Record<string, string[]>
}

export interface VipsOperationInfo {
	/**
	 * Required input parameters
	 */
	ins: VipsOperationParameter[]
	/**
	 * Optional input parameters
	 */
	optionals: VipsOperationParameter[]
	/**
	 * Output parameters
	 */
	outs: VipsOperationParameter[]
	/**
	 * Treat this method as an instance method of VipsImage. Set to the input parameter that represents the instance.
	 */
	instanceMethod: VipsOperationParameter | undefined
	/**
	 * Treat this method as a mutating instance method, that is it mutates the VipsImage instance.
	 * Set to the output parameter that represents the result.
	 */
	mutatingInstanceMethod: VipsOperationParameter | undefined
}
