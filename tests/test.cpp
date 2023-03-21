#include <gtest/gtest.h>

TEST(Test, Basic) {
	EXPECT_STRNE("hello", "world");
	EXPECT_EQ(7*6, 42);
}
