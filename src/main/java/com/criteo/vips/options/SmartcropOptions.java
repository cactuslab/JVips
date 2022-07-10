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
 * Optional arguments for the "smartcrop" operation.
 */
public class SmartcropOptions {

	private VipsInteresting interesting;

	/**
	 * Optional argument: interesting
	 * <p>
	 * How to measure interestingness
	 * @return the value of {@code interesting}
	 */
	public VipsInteresting getInteresting() {
		return this.interesting;
	}

	/**
	 * Set the optional "interesting" argument.
	 * <p>
	 * How to measure interestingness
	 * @param interesting the new value of {@code interesting}
	 */
	public void setInteresting(VipsInteresting interesting) {
		this.interesting = interesting;
	}

	/**
	 * Set the optional "interesting" argument.
	 * <p>
	 * How to measure interestingness
	 * @param interesting the new value of {@code interesting}
	 * @return this object for chaining
	 */
	public SmartcropOptions interesting(VipsInteresting interesting) {
		setInteresting(interesting);
		return this;
	}

}
