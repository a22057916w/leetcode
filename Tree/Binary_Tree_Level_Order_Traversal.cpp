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
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> result;

      // NULL case
      if(root == NULL)
        return result;

      queue<TreeNode *> q;
      q.push(root);

      while(!q.empty()) {
        int n = q.size();   // record level size
        vector<int> temp;   // store data from a level

        for(int i = 0; i < n; i++) {
          TreeNode *node = q.front();
          q.pop();

          temp.push_back(node->val);

          if(node->left)
            q.push(node->left);
          if(node->right)
            q.push(node->right);
        }

        // push the values from the level
        result.push_back(temp);
      }

      // push levels
      return result;
    }
};
