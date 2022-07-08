/*
  Copyright (c) 2021 Criteo

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

import com.criteo.vips.PixelPacket;
import com.criteo.vips.enums.VipsForeignSubsample;

public class JPEGSaveOptions {

	private int q;
	private String profile;
	private boolean optimizeCoding;
	private boolean interlace;
	private boolean trellisQuant;
	private boolean overshootDeringing;
	private boolean optimizeScans;
	private int quantTable;
	private int subsampleMode = -1;
	private int restartInterval;
	private boolean strip;
	private double[] background;
	private int pageHeight;

	public int getQ() {
		return q;
	}

	public void setQ(int q) {
		this.q = q;
	}

	public JPEGSaveOptions q(int q) {
		setQ(q);
		return this;
	}

	public String getProfile() {
		return profile;
	}

	public void setProfile(String profile) {
		this.profile = profile;
	}

	public boolean isOptimizeCoding() {
		return optimizeCoding;
	}

	public void setOptimizeCoding(boolean optimizeCoding) {
		this.optimizeCoding = optimizeCoding;
	}

	public boolean isInterlace() {
		return interlace;
	}

	public void setInterlace(boolean interlace) {
		this.interlace = interlace;
	}

	public boolean isTrellisQuant() {
		return trellisQuant;
	}

	public void setTrellisQuant(boolean trellisQuant) {
		this.trellisQuant = trellisQuant;
	}

	public boolean isOvershootDeringing() {
		return overshootDeringing;
	}

	public void setOvershootDeringing(boolean overshootDeringing) {
		this.overshootDeringing = overshootDeringing;
	}

	public boolean isOptimizeScans() {
		return optimizeScans;
	}

	public void setOptimizeScans(boolean optimizeScans) {
		this.optimizeScans = optimizeScans;
	}

	public int getQuantTable() {
		return quantTable;
	}

	public void setQuantTable(int quantTable) {
		this.quantTable = quantTable;
	}

	public VipsForeignSubsample getSubsampleMode() {
		if (subsampleMode != -1) {
			return VipsForeignSubsample.valueOf(subsampleMode);
		} else {
			return null;
		}
	}

	public void setSubsampleMode(VipsForeignSubsample subsampleMode) {
		if (subsampleMode != null) {
			this.subsampleMode = subsampleMode.getValue();
		} else {
			this.subsampleMode = -1;
		}
	}

	public int getRestartInterval() {
		return restartInterval;
	}

	public void setRestartInterval(int restartInterval) {
		this.restartInterval = restartInterval;
	}

	public boolean isStrip() {
		return strip;
	}

	public void setStrip(boolean strip) {
		this.strip = strip;
	}

	public JPEGSaveOptions strip(boolean strip) {
		setStrip(strip);
		return this;
	}

	public PixelPacket getBackground() {
		if (background != null) {
			return new PixelPacket(background);
		} else {
			return null;
		}
	}

	public void setBackground(PixelPacket background) {
		if (background != null) {
			this.background = background.getComponents();
		} else {
			this.background = null;
		}
	}

	public JPEGSaveOptions background(PixelPacket background) {
		setBackground(background);
		return this;
	}

	public int getPageHeight() {
		return pageHeight;
	}

	public void setPageHeight(int pageHeight) {
		this.pageHeight = pageHeight;
	}

}
