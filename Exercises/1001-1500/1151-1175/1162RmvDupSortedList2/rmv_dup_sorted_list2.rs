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
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
  fn r(root: Option<Rc<RefCell<TreeNode>>>, v: &mut Vec<i32>) {
      if let Some(rt) = root {
        v.push(rt.borrow().val);
        Solution::r(rt.borrow().left.clone(), v);
        Solution::r(rt.borrow().right.clone(), v);
      }
  }
  pub fn flatten(root: &mut Option<Rc<RefCell<TreeNode>>>) {
      let mut v: Vec<i32> = Vec::new();
      Solution::r(root.clone(), &mut v);

      if v.is_empty() { return None; }

      let mut new_root: Option<Rc<RefCell<TreeNode>>> = Some(Rc::new(RefCell::new(TreeNode::new(v[0]))));
      let mut tail = &mut new_root;
      for i in 1..v.len() {
        *tail.right = Some(Rc::new(RefCell::new(TreeNode::new(v[i]))));
        *tail = tail.right;
      }
      *root = new_root;
  }
}