/*


1267. Count Servers that Communicate
Medium
Topics
Companies
Hint
You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.



Example 1:



Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
Example 2:



Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.
Example 3:



Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.


Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 250
1 <= n <= 250
grid[i][j] == 0 or 1
Seen this question in a real interview before?
1/5
Yes
No
Accepted
98.8K
Submissions
147.2K
Acceptance Rate
67.1%

*/

impl Solution {
  pub fn count_servers(grid: Vec<Vec<i32>>) -> i32 {
    // tally m/n
    let h = grid.len();
    let w = grid[0].len();
    let mut row_counts: Vec<i32> = vec![0;h];
    let mut col_counts: Vec<i32> = vec![0;w];
    for r in 0..h {
      for c in 0..w {
        if grid[r][c] == 1 {
          row_counts[r]+=1;
          col_counts[c]+=1;
        }
      }
    }
    let mut res = 0;
    for r in 0..h {
      for c in 0..w {
        if grid[r][c] == 1 {
          if row_counts[r] == 1 && col_counts[c] == 1 {
            continue;
          }

          res+=1;
        }
      }
    }
    res
  }
}