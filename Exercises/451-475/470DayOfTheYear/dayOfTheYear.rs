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

static DAYS_IN_MONTH: [u8; 12] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

impl Solution {
  fn parse_date(date_str: &str) -> Option<(u32, u32, u32)> {
    // Split the date string by '/'
    let mut parts = date_str.split('-');

    println!("parts split {}", date_str);

    // Attempt to parse each part as an integer
    let year: Option<u32> = parts.next()?.parse().ok();
    let month: Option<u32> = parts.next()?.parse().ok();
    let day: Option<u32> = parts.next()?.parse().ok();



    // If any part failed to parse, return None
    if year.is_none() || month.is_none() || day.is_none() {
        return None;
    }

    Some((year.unwrap(), month.unwrap(), day.unwrap()))
  }
  pub fn day_of_year(date: String) -> i32 {
    if let Some((year, month, day)) = Solution::parse_date(date.as_str()) {
      println!("Year: {}, Month: {}, Day: {}", year, month, day);
    } else {
      println!("ass");
      return 0;
    }
    return 0;
  }
}

/*
leap year rule
The year is multiple of 400.
The year is a multiple of 4 and not a multiple of 100.
*/