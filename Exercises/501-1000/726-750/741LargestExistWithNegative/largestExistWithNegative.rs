/*

2441. Largest Positive Integer That Exists With Its Negative
Easy
Topics
Companies
Hint
Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

Return the positive integer k. If there is no such integer, return -1.



Example 1:

Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.
Example 2:

Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
Example 3:

Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.


Constraints:

1 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
nums[i] != 0
Seen this question in a real interview before?
1/5
Yes
No
Accepted
67.5K
Submissions
97.3K
Acceptance Rate
69.4%

*/

use std::collections::HashSet;

impl Solution {
  pub fn find_max_k(nums: Vec<i32>) -> i32 {
    let mut hs: HashSet<i32> = HashSet::new();
    for n in nums {
      if n > 0 {
        hs.insert(n*-1);
      }
    }
    let mut curmin = 1;
    for k in hs {
      if k < curmin {
        curmin = k;
      }
    }
    if curmin > 0 { return -1 }
    -1*curmin
  }
}

