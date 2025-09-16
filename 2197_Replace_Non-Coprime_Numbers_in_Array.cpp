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
    // LCM = a*b/gcd.

    if (nums.size() == 1) {
      return nums;
    }

    int left = 0;

    for (int next_unprocessed = 1; next_unprocessed < nums.size();
         next_unprocessed++) {
      // Move the next unprocessed element into position for processing
      nums[left + 1] = nums[next_unprocessed];
      int gcd = std::gcd(nums[left], nums[left + 1]);

      // Recursively merge left.
      // Loop assumes left+1 is always valid to merge.
      while (gcd > 1) {
        // LCM = a*b/gcd.
        nums[left] = (nums[left] / gcd) * nums[left + 1];
        left--;
        if (left < 0) break;
        gcd = std::gcd(nums[left], nums[left + 1]);
      }
      // Set left to correct spot for next iteration:
      // (A) GCD <= 1, so we don't merge and need to increment it to previous
      // right.
      // (B) We did some merges, and last pair we checked didn't work. So
      // increment to previous right of pair that didn't work.
      // (C) We merged everything and decremented to -1 -> reset to 0.
      left++;
    }

    // If we end on a merge, then left is in the correct index (last merged
    // element).
    // If we don't end on a merge, then left is also in the correct
    // spot (the right element of a failed merge).
    // So we can just delete everything in range [left+1, end)
    nums.erase(nums.begin() + left + 1, nums.end());

    return nums;
  }

 private:
  int lcm(int a, int b, int gcd) { return (a / gcd) * b; }
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
