/*

1534. Count Good Triplets
Easy
Topics
Companies
Hint
Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.

A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
Where |x| denotes the absolute value of x.

Return the number of good triplets.



Example 1:

Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
Output: 4
Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
Example 2:

Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
Output: 0
Explanation: No triplet satisfies all conditions.


Constraints:

3 <= arr.length <= 100
0 <= arr[i] <= 1000
0 <= a, b, c <= 1000
Seen this question in a real interview before?
1/4
Yes
No
Accepted
113K
Submissions
139.3K
Acceptance Rate
81.1%

*/

impl Solution {
  pub fn count_good_triplets(arr: Vec<i32>, a: i32, b: i32, c: i32) -> i32 {
    let mut res = 0;
    let sz = arr.len();
    for i in 0..sz-2 {
      let iv = arr[i];
      for j in i+1..sz-1 {
        let jv = arr[j];
        for k in j+1..sz {
          let kv = arr[k];
        }
      }
    }
    res
  }
}