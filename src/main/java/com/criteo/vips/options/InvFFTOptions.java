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
 * Optional arguments for the "invfft" operation.
 */
public class InvFFTOptions {

	private Boolean real;

	/**
	 * Optional argument: real
	 * <p>
	 * Output only the real part of the transform
	 * @return the value of {@code real}
	 */
	public Boolean getReal() {
		return this.real;
	}

	/**
	 * Set the optional "real" argument.
	 * <p>
	 * Output only the real part of the transform
	 * @param real the new value of {@code real}
	 */
	public void setReal(Boolean real) {
		this.real = real;
	}

	/**
	 * Set the optional "real" argument.
	 * <p>
	 * Output only the real part of the transform
	 * @param real the new value of {@code real}
	 * @return this object for chaining
	 */
	public InvFFTOptions real(Boolean real) {
		setReal(real);
		return this;
	}

}
