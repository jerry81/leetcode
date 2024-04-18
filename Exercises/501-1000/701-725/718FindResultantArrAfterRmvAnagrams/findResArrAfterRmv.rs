/*


2273. Find Resultant Array After Removing Anagrams
Easy
Topics
Companies
Hint
You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.

In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i] are anagrams, and delete words[i] from words. Keep performing this operation as long as you can select an index that satisfies the conditions.

Return words after performing all operations. It can be shown that selecting the indices for each operation in any arbitrary order will lead to the same result.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters exactly once. For example, "dacb" is an anagram of "abdc".



Example 1:

Input: words = ["abba","baba","bbaa","cd","cd"]
Output: ["abba","cd"]
Explanation:
One of the ways we can obtain the resultant array is by using the following operations:
- Since words[2] = "bbaa" and words[1] = "baba" are anagrams, we choose index 2 and delete words[2].
  Now words = ["abba","baba","cd","cd"].
- Since words[1] = "baba" and words[0] = "abba" are anagrams, we choose index 1 and delete words[1].
  Now words = ["abba","cd","cd"].
- Since words[2] = "cd" and words[1] = "cd" are anagrams, we choose index 2 and delete words[2].
  Now words = ["abba","cd"].
We can no longer perform any operations, so ["abba","cd"] is the final answer.
Example 2:

Input: words = ["a","b","c","d","e"]
Output: ["a","b","c","d","e"]
Explanation:
No two adjacent strings in words are anagrams of each other, so no operations are performed.


Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
57.9K
Submissions
99.9K
Acceptance Rate
58.0%

*/

use std::collections::HashMap;

impl Solution {
  pub fn remove_anagrams(words: Vec<String>) -> Vec<String> {
    let mut cw = words.clone();
    let mut changed = true;
    while !cw.len() > 1 && changed {
      changed = false;
      let f = &cw[0];
      let s = &cw[1];
      if Solution::are_ana(f,s) {
        cw.remove(1);
        changed = true;
      }
    }
    cw
  }

  fn are_ana(w1: &String, w2: &String) -> bool {
    let mut hm1:HashMap<char,i32> = HashMap::new();
    let mut hm2:HashMap<char,i32> = HashMap::new();
    for c in w1.chars() {
      *hm1.entry(c).or_insert(0) +=1;
    }
    for c in w2.chars() {
      *hm2.entry(c).or_insert(0) +=1;
    }

    for (k,v) in &hm1 {
      if hm2[k] != *v { return false; }
    }
    for (k,v) in &hm2 {
      if hm1[k] != *v { return false; }
    }

    true
  }
}