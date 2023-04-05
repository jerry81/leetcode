/*

2439. Minimize Maximum of Array
Medium
1.1K
260
Companies
You are given a 0-indexed array nums comprising of n non-negative integers.

In one operation, you must:

Choose an integer i such that 1 <= i < n and nums[i] > 0.
Decrease nums[i] by 1.
Increase nums[i - 1] by 1.
Return the minimum possible value of the maximum integer of nums after performing any number of operations.



Example 1:

Input: nums = [3,7,1,6]
Output: 5
Explanation:
One set of optimal operations is as follows:
1. Choose i = 1, and nums becomes [4,6,1,6].
2. Choose i = 3, and nums becomes [4,6,2,5].
3. Choose i = 1, and nums becomes [5,5,2,5].
The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
Therefore, we return 5.
Example 2:

Input: nums = [10,1]
Output: 10
Explanation:
It is optimal to leave nums as is, and since 10 is the maximum value, we return 10.


Constraints:

n == nums.length
2 <= n <= 105
0 <= nums[i] <= 109
Accepted
28.2K
Submissions
66.3K
Acceptance Rate
42.6%

*/

#include <vector>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {

    }
};

// [1,5,7,3,4, 2, 7]
// [3,3,7,3,4,4,5]
// [3,5,5,3,4,4,5]
// try in one pass
// diff array
// [4,2,-4,1,-2,5]
// if positive, half of diff
// [2,1,0,.5,0,2.5]
// apply
// [3,4,6,3,4,4,5] - nope

// try priority queue?

// struct nodes - idx, value
// put nodes into pq (maxheap)
// reduce the max (adding to max-1) - so pq must have efficient modify

// BST better
// binary search tree
// logn to search index

//       4
//   2       6
//  1  3   5   7


/*
  8


If the list is sorted, you can simply remove the element you're about to change from the list, and after changing it, you could "binary-insert" it, no? That would take an average of log(n) steps.

If you can, change from an array to a java.util.TreeMap: both removal and insertion will be log(n) operations: which will be faster than your O(1) access + O(n) re-insertion solution using an array.

c++ has no tree

3,7,1,6 as tree

     3
  1     6
           7

  remove 7 and 3
  bst becomes
    6
  1
  3,7 become
  5,5
  bst becomes
     6
  1
    5/5

  remove 6
  1
    5/5
  remove 1
  5/5
  modify 6 and 1
  3,4
  insert back
    5/5
3
  4
  5,5,3,4
  5,5 nothing can be, so done
*/

