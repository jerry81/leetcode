/*

1185. Day of the Week
Easy
367
2.4K
Companies
Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.



Example 1:

Input: day = 31, month = 8, year = 2019
Output: "Saturday"
Example 2:

Input: day = 18, month = 7, year = 1999
Output: "Sunday"
Example 3:

Input: day = 15, month = 8, year = 1993
Output: "Sunday"


Constraints:

The given dates are valid dates between the years 1971 and 2100.
Accepted
60.2K
Submissions
105.3K
Acceptance Rate
57.2%

*/

impl Solution {
  pub fn day_of_the_week(day: i32, month: i32, year: i32) -> String {
    // number of days from today
    // % 7 gives the offset from the day
    let mut ydiff = 2023 - year;
    let mut mdiff = 12 - month;
    let mut ddiff = 5 - day;
    println!("days {}", ddiff);
    println!("months {}", mdiff);
    println!("years {}", ydiff);
    "Monday"
  }
}