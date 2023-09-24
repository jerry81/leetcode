# leetcode

leetcode solutions

# Algorithms

## Djikstra's

1.  Setup priority Queue table that will store weighted edges
2.  Setup distances table, initialize all nodes's distances as inf
3.  arbitrarily pick start node - mark dist as 0, insert into pq
4.  while pq not empty
  5.  Pop edge, update distance, mark as visited
  6.  for each neighboring edge, if not visited add to queue

## Find median in two arrays

 - we know the target "index" (half of all elements ish)
    - so we need to find the number that gives us that target index
    - start with nums1 midpoint (idxSum is idx of nums1's midpoint)
    - search in nums2 for this value (totalIdx is idxSum + idxFound)
    - we then repeat with our new search space depending totalIdx's value

## Find if string a is subsequence of string b

- use recursion
- base case is a empty -> return true
- search for first char in a in b
- if not found -> false
- pop a
- drop all chars before first found index in b
- r(a, b)

## champagne pouring

- simulation - this is basically a brute force application of math

# TIL

```

User
can you describe the syntax here (c++)

bool operator()(int a, int b) { return a < b; }

ChatGPT
Certainly! The code snippet you provided is an example of a function call operator overload in C++.

In C++, the operator() is a special function name that allows an object to be called as if it were a function. This feature is often used in functors or function objects, which are objects that can be treated and used as functions.

In this case, the function call operator operator() is defined within a class or struct that is not explicitly mentioned in the provided code snippet. It takes two integer parameters, a and b, and returns a boolean value (bool).

The implementation of the function simply compares the values of a and b using the less-than operator (<). It returns true if a is less than b, and false otherwise. The function acts as a binary predicate that compares two integers for a specific ordering criteria.

This function call operator can be used when an instance of the class or struct is invoked as if it were a function, such as in the following example:

SomeClass compare;
bool result = compare(10, 20);
In the above example, an instance of the class or struct containing the operator() function is created as compare. Then, the instance is called as a function with the arguments 10 and 20. The operator() function is executed, and the result is stored in the variable result.
```