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

import java.io.*;
import java.nio.file.Files;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Vips {
    private static final Logger LOGGER = LoggerFactory.getLogger("com.criteo.vips.Vips");
    private static final String SYSTEM_NAME = System.getProperty("os.name").toLowerCase();

    private static final String[] LINUX_LIBRARIES = {
            "aom",
            "heif",
            "exif",
            "png16",
            "spng",
            "gif",
            "cgif",
            "jpeg",
            "turbojpeg",
            "webp",
            "webpmux",
            "webpdemux",
            "imagequant",
            "lcms2",
            "vips"
    };

    /**
     * Actually, loading embedded libraries doesn't work on Windows 64.
     * An UnsatisfiedLinkError exception is thrown with embedded dll:
     * "Can't find dependent libraries"
     * Thus, JVips.dll should use system libraries.
     * We only provide libimagequant because it's out of windows binaries release.
     * <p>
     * TODO: add Windows 64 embedded libraries
     */
    private final static String[] WINDOWS_LIBRARIES = {
            "libimagequant"
    };

    private static boolean available;

    static {
        try {
            if (tryLoadLibrariesFromJar())
                LOGGER.debug("JVips dependencies have been loaded from jar");
            else
                LOGGER.debug("Using JVips dependencies installed on system");
            LOGGER.debug("Trying to load JVips");
            loadLibraryFromJar("JVips");
            init();
            LOGGER.debug("Loaded JVips");
            available = true;
        } catch (IOException e) {
            available = false;
            LOGGER.warn("Can't load JVips library and/or dependencies: {}", e.getMessage());
        } catch (VipsException e) {
            available = false;
            LOGGER.warn("Failed to init JVips", e);
        } catch (UnsatisfiedLinkError e) {
            available = false;
            /* We should be able to load the JVips native libraries, as they are always bundled in the jar */
            LOGGER.warn("JVips native libraries are not available", e);
        }
    }

    /**
     * Is VIPS initialised and available to be used?
     * @return
     */
    public static boolean isAvailable() {
        return available;
    }

    private static boolean tryLoadLibrariesFromJar() throws IOException {
        if (isMacOS())
            return true;
        String[] libraries = !isWindows() ? LINUX_LIBRARIES : WINDOWS_LIBRARIES;
        try {
            boolean loadedSome = false;
            for (String library : libraries) {
                if (loadLibraryFromJar(library)) {
                    loadedSome = true;
                }
            }
            return loadedSome;
        } catch (RuntimeException e) {
            return false;
        }
    }

    private static boolean isWindows() {
        return SYSTEM_NAME.indexOf("win") >= 0;
    }

    private static boolean isMacOS() {
        return (SYSTEM_NAME.indexOf("mac") >= 0);
    }

    private static File tempExtractionDir;
    
    private static File tempExtractionDir() throws IOException {
        if (tempExtractionDir != null) {
            return tempExtractionDir;
        }

        tempExtractionDir = Files.createTempDirectory("jvips").toFile();
        tempExtractionDir.deleteOnExit();
        return tempExtractionDir;
    }

    private static boolean loadLibraryFromJar(String name) throws IOException {
        String libName = System.mapLibraryName(name);
        File temp;
        try (InputStream in = Thread.currentThread().getContextClassLoader().getResourceAsStream(libName)) {
            if (in == null) {
                LOGGER.debug("Could not load lib '{}' via classloader", libName);
                return false;
            }
            byte[] buffer = new byte[65536];
            int read;
            temp = new File(tempExtractionDir(), libName);
            temp.deleteOnExit();
            try (FileOutputStream fos = new FileOutputStream(temp)) {
                while ((read = in.read(buffer)) != -1) {
                    fos.write(buffer, 0, read);
                }
            }
        }
        System.load(temp.getAbsolutePath());
        return true;
    }

    /**
     * Initialize vips context
     *
     * @throws VipsException
     */
    private static native void init() throws VipsException;

}
