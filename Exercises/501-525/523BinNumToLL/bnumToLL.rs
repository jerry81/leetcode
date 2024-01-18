/*

1290. Convert Binary Number in a Linked List to Integer
Easy
Topics
Companies
Hint
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.



Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0


Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
440.5K
Submissions
542.1K
Acceptance Rate
81.3%

*/

// Definition for singly-linked list.


#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}
impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}
impl Solution {
  pub fn get_decimal_value(head: Option<Box<ListNode>>) -> i32 { // box is for memory allocation onto heap
    let mut lst:Vec<i32> = Vec::new();
    let mut h = head;
    loop {
      match h {
        Some(boxed_node) => {
          lst.push((*boxed_node).val);
          h = (*boxed_node).next;
        }
        None => {
          println!("head is nun");
          break;
        }
      }
    }
    let mut res = 0;
    let mut pwr = 0;
    for i in lst.len()-1..=0 {
      if lst[i] == 1 {
        res+=2^pwr;
      }
      pwr+=1;
    }
    res
  }
}