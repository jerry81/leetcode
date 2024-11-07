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
  fn bt(nums: &Vec<i32>, pivot: usize, sets:&Vec<Vec<i32>>) {
    sets.push(nums.clone());
    for i in pivot+1..nums.len() {
      sets.swap(i, pivot);
      SolutioN::bt(nums, pivot+1, sets);
      sets.swap(i,pivot);
    }
    // swap
    // recurse
    // swapback
  }
  pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
    // generate permutations into a set
    let mut sets: Vec<Vec<i32>> = Vec::new();
    let mut nums = nums.clone();
    Solution::bt(nums, 0, sets);
    println!("{:?}", sets);
    vec![]
  }
}