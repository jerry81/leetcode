/*

1925. Count Square Sum Triples
Easy
Topics
Companies
Hint
A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.

Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.



Example 1:

Input: n = 5
Output: 2
Explanation: The square triples are (3,4,5) and (4,3,5).
Example 2:

Input: n = 10
Output: 4
Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).


Constraints:

1 <= n <= 250
Seen this question in a real interview before?
1/5
Yes
No
Accepted
43.5K
Submissions
64.2K
Acceptance Rate
67.7%

*/

impl Solution {
  pub fn count_triples(n: i32) -> i32 {

  }
  fn is_perfect_square(num: i32) -> bool {
    let root = (num as f64).sqrt() as i32; // Compute square root
    root * root == num // Check if square of square root equals original number
  }
}