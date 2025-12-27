#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return helper(root, p, q).node;
  }

 private:
  struct SearchResult {
    TreeNode* node;  // The node found (p, q, or LCA)
    bool isFixed;  // True ONLY if this node is the definitive LCA (found both p
                   // and q below)
  };

  SearchResult helper(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
      return {nullptr, false};
    }

    // OPTIMIZATION 1: The "Solution 1" Logic
    // If we hit p or q, stop traversing this subtree immediately.
    // We mark isFixed as false because we haven't found the *other* node yet.
    if (root == p || root == q) {
      return {root, false};
    }

    // Search Left
    SearchResult left = helper(root->left, p, q);

    // OPTIMIZATION 2: The "Solution 2" Logic
    // If the left side found the definite LCA, stop! Do not search the right.
    if (left.isFixed) {
      return left;
    }

    // Search Right
    SearchResult right = helper(root->right, p, q);

    // OPTIMIZATION 2 (Continued):
    // If the right side found the definite LCA, pass it up.
    if (right.isFixed) {
      return right;
    }

    // MERGE LOGIC
    // If we found something on the left AND something on the right,
    // then the current 'root' is the LCA.
    if (left.node && right.node) {
      return {root, true};  // isFixed = true! We found both.
    }

    // Otherwise, bubble up whichever non-null value we found.
    return left.node ? left : right;
  }
};

int main() {
  Solution sol;

  cout << sol.lowestCommonAncestor(nullptr, nullptr, nullptr) << endl;

  return 0;
}
