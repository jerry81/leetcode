/*

1128. Number of Equivalent Domino Pairs
Easy
647
323
Companies
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].



Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
Example 2:

Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3


Constraints:

1 <= dominoes.length <= 4 * 104
dominoes[i].length == 2
1 <= dominoes[i][j] <= 9
Accepted
63K
Submissions
131.9K
Acceptance Rate
47.8%

*/

impl Solution {
  pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
    let sz = dominoes.len();
    let mut res = 0;
    for i in 0..sz-1 {
      for j in i+1..sz {
        let cura = &dominoes[i];
        let curb = &dominoes[j];
        if cura[0] == curb[0] && cura[1] == curb[1] {
          res+=1;
          continue;
        }

        if (cura[0] == curb[1] && cura[1] == curb[0]) {
          res+=1;
        }
      }
    }
    res
  }
}