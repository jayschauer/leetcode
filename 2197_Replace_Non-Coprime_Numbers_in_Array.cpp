#include <bits/stdc++.h>
using namespace std;

/**
 * 2197. Replace Non-Coprime Numbers in Array
 *
 * https://leetcode.com/problems/replace-non-coprime-numbers-in-array/
 */
class Solution {
 public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    // todo
    return {};
  }
};

void printVector(const vector<int>& vec) {
  for (const int num : vec) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;

  vector<int> nums{6, 4, 3, 2, 7, 6, 2};
  vector<int> result = sol.replaceNonCoprimes(nums);
  printVector(result);  // [12,7,6]

  nums = {2, 2, 1, 1, 3, 3, 3};
  result = sol.replaceNonCoprimes(nums);
  printVector(result);  // [2,1,1,3]

  return 0;
}
