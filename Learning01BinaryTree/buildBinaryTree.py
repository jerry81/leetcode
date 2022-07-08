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
    def  __str__(self):
        return f"{self.val}, l {self.left} r {self.right}"
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if len(postorder) == 0:
            return None 
        if len(postorder) == 1:
            return TreeNode(postorder[0])
        rootVal = postorder.pop()
        idx = inorder.index(rootVal)
        left = inorder[:idx]
        right = inorder[idx+1:]
        leftP = postorder[:idx]
        rightP = postorder[idx+1:]
        return TreeNode(rootVal, self.buildTree(left,leftP), self.buildTree(right,rightP))

    def buildTreeFail(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
      left = inorder.pop(0)
      idx = postorder.index(left)
      nextNode = None
      print(f"left is {left}")
      print(f"idx is {idx}")
      for i in range(idx+1):
        nextType = ["L","R","V"]
        n = nextType[i%3]
        nextPost = postorder[i]
        print(f"nextPost is {nextPost}")
        node = TreeNode(nextPost)
        print(f"n is {n}")
        nextNode = node 
      postorder = postorder[idx+1:]
      print(f"nextNode is {nextNode.val}")
      print(f"next iter post {postorder} in {inorder}")
      left = inorder.pop(0)
      idx = postorder.index(left)
      print(f"left is {left}")
      print(f"idx is {idx}")
      for i in range(idx+1):
        nextType = ["L","R","V"]
        n = nextType[i%3]
        nextPost = postorder[i]
        print(f"nextPost is {nextPost}")
        node = TreeNode(nextPost)
        print(f"n is {n}")
        nextNode = node 
      postorder = postorder[idx+1:]
      print(f"next iter post {postorder} in {inorder}")

s=Solution()
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
tree = s.buildTree(inorder,postorder)
print(f"tree is {tree}")

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
      3  5  7   9         13    15

post =  3 2 5 7 6 4 9 10 13 15 14 12 8
in = 2 3 4 5 6 7 8 9 10 12 13 14 15
inorder and post meet at first left parent 
post[0] = in[1]
so post[0] is R leaf of in[1]
new leaf = 2 
post [5,7,6,4..
in [4,5,6,7...
post and in intersecting at 5 (post 0 in 1) just means in[0] is the next leftmost item and is a parent of post[0]
starting with in = 8:
and post = 9
get next in - 10 
10 is next item in post so there are no items in between
- 9 is a leaf at the left and 10 is the parent
post 13 15 14 12
in 12 13 14 
- 12 is the next leaf - we need to fill up post until 12 
so 13,15,14 are all moving up lrv 
13 left leaf 15 right leaf 
14 parent of 13 and 15 and right of 12

in[0] intersects with post[1]
in[1] is also post[0]
so post[0] is right child of in[0]
in[0] is leftmost leaf 

post [5,7,6,4...
in [4,5,6,7....

in[0] = 4
indexOf post(4) = 4
- so 5,7,6 are l,r,v and are the right child of 4 

now left leaf is 4 
post is [9 10 13 15 14 12 8]
in is [8 9 10 12 13 14 15]

- pattern is exploding...
in[0] = post[6]
so 8 is left most 
and post 9 is leaf (left) 10 is 

              8
        4             12
    2      6       10        14
 1       5  7    11      13    15
in = 1 2 4 5 6 7 8 10 11 12 13 14 15
post = 1 2 5 7 6 4 11 10 13 15 14 12 8

first find intersection to post[0]
in - 0
so we have a left leaf 

"""

