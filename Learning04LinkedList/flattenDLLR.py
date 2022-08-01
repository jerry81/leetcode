"""
recursive version of flatten doubly linked list problem (not mine)
"""


from typing import Optional

class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
    def __str__(self):
      return f"val is {self.val}"

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # he does not use any returns
        def merge(node, near):  # sub function
            if node.child == None:
                if near: merge(near, near.next)  # if and expression combined on same line
            else:
                child = node.child
                child.prev = node # prev before node makes so we don't need temp var
                node.next = child
                node.child = None
                while child.next: child = child.next # no explicit "is not None"
                child.next = near
                if near: near.prev = child
                merge(node.next, node.next.next)
        if head != None: merge(head, head.next)
        return head