cmake_minimum_required(VERSION 3.31)

set(srcs mo2_cpp_plugin.cpp mo2_cpp_plugin.h resources.qrc)

file(GLOB_RECURSE ts_srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui")
qt6_create_translation(QM_FILES ${ts_srcs} mo2_cpp_plugin_en.ts)

add_library(mo2_cpp_plugin SHARED ${srcs} ${QM_FILES})

# simply link uibase
target_link_libraries(mo2_cpp_plugin uibase)

install(TARGETS mo2_cpp_plugin RUNTIME DESTINATION ${MO2_PATH}/plugins)
