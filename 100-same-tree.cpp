#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/same-tree/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<pair<TreeNode*, TreeNode*>> queue;
    queue.push({p, q});
    while (!queue.empty()) {
      auto [p, q] = queue.front();
      queue.pop();

      if (!p && !q) continue;

      if ((p && !q) || (q && !p)) return false;

      if (p->val != q->val) return false;

      queue.push({p->left, q->left});
      queue.push({p->right, q->right});
    }
    return true;
  }
};

int main() {
  Solution sol;

  cout << sol.isSameTree(nullptr, nullptr) << endl;

  return 0;
}
