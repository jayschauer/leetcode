#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxTurbulenceSize(const vector<int>& arr) {
    // Similar problem to longest substring without repeating characters,
    // just a little more book keeping.

    int length = 1;
    int maxLength = 1;
    // Sign we will use for comparison of LHS and RHS.
    //  10 means we haven't compared yet.
    //  1 means LHS > RHS
    // -1 means LHS < RHS
    int expectedSign = 10;

    for (int i = 1; i < arr.size(); i++) {
      // First set the current sign
      int currentSign;
      if (arr[i - 1] > arr[i]) {
        currentSign = 1;
      } else if (arr[i - 1] < arr[i]) {
        currentSign = -1;
      } else {
        currentSign = 0;
      }

      if (expectedSign == currentSign) {
        // We're good
        expectedSign *= -1;
        length++;
      } else {
        // Need to start new subarray.
        // Either of these cases:
        // (1) Our element didn't match the previous pattern,
        // so we start a new pattern with arr[i-1] and arr[i].
        // or (2) our element is equal to the previous element,
        // in which case we set length = 1 and start the pattern with
        // the next element.

        if (currentSign == 0) {  // case 2
          // Can't start subarray when arr[i-1] == arr[i]
          length = 1;
          expectedSign = 10;
          continue;
        } else {  // case 1
          expectedSign = currentSign * -1;
          length = 2;
        }
      }
      maxLength = max(maxLength, length);
    }

    return maxLength;
  }
};

int main() {
  Solution sol;

  cout << sol.maxTurbulenceSize({9, 4, 2, 10, 7, 8, 8, 1, 9}) << endl;

  return 0;
}
