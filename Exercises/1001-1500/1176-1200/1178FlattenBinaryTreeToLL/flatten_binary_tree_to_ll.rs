/*
114. Flatten Binary Tree to Linked List
Medium
Topics
Companies
Hint
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.


Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100


Follow up: Can you flatten the tree in-place (with O(1) extra space)?
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1.1M
Submissions
1.6M
Acceptance Rate
67.2%
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

      if v.is_empty() {
        *root = None;
        return
      }

      let mut new_root: Option<Rc<RefCell<TreeNode>>> = Some(Rc::new(RefCell::new(TreeNode::new(v[0]))));
      let mut tail = new_root.clone();
      for i in 1..v.len() {
        let mut nxt: Option<Rc<RefCell<TreeNode>>> = Some(Rc::new(RefCell::new(TreeNode::new(v[i]))));
        if let Some(t) = tail {
            t.borrow_mut().right = nxt.clone(); // set t, borrow mut , right to clone
        }
        tail = nxt; // set tail
      }
      *root = new_root;
  }
}