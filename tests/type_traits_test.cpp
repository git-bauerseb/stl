#include <gtest/gtest.h>
#include <type_traits>
#include "../inc/type_traits.h"

TEST(RemoveReferenceTest, Removing) {

    bool cond0 = std::is_same<ostd::remove_reference<int>::type,int>::value;
    EXPECT_TRUE(cond0);

    bool cond1 = std::is_same<ostd::remove_reference<int&>::type,int>::value;
    EXPECT_TRUE(cond1);

    bool cond2 = std::is_same<ostd::remove_reference<int&&>::type,int>::value;
    EXPECT_TRUE(cond2);

    bool cond3 = std::is_reference<ostd::remove_reference<int&&>>::value;
    EXPECT_FALSE(cond3);
}
