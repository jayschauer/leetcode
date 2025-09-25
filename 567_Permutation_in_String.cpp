#include <bits/stdc++.h>
using namespace std;

/**
 * 567. Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/
 */
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    // Initial thoughts:
    // Brute force solution:
    // Check if each character in s2 is the start of a permutation in s1.
    // How would we check that?
    // Build a frequency map of characters in s2, and see if it's the same
    // as the frequency map for s1. Then re-do for every character.
    // O(len(s1)*len(s2)).
    // Can we do better?
    // We can maintain the frequency map with a sliding window.
    // How can we make the comparison of the frequency maps efficient?
    // Maybe what we do is we build a map of frequencies from s1.
    // Then as we read s2 we can subtract frequencies. We delete characters
    // that have zero. If the map ever becomes empty then we know our
    // current window gives a permutation.

    if (s2.size() < s1.size()) {
      return false;
    }

    unordered_map<char, int> freq;
    for (char c : s1) {
      freq[c]++;
    }

    // Initialize window with first substring
    for (int i = 0; i < s1.size(); i++) {
      freq[s2[i]]--;
      if (freq[s2[i]] == 0) {
        freq.erase(s2[i]);
      }
    }

    if (freq.empty()) {
      return true;
    }

    for (int i = s1.size(); i < s2.size(); i++) {
      // Remove character outside window
      freq[s2[i - s1.size()]]++;
      if (freq[s2[i - s1.size()]] == 0) {
        freq.erase(s2[i - s1.size()]);
      }

      // Add new character to window,
      freq[s2[i]]--;
      if (freq[s2[i]] == 0) {
        freq.erase(s2[i]);
      }

      if (freq.empty()) {
        return true;
      }
    }

    return false;
  }
};
