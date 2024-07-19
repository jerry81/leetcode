/*

2558. Take Gifts From the Richest Pile
Easy
Topics
Companies
Hint
You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
Return the number of gifts remaining after k seconds.



Example 1:

Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation:
The gifts are taken in the following way:
- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.
Example 2:

Input: gifts = [1,1,1,1], k = 4
Output: 4
Explanation:
In this case, regardless which pile you choose, you have to leave behind 1 gift in each pile.
That is, you can't take any pile with you.
So, the total gifts remaining are 4.


Constraints:

1 <= gifts.length <= 103
1 <= gifts[i] <= 109
1 <= k <= 103
Seen this question in a real interview before?
1/5
Yes
No
Accepted
47.4K
Submissions
70.9K
Acceptance Rate
66.9%
*/

impl Solution {
  fn get_mx_i(v: Vec<i32>) -> usize {
    let mut mx = 0;
    let mut mx_i = 0;
    for idx in 0..v.len() {
      if v[idx] > mx {
        mx = v[idx];
        mx_i = idx;
      }
    }
    mx_i
  }
  pub fn pick_gifts(gifts: Vec<i32>, k: i32) -> i64 {
    let mut cl: Vec<i32> = gifts.clone();
    for _ in 0..k {
      if cl.is_empty() {
        return 0
      }

      let mx_idx = Solution::get_mx_i(cl);
      cl[mx_idx] = cl[mx_idx].sqrt() as i32;
    }
    cl.iter().sum() as i64
  }
}