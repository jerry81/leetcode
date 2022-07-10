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
import math


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    def __str__(self):
        return f"v: {self.val}, l: {self.left}, r: {self.right} end\n"

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
        if root is None:
            return ""
        accum = []
        self.serializeR(accum,[root])
        res = ",".join(list(map(lambda x: str(x.val) if x is not None else "None", accum)))
        print(f"res is {res}")
        return res
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        

    def deserialize(self, data):
        if data == '':
            return None
        data = data.split(',')
        data = list(map(lambda x: int(x) if x != "None" else None,data))
        if len(data) == 0:
            return None
        levels = int(\
            math.log(len(data)+1, 2)\
        )
        nodes = []
        for d in data:
            if d is not None:
              node = TreeNode(d)
              nodes.append(node)
            else:
              nodes.append(None)
        for l in range(levels-1):
            levelLen = 2**l
            for m in range(levelLen):
                start = levelLen - 1
                nextStart = 2**(l+1) -1
                if (nodes[start+m] is None):
                    continue
                nodes[start+m].left = nodes[nextStart+(m*2)]
                nodes[start+m].right = nodes[nextStart+(m*2)+1]
        print(f"nodes is {nodes}")
        return nodes[0]

        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        0  l= 0
        1 2 l=1
        3 4 5 6 l=2
        7... l=3
        """
        

# Your Codec object will be instantiated and called as such:
c = Codec()


n4 = TreeNode(4)
n5 = TreeNode(5)
n2 = TreeNode(2)
n3 = TreeNode(3)
n1 = TreeNode(1)
n6 = TreeNode(6)
n7 = TreeNode(7)
n1.left = n2
n1.right=n3 
n3.left=n4 
n3.right=n5
n4.left=n6 
n4.right=n7

# root = [1,2,3,null,null,4,5]
expect = [1,2,3,None,None,4,5]
test = c.serialize(n1)
print(f"test is {test}")
test2 = c.deserialize(test)
print(f"test2 is {test2}")
# print(f"expect {expect}\n {test}")
# ans = deser.deserialize(ser.serialize(root))
# depth of tree n is len((2**n) - 1)
# log test 
print(f"math.log(2) {math.log(7,2)}")