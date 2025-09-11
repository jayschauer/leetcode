#include <bits/stdc++.h>
using namespace std;

/**
 * 2785. Sort Vowels in a String
 *
 * https://leetcode.com/problems/sort-vowels-in-a-string/description
 */
class Solution {
 public:
  string sortVowels(string s) {
    // Checking vector should be fast enough, no need for hashmap
    vector<pair<char, int>> vowel_count = {
        {'A', 0}, {'E', 0}, {'I', 0}, {'O', 0}, {'U', 0},
        {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};

    // Count the vowels in the string:
    for (char c : s) {
      auto it = find_if(vowel_count.begin(), vowel_count.end(),
                        [c](const pair<char, int>& p) { return p.first == c; });
      if (it != vowel_count.end()) {
        it->second++;
      }
    }

    // Remove from vowel_count vowels that aren't in the string:
    auto vowel_end =
        remove_if(vowel_count.begin(), vowel_count.end(),
                  [](const pair<char, int>& p) { return p.second == 0; });

    if (vowel_end == vowel_count.begin()) {
      return s;
    }

    auto vowel_replace = vowel_count.begin();

    // Rearrange the vowels:
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      auto it = find_if(vowel_count.begin(), vowel_end,
                        [c](const pair<char, int>& p) { return p.first == c; });

      if (it == vowel_end) {
        continue;
      }

      // if vowel is out of place, update it
      if (c != vowel_replace->first) {
        s[i] = vowel_replace->first;
      }
      vowel_replace->second--;
      if (vowel_replace->second == 0) {
        vowel_replace++;
      }

      if (vowel_replace == vowel_end) {
        break;  // done updating vowels
      }
    }

    return s;
  }
};

int main() {
  Solution sol;

  cout << sol.sortVowels("lEetcOde") << endl;
  cout << sol.sortVowels("lYmpH") << endl;

  return 0;
}
