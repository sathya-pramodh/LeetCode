#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://leetcode.com/problems/sum-root-to-leaf-numbers

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int helper(TreeNode *node, int sum) {
    if (node == NULL)
      return 0;
    if (node->left == NULL && node->right == NULL) {
      sum = sum * 10 + node->val;
      return sum;
    }
    sum = sum * 10 + node->val;
    int left_sum = 0, right_sum = 0;
    left_sum = helper(node->left, sum);
    right_sum = helper(node->right, sum);
    return left_sum + right_sum;
  }
  int sumNumbers(TreeNode *root) { return helper(root, 0); }
};
