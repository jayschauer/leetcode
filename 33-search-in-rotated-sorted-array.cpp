#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
 public:
  int search(const vector<int>& nums, int target) {
    // Two binary searches: one to find the rotation point.
    // Then depending on the first value, search either before/after
    // rotation.
    int pivot = findPivot(nums);
    int l, r;

    if (pivot == 0) {
      l = 0;
      r = nums.size() - 1;
    } else if (nums[0] <= target) {
      // target is in range [0, pivot)
      l = 0;
      r = pivot - 1;
    } else {
      // target is in range [pivot, n)
      l = pivot;
      r = nums.size() - 1;
    }

    return binarySearch(l, r, nums, target);
  }

  int findPivot(const vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    if (!isBeforeRotation(l, r, nums)) {
      return l;
    }
    while (r - l > 1) {
      int m = l + (r - l) / 2;
      if (isBeforeRotation(m, r, nums)) {
        // splitting at m gives us a point before the rotation
        l = m;
      } else {
        // other section isn't sorted, so min must be in there.
        r = m;
      }
    }
    return r;
  }

 private:
  int binarySearch(int l, int r, const vector<int>& nums, int target) {
    // preconditions:
    // 1) nums[l] is < target
    // 2) nums[r] is >= target
    if (nums[l] >= target || nums[r] < target) {
      if (nums[l] == target) {
        return l;
      }
      // target can't be in the range
      return -1;
    }
    while (r - l > 1) {
      int mid = l + (r - l) / 2;
      if (nums[mid] < target) {
        l = mid;
      } else {
        r = mid;
      }
    }

    // so now we have nums[l] < target and nums[r] >= target
    if (nums[r] == target) {
      return r;
    }
    return -1;
  }

  // check if this section is before the rotation
  bool isBeforeRotation(int l, int r, const vector<int>& nums) {
    return nums[l] >= nums[r];
  }
};

int main() {
  Solution sol;

  cout << sol.search({4, 5, 6, 7, 0, 1, 2}, 0) << endl;

  return 0;
}
