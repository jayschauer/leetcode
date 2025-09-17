#include <bits/stdc++.h>
using namespace std;

/**
 * 36. Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/
 */
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int rows[9] = {0};
    int cols[9] = {0};
    int subs[9] = {0};  // subsquares
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        char c = board[row][col];
        if (c == '.') continue;

        int sub = (row / 3) * 3 + (col / 3);
        int pos = 1 << (c - '0');

        if ((rows[row] & pos) || (cols[col] & pos) || (subs[sub] & pos)) {
          return false;
        }

        rows[row] |= pos;
        cols[col] |= pos;
        subs[sub] |= pos;
      }
    }
    return true;
  }
};
