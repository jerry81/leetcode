/*

2370. Longest Ideal Subsequence
Medium
Topics
Companies
Hint
You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

t is a subsequence of the string s.
The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
Return the length of the longest ideal string.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.



Example 1:

Input: s = "acfgbd", k = 2
Output: 4
Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.
Example 2:

Input: s = "abcd", k = 3
Output: 4
Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.


Constraints:

1 <= s.length <= 105
0 <= k <= 25
s consists of lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
43.3K
Submissions
102.5K
Acceptance Rate
42.3%

*/

#include <string>

using namespace std;

class Solution {
int c_diff(char a, char b) {
  return abs((int)a - (int)b);
}
int r(string &s, int &k, int &sz, int idx, char last, bool hasLast) {
  if (idx >= sz) return 0;

  if (!hasLast) {
    int take = r(s,k,sz,idx+1,s[idx],true);
    int leave = r(s,k,sz,idx+1,'a',false);
    return max(take, leave);
  }
};
public:
    int longestIdealString(string s, int k) {
      int sz = s.size();
      return r(s,k,sz,0,'a', false);
    }
};