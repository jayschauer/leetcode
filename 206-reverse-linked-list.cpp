#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-linked-list/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
      ListNode* next = cur->next;
      // Need to make next point back to node
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }
};

int main() {
  Solution sol;

  cout << sol.reverseList(nullptr) << endl;

  return 0;
}
