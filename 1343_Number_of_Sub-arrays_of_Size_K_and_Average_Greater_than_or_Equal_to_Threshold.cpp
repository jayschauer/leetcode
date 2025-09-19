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
    //
    // Don't want to try updating the average due to floating point precision
    // issues Maximum size of sum is 10^4 * 10^5 > 2^31 - 1. So we will use a
    // long for the sum and just calculate the threshold as needed.

    long sum = 0;
    for (int i = 0; i < k; i++) {
      sum += arr[i];
    }

    int count = 0;

    if (sum / k >= threshold) {
      count++;
    }

    for (int i = k; i < arr.size(); i++) {
      sum -= arr[i - k];
      sum += arr[i];

      if (sum / k >= threshold) {
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
