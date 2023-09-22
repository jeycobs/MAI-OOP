cmake_minimum_required(VERSION 3.10)
project(validbrackets)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#делаем переменные с переменными
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

#инклюдим дирректории для билда
include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false ${TEST_DIR}/*.cpp)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})
add_executable(main main.cpp)
add_executable(main_test ${TEST_SOURCES})

target_link_libraries(main PRIVATE ${CMAKE_PROJECT_NAME}_lib)
target_include_directories(main_test PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(main_test PRIVATE ${CMAKE_PROJECT_NAME}_lib gtest gtest_main)

add_test(NAME BASIC COMMAND tests01)



