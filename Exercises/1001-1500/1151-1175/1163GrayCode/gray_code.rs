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
    let total = (2 as i32).pow(n as u32)
    let mut one_map: HashMap<u32, Vec<i32>>=HashMap::new();
    for i in total {
      one_map.entry(i.count_ones()).or_insert_with(Vec::new).push(i);
    }
    let mut res: Vec<i32> = vec![];
    let mut cnt = 0;
    while res.len() < (total-1) {
      if cnt == 0 {
        cnt = 1;
      } else {
        if one_map[cnt+1].len() > one_map[cnt-1].len() {
           cnt+=1;
        } else {
           cnt-=1;
        }
      }
      res.push(one_map.get(&cnt).last());
        res.insert(0,one_map.get(&cnt).last());
        one_map.get_mut(&cnt).unwrap().pop();
        one_map.get_mut(&cnt).unwrap().pop();
    }
    // keep taking 2 items from front and back depending on which has more items


    res.insert(0,0);

    res
  }
}