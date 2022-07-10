"""
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
"""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:
    
    def serializeR(self,nodes, roots):
      if len(list(filter(lambda x: x is not None, roots))) == 0:
        return
      # bfs
      newroots = []
      for r in roots:
        nodes.append(r)
        if r is None:
            newroots.append(None)
            continue
        if r.left is not None:
          newroots.append(r.left)
        else:
          newroots.append(None)
        if r.right is not None:
          newroots.append(r.right)
        else:
          newroots.append(None)
      self.serializeR(nodes,newroots)

    def serialize(self, root):
        accum = []
        self.serializeR(accum,[root])
        return accum
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        

# Your Codec object will be instantiated and called as such:
c = Codec()


n4 = TreeNode(4)
n5 = TreeNode(5)
n2 = TreeNode(2)
n3 = TreeNode(3)
n1 = TreeNode(1)
n1.left = n2
n1.right=n3 
n3.left=n4 
n3.right=n5

# root = [1,2,3,null,null,4,5]
expect = [1,2,3,None,None,4,5]
test = c.serialize(n1)
for t in test:
    print(f"test is {None if t is None else t.val}")
# print(f"expect {expect}\n {test}")
# ans = deser.deserialize(ser.serialize(root))