#include <bits/stdc++.h>
using namespace std;

/**
 * 875. Koko Eating Bananas
 *
 * https://leetcode.com/problems/koko-eating-bananas/
 */
class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    // Order of the piles does not matter.

    // Maximum rate would be equal to the largest element.
    // Minimum rate would be 1 banana per hour.

    // Brute force solution: check every rate, starting with 1, until totalTime
    // takes less than h.

    // Binary search solution: check the middle rate, and see if totalTime is less
    // than or equal to h. If it is, then we can try a smaller rate. If it isn't,
    // then we need to try a larger rate.

    int max = *max_element(piles.begin(), piles.end());
    int L = 1;
    int R = max;

    while (L <= R) {
      int rate = L + (R - L) / 2;
      long long time = eatBananas(piles, rate);
      if (time <= h) {
        R = rate - 1;
      } else {
        L = rate + 1;
      }
    }

    return L;
  }

 private:
  // Eat all the bananas, returning how long it takes
  long long eatBananas(const vector<int>& piles, int rate) {
    long long totalTime = 0;
    for (int p : piles) {
      totalTime += (p + rate - 1) / rate;
    }
    return totalTime;
  }
};
