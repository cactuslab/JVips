file(GLOB SOURCES Vips.c VipsContext.c VipsException.c VipsImage.c AbstractVipsImage.c Max1Result.c)

add_library(JVips SHARED ${SOURCES})
add_dependencies(JVips Vips_header glib-2.0)

target_link_libraries(JVips ${VIPS_LIBRARIES} "-lgobject-2.0" "-lvips" "-lglib-2.0")

if ("${BUILD_TARGET}" STREQUAL "w64")
    # System.mapLibraryName doesn't expect "lib" prefix on Windows system
    set_target_properties(JVips PROPERTIES PREFIX "")
endif()
