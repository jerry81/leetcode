/*
3169. Count Days Without Meetings
Medium
Topics
Companies
Hint
You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.



Example 1:

Input: days = 10, meetings = [[5,7],[1,3],[9,10]]

Output: 2

Explanation:

There is no meeting scheduled on the 4th and 8th days.

Example 2:

Input: days = 5, meetings = [[2,4],[1,3]]

Output: 1

Explanation:

There is no meeting scheduled on the 5th day.

Example 3:

Input: days = 6, meetings = [[1,6]]

Output: 0

Explanation:

Meetings are scheduled for all working days.



Constraints:

1 <= days <= 109
1 <= meetings.length <= 105
meetings[i].length == 2
1 <= meetings[i][0] <= meetings[i][1] <= days
Seen this question in a real interview before?
1/5
Yes
No
Accepted
52.3K
Submissions
140.1K
Acceptance Rate
37.3%
*/

impl Solution {
  pub fn count_days(days: i32, meetings: Vec<Vec<i32>>) -> i32 {
    let mut meetings = meetings.clone();
    meetings.sort_by_key(|item| item[0]);
    let mut last_day = 0;
    let mut res = 0;
    for m in meetings {
      if m[0] > last_day {
        res += m[0] - last_day - 1;
      }
      last_day = last_day.max(m[1]);
    }
    if last_day < days {
      res+=days - last_day;
    }

    res
  }
}

/*
123 4 567 8 9 10

1234 5

123456
*/
