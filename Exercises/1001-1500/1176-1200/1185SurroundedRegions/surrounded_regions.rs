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
  const NEIGHBORS: &'static [(i32,i32)] = &[(-1,0), (1,0), (0,1), (0,-1)];

  fn find_islands(start: (usize,usize), board: &Vec<Vec<char>>, visited: &mut HashSet<(usize,usize)>) -> Vec<(usize,usize)>  { // return a list of nodes or []
    // bfs
    let mut q: Vec<(usize,usize)> = vec![];

    q.push(start);

    let mut invalid: bool = start.0 <= 0 || start.1 <= 0 || start.0 >= board.len() - 1 || start.1 >= board[0].len() - 1;
    let mut res: Vec<(usize,usize)> = vec![start];
    visited.insert(start);
    while !q.is_empty() {
      let top_coord: (usize,usize) = q[0];
      q.remove(0);
      res.push(top_coord);
      for (dy,dx) in Self::NEIGHBORS {
        let ny = dy + top_coord.0 as i32;
        let nx = dx + top_coord.1 as i32;

        if ny < 0 { continue }
        if nx < 0 { continue }
        let nyu = ny as usize;
        let nxu = nx as usize;
        if nyu >= board.len() { continue }
        if nxu >= board[0].len() { continue }
        if !visited.contains(&(nyu, nxu)) && board[nyu][nxu] == 'O' {
          q.push((nyu,nxu));
          visited.insert((nyu,nxu));
          if nyu <= 0 || nxu <= 0 { invalid = true; }
          if nyu >= board.len() - 1 || nxu >= board[0].len() - 1 { invalid = true; }
        }
      }
    }
    if invalid {
        vec![]
    } else {
        res
    }
  }

  fn update_board(board: &mut Vec<Vec<char>>, converted_nodes: Vec<(usize,usize)>) {
    for cn in converted_nodes {
      board[cn.0][cn.1] = 'X';
    }
  }

  pub fn solve(board: &mut Vec<Vec<char>>) {
    let h = board.len();
    let w = board[0].len();
    let mut visited: HashSet<(usize,usize)> = HashSet::new();
    let mut updated_nodes: Vec<(usize,usize)> = vec![];
    for r in 0..h {
      for c in 0..w {
        if visited.contains(&(r,c)) || board[r][c] != 'O' { continue }
        let fi_result = Solution::find_islands((r,c), &board, &mut visited);
        updated_nodes.extend(fi_result);

      }
    }
    Solution::update_board(board, updated_nodes);
  }
}