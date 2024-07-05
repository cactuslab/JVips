import { exec, spawn, SpawnOptionsWithoutStdio } from 'child_process'
import util from 'util'
import { EOL } from 'os'
import { VipsOperation, VipsOperationParameter } from './type'

const execPromise = util.promisify(exec)

export async function testOperations(): Promise<VipsOperation[]> {
	return [
		(await inspectOp({
			name: 'VipsEmbed',
			alias: 'embed',
			summary: '',
			parameters: [],
		}))!,
		(await inspectOp({
			name: 'VipsThumbnailFile',
			alias: 'thumbnail',
			summary: '',
			parameters: [],
		}))!,
		(await inspectOp({
			name: 'VipsThumbnailImage',
			alias: 'thumbnail_image',
			summary: '',
			parameters: [],
		}))!,
	]
}

export async function inspectOperations(): Promise<VipsOperation[]> {
	const { stdout: objects } = await execPromise('vips -l')

	const promises: Promise<VipsOperation | undefined>[] = []
	for (const line of objects.split(EOL)) {
		if (!line.trim()) {
			continue
		}

		const match = line.trim().match(/^([-\w]+) \((\w+)\), (.*)/)
		if (match) {
			const name = match[1]
			const alias = match[2]
			const summary = match[3]

			promises.push(inspectOp({
				name,
				alias,
				summary,
				parameters: [],
			}))
		} else {
			throw new Error(`Unparsable line: ${line}`)
		}
	}

	const result = await Promise.all(promises)
	return result.filter(op => !!op).map(op => op!).sort((a, b) => a.alias.localeCompare(b.alias))
}

async function inspectOp(op: VipsOperation): Promise<VipsOperation | undefined> {
	let opHelp: string
	try {
		opHelp = (await execPromise(`vips ${op.alias}`)).stdout
	} catch (error) {
		/* Not all of the aliases are actual operations that vips will do */
		opHelp = ''
	}

	if (opHelp) {
		try {
			await parseOp(opHelp, op)
		} catch (error) {
			if (error instanceof Error) {
				console.error(`Failed to parse op "${op.name}":`, error.message)
			} else {
				throw error
			}
		}
		return op
	}
}

/**
 * Parse the output from `vips` for an operation.
 * @param text 
 * @param op 
 */
async function parseOp(text: string, op: VipsOperation): Promise<void> {
	const lines = text.split(EOL)

	/* Find the "usage:" section */
	const usage = lines.indexOf('usage:')
	if (usage === -1) {
		throw new Error(`Unprasable operation help (no usage): ${text}`)
	}

	/* The description of the op is before the "usage:" section */
	const description = lines.slice(0, usage).join(EOL)
	op.description = description

	/* The "where:" section starts the definition of the parameters */
	const where = lines.indexOf('where:')
	if (where === -1) {
		throw new Error(`Unprasable operation help (no where): ${text}`)
	}
	op.parameters = await parseOpParameters(lines, where, true)

	const outputs = lines.indexOf('outputs:')
	if (outputs !== -1) {
		op.parameters.push(...await parseOpParameters(lines, outputs, true))
	}

	const optionalArguments = lines.indexOf('optional arguments:')
	if (optionalArguments !== -1) {
		op.parameters.push(...await parseOpParameters(lines, optionalArguments, false))
	}
}

/**
 * Parse the parameters from a section in the `vips` output for the operation.
 * @param lines 
 * @param marker 
 * @param required 
 * @returns 
 */
async function parseOpParameters(lines: string[], marker: number, required: boolean): Promise<VipsOperationParameter[]> {
	const result: VipsOperationParameter[] = []
	let current: VipsOperationParameter | undefined

	/* Look at the lines in the section. All lines in the section are indented with spaces. */
	for (let i = marker + 1; i < lines.length && lines[i].match(/^\s/); i++) {
		const line = lines[i]

		/* The lines are of the form '<name> - <description>"," "input|output" <type>', and they sometimes have additional info on a second line */
		const match = line.match(/^   ([-\w]+)\s+- (.*), (input|output) (\w+)$/)
		if (match) {
			/* Parameter */
			const name = match[1]
			const description = match[2]
			const direction = match[3]
			const type = match[4]

			if (direction !== 'input' && direction !== 'output') {
				throw new Error(`Unsupported parameter direction '${direction}' in ${line}`)
			}

			current = {
				name,
				description,
				direction,
				required,
				type,
				properties: {},
			}
			result.push(current)
		} else {
			/* Continuation */
			if (!current) {
				throw new Error(`Continuation line before a parameter: ${line}`)
			}

			let remainder = line
			while (remainder) {
				/* Continuation lines contain name value pairs (colon separated), with pairs separated by commas */
				const match = remainder.match(/^\s*([-\w ]+): (.*?)($|, ([-\w ]+: .*$))/)
				if (match) {
					const name = match[1]
					const values = match[2].split(', ')
					if (current.properties[name]) {
						throw new Error(`Continuation line contains duplicate property '${name}' for parameter '${current.name}'`)
					}

					current.properties[name] = values
					remainder = match[4]
				} else {
					throw new Error(`Unparsable continuation line part "${remainder}"`)
				}
			}
		}
	}
	return result
}
