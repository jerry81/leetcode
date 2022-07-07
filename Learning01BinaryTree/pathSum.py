"""
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
"""

# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    sums = []
    def getPathSum(self, root: Optional[TreeNode], cur):
      if root.left is None and root.right is None:
        self.sums.append(cur+root.val)
      if root.left is not None: 
        self.getPathSum(root.left,cur+root.val)
      if root.right is not None:
        self.getPathSum(root.right,cur+root.val)
         

    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False
        self.getPathSum(root, 0)
        return targetSum in self.sums


s = Solution()
targetSum = 22
Output = True
c8 = TreeNode(1)
c2 = TreeNode(2)
c1 = TreeNode(7)
b4 = TreeNode(4,right=c8)
b3 = TreeNode(13)
b1 = TreeNode(11,c1,c2)
a2 = TreeNode(8,b3,b4)
a1 = TreeNode(4,b1)
rt = TreeNode(5,a1,a2)
print(f"expect {Output}\n{s.hasPathSum(rt,targetSum)}")


a1 = TreeNode(2)
rt = TreeNode(1,a1)
targetSum = 1
Output = False 
print(f"expect {Output}\n{s.hasPathSum(rt,targetSum)}")


print(f"expect False {s.hasPathSum(None, 0)}")