from typing import List, Optional
# Definition for a binary tree node.
"""
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
"""
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return [-1] 
        queue = [root]
        res = []
        while len(queue) > 0:
            curres = []
            nextqueue = []
            for top in queue:
              if top is None:
                curres.append(None)
              else: 
                curres.append(top.val)
                if top.left is not None:
                  nextqueue.append(top.left)
                else: 
                  nextqueue.append(None)
                if top.right is not None:
                  nextqueue.append(top.right)
                else: 
                  nextqueue.append(None)
            res.append(curres)
            queue = nextqueue
        return res
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        levels = self.levelOrder(root)
        for l in levels:
          if l != l[::-1]:
            return False 
        return True 

        

s = Solution()
b1 = TreeNode(3)
b2 = TreeNode(4)
b3 = TreeNode(4)
b4 = TreeNode(3)
a1 = TreeNode(2,b1,b2)
a2 = TreeNode(2,b3,b4)
rt = TreeNode(1,a1,a2)
print(f"expect True {s.isSymmetric(rt)}")

b2 = TreeNode(3)
b4 = TreeNode(3)
a1 = TreeNode(val=2,right=b2)
a2 = TreeNode(val=2,right=b4)
rt = TreeNode(1,a1,a2)
print(f"expect False {s.isSymmetric(rt)}")