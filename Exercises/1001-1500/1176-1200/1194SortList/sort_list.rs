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

    let mut head = head;
    let mut head_clone = head.clone();
    let mut slow = &mut head;
    let mut fast = &mut head_clone;
    if fast.is_some() && fast.as_ref().unwrap().next.is_some() {
      fast = &mut fast.as_mut().unwrap().next.as_mut().unwrap().next;
    }
    // only have to go until fast reaches end
    /*
      ref creates ref without taking ownership
    */
    while fast.is_some() && fast.as_ref().unwrap().next.is_some() {
      slow = &mut slow.as_mut().unwrap().next;
      fast = &mut fast.as_mut().unwrap().next.as_mut().unwrap().next;
    }
    let mut second_half = slow.as_mut().unwrap().next.take();
    (head, second_half)
  }
  fn merge_lists(head1:Option<Box<ListNode>>, head2: Option<Box<ListNode>>) ->  Option<Box<ListNode>> {
    let mut dummy = ListNode::new(0); // create a node
    let mut tail = &mut dummy;
    let mut head1 = head1;
    let mut head2 = head2;
    while head1.is_some() && head2.is_some() {
        if head1.as_ref().unwrap().val < head2.as_ref().unwrap().val {
            tail.next = head1.take();
            tail = tail.next.as_mut().unwrap();
            head1 = tail.next.take();
        } else {
            tail.next = head2.take();
            tail = tail.next.as_mut().unwrap();
            head2 = tail.next.take();
        }
    }

    if head1.is_some() {
        tail.next = head1;
    } else {
        tail.next = head2;
    }

    dummy.next
  }

  pub fn sort_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    if head.is_none() || head.as_ref().unwrap().next.is_none() {
      return head;
    }
    let (first,second) = Solution::split_list(head);

    let sorted_first = Solution::sort_list(first);
    let sorted_second = Solution::sort_list(second);

    Solution::merge_lists(sorted_first,sorted_second)
  }
}