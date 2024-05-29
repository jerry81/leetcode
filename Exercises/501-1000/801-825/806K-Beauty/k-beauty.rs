/*

2269. Find the K-Beauty of a Number
Easy
Topics
Companies
Hint
The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:

It has a length of k.
It is a divisor of num.
Given integers num and k, return the k-beauty of num.

Note:

Leading zeros are allowed.
0 is not a divisor of any value.
A substring is a contiguous sequence of characters in a string.



Example 1:

Input: num = 240, k = 2
Output: 2
Explanation: The following are the substrings of num of length k:
- "24" from "240": 24 is a divisor of 240.
- "40" from "240": 40 is a divisor of 240.
Therefore, the k-beauty is 2.
Example 2:

Input: num = 430043, k = 2
Output: 2
Explanation: The following are the substrings of num of length k:
- "43" from "430043": 43 is a divisor of 430043.
- "30" from "430043": 30 is not a divisor of 430043.
- "00" from "430043": 0 is not a divisor of 430043.
- "04" from "430043": 4 is not a divisor of 430043.
- "43" from "430043": 43 is a divisor of 430043.
Therefore, the k-beauty is 2.


Constraints:

1 <= num <= 109
1 <= k <= num.length (taking num as a string)
Seen this question in a real interview before?
1/5
Yes
No
Accepted
57.3K
Submissions
95.9K
Acceptance Rate
59.7%

*/

impl Solution {
  pub fn divisor_substrings(num: i32, k: i32) -> i32 {
    // try all substrings
    let as_s = num.to_string();
    let mut res = 0;
    let sz = as_s.len();
    for i in 0..sz-1 {
      for j in i+1..sz {
        if j-i+1 != k as usize { continue }

        let parseRes = &as_s[i..=j].parse::<i32>().unwrap();
        if *parseRes == 0 {
          continue
        }
        if num % parseRes == 0 { res+=1; }
      }
    }
    res
  }
}