/*
2224. Minimum Number of Operations to Convert Time
Easy
Topics
Companies
Hint
You are given two strings current and correct representing two 24-hour times.

24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.

In one operation you can increase the time current by 1, 5, 15, or 60 minutes. You can perform this operation any number of times.

Return the minimum number of operations needed to convert current to correct.



Example 1:

Input: current = "02:30", correct = "04:35"
Output: 3
Explanation:
We can convert current to correct in 3 operations as follows:
- Add 60 minutes to current. current becomes "03:30".
- Add 60 minutes to current. current becomes "04:30".
- Add 5 minutes to current. current becomes "04:35".
It can be proven that it is not possible to convert current to correct in fewer than 3 operations.
Example 2:

Input: current = "11:00", correct = "11:01"
Output: 1
Explanation: We only have to add one minute to current, so the minimum number of operations needed is 1.


Constraints:

current and correct are in the format "HH:MM"
current <= correct
Seen this question in a real interview before?
1/5
Yes
No
Accepted
41.1K
Submissions
63.1K
Acceptance Rate
65.1%

*/

impl Solution {
  pub fn convert_time(current: String, correct: String) -> i32 {
    let current_spl: Vec<&str> = current.split(":").collect();
    let correct_spl: Vec<&str> = correct.split(":").collect();
    let cur_hr = current_spl[0];
    let cur_min = current_spl[1];
    let cor_hr = correct_spl[0];
    let cor_min = correct_spl[1];
    let mut cur_h = 0;
    let mut cor_h = 0;
    cur_h += ((cur_hr.chars().nth(0).unwrap() as u8 - '0' as u8) * 10) as i32;
    cur_h += (cur_hr.chars().nth(1).unwrap() as u8 - '0' as u8) as i32;
    println!("cur h {}", cur_h);
    0
  }
}
