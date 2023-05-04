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
 * Optional arguments for the "draw_image" operation.
 */
public class DrawImageOptions {

	private com.criteo.vips.enums.VipsCombineMode mode;

	/**
	 * Optional argument: mode
	 * <p>
	 * Combining mode
	 * @return the value of {@code mode}
	 */
	public com.criteo.vips.enums.VipsCombineMode getMode() {
		return this.mode;
	}

	/**
	 * Set the optional "mode" argument.
	 * <p>
	 * Combining mode
	 * @param mode the new value of {@code mode}
	 */
	public void setMode(com.criteo.vips.enums.VipsCombineMode mode) {
		this.mode = mode;
	}

	/**
	 * Set the optional "mode" argument.
	 * <p>
	 * Combining mode
	 * @param mode the new value of {@code mode}
	 * @return this object for chaining
	 */
	public DrawImageOptions mode(com.criteo.vips.enums.VipsCombineMode mode) {
		setMode(mode);
		return this;
	}

}
