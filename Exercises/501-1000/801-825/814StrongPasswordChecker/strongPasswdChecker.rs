/*

2299. Strong Password Checker II
Easy
Topics
Companies
Hint
A password is said to be strong if it satisfies all the following criteria:

It has at least 8 characters.
It contains at least one lowercase letter.
It contains at least one uppercase letter.
It contains at least one digit.
It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).
Given a string password, return true if it is a strong password. Otherwise, return false.



Example 1:

Input: password = "IloveLe3tcode!"
Output: true
Explanation: The password meets all the requirements. Therefore, we return true.
Example 2:

Input: password = "Me+You--IsMyDream"
Output: false
Explanation: The password does not contain a digit and also contains 2 of the same character in adjacent positions. Therefore, we return false.
Example 3:

Input: password = "1aB!"
Output: false
Explanation: The password does not meet the length requirement. Therefore, we return false.


Constraints:

1 <= password.length <= 100
password consists of letters, digits, and special characters: "!@#$%^&*()-+".
Seen this question in a real interview before?
1/5
Yes
No
Accepted
41K
Submissions
74.9K
Acceptance Rate
54.7%

*/
use std::collections::HashSet;

impl Solution {
  pub fn strong_password_checker_ii(password: String) -> bool {

    if password.len() < 8 { return false }

    let mut has_lowercase = false;
    let mut has_uppercase = false;
    let mut has_digit = false;
    let specials = "!@#$%^&*()-+";
    let ss: HashSet<char> = specials.chars().collect();
    let mut has_special = false;
    let mut prev = '';
    for c in password.chars() {
      if c == prev { return false; }
      prev = c;
      if ss.contains(&c) { has_special = true; }
      let cv = c as u8;
      if cv >= 'a' as u8 && cv <= 'z' as u8 { has_lowercase = true; }
      if cv >= 'A' as u8 && cv <= 'Z' as u8 { has_uppercase = true; }
      if cv >= '0' as u8 && cv <= '9' as u8 { has_digit = true; }
    }
    has_lowercase && has_uppercase && has_digit && has_special;
  }
}