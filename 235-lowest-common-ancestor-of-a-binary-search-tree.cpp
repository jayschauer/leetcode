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
    // DFS for p and q.
    // Track the highest level where p and q are found.

    // Given that node values are unique, we might be able to take advantage
    // of serialization?
    TreeNode* result = nullptr;
    lowestCommonAncestorInner(root, p, q, result);
    return result;
  }

 private:
  pair<bool, bool> lowestCommonAncestorInner(TreeNode* root, TreeNode* p,
                                             TreeNode* q, TreeNode*& result) {
    if (root == nullptr) {
      return {false, false};
    }

    auto foundPQLeft = lowestCommonAncestorInner(root->left, p, q, result);
    if (result) {
      // p and q have a common ancestor down the left subtree
      return {true, true};
    }
    auto foundPQRight = lowestCommonAncestorInner(root->right, p, q, result);
    if (result) {
      // p and q have a common ancestor down the right subtree
      return {true, true};
    }

    pair<bool, bool> foundPQ{foundPQLeft.first || foundPQRight.first,
                             foundPQLeft.second || foundPQRight.second};

    if (root == p) {
      foundPQ.first = true;
    } else if (root == q) {
      foundPQ.second = true;
    }

    if (foundPQ.first && foundPQ.second) {
      result = root;
      return {true, true};
    }

    return foundPQ;
  }
};

int main() {
  Solution sol;

  cout << sol.lowestCommonAncestor(nullptr, nullptr, nullptr) << endl;

  return 0;
}
