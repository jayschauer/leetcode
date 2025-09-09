#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/number-of-people-aware-of-a-secret/
 */
class Solution {
 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    // Let dp[i][j] be the number of people who have known the secret for
    // exactly j + 1 days, at day i.
    vector<vector<int>> dp(n, vector(n, 0));
    int modulo = 1000000000 + 7;

    // day 1:
    dp[0][0] = 1;  // end of day 1, 1 person knows the secret

    // days 2-n:
    for (int i = 1; i < n; i++) {
      // Copy people from yesterday who know the secret but haven't shared yet
      for (int j = 0; j < delay - 1; j++) {
        // People at day i who have known for j+2 days are
        // the people at day i-1 who have known for j+1 days;
        dp[i][j + 1] = dp[i - 1][j];
      }
      //
      // Copy people from yesterday who know the secret, haven't forgotton, and
      // are sharing it
      int learners = 0;
      for (int j = delay - 1; j < forget - 1; j++) {
        // Why delay-1? Can share today if end of day yesterday was your
        // delay'th day WHy forget-1? Can share today if end of day yesterday
        // you weren't at forget yet
        learners = (learners + dp[i - 1][j]) % modulo;
        dp[i][j + 1] = dp[i - 1][j];
      }
      //
      // set the people today who have learned
      dp[i][0] = learners;
    }

    // return the number of people who know the secret at the end of day n
    int total = 0;
    for (int j = 0; j < n; j++) {
      total = (total + dp[n - 1][j]) % modulo;
    }
    return total;
  }
};

int main() {
  Solution sol;

  cout << sol.peopleAwareOfSecret(6, 2, 4) << endl;
  cout << sol.peopleAwareOfSecret(4, 1, 3) << endl;

  return 0;
}
