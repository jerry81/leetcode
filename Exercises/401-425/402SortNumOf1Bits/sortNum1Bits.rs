/*

1356. Sort Integers by The Number of 1 Bits
Easy
1.9K
96
Companies
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.



Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.


Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 104
Accepted
134.5K
Submissions
181.3K
Acceptance Rate
74.2%

*/

use std::collections::HashMap;
use std::cmp::Ordering;

#[derive(Debug, PartialOrd, PartialEq, Eq)] // autogen impl for various traits for struct or enum
struct Item {
  num: i32,
  count: i32,
} // no semicolon allowed here

impl Ord for Item { // custom comparator
  fn cmp(&self, other: &Self) -> Ordering { // small self, big self! - self - current instance, Self type of current instance
    match self.count.cmp(&other.count) { // here's that nifty match again
      Ordering::Equal => { // ordering is an enum - also Greater, Less
        self.num.cmp(&other.num)
      },
      result => result,
    }
  }
}

impl Solution {
  pub fn sort_by_bits(arr: Vec<i32>) -> Vec<i32> {
    let mut sorted = Vec::new();
    for val in arr {
      let bstr = format!("{:b}", val); // int -> binary string
      let mut ct = 0;
      for c in bstr.chars() {
        if c == '1' {
          ct+=1;
        }
      }
      let newItem = Item {
        num: val,
        count: ct,
      };
      sorted.push(newItem);
    }
    sorted.sort_by(|a,b| a.cmp(b));
    let mut ret = Vec::new();

    for s in &sorted { // why the ampersand?  borrow?
      ret.push(s.num);
    }

    ret
  }
}