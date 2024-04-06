/*

1249. Minimum Remove to Make Valid Parentheses
Medium
Topics
Companies
Hint
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.


Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.


Constraints:

1 <= s.length <= 105
s[i] is either'(' , ')', or lowercase English letter.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
597K
Submissions
886.1K
Acceptance Rate
67.4%

*/

#include <string>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
      int cnt = 0;
      string pre_res = "";
      for (char c: s) {
        if (c == ')') {
          if (cnt > 0) {
            cnt--;
          } else {
            continue;
          }
        }
        if (c == '(') {
          cnt+=1;
        }
        pre_res.push_back(c);
      }
      string res = "";
      cout << "presres is " << pres_res << endl;
      return res;
    }
};