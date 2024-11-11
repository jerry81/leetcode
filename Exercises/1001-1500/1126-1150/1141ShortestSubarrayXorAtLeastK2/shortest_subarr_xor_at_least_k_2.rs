/*

3097. Shortest Subarray With OR at Least K II
Medium
Topics
Companies
Hint
You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty
subarray
 of nums, or return -1 if no special subarray exists.



Example 1:

Input: nums = [1,2,3], k = 2

Output: 1

Explanation:

The subarray [3] has OR value of 3. Hence, we return 1.

Example 2:

Input: nums = [2,1,8], k = 10

Output: 3

Explanation:

The subarray [2,1,8] has OR value of 11. Hence, we return 3.

Example 3:

Input: nums = [1,2], k = 0

Output: 1

Explanation:

The subarray [1] has OR value of 1. Hence, we return 1.



Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 109
0 <= k <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
25.8K
Submissions
67K
Acceptance Rate
38.4%

*/

impl Solution {
  pub fn minimum_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
      let mut bitcount: Vec<i32> = vec![0; 32];
      let mut res = i32::MAX;
      let n = nums.len();
      let mut l: usize = 0;
      let mut current_or = 0;

      for r in 0..n {
          current_or |= nums[r];

          // Update the bitcount vector for the current number
          for i in 0..32 {
              if (nums[r] & (1 << i)) != 0 {
                  bitcount[i] += 1;
              }
          }

          // Shrink the window from the left while the current OR is at least k
          while current_or >= k && l <= r {
              res = res.min((r - l + 1) as i32);

              // Update the bitcount vector to remove the contribution of nums[l]
              for i in 0..32 {
                  if (nums[l] & (1 << i)) != 0 {
                      bitcount[i] -= 1;
                  }
              }

              // Recalculate current_or based on the bitcount vector
              current_or = 0;
              for i in 0..32 {
                  if bitcount[i] > 0 {
                      current_or |= 1 << i;
                  }
              }

              l += 1;
          }
      }

      if res == i32::MAX {
          -1
      } else {
          res
      }
  }
}