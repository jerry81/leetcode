use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
  pub fn recover_tree(root: &mut Option<Rc<RefCell<TreeNode>>>) {
      let mut first: Option<Rc<RefCell<TreeNode>>> = None;
      let mut second: Option<Rc<RefCell<TreeNode>>> = None;
      let mut prev: Option<Rc<RefCell<TreeNode>>> = None;

      fn inorder_traverse(     // inner/nested  funciton
          node: Option<Rc<RefCell<TreeNode>>>,
          first: &mut Option<Rc<RefCell<TreeNode>>>,
          second: &mut Option<Rc<RefCell<TreeNode>>>,
          prev: &mut Option<Rc<RefCell<TreeNode>>>,
      ) { // inorder is just traversing left, processing then traversing right
          if let Some(n) = node {
              let n_borrowed = n.borrow();
              inorder_traverse(n_borrowed.left.clone(), first, second, prev);

              if let Some(prev_node) = prev {
                  if n_borrowed.val < prev_node.borrow().val {
                      if first.is_none() {
                          *first = Some(prev_node.clone());
                      }
                      *second = Some(n.clone());
                  }
              }
              *prev = Some(n.clone());

              inorder_traverse(n_borrowed.right.clone(), first, second, prev);
          }
      }

      inorder_traverse(root.clone(), &mut first, &mut second, &mut prev); // calls inner function with root (cloned), then none for first, second, prev

      // the following just performs the swap (done once)
      if let (Some(first_node), Some(second_node)) = (first, second) {
          let first_val = first_node.borrow().val;
          let second_val = second_node.borrow().val;

          // Swap the values of the two nodes
          first_node.borrow_mut().val = second_val; // borrow mut for directly changing the pointer's contents
          second_node.borrow_mut().val = first_val;
      }
  }
}