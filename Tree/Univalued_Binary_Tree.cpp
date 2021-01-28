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

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
      return preorder(root, root->val);
    }

    bool preorder(TreeNode *curr, int val) {
      if(curr) {
        if(curr->val == val) {
          if(preorder(curr->left, val))
            return preorder(curr->right, val);
          else
            return false;
        }
        else
          return false;
      }
      return true;
    }
};
