#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reorder-list/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head) {
      return;
    }
    // vibe I'm feeling is that we can build up two chains, then combine the
    // chains? e.g. reverse the latter half of the LL, then combine that with
    // the original list. Can find the midway point with two pointers
    // efficiently.
    ListNode* cur = head;
    ListNode* toMerge = reverseList(findMiddle(head));
    while (toMerge != nullptr && toMerge != cur) {
      ListNode* temp = cur->next;
      cur->next = toMerge;
      toMerge = toMerge->next;
      cur->next->next = temp;
      cur = temp;
      // what happens when cur->next is middle?
      // invariant in this loop is that cur is before middle.
      // so then we should break out and make sure cur-next gets cleared
    }
    cur->next = nullptr;  // make sure the list ends
  }

 private:
  ListNode* findMiddle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    // this will return the node at `ceil(<length of list>)`
    return slow;
  }
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

  sol.reorderList(nullptr);

  return 0;
}
