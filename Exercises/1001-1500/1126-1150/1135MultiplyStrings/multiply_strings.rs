/*

43. Multiply Strings
Medium
Topics
Companies
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.



Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"


Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
874.9K
Submissions
2.1M
Acceptance Rate
41.2%

*/

impl Solution {
  fn build_mini_products(num1: String, num2: String) -> Vec<String> {
    let mut res:Vec<String> = vec![];
    for offset1 in 0..num1.len() {
      let n1 = (num1.chars().nth(offset1).unwrap() as u8 - '0' as u8) as i32;
      for offset2 in 0..num2.len() {
        let n2 = (num2.chars().nth(offset2).unwrap() as u8 - '0' as u8) as i32;
        let prod = (n1*n2).to_string();
        let num_zeroes = offset1+offset2;
        let mut s: String = "".to_string();
        for i in 0..num_zeroes {
          s.push('0');
        }
        s+=&prod;
        res.push(s);
      }
    }
    res
  }
  pub fn multiply(num1: String, num2: String) -> String {
    let mp = Solution::build_mini_products(num1, num2);
    println!("{:?}", mp);
    "0".to_string()
  }
}

/*

Input: num1 = "123", num2 = "456"
Output: "56088"

3*6 + 3*50 + 3*400
20*6 + 20*50 + 20*400
600+5000+40000

6*3
1,8
"18"
3*5
(shift 1) 1,5
"150"
3*4
"1200"
(shift 2) 1,2



*/

