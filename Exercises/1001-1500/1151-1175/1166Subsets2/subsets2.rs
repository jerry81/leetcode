/*


90. Subsets II
Medium
Topics
Companies
Given an integer array nums that may contain duplicates, return all possible
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1.1M
Submissions
1.9M
Acceptance Rate
58.5%

*/

use std::collections::HashSet;

impl Solution {
  pub fn subsets_with_dup(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut res: Vec<Vec<i32>> = Vec::new();
    let mut hs:HashSet<string> = HashSet::new();
    res.push(vec![]);
    let n = nums.len();
    hs.insert("".to_string);

    for i in 0..n {
      let mut s:string = String::new();
      let mut cur = vec![];

      for j in i..n {
        cur.push(nums[j]);
        s+=nums[j].to_string();
        if !hs.contains(s) {
          res.push(cur.clone());
          hs.insert(s.clone());
        }
      }
    }
    res
  }
}