#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(const vector<int>& temperatures) {
    vector<int> result(temperatures.size(), 0);
    for (int i = temperatures.size() - 2; i >= 0; i--) {
      int tempToday = temperatures[i];
      int j = i + 1;
      // find next coldest
      while (tempToday >= temperatures[j] && j < temperatures.size()) {
        if (result[j] == 0) {
          break;
        }
        j += result[j];
      }
      if (tempToday >= temperatures[j] && result[j] == 0) {
        continue;  // result is already set to 0
      }

      // else we found the next coldest temperature
      result[i] = j - i;
    }
    return result;
  }
};

int main() {
  Solution sol;

  vector<int> result = sol.dailyTemperatures({30, 38, 30, 36, 35, 40, 28});

  return 0;
}
