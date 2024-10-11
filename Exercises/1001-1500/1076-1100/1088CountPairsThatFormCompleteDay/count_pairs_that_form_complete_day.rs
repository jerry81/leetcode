/*

3184. Count Pairs That Form a Complete Day I
Easy
Topics
Companies
Hint
Given an integer array hours representing times in hours, return an integer denoting the number of pairs i, j where i < j and hours[i] + hours[j] forms a complete day.

A complete day is defined as a time duration that is an exact multiple of 24 hours.

For example, 1 day is 24 hours, 2 days is 48 hours, 3 days is 72 hours, and so on.



Example 1:

Input: hours = [12,12,30,24,24]

Output: 2

Explanation:

The pairs of indices that form a complete day are (0, 1) and (3, 4).

Example 2:

Input: hours = [72,48,24,3]

Output: 3

Explanation:

The pairs of indices that form a complete day are (0, 1), (0, 2), and (1, 2).



Constraints:

1 <= hours.length <= 100
1 <= hours[i] <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
58.9K
Submissions
74.3K
Acceptance Rate
79.3%


*/

impl Solution {
  pub fn count_complete_day_pairs(hours: Vec<i32>) -> i32 {
    // iterate all pairs
    let sz = hours.len();
    let mut res = 0;
    for i in 0..(sz-1) {
      let mut cur = hours[i];
      for j in (i+1)..sz {
        cur+=hours[j];

        if cur % 24 == 0 { res +=1 }
      }
    }
    res
  }
}