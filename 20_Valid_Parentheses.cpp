#include <bits/stdc++.h>
using namespace std;

/**
 * 20. Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/
 */
class Solution {
 public:
  bool isValid(string s) {
    stack<char> openBrackets;

    for (const char c : s) {
      // if it's an open bracket, add it to our stack
      // otherwise it should have a matching closing bracket
      if (isOpenBracket(c)) {
        openBrackets.push(c);
      } else if (openBrackets.empty() ||
                 openBrackets.top() != getOpeningBracket(c)) {
        return false;
      } else {
        openBrackets.pop();
      }
    }

    return openBrackets.empty();
  }

 private:
  bool isOpenBracket(char c) { return (c == '(') || (c == '{') || (c == '['); }

  char getOpeningBracket(char c) {
    switch (c) {
      case ')':
        return '(';
      case '}':
        return '{';
      case ']':
        return '[';
    }
    return '\0';  // should never reach here
  }
};

int main() {
  Solution sol;

  cout << sol.isValid("([{}])") << endl;

  cout << sol.isValid("[(])") << endl;

  return 0;
}
