/*


1556. Thousand Separator
Easy
Topics
Companies
Hint
Given an integer n, add a dot (".") as the thousands separator and return it in string format.



Example 1:

Input: n = 987
Output: "987"
Example 2:

Input: n = 1234
Output: "1.234"


Constraints:

0 <= n <= 231 - 1
Seen this question in a real interview before?
1/4
Yes
No
Accepted
49.4K
Submissions
92K
Acceptance Rate
53.7%

*/

impl Solution {
  pub fn thousand_separator(n: i32) -> String {
    let mut res:Vec<char> = {};
    let as_s = n.to_string();
    let mut cnt = 0;
    for c in as_s.chars().rev() {
      res.insert(0,c);
      cnt += 1;
      if cnt % 3 == 0 { res.insert(0,'.'); }
    }

    res.iter().collect()
  }
}