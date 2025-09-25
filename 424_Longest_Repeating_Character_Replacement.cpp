#include <bits/stdc++.h>
using namespace std;

/**
 * 424. Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/
 */
class Solution {
 public:
  int characterReplacement(std::string s, int k) {
    // Frequency map for characters in the current window
    array<int, 26> count{};
    int l = 0, r = 0;
    int maxf = 0;  // max frequency over any window

    for (; r < s.size(); r++) {
      // Move window to the right by including s[r]
      count[s[r] - 'A']++;
      maxf = max(maxf, count[s[r] - 'A']);

      // Check if replacements needed exceed k:
      // window size - most frequent char count = number of chars to
      // replace.
      // If so, then we can't expand the window and have to shrink from
      // the left. We can only expand the window when maxf increases.
      while ((r - l + 1) - maxf > k) {
        // Shrink from left by removing s[l]
        count[s[l] - 'A']--;
        l++;
      }
    }

    return r - l;
  }
};
