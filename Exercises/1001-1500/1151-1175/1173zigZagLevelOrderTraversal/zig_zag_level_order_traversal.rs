/*


103. Binary Tree Zigzag Level Order Traversal
Medium
Topics
Companies
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1.4M
Submissions
2.2M
Acceptance Rate
60.6%

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
    pub fn zigzag_level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
      let mut stk: Vec<Option<Rc<RefCell<TreeNode>>>> = vec![root];
      let mut ltr: bool = true;
      let mut res: Vec<Vec<i32>> = vec![];
      while !stk.is_empty() {
        let mut cur_level = vec![];
        let mut nstk: Vec<Option<Rc<RefCell<TreeNode>>>> = vec![];
        while !stk.is_empty() {
          if let Some(last_item) = stk.pop() {
            cur_level.push(last_item.unwrap().val);
            if ltr {
            } else {
            }
          }
        }
        res.push(cur_level);
      }
      res
    }
}