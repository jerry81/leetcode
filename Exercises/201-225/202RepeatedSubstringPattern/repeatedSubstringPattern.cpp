/*

459. Repeated Substring Pattern
Easy
4.5K
395
Companies
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.



Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
Example 2:

Input: s = "aba"
Output: false
Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.


Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
Accepted
301.3K
Submissions
689.8K
Acceptance Rate
43.7%

*/

#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      // use substr and compare string
      // only need to check to halfway point
      int halfSize = s.size() / 2;
      for (int i = 0; i <= halfSize; ++i) {
        string substrTry = s.substr(0,i);
        bool match = true;
        for (int mult = 1; mult*i <= s.size(); ++mult) {
          string substrCompare = s.substr(mult,i);
          if (substrTry != substrCompare) {
            match = false;
            break;
          }
        }
        if (match) return true;
      }
      return false;
    }
};

