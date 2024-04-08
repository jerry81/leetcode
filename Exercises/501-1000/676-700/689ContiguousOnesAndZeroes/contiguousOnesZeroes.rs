/*

1869. Longer Contiguous Segments of Ones than Zeros
Easy
Topics
Companies
Hint
Given a binary string s, return true if the longest contiguous segment of 1's is strictly longer than the longest contiguous segment of 0's in s, or return false otherwise.

For example, in s = "110100010" the longest continuous segment of 1s has length 2, and the longest continuous segment of 0s has length 3.
Note that if there are no 0's, then the longest continuous segment of 0's is considered to have a length 0. The same applies if there is no 1's.



Example 1:

Input: s = "1101"
Output: true
Explanation:
The longest contiguous segment of 1s has length 2: "1101"
The longest contiguous segment of 0s has length 1: "1101"
The segment of 1s is longer, so return true.
Example 2:

Input: s = "111000"
Output: false
Explanation:
The longest contiguous segment of 1s has length 3: "111000"
The longest contiguous segment of 0s has length 3: "111000"
The segment of 1s is not longer, so return false.
Example 3:

Input: s = "110100010"
Output: false
Explanation:
The longest contiguous segment of 1s has length 2: "110100010"
The longest contiguous segment of 0s has length 3: "110100010"
The segment of 1s is not longer, so return false.


Constraints:

1 <= s.length <= 100
s[i] is either '0' or '1'.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
46.4K
Submissions
76.1K
Acceptance Rate
60.9%

*/

impl Solution {
  pub fn check_zero_ones(s: String) -> bool {
    let mut zero_len = 0;
    let mut curzero = 0;
    let mut one_len = 0;
    let mut curone = 0;

    for c in s.chars() {
      if c == '0' {
        curzero +=1;
        zero_len = zero_len.max(curzero);
        curone = 0;
      } else {
        curzero = 0;
        curone +=1;
        one_len = one_len.max(curone);
      }
    }
    one_len > zero_len
  }
}