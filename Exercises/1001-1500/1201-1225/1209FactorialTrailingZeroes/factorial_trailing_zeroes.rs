/*

172. Factorial Trailing Zeroes
Medium
Topics
Companies
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.



Example 1:

Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:

Input: n = 0
Output: 0


Constraints:

0 <= n <= 104


Follow up: Could you write a solution that works in logarithmic time complexity?

Seen this question in a real interview before?
1/5
Yes
No
Accepted
529K
Submissions
1.2M
Acceptance Rate
44.4%
*/

impl Solution {
  fn long_mult(n1: Vec<i32>, n2: Vec<i32>) -> Vec<i32> {

    let mut mult_factor = 0;
    let mut addends: Vec<Vec<i32>> = vec![];
    for dig in n1.iter().rev() {
      let mut cur_addend: Vec<i32> = vec![];
      let mut carry = 0;
      for i in 0..mult_factor {
        cur_addend.push(0);
      }
      for dig2 in n2.iter().rev() {
        let prod = dig * dig2 + carry;
        carry = prod/10;
        cur_addend.push(prod%10);
      }
      if carry > 0 {
        cur_addend.push(carry);
      }
      addends.push(cur_addend);
      mult_factor+=1;
    }
    // add them up
    let mut res:Vec<i32> = vec![];
    let mut idx = 0;
    while !addends.is_empty() {
      let mut nxt_addends = vec![];
      let mut sm = 0;
      for addend in addends {
        println!("working with addend {:?}", addend);

        sm += addend[idx];


        if idx < addend.len()-1 {
          nxt_addends.push(addend);
        }

      }
      idx+=1;
      println!("sm is {}", sm);
      addends = nxt_addends;
    }
    res
  }
  fn to_v(n:i32) -> Vec<i32> {
    n.to_string().chars().map(|c| { (c as u8 - '0' as u8) as i32 }).collect()
  }
  fn fact(n:i32) -> Vec<i32> {
    let mut res = vec![1];
    for i in (2..n).rev() {
      res = Solution::long_mult(Solution::to_v(i), res);
    }

    res
  }
  fn cnt(v:Vec<i32>) -> i32 {
    let mut res = 0;
    for i in (0..v.len()).rev() {
      if v[i] != 0 {
        break;
      }
      res+=1;
    }
    res
  }
  pub fn trailing_zeroes(n: i32) -> i32 {
    // must do long multiplication
    println!("{:?}",Solution::long_mult(vec![1,2,9], vec![1,2,8]));
   //  Solution::cnt(Solution::fact(n))
   0
  }
}