#include <bits/stdc++.h>
using namespace std;

/**
 * 3. Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters
 */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    array<int, 128> chars;
    chars.fill(-1);

    int longest = 0;
    int length = 0;
    for (int i = 0; i < s.length(); i++) {
      char c = s[i];
      int loc = chars[c];
      int start = i - length;
      if (loc >= start) {
        // Repeat character.
        // Update longest and reset.
        if (length > longest) {
          longest = length;
        }
        // Now need to reset to next spot not including our repeat character.
        start = loc + 1;
        length = i - start + 1;  // reset length to be from new start to i
      } else {
        length++;
      }
      chars[c] = i;
    }

    if (length > longest) {
      longest = length;
    }

    return longest;
  }
};

int main() {
  Solution sol;

  cout << sol.lengthOfLongestSubstring("") << endl;  // 0

  cout << sol.lengthOfLongestSubstring(" ") << endl;  // 1

  cout << sol.lengthOfLongestSubstring("zxyzxyz") << endl;  // 3

  cout << sol.lengthOfLongestSubstring("xxxx") << endl;  // 1

  cout << sol.lengthOfLongestSubstring("12345") << endl;  // 5

  cout << sol.lengthOfLongestSubstring("aab") << endl;  // 2

  return 0;
}
