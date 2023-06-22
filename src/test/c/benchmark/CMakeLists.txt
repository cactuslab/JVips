add_executable(SimpleBenchmark SimpleBenchmark.c)
add_dependencies(SimpleBenchmark JVips)
target_link_libraries(SimpleBenchmark "${GLIB2_LDFLAGS}"  "${VIPS_LIBRARIES}" "-lgobject-2.0" "-lvips")
