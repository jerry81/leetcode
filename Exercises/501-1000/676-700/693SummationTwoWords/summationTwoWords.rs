/*

1880. Check if Word Equals Summation of Two Words
Easy
Topics
Companies
Hint
The letter value of a letter is its position in the alphabet starting from 0 (i.e. 'a' -> 0, 'b' -> 1, 'c' -> 2, etc.).

The numerical value of some string of lowercase English letters s is the concatenation of the letter values of each letter in s, which is then converted into an integer.

For example, if s = "acb", we concatenate each letter's letter value, resulting in "021". After converting it, we get 21.
You are given three strings firstWord, secondWord, and targetWord, each consisting of lowercase English letters 'a' through 'j' inclusive.

Return true if the summation of the numerical values of firstWord and secondWord equals the numerical value of targetWord, or false otherwise.



Example 1:

Input: firstWord = "acb", secondWord = "cba", targetWord = "cdb"
Output: true
Explanation:
The numerical value of firstWord is "acb" -> "021" -> 21.
The numerical value of secondWord is "cba" -> "210" -> 210.
The numerical value of targetWord is "cdb" -> "231" -> 231.
We return true because 21 + 210 == 231.
Example 2:

Input: firstWord = "aaa", secondWord = "a", targetWord = "aab"
Output: false
Explanation:
The numerical value of firstWord is "aaa" -> "000" -> 0.
The numerical value of secondWord is "a" -> "0" -> 0.
The numerical value of targetWord is "aab" -> "001" -> 1.
We return false because 0 + 0 != 1.
Example 3:

Input: firstWord = "aaa", secondWord = "a", targetWord = "aaaa"
Output: true
Explanation:
The numerical value of firstWord is "aaa" -> "000" -> 0.
The numerical value of secondWord is "a" -> "0" -> 0.
The numerical value of targetWord is "aaaa" -> "0000" -> 0.
We return true because 0 + 0 == 0.


Constraints:

1 <= firstWord.length, secondWord.length, targetWord.length <= 8
firstWord, secondWord, and targetWord consist of lowercase English letters from 'a' to 'j' inclusive.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
64.1K
Submissions
86.6K
Acceptance Rate
74.0%

*/

impl Solution {
  pub fn is_sum_equal(first_word: String, second_word: String, target_word: String) -> bool {
    let v1 = Solution::summation(first_word);
    let v2 = Solution::summation(second_word);
    let vt = Solution::summation(target_word);
    v1+v2 == vt
  }

  fn summation(word:String) -> i32 {
    let mut as_str = String::new();
    let mut non_zero_found = false;

    for c in word.chars() {
      if c == 'a' && !non_zero_found {
        continue;
      }
      non_zero_found = true;
      as_str.push((c as u8 - 97 + '0' as u8) as char);
    }
    if as_str.is_empty() && !word.is_empty() {
        as_str = "0".to_string();
    }

    as_str.parse().unwrap_or(0)
  }
}