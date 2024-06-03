impl Solution {
  pub fn calculate_tax(brackets: Vec<Vec<i32>>, income: i32) -> f64 {
      let mut inc = income;
      let mut totaltax = 0.0;
      let mut prev_upper_bound = 0;

      for bracket in brackets {
          let upper_bound = bracket[0];
          let rate = bracket[1];

          if inc > upper_bound {
              totaltax += (upper_bound - prev_upper_bound) as f64 * (rate as f64 / 100.0);
          } else {
              totaltax += (inc - prev_upper_bound) as f64 * (rate as f64 / 100.0);
              break;
          }

          prev_upper_bound = upper_bound;
      }

      totaltax
  }
}