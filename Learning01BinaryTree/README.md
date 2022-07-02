# intro
- tree - frequently used data struct
  - node has root value and ref to children
  - is a type of directed acyclic graph
  - n nodes, n-1 edges 
- binary tree - at most 2 children, left and right

# traversal 
- pre-order traversal - first visit root then left then right
```
        F
    B       G
  A   D       I
     C E     H
```
- gets traversed in order
- FBADCEGIH

- in order traveral, left root right
- with same example as above 
- ABCDEFGHI

- post-order traversal, left right root
- ACEDBHIGF
  - advantage: used in mathematical expression
  - used for deletion process 
