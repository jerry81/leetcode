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

# Recurrence Relation

- recurrence relation: relationship between result of problem and result of its subproblems
- base case: case where one can compute answer directly without further recursion calls.  aka bottom cases
- example pascal's triangle
  - recurrence rel: f(i,j) = f(i-1, j-1) + f(i-1,j) <-- these will reduce down to j=1 eventually
  - base case f(i,j) =  where j = 1 or j = i

note:  there are many duplicate calculations happening - avoid dups w/ memoization (next)


# memoization

- example - in pascal's triangle, there are many duplicate calculations.  use a hash to find those solutions in o(1) time.

