cmake_minimum_required(VERSION 3.22.1)
project(oop_2lab)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

add_subdirectory(googletest)
include_directories(include)

add_executable(oop_2lab main.cpp src/Octal.cpp)
add_executable(oop_2lab_test tests/test.cpp src/Octal.cpp)

target_link_libraries(oop_2lab_test gtest_main)
add_test(NAME BASIC COMMAND oop_2lab_test)
