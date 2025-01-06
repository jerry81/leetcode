/*
107. Binary Tree Level Order Traversal II
Medium
Topics
Companies
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
699.6K
Submissions
1.1M
Acceptance Rate
65.0%
*/

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
    pub fn level_order_bottom(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
      // reverse of level order result
      let mut res: Vec<Vec<i32>> = vec![];

      let mut q: Vec<Option<Rc<RefCell<TreeNode>>>> = vec![];
      q.push(root);
      while !q.is_empty() {
        let mut nq: Vec<Option<Rc<RefCell<TreeNode>>>> = vec![];
        let mut cur_level: Vec<i32> = vec![];
        while !q.is_empty() {
          if let Some(first_item) = q.remove(0) {
            cur_level.push(first_item.borrow().val);
            nq.push(first_item.borrow().left.clone());
            nq.push(first_item.borrow().right.clone());
          }
        }
        res.push(cur_level);
        q = nq;
      }
      res
    }
}