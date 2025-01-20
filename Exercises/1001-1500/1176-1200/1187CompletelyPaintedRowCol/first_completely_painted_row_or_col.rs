/*

2661. First Completely Painted Row or Column
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.



Example 1:

image explanation for example 1
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
Example 2:

image explanation for example 2
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].


Constraints:

m == mat.length
n = mat[i].length
arr.length == m * n
1 <= m, n <= 105
1 <= m * n <= 105
1 <= arr[i], mat[r][c] <= m * n
All the integers of arr are unique.
All the integers of mat are unique.
Accepted
34.2K
Submissions
63.9K
Acceptance Rate
53.6%

*/

use std::collections::HashMap;

impl Solution {
  pub fn first_complete_index(arr: Vec<i32>, mat: Vec<Vec<i32>>) -> i32 {
    let mut hm: HashMap<i32,(usize,usize)> = HashMap::new();
    let h: usize = mat.len();
    let w: usize = mat[0].len();
    let mut r_counts: Vec<i32> = vec![0;h];
    let mut c_counts: Vec<i32> = vec![0;w];
    for r in 0..h {
      for c in 0..w {
        *hm.entry(mat[r][c]).or_insert((0,0)) = (r,c);
      }
    }
    let mut res = 0;
    for idx in 0..arr.len() {
      let (r,c) = hm[&arr[idx]];
      r_counts[r]+=1;
      c_counts[c]+=1;
      if c_counts[c] == w {
        res = idx;
        break
      }
      if r_counts[r] == h {
        res = idx;
        break
      }
    }
    res
  }
}