#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/balanced-binary-tree/

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
  bool isBalanced(TreeNode* root) {
    auto [isBalanced, height] = dfs(root);
    return isBalanced;
  }

 private:
  pair<bool, int> dfs(TreeNode* root) {
    if (!root) {
      return {true, 0};
    }
    auto [leftBal, leftH] = dfs(root->left);
    if (!leftBal) return {false, -1};
    auto [rightBal, rightH] = dfs(root->right);
    if (!rightBal) return {false, -1};

    if (abs(leftH - rightH) > 1) {
      return {false, -1};
    }

    return {true, 1 + max(leftH, rightH)};
  }
};

int main() {
  Solution sol;

  cout << sol.isBalanced(nullptr) << endl;

  return 0;
}
