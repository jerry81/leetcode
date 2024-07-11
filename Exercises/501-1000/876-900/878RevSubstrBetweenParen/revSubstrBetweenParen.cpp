/*

1190. Reverse Substrings Between Each Pair of Parentheses
Medium
Topics
Companies
Hint
You are given a string s that consists of lower case English letters and
brackets.

Reverse the strings in each pair of matching parentheses, starting from the
innermost one.

Your result should not contain any brackets.



Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is
reversed. Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the
whole string.


Constraints:

1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
115.4K
Submissions
166.9K
Acceptance Rate
69.1%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string reverseParentheses(string s) {
    // stack
    vector<string> stk;
    string cur_top = "";
    for (char c: s) {
      if (c == '(') {
        stk.push_back(cur_top);
        cur_top = "";
      } else if (c == ')') {
        if (stk.empty()) return "";
        string t = stk.back();
        stk.pop_back();
        reverse(cur_top.begin(), cur_top.end());
        t += cur_top;
        cur_top = t;

      } else {
        cur_top.push_back(c);
      }
    }
    return cur_top;
  }
};


/* Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the
whole string.

stack:
start new string with each (
oc
et
ed
pop on ) , reverse
oc -> co - append to remaining top

etco
ed
) etoc -> octe
edocte
letters go to top
edocteel
final )
leetcode
*/