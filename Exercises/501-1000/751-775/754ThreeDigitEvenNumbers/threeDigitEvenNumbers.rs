/*

2094. Finding 3-Digit Even Numbers
Easy
Topics
Companies
Hint
You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.



Example 1:

Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: All the possible integers that follow the requirements are in the output array.
Notice that there are no odd integers or integers with leading zeros.
Example 2:

Input: digits = [2,2,8,8,2]
Output: [222,228,282,288,822,828,882]
Explanation: The same digit can be used as many times as it appears in digits.
In this example, the digit 8 is used twice each time in 288, 828, and 882.
Example 3:

Input: digits = [3,7,5]
Output: []
Explanation: No even integers can be formed using the given digits.


Constraints:

3 <= digits.length <= 100
0 <= digits[i] <= 9
Seen this question in a real interview before?
1/5
Yes
No
Accepted
30.3K
Submissions
50.6K
Acceptance Rate
59.9%

*/

use std::collections::HashSet;

impl Solution {
  pub fn find_even_numbers(digits: Vec<i32>) -> Vec<i32> {
    let sz = digits.len();

    let mut res:Vec<i32>  = vec![];

    let mut firstIdxs: Vec<usize> = (0..sz).filter( |&item| { digits[item] != 0 }).collect();
    // println!("first poss");
    // for i in firstIdxs { println!("{}", i)};
    let mut lastIdxs: Vec<usize> = (0..sz).filter( |&item| { digits[item] % 2 == 0 }).collect();
    // println!("last poss");
    // for i in lastIdxs { println!("{}", i)};

    let mut hsRes: HashSet<i32> = HashSet::new();

    for i in firstIdxs {
      let d1 = digits[i];
      let u81 = d1 as u8 + '0' as u8;
      let c1 = u81 as char;
      for j in 0..sz {
        if j == i { continue }
        let d2 = digits[j];
        let u82 = d2 as u8 + '0' as u8;
        let c2 = u82 as char;
        for k in lastIdxs.clone() {
          if k == j || k == i { continue }
          let d3 = digits[k];
          let u83 = d3 as u8 + '0' as u8;
          let c3 = u83 as char;
          let mut s: String = String::new();
          s.push(c1);
          s.push(c2);
          s.push(c3);
          let as_i: i32 = s.parse().unwrap();
          hsRes.insert(as_i);
        }
      }
    }
    res = hsRes.into_iter().collect();
    res.sort();
    res
  }
}