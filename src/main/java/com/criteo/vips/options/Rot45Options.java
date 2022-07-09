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
 * Optional arguments for the "rot45" operation.
 */
public class Rot45Options {

	private VipsAngle45 angle;

	/**
	 * Optional argument: angle
	 * <p>
	 * Angle to rotate image
	 * @return the value of {@code angle}
	 */
	public VipsAngle45 getAngle() {
		return this.angle;
	}

	/**
	 * Set the optional "angle" argument.
	 * <p>
	 * Angle to rotate image
	 * @param angle the new value of {@code angle}
	 */
	public void setAngle(VipsAngle45 angle) {
		this.angle = angle;
	}

	/**
	 * Set the optional "angle" argument.
	 * <p>
	 * Angle to rotate image
	 * @param angle the new value of {@code angle}
	 * @return this object for chaining
	 */
	public Rot45Options angle(VipsAngle45 angle) {
		setAngle(angle);
		return this;
	}

}
