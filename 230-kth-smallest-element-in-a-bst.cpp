#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
  int kthSmallest(TreeNode* root, int k) { return kthSmallestHelper(root, k); }

 private:
  int kthSmallestHelper(TreeNode* root, int& k) {
    // now we've found the smallest
    if (!root) return -1;
    // otherwise keep diving down the left
    int result = kthSmallestHelper(root->left, k);
    // kth smallest was found down that path, pass it up
    if (result >= 0) {
      return result;
    }

    k--;
    if (k == 0) {
      // we've found the smallest coming back up from the left!
      return root->val;
    }

    // now check to the right
    result = kthSmallestHelper(root->right, k);
    if (result >= 0) {
      return result;
    }

    return -1;
  }
};

int main() {
  Solution sol;

  cout << sol.kthSmallest(nullptr, 1) << endl;

  return 0;
}
