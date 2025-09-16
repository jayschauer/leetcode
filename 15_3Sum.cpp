#include <bits/stdc++.h>
using namespace std;

/**
 * 15. 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 */
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    // Naive solution: just compare everything, O(n^3)

    // Can repeat what we did for 2-some: sort the array, then make the target
    // each element of the array. That gives us a O(n^2) algorithm and O(1)
    // space (not counting the input).

    // Either O(1) or O(n) space depending on the algorithm.
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        // This is just an optimization;
        // we know everything after i is greater than it, so it won't make our
        // sum smaller to be zero.
        break;
      }

      if (i > 0 && nums[i] == nums[i - 1]) {
        // Want to avoid duplicate triplets.
        // So we skip an element equal to one we've already checked.
        // Only need to compare adjacent elements because we've sorted the
        // numbers.
        continue;
      }
      int j = i + 1;
      int k = nums.size() - 1;

      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum > 0) {
          k--;  // need to make sum smaller
        } else if (sum < 0) {
          j++;  // need to make sum bigger
        } else {
          result.push_back({nums[i], nums[j], nums[k]});
          // Increment j to try to find a new triplet.
          j++;
          // Can decrement k as well:
          // If it still summed to zero with j++, that means j is the same and
          // we don't have a distinct triplet.
          k--;

          while (j < k && (nums[j] == nums[j - 1])) {
            // Again, we want to avoid duplicate triplets.
            // So we skip over "j"s that we've already checked.
            // Once we find a new j, that guarantees k will also be different.
            j++;
          }
        }
      }
    }

    return result;
  }
};

void printSolution(const vector<vector<int>>& vec) {
  cout << "[ ";
  for (const auto& v : vec) {
    cout << "[";
    for (const int num : v) {
      cout << num << " ";
    }
    cout << "] ";
  }
  cout << "]" << endl;
}

int main() {
  Solution sol;

  vector<int> nums{-1, 0, 1, 2, -1, -4};
  printSolution(sol.threeSum(nums));
  // [[-1,-1,2],[-1,0,1]]

  nums = {0, 1, 1};
  printSolution(sol.threeSum(nums));
  // []

  nums = {0, 0, 0};
  printSolution(sol.threeSum(nums));
  // [[0,0,0]]

  return 0;
}
