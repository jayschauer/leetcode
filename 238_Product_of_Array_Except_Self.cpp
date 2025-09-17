#include <bits/stdc++.h>
using namespace std;

/**
 * 238. Product of Array Except Self
 * 
 * https://leetcode.com/problems/product-of-array-except-self/description/
 */
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    size_t length = nums.size();
    vector<int> prefixes(length);
    vector<int> suffixes(length);

    // build list of products up to a certain index - the "prefixes" of our
    // product
    prefixes[0] = nums[0];
    for (int i = 1; i < length - 1; i++) {
      prefixes[i] = nums[i] * prefixes[i - 1];
    }

    // build list of products after a certain index - the "suffixes" of our
    // product
    suffixes[length - 1] = nums[length - 1];
    for (int i = length - 2; i > 0; i--) {
      suffixes[i] = nums[i] * suffixes[i + 1];
    }

    // now combine the prefixes and the suffixes to get the final product
    vector<int> result(length);
    // we know nums.length >= 2
    result[0] = suffixes[1];
    result[length - 1] = prefixes[length - 2];
    for (int i = 1; i < length - 1; i++) {
      result[i] = prefixes[i - 1] * suffixes[i + 1];
    }

    return result;
  }
};
