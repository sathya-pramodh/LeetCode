#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
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
  void flatten(TreeNode *root) {
    if (root == NULL)
      return;
    flatten(root->left);
    flatten(root->right);
    TreeNode *temp = root->right;
    root->right = root->left;
    TreeNode *curr = root;
    while (curr->right != NULL) {
      curr = curr->right;
    }
    curr->right = temp;
    root->left = NULL;
  }
};
