# Definition for singly-linked list.
from typing import Optional


class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        la = 1
        head = headA
        while head.next is not None:
            la += 1
            head = head.next
        lb = 1
        head = headB
        while head.next is not None:
            lb += 1
            head = head.next
        print(f"la is {la} lb is {lb}")
        


s = Solution()
a1 = ListNode(4)
a2 = ListNode(1)
a1.next = a2 


b1 = ListNode(5)
b2 = ListNode(6)
b3 = ListNode(1)

b1.next = b2
b2.next = b3


c4 = ListNode(8)
c5 = ListNode(4)
c6 = ListNode(5)
b3.next = c4
a2.next = c4
c4.next = c5
c5.next = c6

print(f"expect 8 {s.getIntersectionNode(a1, b1)}")