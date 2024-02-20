/*

232. Implement Queue using Stacks
Solved
Easy
Topics
Companies
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.


Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false


Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.


Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

Seen this question in a real interview before?
1/4
Yes
No
Accepted
792.8K
Submissions
1.2M
Acceptance Rate
64.6%

*/
use std::cell::RefCell;
/*
q.  what's up with cells?
a.  stdlib, for "interior mutability"
allow mutate data even when immutably borrowed
Cell is for types that implement Copy() like integers and characters
- has methods to get and set value
Cell gives getters and setters
RefCell is for more complex like Vec
provides borrow_mut
overtime is runtime checks for borrowing rules
*/

struct MyQueue {
  stk1: RefCell<Vec<i32>>,
  stk2: RefCell<Vec<i32>>
}
/*
  Q.  why are struct and impl seperated?
  A.  definition (struct) and implementation of methods are separated by design
  - struct focuses on fields
  - impl concentrates on methods
  - traits implemented yet elsewhere (another topic for another day)
  Q.  common to seperate to different files?
  A.  doesn't seem like it
*/

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {

    fn new() -> Self {
      MyQueue { // also constructor
        stk1: RefCell::new(Vec::new()),  // refcell decl
        stk2: RefCell::new(Vec::new())
      }
    }

    fn push(&self, x: i32) {
      let mut stk1_borrow = self.stk1.borrow_mut();
      stk1_borrow.push(x);
    }

    /*
      Q. whats up with passing self in on each method?
      A.  make explicit that its working on struct of type defined by self
    */

    fn pop(&self) -> i32 {
        let mut stk1_borrow = self.stk1.borrow_mut();
        let mut stk2_borrow = self.stk2.borrow_mut();
      while !stk1_borrow.is_empty() {
        stk2_borrow.push(stk1_borrow.pop().unwrap());
      }
      let res = stk2_borrow.pop().unwrap();
      while !stk2_borrow.is_empty() {
        stk1_borrow.push(stk2_borrow.pop().unwrap());
      }
      res
    }

    fn peek(&self) -> i32 {
      let mut stk1_borrow = self.stk1.borrow_mut();
      let mut stk2_borrow = self.stk2.borrow_mut();

      // Transfer elements from stk1 to stk2
      while !stk1_borrow.is_empty() {
        stk2_borrow.push(stk1_borrow.pop().unwrap());
      }

      let res = stk2_borrow.last().cloned().unwrap(); // cloned, not clone - avoids borrowing from stk2_borrow - clone involves full ownership transfer

      // Drop mutable borrow on stk2_borrow
      drop(stk2_borrow);

      // Transfer elements back from stk2 to stk1
      while !self.stk2.borrow().is_empty() {
        stk1_borrow.push(self.stk2.borrow_mut().pop().unwrap());
      }

      res
    }

    fn empty(&self) -> bool {
      self.stk1.borrow().is_empty() && self.stk2.borrow().is_empty()
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.peek();
 * let ret_4: bool = obj.empty();
 */