/*

2609. Find the Longest Balanced Substring of a Binary String
Easy
Topics
Companies
Hint
You are given a binary string s consisting only of zeroes and ones.

A substring of s is considered balanced if all zeroes are before ones and the number of zeroes is equal to the number of ones inside the substring. Notice that the empty substring is considered a balanced substring.

Return the length of the longest balanced substring of s.

A substring is a contiguous sequence of characters within a string.



Example 1:

Input: s = "01000111"
Output: 6
Explanation: The longest balanced substring is "000111", which has length 6.
Example 2:

Input: s = "00111"
Output: 4
Explanation: The longest balanced substring is "0011", which has length 4.
Example 3:

Input: s = "111"
Output: 0
Explanation: There is no balanced substring except the empty substring, so the answer is 0.


Constraints:

1 <= s.length <= 50
'0' <= s[i] <= '1'
Seen this question in a real interview before?
1/5
Yes
No
Accepted
31.2K
Submissions
67.2K
Acceptance Rate
46.4%

*/

impl Solution {
  pub fn find_the_longest_balanced_substring(s: String) -> i32 {
    let mut zeroes_count = 0;
    let mut current_zeroes = true;
    let mut ones_count = 0;
    let mut longest = 0;
    for c in s.chars() {
      if current_zeroes {
        if c == '0' {
          zeroes_count+=1;
        } else {
          ones_count+=1;
          current_zeroes = false;
        }
      } else {
        if c == '0' {
          current_zeroes = true;
          let lesser = ones_count.min(zeroes_count);
          longest = longest.max(lesser*2);
          ones_count = 0;
          zeroes_count = 1;
        } else {
          ones_count+=1;
        }
      }
    }
    let lesser = ones_count.min(zeroes_count);
    longest.max(lesser*2)
  }
}