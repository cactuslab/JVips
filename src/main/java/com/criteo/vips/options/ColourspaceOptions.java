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

import com.criteo.vips.enums.*;
import com.criteo.vips.PixelPacket;

/**
 * Optional arguments for the "colourspace" operation.
 */
public class ColourspaceOptions {

	private VipsInterpretation sourceSpace;

	/**
	 * Optional argument: source-space
	 * <p>
	 * Source colour space
	 * @return the value of {@code sourceSpace}
	 */
	public VipsInterpretation getSourceSpace() {
		return this.sourceSpace;
	}

	/**
	 * Set the optional "source-space" argument.
	 * <p>
	 * Source colour space
	 * @param sourceSpace the new value of {@code sourceSpace}
	 */
	public void setSourceSpace(VipsInterpretation sourceSpace) {
		this.sourceSpace = sourceSpace;
	}

	/**
	 * Set the optional "source-space" argument.
	 * <p>
	 * Source colour space
	 * @param sourceSpace the new value of {@code sourceSpace}
	 * @return this object for chaining
	 */
	public ColourspaceOptions sourceSpace(VipsInterpretation sourceSpace) {
		setSourceSpace(sourceSpace);
		return this;
	}

}
