# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
from typing import Optional


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None: 
            return None
        if head.next is None:
            return head 
        
        prev = None 
        while head is not None:
          tail = head.next 
          head.next = prev  
          prev = head 
          head = tail
        return tail 