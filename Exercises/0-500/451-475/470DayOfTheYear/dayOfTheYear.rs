/*
1154. Day of the Year
Easy
418
456
Companies
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.



Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
Example 2:

Input: date = "2019-02-10"
Output: 41


Constraints:

date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31th, 2019.
Accepted
52K
Submissions
106.6K
Acceptance Rate
48.8%
*/

// TIL: you can put a global static var outside of impl
static DAYS_IN_MONTH: [u8; 12] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

impl Solution {
  fn is_leap_year(yr:u32) -> bool {
    if yr % 400 == 0 { return true; }

    if yr % 4 == 0 && yr % 100 != 0 { return true; }

    return false;
  }
  fn parse_date(date_str: &str) -> Option<(u32, u32, u32)> { // TIL: Option comes OOB, wrap a "tuple" inside?
    // Split the date string by '/'
    let mut parts = date_str.split('-'); // TIL: split is a thing

    // Attempt to parse each part as an integer
    let year: Option<u32> = parts.next()?.parse().ok();
    let month: Option<u32> = parts.next()?.parse().ok();
    let day: Option<u32> = parts.next()?.parse().ok(); // TIL: next(), parse(), ok()



    // If any part failed to parse, return None
    if year.is_none() || month.is_none() || day.is_none() {
        return None; // TIL: flexibility of Option
    }

    Some((year.unwrap(), month.unwrap(), day.unwrap())) // TIL: - Unwrap un-options it
  }
  pub fn day_of_year(date: String) -> i32 {
    let mut res:i32 = 0;
    if let Some((year, month, day)) = Solution::parse_date(date.as_str()) { // TIL: String and str are not the same
      // TIL you must handle the NONE case of Some
      let lp:bool = Solution::is_leap_year(year);
      if (month == 1) { return day as i32; } // TIL: "as" is powerful

      for i in 0..month-1 { // TIL: this is the traditional for
        res+=DAYS_IN_MONTH[i as usize] as i32;
        if (i == 1 && lp) { res+= 1; }
      }
      res+=day as i32;
    } else {
      return 0;
    }
    return res;
  }
}

/*
leap year rule
The year is multiple of 400.
The year is a multiple of 4 and not a multiple of 100.
*/