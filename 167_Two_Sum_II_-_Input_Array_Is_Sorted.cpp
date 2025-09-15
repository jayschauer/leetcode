#include <bits/stdc++.h>
using namespace std;

/**
 * 167. Two Sum II - Input Array Is Sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
 */

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    if (numbers.size() == 2) {
      return {1, 2};
    }

    int a = 0;
    int b = numbers.size() - 1;

    while ((numbers[a] + numbers[b]) != target) {
      if ((numbers[a] + numbers[b]) > target) {
        b--;
      } else {
        a++;
      }
    }

    return {a + 1, b + 1};
  }
};

int main() {
  Solution sol;

  vector<int> numbers{2, 7, 11, 15};
  int target = 9;
  vector<int> result = sol.twoSum(numbers, target);
  cout << result[0] << " " << result[1] << endl;  // 1, 2

  numbers = {2, 3, 4};
  target = 6;
  result = sol.twoSum(numbers, target);
  cout << result[0] << " " << result[1] << endl;  // 1, 3

  numbers = {-1, 0};
  target = -1;
  result = sol.twoSum(numbers, target);
  cout << result[0] << " " << result[1] << endl;  // 1, 2

  return 0;
}
