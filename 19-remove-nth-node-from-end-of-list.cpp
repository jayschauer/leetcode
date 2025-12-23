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
    // 1) get size of list
    // 2) now go to the size-n th node and remove it
    if (!head) {
      return nullptr;
    }
    int length = getLength(head);
    int toRemoveIndex = length - n;
    if (toRemoveIndex == 0) {
      return head->next;
    }
    int i = 0;
    ListNode* cur = head;
    while (i < toRemoveIndex - 1) {
      cur = cur->next;
      i++;
    }
    // Now cur->toRemove
    if (cur->next) {
      cur->next = cur->next->next;
    } else {
      cur->next = nullptr;
    }
    return head;
  }

 private:
  int getLength(ListNode* head) {
    int length = 0;
    while (head) {
      length++;
      head = head->next;
    }
    return length;
  }
};

int main() {
  Solution sol;

  cout << sol.removeNthFromEnd(nullptr, 0) << endl;

  return 0;
}
