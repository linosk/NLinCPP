cmake_minimum_required(VERSION 3.13)

project(MnistReader)

set(CMAKE_CXX_COMPILER g++)

#find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS 
    "src/*.cpp"
    "../MTRX/src/*.cpp"
    "../Logger/src/*.cpp"
)

add_executable(MnistReader "${MY_SOURCES}")

target_include_directories(MnistReader PUBLIC
    "include"
    "../MTRX/include"
    "../Logger/include"
    )
#target_link_libraries(MTRX gtest gtest_main)