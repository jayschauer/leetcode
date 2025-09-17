#include <bits/stdc++.h>
using namespace std;

/**
 * 1733. Minimum Number of People to Teach
 *
 * https://leetcode.com/problems/minimum-number-of-people-to-teach/
 */
class Solution {
 public:
  int minimumTeachings(int n, vector<vector<int>>& languages,
                       vector<vector<int>>& friendships) {
    // First find set of users that can't communicate:
    unordered_set<int> cannot_communicate;
    for (auto& friends : friendships) {
      int u = friends[0] - 1;
      int v = friends[1] - 1;
      unordered_set<int> friend_u_languages(languages[u].begin(),
                                            languages[u].end());
      bool can_communicate = false;
      for (int lang : languages[v]) {
        if (friend_u_languages.contains(lang)) {
          can_communicate = true;
          break;
        }
      }

      if (!can_communicate) {
        cannot_communicate.insert(u);
        cannot_communicate.insert(v);
      }
    }

    // Figure out which language is already known by the most people.
    // Greedily choose to teach everyone else that language.
    vector<int> language_count(n + 1, 0);
    int max_count = 0;
    for (int user : cannot_communicate) {
      for (int lang : languages[user]) {
        language_count[lang]++;
        max_count = max(max_count, language_count[lang]);
      }
    }
    return cannot_communicate.size() - max_count;
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
