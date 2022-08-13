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


# strings

- def - an array of unicode chars
- can usually perform all operations of array

## diff from array

- has its own compare function
  - '==' supported if language supports operator overloading
  - yes in c++, no in java
    - == in java is object (hash) comparison, compare compares the string contents

## immutable

- means you can't change contents after init
  - C++ string is mutable
  - Java string immutable
- test modification of string
```java
// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        String s1 = "Hello World";
        s1[5] = ',';
        System.out.println(s1);
    }
}
```

## other ops

+= in c++ - concatenation
s1.substr(6, 5) in c++ - find substring O(N)
