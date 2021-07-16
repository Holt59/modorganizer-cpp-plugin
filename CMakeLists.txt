cmake_minimum_required(VERSION 3.13)

# name of your project
project(test-cpp-plugin)

# BEGIN: uibase settings

# WARNING: Do not modify this, or at your own risk.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_library(uibase STATIC IMPORTED)
set_target_properties(uibase PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/uibase/uibase.lib")
target_link_libraries(uibase INTERFACE Qt5::Widgets)
target_include_directories(uibase INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/uibase")

# END: uibase settings

add_subdirectory(src)
