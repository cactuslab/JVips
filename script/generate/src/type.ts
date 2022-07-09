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
