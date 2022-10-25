# heap

## introduction

- only preview available for free

## definition - priority queue

- like queue in which each element also has "priority" associated with it

- heap is not exactly the same as priority queue.  PQ is abstract data type, heap is DS.  Heap implements priority queue

- PQ implemented with array or linked list has O(N) complexity.  Heap impl has O(log N)

## definition heap

- special type of binary tree
- is complete bin tree
- each node greater or less than child nodes, so sorted.
- insertion log N
- deletion log N
- getMin/Max O(1)

## classification

- min or max heap
- min/max val is at top

## insertion

- log n operation
- first insert into first available slot
- swap with its parent until min/max heap rule is fulfilled

## deletion

- goal: remove "top" item from heap
- first detect if heap is min or max heap
- move bottom right item to top, delete top item
- swap the new top down until min/max heap rule is fulfilled

## binary tree -> array

- number items of tree from root, moving left to right, top to bottom
- these indexes match the array indexes
- get parents with n/2 (integer division)
- left child n*2, right child n*2+1