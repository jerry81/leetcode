/*

1736. Latest Time by Replacing Hidden Digits
Easy
Topics
Companies
Hint
You are given a string time in the form of  hh:mm, where some of the digits in the string are hidden (represented by ?).

The valid times are those inclusively between 00:00 and 23:59.

Return the latest valid time you can get from time by replacing the hidden digits.



Example 1:

Input: time = "2?:?0"
Output: "23:50"
Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
Example 2:

Input: time = "0?:3?"
Output: "09:39"
Example 3:

Input: time = "1?:22"
Output: "19:22"


Constraints:

time is in the format hh:mm.
It is guaranteed that you can produce a valid time from the given string.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
34.4K
Submissions
80.7K
Acceptance Rate
42.6%

*/

impl Solution {
  pub fn maximum_time(time: String) -> String {
    // hh:mm
    let mut res: String = String::new();

    let mut h1 = time.chars().nth(0).unwrap();
    let h2 = time.chars().nth(1).unwrap();
    let m1 = time.chars().nth(3).unwrap();
    let m2 = time.chars().nth(4).unwrap();
    // only one tricky case - h2 is set

    let valid_20th_hr = vec!['0','1','2','3','?'];
    if h1 == '?' {
      if valid_20th_hr.contains(&h2) {
        res.push('2');
        h1 = '2';
      } else {
        res.push('1');
      }
    } else {
      res.push(h1);
    }

    if h2 == '?' {
      if h1 == '2' {
        res.push('3');
      } else {
        res.push('9');
      }
    } else {
      res.push(h2);
    }
    res.push(':');
    if m1 == '?' {
      res.push('5');
    } else {
      res.push(m1);
    }

    if m2 == '?' {
      res.push('9');
    } else {
      res.push(m2);
    }

    res
  }
}