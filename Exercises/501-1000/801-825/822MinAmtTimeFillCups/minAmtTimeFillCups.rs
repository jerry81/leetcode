/*

2335. Minimum Amount of Time to Fill Cups
Easy
Topics
Companies
Hint
You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.

You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold, warm, and hot water cups you need to fill respectively. Return the minimum number of seconds needed to fill up all the cups.



Example 1:

Input: amount = [1,4,2]
Output: 4
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup and a warm cup.
Second 2: Fill up a warm cup and a hot cup.
Second 3: Fill up a warm cup and a hot cup.
Second 4: Fill up a warm cup.
It can be proven that 4 is the minimum number of seconds needed.
Example 2:

Input: amount = [5,4,4]
Output: 7
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup, and a hot cup.
Second 2: Fill up a cold cup, and a warm cup.
Second 3: Fill up a cold cup, and a warm cup.
Second 4: Fill up a warm cup, and a hot cup.
Second 5: Fill up a cold cup, and a hot cup.
Second 6: Fill up a cold cup, and a warm cup.
Second 7: Fill up a hot cup.
Example 3:

Input: amount = [5,0,0]
Output: 5
Explanation: Every second, we fill up a cold cup.


Constraints:

amount.length == 3
0 <= amount[i] <= 100
Seen this question in a real interview before?
1/5
Yes
No
Accepted
46.9K
Submissions
81.4K
Acceptance Rate
57.6%

*/

impl Solution {
  pub fn fill_cups(amount: Vec<i32>) -> i32 {
      let mut sorted = amount.clone();
      sorted.retain(|&x| x > 0); // TIL: amazing
      if sorted.is_empty() { return 0 }

      if sorted.len() == 1 { return sorted[0]; }

      sorted.sort_unstable_by(|a,b| b.cmp(a));
      sorted[0]-=1;
      sorted[1]-=1;
      sorted.retain(|&x| x > 0);
      return 1+Solution::fill_cups(sorted)
  }
}

