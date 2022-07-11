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
 * Optional arguments for the "draw_flood" operation.
 */
public class DrawFloodOptions {

	private Image test;
	private Boolean equal;

	/**
	 * Optional argument: test
	 * <p>
	 * Test pixels in this image
	 * @return the value of {@code test}
	 */
	public Image getTest() {
		return this.test;
	}

	/**
	 * Set the optional "test" argument.
	 * <p>
	 * Test pixels in this image
	 * @param test the new value of {@code test}
	 */
	public void setTest(Image test) {
		this.test = test;
	}

	/**
	 * Set the optional "test" argument.
	 * <p>
	 * Test pixels in this image
	 * @param test the new value of {@code test}
	 * @return this object for chaining
	 */
	public DrawFloodOptions test(Image test) {
		setTest(test);
		return this;
	}

	/**
	 * Optional argument: equal
	 * <p>
	 * DrawFlood while equal to edge
	 * @return the value of {@code equal}
	 */
	public Boolean getEqual() {
		return this.equal;
	}

	/**
	 * Set the optional "equal" argument.
	 * <p>
	 * DrawFlood while equal to edge
	 * @param equal the new value of {@code equal}
	 */
	public void setEqual(Boolean equal) {
		this.equal = equal;
	}

	/**
	 * Set the optional "equal" argument.
	 * <p>
	 * DrawFlood while equal to edge
	 * @param equal the new value of {@code equal}
	 * @return this object for chaining
	 */
	public DrawFloodOptions equal(Boolean equal) {
		setEqual(equal);
		return this;
	}

}
