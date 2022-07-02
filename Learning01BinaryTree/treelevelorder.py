"""
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
"""

# Definition for a binary tree node.
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        return 
        
s = Solution()
n1 = TreeNode(val=15)
n2 = TreeNode(val=7)
n3 = TreeNode(val=20, left=n1, right=n2)
n4 = TreeNode(val=9)
root = TreeNode(val=3, left=n4, right=n3)
ex = [[3],[9,20],[15,7]]
print(f"expect {ex}\ns {s.levelOrder(root)}")