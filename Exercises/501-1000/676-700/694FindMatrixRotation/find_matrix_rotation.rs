/*


1886. Determine Whether Matrix Can Be Obtained By Rotation
Easy
Topics
Companies
Hint
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.



Example 1:


Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
Example 2:


Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.
Example 3:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.


Constraints:

n == mat.length == target.length
n == mat[i].length == target[i].length
1 <= n <= 10
mat[i][j] and target[i][j] are either 0 or 1.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
66.3K
Submissions
117K
Acceptance Rate
56.7%


*/

impl Solution {
  pub fn find_rotation(mat: Vec<Vec<i32>>, target: Vec<Vec<i32>>) -> bool {
    // ez, so simluation
    // not trivial
    //
    // stop condition: reached original state
    let sz = mat.len();
    let mut rotated = mat.clone();
    let tgt_s = Solution::serialize(&target);
    for i in 0..4 {
      rotated = Solution::rotate(&rotated, sz); // changed to &
      if Solution::serialize(&rotated) == tgt_s { return true }
    }
    false
  }

  fn rotate(mat: &Vec<Vec<i32>>, sz: usize) -> Vec<Vec<i32>> { // added &
    let mut ret = vec![vec![0; sz]; sz]; // changed from .clone()
    for i in 0..sz {
      for j in 0..sz {
        ret[i][j] = ret[j][sz-i-1];
      }
    }
    ret
  }

  fn serialize(mat: &Vec<Vec<i32>>) -> String {
    let mut res = String::new();
    for v in mat {
      for r in v {
        res.push((*r as u8 +'0' as u8) as char);
      }
    }
    res
  }
}