/*

925. Long Pressed Name
Easy
2.3K
333
Companies
Your friend is typing his name into a keyboard. Sometimes, when typing a
character c, the key might get long pressed, and the character will be typed 1
or more times.

You examine the typed characters of the keyboard. Return True if it is possible
that it was your friends name, with some characters (possibly none) being long
pressed.



Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it was not in the typed
output.


Constraints:

1 <= name.length, typed.length <= 1000
name and typed consist of only lowercase English letters.
Accepted
127.4K
Submissions
390.7K
Acceptance Rate
32.6%

*/

#include <string>

using namespace std;

class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    // recursion?
    if (name.empty() && typed.empty()) return true;

    if (name.empty()) return false;

    if (typed.empty()) return false;

    char curback = name.back();

    if (curback == typed.back()) {
      int typoCount = 0;
      while (!typed.empty() && typed.back() == curback) {
        typed.pop_back();
        typoCount++;
      }
      while (!name.empty() && name.back() == curback && typoCount > 0) {
        name.pop_back();
        typoCount--;
      }
      return isLongPressedName(name, typed);
    }

    return false;
  }
};

// fix: only can pop typed if prev popped matches

// when can we pop typed only?
// when a matched has been made