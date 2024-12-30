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
  pub fn r(nums: &Vec<i32>, res: &mut Vec<Vec<i32>>, hs: &mut HashSet<String>, idx: usize, cur: Vec<i32>) {
    // do a take or leave
    if idx >= nums.len() { return }

    let currenti = nums[idx];
    let mut cur2 = cur.clone(); // Changed to mutable
    let mut curc = cur.clone();
    curc.sort();
    cur2.push(currenti);
    cur2.sort();
    let cs = curc.iter().map(|i| { (i as u8 + '0' as u8) as char }).collect();
    let cs2 = cur2.iter().map(|i| { (i as u8 + '0' as u8) as char }).collect();
    if !hs.contains(&cs) {
        res.push(curc.clone());
        hs.insert(cs);
    } // Changed to push a clone of cur
    if !hs.contains(&cs2) {
        res.push(cur2.clone());
        hs.insert(cs2);
    }

    Solution::r(nums, res, hs, idx + 1, cur.clone()); // Removed &mut from hs
    Solution::r(nums, res, hs, idx + 1, cur2); // Removed &mut from hs
  }

  pub fn subsets_with_dup(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut res: Vec<Vec<i32>> = Vec::new();
    let mut hs: HashSet<String> = HashSet::new();
    res.push(vec![]);
    let n = nums.len();
    hs.insert("".to_string());

    for i in 0..n {
      let mut cur = vec![];

      Solution::r(&nums,&mut res,&mut hs,i,cur.clone());
    }
    res
  }
}