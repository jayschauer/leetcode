#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/diameter-of-binary-tree/

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
  int diameterOfBinaryTree(TreeNode* root) {
    auto [maxDiameter, height] = diameterOfBinaryTreeInner(root);
    return maxDiameter;
  }

 private:
  pair<int, int> diameterOfBinaryTreeInner(TreeNode* root) {
    if (!root) return {-1, 0};

    auto [leftD, leftH] = diameterOfBinaryTreeInner(root->left);
    auto [rightD, rightH] = diameterOfBinaryTreeInner(root->right);

    // Diameter at root is leftH + rightH.

    return {max({leftD, rightD, leftH + rightH}), 1 + max(leftH, rightH)};
  }
};

int main() {
  Solution sol;

  cout << sol.diameterOfBinaryTree(nullptr) << endl;

  return 0;
}
