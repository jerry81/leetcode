# disjoint set explore card

## overview

- goal is to check if two nodes are connected aka union find
- disjoint set is the data structure

## implmentation

- need array idx and value where value stores parent node
- to find a "path to root" - follow the array jumps until parent node is itself
- disjoint set 2 functions
  - find - find root by recursively walking parent until root (parent is itself)
  - union - connects two disjoint sets - connect an element to another element