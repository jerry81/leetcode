/*

1550. Three Consecutive Odds
Easy
Topics
Companies
Hint
Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.


Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.
Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.


Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000
Seen this question in a real interview before?
1/4
Yes
No
Accepted
80.1K
Submissions
126.9K
Acceptance Rate
63.1%

*/

impl Solution {
  pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
    let mut cur = 0;
    for i in arr {
      if i%2 == 1 {
        cur+=1;
        if cur == 3 { return true }
      } else {
        cur = 0;
      }
    }
    false
  }
}