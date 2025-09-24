#include <bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    // want to find lower bound for bad versions
    int L = 0;
    int R = n;
    while (L < R) {
      int mid = L + (R - L) / 2;
      if (isBadVersion(mid)) {
        R = mid;
      } else {
        L = mid + 1;
      }
    }
    return L;
  }
};