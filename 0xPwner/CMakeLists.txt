add_library(0xPwner STATIC)

target_compile_features(0xPwner
    PUBLIC
        cxx_std_20)

target_link_libraries(0xPwner
    PUBLIC
        GTest::GTest)

target_sources(0xPwner
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/data_structures/lru_cache.cpp)
