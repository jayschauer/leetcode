#include <bits/stdc++.h>
using namespace std;

/**
 * 42. Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/
 */
class Solution {
 public:
  int trap(vector<int>& height) {
    // Algorithm idea:
    // Keep an array of 'tallest' to the outside
    // Then use two pointers, moving inwards
    // When we encounter something taller, we add water to previous total area

    // Amount of water in a given position i:
    // min(height[l], height[r]) - height[i]
    // Where l is the highest element left of i, and r is the highest element
    // right of i.

    // We can build arrays that track this information in two passes.
    // Then we can do a third pass and tally up the water.
    // We can eliminate one of those passes but wouldn't change big O of the
    // algorithm.

    vector<int> greater_left(height.size(), 0);
    vector<int> greater_right(height.size(), 0);

    greater_left[0] = 0;
    for (int i = 1; i < height.size(); i++) {
      if (height[i - 1] > greater_left[i - 1]) {
        greater_left[i] = height[i - 1];
      } else {
        greater_left[i] = greater_left[i - 1];
      }
    }

    greater_right[height.size() - 1] = 0;
    for (int i = height.size() - 2; i >= 0; i--) {
      if (height[i + 1] > greater_right[i + 1]) {
        greater_right[i] = height[i + 1];
      } else {
        greater_right[i] = greater_right[i + 1];
      }
    }

    int area = 0;

    for (int i = 0; i < height.size(); i++) {
      int water = min(greater_left[i], greater_right[i]) - height[i];
      if (water > 0) {
        area += water;
      }
    }
    return area;
  }
};
