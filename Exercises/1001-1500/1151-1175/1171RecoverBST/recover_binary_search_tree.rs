/*
99. Recover Binary Search Tree
Medium
Topics
Companies
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.



Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.


Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1


Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
Seen this question in a real interview before?
1/5
Yes
No
Accepted
505.6K
Submissions
919.7K
Acceptance Rate
55.0%
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
use std::collections::HashMap;
impl Solution {
  fn traverse(root: &mut Option<Rc<RefCell<TreeNode>>>, parents: &mut HashMap<i32, (Option<Rc<RefCell<TreeNode>>>, bool)>) {
    if let Some(r) = root {
      let b = r.borrow();
      let l = b.left;
      let ri = b.right;
    }
  }

  pub fn recover_tree(root: &mut Option<Rc<RefCell<TreeNode>>>) {
    let mut parents: HashMap<i32, (Option<Rc<RefCell<TreeNode>>>, bool)> = HashMap::new();
    if let Some(r) = root {
      let b = r.borrow();
      *parents.entry(b.val).or_insert((None, false)) = (None,false);
    }
    Self::traverse(root, &mut parents);
  }

}