/*

39. Combination Sum
Medium
Topics
Companies
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []


Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2.2M
Submissions
3M
Acceptance Rate
73.1%

*/

impl Solution {
  fn backtrack(
    candidates: &Vec<i32>,
    target: i32,
    start: usize,
    current_sum: i32,
    combination: &mut Vec<i32>,
    results: &mut Vec<Vec<i32>>
  ) {
    if start >= candidates.len() { return }
    // base: over target
    if current_sum > target { return }
    // target reached
    if current_sum == target {
      results.push(combination.clone());
      return
    }
    for i in start..candidates.len() {
      // Add the current candidate to the combination
      combination.push(candidates[i]);
      // Recurse with updated sum and same start index (allowing reuse of the current element)
      Solution::backtrack(candidates, target, i, current_sum + candidates[i], combination, results);
      // Remove the last element to backtrack
      combination.pop();
    }
  }

  pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
    let mut comb: Vec<i32> = vec![];
    let mut res: Vec<Vec<i32>> = vec![];

    Solution::backtrack(&candidates, target, 0, 0, &mut comb, &mut res);
    res
  }
}