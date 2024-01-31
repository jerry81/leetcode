/*

1507. Reformat Date
Easy
Topics
Companies
Hint
Given a date string in the form Day Month Year, where:

Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
Year is in the range [1900, 2100].
Convert the date string to the format YYYY-MM-DD, where:

YYYY denotes the 4 digit year.
MM denotes the 2 digit month.
DD denotes the 2 digit day.


Example 1:

Input: date = "20th Oct 2052"
Output: "2052-10-20"
Example 2:

Input: date = "6th Jun 1933"
Output: "1933-06-06"
Example 3:

Input: date = "26th May 1960"
Output: "1960-05-26"


Constraints:

The given dates are guaranteed to be valid, so no error handling is necessary.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
67.2K
Submissions
103.3K
Acceptance Rate
65.1%

*/

use std::collections::HashMap;

impl Solution {
  pub fn reformat_date(date: String) -> String {
    let mut hm: HashMap<&str, &str> = HashMap::new();
    hm.insert("Jan", "01");
    hm.insert("Feb", "02");
    hm.insert("Mar", "03");
    hm.insert("Apr", "04");
    hm.insert("May", "05");
    hm.insert("Jun", "06");
    hm.insert("Jul", "07");
    hm.insert("Aug", "08");
    hm.insert("Sep", "09");
    hm.insert("Oct", "10");
    hm.insert("Nov", "11");
    hm.insert("Dec", "12");

    let mut spl: Vec<&str> = date.split(' ').collect();
    let mut cnt = 0;
    let mut res = String::new();
    for s in spl.iter().rev() {
        if cnt == 0 {
          res+=s;
          res+="-";
        } else if cnt == 1 {
          match hm.get(s) {
            Some(v) => {
                res+=v;
                res+="-";
            },
            None => { println!("that's fucked"); }
          }
        } else {

        }
        cnt +=1;
    }
    res
  }
}