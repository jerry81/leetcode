/*


1592. Rearrange Spaces Between Words
Easy
Topics
Companies
Hint
You are given a string text of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by at least one space. It's guaranteed that text contains at least one word.

Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent words and that number is maximized. If you cannot redistribute all the spaces equally, place the extra spaces at the end, meaning the returned string should be the same length as text.

Return the string after rearranging the spaces.



Example 1:

Input: text = "  this   is  a sentence "
Output: "this   is   a   sentence"
Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.
Example 2:

Input: text = " practice   makes   perfect"
Output: "practice   makes   perfect "
Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space. We place this extra space at the end of the string.


Constraints:

1 <= text.length <= 100
text consists of lowercase English letters and ' '.
text contains at least one word.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
54.4K
Submissions
125.5K
Acceptance Rate
43.4%

*/

impl Solution {
  pub fn reorder_spaces(text: String) -> String {
    let mut space_cnt = 0;
    for c in text.chars() {
      if c == ' ' { space_cnt += 1; }
    }
    if space_cnt == 0 { return text }
    let mut words: Vec<&str> = text.split(' ').filter(|&x| !x.is_empty()).collect();
    let wordcnt = words.len();
    let mut res: String = String::new();
    if wordcnt == 1 {
      res += words[0];
      res += &" ".repeat(space_cnt);
      return res;
    }
    let spaces_per = space_cnt / (wordcnt - 1);

    let rem = space_cnt % (wordcnt - 1);


    let tmpl = " ".repeat(spaces_per);

    for s in words {
      res+=&s;
      res+=&tmpl;
    }
    res = res[0..res.len()-spaces_per].to_string();
    res+=&" ".repeat(rem);
    res
  }
}