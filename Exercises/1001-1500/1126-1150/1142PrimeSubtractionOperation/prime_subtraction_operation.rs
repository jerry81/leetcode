/*
2601. Prime Subtraction Operation
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums of length n.

You can perform the following operation as many times as you want:

Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
Return true if you can make nums a strictly increasing array using the above operation and false otherwise.

A strictly increasing array is an array whose each element is strictly greater than its preceding element.



Example 1:

Input: nums = [4,9,6,10]
Output: true
Explanation: In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
After the second operation, nums is sorted in strictly increasing order, so the answer is true.
Example 2:

Input: nums = [6,8,11,12]
Output: true
Explanation: Initially nums is sorted in strictly increasing order, so we don't need to make any operations.
Example 3:

Input: nums = [5,8,3]
Output: false
Explanation: It can be proven that there is no way to perform operations to make nums sorted in strictly increasing order, so the answer is false.


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 1000
nums.length == n
Seen this question in a real interview before?
1/5
Yes
No
Accepted
21.2K
Submissions
51.6K
Acceptance Rate
41.0%

*/

impl Solution {
  fn sieve_of_eratosthenes(limit: usize) -> Vec<usize> {
    let mut is_prime = vec![true; limit as usize + 1];
    is_prime[0] = false;
    if limit >= 1 {
        is_prime[1] = true;
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

    // Collect the prime numbers into a vector
    is_prime.iter()
        .enumerate()
        .filter_map(|(num, &prime)| if prime { Some(num) } else { None })
        .collect()
  }

  pub fn prime_sub_operation(nums: Vec<i32>) -> bool {
    let primes: Vec<usize> = Solution::sieve_of_eratosthenes(1000);

    let n = nums.len();

    for i in 0..n {
      // get prev number
      // search for the current number
      // step back in  primes until
      // cur - prime > prev
      let cur = nums[i];
      let prev = if i == 0 { -1 } else {
        nums[i-1]
      };
      match primes.binary_search(&cur) {
          Ok(index) => println!("Found {} at index {}", &cur, index),
          Err(pos) => println!("{} is not present in the vector, but could be inserted at index {}", &cur, pos),
      }
    }
    true
  }
}