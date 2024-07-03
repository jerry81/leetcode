/*
2446. Determine if Two Events Have Conflict
Easy
Topics
Companies
Hint
You are given two arrays of strings that represent two inclusive events that happened on the same day, event1 and event2, where:

event1 = [startTime1, endTime1] and
event2 = [startTime2, endTime2].
Event times are valid 24 hours format in the form of HH:MM.

A conflict happens when two events have some non-empty intersection (i.e., some moment is common to both events).

Return true if there is a conflict between two events. Otherwise, return false.



Example 1:

Input: event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
Output: true
Explanation: The two events intersect at time 2:00.
Example 2:

Input: event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
Output: true
Explanation: The two events intersect starting from 01:20 to 02:00.
Example 3:

Input: event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
Output: false
Explanation: The two events do not intersect.


Constraints:

event1.length == event2.length == 2
event1[i].length == event2[i].length == 5
startTime1 <= endTime1
startTime2 <= endTime2
All the event times follow the HH:MM format.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
44.4K
Submissions
87.1K
Acceptance Rate
51.0%
*/

impl Solution {
  pub fn have_conflict(event1: Vec<String>, event2: Vec<String>) -> bool {
    let start1 = Solution::convert_to_seconds(&event1[0]);
    let end1 = Solution::convert_to_seconds(&event1[1]);
    let start2 = Solution::convert_to_seconds(&event2[0]);
    let end2 = Solution::convert_to_seconds(&event2[1]);
    start2 > start1 && start2 < end1 || start1 > start2 && start1 < end2
  }

  fn convert_to_minutes(time: &str) -> i32 {
    let h1 = time.chars().nth(0).unwrap();
    let h2 = time.chars().nth(1).unwrap();
    let m1 = time.chars().nth(3).unwrap();
    let m2 = time.chars().nth(4).unwrap();
    let c1 = h1 as u8 -'0' as u8;
    let c2 = h2 as u8 -'0' as u8;
    let c3 = m1 as u8 -'0' as u8;
    let c4 = m2 as u8 -'0' as u8;
    let mut res = 0;
    res+= c1 * 10*60;
    res+= c2 * 60;
    res+= m1*10;
    res+= m2;
    res
  }
}