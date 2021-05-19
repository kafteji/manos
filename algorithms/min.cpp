#include <algorithm>
#include <iostream>
#include <gtest/gtest.h>

namespace alg
{
    template <typename T, typename Compare = std::less<T>>
    const T &min(const T &a, const T &b, Compare cmp = std::less<T>())
    {
        return (cmp(b, a)) ? b : a;
    }
}

TEST(min, compare_to_std_temp)
{
    auto std_min = std::min(1, 2);
    auto alg_min = alg::min(1, 2);

    EXPECT_EQ(std_min, alg_min);
}

TEST(min, compare_to_std_custom_with_stability)
{
    struct custom
    {
        int first;
        int second;
    };

    custom a{1, 1};
    custom b{1, 2};

    auto cmp = [](const auto &a, const auto &b)
    { return a.first < b.first; };

    auto std_min = std::min(a, b, cmp);
    auto alg_min = alg::min(a, b, cmp);

    EXPECT_EQ(std_min.first, alg_min.first);
    EXPECT_EQ(std_min.second, alg_min.second);
}