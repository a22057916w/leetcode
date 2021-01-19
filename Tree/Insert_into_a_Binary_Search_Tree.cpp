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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root, new TreeNode(val));
    }

    TreeNode *insert(TreeNode *root, TreeNode *newNode) {
      if(root == NULL)
        return newNode;

      if(newNode->val <= root->val)
        root->left = insert(root->left, newNode);
      else
        root->right = insert(root->right, newNode);

      return root;
    }
};
