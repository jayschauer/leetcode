#include <bits/stdc++.h>
using namespace std;

/**
 * 271. Encode and Decode Strings
 *
 * https://leetcode.com/problems/encode-and-decode-strings/
 */
class Solution {
 public:
  string encode(vector<string>& strs) {
    string output;
    for (const auto& str : strs) {
      output += to_string(str.length());
      output += '#';
      output += str;
    }
    return output;
  }

  vector<string> decode(string s) {
    vector<string> output;

    int i = 0;
    while (i < s.length()) {
      // First find the length string before the actual string
      int j = s.find('#', i);
      int length = stoi(s.substr(i, j - i));

      // now extract the string we care about
      output.push_back(s.substr(j + 1, length));
      i = j + 1 + length;
    }

    return output;
  }
};
