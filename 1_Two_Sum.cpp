#include <bits/stdc++.h>
using namespace std;

#include <ranges>

/**
 * 1. Two Sum
 *
 * https://leetcode.com/problems/two-sum/
 */
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> prevMap;

    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];
      auto diffIter = prevMap.find(diff);
      if (diffIter != prevMap.end()) {
        return {diffIter->second, i};
      }
      prevMap[nums[i]] = i;
    }

    return {};
  }
};
