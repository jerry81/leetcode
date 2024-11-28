/*
82. Remove Duplicates from Sorted List II
Medium
Topics
Companies
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.



Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]


Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

Seen this question in a real interview before?
1/5
Yes
No
Accepted
828.8K
Submissions
1.7M
Acceptance Rate
48.7%
*/

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::collections::HashSet;
impl Solution {
  pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    // no constraints on memory, so just build another one with aid of hashset
    let mut seen: HashSet<i32> = HashSet::new();
    let mut dups: HashSet<i32> = HashSet::new();
    let mut res: Option<Box<ListNode>> = None;
    let mut cur = head.clone();
    while let Some(mut n) = cur {
      if seen.contains(&n.val) {
        dups.insert(n.val);
      } else {
        seen.insert(n.val);
      }
      cur = n.next;
    }
    cur = head.clone();
    let mut tail = &mut res;
    while let Some(mut n) = cur {
      if !dups.contains(&n.val){
        let new_node = Some(Box::new(ListNode::new(n.val)));
        *tail = new_node;
        tail = &mut tail.as_mut().unwrap().next;
      }
      cur = n.next.take();
    }

    res
  }
}