#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int largestRectangleArea(const vector<int>& heights) {
    // precompute pse & nse for each item in the histogram. then use that to
    // calculate largestRectangleArea.

    int n = heights.size();
    // pse[i] represents the idx of the prevous smaller height
    vector<int> pse(n, -1);
    // nse[i] represents the idx of the next smaller height
    vector<int> nse(n, n);

    for (int i = 1; i < n; i++) {
      int j = i - 1;
      while (heights[j] >= heights[i]) {
        if (pse[j] == -1) {
          break;
        }
        j = pse[j];
      }

      if (heights[j] >= heights[i] && pse[j] == -1) {
        continue;  // pse[i] is already set to -1
      }
      pse[i] = j;
    }

    for (int i = n - 2; i >= 0; i--) {
      int j = i + 1;
      while (heights[j] >= heights[i]) {
        if (nse[j] == n) {
          break;
        }
        j = nse[j];
      }

      if (heights[j] >= heights[i] && nse[j] == n) {
        continue;  // nse[i] is already set to n
      }
      nse[i] = j;
    }

    int maxArea = -1;
    for (int i = 0; i < heights.size(); i++) {
      // Formula is (right - left + 1) * height.
      // nse / pse are +1/-1 from our actual rectangle.
      // So instead we do (nse - pse - 2 + 1) * height = (nse - pse - 1) *
      // height.
      maxArea = max(maxArea, (nse[i] - pse[i] - 1) * heights[i]);
    }
    return maxArea;
  }
};

int main() {
  Solution sol;

  cout << sol.largestRectangleArea({7, 1, 7, 2, 2, 4}) << endl;

  return 0;
}
