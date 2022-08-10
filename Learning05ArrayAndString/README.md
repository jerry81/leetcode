# Array And String explore card

## intro

- string similar to array - it is an array of characters
- most interview questions fall into this category
- understand diff between arr and dynamic arr
- basic operations in both types of arrays
- multidimensional array
- string and its features
- two pointer technique

## definition

- definition: data structure used to store elements sequentially
- accessed randomly like hash map (with keys as indexes)

## dynamic array

- most PL offer this
- can have variable size
  - vector in C++
  - ArrayList in Java

## 2D array

- seq of elements
- rectangular grid instead of line
- could be implemented as one-dim array in some languages
  - e.g. C++
    - single contiguous block of mem A[0][0] .. A[0][N-1], A[1][0] ... A[M-1][N-1]
    - index i,j with A[i*N+j]
  - e.g. Java
  - 1D array which contains Arrays
- some languages lack it
