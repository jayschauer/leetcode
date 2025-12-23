#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) {
      return head;
    }
    ListNode* cur = head;
    // Move cur n spots ahead
    while (n > 0) {
      cur = cur->next;
      n--;
    }

    ListNode dummy{0, head};
    ListNode* beforeRemove = &dummy;
    while (cur) {
      cur = cur->next;
      beforeRemove = beforeRemove->next;
    }

    beforeRemove->next = beforeRemove->next->next;
    return dummy.next;
  }
};

int main() {
  Solution sol;

  cout << sol.removeNthFromEnd(nullptr, 0) << endl;

  return 0;
}
