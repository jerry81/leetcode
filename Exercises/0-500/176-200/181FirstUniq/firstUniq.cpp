/*

387. First Unique Character in a String
Easy
7.8K
255
Companies
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.



Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1


Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
Accepted
1.4M
Submissions
2.4M
Acceptance Rate
59.8%

*/

#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
      map<char, int> freq;
      for (char c: s) {
        freq[c]++;
      }
      for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (freq[c] == 1) return i;
      }
      return -1;
    }
};