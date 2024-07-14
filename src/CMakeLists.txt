cmake_minimum_required(VERSION 3.16)

find_package(mo2-cmake CONFIG REQUIRED)
find_package(mo2-uibase CONFIG REQUIRED)

add_library(mo2_cpp_plugin SHARED
	mo2_cpp_plugin.h mo2_cpp_plugin.cpp
)
mo2_configure_plugin(mo2_cpp_plugin NO_SOURCES WARNINGS 4)
target_link_libraries(mo2_cpp_plugin PRIVATE mo2::uibase)
mo2_install_plugin(mo2_cpp_plugin)
