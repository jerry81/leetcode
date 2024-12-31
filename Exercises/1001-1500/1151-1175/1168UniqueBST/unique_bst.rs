/*


96. Unique Binary Search Trees
Medium
Topics
Companies
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.



Example 1:


Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1


Constraints:

1 <= n <= 19
Seen this question in a real interview before?
1/5
Yes
No
Accepted
721.5K
Submissions
1.2M
Acceptance Rate
61.9%

*/

impl Solution {
  pub fn num_trees(n: i32) -> i32 {
    let mut v:Vec<i32> = vec![0;n as usize+1];
    v[0] = 1;
    v[1] = 1;
    let n = n as usize;
    for i in 2..=n {
      for mid in 1..=i {
       v[i] += v[mid-1] * v[i-mid];
      }
    }
    v[n as usize]
  }
}

 // for each number 1 to n
    // n = 1
    // dp[1] = 1
    // n = 2
    // 1
    //    dp[1] multiplier works
    //       2
    // dp[1]
    // dp[2] = 2
    // n = 3
    //   1
    //     dp[2]
    //       2
    //dp[1]     dp[1]
    //       3
    // dp[2]
    // n = 5
    /*
    1
      (2-5)
    2
  1   (3-5)
        3
  (1-2)   (4-5)
        4
  (1-3)    5
    */
