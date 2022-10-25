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
