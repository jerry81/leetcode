/*

3300. Minimum Element After Replacement With Digit Sum
Easy
Topics
Companies
Hint
You are given an integer array nums.

You replace each element in nums with the sum of its digits.

Return the minimum element in nums after all replacements.



Example 1:

Input: nums = [10,12,13,14]

Output: 1

Explanation:

nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

Example 2:

Input: nums = [1,2,3,4]

Output: 1

Explanation:

nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

Example 3:

Input: nums = [999,19,199]

Output: 10

Explanation:

nums becomes [27, 10, 19] after all replacements, with minimum element 10.



Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 104
Seen this question in a real interview before?
1/5
Yes
No
Accepted
40K
Submissions
47.9K
Acceptance Rate
83.5%

*/

impl Solution {
  pub fn min_element(nums: Vec<i32>) -> i32 {
    nums.iter().map(|n| {
      n.to_string().chars().map(|c| {
        (c as u8 - '0' as u8) as i32
      }).sum()
    }).min().unwrap()
  }
}