#include <bits/stdc++.h>
using namespace std;

/**
 * 704. Binary Search
 *
 * https://leetcode.com/problems/binary-search/
 */
class Solution {
 public:
  int search(const vector<int>& nums, int target) {
    int L = 0;
    int R = nums.size() - 1;
    while (L <= R) {
      int mid = L + (R - L) / 2;
      if (nums[mid] < target) {
        L = mid + 1;
      } else if (nums[mid] > target) {
        R = mid - 1;
      } else {
        return mid;
      }
    }

    return -1;
  }
};

int main() {
  Solution sol;

  cout << sol.search({-1, 0, 2, 4, 6, 8}, 4) << endl;  // 3
  cout << sol.search({-1, 0, 2, 4, 6, 8}, 3) << endl;  // -1

  return 0;
}
