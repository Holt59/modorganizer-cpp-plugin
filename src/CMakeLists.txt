cmake_minimum_required(VERSION 3.13)

set(srcs test-cpp-plugin.cpp resources.qrc)

file(GLOB_RECURSE ts_srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui")
qt5_create_translation(QM_FILES ${ts_srcs} test-cpp-plugin_en.ts)

add_library(test-cpp-plugin SHARED ${srcs} ${QM_FILES})

# simply link uibase
target_link_libraries(test-cpp-plugin uibase)


if (MO2_PATH)
    install(TARGETS test-cpp-plugin RUNTIME DESTINATION ${MO2_PATH}/plugins)
endif()
