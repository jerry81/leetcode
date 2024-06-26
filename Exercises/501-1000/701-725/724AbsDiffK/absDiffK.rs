/*

2006. Count Number of Pairs With Absolute Difference K
Easy
Topics
Companies
Hint
Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

The value of |x| is defined as:

x if x >= 0.
-x if x < 0.


Example 1:

Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
Example 2:

Input: nums = [1,3], k = 3
Output: 0
Explanation: There are no pairs with an absolute difference of 3.
Example 3:

Input: nums = [3,2,1,5,4], k = 2
Output: 3
Explanation: The pairs with an absolute difference of 2 are:
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]


Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
1 <= k <= 99
Seen this question in a real interview before?
1/5
Yes
No
Accepted
144.3K
Submissions
172.5K
Acceptance Rate
83.7%

*/

impl Solution {
  pub fn count_k_difference(nums: Vec<i32>, k: i32) -> i32 {
    let mut res = 0;
    let sz = nums.len();
    for i in 0..sz-1 {
      let item1 = nums[i];
      for j in i+1..sz {
        let item2 = nums[j];
        let diff = item2 - item1;
        let absd = diff.abs();
        if absd == k { res+=1; }
      }
    }
    res
  }
}