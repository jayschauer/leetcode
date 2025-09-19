#include <bits/stdc++.h>
using namespace std;

/**
 * 219. Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/
 */
class Solution {
 public:
  bool containsNearbyDuplicate(const vector<int>& nums, int k) {
    unordered_set<int> window;
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      // update window
      if (r - l > k) {
        window.erase(nums[l]);
        l++;
      }

      if (window.contains(nums[r])) {
        return true;
      }

      window.insert(nums[r]);
    }

    return false;
  }
};

int main() {
  Solution sol;

  cout << sol.containsNearbyDuplicate({1, 2, 3, 1}, 3) << endl;

  return 0;
}
