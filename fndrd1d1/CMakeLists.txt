add_library(fndrd1d1 STATIC)

target_compile_features(fndrd1d1
    PUBLIC
        cxx_std_20)

target_link_libraries(fndrd1d1
    PUBLIC
        GTest::GTest)

target_sources(fndrd1d1
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/minmax_element.cpp)
