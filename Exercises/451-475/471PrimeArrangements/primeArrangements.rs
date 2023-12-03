/*

1175. Prime Arrangements
Easy
377
499
Companies
Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)

(Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers both smaller than it.)

Since the answer may be large, return the answer modulo 10^9 + 7.



Example 1:

Input: n = 5
Output: 12
Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.
Example 2:

Input: n = 100
Output: 682289015


Constraints:

1 <= n <= 100
Accepted
28.3K
Submissions
50.5K
Acceptance Rate
56.0%

*/

static MOD:i32=pow(10,9) + 7;
impl Solution {
  fn is_prime(n:i32) -> bool {
    let sr = sqrt(n);
    for i in 2..=sr {
      if n%i == 0 { return false; }
    }
    return true;
  }

  pub fn num_prime_arrangements(n: i32) -> i32 {
    let mut res: i64 = 1;
    let mut prime_count: i32 = 0;
    for i in 2..n {
      if is_prime(i) {
        prime_count+=1;
      }
    }
    for i in 2..prime_count {
      res*=i;
      res%=MOD;
    }
    return res as i32;
  }
}