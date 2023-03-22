#include <gtest/gtest.h>
#include <vector>
#include "../inc/vector.h"

class VectorTest : public ::testing::Test {

    protected:
        void SetUp() override {
            m_v1.push_back(1);
            m_v1.push_back(2);
            m_v1.push_back(3);

            m_cv1.push_back(1);
            m_cv1.push_back(2);
            m_cv1.push_back(3);
        }

        ostd::vector<int> m_v1;
        std::vector<int> m_cv1;
};

TEST_F(VectorTest, iterators) {
    int idx = 0;
    for (auto& el : m_v1) {
        EXPECT_EQ(el, m_cv1[idx]);
        idx++;
    }
}
