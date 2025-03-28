/*

2275. Largest Combination With Bitwise AND Greater Than Zero
Medium
Topics
Companies
Hint
The bitwise AND of an array nums is the bitwise AND of all integers in nums.

For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
Also, for nums = [7], the bitwise AND is 7.
You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.

Return the size of the largest combination of candidates with a bitwise AND greater than 0.



Example 1:

Input: candidates = [16,17,71,62,12,24,14]
Output: 4
Explanation: The combination [16,17,62,24] has a bitwise AND of 16 & 17 & 62 & 24 = 16 > 0.
The size of the combination is 4.
It can be shown that no combination with a size greater than 4 has a bitwise AND greater than 0.
Note that more than one combination may have the largest size.
For example, the combination [62,12,24,14] has a bitwise AND of 62 & 12 & 24 & 14 = 8 > 0.
Example 2:

Input: candidates = [8,8]
Output: 2
Explanation: The largest combination [8,8] has a bitwise AND of 8 & 8 = 8 > 0.
The size of the combination is 2, so we return 2.


Constraints:

1 <= candidates.length <= 105
1 <= candidates[i] <= 107
Seen this question in a real interview before?
1/5
Yes
No
Accepted
32.9K
Submissions
44.6K
Acceptance Rate
73.8%

*/

impl Solution {
  fn r(candidates: &Vec<i32>, cur_sum: i32, index: usize) -> i32 {
    // max of take or leave
    if index >= candidates.len() { return 0 }


    if cur_sum == -1 {
      return (1+Solution::r(candidates, candidates[index], index+1)).max(Solution::r(candidates, -1, index+1));
    } else {
      let prod = cur_sum & candidates[index];
      if prod != 0 {
        return (1+Solution::r(candidates, prod, index+1)).max(Solution::r(candidates, cur_sum, index+1));
      } else {
        return Solution::r(candidates, cur_sum, index+1);
      }
    }
  }
  pub fn largest_combination(candidates: Vec<i32>) -> i32 {
    Solution::r(&candidates, -1, 0)
  }
}