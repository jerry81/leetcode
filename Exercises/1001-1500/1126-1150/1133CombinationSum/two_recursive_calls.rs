impl Solution {
  fn backtrack(
      candidates: &Vec<i32>,
      target: i32,
      start: usize,
      current_sum: i32,
      combination: &mut Vec<i32>,
      results: &mut Vec<Vec<i32>>
  ) {
      // Base case: if current_sum exceeds target, return
      if current_sum > target {
          return;
      }

      // Target reached, store a clone of the current combination
      if current_sum == target {
          results.push(combination.clone());
          return;
      }

      // Base case: if start index is out of bounds, return
      if start >= candidates.len() {
          return;
      }

      // Recursive case 1: Exclude the current candidate and move to the next index
      Solution::backtrack(candidates, target, start + 1, current_sum, combination, results);

      // Recursive case 2: Include the current candidate and stay at the current index (allowing reuse)
      combination.push(candidates[start]);
      Solution::backtrack(candidates, target, start, current_sum + candidates[start], combination, results);
      combination.pop(); // Backtrack by removing the last element
  }

  pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
      let mut res: Vec<Vec<i32>> = Vec::new();
      let mut comb: Vec<i32> = Vec::new();
      Solution::backtrack(&candidates, target, 0, 0, &mut comb, &mut res);
      res
  }
}