/*

3335. Total Characters in String After Transformations I
Medium
Topics
Companies
Hint
You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.



Example 1:

Input: s = "abcyy", t = 2

Output: 7

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'b' becomes 'c'
'c' becomes 'd'
'y' becomes 'z'
'y' becomes 'z'
String after the first transformation: "bcdzz"
Second Transformation (t = 2):
'b' becomes 'c'
'c' becomes 'd'
'd' becomes 'e'
'z' becomes "ab"
'z' becomes "ab"
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.
Example 2:

Input: s = "azbk", t = 1

Output: 5

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'z' becomes "ab"
'b' becomes 'c'
'k' becomes 'l'
String after the first transformation: "babcl"
Final Length of the string: The string is "babcl", which has 5 characters.


Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
1 <= t <= 105
Seen this question in a real interview before?
1/5
Yes
No
Accepted
36.5K
Submissions
100.1K
Acceptance Rate
36.4%

*/
impl Solution {
  pub fn length_after_transformations(s: String, t: i32) -> i32 {
    const MOD:i32 = 1_000_000_007; // decl const
    let mut cnt = [0; 26]; // one dim array len 26, init value 0
    for ch in s.chars() { // build freq arr
      cnt[(ch as u8 - b'a' /*shorthand for u8 (byte)*/) as usize] +=1;
    }
    for _ in 0..t { // iterate t times
      let mut nxt = [0; 26]; // rebuild the array
      nxt[0] = cnt[25]; // z-> a
      nxt[1] = (cnt[25] + cnt[0]) % MOD; // z -> b, a-> b
      for i in 2..26 {
        nxt[i] = nxt[i-1];
      }
      cnt = nxt;
    }
    let mut ans = 0;
    for &num /*accessing array value*/ in cnt.iter() {
      ans = (ans+num) % MOD;
    }
    ans
  }
}
