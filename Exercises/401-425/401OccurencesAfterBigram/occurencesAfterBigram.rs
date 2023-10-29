/*

1078. Occurrences After Bigram
Easy
462
349
Companies
Given two strings first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.

Return an array of all the words third for each occurrence of "first second third".



Example 1:

Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]
Example 2:

Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]


Constraints:

1 <= text.length <= 1000
text consists of lowercase English letters and spaces.
All the words in text a separated by a single space.
1 <= first.length, second.length <= 10
first and second consist of lowercase English letters.
Accepted
66.7K
Submissions
105.2K
Acceptance Rate
63.4%

*/

impl Solution {
  pub fn find_ocurrences(text: String, first: String, second: String) -> Vec<String> {
    let split_result: Vec<&str> = text.split(' ').collect();
    let ret = Vec::new();
    let fst = false;
    let sec = false;
    for s in split_result {
      if s == first {
        fst = true;
        sec = false;
      } else if fst && s == second {
        ret.push(s);
        fst = false;
        sec = false;
      } else {
        fst = false;
        sec = false;
      }
    }
  }
}