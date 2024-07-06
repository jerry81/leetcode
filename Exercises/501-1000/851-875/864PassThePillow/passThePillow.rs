/*

2582. Pass the Pillow
Easy
Topics
Companies
Hint
There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.



Example 1:

Input: n = 4, time = 5
Output: 2
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
After five seconds, the 2nd person is holding the pillow.
Example 2:

Input: n = 3, time = 2
Output: 3
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
After two seconds, the 3rd person is holding the pillow.


Constraints:

2 <= n <= 1000
1 <= time <= 1000
Seen this question in a real interview before?
1/5
Yes
No
Accepted
56.2K
Submissions
110.3K
Acceptance Rate
50.9%

*/

impl Solution {
  pub fn pass_the_pillow(n: i32, time: i32) -> i32 {
    Solution::ptp(n, time, 1);
  }

  fn ptp(n: i32, time: i32, cur: usize, forwards: bool) -> i32 {
    if time == 0 {
      cur
    } else {
      let mut nxt = cur+1;
      let mut dir = forwards;
      if cur == n && forwards {
        dir = backwards;
      } else if cur == 1 && backwards {
        dir = forwards;
      }
      if dir == backwards {
        nxt = cur-1;
      }
      Solution::ptp(n, time-1, nxt, dir)
    }
  }
}