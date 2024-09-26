/*


3105. Longest Strictly Increasing or Strictly Decreasing Subarray
Easy
Topics
Companies
You are given an array of integers nums. Return the length of the longest
subarray
 of nums which is either
strictly increasing
 or
strictly decreasing
.



Example 1:

Input: nums = [1,4,3,3,2]

Output: 2

Explanation:

The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].

The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].

Hence, we return 2.

Example 2:

Input: nums = [3,3,3,3]

Output: 1

Explanation:

The strictly increasing subarrays of nums are [3], [3], [3], and [3].

The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

Hence, we return 1.

Example 3:

Input: nums = [3,2,1]

Output: 3

Explanation:

The strictly increasing subarrays of nums are [3], [2], and [1].

The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].

Hence, we return 3.



Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50
Seen this question in a real interview before?
1/5
Yes
No
Accepted
41.4K
Submissions
72.4K
Acceptance Rate
57.2%

*/

impl Solution {
  pub fn longest_monotonic_subarray(nums: Vec<i32>) -> i32 {
    let mut inc_mx_streak = 0;
    let mut dec_mx_streak = 0;
    let mut cur_inc = 0;
    let mut cur_dec = 51;
    let mut cur_inc_streak = 0;
    let mut cur_dec_streak = 0;
    for n in nums {
      if n > cur_inc {
        cur_inc_streak+=1;
        inc_mx_streak = inc_mx_streak.max(cur_inc_streak);
      } else {
        cur_inc_streak = 0;
      }
      cur_inc = n;
      if n < cur_dec {
        cur_dec_streak+=1;
        dec_mx_streak = dec_mx_streak.max(cur_dec_streak);
      } else {
        cur_dec_streak = 0;
      }
      cur_dec = n;
    }
    dec_mx_streak.max(inc_mx_streak)
  }
}