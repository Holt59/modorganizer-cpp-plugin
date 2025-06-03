cmake_minimum_required(VERSION 3.31)

include(FetchContent)

# name of your project
project(mo2-demo-cpp-plugin)

# MO2 uibase settings
# WARNING: Do not modify this, or at your own risk.

option(MO2_PATH "Path to the MO2 installation folder.")

if (NOT MO2_PATH)
  message(FATAL_ERROR "MO2_PATH needs to be specified when configuring.")
endif()

cmake_path(ABSOLUTE_PATH MO2_PATH)

execute_process(
    COMMAND powershell -Command "(Get-ItemProperty ${MO2_PATH}\\ModOrganizer.exe).VersionInfo.ProductVersion"
    OUTPUT_VARIABLE MO2_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

message(STATUS "Detected MO2 version ${MO2_VERSION}.")

FetchContent_Declare(
  uibase
  URL      "https://github.com/ModOrganizer2/modorganizer/releases/download/v${MO2_VERSION}/Mod.Organizer-${MO2_VERSION}-uibase.7z"
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(uibase)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets LinguistTools REQUIRED)

add_library(uibase STATIC IMPORTED)
set_target_properties(uibase PROPERTIES
    IMPORTED_LOCATION "${uibase_SOURCE_DIR}/uibase.lib")
target_link_libraries(uibase INTERFACE Qt6::Widgets)
target_include_directories(uibase INTERFACE "${uibase_SOURCE_DIR}" "${uibase_SOURCE_DIR}/game_features")

# END: uibase settings

add_subdirectory(src)
