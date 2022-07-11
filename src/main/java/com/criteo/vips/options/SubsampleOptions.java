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
import com.criteo.vips.PixelPacket;
import com.criteo.vips.enums.*;

/**
 * Optional arguments for the "subsample" operation.
 */
public class SubsampleOptions {

	private Boolean point;

	/**
	 * Optional argument: point
	 * <p>
	 * Point sample
	 * @return the value of {@code point}
	 */
	public Boolean getPoint() {
		return this.point;
	}

	/**
	 * Set the optional "point" argument.
	 * <p>
	 * Point sample
	 * @param point the new value of {@code point}
	 */
	public void setPoint(Boolean point) {
		this.point = point;
	}

	/**
	 * Set the optional "point" argument.
	 * <p>
	 * Point sample
	 * @param point the new value of {@code point}
	 * @return this object for chaining
	 */
	public SubsampleOptions point(Boolean point) {
		setPoint(point);
		return this;
	}

}
