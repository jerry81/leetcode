/*

501. Find Mode in Binary Search Tree
Easy
3.1K
686
Companies
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:


Input: root = [1,null,2,2]
Output: [2]
Example 2:

Input: root = [0]
Output: [0]


Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105


Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
Accepted
211.9K
Submissions
417.6K
Acceptance Rate
50.7%

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

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}
impl TreeNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    TreeNode {
      val,
      left: None,
      right: None
    }
  }
}

use std::rc::Rc; // reference counting - smart ptr
use std::cell::RefCell; // ref cell - interior mutability
use std::collections::HashMap;
impl Solution {
    pub fn find_mode(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> { // Option -> Some or None
      let mut ret = Vec::new();
      let mut freq:HashMap<i32,i32> = HashMap::new();
      Solution::r(&root, &mut freq);
      let mut v: Vec<_> = freq.iter().collect(); // hm to vec
      v.sort_by(|a,b| b.1.cmp(&a.1));
      let mut mx = v[0].1;
      for (k,val) in v {
        if val == mx {
          ret.push(*k);
        }
      }
      ret
    }

    fn r(root: &Option<Rc<RefCell<TreeNode>>>, freq: &mut HashMap<i32, i32>) {
      if root.is_none() {
        return;
      }

      let borrowed = root.unwrap().borrow(); // unwrap for refcell/rc or option?
      let value = borrowed.val;
      *freq.entry(value).or_insert(0) += 1;
      Solution::r(&borrowed.left, freq);
      Solution::r(&borrowed.right, freq);
    }
}

/*

freq hashmap
dfs with recursive fn

*/