#include <bits/stdc++.h>
using namespace std;

/**
 * 1929. Concatenation of Array
 *
 * https://leetcode.com/problems/concatenation-of-array/
 */
class Solution {
 public:
  vector<int> getConcatenation(vector<int>& nums) {
    vector<int> result;
    result.reserve(nums.size() * 2);
    result.insert(result.begin(), nums.begin(), nums.end());
    result.insert(result.begin(), nums.begin(), nums.end());
    return result;
  }
};
