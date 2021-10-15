add_library(kafteji STATIC)

target_compile_features(kafteji
    PUBLIC
        cxx_std_20)

target_link_libraries(kafteji
    PUBLIC
        GTest::GTest)

target_sources(kafteji
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/data_structures/lru_cache/lru_cache.cpp)
