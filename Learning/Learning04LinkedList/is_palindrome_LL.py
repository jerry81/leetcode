"""
Given the head of a singly linked list, return true if it is a palindrome.

Example 1:

Input: head = [1,2,2,1]
Output: true
Example 2:

Input: head = [1,2]
Output: false

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space?
"""

# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def __str__(self):
      return f"val is {self.val} next is {self.next}"

class Solution:
  # Definition for singly-linked list.
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
      values = []
      while head is not None:
        values.append(head.val)
        head = head.next
      print(f"values {values}")
      return values == values[::-1]