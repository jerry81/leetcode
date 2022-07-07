"""
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a
 binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
"""

from typing import List, Optional


# sDefinition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
      root = TreeNode(postorder[-1])

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

"""
first item in both arrays is leftmost leaf 
inorder - LVR
postorder LRV 
last item in postorder is root
inorder until root reached
- this is the left side of the tree up until root 
- remove [9,3]
     3
  9
[15,20,7]
[15,7,20]
- 15 is left most of the remaining tree
- iterate until 20 
- this is the new left with 20 being R of the root 

        3
    9      20
        15    7

- bigger example

               8
        4             12
    2      6       10        14
1     3  5  7   9     11  13    15

postorder = [ 1 3 2 5 7 6 4 9 11 10 13 15 14 12 8 ] 
inorder = [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15]
inorder starts with leftmost 
postorder starts with bottomest leftmost leaf 

with holes

               8
        4             12
    2      6       10        14
      3  5  7   9    11   13    15

post =  3 2 5 7 6 4 9 10 13 15 14 12 8
in = 2 3 4 5 6 7 8 9 10 12 13 14 15
inorder and post meet at first left parent 
post[0] = in[1]
so post[0] is R leaf of in[1]
new leaf = 2 
[5,7,6,4..
[4,5,6,7...

post[0] = 5
indexOf in(5) = 1

              8
        4             12
    2      6       10        14
 1       5  7           13    15
in = 1 2 4 5 6 7 8 10 11 12 13 14 15
post = 1 2 5 7 6 4 11 10 13 15 14 12 8

first find intersection to post[0]
in - 0
so we have a left leaf 

"""

