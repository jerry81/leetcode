/*

2461. Maximum Sum of Distinct Subarrays With Length K
Medium
Topics
Companies
Hint
You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.


Constraints:

1 <= k <= nums.length <= 105
1 <= nums[i] <= 105
Accepted
82.3K
Submissions
230.2K
Acceptance Rate
35.8%

*/

use std::collections::HashMap;

impl Solution {
  pub fn maximum_subarray_sum(nums: Vec<i32>, k: i32) -> i64 {
    let mut res = 0;
    let mut hm: HashMap<i32, usize> = HashMap::new();  // stores latest index of i32
    let n = nums.len();
    let mut rp = -1;
    let mut cursum = 0;
    let mut lp = 0;
    loop {
          // try to incr rp
          if rp < n-1 {
            rp+=1;
          }
          let cand = nums[rp];
          // fix issues
          // rp item is in hm
          if hm.contains(cand) {
            // try to increase lp
            let last_seen = hm[cand];
            if last_seen > (rp - k + 1) {
              while lp < (last_seen+1) {
                cursum-=nums[lp];
                lp+=1;
              }
            }
          }

          *hm.entry(cand).or_insert(rp) = rp;

          // window too big
          if rp - lp >= k {
            cursum-=nums[lp];
            lp +=1;
          }
    }


  }
}