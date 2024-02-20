/*

796. Rotate String
Easy
3.2K
124
Companies
Given two strings s and goal, return true if and only if s can become goal after
some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost
position.

For example, if s = "abcde", then it will be "bcdea" after one shift.


Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false


Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
Accepted
240.1K
Submissions
426.5K
Acceptance Rate
56.3%

*/

#include <string>

using namespace std;

class Solution {
  bool test(string &s, string &goal, int &n, int idx) {
    for (int i = 0; i < n; ++i) {
      if (s[i] != goal[(idx+i) % n]) return false;
    }
    return true;
  }

 public:
  bool rotateString(string s, string goal) {
    int n = s.size();
    if (n != goal.size()) return false;

    char first = s[0];
    for (int i = 0; i < n; ++i) {
      if (goal[i] == first) {
        if (test(s, goal,n, i)) return true;
      }
    }
    return false;
  }
};