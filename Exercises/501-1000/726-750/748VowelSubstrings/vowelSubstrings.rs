/*
2062. Count Vowel Substrings of a String
Easy
Topics
Companies
Hint
A substring is a contiguous (non-empty) sequence of characters within a string.

A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.

Given a string word, return the number of vowel substrings in word.



Example 1:

Input: word = "aeiouu"
Output: 2
Explanation: The vowel substrings of word are as follows (underlined):
- "aeiouu"
- "aeiouu"
Example 2:

Input: word = "unicornarihan"
Output: 0
Explanation: Not all 5 vowels are present, so there are no vowel substrings.
Example 3:

Input: word = "cuaieuouac"
Output: 7
Explanation: The vowel substrings of word are as follows (underlined):
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"


Constraints:

1 <= word.length <= 100
word consists of lowercase English letters only.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
39.2K
Submissions
58K
Acceptance Rate
67.5%
*/

use std::collections::HashSet;

 lazy_static! {
    static ref VOWELS: HashSet<char> = {
        let mut set = HashSet::new();
        set.insert('a');
        set.insert('e');
        set.insert('i');
        set.insert('o');
        set.insert('u');
        set
    };
}
impl Solution {

  fn check(word: String) -> bool {
    if word.len() < 5 { return false }
    let mut hs: HashSet<char> = HashSet::new();
    for c in word.chars() {
      if VOWELS.contains(&c) {
        hs.insert(c);
      }
    }
    hs.len() == 5
  }
  pub fn count_vowel_substrings(word: String) -> i32 {
    // brute force it
    let sz = word.len();
    let mut res = 0;
    for i in 0..sz-1 {
      for j in i+1..sz {
        let substr: String = word[i..j].to_string();
        if Self::check(substr) { res+=1; }
      }
    }
    res
  }
}