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
 * Optional arguments for the "cast" operation.
 */
public class CastOptions {

	private Boolean shift;

	/**
	 * Optional argument: shift
	 * <p>
	 * Shift integer values up and down
	 * @return the value of {@code shift}
	 */
	public Boolean getShift() {
		return this.shift;
	}

	/**
	 * Set the optional "shift" argument.
	 * <p>
	 * Shift integer values up and down
	 * @param shift the new value of {@code shift}
	 */
	public void setShift(Boolean shift) {
		this.shift = shift;
	}

	/**
	 * Set the optional "shift" argument.
	 * <p>
	 * Shift integer values up and down
	 * @param shift the new value of {@code shift}
	 * @return this object for chaining
	 */
	public CastOptions shift(Boolean shift) {
		setShift(shift);
		return this;
	}

}
