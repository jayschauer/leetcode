#include <bits/stdc++.h>
using namespace std;

/**
 * 49. Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/
 */
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;
    for (const auto& s : strs) {
      int count[26] = {0};
      for (char c : s) {
        count[c - 'a']++;
      }
      string key;
      for (int i = 0; i < 26; ++i) {
        key += to_string(count[i]) + ';';
      }
      anagramGroups[key].push_back(s);
    }

    vector<vector<string>> result;
    for (const auto& pair : anagramGroups) {
      result.push_back(pair.second);
    }

    return result;
  }
};
