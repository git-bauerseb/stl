enable_testing()

add_executable(
	type_traits_test
    type_traits_test.cpp
)

target_link_libraries(
	type_traits_test
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(type_traits_test)
