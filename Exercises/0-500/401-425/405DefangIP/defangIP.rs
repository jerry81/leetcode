/*
1108. Defanging an IP Address
Easy
1.9K
1.7K
Companies
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".



Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"


Constraints:

The given address is a valid IPv4 address.
Accepted
576.7K
Submissions
648.8K
Acceptance Rate
88.9%
*/

impl Solution {
  pub fn defang_i_paddr(address: String) -> String {
    let mut ret = Vec::new();
    for c in address.chars() {
      if c == '.' {
        ret.push('[');
        ret.push('.');
        ret.push(']');
      } else {
        ret.push(c);
      }
    }
    ret.iter().collect()
  }
}