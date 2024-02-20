/*

2264. Largest 3-Same-Digit Number in String
Easy
394
20
Companies
You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.


Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.
Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.


Constraints:

3 <= num.length <= 1000
num only consists of digits.
Accepted
42.9K
Submissions
69.4K
Acceptance Rate
61.8%

*/

impl Solution {
  pub fn largest_good_integer(num: String) -> String {
      let mut ret = i32::MIN; // safer
      let mut ret_s = String::new(); // different initializer
      let sz = num.len();

      for i in 0..(sz - 2) { // parens for clarity
          let cur = &num[i..i + 3];
          if cur.chars().all(|c| c == cur.chars().next().unwrap()) { // replaces the char by char check
              if let Ok(cur_dig) = cur.parse::<i32>() { // safe parse
                  if cur_dig > ret { // snake case
                      ret_s = cur.to_string();
                      ret = cur_dig;
                  }
              }
          }
      }

      ret_s
  }
}