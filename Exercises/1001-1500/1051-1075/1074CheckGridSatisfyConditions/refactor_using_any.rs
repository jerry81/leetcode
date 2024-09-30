impl Solution {
  pub fn satisfies_conditions(grid: Vec<Vec<i32>>) -> bool {
    let h = grid.len();
    let w = grid[0].len();

    // Check conditions using iter().any()
    !(grid.iter().enumerate().any(|(r, row)| {
      row.iter().enumerate().any(|(c, &val)| {
        (r < h - 1 && val != grid[r + 1][c]) || (c < w - 1 && val == grid[r][c + 1])
      })
    }))
  }
}