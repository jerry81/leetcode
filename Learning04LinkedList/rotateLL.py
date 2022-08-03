"""
Given the head of a linked list, rotate the list to the right by k places.



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]


Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from collections import defaultdict
from typing import Optional


class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        l = 0
        lookup = defaultdict(lambda: None)
        if head is None: return None

        while head is not None:
          lookup[l] = head
          l+=1
          head = head.next
        if k > l: k = k%l

        lookup[k].next = None
        lookup[l-1].next = lookup[0]
        return lookup[l - k]

"""
no wraparounds (k < len)
len - 1 - k becomes new head
len - 1 next is old head
k next becomes none

wraparounds (k > len)
k becomes len%k
repeat above
"""