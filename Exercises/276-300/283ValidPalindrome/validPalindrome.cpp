/*

680. Valid Palindrome II
Easy
7.6K
384
Companies
Given a string s, return true if the s can be palindrome after deleting at most one character from it.



Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false


Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
Accepted
621.8K
Submissions
1.6M
Acceptance Rate
39.5%

*/

#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
      int p1 = 0;
      int p2 = s.size()-1;
      bool error = false;
      while (p1 < p2) {
        if (s[p1] != s[p2]) {
          if (error) return false;

          error = true;
          if (s[p1+1] == s[p2]) {
            p1+=1;
          } else {
            p2-=1;
          }
          continue;
        }
        p1++;
        p2--;
      }
      return true;
    }
};