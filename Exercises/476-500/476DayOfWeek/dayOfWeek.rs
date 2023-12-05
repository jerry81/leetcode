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

static DAYS_IN_MONTH: [u8; 12] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

impl Solution {
  fn is_leap_year(yr:u32) -> bool {
    if yr % 400 == 0 { return true; }

    if yr % 4 == 0 && yr % 100 != 0 { return true; }

    return false;
  }

  pub fn day_of_year(day: i32, month: i32, year: i32) -> i32 {
    let mut res:i32 = 0;
    let lp:bool = Solution::is_leap_year(year as u32);
    // if (month == 1) { return day as i32; } // TIL: "as" is powerful
    for i in 0..month-1 { // TIL: this is the traditional for
      res+=DAYS_IN_MONTH[i as usize] as i32;
      if (i == 1 && lp) { res+= 1; }
    }
    res+=day as i32;

    return res;
  }

  pub fn day_of_the_week(day: i32, month: i32, year: i32) -> String {
    // number of days from today
    // % 7 gives the offset from the day
    let myDay = Solution::day_of_year(5,12,2023);
    let thatDay = Solution::day_of_year(day,month,year);
    let mut ydiff = 2023 - year;
    let mut mdiff = 12 - month;
    let mut ddiff = 5 - day;
    let mut totalDiff = 0;
    let mut future = false;
    if year > 2023 {
      future = true;
      for i in 2024..year {
        let to_add = if Solution::is_leap_year(i as u32) { 366 } else { 365 }; //TODO: extract
        totalDiff += to_add;
      }
      totalDiff += 365;
      totalDiff -= myDay;
      totalDiff += thatDay;
    } else if year < 2023 {
      for i in year..2023 {
        let to_add = if Solution::is_leap_year(i as u32) { 366 } else { 365 };
        totalDiff += to_add;
      }
      totalDiff+= myDay;
      totalDiff+=365;
      totalDiff-=thatDay;
    } else {
        if thatDay < myDay {
          totalDiff = myDay - thatDay;
        } else {
          future = true;
          totalDiff = thatDay - myDay;
        }
    }
    totalDiff %= 7;
    if future {
      if totalDiff == 0 {
        return "Tuesday".to_string();
      } else if totalDiff == 1 {
        return "Wednesday".to_string();
      } else if totalDiff == 2 {
        return "Thursday".to_string();
      } else if totalDiff == 3 {
        return "Friday".to_string();
      } else if totalDiff == 4 {
        return "Saturday".to_string();
      } else if totalDiff == 5 {
        return "Sunday".to_string();
      } else {
        return "Monday".to_string();
      }
    } else {
      if totalDiff == 0 {
        return "Wednesday".to_string();
      } else if totalDiff == 1 {
        return "Tuesday".to_string();
      } else if totalDiff == 2 {
        return "Monday".to_string();
      } else if totalDiff == 3 {
        return "Sunday".to_string();
      } else if totalDiff == 4 {
        return "Saturday".to_string();
      } else if totalDiff == 5 {
        return "Friday".to_string();
      } else {
        return "Thursday".to_string();
      }
    }
    "Tuesday".to_string();
  }
}