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
    // Algorithm:
    // Make sliding window big enough until we have a substring that works
    // Once we do, shrink from left until it doesn't.
    // Now move substring until it works again. At that point, shrink from
    // left until it doesn't.

    // How to efficiently check if our substring "works":
    // Make a frequency map of letters in t.
    // Make a frequency map of letters in our sliding window that match our
    // "target" letters. Add / remove letters from from the map as the
    // sliding window changes. Track when we have "enough" of each letter in
    // our substring to make target.

    if (s.size() < t.size() || t.empty()) {
      return "";
    }

    unordered_map<char, int> target;
    unordered_map<char, int> freq;
    for (char c : t) {
      target[c]++;
    }

    int have = 0;
    int need = target.size();
    int resL = 0;
    int resLength = s.size() + 1;

    int l = 0;
    for (int r = 0; r < s.size(); r++) {
      char c = s[r];
      if (target.count(c)) {
        freq[c]++;
        if (freq[c] == target[c]) {
          have++;  // we have enough of this character
        }
      }

      while (have == need) {
        // we have enough of every character in target
        if ((r - l + 1) < resLength) {
          resLength = r - l + 1;
          resL = l;
        }

        char oldChar = s[l];
        if (target.count(oldChar)) {
          freq[oldChar]--;
          // Okay for this check to just be <, since we will break out
          // of the loop the first time it gets hit.
          if (freq[oldChar] < target[oldChar]) {
            have--;
          }
        }
        l++;
      }
    }

    if (resLength == s.size() + 1) {
      return "";
    } else {
      return s.substr(resL, resLength);
    }
  }
};
