/*
89. Gray Code
Medium
Topics
Companies
An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.



Example 1:

Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit
Example 2:

Input: n = 1
Output: [0,1]


Constraints:

1 <= n <= 16

Seen this question in a real interview before?
1/5

*/

use std::collections::HashMap;
impl Solution {
  pub fn gray_code(n: i32) -> Vec<i32> {
    let mut one_map: HashMap<u32, Vec<i32>>=HashMap::new();
    for i in 0..(2 as i32).pow(n as u32) {
      one_map.entry(i.count_ones()).or_insert_with(Vec::new).push(i);
    }
    println!("map is {:?}", one_map);
    let mut cnt = 0;
    let mut res: Vec<i32> = vec![];

    res.insert(0,0);

    res
  }
}