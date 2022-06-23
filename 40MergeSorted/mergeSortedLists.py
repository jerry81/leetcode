# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
from typing import Optional


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        newHead = None
        headPtr = None 
        head1 = list1
        head2 = list2
        while True:
          if head1 is None:
              if head2 is None:
                  return None 
              else:
                  if newHead is None:
                    newHead = head2 
                    headPtr = newHead 
                  else:
                    newHead.next = head2 
                  return headPtr 
          if head2 is None:
            if newHead is None:
                newHead = head1 
                headPtr = newHead 
            else:
                newHead.next = head1 
                return headPtr  

          head1Rest = head1.next 
          head2Rest = head2.next 
          if head1.val <= head2.val:
            newHead = head1
            newHead.next = None
            head1 = head1Rest 
          else:
            newHead = head2
            newHead.next = None 
            head2 = head2Rest 
          if headPtr is None:
            headPtr = newHead 
        
"""
list1 = [1,2,4], list2 = [1,3,4]
res = [1,1,2,3,4,4]

1 2 4
1 3 4 

detach
1 
2 4 
1 
3 4 

pick 1 or 1
1, 1 
2 4 
3 4 
detach
2
3
4
4
"""