#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSubArray(const vector<int>& nums) {
    // Kadane's algorithm
    int maxSum = nums[0];
    int currentSum = 0;

    for (int i : nums) {
      currentSum += i;
      maxSum = max(maxSum, currentSum);
      if (currentSum < 0) currentSum = 0;
    }

    return maxSum;
  }
};

int main() {
  Solution sol;

  cout << sol.maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;  // 6
  cout << sol.maxSubArray({1}) << endl;                              // 1
  cout << sol.maxSubArray({5, 4, -1, 7, 8}) << endl;                 // 23
  cout << sol.maxSubArray({2, -3, 4, -2, 2, 1, -1, 4}) << endl;      // 8
  cout << sol.maxSubArray({-1}) << endl;                             // -1
  cout << sol.maxSubArray({-2, -1}) << endl;                         // -1
  cout << sol.maxSubArray({-1, -2}) << endl;                         // -1

  return 0;
}
