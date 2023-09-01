/*

709. To Lower Case
Easy
1.7K
2.7K
Companies
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.



Example 1:

Input: s = "Hello"
Output: "hello"
Example 2:

Input: s = "here"
Output: "here"
Example 3:

Input: s = "LOVELY"
Output: "lovely"


Constraints:

1 <= s.length <= 100
s consists of printable ASCII characters.
Accepted
448.7K
Submissions
542.6K
Acceptance Rate
82.7%

*/

#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    string toLowerCase(string s) {
      string ret;
      for (char c: s) {
        ret.push_back(tolower(c));
      }
      return ret;
    }
};