#include <bits/stdc++.h>
using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

/**
 * 374. Guess Number Higher or Lower
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower/
 */
class Solution {
 public:
  int guessNumber(int n) {
    int L = 1;
    int R = n;
    while (L <= R) {
      int num = L + (R - L) / 2;
      int answer = guess(num);
      if (answer == -1) {
        R = num - 1;
      } else if (answer == 1) {
        L = num + 1;
      } else {
        return num;
      }
    }

    // shouldn't hit this
    return -1;
  }
};