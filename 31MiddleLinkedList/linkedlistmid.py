from collections import defaultdict
from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next



class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        nodes = defaultdict(lambda: -1)
        nodes[0] = head
        idx = 0
        while head.next is not None:
            head = head.next
            idx += 1
            nodes[idx] = head
        mid = (idx // 2) 
        return nodes[mid+1] if ((idx+1) % 2) == 0 else nodes[mid]

