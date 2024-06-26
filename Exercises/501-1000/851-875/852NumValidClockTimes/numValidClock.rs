/*


2437. Number of Valid Clock Times
Easy
Topics
Companies
Hint
You are given a string of length 5 called time, representing the current time on a digital clock in the format "hh:mm". The earliest possible time is "00:00" and the latest possible time is "23:59".

In the string time, the digits represented by the ? symbol are unknown, and must be replaced with a digit from 0 to 9.

Return an integer answer, the number of valid clock times that can be created by replacing every ? with a digit from 0 to 9.



Example 1:

Input: time = "?5:00"
Output: 2
Explanation: We can replace the ? with either a 0 or 1, producing "05:00" or "15:00". Note that we cannot replace it with a 2, since the time "25:00" is invalid. In total, we have two choices.
Example 2:

Input: time = "0?:0?"
Output: 100
Explanation: Each ? can be replaced by any digit from 0 to 9, so we have 100 total choices.
Example 3:

Input: time = "??:??"
Output: 1440
Explanation: There are 24 possible choices for the hours, and 60 possible choices for the minutes. In total, we have 24 * 60 = 1440 choices.


Constraints:

time is a valid string of length 5 in the format "hh:mm".
"00" <= hh <= "23"
"00" <= mm <= "59"
Some of the digits might be replaced with '?' and need to be replaced with digits from 0 to 9.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
31.4K
Submissions
67.2K
Acceptance Rate
46.7%

*/

impl Solution {
  pub fn count_time(time: String) -> i32 {
    let c1 = time.chars().nth(0).unwrap();
    let c2 = time.chars().nth(1).unwrap();
    let c3 = time.chars().nth(3).unwrap();
    let c4 = time.chars().nth(4).unwrap();
    let u2 = c2 as u8 - '0' as u8;
    let mut h = 1;
    let mut m = 1;
    if c1 == '?' {
      if c2 == '?' {
        h = 24;
      } else {
        if u2 <= 3 {
          h = 3;
        } else {
          h = 2;
        }
      }
    } else {
      if c2 == '?' {
        if c1 == '2' {
          h = 4;
        } else {
          h = 10;
        }
      }
    }

    if c3 == '?' {
      if c4 == '?' {
        m = 60;
      } else {
        m = 6;
      }
    } else {
      if c4 == '?' {
        m = 10;
      }

    }
    h*m
  }
}