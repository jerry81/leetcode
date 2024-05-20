/*

2160. Minimum Sum of Four Digit Number After Splitting Digits
Easy
Topics
Companies
Hint
You are given a positive integer num consisting of exactly four digits. Split num into two new integers new1 and new2 by using the digits found in num. Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.

For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
Return the minimum possible sum of new1 and new2.



Example 1:

Input: num = 2932
Output: 52
Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.
Example 2:

Input: num = 4009
Output: 13
Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc.
The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.


Constraints:

1000 <= num <= 9999
Seen this question in a real interview before?
1/5
Yes
No
Accepted
126.5K
Submissions
147K
Acceptance Rate
86.1%

*/
impl Solution {
  pub fn minimum_sum(num: i32) -> i32 {
      // brute
      let mut s: String = num.to_string();
      let c1 = s.chars().nth(0).unwrap();
      let c2 = s.chars().nth(1).unwrap();
      let c3 = s.chars().nth(2).unwrap();
      let c4 = s.chars().nth(3).unwrap();
      let mut res = i32::MAX;
      let mut chrs: Vec<char> = vec![c1,c2,c3,c4];

      for i in 0..4 {
          let mut str1: String = String::new();
          let mut str2: String = String::new();
          str1.push(chrs[i]);
          for j in 0..4 {
              if j == i { continue }

              str1.push(chrs[j]);
              for k in 0..4 {
                  str2 = String::new();
                  if k == i || k == j { continue }

                  str2.push(chrs[k]);
                  for l in 0..4 {
                      if l == k || j == l || l == i { continue }

                      str2.push(chrs[l]);
                      let cur = str1.parse::<i32>().unwrap() + str2.parse::<i32>().unwrap();
                      res = res.min(cur);
                  }
              }
          }


      }

      res
  }
}