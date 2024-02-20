/*

58. Length of Last Word
Easy
3.1K
163
Companies
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal
substring
 consisting of non-space characters only.



Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.


Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
Accepted
1.1M
Submissions
2.6M
Acceptance Rate
43.5%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
vector<string> split(string str) {
    // Returns first token
    vector<string> ret;
    char *token = strtok(str.data(), " ");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != nullptr) {
      ret.push_back(token);
      token = strtok(nullptr, " ");

    }

    return ret;
  }
public:
    int lengthOfLastWord(string s) {
      vector<string> spl = split(s);
      return spl[spl.size()-1].size();
    }
};