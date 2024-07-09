/*

2511. Maximum Enemy Forts That Can Be Captured
Easy
Topics
Companies
Hint
You are given a 0-indexed integer array forts of length n representing the positions of several forts. forts[i] can be -1, 0, or 1 where:

-1 represents there is no fort at the ith position.
0 indicates there is an enemy fort at the ith position.
1 indicates the fort at the ith the position is under your command.
Now you have decided to move your army from one of your forts at position i to an empty position j such that:

0 <= i, j <= n - 1
The army travels over enemy forts only. Formally, for all k where min(i,j) < k < max(i,j), forts[k] == 0.
While moving the army, all the enemy forts that come in the way are captured.

Return the maximum number of enemy forts that can be captured. In case it is impossible to move your army, or you do not have any fort under your command, return 0.



Example 1:

Input: forts = [1,0,0,-1,0,0,0,0,1]
Output: 4
Explanation:
- Moving the army from position 0 to position 3 captures 2 enemy forts, at 1 and 2.
- Moving the army from position 8 to position 3 captures 4 enemy forts.
Since 4 is the maximum number of enemy forts that can be captured, we return 4.
Example 2:

Input: forts = [0,0,1,-1]
Output: 0
Explanation: Since no enemy fort can be captured, 0 is returned.


Constraints:

1 <= forts.length <= 1000
-1 <= forts[i] <= 1
Seen this question in a real interview before?
1/5
Yes
No
Accepted
23.5K
Submissions
61.4K
Acceptance Rate
38.3%

*/

impl Solution {
  pub fn capture_forts(forts: Vec<i32>) -> i32 {
    let mut starting_positions: Vec<usize> = Vec::new();
    for i in 0..forts.len() {
      if forts[i] == 1 { starting_positions.push(i); }
    }
    let mut res = 0 ;
    // for each starting position look left and look right
    for sp in starting_positions {
      // go left
      let mut idx = (sp as i32-1);
      let mut curcount = 0;
      let mut found = false;
      while idx >= 0 {
        if forts[idx as usize] == 0 {
          curcount += 1;
        } else if forts[idx as usize] == -1 {
          found = true;
          break;
        } else {
          break;
        }
        idx-=1;
      }
      if found && curcount > res {
        res = curcount;
      }
      // go right
      let mut idx2 = sp+1;
      curcount = 0;
      found = false;
      while idx2 < forts.len() {
        if forts[idx2] == 0 {
          curcount += 1;
        } else if forts[idx2] == -1 {
          found = true;
          break;
        } else {
          break;
        }
        idx2+=1;
      }
      if found && curcount > res {
        res = curcount;
      }
    }
    res
  }
}