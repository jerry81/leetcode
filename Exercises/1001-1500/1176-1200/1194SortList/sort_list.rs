/*

148. Sort List
Medium
Topics
Companies
Given the head of a linked list, return the list after sorting it in ascending order.



Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105


Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

Seen this question in a real interview before?
1/5
Yes
No
Accepted
955.6K
Submissions
1.6M
Acceptance Rate
60.6%

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
impl Solution {
  fn split_list(head:Option<Box<ListNode>>) -> (Option<Box<ListNode>>,Option<Box<ListNode>>) {
    if head.is_none() { // x.is_none() is same as x == None
      return (None, None);
    }
    let mut slow = head.clone();
    let mut fast = head.clone();
    let mut prev = None;
    // only have to go until fast reaches end
    /*
      ref creates ref without taking ownership
    */
    while let Some(ref fast_node) = fast {
      if let Some(ref next_fast_node) = fast_node.next { // checking next for None
        prev = slow.clone();
        slow = slow.unwrap().next.clone();
        fast = next_fast_node.next.clone();
      } else {
        break;
      }
    }
    if let Some(ref mut prev_node) = prev {
      prev_node.next = None;
    }
    (head, slow)
  }

  fn merge_lists(head1:Option<Box<ListNode>>, head2: Option<Box<ListNode>>) {
  }
  pub fn sort_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let (mut first,mut second) = Solution::split_list(head);
    println!("first");
    while !first.clone().is_none() {
      println!("{}", first.clone().unwrap().val);
      first=first.unwrap().next;
    }
    println!("second");
    while !second.clone().is_none() {
      println!("{}", second.clone().unwrap().val);
      second=second.unwrap().next;
    }
    None
  }
}