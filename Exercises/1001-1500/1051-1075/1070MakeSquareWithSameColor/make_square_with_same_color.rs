/*

3127. Make a Square with the Same Color
Easy
Topics
Companies
Hint
You are given a 2D matrix grid of size 3 x 3 consisting only of characters 'B' and 'W'. Character 'W' represents the white color, and character 'B' represents the black color.

Your task is to change the color of at most one cell so that the matrix has a 2 x 2 square where all cells are of the same color.

Return true if it is possible to create a 2 x 2 square of the same color, otherwise, return false.



Example 1:










Input: grid = [["B","W","B"],["B","W","W"],["B","W","B"]]

Output: true

Explanation:

It can be done by changing the color of the grid[0][2].

Example 2:










Input: grid = [["B","W","B"],["W","B","W"],["B","W","B"]]

Output: false

Explanation:

It cannot be done by changing at most one cell.

Example 3:










Input: grid = [["B","W","B"],["B","W","W"],["B","W","W"]]

Output: true

Explanation:

The grid already contains a 2 x 2 square of the same color.



Constraints:

grid.length == 3
grid[i].length == 3
grid[i][j] is either 'W' or 'B'.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
26.4K
Submissions
51.4K
Acceptance Rate
51.5%

*/

impl Solution {
  pub fn can_make_square(grid: Vec<Vec<char>>) -> bool {
    // test 2x2 blocks
    let h = grid.len();
    let w = grid[0].len();
    for sr in 0..h-1 {
      for sc in 0..w-1 {
        // four squares
        let mut cnt = 0;
        for dr in 0..2 {
          let r = &grid[dr+sr];
          for dc in 0..2 {
            if r[dc+sc] == 'W' { cnt+=1; }
          }
        }
        if cnt > 2 { return true }
      }
    }
    false
  }
}