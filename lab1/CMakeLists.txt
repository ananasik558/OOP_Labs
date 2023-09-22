cmake_minimum_required(VERSION 3.10)
project(lab1)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task task.cpp calc.cpp)

enable_testing()
add_executable(test1 test1.cpp calc.cpp)
target_link_libraries(test1 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND test1)
