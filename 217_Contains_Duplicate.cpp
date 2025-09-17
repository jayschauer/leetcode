#include <bits/stdc++.h>
using namespace std;

/**
 * 217. Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/
 */
class Solution {
 public:
  bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> uniqueNums(nums.begin(), nums.end());
    return uniqueNums.size() < nums.size();
  }
};
