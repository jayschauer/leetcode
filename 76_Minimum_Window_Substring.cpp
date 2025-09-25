#include <bits/stdc++.h>
using namespace std;

/**
 * 76. Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/
 */
class Solution {
 public:
  string minWindow(string s, string t) {
    array<int, 128> freq{};
    int need = t.size();
    for (char c : t) {
      freq[c]++;
    }
    // For every c where freq[c] > 0, we still need those characters from s in
    // our substring. The sum of those frequencies will equal need.

    int l = 0;
    int r = 0;
    int resStart = 0;
    int resLength = s.size() + 1;

    while (r < s.size()) {
      char c = s[r];
      if (freq[c] > 0) {
        need--;  // this was a character we needed
      }
      freq[c]--;
      r++;

      while (need == 0) {
        // We have a valid substring.
        if (r - l < resLength) {
          resStart = l;
          resLength = r - l;
        }

        // Try making substring smaller.
        int oldChar = s[l];
        if (freq[oldChar] == 0) {
          // After removing oldChar, we need more of it.
          need++;
        }
        freq[oldChar]++;
        l++;
      }
    }

    if (resLength == s.size() + 1) {
      return "";
    } else {
      return s.substr(resStart, resLength);
    }
  }
};
