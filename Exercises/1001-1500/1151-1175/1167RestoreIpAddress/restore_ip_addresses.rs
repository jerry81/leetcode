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
  fn is_valid_segment(s: &str) -> bool {
    if s.len() == 1 { return true }
    if s.len() > 3 { return false }

    if s.starts_with('0') && s.len() > 1 { return false }
    let n = s.parse::<u16>().unwrap();
    if n > 255 { return false }
    true
  }

  fn r(res: &mut Vec<String>, s: &str, idx: usize, num_dots: u8, cur: String) {

    if num_dots == 4 || idx >= s.len() { return }

    if num_dots == 3 {
      let remaining_segment: String = s[idx..].to_string();
      if Solution::is_valid_segment(&remaining_segment){
        res.push((cur+&remaining_segment).to_string());
      }
      return
    }

    // try len 1, 2, 3
    let chars_remaining = 3.min(s.len() - idx);
    for i in 1..=chars_remaining {
      let segment: String = s[idx..idx+i].to_string();
      if Solution::is_valid_segment(&segment) {
        Solution::r(res, s, idx + i, num_dots + 1, cur.clone() + &segment + ".");
      }
    }
  }

  pub fn restore_ip_addresses(s: String) -> Vec<String> {
    if s.is_empty() || s.len() > 12 { return vec![] }
    let mut res: Vec<String> = vec![];
    Solution::r(&mut res, &s, 0, 0, String::new());
    res
  }
}