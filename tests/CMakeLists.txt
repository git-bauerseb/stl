enable_testing()

# Test suit for type trait reimplementation
add_executable(
	type_traits_test
    type_traits_test.cpp
)

# Test suit for vector reimplementation
add_executable(
    vector_test
    vector_test.cpp
)

target_link_libraries(
	type_traits_test
	GTest::gtest_main
)

target_link_libraries(
    vector_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(type_traits_test vector_test)
