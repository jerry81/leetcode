/*

3216. Lexicographically Smallest String After a Swap
Easy
Topics
Companies
Hint
Given a string s containing only digits, return the
lexicographically smallest string
 that can be obtained after swapping adjacent digits in s with the same parity at most once.

Digits have the same parity if both are odd or both are even. For example, 5 and 9, as well as 2 and 4, have the same parity, while 6 and 9 do not.



Example 1:

Input: s = "45320"

Output: "43520"

Explanation:

s[1] == '5' and s[2] == '3' both have the same parity, and swapping them results in the lexicographically smallest string.

Example 2:

Input: s = "001"

Output: "001"

Explanation:

There is no need to perform a swap because s is already the lexicographically smallest.



Constraints:

2 <= s.length <= 100
s consists only of digits.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
45.7K
Submissions
84.9K
Acceptance Rate
53.9%

*/

impl Solution {
  pub fn get_smallest_string(s: String) -> String {
    // swap smallest to front
    let mut as_v: Vec<char> = s.chars().collect();
    let l = as_v.len();
    let mut swap1 = 0;
    let mut swap2 = 0;
    for i in 0..(l-1) {
      let c1 = (as_v[i] as u8 - '0' as u8) as i32;
      let mut mn_swap = 10;

      let c2 = (as_v[i+1] as u8 - '0' as u8) as i32;
      if c1%2 != c2%2 { continue; }

      if c2 >= c1 { continue; }
      if c2 < mn_swap {
        mn_swap = c2;
        swap1 = i;
        swap2 = i+1;
        break;
      }
    }
    as_v.swap(swap1, swap2); // TIL: built in swap in Vec
    as_v.collect()
  }
}