#include <bits/stdc++.h>
using namespace std;

/**
 * 242. Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/
 */
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }

    int counts[26] = {0};

    for (size_t i = 0; i < s.length(); i++) {
      counts[s[i] - 'a']++;
      counts[t[i] - 'a']--;
    }

    for (int val : counts) {
      if (val != 0) {
        return false;
      }
    }
    return true;
  }
};
