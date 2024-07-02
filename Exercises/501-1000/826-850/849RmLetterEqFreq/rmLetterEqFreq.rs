/*

2423. Remove Letter To Equalize Frequency
Easy
Topics
Companies
Hint
You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.

Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.

Note:

The frequency of a letter x is the number of times it occurs in the string.
You must remove exactly one letter and cannot choose to do nothing.


Example 1:

Input: word = "abcc"
Output: true
Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.
Example 2:

Input: word = "aazz"
Output: false
Explanation: We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.


Constraints:

2 <= word.length <= 100
word consists of lowercase English letters only.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
46.3K
Submissions
266.6K
Acceptance Rate
17.4%

*/
// double freq map?
use std::collections::HashMap;

impl Solution {
  pub fn equal_frequency(word: String) -> bool {
    let mut freq: HashMap<char, i32> = HashMap::new();
    let mut fof: HashMap<i32, i32> = HashMap::new();
    for c in word.chars() {
      *freq.entry(c).or_insert(0) +=1;
    }
    for (_,f) in &freq {
      *fof.entry(*f).or_insert(0)+=1;
    }

    // edge 1: when all 1s, removing doesn't change freq
    // case "abc"
    if fof.len() == 1 && fof.contains_key(&1) {
      return true
    }

    // we are looking for
    // # of keys - 2 and the key with one greater key has a freq of 1
    if fof.len() != 2 { return false }

    let mut sorted:Vec<(&i32,&i32)>=fof.iter().collect();
    sorted.sort_by(|a,b| { b.0.cmp(&a.0)});
    *(sorted.clone().get(1).unwrap()).0 == 1
  }
}