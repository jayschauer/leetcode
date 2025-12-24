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
    pair<int, int> result = diameterOfBinaryTreeInner(root);
    return max(result.first, result.second);
  }

 private:
  pair<int, int> diameterOfBinaryTreeInner(TreeNode* root) {
    if (!root) return {-1, -1};

    auto leftDiameter = diameterOfBinaryTreeInner(root->left);
    auto rightDiameter = diameterOfBinaryTreeInner(root->right);

    // We can either make a path going through root, or a path ending at root
    // result.first is for the path going through root
    // result.second is for the path ending at root

    // through: we connect the left/right through root with 2 edges
    int through = leftDiameter.second + rightDiameter.second + 2;
    through = max({through, leftDiameter.first, rightDiameter.first});

    // ending at root: we add 1 edge to the longer of the paths ending at
    // right/left
    int ending = 1 + max(leftDiameter.second, rightDiameter.second);

    return {through, ending};
  }
};

int main() {
  Solution sol;

  cout << sol.diameterOfBinaryTree(nullptr) << endl;

  return 0;
}
