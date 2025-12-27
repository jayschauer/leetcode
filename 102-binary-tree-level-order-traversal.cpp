#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode*> nodes;
    if (!root) return {};
    nodes.push(root);
    while (!nodes.empty()) {
      vector<int> level;
      int levelSize = nodes.size();
      level.reserve(levelSize);
      for (int i = 0; i < levelSize; i++) {
        TreeNode* node = nodes.front();
        nodes.pop();
        if (node->left) nodes.push(node->left);
        if (node->right) nodes.push(node->right);

        level.push_back(node->val);
      }
      result.push_back(level);
    }
    return result;
  }
};

int main() {
  Solution sol;

  sol.levelOrder(nullptr);

  return 0;
}
