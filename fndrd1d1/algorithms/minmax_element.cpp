#include <algorithm>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

namespace alg {
// idea: go through container two elements at a time
template <typename I, typename Compare>
// requires I is a ForwardIterator
// Compare is StrictWeakOrdering on ValueType(I)
std::pair<I, I> minmax_element(I first, I last, Compare cmp) {
  if (first == last)
    return std::make_pair(last, last);
  I min = first;
  I max = first;
  ++first;

  while (first != last && std::next(first) != last) {
    I potentialMin = first;
    I potentialMax = std::next(first);

    if (cmp(*potentialMax, *potentialMin)) {
      std::swap(potentialMax, potentialMin);
    }
    if (cmp(*potentialMin, *min)) {
      min = potentialMin;
    }
    if (!cmp(*potentialMax, *max)) {
      max = potentialMax;
    }
    std::advance(first, 2);
  }

  // odd amount of elements
  if (first != last) {
    if (cmp(*first, *min)) {
      min = first;
    }
    if (!cmp(*first, *max)) {
      max = first;
    }
  }

  return std::make_pair(min, max);
}
}  // namespace alg

TEST(MinMaxElement, compare_to_std) {
  std::vector<int> v{1, 2, 3, 4, 3};
  auto [min, max] = alg::minmax_element(begin(v), end(v), std::less());
  auto [min2, max2] = std::minmax_element(begin(v), end(v), std::less());

  EXPECT_EQ(*min, *min2);
  EXPECT_EQ(*max, *max2);
}
