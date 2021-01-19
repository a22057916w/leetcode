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
    TreeNode *getSuccessor(TreeNode *curr) {
      while(curr && curr->left)
        curr = curr->left;
      return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

      // base case
      if(root == NULL)
        return root;

      if(key < root->val)
        root->left = deleteNode(root->left, key);
      else if(key > root->val)
        root->right = deleteNode(root->right, key);

      // find the target node
      else {
        TreeNode *temp;

        // one child or no child
        if(root->left == NULL) {
          temp = root->right;         // This may return null
          root = NULL;
          delete root;
          return temp;
        }
        else if(root->right == NULL) {
          temp = root->left;          // This may return null
          root = NULL;
          delete root;
          return temp;
        }

        // two childern
        else {

          // find the leftmost node in the right subtree
          temp = getSuccessor(root->right);

          // copy the inorder successor's content to this node
          root->val = temp->val;

          // delete the inorder successor
          root->right = deleteNode(root->right, temp->val);

        }
      }

      // for Case : target with two nodes
      return root;
  }
};
