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
 * Optional arguments for the "hist_equal" operation.
 */
public class HistEqualOptions {

	private Integer band;

	/**
	 * Optional argument: band
	 * <p>
	 * Equalise with this band
	 * @return the value of {@code band}
	 */
	public Integer getBand() {
		return this.band;
	}

	/**
	 * Set the optional "band" argument.
	 * <p>
	 * Equalise with this band
	 * @param band the new value of {@code band}
	 */
	public void setBand(Integer band) {
		this.band = band;
	}

	/**
	 * Set the optional "band" argument.
	 * <p>
	 * Equalise with this band
	 * @param band the new value of {@code band}
	 * @return this object for chaining
	 */
	public HistEqualOptions band(Integer band) {
		setBand(band);
		return this;
	}

}
