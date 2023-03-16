# Pre-compile java classes for generating JNI header files

set(JAVA_SOURCE_DIRECTORY "${PROJECT_SOURCE_DIR}/src/main/java/com/criteo/vips/")
set(JNI_HEADER_DIRECTORY "${PROJECT_SOURCE_DIR}/src/main/c/")
set(JAVA_SOURCE_FILES
    "${JAVA_SOURCE_DIRECTORY}/Max1Result.java"
    "${JAVA_SOURCE_DIRECTORY}/PixelPacket.java"
    "${JAVA_SOURCE_DIRECTORY}/Vips.java"
    "${JAVA_SOURCE_DIRECTORY}/VipsContext.java"
    "${JAVA_SOURCE_DIRECTORY}/VipsException.java"
    "${JAVA_SOURCE_DIRECTORY}/Image.java"
    "${JAVA_SOURCE_DIRECTORY}/VipsImage.java"
    "${JAVA_SOURCE_DIRECTORY}/AbstractVipsImage.java")
file(GLOB JAVA_ENUM_SOURCE_FILES "${JAVA_SOURCE_DIRECTORY}/enums/*.java")
file(GLOB JAVA_OPTIONS_SOURCE_FILES "${JAVA_SOURCE_DIRECTORY}/options/*.java")
file(GLOB JAVA_CLASSPATH_JARS "${PROJECT_SOURCE_DIR}/build/artifacts/*.jar")

file(REMOVE ${JNI_HEADER_DIRECTORY}/com_criteo_vips_Vips.h
            ${JNI_HEADER_DIRECTORY}/com_criteo_vips_VipsContext.h
            ${JNI_HEADER_DIRECTORY}/com_criteo_vips_VipsImage.h
            ${JNI_HEADER_DIRECTORY}/com_criteo_vips_AbstractVipsImage.h)

add_jar(JVipsWrapper ${JAVA_ENUM_SOURCE_FILES} ${JAVA_OPTIONS_SOURCE_FILES} ${JAVA_SOURCE_FILES} INCLUDE_JARS ${JAVA_CLASSPATH_JARS} GENERATE_NATIVE_HEADERS Vips_header DESTINATION ${JNI_HEADER_DIRECTORY})

if(NOT ${BUILD_TARGET} STREQUAL "macOS")
    add_dependencies(Vips_header libvips)
    add_dependencies(VipsContext_header libvips)
    add_dependencies(VipsImage_header libvips)
    add_dependencies(AbstractVipsImage_header libvips)
    add_dependencies(Max1Result_header libvips)
endif()
