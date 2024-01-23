/*

1360. Number of Days Between Two Dates
Easy
Topics
Companies
Hint
Write a program to count the number of days between two dates.

The two dates are given as strings, their format is YYYY-MM-DD as shown in the examples.



Example 1:

Input: date1 = "2019-06-29", date2 = "2019-06-30"
Output: 1
Example 2:

Input: date1 = "2020-01-15", date2 = "2019-12-31"
Output: 15


Constraints:

The given dates are valid dates between the years 1971 and 2100.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
47.4K
Submissions
96.2K
Acceptance Rate
49.3%

*/

impl Solution {
  pub fn days_between_dates(date1: String, date2: String) -> i32 {
    // split into year, month day
    let v1: Vec<String> = date1.split('-').map(String::from).collect(); // map works on iterator
    let v2: Vec<String> = date2.split('-').map(String::from).collect();
    let (y1, m1, d1) : (i32, i32, i32) = ((&v1[0]).parse().unwrap(), (&v1[1]).parse().unwrap(), (&v1[2]).parse().unwrap());
    let (y2, m2, d2) : (i32, i32, i32) = ((&v2[0]).parse().unwrap(), (&v2[1]).parse().unwrap(), (&v2[2]).parse().unwrap());

    let (fy, sy, fm, sm, fd, sd) = if (y1, m1, d1) > (y2, m2, d2) {
      (y2, y1, m2, m1, d2, d1)
    } else {
      (y1, y2, m1, m2, d1, d2)
    };


    println!("first date is {}-{}-{}", fy, fm, fd);

    if fy == sy {
      if fm == sm {
        return sd - fd;
      }
    }
    0
  }
}

