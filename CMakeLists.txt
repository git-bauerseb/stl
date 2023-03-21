cmake_minimum_required(VERSION 3.11)

project(
	stl
	VERSION 0.1
	LANGUAGES CXX
)

# Fetch dependency
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable gtest unit testing
enable_testing()
add_subdirectory(tests)
add_subdirectory(src)
