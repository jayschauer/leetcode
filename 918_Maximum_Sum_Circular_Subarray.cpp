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

  int maxSubarraySumCircularSuffix(const vector<int>& nums) {
    // find rightMax - the largest suffix sum from any position
    vector<int> rightMax(nums.size());
    int suffixSum = nums[nums.size() - 1];
    rightMax[nums.size() - 1] = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i > 0; i--) {
      suffixSum += nums[i];
      rightMax[i] = max(rightMax[i + 1], suffixSum);
    }

    // Now use kadane's to find the largest non-circular subarray,
    // while also keeping a prefix sum and checking if prefix + suffix is
    // larger.
    int prefixSum = 0;
    int currentSum = 0;
    int maxSum = nums[0];
    for (int i = 0; i < nums.size(); i++) {
      // Either keep currentSum going or startover with nums[i]
      currentSum = max(currentSum, 0) + nums[i];
      maxSum = max(maxSum, currentSum);
      prefixSum += nums[i];
      if (i + 1 < nums.size()) {
        // why i+1? don't want to include the current element in the suffix sum
        // since it's already included in the prefix
        maxSum = max(maxSum, prefixSum + rightMax[i + 1]);
      }
    }

    return maxSum;
  }
};

int main() {
  Solution sol;

  cout << sol.maxSubarraySumCircular({1, -2, 3, -2}) << endl;

  return 0;
}
