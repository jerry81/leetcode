/*

38. Count and Say
Medium
Topics
Companies
Hint
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.



Example 1:

Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
Example 2:

Input: n = 1

Output: "1"

Explanation:

This is the base case.



Constraints:

1 <= n <= 30


Follow up: Could you solve it iteratively?
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1M
Submissions
1.8M
Acceptance Rate
56.8%

*/

impl Solution {
  pub fn count_and_say(n: i32) -> String {
    if n == 1 { return "1".to_string() }

    let prev: String = Solution::count_and_say(n-1);
    let mut v_res: Vec<char> = vec![];
    let mut cur_c: char = '?';
    let mut cur_cnt: u8 = 0;
    for c in prev.chars() {
      if cur_c == c {
        cur_cnt += 1;
      } else {
        if cur_cnt != 0 {
          v_res.push((cur_cnt+'0' as u8) as char);
          v_res.push(cur_c);
        }
        cur_c = c;
        cur_cnt = 1;
      }
    }
    if cur_cnt != 0 {
      v_res.push((cur_cnt+'0' as u8) as char);
      v_res.push(cur_c);
    }
    v_res.into_iter().collect()
  }
}