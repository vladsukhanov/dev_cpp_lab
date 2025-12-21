cmake_minimum_required(VERSION 3.10)

project(dev_cpp_lab_tests)

# Test source files
set(TEST_SOURCES
    BaseTest.cpp
    TempFunTest.cpp
    ../source/TempFun.cpp
    ../source/Base.cpp
)

# Create the test executable
add_executable(sample_tests ${TEST_SOURCES})

# Include project headers
target_include_directories(sample_tests PRIVATE ../include)

# Link with Google Test
target_link_libraries(sample_tests PRIVATE 
    gtest
    gtest_main
    -fprofile-arcs
    -ftest-coverage
)

target_compile_options(sample_tests PRIVATE -fprofile-arcs -ftest-coverage)

# Add tests to CTest
add_test(NAME run_ctests COMMAND sample_tests)
