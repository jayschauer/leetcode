#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode head{};
    // now add the smaller node of each list
    ListNode* cur = &head;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        cur->next = list1;
        cur = cur->next;
        list1 = list1->next;
      } else {
        cur->next = list2;
        cur = cur->next;
        list2 = list2->next;
      }
    }
    // now add the remaining nodes from either list
    if (list1) {
      cur->next = list1;
    } else {
      cur->next = list2;
    }
    return head.next;
  }
};

int main() {
  Solution sol;

  cout << sol.mergeTwoLists(nullptr, nullptr) << endl;

  return 0;
}
