/*
2466. Count Ways To Build Good Strings
Medium
Topics
Companies
Hint
Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.



Example 1:

Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation:
One possible valid good string is "011".
It can be constructed as follows: "" -> "0" -> "01" -> "011".
All binary strings from "000" to "111" are good strings in this example.
Example 2:

Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".


Constraints:

1 <= low <= high <= 105
1 <= zero, one <= low
Accepted
87.3K
Submissions
159K
Acceptance Rate
54.9%

*/
impl Solution {
  const MOD: u64 = 1_000_000_007;
  pub fn count_good_strings(low: i32, high: i32, zero: i32, one: i32) -> i32 {
    let mut dp: Vec<u64> = vec![0; (high + 1) as usize]; // Ensure dp is initialized for all lengths
    dp[0] = 1; // Base case: one way to form an empty string
    let mut res: u64 = 0;

    for i in 1..=high {
      let mut zerocnt = 0;
      if i - zero >= 0 { zerocnt = dp[(i - zero) as usize]; }
      let mut onecnt = 0;
      if i - one >= 0 { onecnt = dp[(i - one) as usize]; }
      dp[i as usize] = (zerocnt + onecnt) % Self::MOD; // Store the result for length i

      // Only accumulate results for lengths within [low, high]
      if i >= low {
        res = (res + dp[i as usize]) % Self::MOD; // Accumulate results only for valid lengths
      }
    }
    println!("res is {}", res);
    res as i32
  }
}