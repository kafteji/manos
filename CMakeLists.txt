cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(manos VERSION 0.1.0 LANGUAGES CXX)

find_package(GTest REQUIRED)

add_subdirectory(fndrd1d1)
add_subdirectory(0xPwner)

## fndrd1d1 executable

add_executable(test_fndrd1d1)

target_sources(test_fndrd1d1
    PRIVATE
        ${CMAKE_SOURCE_DIR}/main.cpp)

target_link_libraries(test_fndrd1d1
    PRIVATE
        fndrd1d1
        GTest::GTest)

## 0xPwner executable

add_executable(test_0xPwner)

target_sources(test_0xPwner
    PRIVATE
        ${CMAKE_SOURCE_DIR}/main.cpp)

target_link_libraries(test_0xPwner
    PRIVATE
        0xPwner
        GTest::GTest)
