"""
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return

s = Solution()

n0 = TreeNode(3)
n1 = TreeNode(5)
n2 = TreeNode(1)
n3 = TreeNode(6)
n4 = TreeNode(2)
n5 = TreeNode(0)
n6 = TreeNode(8)
n7 = TreeNode(7)
n8 = TreeNode(4)
n0.left = n1 
n0.right = n2 
n1.left = n3
n1.right = n4 
n2.left = n5 
n2.right = n6
n4.left = n7
n4.right = n8

p = n1
q = n2
expect = n0
print(f"example 1 is {'correct' if s.lowestCommonAncestor(n0,p,q) == expect else 'fail'}")
