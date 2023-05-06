cmake_minimum_required(VERSION 3.6.0)
cmake_policy(VERSION 3.6.0)
if (POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

project(JVIPS C Java)

set(JVIPS_VERSION 8.14.2)

set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${JVIPS_VERSION}")
set(CPACK_SOURCE_GENERATOR "TGZ")

find_package(PkgConfig REQUIRED)

find_package(Java 1.8 REQUIRED)
include(UseJava)

SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

set(CMAKE_C_FLAGS "-std=c99")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -g3")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3 -g")
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -g")

# Mingw toolchain fails to find awt and jvm libraries.
# Just check if JNI_INCLUDE_DIRS is defined.
set(JAVA_AWT_LIBRARY NotNeeded)
set(JAVA_AWT_INCLUDE_PATH NotNeeded)
set(JAVA_JVM_LIBRARY NotNeeded)
set(JAVA_INCLUDE_PATH "$ENV{JAVA_HOME}/include")
set(JAVA_INCLUDE_PATH2 "${JAVA_INCLUDE_PATH}/${JAVA_INCLUDE_PLATFORM_PATH}")
find_package(JNI REQUIRED)

if (DEFINED JNI_INCLUDE_DIRS)
    message (STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    message (STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
endif()
include_directories(${JNI_INCLUDE_DIRS})

set(EXT_INSTALL_DIR "${CMAKE_SOURCE_DIR}/build/${BUILD_TARGET}/inst")

include_directories(SYSTEM "${EXT_INSTALL_DIR}/include/")
link_directories("${EXT_INSTALL_DIR}/lib/")

set(ENV{PKG_CONFIG_PATH} "${EXT_INSTALL_DIR}/lib/pkgconfig/")

add_subdirectory(lib)

pkg_check_modules(GLIB2 REQUIRED glib-2.0)
if (GLIB2_FOUND)
    message (STATUS "GLIB2_INCLUDE_DIRS=${GLIB2_INCLUDE_DIRS}")
    message (STATUS "GLIB2_LIBRARIES=${GLIB2_LIBRARIES}")
    message (STATUS "GLIB2_LIBRARY_DIRS=${GLIB2_LIBRARY_DIRS}")
    message (STATUS "GLIB2_LDFLAGS=${GLIB2_LDFLAGS}")
endif()
link_directories(${GLIB2_LIBRARY_DIRS})
include_directories(${GLIB2_INCLUDE_DIRS})

# Use libspng if WITH_LIBSPNG is ON, libpng otherwise.
option(WITH_LIBSPNG "Build libvips with libspng" OFF)
# Compile with libheif if WITH_LIBHEIF is ON, without it otherwise. libheif is required to handle the AVIF format.
option(WITH_LIBHEIF "Build libvips with libheif" OFF)

add_subdirectory(src/main/java/com/criteo/vips/)
add_subdirectory(src/main/c)

add_subdirectory(src/test/java/com/criteo/vips/)
add_subdirectory(src/test/c)

add_subdirectory(src/test/c/benchmark/)
