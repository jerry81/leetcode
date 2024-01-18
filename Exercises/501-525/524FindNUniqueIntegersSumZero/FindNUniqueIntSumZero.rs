/*

1304. Find N Unique Integers Sum up to Zero
Easy
Topics
Companies
Hint
Given an integer n, return any array containing n unique integers such that they add up to 0.



Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]


Constraints:

1 <= n <= 1000
Seen this question in a real interview before?
1/4
Yes
No
Accepted
206.4K
Submissions
270.4K
Acceptance Rate
76.4%

*/

impl Solution {
  pub fn sum_zero(n: i32) -> Vec<i32> {
    let mut cur = 0;
    let mut cursum = 0;
    let mut res:Vec<i32> = Vec::new();
    if n == 2 {
        return vec![1,-1];
    }
    for i in 0..n-1 {
      res.push(cur);
      cursum+=cur;
      cur+=1;
    }
    res.push(cursum*-1);
    res
  }
}