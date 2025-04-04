/*
113. Path Sum II
Medium
Topics
Companies
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.



Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
955.5K
Submissions
1.6M
Acceptance Rate
59.7%
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
    fn is_leaf(node: Option<Rc<RefCell<TreeNode>>>) -> bool {
        if let Some(n) = node {
          if let Some(l) = n.borrow().left.clone() {
            return false
          }
          if let Some(r) = n.borrow().right.clone() {
            return false
          }
          true
        } else {
            false
        }
    }
    fn backtrack(root: Option<Rc<RefCell<TreeNode>>>, target_sum:i32, current_sum:i32, results: &mut Vec<Vec<i32>>, cur: Vec<i32>) {
      if let Some(r) = root.clone() {
        let v = r.borrow().val;
        let next_sum = current_sum+v;
        let mut nxt_cur = cur.clone();
        nxt_cur.push(v);
        if next_sum == target_sum && Solution::is_leaf(root.clone()) {
          results.push(nxt_cur.clone());
        }
        Solution::backtrack(r.borrow().left.clone(), target_sum, next_sum, results, nxt_cur.clone());
        Solution::backtrack(r.borrow().right.clone(),target_sum, next_sum, results, nxt_cur.clone());

      }
    }
    pub fn path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> Vec<Vec<i32>> {
      let mut res: Vec<Vec<i32>> = vec![];
      Solution::backtrack(root, target_sum, 0, &mut res, vec![]);
      res
    }
}