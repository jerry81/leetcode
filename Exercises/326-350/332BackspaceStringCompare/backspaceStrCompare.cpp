/*

844. Backspace String Compare
Easy
6.7K
304
Companies
Given two strings s and t, return true if they are equal when both are typed
into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.



Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".


Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.


Follow up: Can you solve it in O(n) time and O(1) space?

Accepted
670.6K
Submissions
1.4M
Acceptance Rate
48.1%

*/

#include <string>

using namespace std;

class Solution {
  string type_out(string inp) {
    string ret = "";
    for (char c : inp) {
      if (c == "#" && !ret.empty()) {
        ret.pop_back();
        continue;
      }

      ret+=c;
    }
    return ret;
  }

 public:
  bool backspaceCompare(string s, string t) {
    string typeds = type_out(s);
    string typedt = type_out(t);
    return typeds == typedt;
  }
};