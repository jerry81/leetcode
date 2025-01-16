/*

130. Surrounded Regions
Medium
Topics
Companies
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.



Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]



Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
856.5K
Submissions
2.1M
Acceptance Rate
41.6%

*/

use std::collections::HashSet;

impl Solution {
  fn find_islands(start: (usize,usize), board: &Vec<Vec<char>>, visited: &mut HashSet<(usize,usize)>) -> Vec<(usize,usize)>  { // return a list of nodes or []
    return vec![]
  }

  pub fn solve(board: &mut Vec<Vec<char>>) {
    let h = board.len();
    let w = board[0].len();
    let mut visited: HashSet<(usize,usize)> = HashSet::new();
    for r in 0..h {
      for c in 0..w {
        let result = Solution::find_islands((r,c), &board, &mut visited);
        println!("result {:?}", result);
      }
    }
  }
}