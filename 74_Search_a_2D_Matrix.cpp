#include <bits/stdc++.h>
using namespace std;

/**
 * 74. Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/
 */
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // 1) Find upper bound row.
    // Why upper bound? Then we know it should be in the previous row.
    // 2) Then within that row, apply regular binary search.

    // 1) Upper bound (first row bigger than target)
    int L = 0;
    int R = matrix.size();
    while (L < R) {
      int mid = L + ((R - L) / 2);
      if (matrix[mid][0] > target) {
        R = mid;
      } else {
        L = mid + 1;
      }
    }

    // we've failed if L=0 after this -> means even our first row is bigger
    // than target
    if (L == 0) {
      return false;
    }

    // 2) Now search within the target row
    int row = L - 1;
    L = 0;
    R = matrix[row].size() - 1;
    while (L <= R) {
      int mid = L + ((R - L) / 2);
      if (matrix[row][mid] > target) {
        R = mid - 1;
      } else if (matrix[row][mid] < target) {
        L = mid + 1;
      } else {
        return true;
      }
    }

    return false;
  }
};
