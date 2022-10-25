"""
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.



Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]


Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def __str__(self):
      return f"val is {self.val} next {self.next}"

from typing import Optional


class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
          return None

        oddshead = ListNode(val=head.val)
        oddsptr = oddshead
        if head.next is None:
          return head
        evenshead = ListNode(val=head.next.val)
        evenptr = evenshead
        curptr = head.next.next
        even = False
        while curptr is not None:
          newptr = ListNode(curptr.val)
          if even:
            evenptr.next = newptr
            evenptr = newptr
          else:
            oddsptr.next = newptr
            oddsptr = newptr
          curptr = curptr.next
          even = not even
        oddsptr.next = evenshead
        return oddshead
