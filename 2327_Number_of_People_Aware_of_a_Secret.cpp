#include <bits/stdc++.h>
using namespace std;

/**
 * Number of People Aware of a Secret
 *
 * https://leetcode.com/problems/number-of-people-aware-of-a-secret/
 */
class Solution {
 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    // Learners[i-1] is the number of people who learn the secret on day i
    vector<int> learners(n, 0);
    int sharers = 0;  // running total of people who can share the secret
    int total = 1;    // running total of people who know the secret

    // Day 1, 1 person learns the secret:
    learners[0] = 1;

    // Day delay to forget - can ignore forgetting
    for (int day = delay; day < forget; day++) {
      // New sharers are those who learned the secret 'delay' days ago
      sharers = (sharers + learners[day - delay]) % modulo;
      // All sharers share the secret with a new set of learners
      learners[day] = sharers;
      // Add new learners to total
      total = (total + learners[day]) % modulo;
    }

    // Day forget to n - need to account for forgetting
    for (int day = forget; day < n; day++) {
      // Remove those who forget the secret today
      sharers = (sharers - learners[day - forget]) % modulo;
      // Add new sharers who learned the secret 'delay' days ago
      sharers = (sharers + learners[day - delay]) % modulo;
      // All sharers share the secret with a new set of learners
      learners[day] = sharers;
      // Remove those who forget the secret today, add new learners
      total = (total - learners[day - forget]) % modulo;
      total = (total + learners[day]) % modulo;
    }

    return (total + modulo) % modulo;  // make sure answer is positive
  }

 private:
  static constexpr int modulo = 1'000'000'000 + 7;
};

int main() {
  Solution sol;

  cout << sol.peopleAwareOfSecret(6, 2, 4) << endl;
  cout << sol.peopleAwareOfSecret(4, 1, 3) << endl;

  return 0;
}
