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
 * Optional arguments for the "jxlsave" operation.
 */
public class JXLSaveOptions {

	private Integer tier;
	private Double distance;
	private Integer effort;
	private Boolean lossless;
	private Integer q;
	private Boolean strip;
	private double[] background;
	private Integer pageHeight;

	/**
	 * Optional argument: tier
	 * <p>
	 * Decode speed tier
	 * @return the value of {@code tier}
	 */
	public Integer getTier() {
		return this.tier;
	}

	/**
	 * Set the optional "tier" argument.
	 * <p>
	 * Decode speed tier
	 * @param tier the new value of {@code tier}
	 */
	public void setTier(Integer tier) {
		this.tier = tier;
	}

	/**
	 * Set the optional "tier" argument.
	 * <p>
	 * Decode speed tier
	 * @param tier the new value of {@code tier}
	 * @return this object for chaining
	 */
	public JXLSaveOptions tier(Integer tier) {
		setTier(tier);
		return this;
	}

	/**
	 * Optional argument: distance
	 * <p>
	 * Target butteraugli distance
	 * @return the value of {@code distance}
	 */
	public Double getDistance() {
		return this.distance;
	}

	/**
	 * Set the optional "distance" argument.
	 * <p>
	 * Target butteraugli distance
	 * @param distance the new value of {@code distance}
	 */
	public void setDistance(Double distance) {
		this.distance = distance;
	}

	/**
	 * Set the optional "distance" argument.
	 * <p>
	 * Target butteraugli distance
	 * @param distance the new value of {@code distance}
	 * @return this object for chaining
	 */
	public JXLSaveOptions distance(Double distance) {
		setDistance(distance);
		return this;
	}

	/**
	 * Optional argument: effort
	 * <p>
	 * Encoding effort
	 * @return the value of {@code effort}
	 */
	public Integer getEffort() {
		return this.effort;
	}

	/**
	 * Set the optional "effort" argument.
	 * <p>
	 * Encoding effort
	 * @param effort the new value of {@code effort}
	 */
	public void setEffort(Integer effort) {
		this.effort = effort;
	}

	/**
	 * Set the optional "effort" argument.
	 * <p>
	 * Encoding effort
	 * @param effort the new value of {@code effort}
	 * @return this object for chaining
	 */
	public JXLSaveOptions effort(Integer effort) {
		setEffort(effort);
		return this;
	}

	/**
	 * Optional argument: lossless
	 * <p>
	 * Enable lossless compression
	 * @return the value of {@code lossless}
	 */
	public Boolean getLossless() {
		return this.lossless;
	}

	/**
	 * Set the optional "lossless" argument.
	 * <p>
	 * Enable lossless compression
	 * @param lossless the new value of {@code lossless}
	 */
	public void setLossless(Boolean lossless) {
		this.lossless = lossless;
	}

	/**
	 * Set the optional "lossless" argument.
	 * <p>
	 * Enable lossless compression
	 * @param lossless the new value of {@code lossless}
	 * @return this object for chaining
	 */
	public JXLSaveOptions lossless(Boolean lossless) {
		setLossless(lossless);
		return this;
	}

	/**
	 * Optional argument: Q
	 * <p>
	 * Quality factor
	 * @return the value of {@code q}
	 */
	public Integer getQ() {
		return this.q;
	}

	/**
	 * Set the optional "Q" argument.
	 * <p>
	 * Quality factor
	 * @param q the new value of {@code q}
	 */
	public void setQ(Integer q) {
		this.q = q;
	}

	/**
	 * Set the optional "Q" argument.
	 * <p>
	 * Quality factor
	 * @param q the new value of {@code q}
	 * @return this object for chaining
	 */
	public JXLSaveOptions q(Integer q) {
		setQ(q);
		return this;
	}

	/**
	 * Optional argument: strip
	 * <p>
	 * Strip all metadata from image
	 * @return the value of {@code strip}
	 */
	public Boolean getStrip() {
		return this.strip;
	}

	/**
	 * Set the optional "strip" argument.
	 * <p>
	 * Strip all metadata from image
	 * @param strip the new value of {@code strip}
	 */
	public void setStrip(Boolean strip) {
		this.strip = strip;
	}

	/**
	 * Set the optional "strip" argument.
	 * <p>
	 * Strip all metadata from image
	 * @param strip the new value of {@code strip}
	 * @return this object for chaining
	 */
	public JXLSaveOptions strip(Boolean strip) {
		setStrip(strip);
		return this;
	}

	/**
	 * Optional argument: background
	 * <p>
	 * Background value
	 * @return the value of {@code background}
	 */
	public double[] getBackground() {
		return this.background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background value
	 * @param background the new value of {@code background}
	 */
	public void setBackground(double[] background) {
		this.background = background;
	}

	/**
	 * Set the optional "background" argument.
	 * <p>
	 * Background value
	 * @param background the new value of {@code background}
	 * @return this object for chaining
	 */
	public JXLSaveOptions background(double[] background) {
		setBackground(background);
		return this;
	}

	/**
	 * Optional argument: page-height
	 * <p>
	 * Set page height for multipage save
	 * @return the value of {@code pageHeight}
	 */
	public Integer getPageHeight() {
		return this.pageHeight;
	}

	/**
	 * Set the optional "page-height" argument.
	 * <p>
	 * Set page height for multipage save
	 * @param pageHeight the new value of {@code pageHeight}
	 */
	public void setPageHeight(Integer pageHeight) {
		this.pageHeight = pageHeight;
	}

	/**
	 * Set the optional "page-height" argument.
	 * <p>
	 * Set page height for multipage save
	 * @param pageHeight the new value of {@code pageHeight}
	 * @return this object for chaining
	 */
	public JXLSaveOptions pageHeight(Integer pageHeight) {
		setPageHeight(pageHeight);
		return this;
	}

}
