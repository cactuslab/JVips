import { exec, spawn, SpawnOptionsWithoutStdio } from 'child_process'
import fs from 'node:fs/promises'
import util from 'util'
import path from 'node:path'
import { VipsEnum, VipsEnumMember } from "./type"
import { pascalCase } from './utils'

export async function inspectEnums(): Promise<VipsEnum[]> {
	const result: VipsEnum[] = []

	const includePath = await findIncludePath()
	const files = await fs.readdir(includePath)
	for (const file of files) {
		if ('almostdeprecated.h' === file) {
			continue
		}

		const contents = await fs.readFile(path.join(includePath, file))
		const string = contents.toString()
		const lines = string.split(/\n/)

		let members: VipsEnumMember[] = []
		let nextEnumValue = 0
		let inEnum = false
		for (let line of lines) {
			if (!inEnum) {
				if (line.startsWith('typedef enum')) {
					inEnum = true
					members = []
					nextEnumValue = 0
				}
			} else {
				if (line.trim().endsWith(';')) {
					let working = line.trim().match(/\w+;$/)
					if (working) {
						const name = working[0].replace(/;$/, '')

						/* We ignore enums that aren't intended to be public */
						if (name.startsWith('Vips')) {
							const vipsEnum: VipsEnum = {
								name,
								members,
							}
							tidyVipsEnum(vipsEnum)
							result.push(vipsEnum)
						}
					} else {
						console.warn('Invalid enum ending line:', line.trim())
					}
					inEnum = false

					// console.log(members)
				} else {
					/* Remove comments from the enum value line */
					let docs = line.match(/\/\*.*\*\//)
					let comment: string | undefined
					if (docs) {
						comment = docs[0].substring(2, docs[0].length - 2).trim()
					}

					/* Convert bit shifts */
					const matchShifts = line.match(/(.*) 1 << (\d+)(.*)/)
					if (matchShifts) {
						const shiftedValue = 1 << parseInt(matchShifts[2])
						line = matchShifts[1] + ' ' + shiftedValue + matchShifts[3]
					}

					/* Split the line into either "name" or "name" "=" "value" */
					let working = line.replace(/\/\*.*\*\//g, '').trim().replace(/,$/, '').split(' ')
					if (working.length === 1) {
						if (!working[0]) {
							/* Skip empty line */
						} else if (working[0].match(/^[a-zA-Z_0-9]+$/)) {
							members.push({ name: working[0], nativeName: working[0], value: nextEnumValue++, comment })
						} else {
							console.warn(`Invalid enum line in ${file}:`, line.trim())
						}
					} else if (working.length === 3) {
						if (working[1] !== '=') {
							console.warn(`Invalid enum line in ${file}:`, line.trim())
						} else {
							nextEnumValue = Number(working[2])
							members.push({ name: working[0], nativeName: working[0], value: nextEnumValue++, comment })
						}
					} else {
						console.warn(`Invalid enum line in ${file}:`, line.trim())
					}
				}
			}
		}
	}

	return result
}

async function findIncludePath(): Promise<string> {
	try {
		await fs.stat('/usr/local/include/vips')
		return '/usr/local/include/vips'
	} catch {
		
	}
	try {
		await fs.stat('/opt/homebrew/include/vips')
		return '/opt/homebrew/include/vips'
	} catch {

	}
	throw new Error('Cannot find vips include directory, is vips installed using Homebrew?')
}
function tidyVipsEnum(e: VipsEnum): void {
	let best: string[] | undefined

	for (const member of e.members) {
		const splitName = member.name.split('_')
		if (best) {
			for (let i = 0; i < best.length; i++) {
				if (splitName[i] !== best[i]) {
					best.splice(i, best.length)
					break
				}
			}
		} else {
			best = splitName
		}
	}

	for (const member of e.members) {
		member.name = member.name.split('_').slice(best?.length).join('_')
		member.name = pascalCase(member.name.toLowerCase())
	}
}
