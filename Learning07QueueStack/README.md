# Queue and Stack

## intro

- like array but restricted processing order
- fifo and lifo
1.  principles
2.  implementation
3.  structure
4.  queue problems
5.  stack problems
6.  stack for DFS and recursion

## Queue: FIFO

### basics
- front, back, enqueue, dequeue

### impl
- use dynamic array and index pointing to head (tail not needed)
- two operations enqueue and dequeue
```cpp
#include <iostream>

class MyQueue {
    private:
        // store elements
        vector<int> data;
        // a pointer to indicate the start position
        int p_start;
    public:
        MyQueue() {p_start = 0;}
        /** Insert an element into the queue. Return true if the operation is successful. */
        bool enQueue(int x) {
            data.push_back(x);
            return true;
        }
        /** Delete an element from the queue. Return true if the operation is successful. */
        bool deQueue() {
            if (isEmpty()) {
                return false;
            }
            p_start++;
            return true;
        };
        /** Get the front item from the queue. */
        int Front() {
            return data[p_start];
        };
        /** Checks whether the queue is empty or not. */
        bool isEmpty()  {
            return p_start >= data.size();
        }
};

int main() {
    MyQueue q;
    q.enQueue(5);
    q.enQueue(3);
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
    q.deQueue();
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
    q.deQueue();
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
}
```

- above inefficient because space wasted with dequeues

## circular queue

- solve the above inefficiency with circular queue
- fixed size array, two pointers (add the ending position)
- goal to reuse wasted storage

## Queue and BFS

- BFS application: shortest path from root to target
- process neightbors
- uses queue
- enqueue root first
- enqueue neighbors
- dequeue after adding neighbors

## BFS template

- two templates provided, one that checks for visited (visit at most once)
- one checks for visited (to prevent infinite loops)
  - inf loop could be due to graph with cycle or bidirectional edges

## Stack

- LIFO
- easier to implement than queue
- dynamic array is enough.  c++ vector is perfect to impl stack
- c++ also has built in stack
```cpp
stack<int> a;
a.push(5);
a.empty();
a.pop();
a.top();
a.size();
```
## stack and DFS

- dfs find deepest path first
- involves backtracking
- backtracking goes in reverse order that nodes were added, so stack is suitable
- keeping track of visited is key, as usual
- 2 methods, recursion (call stack), or iteration (user maintained stack)

- DFS pseudocode template
```
/*
 * Return true if there is a path from cur to target.
 */
boolean DFS(Node cur, Node target, Set<Node> visited) {
    return true if cur is target;
    for (next : each neighbor of cur) {
        if (next is not in visited) {
            add next to visted;
            return true if DFS(next, target, visited) == true;
        }
    }
    return false;
}
```

- using new vs not using new in C++
[ref](https://stackoverflow.com/questions/655065/when-should-i-use-the-new-keyword-in-c)
- new uses heap aka free store, which consumes less resources
- no new uses stack

- DFS without recursion

```
/*
 * Return true if there is a path from cur to target.
 */
boolean DFS(int root, int target) {
    Set<Node> visited;
    Stack<Node> stack;
    add root to stack;
    while (stack is not empty) {
        Node cur = the top element in stack;
        remove the cur from the stack;
        return true if cur is target;
        for (Node next : the neighbors of cur) {
            if (next is not in visited) {
                add next to visited;
                add next to stack;
            }
        }
    }
    return false;
}
```