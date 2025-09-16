#include <bits/stdc++.h>
using namespace std;

/**
 * 2197. Replace Non-Coprime Numbers in Array
 *
 * https://leetcode.com/problems/replace-non-coprime-numbers-in-array/
 */
class Solution {
 public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    // Two numbers are co-prime if their GCD is 1.
    // We are replacing all adjacent non-co-prime pairs with their LCM.

    int top = -1;
    for (int x : nums) {
      // While there is at least one element on the "stack"
      while (top != -1) {
        int g = gcd(nums[top], x);
        // If GCD is 1, they are co-prime, so no merge.
        if (g == 1) break;

        // Otherwise, merge the two numbers into their LCM.
        // LCM = a*b/gcd.
        x = nums[top] / g * x;

        // Pop the top since it has been merged.
        top--;
      }

      // Push the merged (or unmerged) number back onto the stack.
      nums[++top] = x;
    }

    // Erase everything not part of the processed stack
    nums.erase(nums.begin() + top + 1, nums.end());
    return nums;
  }
};

void printVector(const vector<int>& vec) {
  for (const int num : vec) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;

  vector<int> nums{6, 4, 3, 2, 7, 6, 2};
  vector<int> result = sol.replaceNonCoprimes(nums);
  printVector(result);  // [12,7,6]

  nums = {2, 2, 1, 1, 3, 3, 3};
  result = sol.replaceNonCoprimes(nums);
  printVector(result);  // [2,1,1,3]

  return 0;
}
