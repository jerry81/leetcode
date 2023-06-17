/*

434. Number of Segments in a String
Easy
670
1.2K
Companies
Given a string s, return the number of segments in the string.

A segment is defined to be a contiguous sequence of non-space characters.



Example 1:

Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
Example 2:

Input: s = "Hello"
Output: 1


Constraints:

0 <= s.length <= 300
s consists of lowercase and uppercase English letters, digits, or one of the following characters "!@#$%^&*()_+-=',.:".
The only space character in s is ' '.
Accepted
147.8K
Submissions
400.8K
Acceptance Rate
36.9%


*/

#include <string>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
      int sum = 0;
      bool toggle = false;
      for (char c: s) {
        if (c == ' ') {
          if (toggle) {
            toggle = false;
            sum++;
          }
        } else {
          if (!toggle) {
            toggle = true;
          }
        }
      }
      if (toggle) sum++;
      return sum;
    }
};