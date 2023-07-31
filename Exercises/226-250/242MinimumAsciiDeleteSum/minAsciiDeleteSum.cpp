/*

712. Minimum ASCII Delete Sum for Two Strings
Medium
3.1K
81
Companies
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters
to make two strings equal.



Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the
sum. Deleting "t" from "eat" adds 116 to the sum. At the end, both strings are
equal, and 115 + 116 = 231 is the minimum sum possible to achieve this. Example
2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 =
403. If instead we turned both strings into "lee" or "eet", we would get answers
of 433 or 417, which are higher.


Constraints:

1 <= s1.length, s2.length <= 1000
s1 and s2 consist of lowercase English letters.
Accepted
99.4K
Submissions
154.9K
Acceptance Rate
64.1%

*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  string first;
  string second;
  unordered_map<string, int> dp;
  int r(int i1, int i2) {
    string as_hash = to_hash(i1, i2);
    if (dp.find(as_hash) != dp.end()) return dp[as_hash];

    if (i1 < 0 && i2 < 0) {
      dp[as_hash] = 0;
      return 0;
    }

    // termination cases
    if (i1 < 0) {
      int sum = 0;
      while (i2 >= 0) {
        sum += (int)second[i2];
        i2--;
      }
      dp[as_hash] = sum;
      return sum;
    }

    if (i2 < 0) {
      int sum = 0;
      while (i1 >= 0) {
        sum += (int)first[i1];
        i1--;
      }
      dp[as_hash] = sum;
      return sum;
    }

    if (first[i1] == second[i2]) {
      dp[as_hash] = r(i1 - 1, i2 - 1);
      return dp[as_hash];
    }

    if (first[i1] != second[i2]) {
      int path1 = (int)first[i1] + r(i1 - 1, i2);
      int path2 = (int)second[i2] + r(i1, i2 - 1);
      int path3 = (int)first[i1] + (int)second[i2] + r(i1 - 1, i2 - 1);
      dp[as_hash] = min(path1, min(path2, path3));
      return dp[as_hash];
    }
  }
  string to_hash(int i1, int i2) { return to_string(i1) + "," + to_string(i2); }

 public:
  int minimumDeleteSum(string s1, string s2) {
    first = s1;
    second = s2;
    return r(s1.size() - 1, s2.size() - 1);
  }
};

/*

2 stages

1.  ways to delete to make equal
  a.  something with subsequences? - longest common subsequence finds the min
diff
2.  optimize sums

official solutions
1.  recursion (TLE)
  - base case
    - both empty - cost 0
    - one empty - delete all of the other
  - recursive relation
    1.  case - chars dont match
      1.  delete from a
      2.  delete from b
      3.  delete from both
    2.  case - chars match dont delete
2.  bottom up dp
3.  top down dp
4.  space optimized bottom up

*/