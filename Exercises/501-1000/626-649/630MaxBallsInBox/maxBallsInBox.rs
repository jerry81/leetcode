/*

1742. Maximum Number of Balls in a Box
Easy
Topics
Companies
Hint
You are working in a ball factory where you have n balls numbered from lowLimit up to highLimit inclusive (i.e., n == highLimit - lowLimit + 1), and an infinite number of boxes numbered from 1 to infinity.

Your job at this factory is to put each ball in the box with a number equal to the sum of digits of the ball's number. For example, the ball number 321 will be put in the box number 3 + 2 + 1 = 6 and the ball number 10 will be put in the box number 1 + 0 = 1.

Given two integers lowLimit and highLimit, return the number of balls in the box with the most balls.



Example 1:

Input: lowLimit = 1, highLimit = 10
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
Ball Count:  2 1 1 1 1 1 1 1 1 0  0  ...
Box 1 has the most number of balls with 2 balls.
Example 2:

Input: lowLimit = 5, highLimit = 15
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 ...
Ball Count:  1 1 1 1 2 2 1 1 1 0  0  ...
Boxes 5 and 6 have the most number of balls with 2 balls in each.
Example 3:

Input: lowLimit = 19, highLimit = 28
Output: 2
Explanation:
Box Number:  1 2 3 4 5 6 7 8 9 10 11 12 ...
Ball Count:  0 1 1 1 1 1 1 1 1 2  0  0  ...
Box 10 has the most number of balls with 2 balls.


Constraints:

1 <= lowLimit <= highLimit <= 105
Seen this question in a real interview before?
1/4
Yes
No
Accepted
61.4K
Submissions
83.8K
Acceptance Rate
73.3%

*/

/*
  2 skills:
  i32 to string +
  simulation
*/

use std::collections::HashMap;

impl Solution {
  fn get_bucket(num: i32) -> i32 {
    let mut res = 0;
    for c in num.to_string().chars() {
      let dig = c as i32 - '0' as i32;
      res+=dig;
    }
    res
  }
  pub fn count_balls(low_limit: i32, high_limit: i32) -> i32 {
    let mut counts: HashMap<i32, i32> = HashMap::new();
    let mut res = 0;
    for cur in low_limit..=high_limit {
      let bk = Solution::get_bucket(cur);
      let count = counts.entry(bk).or_insert(0); // nice.  it allows us to use a compact var to update hm
      *count += 1;
      res = (*count).max(res);
    }
    res
  }
}