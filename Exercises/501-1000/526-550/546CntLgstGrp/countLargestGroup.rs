/*

1399. Count Largest Group
Easy
Topics
Companies
Hint
You are given an integer n.

Each number from 1 to n is grouped according to the sum of its digits.

Return the number of groups that have the largest size.



Example 1:

Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.
Example 2:

Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.


Constraints:

1 <= n <= 104
Seen this question in a real interview before?
1/4
Yes
No
Accepted
43.2K
Submissions
64.9K
Acceptance Rate
66.5%

*/
use std::collections::HashMap;

impl Solution {

  pub fn count_largest_group(n: i32) -> i32 {
    let mut sums:HashMap<i32,i32> = HashMap::new();
    let mut lgstSz = 0;
    for i in 1..=n {
      let cur = sum_digits(i);
      *sums.entry(cur).or_insert(0)+=1;
      lgstSz = lgstSz.max(*sums.entry(cur).or_insert(0));
    }
    let mut res = 0;
    for (_,v) in &sums {
      if *v == lgstSz { res+=1; }
    }
    res
  }
}

fn sum_digits(n: i32) -> i32 {
  let ns = n.to_string();
  let mut res = 0;
  for c in ns.chars() {
    res+=c.to_digit(10).unwrap();
  }
  res as i32
}