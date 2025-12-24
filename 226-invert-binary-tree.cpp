#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/invert-binary-tree/

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
  TreeNode* invertTree(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    TreeNode* oldLeft = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(oldLeft);
    return root;
  }
};

int main() {
  Solution sol;

  cout << sol.invertTree(nullptr) << endl;

  return 0;
}
