# intro

- another Data struct, linked list
- similar to array, linear DS
- objects linked with ref field
- 2 types
  - singly and doubly linked

# singly linked list

## intro

- each node contains value and ref to next
- last node points to None
- impl in C++ with struct
- in java with class

- unlike arrays, not able to access random element in constant time.  takes O(N) time to visit element by index
- if bad perf, why useful then?
  - insert and delete operations better

## insert

1.  init new node
2. link next of cur to prev's next
3. link next in prev to cur

- better than array b/c we don't need to shift all items over in memory
- O(1) complexity (if you don't count searching for prev and next)

## delete

want to delete cur
1.  find cur's previous node and next
2.  link prev to cur's next

delete complexity O(N)

space complexity only O(1)

