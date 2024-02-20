/*

696. Count Binary Substrings
Easy
3.8K
814
Companies
Given a binary string s, return the number of non-empty substrings that have the
same number of 0's and 1's, and all the 0's and all the 1's in these substrings
are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.



Example 1:

Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's
and 0's: "0011", "01", "1100", "10", "0011", and "01". Notice that some of these
substrings repeat and are counted the number of times they occur. Also,
"00110011" is not a valid substring because all the 0's (and 1's) are not
grouped together. Example 2:

Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal
number of consecutive 1's and 0's.


Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.
Accepted
191.9K
Submissions
293.4K
Acceptance Rate
65.4%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int countBinarySubstrings(string s) {
    vector<int> groups;
    bool init = false;
    char cur;
    int count = 0;
    for (char c : s) {
      if (!init) {
        cur = c;
        count = 1;
        init = true;
      } else {
        if (cur == c) {
          count++;
        } else {
          groups.push_back(count);
          count = 1;
          cur = c;
        }
      }
    }
    groups.push_back(count);
    if (groups.size() < 2) return 0;
    int res = 0;
    for (int i = 0; i < groups.size() - 1; ++i) {
      int group1 = groups[i];
      int group2 = groups[i+1];
      res+= min(group1,group2);
    }
    return res;
  }
};
// prefix sums?
// nope - another condition - 1s and 0s grouped together
//
