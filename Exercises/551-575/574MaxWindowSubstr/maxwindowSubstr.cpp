/*

76. Minimum Window Substring
Hard
Topics
Companies
Hint
Given two strings s and t of lengths m and n respectively, return the minimum window
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?

Seen this question in a real interview before?
1/4
Yes
No
Accepted
1.2M
Submissions
2.9M
Acceptance Rate
41.9%

*/

#include <string>
#include <unordered_map>
using namespace std;

class Solution {

public:
    string minWindow(string s, string t) {
      unordered_map<char, int> t_freq;
      for (char c: t) {
        t_freq[c]++;
      }
      int mx = 0;

      unordered_map<char,int> under_flow;
      int left = 0;
      string res = "";
      for (int right = 0; right < s.size(); ++right) {
        char c = s[right];
        if (t_freq.empty()) {
          if (res.size() < (right - left + 1)) {
            res = res.substr(left, right - left + 1);
          }
        }
      }
      return res;
    }
};