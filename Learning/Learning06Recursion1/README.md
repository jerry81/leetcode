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

# time comlexity

- number of recursions * time complexity of calculation

# space complexity

- two parts
  - recursion related
    - stack to keep track of recursive function calls.
      - 3 pts of info
        - returning address of the function call
        - params passed to function call
        - local vars in function call
  - non-recursion related
    - space for global vars
    - space for memoization

# tail recursion
  - recursion where recursive call is final instruction and there is only one recursive call in fn
  - tail recursion doesn't have the space overhead

  - code snippet for comparison
  ```java
  public class Main {

  private static int helper_non_tail_recursion(int start, int [] ls) { // less params
    if (start >= ls.length) {
      return 0; // diff
    }
    // not a tail recursion because it does some computation after the recursive call returned.
    return ls[start] + helper_non_tail_recursion(start+1, ls); // the appending happens outside of the call.
  }

  public static int sum_non_tail_recursion(int [] ls) {
    if (ls == null || ls.length == 0) {
      return 0;
    }
    return helper_non_tail_recursion(0, ls);
  }

  //---------------------------------------------

  private static int helper_tail_recursion(int start, int [] ls, int acc) { // extra param
    if (start >= ls.length) {
      return acc; // diff
    }
    // this is a tail recursion because the final instruction is the recursive call.
    return helper_tail_recursion(start+1, ls, acc+ls[start]); // the appending is within the parameters
  }

  public static int sum_tail_recursion(int [] ls) {
    if (ls == null || ls.length == 0) {
      return 0;
    }
    return helper_tail_recursion(0, ls, 0);
  }
}
```

- so when comparing, when there is an accumulator being passed around, it is tail recursion.

