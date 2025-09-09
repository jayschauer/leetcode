#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/number-of-people-aware-of-a-secret/
 */
class Solution {
 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    // p.second stores the number of people who know the secret for p.first days
    queue<pair<int, int>> knowers;

    // End of day 1, 1 person knows the secret:
    knowers.emplace(1, 1);

    // days 2-n:
    for (int i = 1; i < n; i++) {
      int learners = 0;

      while (true) {
        const pair<int, int>& front = knowers.front();

        // Skip people who forget today
        if (front.first >= forget) {
          knowers.pop();
          continue;
        }

        // Copy people who haven't forgot forward
        knowers.emplace(front.first + 1, front.second);

        // if they've reached delay, add the people they share with to learners
        if (front.first >= delay) {
          learners = (learners + front.second) % modulo;
        }

        // Base case: learners from yesterday. They
        if (front.first == 1) {
          knowers.pop();
          break;
        }

        knowers.pop();
      }

      knowers.emplace(1, learners);
    }

    // return the number of people who know the secret at the end of day n
    int total = 0;
    while (!knowers.empty()) {
      total = (total + knowers.front().second) % modulo;
      knowers.pop();
    }
    return total;
  }

 private:
  static constexpr int modulo = 1000000000 + 7;
};

int main() {
  Solution sol;

  cout << sol.peopleAwareOfSecret(6, 2, 4) << endl;
  cout << sol.peopleAwareOfSecret(4, 1, 3) << endl;

  return 0;
}
