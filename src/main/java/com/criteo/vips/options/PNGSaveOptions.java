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
import com.criteo.vips.enums.VipsForeignPngFilter;

public class PNGSaveOptions {

	private int compression = -1;
	private boolean interlace;
	private String profile;
	private int filter = -1;
	private boolean palette;
	private int q;
	private double dither;
	private int bitdepth = -1;
	private int effort = -1;
	private boolean strip;
	private double[] background;
	private int pageHeight = -1;

	public int getCompression() {
		return compression;
	}

	public void setCompression(int compression) {
		this.compression = compression;
	}

	public boolean isInterlace() {
		return interlace;
	}

	public void setInterlace(boolean interlace) {
		this.interlace = interlace;
	}

	public PNGSaveOptions interlace(boolean interlace) {
		setInterlace(interlace);
		return this;
	}

	public String getProfile() {
		return profile;
	}

	public void setProfile(String profile) {
		this.profile = profile;
	}

	public VipsForeignPngFilter getFilter() {
		if (filter != -1) {
			return VipsForeignPngFilter.valueOf(filter);
		} else {
			return null;
		}
	}

	public void setFilter(VipsForeignPngFilter filter) {
		if (filter != null) {
			this.filter = filter.getValue();
		} else {
			this.filter = -1;
		}
	}

	public boolean isPalette() {
		return palette;
	}

	public void setPalette(boolean palette) {
		this.palette = palette;
	}

	public int getQ() {
		return q;
	}

	public void setQ(int q) {
		this.q = q;
	}

	public double getDither() {
		return dither;
	}

	public void setDither(double dither) {
		this.dither = dither;
	}

	public int getBitdepth() {
		return bitdepth;
	}

	public void setBitdepth(int bitdepth) {
		this.bitdepth = bitdepth;
	}

	public PNGSaveOptions bitdepth(int bitdepth) {
		setBitdepth(bitdepth);
		return this;
	}

	public int getEffort() {
		return effort;
	}

	public void setEffort(int effort) {
		this.effort = effort;
	}

	public boolean isStrip() {
		return strip;
	}

	public void setStrip(boolean strip) {
		this.strip = strip;
	}

	public PNGSaveOptions strip(boolean strip) {
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

	public int getPageHeight() {
		return pageHeight;
	}

	public void setPageHeight(int pageHeight) {
		this.pageHeight = pageHeight;
	}

}
