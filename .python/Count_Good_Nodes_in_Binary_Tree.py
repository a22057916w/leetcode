# https://leetcode.com/problems/count-good-nodes-in-binary-tree/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
      def preorder(node, max_val):
        if not node:
          return 0;

        good = 1 if node.val >= max_val else 0
        max_val = max(max_val, node.val)
        return good + preorder(node.left, max_val) + preorder(node.right, max_val)

      return preorder(root, root.val)
