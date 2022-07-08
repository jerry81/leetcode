"""
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:


Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 6000].
-100 <= Node.val <= 100
 

Follow-up:

You may only use constant extra space.
The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
"""

# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
    def __str__(self):
        print(f"val {self.val}")

class Solution:
    def flattenNodes(self,nodes,roots):
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
      self.flattenNodes(nodes,newroots)

    def connect(self, root: Node) -> Node:
        if root is None:
            return None
        # first enumerate as flat list
        nodes = []
        self.flattenNodes(nodes,[root])
        for n in nodes:
            if n is not None:
              print(n.val)
            else:
              print('NONE')
        curE = 0
        count = 0
        for i in range(len(nodes)):
            if (2**curE)-1 != count:
                if nodes[i] is not None:
                  nodes[i].next = nodes[i+1]
                count+=1
            else: 
                curE+=1
                count = 0
        return nodes[0]
    
s=Solution()


n7 = Node(7)
n5 = Node(5)
n4 = Node(4)

n2 = Node(2,n4,n5)
n3 = Node(3, right=n7)
n1 = Node(1,n2,n3)

s.connect(n1)
""" 
[1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
"""