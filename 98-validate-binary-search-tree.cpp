#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/validate-binary-search-tree/

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
  bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, numeric_limits<long>::min(), numeric_limits<long>::max());
  }

 private:
  bool isValidBSTHelper(TreeNode* root, long minVal, long maxVal) {
    if (!root) {
      return true;
    }

    long cur = root->val;

    if (cur <= minVal || cur >= maxVal) {
      return false;
    }

    return isValidBSTHelper(root->left, minVal, min(maxVal, cur)) &&
           isValidBSTHelper(root->right, max(minVal, cur), maxVal);
  }
};

int main() {
  Solution sol;

  cout << sol.isValidBST(nullptr) << endl;

  return 0;
}
