
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


from typing import Optional


class Solution:
    def flattenNodes(self,nodes,roots):
      # bfs
      newroots = []
      if len(roots) == 0:
        return
      for r in roots:
        nodes.append(r)
        if r.left is not None:
          newroots.append(r.left)
        if r.right is not None:
          newroots.append(r.right)
      self.flattenNodes(nodes,newroots)

    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if root is None:
            return None
        # first enumerate as flat list
        nodes = []
        self.flattenNodes(nodes,[root])
        curE = 0
        count = 0
        for i in range(len(nodes)):
            if (2**curE)-1 != count:
                nodes[i].next = nodes[i+1]
                count+=1
            else: 
                curE+=1
                count = 0
        return nodes[0]


        

    # example 
    # 1,2,3,4,5,6,7
    # 1, 2,3,  4,5,6,7, 8,9,10,11,12,13,14,15
    