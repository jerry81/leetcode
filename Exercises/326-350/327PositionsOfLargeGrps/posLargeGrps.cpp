/*

830. Positions of Large Groups
Easy
821
121
Companies
In a string s of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".

A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].

A group is considered large if it has 3 or more characters.

Return the intervals of every large group sorted in increasing order by start index.



Example 1:

Input: s = "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the only large group with start index 3 and end index 6.
Example 2:

Input: s = "abc"
Output: []
Explanation: We have groups "a", "b", and "c", none of which are large groups.
Example 3:

Input: s = "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
Explanation: The large groups are "ddd", "eeee", and "bbb".


Constraints:

1 <= s.length <= 1000
s contains lowercase English letters only.
Accepted
87.4K
Submissions
168.3K
Acceptance Rate
51.9%

*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
      vector<vector<int>> res;
      char cur = ' ';
      int starti = 0;
      for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c != cur) {
          cur = c;
          if ((i-starti) >= 2) res.push_back({starti, i});
          starti = i;
        }
      }
      return res;
    }
};