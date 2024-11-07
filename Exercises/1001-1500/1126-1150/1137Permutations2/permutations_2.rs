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
  fn bt(nums: &mut Vec<i32>, pivot: usize, sets:&mut HashSet<Vec<i32>>) {
    sets.insert(nums.clone());
    for i in pivot..nums.len() {
      nums.swap(i, pivot);
      Solution::bt(nums, pivot+1, sets);
      nums.swap(i,pivot);
    }
    // swap
    // recurse
    // swapback
  }
  pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
    // generate permutations into a set
    let mut sets: HashSet<Vec<i32>> = HashSet::new();
    let mut nums = nums.clone();
    Solution::bt(&mut nums, 0, &mut sets);

    sets.iter().map(|hs| {
      hs.to_vec()
    }).collect()
  }
}