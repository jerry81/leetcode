from typing import Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right



class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        newroot = TreeNode()
        if root1 is None and root2 is None:
            return None 
        elif root1 is not None and root2 is not None:
          if root1.val is not None and root2.val is not None:
              newroot.val = root1.val + root2.val 
        elif root1 is not None:
            newroot.val = root1.val 
        elif root2 is not None:
            newroot.val = root2.val 
        else:
            return None
        left1 = None if root1 is None else root1.left 
        left2 = None if root2 is None else root2.left
        right1 = None if root1 is None else root1.right
        right2 = None if root2 is None else root2.right
        newleft = self.mergeTrees(left1, left2)
        newright = self.mergeTrees(right1,right2)
        newroot.left = newleft 
        newroot.right = newright
        return newroot

