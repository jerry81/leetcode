# Definition for singly-linked list.
from collections import defaultdict
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        nodes = defaultdict(lambda: -1)
        nodes[0] = head
        idx = 0
        while head.next is not None:
            head = head.next
            idx+=1
            nodes[idx] = head

        # remove 
        removedIdx = (idx - n) + 1
        if (removedIdx - 1) == 0:
          return nodes[1]
        nodes[removedIdx-1].next = nodes[removedIdx+1] if nodes[removedIdx+1] != -1 else None
        # handle edge case 
        return nodes[0]