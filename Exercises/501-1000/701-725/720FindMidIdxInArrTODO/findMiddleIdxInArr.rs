/*

1991. Find the Middle Index in Array
Easy
Topics
Companies
Hint
Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).

A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].

If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.

Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.



Example 1:

Input: nums = [2,3,-1,8,4]
Output: 3
Explanation: The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
The sum of the numbers after index 3 is: 4 = 4
Example 2:

Input: nums = [1,-1,4]
Output: 2
Explanation: The sum of the numbers before index 2 is: 1 + -1 = 0
The sum of the numbers after index 2 is: 0
Example 3:

Input: nums = [2,5]
Output: -1
Explanation: There is no valid middleIndex.


Constraints:

1 <= nums.length <= 100
-1000 <= nums[i] <= 1000


Note: This question is the same as 724: https://leetcode.com/problems/find-pivot-index/

Seen this question in a real interview before?
1/5
Yes
No
Accepted
91K
Submissions
135.1K
Acceptance Rate
67.4%

*/

impl Solution {
  pub fn find_middle_index(nums: Vec<i32>) -> i32 {
    // 2 prefix sums forward and back
    let mut pf: Vec<i32> = Vec::new();
    let mut pb: Vec<i32> = Vec::new();
    let mut smf = 0;
    for i in &nums {
      smf += i;
      pf.push(smf);
    }
    let mut smb = 0;
    let mut rev = nums.clone();
    rev.reverse();
    for i in &rev {
        smb +=i;
        pb.push(smb);
    }
    let sz = nums.len();

    for i in 0..sz {
      let mut f = 0;
      if i > 0 { f = pf[i-1]; }
      let mut bidx:i32 = sz as i32-i as i32-2;
      let mut b = 0;
      if bidx >= 0 { b = pb[bidx as usize] };
      if f == b {
        return i as i32;
      }
    }
    -1
  }
}