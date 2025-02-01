/*

147. Insertion Sort List
Medium
Topics
Companies
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.




Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]


Constraints:

The number of nodes in the list is in the range [1, 5000].
-5000 <= Node.val <= 5000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
408.8K
Submissions
736.2K
Acceptance Rate
55.5%

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
  pub fn insertion_sort_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut cur_head = head.clone();
    let mut prev: Option<Box<ListNode>> = None;
    while cur_head != None { // for each

      if let Some(ch) = cur_head {
        // get next
        let nxt = ch.next;
        let v = ch.val;
        // find spot for cur_head
        let mut insert_head = head.clone();
        if let Some(ih) = insert_head {
          if
        }
      }

    }

  }
}

// *4 2 1 3
// 2 *4 1 3
// 1 2 *4 3
// 1 2 3 *4