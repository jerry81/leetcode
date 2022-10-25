"""
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
"""

# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
  def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []
        res = []
        if root.left is not None:
            res += (self.inorderTraversal(root.left))
        res += [root.val]
        if root.right is not None:
            res += (self.inorderTraversal(root.right))
        return res 
        
l2 = TreeNode(val=3)
r1 = TreeNode(val=2, left=l2)
root = TreeNode(val=1, right=r1)

ex = [1,3,2]
s = Solution()
print(f"expect {ex}\ns {s.inorderTraversal(root)}")