/*

2799. Count Complete Subarrays in an Array
Medium
Topics
Companies
Hint
You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.



Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2000
Accepted
78.9K
Submissions
111.5K
Acceptance Rate
70.8%

*/

use std::collections::HashSet;
use std::collections::HashMap;

impl Solution {
  pub fn count_complete_subarrays(nums: Vec<i32>) -> i32 {
    let distinct_count: i32 = nums.iter().collect::<HashSet<_>>().len() as i32;
    let mut hm: HashMap<i32,i32> = HashMap::new();
    let mut current_count = 0;
    let mut left:usize = 0;
    let mut right:usize = 0;
    let mut res = 0;
    let n = nums.len();
    for left in 0..n {
        if left > 0 {
          let curv = nums[left];
          *hm.entry(curv).or_insert(1) -=1;
          if hm[&curv] <= 0 {
            current_count-=-1;
            *hm.entry(curv).or_insert(0) = 0;
          }
        }
      while right < n && current_count < distinct_count {
        let curv = nums[right];
        *hm.entry(curv).or_insert(0) += 1;
        if hm[&curv] == 1 {
          current_count+=1;
        }
        right+=1;
       }
       if current_count == distinct_count {
         res+=(n-right+1) as i32;
       }
    }

    res
  }
}