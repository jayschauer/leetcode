#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;

    // Algorithm:
    // Keep a priority queue of elements we've seen in the window.
    // When we slide the window, pop the largest until largest is outside the
    // window. Also pop anything that is outside our window. Then we can easily
    // get the biggest element in our window. Building priority queue takes
    // klogk time. Then we slide it n-k times.
    // Each time we slide it takes amortized log(k) to pop elements until we
    // find the biggest within our range. The priority queue could carry up to
    // n-k-1 extra elements outside the window before we pop them. So overall
    // algorithm would take O(klogk + (n-k)log(n-k-1)) = O(nlogn). Space would
    // be O(n).

    priority_queue<pair<int, int>> max;
    for (int i = 0; i < k; i++) {
      max.push({nums[i], i});
    }

    result.push_back(max.top().first);

    for (int i = k; i < nums.size(); i++) {
      // Add next element
      max.push({nums[i], i});
      // Get biggest element inside our range
      pair<int, int> top = max.top();
      while (top.second <= i - k) {
        max.pop();
        top = max.top();
      }
      result.push_back(max.top().first);
      // Move window (i++)
    }

    return result;
  }
};
