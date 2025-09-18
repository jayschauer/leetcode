#include <bits/stdc++.h>
using namespace std;

/**
 * 121. Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock
 */
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // To maximize profit, want to buy low and sell high.
    // So go left to right, tracking the smallest we've seen so far.
    // If buying on that day and selling on the current day
    // gives more profit than our max we've been able to generate,
    // then that becomes our new max profit.

    int lowestPrice = prices[0];
    int maxProfit = 0;
    for (int price : prices) {
      if (price < lowestPrice) {
        lowestPrice = price;
      } else if (price > lowestPrice) {
        maxProfit = max(maxProfit, price - lowestPrice);
      }
    }
    return maxProfit;
  }
};
