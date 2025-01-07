/*

109. Convert Sorted List to Binary Search Tree
Medium
Topics
Companies
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a
height-balanced
 binary search tree.



Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []


Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105
Seen this question in a real interview before?
1/5
Yes
No
Accepted
574.4K
Submissions
904.4K
Acceptance Rate
63.5%

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
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }

use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn r(v:Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
      if v.is_empty() { return None }

      let mid = v.len() / 2;
      let root = Rc::new(RefCell::new(TreeNode::new(v[mid])));

      root.borrow_mut().left = Solution::r(v[..mid].to_vec());
      root.borrow_mut().right = Solution::r(v[mid+1..].to_vec());
      Some(root)
    }
    /*
      In Rust, Box is a smart pointer that provides ownership of
      heap-allocated data.
    */
    pub fn sorted_list_to_bst(head: Option<Box<ListNode>>) -> Option<Rc<RefCell<TreeNode>>> {
      let mut v: Vec<i32> = vec![];
      let mut head = head;
      while let Some(h) = head {
        v.push(h.val);
        head = h.next;
      }

      Solution::r(v)
    }
}