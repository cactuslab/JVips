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
 * Optional arguments for the "hist_find_indexed" operation.
 */
public class HistFindIndexedOptions {

	private VipsCombine combine;

	/**
	 * Optional argument: combine
	 * <p>
	 * Combine bins like this
	 * @return the value of {@code combine}
	 */
	public VipsCombine getCombine() {
		return this.combine;
	}

	/**
	 * Set the optional "combine" argument.
	 * <p>
	 * Combine bins like this
	 * @param combine the new value of {@code combine}
	 */
	public void setCombine(VipsCombine combine) {
		this.combine = combine;
	}

	/**
	 * Set the optional "combine" argument.
	 * <p>
	 * Combine bins like this
	 * @param combine the new value of {@code combine}
	 * @return this object for chaining
	 */
	public HistFindIndexedOptions combine(VipsCombine combine) {
		setCombine(combine);
		return this;
	}

}
