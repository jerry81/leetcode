/*

3306. Count of Substrings Containing Every Vowel and K Consonants II
Medium
Topics
Companies
Hint
You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.



Example 1:

Input: word = "aeioqq", k = 1

Output: 0

Explanation:

There is no substring with every vowel.

Example 2:

Input: word = "aeiou", k = 0

Output: 1

Explanation:

The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Example 3:

Input: word = "ieaouqqieaouqq", k = 1

Output: 3

Explanation:

The substrings with every vowel and one consonant are:

word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".


Constraints:

5 <= word.length <= 2 * 105
word consists only of lowercase English letters.
0 <= k <= word.length - 5
Seen this question in a real interview before?
1/5
Yes
No
Accepted
16.2K
Submissions
63.4K
Acceptance Rate
25.5%

*/
use std::collections::HashMap;
use std::collections::HashSet;

impl Solution {

  pub fn count_of_substrings(word: String, k: i32) -> i64 {
    let mut v_f: HashMap<char,i32> = HashMap::new();
    // substring is contiguous
    // breaking it down
    // all substrings
    // maintain counts of each vowel and total consonants
    // optimization:  sliding window - only consider when all vowels are in
    let mut VOWELS: HashSet<char> = HashSet::new();
    VOWELS.insert('a');
    VOWELS.insert('e');
    VOWELS.insert('i');
    VOWELS.insert('o');
    VOWELS.insert('u');

    let mut constanant_count = 0;
    let mut res:i64 = 0;
    let n = word.len();
    let mut left: usize = -1;
    let mut right: usize = 0;
    loop do {
      // apply right
      let rc = word.chars().nth(right).unwrap();
      if VOWELS.contains(&rc) {
        *v_f.entry(rc).or_insert(0) +=1;
      } else {
        constanant_count +=1;
      }
      println!("consanant+count is now {}", constanant_count);
      println!("vf is {:?}", v_f);
      // cconstraints not met increase right
      if v_f.len() < 5 || constant_count < k {
        right+=1;
        if right >= n { break; }
        continue;
      }

    }
    res
  }
}