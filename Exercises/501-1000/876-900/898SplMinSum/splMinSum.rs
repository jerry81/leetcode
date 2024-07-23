/*


2578. Split With Minimum Sum
Easy
Topics
Companies
Hint
Given a positive integer num, split it into two non-negative integers num1 and num2 such that:

The concatenation of num1 and num2 is a permutation of num.
In other words, the sum of the number of occurrences of each digit in num1 and num2 is equal to the number of occurrences of that digit in num.
num1 and num2 can contain leading zeros.
Return the minimum possible sum of num1 and num2.

Notes:

It is guaranteed that num does not contain any leading zeros.
The order of occurrence of the digits in num1 and num2 may differ from the order of occurrence of num.


Example 1:

Input: num = 4325
Output: 59
Explanation: We can split 4325 so that num1 is 24 and num2 is 35, giving a sum of 59. We can prove that 59 is indeed the minimal possible sum.
Example 2:

Input: num = 687
Output: 75
Explanation: We can split 687 so that num1 is 68 and num2 is 7, which would give an optimal sum of 75.


Constraints:

10 <= num <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
35.7K
Submissions
50.5K
Acceptance Rate
70.7%

*/

impl Solution {
  pub fn split_num(num: i32) -> i32 {
    // get Vec<i32>
    let as_v: Vec<i32> = num.to_string().chars()
    .map(|c| {
      (c as u8 - '0' as u8) as i32
    }).collect();
    let mut res = 0;
    let mut sorted = as_v.clone();
    sorted.sort();
    let mut left: bool = true;
    let mut s1:String = String::new();
    let mut s2:String = String::new();
    for i in sorted {
      if left {
        s1.push((i as u8 + '0' as u8) as char;
      } else {
        s2.push((i as u8 + '0' as u8) as char;
      }
    }
    println!("s1 {} s2 {}", s1, s2);
    res
  }
}