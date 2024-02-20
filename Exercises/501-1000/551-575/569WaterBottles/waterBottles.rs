/*

1518. Water Bottles
Easy
Topics
Companies
Hint
There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.



Example 1:


Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.
Example 2:


Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 15 + 3 + 1 = 19.


Constraints:

1 <= numBottles <= 100
2 <= numExchange <= 100
Seen this question in a real interview before?
1/4
Yes
No
Accepted
72.7K
Submissions
119.7K
Acceptance Rate
60.7%

*/

impl Solution {
  pub fn num_water_bottles(num_bottles: i32, num_exchange: i32) -> i32 {
    let mut full: i32 = num_bottles;
    let mut emp: i32 = 0;
    let mut res: i32 = 0;
    while full > 0 {
      let mut tmp_empty=emp;
      res+=full;
      tmp_empty+=full;
      emp = tmp_empty%num_exchange;
      full = tmp_empty/num_exchange;

    }
    res
  }
}