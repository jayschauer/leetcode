#include <bits/stdc++.h>
using namespace std;

/**
 * 1733. Minimum Number of People to Teach
 *
 * https://leetcode.com/problems/minimum-number-of-people-to-teach/description/
 */
class Solution {
 public:
  int minimumTeachings(int n, vector<vector<int>>& languages,
                       vector<vector<int>>& friendships) {
    return 0;
  }
};

int main() {
  Solution sol;

  int language_count = 2;
  vector<vector<int>> languages = {{1}, {2}, {1, 2}};
  vector<vector<int>> friendships = {{1, 2}, {1, 3}, {2, 3}};
  cout << sol.minimumTeachings(language_count, languages, friendships) << endl;

  language_count = 3;
  languages = {{2}, {1, 3}, {1, 2}, {3}};
  friendships = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
  cout << sol.minimumTeachings(language_count, languages, friendships) << endl;

  return 0;
}
