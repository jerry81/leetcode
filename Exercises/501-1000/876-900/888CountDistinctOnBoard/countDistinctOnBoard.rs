/*

2549. Count Distinct Numbers on Board
Easy
Topics
Companies
Hint
You are given a positive integer n, that is initially placed on a board. Every day, for 109 days, you perform the following procedure:

For each number x present on the board, find all numbers 1 <= i <= n such that x % i == 1.
Then, place those numbers on the board.
Return the number of distinct integers present on the board after 109 days have elapsed.

Note:

Once a number is placed on the board, it will remain on it until the end.
% stands for the modulo operation. For example, 14 % 3 is 2.


Example 1:

Input: n = 5
Output: 4
Explanation: Initially, 5 is present on the board.
The next day, 2 and 4 will be added since 5 % 2 == 1 and 5 % 4 == 1.
After that day, 3 will be added to the board because 4 % 3 == 1.
At the end of a billion days, the distinct numbers on the board will be 2, 3, 4, and 5.
Example 2:

Input: n = 3
Output: 2
Explanation:
Since 3 % 2 == 1, 2 will be added to the board.
After a billion days, the only two distinct numbers on the board are 2 and 3.


Constraints:

1 <= n <= 100
Seen this question in a real interview before?
1/5
Yes
No
Accepted
41.5K
Submissions
68.8K
Acceptance Rate
60.3%

*/

use std::collections::HashSet;

impl Solution {
  pub fn distinct_integers(n: i32) -> i32 {
    // math equation or simulation?
    let mut nums_list: HashSet<i32> = HashSet::new();
    let mut cnt = 0;
    while changed && cnt < 1_000_000_000 {
      cnt+=1;
      changed = false;
      for x in nums_list {
        for i in 1..=n {
          if x%i == 1 {
            if nums_list.insert(i) {
              changed = true
            }
          }
        }
      }
    }
    nums_list.len() as i32
  }
}