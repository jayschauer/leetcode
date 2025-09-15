#include <bits/stdc++.h>
using namespace std;

/**
 * 1935. Maximum Number of Words You Can Type

 * https://leetcode.com/problems/maximum-number-of-words-you-can-type/
 */
class Solution {
 public:
  int canBeTypedWords(string text, string brokenLetters) {
    if (brokenLetters.size() == 0) {
      return count(text.begin(), text.end(), ' ') + 1;
    }

    vector<bool> is_broken_letter(26, false);
    for (char c : brokenLetters) {
      is_broken_letter[c - 'a'] = true;
    }

    int count = 0;
    bool canType = true;

    for (char c : text) {
      // We've finished a word - increment count if we can type it
      if (c == ' ') {
        // Note: this check is safe because there's no leading spaces
        if (canType) {
          count++;
        }
        canType = true;
        continue;
      }

      // We've already found we can't type this word - skip to the next one
      if (!canType) {
        continue;
      }

      if (is_broken_letter[c - 'a']) {
        canType = false;
      }
    }

    if (canType) {
      // Note: no trailing spaces, so if we get to here then we've finished
      // checking the list with a word we can type
      count++;
    }

    return count;
  }
};

int main() {
  Solution sol;

  string text = "hello world", brokenLetters = "ad";
  cout << sol.canBeTypedWords(text, brokenLetters) << endl;  // 1

  text = "leet code", brokenLetters = "lt";
  cout << sol.canBeTypedWords(text, brokenLetters) << endl;  // 1

  text = "leet code", brokenLetters = "e";
  cout << sol.canBeTypedWords(text, brokenLetters) << endl;  // 0

  return 0;
}
