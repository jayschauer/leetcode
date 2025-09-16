#include <bits/stdc++.h>
using namespace std;

/**
 * 15. 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 */
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    // todo
    return {};
  }
};

void printSolution(const vector<vector<int>>& vec) {
  cout << "[ ";
  for (const auto& v : vec) {
    cout << "[";
    for (const int num : v) {
      cout << num << " ";
    }
    cout << "] ";
  }
  cout << "]" << endl;
}

int main() {
  Solution sol;

  vector<int> nums{-1, 0, 1, 2, -1, -4};
  printSolution(sol.threeSum(nums));
  // [[-1,-1,2],[-1,0,1]]

  nums = {0, 1, 1};
  printSolution(sol.threeSum(nums));
  // []

  nums = {0, 0, 0};
  printSolution(sol.threeSum(nums));
  // [[0,0,0]]

  return 0;
}
