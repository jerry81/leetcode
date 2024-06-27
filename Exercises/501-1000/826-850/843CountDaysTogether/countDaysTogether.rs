/*

2409. Count Days Spent Together
Easy
Topics
Companies
Hint
Alice and Bob are traveling to Rome for separate business meetings.

You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.

Return the total number of days that Alice and Bob are in Rome together.

You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].



Example 1:

Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
Output: 3
Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.
Example 2:

Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
Output: 0
Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.


Constraints:

All dates are provided in the format "MM-DD".
Alice and Bob's arrival dates are earlier than or equal to their leaving dates.
The given dates are valid dates of a non-leap year.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
22.8K
Submissions
50.8K
Acceptance Rate
45.0%

*/

impl Solution {

  pub fn count_days_together(arrive_alice: String, leave_alice: String, arrive_bob: String, leave_bob: String) -> i32 {
    let (aam, aad) = Solution::parse_date(&arrive_alice);
    let (lam, lad) = Solution::parse_date(&leave_alice);
    let (abm, abd) = Solution::parse_date(&arrive_bob);
    let (lbm, lbd) = Solution::parse_date(&leave_bob);
    let mut alice_arrive_day = Solution::month_to_day_of_year(aam) + aad;
    let mut alice_leave_day = Solution::month_to_day_of_year(lam) + lad;
    let bob_arrive_day = Solution::month_to_day_of_year(abm) + abd;
    let bob_leave_day = Solution::month_to_day_of_year(lbm) + lbd;
    alice_arrive_day = alice_arrive_day.max(bob_arrive_day);
    alice_leave_day = alice_leave_day.min(bob_leave_day);
    let mut res = alice_leave_day - alice_arrive_day;
    res.max(0);
  }

  fn month_to_day_of_year(m: i32) -> i32 {
    let months:Vec<i32> = vec![31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    months[0..(m-1) as usize].iter().sum()
  }

  fn parse_date(date: &str) -> (i32, i32) { // TIL tuple
    let parts: Vec<&str> = date.split('-').collect();
    let month: i32 = parts[0].parse().expect("Invalid month");
    let day: i32 = parts[1].parse().expect("Invalid day");
    (month, day)
  }
}