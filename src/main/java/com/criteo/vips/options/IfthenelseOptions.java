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
 * Optional arguments for the "ifthenelse" operation.
 */
public class IfthenelseOptions {

	private Boolean blend;

	/**
	 * Optional argument: blend
	 * <p>
	 * Blend smoothly between then and else parts
	 * @return the value of {@code blend}
	 */
	public Boolean getBlend() {
		return this.blend;
	}

	/**
	 * Set the optional "blend" argument.
	 * <p>
	 * Blend smoothly between then and else parts
	 * @param blend the new value of {@code blend}
	 */
	public void setBlend(Boolean blend) {
		this.blend = blend;
	}

	/**
	 * Set the optional "blend" argument.
	 * <p>
	 * Blend smoothly between then and else parts
	 * @param blend the new value of {@code blend}
	 * @return this object for chaining
	 */
	public IfthenelseOptions blend(Boolean blend) {
		setBlend(blend);
		return this;
	}

}
