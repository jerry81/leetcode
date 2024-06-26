/*


1848. Minimum Distance to the Target Element
Easy
Topics
Companies
Hint
Given an integer array nums (0-indexed) and two integers target and start, find an index i such that nums[i] == target and abs(i - start) is minimized. Note that abs(x) is the absolute value of x.

Return abs(i - start).

It is guaranteed that target exists in nums.



Example 1:

Input: nums = [1,2,3,4,5], target = 5, start = 3
Output: 1
Explanation: nums[4] = 5 is the only value equal to target, so the answer is abs(4 - 3) = 1.
Example 2:

Input: nums = [1], target = 1, start = 0
Output: 0
Explanation: nums[0] = 1 is the only value equal to target, so the answer is abs(0 - 0) = 0.
Example 3:

Input: nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
Output: 0
Explanation: Every value of nums is 1, but nums[0] minimizes abs(i - start), which is abs(0 - 0) = 0.


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 104
0 <= start < nums.length
target is in nums.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
43K
Submissions
78.6K
Acceptance Rate
54.7%

*/
impl Solution {
  pub fn get_min_distance(nums: Vec<i32>, target: i32, start: i32) -> i32 {
      let mut res = 0;
      let sz = nums.len();
      let mut dist = i32::MAX;
      for i in 0..sz {
        if nums[i] == target {
          let curd = (i as i32-start).abs();
          if curd < dist {
            dist = curd;
            res = (i as i32 - start).abs() as i32;
          }
        }
      }
      res
  }
}