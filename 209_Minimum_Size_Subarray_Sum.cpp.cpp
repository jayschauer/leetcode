#include <bits/stdc++.h>
using namespace std;

/**
 * 209. Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/
 */
class Solution {
 public:
  int minSubArrayLen(int target, const vector<int>& nums) {
    // Algorithm:
    // expand subarray to the right until sum >= target
    // at which point shrink subarray from left until sum < target
    // keep track of minimum subarray length we can get with sum >= target
    // subarray will be [L,R]

    // Intuition why this works:
    // nums are all positive, so growing the subarray can only make the sum
    // larger So once we have sum >= target, we can start over with a new
    // subarray at the next element. However, we don't need to repeat our
    // work of summing the elements, we can just subtract the element that
    // is now excluded from the subarray.

    int length = nums.size() + 1;
    int L = 0;
    int sum = 0;

    for (int R = 0; R < nums.size(); R++) {
      sum += nums[R];
      while (sum >= target && L <= R) {
        length = min(length, R - L + 1);
        sum -= nums[L];
        L++;
      }
    }

    if (length == nums.size() + 1) {
      return 0;
    } else {
      return length;
    }
  }
};

int main() {
  Solution sol;

  cout << sol.minSubArrayLen(7, {2, 3, 1, 2, 4, 3}) << endl;  // 2

  return 0;
}
