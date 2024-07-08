/*

2490. Circular Sentence
Easy
Topics
Companies
Hint
A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.

A sentence is circular if:

The last character of a word is equal to the first character of the next word.
The last character of the last word is equal to the first character of the first word.
For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.

Given a string sentence, return true if it is circular. Otherwise, return false.



Example 1:

Input: sentence = "leetcode exercises sound delightful"
Output: true
Explanation: The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
- leetcode's last character is equal to exercises's first character.
- exercises's last character is equal to sound's first character.
- sound's last character is equal to delightful's first character.
- delightful's last character is equal to leetcode's first character.
The sentence is circular.
Example 2:

Input: sentence = "eetcode"
Output: true
Explanation: The words in sentence are ["eetcode"].
- eetcode's last character is equal to eetcode's first character.
The sentence is circular.
Example 3:

Input: sentence = "Leetcode is cool"
Output: false
Explanation: The words in sentence are ["Leetcode", "is", "cool"].
- Leetcode's last character is not equal to is's first character.
The sentence is not circular.


Constraints:

1 <= sentence.length <= 500
sentence consist of only lowercase and uppercase English letters and spaces.
The words in sentence are separated by a single space.
There are no leading or trailing spaces.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
39.8K
Submissions
63.4K
Acceptance Rate
62.8%

*/

impl Solution {
  pub fn is_circular_sentence(sentence: String) -> bool {
    let mut Vec<&str> words = sentence.split().collect();
    if words.len() == 1 {
      words[0].chars().next().unwrap() == words[0].last().unwrap()
    } else {
      let finalmatch = words[0].chars().next().unwrap();
      let mut curmatch = words[0].chars().last().unwrap();
      for w in words.skip(1) {
        let nxtchar = w.chars().next().unwrap();
        if nxtchar != curmatch { return false }
        curmatch = nxtchar;
      }
      curmatch == finalmatch
    }
  }
}