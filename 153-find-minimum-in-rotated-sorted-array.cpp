#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
 public:
  int findMin(const vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] < nums[r]) {
        // this section is sorted, so min is in [l, m]
        r = m;
      } else {
        // other section isn't sorted, so min must be in there.
        l = m + 1;
      }
    }
    return nums[l];
  }
};

int main() {
  Solution sol;

  cout << sol.findMin({3, 4, 5, 1, 2}) << endl;

  return 0;
}
