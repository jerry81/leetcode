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
        if root1.val is not None and root2.val is not None:
            newroot.val = root1.val + root2.val 
        elif root1.val is not None:
            newroot.val = root1.val 
        elif root2.val is not None:
            newroot.val = root2.val 
        else:
            return None
        newleft = self.mergeTrees(root1.left, root2.left)
        newright = self.mergeTrees(root1.right,root2.right)
        newroot.left = newleft 
        newroot.right = newright
        return newroot

