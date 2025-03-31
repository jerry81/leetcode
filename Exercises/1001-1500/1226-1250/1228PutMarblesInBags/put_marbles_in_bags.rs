/*

2551. Put Marbles in Bags
Hard
Topics
Companies
Hint
You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.

Divide the marbles into the k bags according to the following rules:

No bag is empty.
If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
The score after distributing the marbles is the sum of the costs of all the k bags.

Return the difference between the maximum and minimum scores among marble distributions.



Example 1:

Input: weights = [1,3,5,1], k = 2
Output: 4
Explanation:
The distribution [1],[3,5,1] results in the minimal score of (1+1) + (3+1) = 6.
The distribution [1,3],[5,1], results in the maximal score of (1+3) + (5+1) = 10.
Thus, we return their difference 10 - 6 = 4.
Example 2:

Input: weights = [1, 3], k = 2
Output: 0
Explanation: The only distribution possible is [1],[3].
Since both the maximal and minimal score are the same, we return 0.


Constraints:

1 <= k <= weights.length <= 105
1 <= weights[i] <= 109
Seen this question in a real interview before?
1/5
Yes
No
Accepted
66.3K
Submissions
99.2K
Acceptance Rate
66.9%

*/

use std::collections::HashMap;

impl Solution {
  // naive: brute force, memoize "ranges"
  fn get_min_score(weights: &Vec<i32>, k: i32, hm: &HashMap<(usize,usize), i64>) -> i64 {
    0
  }
  fn get_max_score(weights: &Vec<i32>, k: i32, hm: &HashMap<(usize,usize), i64>) -> i64 {
    0
  }
  fn build_hashmap(weights: &Vec<i32>, k: i32) -> HashMap<(usize,usize), i64> {
    // recursively?
    let mut ret:HashMap<(usize,usize), i64> = HashMap::new();
    let ku:usize = k as usize;
    // k groups
    let mut starter = 0;
    let starter_val = weight[0];
    for group1ender in 0..ku {
      ender_val = weight[group1ender];
      *ret.entry((0, group1ender)).or_insert(0) = starter_val + ender_val;
    }
    ret.clone()
  }
  pub fn put_marbles(weights: Vec<i32>, k: i32) -> i64 {
    let mut hm: HashMap<(usize,usize), i64> = Solution::build_hashmap(&weights,k);
    println!("hm is {:?}", hm);
    Solution::get_max_score(&weights, k,&hm) - Solution::get_min_score(&weights,k,&hm)
  }
}