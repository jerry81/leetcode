# introduction

- example, friend circle

## types

- undirected
  - no direction, two way edges

- directed
  - direction edges

- weighted
  - edges have weight attached to them, representing distance, time, size, etc

## definitions

- vertex (nodes)
- edge - connections
- path - sequence of verticies from one to another
- degree (in unweighted) - number of edges connecting vertex

## disjoint set

- multiple graphs that may not be connected
- practical use: finding connectivity in components in network, i.e. computer network or social network

- introduction video
  - build independent vertexes
  - iterate through verticies
  - union on sets, merging into larger sets
  - create new sets if no intersection
  - root aka head

- implement disjoint set video
  - initialize root array - element at index should be the element value = index
  - for each vertex, choose parent node, - in the array, change array index to parent
  - in the root array, the root node's parent is itself

- important functions
  - find_root given vertex
  - union - unions 2 verticies and makes root the same