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
    int rootToLeaf = 0;

    int sumRootToLeaf(TreeNode* root) {
      preorder(root, 0);
      return rootToLeaf;
    }

    void preorder(TreeNode *curr, int currNum) {
      if(curr) {
        currNum = (currNum << 1) | curr->val;

        // if it's a leaf, update root-to-leaf sum
        if(curr->left == NULL && curr->right == NULL)
          rootToLeaf += currNum;

        preorder(curr->left, currNum);
        preorder(curr->right, currNum);
      }
    }
};
