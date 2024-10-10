/*

3158. Find the XOR of Numbers Which Appear Twice
Easy
Topics
Companies
Hint
You are given an array nums, where each number in the array appears either once or twice.

Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.



Example 1:

Input: nums = [1,2,1,3]

Output: 1

Explanation:

The only number that appears twice in nums is 1.

Example 2:

Input: nums = [1,2,3]

Output: 0

Explanation:

No number appears twice in nums.

Example 3:

Input: nums = [1,2,2,1]

Output: 3

Explanation:

Numbers 1 and 2 appeared twice. 1 XOR 2 == 3.



Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50
Each number in nums appears either once or twice.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
48.7K
Submissions
59.5K
Acceptance Rate
82.0%

*/

use std::collections::HashSet;
impl Solution {
  pub fn duplicate_numbers_xor(nums: Vec<i32>) -> i32 {
    let mut res = 0;
    let mut seen:HashSet<i32>=HashSet::new();
    for n in nums.iter() {
      if seen.contains(n) {
        res ^= n;
      }
      seen.insert(*n);
    }
    res
  }
}