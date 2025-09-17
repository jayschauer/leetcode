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
      greater_left[i] = max(height[i - 1], greater_left[i - 1]);
    }

    greater_right[height.size() - 1] = 0;
    for (int i = height.size() - 2; i >= 0; i--) {
      greater_right[i] = max(height[i + 1], greater_right[i + 1]);
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

  int trapStack(vector<int>& height) {
    // The stack keeps track of indices of bars that form potential "walls" of
    // containers. We iterate over the heights, and when we find a new bar that
    // is taller than the bar at the stack’s top, we have potentially found a
    // right wall that can trap water with a left wall from earlier in the
    // stack.

    if (height.empty()) {
      return 0;
    }

    stack<int> stk;
    int res = 0;

    for (int i = 0; i < height.size(); i++) {
      while (!stk.empty() && height[i] >= height[stk.top()]) {
        int mid = height[stk.top()];
        stk.pop();
        if (!stk.empty()) {
          int right = height[i];
          int left = height[stk.top()];
          int h = min(right, left) - mid;
          int w = i - stk.top() - 1;
          res += h * w;
        }
      }
      stk.push(i);
    }

    return res;
  }

  int trapTwoPointers(vector<int>& height) {
    if (height.empty()) {
      return 0;
    }

    int l = 0, r = height.size() - 1;
    int leftMax = height[l], rightMax = height[r];
    int res = 0;
    while (l < r) {
      if (leftMax < rightMax) {
        l++;
        leftMax = max(leftMax, height[l]);
        res += leftMax - height[l];
      } else {
        r--;
        rightMax = max(rightMax, height[r]);
        res += rightMax - height[r];
      }
    }
    return res;
  }
};

#include <bits/stdc++.h>
using namespace std;

int main() {
  Solution sol;

  vector<int> height = {0, 2, 0, 3, 1, 0, 1, 3, 2, 1};
  cout << sol.trapTwoPointers(height) << endl;

  return 0;
}
