#include <bits/stdc++.h>
using namespace std;

/**
 * 167. Two Sum II - Input Array Is Sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
 */

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) { return {1, 2}; }
};

int main() {
  Solution sol;

  vector<int> numbers{2, 7, 11, 15};
  int target = 9;
  vector<int> result = sol.twoSum(numbers, target);
  cout << result[0] << " " << result[1] << endl;

  numbers = {2, 3, 4};
  target = 6;
  result = sol.twoSum(numbers, target);
  cout << result[0] << " " << result[1] << endl;

  numbers = {-1, 0};
  target = -1;
  result = sol.twoSum(numbers, target);
  cout << result[0] << " " << result[1] << endl;

  return 0;
}
