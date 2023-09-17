/*

821. Shortest Distance to a Character
Easy
3K
151
Companies
Given a string s and a character c that occurs in s, return an array of integers
answer where answer.length == s.length and answer[i] is the distance from index
i to the closest occurrence of character c in s.

The distance between two indices i and j is abs(i - j), where abs is the
absolute value function.



Example 1:

Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is
abs(0 - 3) = 3. The closest occurrence of 'e' for index 1 is at index 3, so the
distance is abs(1 - 3) = 2. For index 4, there is a tie between the 'e' at index
3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) ==
abs(4 - 5) = 1. The closest occurrence of 'e' for index 8 is at index 6, so the
distance is abs(8 - 6) = 2. Example 2:

Input: s = "aaab", c = "b"
Output: [3,2,1,0]


Constraints:

1 <= s.length <= 104
s[i] and c are lowercase English letters.
It is guaranteed that c occurs at least once in s.
Accepted
166.8K
Submissions
233.9K
Acceptance Rate
71.3%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> shortestToChar(string s, char c) {
    vector<int> ret;
    int n = s.size();
    bool found = false;
    for (int i = 0; i < n; ++i) {
      if (s[i] == c) {
        found = true;
        ret[i] = 0;
      } else if (!found) {
        ret[i] = INT_MAX;
      } else {
        ret[i] = ret[i - 1] + 1;
      }
    }
    for (int i = n - 2; i >= 0; --i) {
      ret[i] = min(ret[i], ret[i + 1]);
    }
  }
};