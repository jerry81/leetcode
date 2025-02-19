/*


173. Binary Search Tree Iterator
Medium
Topics
Companies
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.



Example 1:


Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False


Constraints:

The number of nodes in the tree is in the range [1, 105].
0 <= Node.val <= 106
At most 105 calls will be made to hasNext, and next.


Follow up:

Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?
Seen this question in a real interview before?
1/5
Yes
No
Accepted
909.7K
Submissions
1.2M
Acceptance Rate
74.1%

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

use std::rc::Rc; // reference counting - smart ptr
use std::cell::RefCell; // ref cell - interior mutability

struct BSTIterator {
  values: Vec<i32>,
  idx: usize,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */



impl BSTIterator {
    fn create(root: Option<Rc<RefCell<TreeNode>>>, v: &mut Vec<i32>) {
      if let Some(r) = root {
        Self::create(r.borrow().left.clone(),v);
        v.push(r.borrow().val);
        Self::create(r.borrow().right.clone(),v);
      }
    }
    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut v: &mut Vec<i32> = &mut Vec::<i32>::new();
        Self::create(root,v);
        BSTIterator {
            values: v.clone(),
            idx:0
        }

    }

    fn next(&mut self) -> i32 {
        let res = self.values[self.idx as usize];
        self.idx+=1;
        res
    }

    fn has_next(&mut self) -> bool {
        self.idx < self.values.len()
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * let obj = BSTIterator::new(root);
 * let ret_1: i32 = obj.next();
 * let ret_2: bool = obj.has_next();
 */