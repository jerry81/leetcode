/*

2765. Longest Alternating Subarray
Easy
Topics
Companies
Hint
You are given a 0-indexed integer array nums. A subarray s of length m is called alternating if:

m is greater than 1.
s1 = s0 + 1.
The 0-indexed subarray s looks like [s0, s1, s0, s1,...,s(m-1) % 2]. In other words, s1 - s0 = 1, s2 - s1 = -1, s3 - s2 = 1, s4 - s3 = -1, and so on up to s[m - 1] - s[m - 2] = (-1)m.
Return the maximum length of all alternating subarrays present in nums or -1 if no such subarray exists.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:

Input: nums = [2,3,4,3,4]
Output: 4
Explanation: The alternating subarrays are [3,4], [3,4,3], and [3,4,3,4]. The longest of these is [3,4,3,4], which is of length 4.
Example 2:

Input: nums = [4,5,6]
Output: 2
Explanation: [4,5] and [5,6] are the only two alternating subarrays. They are both of length 2.


Constraints:

2 <= nums.length <= 100
1 <= nums[i] <= 104
Seen this question in a real interview before?
1/5
Yes
No
Accepted
25.4K
Submissions
74.1K
Acceptance Rate
34.2%

*/

impl Solution {
  pub fn alternating_subarray(nums: Vec<i32>) -> i32 {
    let sz = nums.len();
    let mut res = 0;
    for l in 0..sz {
      let left = nums[l];
      let mut start = false;
      let mut broke = false;
      for r in l+1..sz {
        let right = nums[r];

        if (right != (left+1) && (right != left)) || (start && right != left) || (!start && right == left) {
          broke = true;
          res = res.max(r-l);
          break;
        }
        start = !start;
      }
      if !broke {
        res = res.max(sz-l);
      }

    }
    if res < 2 {
      -1
    } else {
      res as i32
    }
  }
}