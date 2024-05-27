/*

2231. Largest Number After Digit Swaps by Parity
Easy
Topics
Companies
Hint
You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).

Return the largest possible value of num after any number of swaps.



Example 1:

Input: num = 1234
Output: 3412
Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
Example 2:

Input: num = 65875
Output: 87655
Explanation: Swap the digit 8 with the digit 6, this results in the number 85675.
Swap the first digit 5 with the digit 7, this results in the number 87655.
Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number.


Constraints:

1 <= num <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
42.7K
Submissions
69.4K
Acceptance Rate
61.5%

*/

impl Solution {
  pub fn largest_integer(num: i32) -> i32 {
    // access each digit individually
    // i32 to string to chars
    let mut as_cv: Vec<char> = num.to_string().chars().collect();
    // chars to i32
    let mut iv :Vec<i32> = as_cv.iter().map(|&item| { (item as u8 - '0' as u8) as i32 }).collect();
    let mut op_made = true;
    let sz = num.len();
    while op_made {
      op_made = false;
      for i in 0..sz-1 {
        j in i+1..sz {
          if iv[i] > iv[j] { continue }

          iv.swap(i,j);
          op_made = true;
          break
        }
        if op_made { break }
      }
    }
    let mut res = 0;
    let multiplier = 1;
    for i in 0..sz {
      let idx = (sz-1) - i;
      res+=iv[idx] * 10.pow(i);
    }
    res
  }
}