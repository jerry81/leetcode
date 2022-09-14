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
