cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(manos VERSION 0.1.0 LANGUAGES CXX)

find_package(GTest REQUIRED)

add_subdirectory(fndrd1d1)
add_subdirectory(kafteji)

## fndrd1d1 executable

add_executable(test_fndrd1d1)

target_sources(test_fndrd1d1
    PRIVATE
        ${CMAKE_SOURCE_DIR}/main.cpp)

target_link_libraries(test_fndrd1d1
    PRIVATE
        fndrd1d1
        GTest::GTest)

## kafteji executable

add_executable(test_kafteji)

target_sources(test_kafteji
    PRIVATE
        ${CMAKE_SOURCE_DIR}/main.cpp)

target_link_libraries(test_kafteji
    PRIVATE
        kafteji
        GTest::GTest)
