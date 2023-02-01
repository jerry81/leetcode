# Principle of Recursion

- approach to solving problems using a function that calls itself as subroutine
- avoid infinite loop by
  - ensuring base case that terminates the loop
  - move towards the base case
  - could be multiple places that function calls itslef

- example: reverse string

# Recursion Function

1.  break problem into smaller scopes
2.  call fn recursively to solve subproblems
3.  process results from recursive functions to solve problem

- example - given linked list, swap every two adjacent nodes and return to head
  -  1.2.3.4 -> 2.1.4.3
  - algorithm
    1.  define swap(head) - this returns head of new linked list
    2. swap first 2 nodes
    3.  call function again on next.next
    4.  attach returned head to sublist in step 2