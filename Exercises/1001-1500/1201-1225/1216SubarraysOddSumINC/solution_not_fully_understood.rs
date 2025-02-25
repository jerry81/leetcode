impl Solution {
  pub fn num_of_subarrays(arr: Vec<i32>) -> i32 {
    let mut odd_count = 0;
    let mut even_count = 1; // Start with one even count for the empty subarray
    let mut current:bool = true;
    let mut total_odd_subarrays:i64 = 0;

    for num in arr {

      let num_ev = (num % 2) == 0;
      if current && num_ev || !num_ev && !current {
        total_odd_subarrays += odd_count; // Add odd counts to total if current sum is even
        even_count += 1; // Increment even count
        current = true;
      } else {
        total_odd_subarrays += even_count; // Add even counts to total if current sum is odd
        odd_count += 1; // Increment odd count
        current = false;
      }
    }
    (total_odd_subarrays % 1_000_000_007) as i32 // Return the result modulo 10^9 + 7
  }
}