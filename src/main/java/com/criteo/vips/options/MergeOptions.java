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
 * Optional arguments for the "merge" operation.
 */
public class MergeOptions {

	private Integer mblend;

	/**
	 * Optional argument: mblend
	 * <p>
	 * Maximum blend size
	 * @return the value of {@code mblend}
	 */
	public Integer getMblend() {
		return this.mblend;
	}

	/**
	 * Set the optional "mblend" argument.
	 * <p>
	 * Maximum blend size
	 * @param mblend the new value of {@code mblend}
	 */
	public void setMblend(Integer mblend) {
		this.mblend = mblend;
	}

	/**
	 * Set the optional "mblend" argument.
	 * <p>
	 * Maximum blend size
	 * @param mblend the new value of {@code mblend}
	 * @return this object for chaining
	 */
	public MergeOptions mblend(Integer mblend) {
		setMblend(mblend);
		return this;
	}

}
