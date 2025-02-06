/*

152. Maximum Product Subarray
Medium
Topics
Companies
Given an integer array nums, find a
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.



Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1.5M
Submissions
4.4M
Acceptance Rate
34.4%
*/

impl Solution {
  pub fn max_product(nums: Vec<i32>) -> i32 {
    let mut max_product = nums[0];
    let mut min_product = nums[0];
    let mut result = nums[0];

    for &n in &nums[1..] {
      max_product*=n;
      min_product*=n;
      if n < 0 {

        // Swap max and min when n is negative
        std::mem::swap(&mut max_product, &mut min_product);
      }
      max_product = max_product.max(n as i32);
      min_product = min_product.min(n as i32);

      result = result.max(max_product);
    }

    result
  }
}