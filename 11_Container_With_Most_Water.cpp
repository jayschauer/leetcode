#include <bits/stdc++.h>
using namespace std;

/**
 * 11. Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/
 */

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int maxArea = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i < j) {
      int width = j - i;
      int area = width * min(height[i], height[j]);
      if (area > maxArea) maxArea = area;

      if (height[i] < height[j]) {
        i++;
      } else {
        j--;
      }
    }
    return maxArea;
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
