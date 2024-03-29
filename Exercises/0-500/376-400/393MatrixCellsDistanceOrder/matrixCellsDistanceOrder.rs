/*

1030. Matrix Cells in Distance Order
Easy
703
305
Companies
You are given four integers row, cols, rCenter, and cCenter. There is a rows x cols matrix and you are on the cell with the coordinates (rCenter, cCenter).

Return the coordinates of all cells in the matrix, sorted by their distance from (rCenter, cCenter) from the smallest distance to the largest distance. You may return the answer in any order that satisfies this condition.

The distance between two cells (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|.



Example 1:

Input: rows = 1, cols = 2, rCenter = 0, cCenter = 0
Output: [[0,0],[0,1]]
Explanation: The distances from (0, 0) to other cells are: [0,1]
Example 2:

Input: rows = 2, cols = 2, rCenter = 0, cCenter = 1
Output: [[0,1],[0,0],[1,1],[1,0]]
Explanation: The distances from (0, 1) to other cells are: [0,1,1,2]
The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
Example 3:

Input: rows = 2, cols = 3, rCenter = 1, cCenter = 2
Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
Explanation: The distances from (1, 2) to other cells are: [0,1,1,2,2,3]
There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].


Constraints:

1 <= rows, cols <= 100
0 <= rCenter < rows
0 <= cCenter < cols
Accepted
53.8K
Submissions
76.6K
Acceptance Rate
70.2%

*/
struct Cell { // struct cant be in impl
  r:i32,
  c:i32,
  d:i32,
}

impl Solution {

  pub fn all_cells_dist_order(rows: i32, cols: i32, r_center: i32, c_center: i32) -> Vec<Vec<i32>> {
    let mut ret  = Vec::new(); // vec constructor (no need for generic type) - type inference later
    let mut cells  = Vec::new();
    for r in 0..rows {
      for c in 0..cols {
        let dist = (r_center - r).abs() + (c_center - c).abs(); // abs
        let cell = Cell { // struct delc and initializer
          r:r,
          c:c,
          d:dist
        };
        cells.push(cell); // append to vec
      }
    }
    cells.sort_by(|a,b| a.d.cmp(&b.d)); // custom comparator, lambda, closure, anonymous function, cmp
    for cl in cells {
      ret.push(vec![cl.r,cl.c]);
    }
    ret // auto-return
  }
}