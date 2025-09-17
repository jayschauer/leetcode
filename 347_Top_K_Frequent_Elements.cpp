#include <bits/stdc++.h>
using namespace std;

/**
 * 347. Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/
 */
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    if (k == nums.size()) {
      return nums;
    }

    // Get number:frequency map. O(n)
    unordered_map<int, int> frequencies;
    for (int num : nums) {
      frequencies[num]++;
    }

    // Convert to vector of (frequency, num) pairs,
    // so we can run selection algorithm on the frequencies
    // O(n)
    vector<pair<int, int>> frequency_list;
    frequency_list.reserve(frequencies.size());
    for (const auto& kv : frequencies) {
      frequency_list.emplace_back(kv.second, kv.first);
    }

    // Find topK with STL selection algorithm
    nth_element(frequency_list.begin(), frequency_list.begin() + k - 1,
                frequency_list.end(), greater<pair<int, int>>());

    // return result
    vector<int> topK;
    topK.reserve(k);
    for (auto freq_num = frequency_list.begin();
         freq_num != frequency_list.begin() + k; freq_num++) {
      topK.push_back(freq_num->second);
    }

    return topK;
  }
};
