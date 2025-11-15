/*
  Copyright (c) 2019 Criteo

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

package com.criteo.vips;

import java.awt.Color;

public class PixelPacket extends Vips {
    double r;
    double g;
    double b;
    double a;
    private int components;

    public PixelPacket(double r, double g, double b, double a) {
        this.r = r;
        this.g = g;
        this.b = b;
        this.a = a;
        this.components = 4;
    }

    public PixelPacket(double r, double g, double b) {
        this(r, g, b, 255.0);
        this.components = 3;
    }

    public PixelPacket(double r) {
        this(r, r, r, 255.0);
        this.components = 1;
    }

    public PixelPacket(double r, double a) {
        this(r, r, r, a);
        this.components = 2;
    }

    public PixelPacket(Color color) {
        this(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    }

    public PixelPacket(double[] pixel) {
        boolean isMonochrome = pixel.length < 3;
        boolean hasAlpha = pixel.length == 2 || pixel.length == 4;
        if (isMonochrome) {
            this.r = pixel[0];
            this.g = pixel[0];
            this.b = pixel[0];
            this.a = hasAlpha ? pixel[1] : 255.0;
        } else {
            this.r = pixel[0];
            this.g = pixel[1];
            this.b = pixel[2];
            this.a = hasAlpha ? pixel[3] : 255.0;
        }
        this.components = pixel.length;
    }

    public double getRed() {
        return r;
    }

    public double getGreen() {
        return g;
    }

    public double getBlue() {
        return b;
    }

    public double getAlpha() {
        return a;
    }

    public void setRed(double r) {
        this.r = r;
    }

    public void setGreen(double g) {
        this.g = g;
    }

    public void setBlue(double b) {
        this.b = b;
    }

    public void setAlpha(double a) {
        this.a = a;
    }

    public double[] getComponents() {
        return getComponents(this.components);
    }

    public double[] getComponents(int count) {
        if (count == 1) {
            return new double[] { r };
        } else if (count == 2) {
            return new double[] { r, a };
        } else if (count == 3) {
            return new double[] { r, g, b };
        } else if (count == 4) {
            return new double[] { r, g, b, a };
        } else {
            throw new IllegalArgumentException("Unsupported component count: " + count);
        }
    }

    /**
     * Some operations sometimes require no alpha component in the pixel vector.
     */
    public double[] getComponentsNoAlpha() {
        if (components == 1 || components == 2) {
            return new double[] { r };
        } else if (components == 3 || components == 4) {
            return new double[] { r, g, b };
        } else {
            throw new IllegalArgumentException("Unsupported component count: " + components);
        }
    }

    /**
     * Some operations sometimes require an alpha component in the pixel vector.
     */
    public double[] getComponentsWithAlpha() {
        if (components == 1 || components == 2) {
            return new double[] { r, a };
        } else if (components == 3 || components == 4) {
            return new double[] { r, g, b, a };
        } else {
            throw new IllegalArgumentException("Unsupported component count: " + components);
        }
    }

    @Override
    public boolean equals(Object o) {
        if (o instanceof PixelPacket) {
            PixelPacket pixelPacket = (PixelPacket) o;

            if (components != pixelPacket.components) {
                return false;
            }
            if (components >= 1 && r != pixelPacket.r) {
                return false;
            }
            if (components >= 2 && g != pixelPacket.g) {
                return false;
            }
            if (components >= 3 && b != pixelPacket.b) {
                return false;
            }
            if (components >= 4 && a != pixelPacket.a) {
                return false;
            }
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        if (components == 4) {
            return "[r = " + r + ", g = " + g + ", b = " + b + ", a = " + a + "]";
        } else if (components == 3) {
            return "[r = " + r + ", g = " + g + ", b = " + b + "]";
        } else if (components == 2) {
            return "[r = " + r + ", a = " + a + "]";
        } else if (components == 1) {
            return "[r = " + r + "]";
        } else {
            return super.toString();
        }
    }
}
