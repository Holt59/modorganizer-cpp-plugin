cmake_minimum_required(VERSION 3.13)

set(srcs test-cpp-plugin.cpp resources.qrc)

add_library(test-cpp-plugin SHARED ${srcs})

# simply link uibase
target_link_libraries(test-cpp-plugin uibase)

if (MO2_PATH)
    install(TARGETS test-cpp-plugin RUNTIME DESTINATION ${MO2_PATH}/plugins)
endif()
