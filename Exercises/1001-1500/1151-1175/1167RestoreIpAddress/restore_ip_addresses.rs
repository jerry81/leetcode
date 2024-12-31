/*

93. Restore IP Addresses
Medium
Topics
Companies
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.



Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]


Constraints:

1 <= s.length <= 20
s consists of digits only.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
504.4K
Submissions
972.9K
Acceptance Rate
51.8%

*/

impl Solution {
  fn r(res: &mut Vec<String>, s: &str, idx: usize, num_dots: u8, cur: String) {
    if num_dots == 3 || idx >= s.len() { return }

    if num_dots == 2 {
      res.push((cur+"."+s[idx..]).to_string());
      return
    }
    let leading_c:char = s[idx];
    // check leading char for 0
    if leading_c == '0' {
      Solution::r(res, s, idx+1, num_dots+1, cur+"0.")
    } else if leading_c == '1' {
      // 100 - 199
      Solution::r(res, s, idx+1, num_dots+1, cur+"1.");
      Solution::r(res, s, idx+2, num_dots+1, cur+s[idx..idx+2]);
      Solution::r(res, s, idx+3, num_dots+1, cur+s[idx..idx+3]);
    } else if leading_c == '2' {
      // 200 - 255
      // need to be in bounds
      Solution::r(res, s, idx+1, num_dots+1, cur+"1.");
      if s.len() - idx > 2 {
        let second_c: char = s[idx+1];
        Solution::r(res, s, idx+2, num_dots+1, cur+s[idx..idx+2]);
        if s.len() - idx > 3 && second_c <= '5' {
          let third_c: char = s[idx+2];
          if third_c <= '5' {
            Solution::r(res, s, idx+3, num_dots+1, cur+s[idx..idx+3])
          }
        }
      }
    } else {
      // 2 digit
      Solution::r(res, s, idx+1, num_dots+1, cur+"1.");
      Solution::r(res, s, idx+2, num_dots+1, cur+s[idx..idx+2]);
    }
  }
  pub fn restore_ip_addresses(s: String) -> Vec<String> {
    // some kind of recursion
    let mut res: Vec<String> = vec![];
    Solution::r(&mut res, &s, 0, 0);
    res
  }
}