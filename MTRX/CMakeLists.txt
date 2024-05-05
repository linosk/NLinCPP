cmake_minimum_required(VERSION 3.13)

project(MTRX)

set(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_STANDARD 17)

add_executable(MTRX src/main.cpp src/mtrx.cpp ../Logger/src/logger.cpp ../Logger/src/loggertime.cpp)

target_include_directories(MTRX PUBLIC include ../Logger/include)