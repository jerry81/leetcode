/*

2839. Check if Strings Can be Made Equal With Operations I
Easy
Topics
Companies
Hint
You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:

Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.



Example 1:

Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: We can do the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbad".
- Choose the indices i = 1, j = 3. The resulting string is s1 = "cdab" = s2.
Example 2:

Input: s1 = "abcd", s2 = "dacb"
Output: false
Explanation: It is not possible to make the two strings equal.


Constraints:

s1.length == s2.length == 4
s1 and s2 consist only of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
38.4K
Submissions
81.1K
Acceptance Rate
47.3%

*/

use std::collections::HashMap;

impl Solution {
  pub fn can_be_equal(s1: String, s2: String) -> bool {
    if s1 == s2 { return true }

    let s11 = s1.chars().nth(0).unwrap();
    let s12 = s1.chars().nth(1).unwrap();
    let s13 = s1.chars().nth(2).unwrap();
    let s14 = s1.chars().nth(3).unwrap();
    let s21 = s2.chars().nth(0).unwrap();
    let s22 = s2.chars().nth(1).unwrap();
    let s23 = s2.chars().nth(2).unwrap();
    let s24 = s2.chars().nth(3).unwrap();

    let oddsPass1 = s11 == s21 && s13 == s23;
    let oddsPass2 = s11 == s23 && s13 == s21;
    let oddsPass = oddsPass1 || oddsPass2;

    if !oddsPass { return false }

    let evensPass1 = s12 == s22 && s14 == s24;
    let evensPass2 = s12 == s24 && s14 == s22;
    let evensPass = evensPass1 || evensPass2;

    if !evensPass { return false }
    true

  }
}