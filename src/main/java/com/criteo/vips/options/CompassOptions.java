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
 * Optional arguments for the "compass" operation.
 */
public class CompassOptions {

	private Integer times;
	private VipsAngle45 angle;
	private VipsCombine combine;
	private VipsPrecision precision;
	private Integer layers;
	private Integer cluster;

	/**
	 * Optional argument: times
	 * <p>
	 * Rotate and convolve this many times
	 * @return the value of {@code times}
	 */
	public Integer getTimes() {
		return this.times;
	}

	/**
	 * Set the optional "times" argument.
	 * <p>
	 * Rotate and convolve this many times
	 * @param times the new value of {@code times}
	 */
	public void setTimes(Integer times) {
		this.times = times;
	}

	/**
	 * Set the optional "times" argument.
	 * <p>
	 * Rotate and convolve this many times
	 * @param times the new value of {@code times}
	 * @return this object for chaining
	 */
	public CompassOptions times(Integer times) {
		setTimes(times);
		return this;
	}

	/**
	 * Optional argument: angle
	 * <p>
	 * Rotate mask by this much between convolutions
	 * @return the value of {@code angle}
	 */
	public VipsAngle45 getAngle() {
		return this.angle;
	}

	/**
	 * Set the optional "angle" argument.
	 * <p>
	 * Rotate mask by this much between convolutions
	 * @param angle the new value of {@code angle}
	 */
	public void setAngle(VipsAngle45 angle) {
		this.angle = angle;
	}

	/**
	 * Set the optional "angle" argument.
	 * <p>
	 * Rotate mask by this much between convolutions
	 * @param angle the new value of {@code angle}
	 * @return this object for chaining
	 */
	public CompassOptions angle(VipsAngle45 angle) {
		setAngle(angle);
		return this;
	}

	/**
	 * Optional argument: combine
	 * <p>
	 * Combine convolution results like this
	 * @return the value of {@code combine}
	 */
	public VipsCombine getCombine() {
		return this.combine;
	}

	/**
	 * Set the optional "combine" argument.
	 * <p>
	 * Combine convolution results like this
	 * @param combine the new value of {@code combine}
	 */
	public void setCombine(VipsCombine combine) {
		this.combine = combine;
	}

	/**
	 * Set the optional "combine" argument.
	 * <p>
	 * Combine convolution results like this
	 * @param combine the new value of {@code combine}
	 * @return this object for chaining
	 */
	public CompassOptions combine(VipsCombine combine) {
		setCombine(combine);
		return this;
	}

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
	public CompassOptions precision(VipsPrecision precision) {
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
	public CompassOptions layers(Integer layers) {
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
	public CompassOptions cluster(Integer cluster) {
		setCluster(cluster);
		return this;
	}

}
