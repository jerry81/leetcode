/*

2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
Easy
Topics
Companies
Hint
You are given a 0-indexed array of integers nums.

A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.

Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.



Example 1:

Input: nums = [1,2,3,2,5]
Output: 6
Explanation: The longest sequential prefix of nums is [1,2,3] with a sum of 6. 6 is not in the array, therefore 6 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.
Example 2:

Input: nums = [3,4,5,1,12,14,13]
Output: 15
Explanation: The longest sequential prefix of nums is [3,4,5] with a sum of 12. 12, 13, and 14 belong to the array while 15 does not. Therefore 15 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.


Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50

Seen this question in a real interview before?
1/5
Yes
No
Accepted
32.1K
Submissions
97.5K
Acceptance Rate
32.9%

*/

impl Solution {
  pub fn missing_integer(nums: Vec<i32>) -> i32 {
    // first find the longest sequence prefix sum
    let mut prefix_sum = nums[0];
    for i in 1..nums.len() {
      if nums[i] == nums[i-1] + 1 {
        prefix_sum += nums[i];
      } else {
        break
      }
    }
    // then find the smallest integer that is greater than the prefix sum
    let mut sorted = nums.clone();
    sorted.sort();
    let mut x = prefix_sum;
    for &num in sorted.iter() {
        if x < num {
            break;
        }
        if x == num {
            x += 1;
        }
    }
    x
  }
}