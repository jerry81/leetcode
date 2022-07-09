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
    def contains(self, root: 'TreeNode', search: 'TreeNode', results=[], depthMap = {}, depth=0):
        if root is None:
            return False
        if root == search:
            results.append(root)
            depthMap[root.val] = depth
            return True 
        if (self.contains(root.left, search, results, depthMap, depth+1) or self.contains(root.right,search, results, depthMap, depth+1)):
            results.append(root)
            depthMap[root.val] = depth

    def lowestCommonR(self, root:'TreeNode', p: 'TreeNode', q:'TreeNode', depth, maxDepth, sol):
        if root is None:
            return
        if self.contains(root, q) and self.contains(root, p) and depth > maxDepth:
            sol.append({ "node": root, "depth": depth})
            maxDepth = depth
            
        self.lowestCommonR(root.left, p, q, depth+1, maxDepth, sol)
        self.lowestCommonR(root.right, p, q, depth+1, maxDepth, sol)
           
        
    def lowestCommonAncestorBadPerf(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        res = []
        self.lowestCommonR(root, p, q, 0,-1,sol=res)
        res =  list(sorted(res, key=lambda item: item['depth'], reverse=True))
        print(f"sortedRes is {res}")
        return res[0]['node']
    
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        resP = []
        depthMap = {}
        self.contains(root, p, resP, depthMap)
        resQ = []
        self.contains(root, q, resQ, depthMap)
        print(f"resP is {resP}")
        print(f"resQ is {resQ}")
        print(f"depthMap is {depthMap}")

    # need to improve performance 

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

print(f"expect True {s.contains(n0,n8)}")
print(f"expect False {s.contains(n2,n1)}")

p = n1
q = n2
expect = n0
print(f"example 1 is {'correct' if s.lowestCommonAncestor(n0,p,q) == expect else 'fail'}")

q = n8
expect = n1
# print(f"val is {s.lowestCommonAncestor(n0,p,q).val}")
print(f"example 2 is {'correct' if s.lowestCommonAncestor(n0,p,q) == expect else 'fail'}")
