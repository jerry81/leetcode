/*

2259. Remove Digit From Number to Maximize Result
Easy
Topics
Companies
Hint
You are given a string number representing a positive integer and a character digit.

Return the resulting string after removing exactly one occurrence of digit from number such that the value of the resulting string in decimal form is maximized. The test cases are generated such that digit occurs at least once in number.



Example 1:

Input: number = "123", digit = "3"
Output: "12"
Explanation: There is only one '3' in "123". After removing '3', the result is "12".
Example 2:

Input: number = "1231", digit = "1"
Output: "231"
Explanation: We can remove the first '1' to get "231" or remove the second '1' to get "123".
Since 231 > 123, we return "231".
Example 3:

Input: number = "551", digit = "5"
Output: "51"
Explanation: We can remove either the first or second '5' from "551".
Both result in the string "51".


Constraints:

2 <= number.length <= 100
number consists of digits from '1' to '9'.
digit is a digit from '1' to '9'.
digit occurs at least once in number.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
81K
Submissions
179.1K
Acceptance Rate
45.2%

*/

impl Solution {
  pub fn remove_digit(number: String, digit: char) -> String {
    // nope, we must find a trick and stick to string
    let sz = number.len();
    let mut to_drop:i32 = -1;
    for i in 0..sz {
      let mut nxt = i+1;
      let cur = number.chars().nth(i).unwrap();
      if cur != digit { continue }

      if nxt < sz {
        let nxtv = number.chars().nth(nxt).unwrap();
        if nxtv > cur {
          // drop this one
          to_drop = i as i32;
        } else {
            if to_drop < 0 { to_drop = i as i32; }
        }
      } else {
        if to_drop < 0 { to_drop = i as i32; }
      }
    }
    // remove char from string,
    // convert to vec<char>
    let mut tmp : Vec<char> = number.clone().chars().collect();
    // rmv
    tmp.remove(to_drop as usize);
    // back to string

    tmp.iter().collect()
  }
}