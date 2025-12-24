#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    queue<pair<TreeNode*, int>> nodes;
    nodes.push({root, 1});
    int maxDepth = 0;
    while (!nodes.empty()) {
      pair<TreeNode*, int> current = nodes.front();
      nodes.pop();

      TreeNode* node = current.first;
      int depth = current.second;

      maxDepth = max(maxDepth, depth);
      if (node->left) nodes.push({node->left, depth + 1});
      if (node->right) nodes.push({node->right, depth + 1});
    }
    return maxDepth;
  }
};

int main() {
  Solution sol;

  cout << sol.maxDepth(nullptr) << endl;

  return 0;
}
