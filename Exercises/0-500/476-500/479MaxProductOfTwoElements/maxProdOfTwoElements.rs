/*
1464. Maximum Product of Two Elements in an Array
Easy
1.8K
198
Companies
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).


Example 1:

Input: nums = [3,4,5,2]
Output: 12
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12.
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
Example 3:

Input: nums = [3,7]
Output: 12


Constraints:

2 <= nums.length <= 500
1 <= nums[i] <= 10^3
Accepted
228.1K
Submissions
282.3K
Acceptance Rate
80.8%
*/

impl Solution {
  pub fn max_product(nums: Vec<i32>) -> i32 {
    let mut mu = nums;
    mu.sort_by(|a, b| b.cmp(a));
    return (mu[0]-1) * (mu[1]-1);
  }
}