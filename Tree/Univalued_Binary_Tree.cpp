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
