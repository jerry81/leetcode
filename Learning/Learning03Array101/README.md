Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

# insertions

- insert at end of array not costly 
- insert at beginning O(N) - as everything has to shift 

# deletions
- similar to insertion, 3 cases
  - delete last
  - delete first
  - delete at index
- delete from start O(N)
- delete from mid is like delete from start, involves shift, worst case is O(N)

# searching
- the most important operation of all 
- design choices depend on speed of search 
- def: find occurence of element in array and return position 
- constant time if we know index in advance 
- linear search is O(N) - checking thru all elements one by one. 
- binary search 
  - only works if list is sorted 

# in place operations 
- use if you need to reduce space complexity 
- modifies the input array 

# improved deletion of repeated elements
- do 2 passes - one to check how many unique items to determine new array's size
- second to add to the new array 
- so this is not in place 