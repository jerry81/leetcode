/*

3190. Find Minimum Operations to Make All Elements Divisible by Three
Easy
Topics
Companies
Hint
You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.

Return the minimum number of operations to make all elements of nums divisible by 3.



Example 1:

Input: nums = [1,2,3,4]

Output: 3

Explanation:

All array elements can be made divisible by 3 using 3 operations:

Subtract 1 from 1.
Add 1 to 2.
Subtract 1 from 4.
Example 2:

Input: nums = [3,6,9]

Output: 0



Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50
Seen this question in a real interview before?
1/5
Yes
No
Accepted
94.1K
Submissions
104.7K
Acceptance Rate
89.9%

*/

impl Solution {
  pub fn minimum_operations(nums: Vec<i32>) -> i32 {
    let mut nums = nums;
    nums.iter().map(|n| { 1.min(n%3) }).sum()
  }
}