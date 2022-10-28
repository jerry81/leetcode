# Intro

- def: HT is DS that organizes data using hash function
- goal is quick insertion and search

## Hashset vs HashMap

- hash-set no repeated values, implementation of set
- hash map - implements map data structure

## design

- principle:
  - map keys to buckets
    - when insert key, hash funct decides which bucket key is assigned
    - searching - use same hash function to find bucket then arbitrary search in bucket
    - different keys may map to same bucket

## complexity

- if all items go into same bucket, then O(N) for insert and search

- built-in hash tables
  - starts with array buckets
  - when they get large, they use height-balanced binary search tree instead
  - key value
  - key value can be hashable type
  - value belonging to hashable type has hashcode - this is used in mapping function to get bucket index
  - this way worst case is improved to O(logN) for insertion and search

## cases for using hashMap vs set

- use hashMap when you need "more info" than just the key
- e.g. given arr of ints, return indicies of two numbers that add up to specific target