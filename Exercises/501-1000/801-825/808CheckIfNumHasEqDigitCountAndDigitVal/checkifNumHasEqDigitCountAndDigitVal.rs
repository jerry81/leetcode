/*

2283. Check if Number Has Equal Digit Count and Digit Value
Easy
Topics
Companies
Hint
You are given a 0-indexed string num of length n consisting of digits.

Return true if for every index i in the range 0 <= i < n, the digit i occurs num[i] times in num, otherwise return false.



Example 1:

Input: num = "1210"
Output: true
Explanation:
num[0] = '1'. The digit 0 occurs once in num.
num[1] = '2'. The digit 1 occurs twice in num.
num[2] = '1'. The digit 2 occurs once in num.
num[3] = '0'. The digit 3 occurs zero times in num.
The condition holds true for every index in "1210", so return true.
Example 2:

Input: num = "030"
Output: false
Explanation:
num[0] = '0'. The digit 0 should occur zero times, but actually occurs twice in num.
num[1] = '3'. The digit 1 should occur three times, but actually occurs zero times in num.
num[2] = '0'. The digit 2 occurs zero times in num.
The indices 0 and 1 both violate the condition, so return false.


Constraints:

n == num.length
1 <= n <= 10
num consists of digits.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
56K
Submissions
77.7K
Acceptance Rate
72.1%

*/

use std::collections::HashMap;

impl Solution {
  pub fn digit_count(num: String) -> bool {
    let mut hm: HashMap<i32,i32> = HashMap::new();
    for c in num.chars() {
      let as_i = (c as u8 - '0' as u8) as i32;
      *hm.entry(as_i).or_insert(0) += 1;
    }
    let sz = num.len();
    for i in 0..sz {

      let c = num.chars().nth(i).unwrap();
      let ci = (c as u8 - '0' as u8) as i32;
      if hm.get(i).unwrap() != ci {
        return false
      }
    }
    true
  }
}