/*

1752. Check if Array Is Sorted and Rotated
Easy
Topics
Companies
Hint
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.



Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.


Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
Seen this question in a real interview before?
1/4
Yes
No
Accepted
189.4K
Submissions
372K
Acceptance Rate
50.9%

*/

impl Solution {
  pub fn check(nums: Vec<i32>) -> bool {
    let mut rule_breaks = 0;
    let mut prev = 0;
    for i in nums {
      if prev != 0 && i != prev+1 {
        rule_breaks+=1;
        if rule_breaks > 1 { return false; }

      }
      prev = i;
    }
    true
  }
}