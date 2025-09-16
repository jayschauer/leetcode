#include <bits/stdc++.h>
using namespace std;

/**
 * 11. Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 */

class Solution {
 public:
  int maxArea(vector<int>& height) {
    // todo
    return 0;
  }
};

int main() {
  Solution sol;

  vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << sol.maxArea(height) << endl;  // 49

  height = {1, 1};
  cout << sol.maxArea(height) << endl;  // 1

  height = {1, 7, 2, 5, 4, 7, 3, 6};
  cout << sol.maxArea(height) << endl;  // 36

  height = {2, 2, 2};
  cout << sol.maxArea(height) << endl;  // 4

  return 0;
}
