"""
Given two integer arrays preorder and inorder where preorder is the preorder traversal 
of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
"""

from typing import List, Optional

# sDefinition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    def  __str__(self):
        return f"{self.val}, l {self.left} r {self.right}"
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0:
            return None 
        if len(preorder) == 1:
            return TreeNode(preorder[0])
        rootVal = preorder.pop(0)
        idx = inorder.index(rootVal)
        left = inorder[:idx]
        right = inorder[idx+1:]
        leftP = preorder[:idx]
        rightP = preorder[idx:]
        return TreeNode(rootVal, self.buildTree(leftP,left), self.buildTree(rightP,right))


s=Solution()
preorder =  [3,9,20,15,7]
inorder = [9,3,15,20,7]
tree = s.buildTree(preorder,inorder)
print(f"tree is {tree}")
