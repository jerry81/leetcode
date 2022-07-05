# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return 

s = Solution()
a1 = TreeNode(9)
b3 = TreeNode(15)
b4 = TreeNode(7)
a2 = TreeNode(20,b3,b4)
root = TreeNode(3, a1,a2)

print(f"expect 3 {s.maxDepth(root)}")

a2 = TreeNode(2)
root = TreeNode(val=1, right=a2)
print(f"expect 2 {s.maxDepth(root)}")
"""
root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
"""