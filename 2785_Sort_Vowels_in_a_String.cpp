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
    vector<bool> isVowel(58, false);
    vector<int> freq(58, 0);

    // create fast vowel check
    string vowels = "AEIOUaeiou";
    for (char v : vowels) {
      isVowel[v - 'A'] = true;
    }

    // count the vowels
    for (char c : s) {
      if (isVowel[c-'A']) {
        freq[c - 'A']++;
      }
    }

    auto vowel = vowels.begin();

    // Rearrange the vowels:
    for (size_t i = 0; i < s.size(); i++) {
      // Get the next vowel to update:
      while (vowel != vowels.end() && freq[*vowel - 'A'] == 0) {
        vowel++;
      }
      if (vowel == vowels.end()) {
        break;  // done updating vowels
      }

      char c = s[i];
      if (!isVowel[c - 'A']) {
        continue;
      }

      if (c != *vowel) {
        s[i] = *vowel; 
      }

      freq[*vowel-'A']--;
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
