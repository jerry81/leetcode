
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
        nodes.append(r.val)
        if r.left is not None:
          newroots.append(r.left)
        if r.right is not None:
          newroots.append(r.right)
      self.flattenNodes(nodes,newroots)

    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        # first enumerate as flat list
        nodes = []
        self.flattenNodes(nodes,root)
        print(f"nodes is now {nodes}")