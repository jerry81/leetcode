/*

541. Reverse String II
Easy
1.7K
3.3K
Companies
Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.



Example 1:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Example 2:

Input: s = "abcd", k = 2
Output: "bacd"


Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 104
Accepted
204.2K
Submissions
405.3K
Acceptance Rate
50.4%

*/

#include <string>

using namespace std;
class Solution {
  string r(string s) {
    string ret = "";
    for (int i = s.size()-1; i >= 0; --i) {
      ret.push_back(s[i]);
    }
    return ret;
  }
public:
    string reverseStr(string s, int k) {
      // chop and stitch
      bool flipper = true;
      string ret = "";
      for (int i = 0; i <= s.size(); i+=k) {
        string temp = s.substr(i,k);
        if (flipper) {
          ret+=r(temp);
        } else {
          ret+=temp;
        }
        flipper=!flipper;
      }
      return ret;
    }
};