/*

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.


Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False


Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.


Follow-up: Can you implement the stack using only one queue?

*/

#include <iostream>
#include <queue> // push, pop, front, empty
using namespace std;

class MyStack {
private:
  queue<int> a; // a is always the "stack"
  queue<int> b;
  int queue_count = 0;
  bool top_is_b;
  void reorg() {
    // empty
  };

public:
    MyStack() { top_is_b = false; }

    void push(int x) {
      queue<int> *t = top_is_b ? &b:&a;
      if (queue_count == 0) {
        t->push(x);
        ++queue_count;
        return;
      }

      int top = t->front();
      t->pop();
      queue<int> *q = top_is_b ? &a:&b;
      q->push(top);
      t->push(x);
      ++queue_count;
    }

    int pop() {
      queue<int> *t = top_is_b ? &b:&a;
      queue<int> *q = top_is_b ? &a:&b;
      int returned = t->front();
      t->pop();
      // make new top
      --queue_count;
      while (queue_count != 1) {
        --queue_count;
        t->push(q->front());
        q->pop();
      }
      top_is_b = !top_is_b;
      return returned;
    }

    int top() {
      return top_is_b ? b.front():a.front();
    }

    bool empty() {
      return a.empty() && b.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */