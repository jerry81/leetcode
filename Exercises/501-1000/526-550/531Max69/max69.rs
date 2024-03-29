/*

1323. Maximum 69 Number
Easy
Topics
Companies
Hint
You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).



Example 1:

Input: num = 9669
Output: 9969
Explanation:
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.


Constraints:

1 <= num <= 104
num consists of only 6 and 9 digits.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
246.3K
Submissions
300K
Acceptance Rate
82.1%

*/

impl Solution {
  pub fn maximum69_number (num: i32) -> i32 {
    let mut v: Vec<char> = Vec::new();
    let mut replaced = false;
    for mut c in num.to_string().chars() { // mut in loop!
      if !replaced && c == '6' {
       replaced = true;
       c = '9';
      }
      v.push(c);
    }
    let char_string: String = v.into_iter().collect(); // split it into 2 lines!
    char_string.parse::<i32>().unwrap()
  }
}