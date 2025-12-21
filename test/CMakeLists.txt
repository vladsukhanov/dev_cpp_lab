cmake_minimum_required(VERSION 3.10)

project(dev_cpp_lab_tests)

# Файлы тестов
set(TEST_SOURCES
    BaseTest.cpp
    TempFunTest.cpp
    ../source/TempFun.cpp
    ../source/Base.cpp
)

# Создаём исполняемый файл для тестов
add_executable(sample_tests ${TEST_SOURCES})

# Подключаем заголовки проекта
target_include_directories(sample_tests PRIVATE ../include)

# Линкуем с Google Test
target_link_libraries(sample_tests PRIVATE 
    gtest
    gtest_main
    -fprofile-arcs
    -ftest-coverage
)

target_compile_options(sample_tests PRIVATE -fprofile-arcs -ftest-coverage)

# Добавляем тесты в CTest
add_test(NAME run_ctests COMMAND sample_tests)
