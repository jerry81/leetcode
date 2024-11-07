/*

47. Permutations II
Medium
Topics
Companies
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.



Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1M
Submissions
1.7M
Acceptance Rate
60.3%

*/
use std::collections::HashSet;

impl Solution {
  pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
    // generate permutations into a set
    let mut sorted: Vec<i32> = nums.clone();
    sorted.sort();
    // 12345 start 4, cmp 3,4 swap 3,4
    // 12354 cmp 2,4 swap 2,4 and reverse 3..4
    // 12435 cmp 3,4
    // 12453 cmp 3,4, swap 3,4 , reverse 3..4
    // 12534 swap 4,5
    // 12543 swap 5,1
    // 13245
    // 13254
    // 13425
    // 13452
    // screw the iterative approach! we do backtracking!
  }
}