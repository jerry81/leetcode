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

- also immutable in python
- also in ruby3, optional in ruby 2
- in rust mut String is mutable

- when immutable to add a char you must create a new string
- adding a char to string in a loop much slower in java because of the immutability
- if you convert Str to char array in java then it is mutable
- stringbuilder better for strings that are modified often
## other ops

+= in c++ - concatenation
s1.substr(6, 5) in c++ - find substring O(N)

## 2 pointer

- reverse array, with two pointers
- pointer at start, pointer at end
- swap 1 and 2 until they meet

### 2 pointer for array item deletion

- 1 pointer iterates normally
- another pointer points to where should be adding to array
- similar to create new array and recreate

## array-related techniques

- similar data structures
  - string
  - hash table
  - linked list
  - queue
  - stack

- sort is usually built in, but should also understand the algorithms

- binary search important technique

- sliding window problem (two pointer)

- greedy algorithm with two-pointer