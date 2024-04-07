/*


678. Valid Parenthesis String
Medium
Topics
Companies
Given a string s containing only three types of characters: '(', ')' and '*',
return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left
parenthesis '(' or an empty string "".


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true


Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
261.6K
Submissions
745.3K
Acceptance Rate
35.1%

*/

#include <string>

using namespace std;
class Solution {
 public:
  bool checkValidString(string s) {
    // iterate forwards
    // iterate backwards
    int wildcount = 0;
    int lcount = 0;
    for (char c : s) {
      if (c == '(') {
        lcount += 1;
      } else if (c == ')') {
        if (lcount < 1) {
          if (wildcount < 1) {
            return false;
          } else {
            wildcount -= 1;
          }
        } else {
          lcount -= 1;
        }
      } else {
        wildcount += 1;
      }
    }
    cout << "lcount " << lcount << endl;
    if (lcount > wildcount) return false;

    string rev = s;
    reverse(rev.begin(), rev.end());
    cout << "rev is " << rev << endl;
    lcount = 0;
    wildcount = 0;
    for (char c : rev) {
      if (c == ')') {
        lcount += 1;
      } else if (c == '(') {
        if (lcount < 1) {
          if (wildcount < 1) {
            return false;
          } else {
            wildcount -= 1;
          }
        } else {
          lcount -= 1;
        }
      } else {
        wildcount += 1;
      }
    }
    cout << "lcount " << lcount << endl;
    cout << "wildcount is " << wildcount << endl;
    return lcount <= wildcount;
  }
};