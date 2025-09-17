#include <bits/stdc++.h>
using namespace std;

/**
 * 27. Remove Element
 *
 * https://leetcode.com/problems/remove-element/
 */
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int l = 0;
    int r = nums.size();

    while (l < r) {
      if (nums[l] == val) {
        // swap with the last unchecked element.
        // shrink array boundary
        nums[l] = nums[--r];
      } else {
        l++;
      }
    }
    return r;
  }
};
