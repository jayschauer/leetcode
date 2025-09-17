#include <bits/stdc++.h>
using namespace std;

/**
 * 128. Longest Consecutive Sequence
 * 
 * https://leetcode.com/problems/longest-consecutive-sequence/
 */
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> mp;
    int res = 0;

    for (int num : nums) {
      if (!mp[num]) {
        mp[num] = mp[num - 1] + mp[num + 1] + 1;
        mp[num - mp[num - 1]] = mp[num];
        mp[num + mp[num + 1]] = mp[num];
        res = max(res, mp[num]);
      }
    }
    return res;
  }
};
