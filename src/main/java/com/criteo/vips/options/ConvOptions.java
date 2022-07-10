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
 * Optional arguments for the "conv" operation.
 */
public class ConvOptions {

	private VipsPrecision precision;
	private Integer layers;
	private Integer cluster;

	/**
	 * Optional argument: precision
	 * <p>
	 * Convolve with this precision
	 * @return the value of {@code precision}
	 */
	public VipsPrecision getPrecision() {
		return this.precision;
	}

	/**
	 * Set the optional "precision" argument.
	 * <p>
	 * Convolve with this precision
	 * @param precision the new value of {@code precision}
	 */
	public void setPrecision(VipsPrecision precision) {
		this.precision = precision;
	}

	/**
	 * Set the optional "precision" argument.
	 * <p>
	 * Convolve with this precision
	 * @param precision the new value of {@code precision}
	 * @return this object for chaining
	 */
	public ConvOptions precision(VipsPrecision precision) {
		setPrecision(precision);
		return this;
	}

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
	public ConvOptions layers(Integer layers) {
		setLayers(layers);
		return this;
	}

	/**
	 * Optional argument: cluster
	 * <p>
	 * Cluster lines closer than this in approximation
	 * @return the value of {@code cluster}
	 */
	public Integer getCluster() {
		return this.cluster;
	}

	/**
	 * Set the optional "cluster" argument.
	 * <p>
	 * Cluster lines closer than this in approximation
	 * @param cluster the new value of {@code cluster}
	 */
	public void setCluster(Integer cluster) {
		this.cluster = cluster;
	}

	/**
	 * Set the optional "cluster" argument.
	 * <p>
	 * Cluster lines closer than this in approximation
	 * @param cluster the new value of {@code cluster}
	 * @return this object for chaining
	 */
	public ConvOptions cluster(Integer cluster) {
		setCluster(cluster);
		return this;
	}

}
