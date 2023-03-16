set(JAVA_TEST_SOURCE_DIRECTORY "${PROJECT_SOURCE_DIR}/src/test/java/com/criteo/vips/")
set(JNI_TEST_HEADER_DIRECTORY "${PROJECT_SOURCE_DIR}/src/test/c/")
set(JAVA_TEST_SOURCE_FILES "${JAVA_TEST_SOURCE_DIRECTORY}/VipsEnumTest.java")
set(JUNIT_HOME "${PROJECT_SOURCE_DIR}/build/artifacts/junit-4.13.1.jar")

file(REMOVE ${JNI_TEST_HEADER_DIRECTORY}/com_criteo_vips_VipsEnumTest.h)

add_jar(JVipsTestWrapper ${JAVA_TEST_SOURCE_FILES} "${PROJECT_SOURCE_DIR}/src/main/java/com/criteo/vips//VipsException.java" INCLUDE_JARS ${JVipsWrapper} ${JUNIT_HOME} GENERATE_NATIVE_HEADERS VipsEnumTest_header DESTINATION ${JNI_TEST_HEADER_DIRECTORY})
add_dependencies(JVipsTestWrapper JVipsWrapper)
