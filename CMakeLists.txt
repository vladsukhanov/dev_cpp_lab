cmake_minimum_required(VERSION 3.10)

project(dev_cpp_lab)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
    source/main.cpp
    source/TempFun.cpp
    source/Base.cpp
)

add_executable(sample_program ${SOURCES})

target_include_directories(sample_program PRIVATE include)

## Adding tests
enable_testing() # Enable CTest support
add_subdirectory(external/googletest)
add_subdirectory(test)
