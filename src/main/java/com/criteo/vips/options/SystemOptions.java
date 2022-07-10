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

import com.criteo.vips.Image;
import com.criteo.vips.enums.*;

/**
 * Optional arguments for the "system" operation.
 */
public class SystemOptions {

	private Image[] in;
	private String outFormat;
	private String inFormat;

	/**
	 * Optional argument: in
	 * <p>
	 * Array of input images
	 * @return the value of {@code in}
	 */
	public Image[] getIn() {
		return this.in;
	}

	/**
	 * Set the optional "in" argument.
	 * <p>
	 * Array of input images
	 * @param in the new value of {@code in}
	 */
	public void setIn(Image[] in) {
		this.in = in;
	}

	/**
	 * Set the optional "in" argument.
	 * <p>
	 * Array of input images
	 * @param in the new value of {@code in}
	 * @return this object for chaining
	 */
	public SystemOptions in(Image[] in) {
		setIn(in);
		return this;
	}

	/**
	 * Optional argument: out-format
	 * <p>
	 * Format for output filename
	 * @return the value of {@code outFormat}
	 */
	public String getOutFormat() {
		return this.outFormat;
	}

	/**
	 * Set the optional "out-format" argument.
	 * <p>
	 * Format for output filename
	 * @param outFormat the new value of {@code outFormat}
	 */
	public void setOutFormat(String outFormat) {
		this.outFormat = outFormat;
	}

	/**
	 * Set the optional "out-format" argument.
	 * <p>
	 * Format for output filename
	 * @param outFormat the new value of {@code outFormat}
	 * @return this object for chaining
	 */
	public SystemOptions outFormat(String outFormat) {
		setOutFormat(outFormat);
		return this;
	}

	/**
	 * Optional argument: in-format
	 * <p>
	 * Format for input filename
	 * @return the value of {@code inFormat}
	 */
	public String getInFormat() {
		return this.inFormat;
	}

	/**
	 * Set the optional "in-format" argument.
	 * <p>
	 * Format for input filename
	 * @param inFormat the new value of {@code inFormat}
	 */
	public void setInFormat(String inFormat) {
		this.inFormat = inFormat;
	}

	/**
	 * Set the optional "in-format" argument.
	 * <p>
	 * Format for input filename
	 * @param inFormat the new value of {@code inFormat}
	 * @return this object for chaining
	 */
	public SystemOptions inFormat(String inFormat) {
		setInFormat(inFormat);
		return this;
	}

}
