/*

316. Remove Duplicate Letters
Medium
7.4K
474
Companies
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
the smallest in lexicographical order
 among all possible results.



Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"


Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.


Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

Accepted
247.8K
Submissions
538.5K
Acceptance Rate
46.0%

*/

#include <string>
#include <unordered_map>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
string res = "";
string knapsack(int idx, int mask, int &fullmask, int &sz, string &s) {
  return "";
}
public:
    string removeDuplicateLetters(string s) {
      unordered_map<char, int> chars;
      int fullmask = 0;
      int counter = 0;
      unordered_map<char,int> masks;
      for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (chars.find(c) == chars.end()) {
          chars[c] = i;
          masks[c] = pow(2,counter);
          fullmask+=masks[c];
          ++counter;
        }
      }
      // bitmask can be used to check if a char has been "used"
      // knapsack, take or leave - leave if duplicate, also leave voluntarily
      // further optimization -> start with each character (lowest index of)
    }
};