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
  fn sum_prods(v: Vec<String>) -> String {
    let mut cur_v = v.clone();
    let mut res: String = String::new();
    let mut cnt= 0;
    while !cur_v.is_empty() && cnt < 10 {
        cnt+=1;
      let mut sm = 0;
      let mut nxt_v:Vec<String> = vec![];
      for s in cur_v.clone() {
          sm+=(s.chars().nth(s.len()-1).unwrap() as u8 - '0' as u8) as i32;
          if s.len() != 1 {
            // trim
            let trimmed:String = s[..s.len()-1].to_string();
            nxt_v.push(trimmed.clone());
            println!("{} has become {}", &s, &trimmed);
          }
      }
      println!("sm is {}", sm);
      println!("carry is {}, appended is {}", sm/10, sm%10);
      let carry = sm/10;
      let appended = sm%10;
      if carry > 0 {
        nxt_v.push(carry.to_string())
      }
      res.push((appended as u8 + '0' as u8) as char);
      cur_v = nxt_v;
    }
    res
  }
  fn build_mini_products(num1: String, num2: String) -> Vec<String> {
    let mut res:Vec<String> = vec![];
    let n1l = num1.len();
    let n2l = num2.len();
    for offset1 in 0..n1l {
      let n1 = (num1.chars().nth(n1l-offset1-1).unwrap() as u8 - '0' as u8) as i32;
      for offset2 in 0..n2l {
        let n2 = (num2.chars().nth(n2l-offset2-1).unwrap() as u8 - '0' as u8) as i32;
        let prod = (n1*n2).to_string();
        let num_zeroes = offset1+offset2;
        let mut s: String = prod;
        for i in 0..num_zeroes {
          s.push('0');
        }
        res.push(s);
      }
    }
    res
  }
  pub fn multiply(num1: String, num2: String) -> String {
    let mp = Solution::build_mini_products(num1, num2);
    Solution::sum_prods(mp)
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

