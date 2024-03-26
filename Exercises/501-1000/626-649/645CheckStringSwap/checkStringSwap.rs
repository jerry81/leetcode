/*

1790. Check if One String Swap Can Make Strings Equal
Easy
Topics
Companies
Hint
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.



Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".
Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.
Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.


Constraints:

1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
102.7K
Submissions
225K

*/

impl Solution {
  pub fn are_almost_equal(s1: String, s2: String) -> bool {
    // try every possibility
    // rust swap:
    // convert to vec<char>
    // vec<char>.swap(idx1, idx2)
    // into_iter().collect()
    if (s1 == s2) { return true }

    let l1 = s1.len();
    let l2 = s2.len();
    if (l1 != l2) { return false }

    for i in 0..l1 {
      for j in i+1..l2 {
        let mut chrs: Vec<char> = s1.chars().collect();
        chrs.swap(i,j);
        let cmp = chrs.into_iter().collect();
        if (cmp == s2) { return true;}
      }
    }
    false
  }
}