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
 * Optional arguments for the "bandrank" operation.
 */
public class BandrankOptions {

	private Integer index;

	/**
	 * Optional argument: index
	 * <p>
	 * Select this band element from sorted list
	 * @return the value of {@code index}
	 */
	public Integer getIndex() {
		return this.index;
	}

	/**
	 * Set the optional "index" argument.
	 * <p>
	 * Select this band element from sorted list
	 * @param index the new value of {@code index}
	 */
	public void setIndex(Integer index) {
		this.index = index;
	}

	/**
	 * Set the optional "index" argument.
	 * <p>
	 * Select this band element from sorted list
	 * @param index the new value of {@code index}
	 * @return this object for chaining
	 */
	public BandrankOptions index(Integer index) {
		setIndex(index);
		return this;
	}

}
