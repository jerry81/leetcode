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

- Level-order traversal - traverse tree level by level
  - BFS - root, neighbors, next level repeat
  - FBGADICEH
  - implemented with queue 

# recursion

- often used to solve tree problems 
- topdown or bottom up

## top down 

- similar to preorder traversal
- visit node, do something, pass value down to children 
- pattern
1. return specific value for null node // termination 
2. update the answer if needed                      // answer <-- params
3. left_ans = top_down(root.left, left_params)      // left_params <-- root.val, params
4. right_ans = top_down(root.right, right_params)   // right_params <-- root.val, params
5. return the answer if needed                      // answer <-- left_ans, right_ans

- example, max depth of binary tree
store answer as a global var
- handle null case
- recursive(left, d+1)
- recursive(right, d+1)
if !node.left && !node.right
  update answer if d > answer 

