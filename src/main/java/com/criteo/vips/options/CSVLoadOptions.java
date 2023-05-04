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

package com.criteo.vips.options;

/**
 * Optional arguments for the "csvload" operation.
 */
public class CSVLoadOptions {

	private Integer skip;
	private Integer lines;
	private String whitespace;
	private String separator;
	private Boolean memory;
	private com.criteo.vips.enums.VipsAccess access;
	private com.criteo.vips.enums.VipsFailOn failOn;

	/**
	 * Optional argument: skip
	 * <p>
	 * Skip this many lines at the start of the file
	 * @return the value of {@code skip}
	 */
	public Integer getSkip() {
		return this.skip;
	}

	/**
	 * Set the optional "skip" argument.
	 * <p>
	 * Skip this many lines at the start of the file
	 * @param skip the new value of {@code skip}
	 */
	public void setSkip(Integer skip) {
		this.skip = skip;
	}

	/**
	 * Set the optional "skip" argument.
	 * <p>
	 * Skip this many lines at the start of the file
	 * @param skip the new value of {@code skip}
	 * @return this object for chaining
	 */
	public CSVLoadOptions skip(Integer skip) {
		setSkip(skip);
		return this;
	}

	/**
	 * Optional argument: lines
	 * <p>
	 * Read this many lines from the file
	 * @return the value of {@code lines}
	 */
	public Integer getLines() {
		return this.lines;
	}

	/**
	 * Set the optional "lines" argument.
	 * <p>
	 * Read this many lines from the file
	 * @param lines the new value of {@code lines}
	 */
	public void setLines(Integer lines) {
		this.lines = lines;
	}

	/**
	 * Set the optional "lines" argument.
	 * <p>
	 * Read this many lines from the file
	 * @param lines the new value of {@code lines}
	 * @return this object for chaining
	 */
	public CSVLoadOptions lines(Integer lines) {
		setLines(lines);
		return this;
	}

	/**
	 * Optional argument: whitespace
	 * <p>
	 * Set of whitespace characters
	 * @return the value of {@code whitespace}
	 */
	public String getWhitespace() {
		return this.whitespace;
	}

	/**
	 * Set the optional "whitespace" argument.
	 * <p>
	 * Set of whitespace characters
	 * @param whitespace the new value of {@code whitespace}
	 */
	public void setWhitespace(String whitespace) {
		this.whitespace = whitespace;
	}

	/**
	 * Set the optional "whitespace" argument.
	 * <p>
	 * Set of whitespace characters
	 * @param whitespace the new value of {@code whitespace}
	 * @return this object for chaining
	 */
	public CSVLoadOptions whitespace(String whitespace) {
		setWhitespace(whitespace);
		return this;
	}

	/**
	 * Optional argument: separator
	 * <p>
	 * Set of separator characters
	 * @return the value of {@code separator}
	 */
	public String getSeparator() {
		return this.separator;
	}

	/**
	 * Set the optional "separator" argument.
	 * <p>
	 * Set of separator characters
	 * @param separator the new value of {@code separator}
	 */
	public void setSeparator(String separator) {
		this.separator = separator;
	}

	/**
	 * Set the optional "separator" argument.
	 * <p>
	 * Set of separator characters
	 * @param separator the new value of {@code separator}
	 * @return this object for chaining
	 */
	public CSVLoadOptions separator(String separator) {
		setSeparator(separator);
		return this;
	}

	/**
	 * Optional argument: memory
	 * <p>
	 * Force open via memory
	 * @return the value of {@code memory}
	 */
	public Boolean getMemory() {
		return this.memory;
	}

	/**
	 * Set the optional "memory" argument.
	 * <p>
	 * Force open via memory
	 * @param memory the new value of {@code memory}
	 */
	public void setMemory(Boolean memory) {
		this.memory = memory;
	}

	/**
	 * Set the optional "memory" argument.
	 * <p>
	 * Force open via memory
	 * @param memory the new value of {@code memory}
	 * @return this object for chaining
	 */
	public CSVLoadOptions memory(Boolean memory) {
		setMemory(memory);
		return this;
	}

	/**
	 * Optional argument: access
	 * <p>
	 * Required access pattern for this file
	 * @return the value of {@code access}
	 */
	public com.criteo.vips.enums.VipsAccess getAccess() {
		return this.access;
	}

	/**
	 * Set the optional "access" argument.
	 * <p>
	 * Required access pattern for this file
	 * @param access the new value of {@code access}
	 */
	public void setAccess(com.criteo.vips.enums.VipsAccess access) {
		this.access = access;
	}

	/**
	 * Set the optional "access" argument.
	 * <p>
	 * Required access pattern for this file
	 * @param access the new value of {@code access}
	 * @return this object for chaining
	 */
	public CSVLoadOptions access(com.criteo.vips.enums.VipsAccess access) {
		setAccess(access);
		return this;
	}

	/**
	 * Optional argument: fail-on
	 * <p>
	 * Error level to fail on
	 * @return the value of {@code failOn}
	 */
	public com.criteo.vips.enums.VipsFailOn getFailOn() {
		return this.failOn;
	}

	/**
	 * Set the optional "fail-on" argument.
	 * <p>
	 * Error level to fail on
	 * @param failOn the new value of {@code failOn}
	 */
	public void setFailOn(com.criteo.vips.enums.VipsFailOn failOn) {
		this.failOn = failOn;
	}

	/**
	 * Set the optional "fail-on" argument.
	 * <p>
	 * Error level to fail on
	 * @param failOn the new value of {@code failOn}
	 * @return this object for chaining
	 */
	public CSVLoadOptions failOn(com.criteo.vips.enums.VipsFailOn failOn) {
		setFailOn(failOn);
		return this;
	}

}
