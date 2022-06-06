# Definition for singly-linked list.
from typing import Optional


class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    lookup = {}
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        self.lookup[headA.val] = True
        nA = headA.next
        idx = 0
        while nA is not None:
            self.lookup[nA.val] = idx
            nA = nA.next
            idx+=1
        head = headB
        idxs = []
        lookup2 = {}
        while head is not None:
          try:
              i = self.lookup[head.val]
              idxs.append(i)
              lookup2[i] = head
              head = head.next 
          except: 
              head = head.next
        if len(idxs) > 0:
            return lookup2[min(idxs)]
        return None
        


s = Solution()
a1 = ListNode(4)
a2 = ListNode(1)
a3 = ListNode(8)
a4 = ListNode(4)
a5 = ListNode(5)
a1.next = a2 
a2.next = a3 
a3.next = a4
a4.next = a5

b1 = ListNode(5)
b2 = ListNode(6)
b3 = ListNode(1)
b4 = ListNode(8)
b5 = ListNode(4)
b6 = ListNode(5)
b1.next = b2
b2.next = b3
b3.next = b4
b4.next = b5
b5.next = b6

print(f"expect 8 {s.getIntersectionNode(a1, b1)}")