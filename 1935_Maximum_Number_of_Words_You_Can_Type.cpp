#include <bits/stdc++.h>
using namespace std;

/**
 * 1935. Maximum Number of Words You Can Type

 * https://leetcode.com/problems/maximum-number-of-words-you-can-type/
 */
class Solution {
 public:
  int canBeTypedWords(string text, string brokenLetters) { return 0; }
};

int main() {
  Solution sol;

  string text = "hello world", brokenLetters = "ad";
  cout << sol.canBeTypedWords(text, brokenLetters) << endl;

  text = "leet code", brokenLetters = "lt";
  cout << sol.canBeTypedWords(text, brokenLetters) << endl;

  text = "leet code", brokenLetters = "e";
  cout << sol.canBeTypedWords(text, brokenLetters) << endl;

  return 0;
}
