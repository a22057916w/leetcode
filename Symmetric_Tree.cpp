// The idea is similar to that compare two tree but in a symmtric
// way(left to right; right to left).

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        else
            return isSymEqual(root->left, root->right);
    }

    bool isSymEqual(TreeNode *l, TreeNode *r) {
        if(l == NULL && r == NULL)                  // case 1 (l and r are both null)
            return true;
        else if(l != NULL && r != NULL) {           // case 2 (none of both is null)
            if(l->val != r->val)
                return false;
            else {
                if(isSymEqual(l->left, r->right))
                    return isSymEqual(l->right, r->left);
                else
                    return false;
            }
        }
        else                                       // case 3 (either one of them is null)
            return false;
    }
};
