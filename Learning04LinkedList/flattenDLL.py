"""
You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.



Example 1:


Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Example 2:


Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Example 3:

Input: head = []
Output: []
Explanation: There could be empty list in the input.


Constraints:

The number of Nodes will not exceed 1000.
1 <= Node.val <= 105


How the multilevel linked list is represented in test cases:

We use the multilevel linked list from Example 1 above:

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
The serialization of each level is as follows:

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
To serialize all levels together, we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

[1,    2,    3, 4, 5, 6, null]
             |
[null, null, 7,    8, 9, 10, null]
                   |
[            null, 11, 12, null]
Merging the serialization of each level and removing trailing nulls we obtain:

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
"""

"""
# Definition for a Node.
"""
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


from typing import Optional


class Solution:
    def flattenR(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
          return None

        if head.child is not None:
          # flatten child, return tail
          # connect head to child, and return value to original next
          nxt = head.next
          head.next = head.child
          head.child = None
          head.next.prev = head
          tail = self.flattenR(head.child)
          if tail is not None:
            tail.next = self.flattenR(nxt)
            if nxt is not None:
              nxt.prev = tail
        elif head.next is not None:
          # move pointer
          return self.flattenR(head.next)
        else:
          return head


    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
          return None

        self.flattenR(head)
        return head


"""
current results:
[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Your answer
The linked list [1,2,3,7,8,9,10] is not a valid doubly linked list.
Expected answer
[1,2,3,7,8,11,12,9,10,4,5,6]
"""