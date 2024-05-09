/*
3136. Valid Word
Easy
Topics
Companies
Hint
A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.


Example 1:

Input: word = "234Adas"

Output: true

Explanation:

This word satisfies the conditions.

Example 2:

Input: word = "b3"

Output: false

Explanation:

The length of this word is fewer than 3, and does not have a vowel.

Example 3:

Input: word = "a3$e"

Output: false

Explanation:

This word contains a '$' character and does not have a consonant.



Constraints:

1 <= word.length <= 20
word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
27.2K
Submissions
78.3K
Acceptance Rate
34.7%
*/

impl Solution {
  pub fn is_valid(word: String) -> bool {
    // len
    let mut sz = word.len();
    if sz < 3 { return false }
    let mut has_vowel = false;
    let mut has_consonant = false;
    let VOWELS: Vec<char> = vec!['a','A','e','E','i','I','o','O','u','U'];
    // letters or digits
    for c in word.chars() {
      if c >= 'a' && c <= 'z' || c >= 'A' && c < 'Z' {
        if VOWELS.contains(c) {
          has_vowel = true;
        } else {
          has_consonant = true;
        }
        continue
      }

      if c >= '0' && c <= '9' { continue }

      return false
    }

    has_vowel && has_consonant
  }
}