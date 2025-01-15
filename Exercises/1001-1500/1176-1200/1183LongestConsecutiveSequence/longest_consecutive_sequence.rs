/*

128. Longest Consecutive Sequence
Medium
Topics
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2.3M
Submissions
4.7M
Acceptance Rate
47.6%

*/

use std::collections::HashSet;

impl Solution {
  pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
    let mut hs:HashSet<i32> = nums.into_iter().collect();

    /*
      iter borrows, no ownership, doesn't touch original yields references
      into_iter consumes collection and takes ownership, yields actual values, moves nums
    */
    let mut res = 0;
    for &item in &hs {
      if hs.contains(&(item-1)) { continue }
      let mut cur = 1;
      let mut nxt = item+1;
      while hs.contains(&nxt) {
        cur+=1;
        nxt+=1;
      }
      res = res.max(cur);
    }
    res
  }
}