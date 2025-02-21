/*
1261. Find Elements in a Contaminated Binary Tree
Medium
Topics
Companies
Hint
Given a binary tree with the following rules:

root.val == 0
For any treeNode:
If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

Implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
bool find(int target) Returns true if the target value exists in the recovered binary tree.


Example 1:


Input
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1]);
findElements.find(1); // return False
findElements.find(2); // return True
Example 2:


Input
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
Example 3:


Input
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
Output
[null,true,false,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True


Constraints:

TreeNode.val == -1
The height of the binary tree is less than or equal to 20
The total number of nodes is between [1, 104]
Total calls of find() is between [1, 104]
0 <= target <= 106
Seen this question in a real interview before?
1/5
Yes
No
Accepted
78.6K
Submissions
99.5K
Acceptance Rate
79.0%
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

struct FindElements {
  root: Option<Rc<RefCell<TreeNode>>>
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FindElements {
    fn build(root: &mut Option<Rc<RefCell<TreeNode>>>) {
      if let Some(node) = root {
          let mut node_ref = node.borrow_mut();

          let mut curval = node_ref.val;
          if let Some(l) = node_ref.left.as_mut() { // TIL asmut - used with Option - get mutable ref to value inside of option if it exists
            l.borrow_mut().val = curval * 2 + 1;
            Self::build(&mut node_ref.left);
          }
          if let Some(r) = node_ref.right.as_mut() {
            r.borrow_mut().val = curval * 2 + 2;
            Self::build(&mut node_ref.right);
          }

      }
    }
    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
      let mut root = &mut root.clone();
      if let Some(r) = root {
        r.borrow_mut().val = 0;
        let mut root_clone = root.clone(); //
        Self::build(&mut root_clone);
      }
      FindElements {
        root: root.clone()
      }
    }
    fn find_r(root: Option<Rc<RefCell<TreeNode>>>, target: i32) -> bool {
      if let Some(r) = root {
        if r.borrow().val == target { return true }

        return Self::find_r(r.left) || Self::find_r(r.right)
      }
      false
    }
    fn find(&self, target: i32) -> bool {
      Self::find_r(self.root.clone(), target)
    }
}
/**
 * Your FindElements object will be instantiated and called as such:
 * let obj = FindElements::new(root);
 * let ret_1: bool = obj.find(target);
 */