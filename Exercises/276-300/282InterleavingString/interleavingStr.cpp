/*

97. Interleaving String
Medium
7.2K
424
Companies
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1
and s2.

An interleaving of two strings s and t is a configuration where s and t are
divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3
+ s3 + ... Note: a + b is the concatenation of strings a and b.



Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" =
"aadbbcbcac". Since s3 can be obtained by interleaving s1 and s2, we return
true. Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string
to obtain s3. Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true


Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.


Follow up: Could you solve it using only O(s2.length) additional memory space?

Accepted
424.4K
Submissions
1.1M
Acceptance Rate
38.4%

*/

#include <string>

using namespace std;

class Solution {
  bool r(int p1, int p2, int p3, bool is1, string &s1, string &s2, string &s3) {
    if (is1) {
      if (p1 >= s1.size()) {
        return p3 >= s3.size() && p2 >= s2.size();
      }

      // matching time
      if (s1[p1] != s3[p3]) return false;

      while (p1 < s1.size() && p3 < s3.size()) {
        if (s1[p1] == s3[p3]) {
          if (r(p1+1,p2,p3+1,!is1,s1,s2,s3)) return true;

          p1++;
          p3++;
        } else {
          break;
        }
      }
    } else {
      if (p2 >= s2.size()) {
        return p3 >= s3.size() && p1 >= s1.size();
      }

      if (s2[p2] != s3[p3]) return false;

      while (p2 < s2.size() && p3 < s3.size()) {
        if (s2[p2] == s3[p3]) {
          if (r(p1,p2+1,p3+1,!is1,s1,s2,s3)) return true;

          p2++;
          p3++;
        } else {
          break;
        }
      }
      return false;
    }
    return false;
  }

 public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size()+s2.size()!=s3.size()) return false;
    return r(0,0,0,false,s1,s2,s3) || r(0,0,0,true,s1,s2,s3);
    // params - p1, p2, p3, is1
    // base cases active pointer >= len and p3 >= len - true
    // active pointer < len but p3 done - false
    // active pointer > len p3 < len - false
    // if first letter doesn't match then false
    // else for each matching letter dfs
    // s1 match n chars
    // must try 1 to n chars
  }
};