#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
 public:
  int search(const vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) {
        return mid;
      }

      if (nums[mid] < target) {
        // Target is to the "right".
        // Need to decide if we search left of mid or right of mid.
        // So need to figure out which section will have target.
        if (nums[l] <= nums[mid] || nums[l] > target) {
          // If nums[l] <= nums[mid] then [l,mid] section is increasing,
          // and target > mid, so it must be to the right.
          // Target will also be to the right when the left edge is more than
          // target.
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      } else {
        // target is to the "left"
        if (nums[mid] <= nums[r] || nums[r] < target) {
          // If nums[mid] <= nums[r] then [mid,r] section is increasing,
          // and target < mid, so it must be to the left.
          // Also target will be to the left when the right edge is less than
          // target.
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;

  cout << sol.search({4, 5, 6, 7, 0, 1, 2}, 0) << endl;

  return 0;
}
