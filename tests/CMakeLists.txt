enable_testing()

add_executable(
	impl_test
	test.cpp
)

target_link_libraries(
	impl_test
	GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(impl_test)
