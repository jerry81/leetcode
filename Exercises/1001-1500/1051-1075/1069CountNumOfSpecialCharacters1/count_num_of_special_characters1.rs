/*
3120. Count the Number of Special Characters I
Easy
Topics
Companies
Hint
You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

Return the number of special letters in word.



Example 1:

Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters in word are 'a', 'b', and 'c'.

Example 2:

Input: word = "abc"

Output: 0

Explanation:

No character in word appears in uppercase.

Example 3:

Input: word = "abBCab"

Output: 1

Explanation:

The only special character in word is 'b'.



Constraints:

1 <= word.length <= 50
word consists of only lowercase and uppercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
46.9K
Submissions
71.2K
Acceptance Rate
65.8%
*/

use std::collections::HashSet;

impl Solution {
  pub fn number_of_special_chars(word: String) -> i32 {
    let mut lookup:HashSet<char> = HashSet::new();
    let mut counted:HashSet<char> = HashSet::new();
    let mut res = 0;
    for c in word.chars() {
      lookup.insert(c);
      let lower = c.to_lowercase().next().unwrap();
      if lookup.contains(&(c.to_uppercase().next().unwrap())) && lookup.contains(&lower) {

        if !(counted.contains(&lower)) {
          res+=1;
        }

        counted.insert(lower);
      }
    }
    res
  }
}