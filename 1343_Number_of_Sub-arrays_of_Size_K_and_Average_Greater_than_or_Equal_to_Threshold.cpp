#include <bits/stdc++.h>
using namespace std;

/**
 * 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to
 * Threshold
 *
 * https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
 */
class Solution {
 public:
  int numOfSubarrays(const vector<int>& arr, int k, int threshold) {
    // average formula:
    // (arr[i] + arr[i+1] + ... + arr[i+k-1]) / k

    // safe to use int for sum because max size is 10^9, and 2^31-1 is > 10^9

    int sum = 0;
    for (int i = 0; i < k; i++) {
      sum += arr[i];
    }

    int count = 0;
    int limit = k * threshold;

    if (sum >= limit) {
      count++;
    }

    for (int i = k; i < arr.size(); i++) {
      sum -= arr[i - k];
      sum += arr[i];

      if (sum >= limit) {
        count++;
      }
    }

    return count;
  }
};

int main() {
  Solution sol;

  cout << sol.numOfSubarrays({11, 13, 17, 23, 29, 31, 7, 5, 2, 3}, 3, 5)
       << endl;

  return 0;
}
