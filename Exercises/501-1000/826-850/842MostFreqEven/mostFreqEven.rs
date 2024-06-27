/*

2404. Most Frequent Even Element
Easy
Topics
Companies
Hint
Given an integer array nums, return the most frequent even element.

If there is a tie, return the smallest one. If there is no such element, return -1.



Example 1:

Input: nums = [0,1,2,2,4,4,1]
Output: 2
Explanation:
The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
We return the smallest one, which is 2.
Example 2:

Input: nums = [4,4,4,9,2,4]
Output: 4
Explanation: 4 is the even element appears the most.
Example 3:

Input: nums = [29,47,21,41,13,37,25,7]
Output: -1
Explanation: There is no even element.


Constraints:

1 <= nums.length <= 2000
0 <= nums[i] <= 105
Seen this question in a real interview before?
1/5
Yes
No
Accepted
81.4K
Submissions
161.2K
Acceptance Rate
50.5%

*/

use std::collections::HashMap;

impl Solution {
  pub fn most_frequent_even(nums: Vec<i32>) -> i32 {
    let mut hm: HashMap<i32,i32> = HashMap::new();
    let mut res = -1;
    let mut resV = 0
    for n in nums {
      if n%2 != 0 { continue }

      *hm.entry(n).or_insert(0) += 1;
      if let Some(curV) = hm.get(&n) {
        if curV > resV {
          resV = curV;
          res = n;
        } else if curV == resV && n < res {
          res = n;
        }
      }
    }
    res
  }
}