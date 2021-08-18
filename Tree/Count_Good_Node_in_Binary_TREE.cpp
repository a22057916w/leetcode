// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
  vector<int> v;


  int goodNodes(TreeNode* root) {
    int maxn = root->val;
    preorder(root, maxn);

    return v.size();
  }

  void preorder(TreeNode *curr, int maxn) {
    if(curr) {
      maxn = max(maxn, curr->val);
      if(curr->val >= maxn)
        v.push_back(curr->val);

      preorder(curr->left, maxn);
      preorder(curr->right, maxn)
    }
  }
};
