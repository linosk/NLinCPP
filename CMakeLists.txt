cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

project(NNinCPP)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(NNinCPP "${MY_SOURCES}")

target_include_directories(NNinCPP PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")