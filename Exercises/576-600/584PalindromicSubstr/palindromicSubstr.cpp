/*

647. Palindromic Substrings
Medium
Topics
Companies
Hint
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
671.9K
Submissions
982.2K
Acceptance Rate
68.4%

*/

#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
      int sz = s.size();
      if (sz==1) return 1;
      // try brute force
      int count = 0;
      for (int i = 0; i < sz; ++i) {
        for (int j = 2; j < sz-i; ++j) {
          cout << "substr from " << i << " of len " << j << endl;
          cout << s.substr(i, j) << endl;
        }
      }
      return count;
    }
};

/*
abc
0, 01, 012  len 1 auto yes, len 2 - characters are equal, len 3 char 1 and 3 are equal
1, 12 - any relation to previous substrings?
2
*/
/*
abccbd
01,012,0123,01234,012345
12,123,1234,12345
23,234,2345
34,345
45
*/