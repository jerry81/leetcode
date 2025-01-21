/*

137. Single Number II
Medium
Topics
Companies
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.



Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99


Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
684.3K
Submissions
1.1M
Acceptance Rate
64.4%

*/
impl Solution {
  pub fn single_number(nums: Vec<i32>) -> i32 {
    let mut bits = [0; 32]; // Array to hold the count of bits

    // Count the bits for each number
    for num in nums {
      for i in 0..32 {
        bits[i] += (num >> i) & 1; // Increment the bit count
      }
    }

    let mut result = 0;
    // Construct the result from bits that are not multiples of 3
    for i in 0..32 {
      if bits[i] % 3 != 0 {
        result |= 1 << i; // Set the bit in the result
      }
    }

    result
  }
}