#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/linked-list-cycle/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  bool hasCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        // fast caught up to slow
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;

  cout << sol.hasCycle(nullptr) << endl;

  return 0;
}
