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
 * Optional arguments for the "convasep" operation.
 */
public class ConvasepOptions {

	private Integer layers;

	/**
	 * Optional argument: layers
	 * <p>
	 * Use this many layers in approximation
	 * @return the value of {@code layers}
	 */
	public Integer getLayers() {
		return this.layers;
	}

	/**
	 * Set the optional "layers" argument.
	 * <p>
	 * Use this many layers in approximation
	 * @param layers the new value of {@code layers}
	 */
	public void setLayers(Integer layers) {
		this.layers = layers;
	}

	/**
	 * Set the optional "layers" argument.
	 * <p>
	 * Use this many layers in approximation
	 * @param layers the new value of {@code layers}
	 * @return this object for chaining
	 */
	public ConvasepOptions layers(Integer layers) {
		setLayers(layers);
		return this;
	}

}
