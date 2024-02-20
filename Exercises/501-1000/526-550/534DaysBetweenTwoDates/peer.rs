use std::str::FromStr; // completely different approach - gets the "absolute" number of days from year 0 with parse method.

impl Solution {
    pub fn days_between_dates(date1: String, date2: String) -> i32 {
        return (parse(date1) - parse(date2)).abs(); // put the fn outside
    }
}

const DAYS_IN_MONTH: [i32; 13] = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]; // old school array

fn parse(date: String) -> i32 {
    let s = date.as_str();

    let year = i32::from_str(&s[0..4]).unwrap(); // no split, but rather knows about fixed length, and slices (substr)
    let month = i32::from_str(&s[5..7]).unwrap() - 1;
    let day = i32::from_str(&s[8..10]).unwrap() - 1;

    let mut result = 0;
    result += year * 365;
    { // count february's extra days for previous leap years
        result += (year-1) / 4;
        result -= (year-1) / 100;
        result += (year-1) / 400;
    }

    for i in 0..=month {
        result += DAYS_IN_MONTH[i as usize];
    }
    let leap: bool = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    if leap && month > 1 { // after february in leap year turn 28 into 29
        result += 1;
    }

    result += day;

    return result;
}