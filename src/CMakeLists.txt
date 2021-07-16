cmake_minimum_required(VERSION 3.13)

add_library(test-cpp-plugin SHARED test-cpp-plugin.cpp)

# simply link uibase
target_link_libraries(test-cpp-plugin uibase)
