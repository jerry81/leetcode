/*

997. Find the Town Judge
Solved
Easy
Topics
Companies
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.



Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1


Constraints:

1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n
Seen this question in a real interview before?
1/4
Yes
No
Accepted
463.8K
Submissions
942.2K
Acceptance Rate
49.2%

*/
use std::collections::HashMap;

impl Solution {
  pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
    let mut indegrees: HashMap<i32,i32> = HashMap::new();
    let mut outdegrees: HashMap<i32,i32> = HashMap::new();
    for i in 1..=n {
      indegrees.insert(i, 0);
      outdegrees.insert(i,0);
    }
    for v in trust {
      *indegrees.entry(v[1]).or_insert(0) += 1;
      *outdegrees.entry(v[0]).or_insert(0) += 1;
    }
    let mut cnt = 0;
    let mut cnt2 = 0;
    for (k,v) in &indegrees {
      if *v == n-1 {
       cnt+=1;
      }
    }
    let mut cnt2 = 0;
    let mut idx = -1;
    for (k,v) in &outdegrees {
      if *v == 0 {
       cnt2+=1;
       idx = *k;
      }
    }
    if cnt == 1 && cnt2 == 1 {
      return idx;
    }
    -1
  }
}