/*

3210. Find the Encrypted String
Easy
Topics
Companies
Hint
You are given a string s and an integer k. Encrypt the string using the following algorithm:

For each character c in s, replace c with the kth character after c in the string (in a cyclic manner).
Return the encrypted string.



Example 1:

Input: s = "dart", k = 3

Output: "tdar"

Explanation:

For i = 0, the 3rd character after 'd' is 't'.
For i = 1, the 3rd character after 'a' is 'd'.
For i = 2, the 3rd character after 'r' is 'a'.
For i = 3, the 3rd character after 't' is 'r'.
Example 2:

Input: s = "aaa", k = 1

Output: "aaa"

Explanation:

As all the characters are the same, the encrypted string will also be the same.



Constraints:

1 <= s.length <= 100
1 <= k <= 104
s consists only of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
36.9K
Submissions
53.2K
Acceptance Rate
69.5%

*/

impl Solution {
  pub fn get_encrypted_string(s: String, k: i32) -> String {
    let sz = s.len();
    let chrs: Vec<char> = s.chars().collect();
    let res: String = (0..sz)
    .map(|i| {
        let idx = (i+k as usize) % sz;
        chrs[idx]
    })
    .collect();
    res
  }
}