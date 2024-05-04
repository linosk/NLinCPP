cmake_minimum_required(VERSION 3.13)

project(LOGGER)

set(CMAKE_CXX_COMPILER g++)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(LOGGER src/loggertime.cpp test/test_loggertime.cpp src/logger.cpp test/test_logger.cpp)
#add_executable(LOGGER test/test_logger.cpp)

target_include_directories(LOGGER PUBLIC include)
target_link_libraries(LOGGER gtest gtest_main)
#target_link_libraries(LOGGER GTest::GTest GTest::Main include/logger.hpp)

#project(LOGGER LANGUAGES CXX)

#set(CMAKE_C_COMPILER gcc)
#set(CMAKE_CXX_COMPILER g++)

#project(LOGGER)

#set(CMAKE_CXX_STANDARD 17)

#target_link_libraries(GTest::GTest GTest::Main)

#add_executable(LOGGER src/logger.cpp)
#add_executable(LOGGER test/test_logger.cpp)

#target_link_libraries(LOGGER GTest::GTest GTest::Main include/logger.hpp)