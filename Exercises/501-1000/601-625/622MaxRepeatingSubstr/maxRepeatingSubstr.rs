/*


1668. Maximum Repeating Substring
Easy
Topics
Companies
Hint
For a string sequence, a string word is k-repeating if word concatenated k times is a substring of sequence. The word's maximum k-repeating value is the highest value k where word is k-repeating in sequence. If word is not a substring of sequence, word's maximum k-repeating value is 0.

Given strings sequence and word, return the maximum k-repeating value of word in sequence.



Example 1:

Input: sequence = "ababc", word = "ab"
Output: 2
Explanation: "abab" is a substring in "ababc".
Example 2:

Input: sequence = "ababc", word = "ba"
Output: 1
Explanation: "ba" is a substring in "ababc". "baba" is not a substring in "ababc".
Example 3:

Input: sequence = "ababc", word = "ac"
Output: 0
Explanation: "ac" is not a substring in "ababc".


Constraints:

1 <= sequence.length <= 100
1 <= word.length <= 100
sequence and word contains only lowercase English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
44.4K
Submissions
114.7K
Acceptance Rate
38.7%

*/
impl Solution {
  pub fn max_repeating(sequence: String, word: String) -> i32 {
    let mut max_repeats = 0;
    let word_len = word.len();
    if word_len > sequence.len() { return 0 } // edge case

    for i in 0..=(sequence.len() - word_len) { // for each index
        let substring = &sequence[i..i + word_len]; // string slice
        let mut repeats = 0; // reset
        let mut j = i;
        while j + word_len <= sequence.len() && &sequence[j..j + word_len] == word { // while with increment
            repeats += 1;
            j += word_len;
        }
        max_repeats = max_repeats.max(repeats);
    }

    max_repeats
}
}