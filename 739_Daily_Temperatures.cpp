#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(const vector<int>& temperatures) {
    vector<int> result(temperatures.size(), 0);
    stack<int> coldestIndex;
    for (int i = temperatures.size() - 1; i >= 0; i--) {
      int tempToday = temperatures[i];
      // find next coldest
      while (!coldestIndex.empty() &&
             tempToday >= temperatures[coldestIndex.top()]) {
        coldestIndex.pop();
      }
      if (coldestIndex.empty()) {
        coldestIndex.push(i);
        continue;  // result is already set to 0
      }
      // else we found the next coldest temperature
      result[i] = coldestIndex.top() - i;
      coldestIndex.push(i);
    }
    return result;
  }
};

int main() {
  Solution sol;

  vector<int> result = sol.dailyTemperatures({30, 38, 30, 36, 35, 40, 28});

  return 0;
}
