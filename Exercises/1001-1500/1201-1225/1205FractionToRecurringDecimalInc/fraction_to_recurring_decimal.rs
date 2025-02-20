/*

166. Fraction to Recurring Decimal
Medium
 vc231Companies
Hint
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.



Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 4, denominator = 333
Output: "0.(012)"


Constraints:

-231 <= numerator, denominator <= 231 - 1
denominator != 0
Seen this question in a real interview before?
1/5
Yes
No
Accepted
246.4K
Submissions
954.6K
Acceptance Rate
25.8%

*/

use std::collections::HashMap;

impl Solution {
  fn insert_char(original: &str, index: usize, ch: char) -> String {
    let mut chars: Vec<char> = original.chars().collect();
    chars.insert(index, ch);
    chars.iter().collect()
}
  pub fn fraction_to_decimal(numerator: i32, denominator: i32) -> String {
    let mut neg = false;
    let mut numerator:i64 = numerator as i64;
    let mut denominator:i64 = denominator as i64;
    if numerator < 0 { neg = true; numerator = numerator*-1; }
    if denominator < 0 { neg = !neg; denominator = denominator*-1; }
    if numerator == 0 { return "0".to_string() }
    let mut res = "0.".to_string();
    let mut num = numerator*10;
    if numerator >= denominator {
      if numerator % denominator == 0 {
        if neg {
            return (-1*numerator / denominator).to_string()
        } else {
            return (numerator / denominator).to_string()
        }
      } else {
        res = (numerator/denominator).to_string() + ".";
        num = (numerator % denominator)*10;
      }
    }


    let mut hm: HashMap<i64, usize> = HashMap::new();
    let mut idx = res.len();
    loop {
      if hm.contains_key(&num) {
        res+=")";
        let newres = Self::insert_char(&res, hm[&num], '(');
        res = newres;
        if neg {
            let newres = Self::insert_char(&res, 0, '-');
            return newres
          } else {
            return res
          }
      }
      *hm.entry(num).or_insert(idx) = idx;
      idx+=1;
      if num < denominator {

        res+="0";
        num*=10;
      } else {
        let rem = num%denominator;
        res+=&(num/denominator).to_string();
        num = rem*10;
        if rem == 0 {
          if neg {
            let newres = Self::insert_char(&res, 0, '-');
            return newres
          } else {
            return res
          }
        }
      }
    }
    res
  }
}
/*

Input: numerator = 4, denominator = 333
Output: "0.(012)"

4/333
0 ->
40 / 333
0->
400/333
1-> rem 67
670/

1/2 =
0.5 10/2 = 5
1/4
0. 10/4
2 r 2
10/2 = 5
1/8
10/2
0.1
r 2
20/8 = 2 r 4
40/8 = 5
.125
1/3
10/3 = 3 r 1
10/3 = 3 r 1

4/333
0 40
0 400 / 333
1 r 67
670/333 = 2 r 4
4/333

1/6 0.16666
10/6 1 r4
40/6 6 r 4
40
*/