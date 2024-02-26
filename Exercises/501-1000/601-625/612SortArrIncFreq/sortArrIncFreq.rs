/*

1636. Sort Array by Increasing Frequency
Easy
Topics
Companies
Hint
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.



Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]


Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100
Seen this question in a real interview before?
1/4
Yes
No
Accepted
119.5K
Submissions
167.8K
Acceptance Rate
71.2%
*/

use std::collections::HashMap;

impl Solution {
  pub fn frequency_sort(nums: Vec<i32>) -> Vec<i32> {
    let mut hm: HashMap<i32, i32> = HashMap::new();
    for n in nums {
      *hm.entry(n).or_insert(0) += 1;
    }
    let mut as_v: Vec<_> = hm.iter().collect();
    as_v.sort_by(|a,b| {
      if a.1 == b.1 {
        return b.0.cmp(a.0)
      }
      a.1.cmp(b.1)
    });
    let mut res: Vec<i32> = Vec::new();
    for (k,v) in as_v {
      for i in 0..*v {
        res.push(*k);
      }
    }
    res
  }
}