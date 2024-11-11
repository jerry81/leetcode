impl Solution {
  fn sieve_of_eratosthenes(limit: usize) -> Vec<usize> {
      let mut is_prime = vec![true; limit + 1];
      is_prime[0] = false;
      if limit >= 1 {
          is_prime[1] = false;
      }

      for i in 2..=limit {
          if is_prime[i] {
              let mut multiple = i * i;
              while multiple <= limit {
                  is_prime[multiple] = false;
                  multiple += i;
              }
          }
      }

      is_prime
          .iter()
          .enumerate()
          .filter_map(|(num, &prime)| if prime { Some(num) } else { None })
          .collect()
  }

  pub fn prime_sub_operation(nums: Vec<i32>) -> bool {
      let primes: Vec<usize> = Solution::sieve_of_eratosthenes(1000);
      let mut prev = -1; // Initial value for the previous element

      for &cur in &nums {
          let mut found = false;

          // Find the largest prime to subtract that still keeps the value greater than `prev`
          for &prime in primes.iter().rev() {
              if prime as i32 >= cur {
                  continue; // Skip primes larger than or equal to `cur`
              }
              let new_value = cur - prime as i32;
              if new_value > prev {
                  prev = new_value;
                  found = true;
                  break;
              }
          }

          // If no prime subtraction works, check if the original value works
          if !found {
              if cur > prev {
                  prev = cur;
              } else {
                  return false;
              }
          }
      }

      true
  }
}