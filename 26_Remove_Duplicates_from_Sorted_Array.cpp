#include <bits/stdc++.h>
using namespace std;

/**
 * 26. Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array
 */
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 1) {
      return 1;
    }
    int write_index = 1;  // where we will write the next unique element
    int unique_count = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[write_index - 1]) {
        nums[write_index] = nums[i];
        write_index++;
        unique_count++;
      }
    }
    return unique_count;
  }
};
