#include <bits/stdc++.h>
using namespace std;

/**
 * 918. Maximum Sum Circular Subarray
 *
 * https://leetcode.com/problems/maximum-sum-circular-subarray/
 */
class Solution {
 public:
  int maxSubarraySumCircular(const vector<int>& nums) {
    int maxSum = nums[0];
    int minSum = nums[0];
    int currentMax = 0;
    int currentMin = 0;
    int total = 0;

    for (int i : nums) {
      total += i;
      currentMax = max(currentMax + i, i);
      currentMin = min(currentMin + i, i);
      maxSum = max(maxSum, currentMax);
      minSum = min(minSum, currentMin);
    }

    // Because our algorithm says the minimum is:
    // (1) The non-circular maxSum,
    // (2) Or all the elements not included in our minSum, wrapping
    // circularly. We need to handle the edge case of (2) where all the
    // elements are included in minSum, We can check for this by seeing if
    // minSum is the same as total.
    if (minSum == total) {
      return maxSum;
    } else {
      return max(total - minSum, maxSum);
    }
  }
};

int main() {
  Solution sol;

  cout << sol.maxSubarraySumCircular({1, -2, 3, -2}) << endl;

  return 0;
}
