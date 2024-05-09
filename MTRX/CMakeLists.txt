cmake_minimum_required(VERSION 3.13)

project(MTRX)

set(CMAKE_CXX_COMPILER g++)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(MTRX src/mtrx.cpp ../Logger/src/logger.cpp ../Logger/src/loggertime.cpp test/test_main.cpp test/test_mtrx.cpp)

target_include_directories(MTRX PUBLIC include ../Logger/include)
target_link_libraries(MTRX gtest gtest_main)