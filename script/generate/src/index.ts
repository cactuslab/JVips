import { inspectOperations, testOperations } from "./inspect"
import { nativeFileHeader, nativeMethod } from "./jni"
import { javaFileFooter, javaFileHeader, javaNativeStub, javaOperationClassName, optionsClass } from "./java"
import { indent } from "./utils"
import { promises as fs } from 'fs'
import path from "path"

interface Files {
	nativeFile: string
	javaFile: string
	optionsPath: string
}

async function run (files: Files) {
	let nativeFileContents = nativeFileHeader()
	let javaFileContents = javaFileHeader()

	const ops = await inspectOperations()
	// const ops = await testOperations()

	const successes = new Set<string>()
	const filePromises: Promise<void>[] = []
	let failures = 0
	for (const op of ops) {
		if (successes.has(op.alias)) {
			/* Skip any duplicates, e.g. extract_area */
			continue
		}

		try {
			const native = nativeMethod(op)
			const java = javaNativeStub(op)
			const options = optionsClass(op)

			nativeFileContents += native
			javaFileContents += indent(java, '\t')

			if (options) {
				filePromises.push(fs.writeFile(path.resolve(files.optionsPath, `${javaOperationClassName(op)}Options.java`), options))
			}
			// console.log(native)
			// console.log(java)
			successes.add(op.alias)
		} catch (error) {
			console.warn(`Cannot generate ${op.alias}: ${error}`)
			failures++
		}
	}

	javaFileContents += javaFileFooter()

	await fs.writeFile(files.nativeFile, nativeFileContents)
	await fs.writeFile(files.javaFile, javaFileContents)
	await Promise.all(filePromises)
	console.log(`Generation complete with ${successes.size} successes and ${failures} failures`)
}

run({
	nativeFile: '../../src/main/c/AbstractVipsImage.c',
	javaFile: '../../src/main/java/com/criteo/vips/AbstractVipsImage.java',
	optionsPath: '../../src/main/java/com/criteo/vips/options',
})
