cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

project(NNinCPP)
set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

#target_compile_options(NNinCPP PRIVATE ${MY_CXX_FLAGS})

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(NNinCPP "${MY_SOURCES}")

target_include_directories(NNinCPP PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

project(testNNinCPP)

set(EXCLUDE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

list(REMOVE_ITEM MY_SOURCES "${EXCLUDE_FILE}")

file(GLOB_RECURSE MY_TESTS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp")

set(ALL_TEST_SOURCES ${MY_SOURCES} ${MY_TESTS})

add_executable(testNNinCPP "${ALL_TEST_SOURCES}")

target_include_directories(testNNinCPP PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG release-1.11.0
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

target_link_libraries(testNNinCPP gtest_main gmock_main)
