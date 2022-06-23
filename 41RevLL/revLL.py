# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def __str__(self):
        return f"val:{self.val}, next: {self.next}"

from typing import Optional


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None: 
            return None
        if head.next is None:
            return head 
        
        prev = None 
        newHead = None 
        while head is not None:
          # " break off " head 
          tail = head.next
          ntail = newHead
          if newHead is None:
            newHead = head
            newHead.next = None
          else:
            head.next = None
            newHead = head 
            newHead.next = ntail
          head = tail
        return newHead 

"""
1,2,3
1 
2,3 

2,1
3
3,2,1
"""
n2 = ListNode(3)
n1 = ListNode(2,n2)
n0 = ListNode(1,n1)
sol = Solution()
print(f"expect something {sol.reverseList(n0)}")
