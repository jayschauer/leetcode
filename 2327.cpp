#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/number-of-people-aware-of-a-secret/
 */
class Solution {
 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    // At end of day i, learners[i-1] is the number of people who learn the
    // secret on a given day
    vector<long long> learners(n, 0);
    long long sharers = 0;
    long long total = 1;

    // End of day 1, 1 person learns the secret:
    learners[0] = 1;

    for (int day = delay; day < forget; day++) {
      // people who share equals previous sharers plus people who start
      // sharing today
      sharers = sharers + learners[day - delay];
      learners[day] = sharers;
      total = (total + sharers) % modulo;
    }

    for (int day = forget; day < n; day++) {
      sharers = sharers + learners[day - delay] - learners[day - forget];
      learners[day] = sharers;
      total = (total + sharers - learners[day - forget]) % modulo;
    }

    return (int)total;
  }

 private:
  static constexpr long long modulo = 1'000'000'000 + 7;
};

int main() {
  Solution sol;

  cout << sol.peopleAwareOfSecret(6, 2, 4) << endl;
  cout << sol.peopleAwareOfSecret(4, 1, 3) << endl;

  return 0;
}
