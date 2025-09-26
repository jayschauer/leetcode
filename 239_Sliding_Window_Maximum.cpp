#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;

    deque<pair<int, int>> queue;
    for (int i = 0; i < k; i++) {
      int n = nums[i];
      while (!queue.empty() && queue.back().first <= n) {
        queue.pop_back();
      }
      queue.push_back({n, i});
    }

    result.push_back(queue.front().first);

    for (int i = k; i < nums.size(); i++) {
      // Add next element
      int n = nums[i];
      // Remove everything smaller than n
      while (!queue.empty() && queue.back().first <= n) {
        queue.pop_back();
      }
      queue.push_back({n, i});
      // Get biggest element inside our range
      // 1) Remove stuff outside range
      while (queue.front().second <= i - k) {
        queue.pop_front();
      }
      // 2) Get biggest element
      result.push_back(queue.front().first);
      // Move window (i++)
    }

    return result;
  }
};
