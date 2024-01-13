/*

1347. Minimum Number of Steps to Make Two Strings Anagram
Medium
Topics
Companies
Hint
You are given two strings of the same length s and t. In one step you can choose
any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a
different (or the same) ordering.



Example 1:

Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
Example 2:

Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to
make t anagram of s. Example 3:

Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams.


Constraints:

1 <= s.length <= 5 * 104
s.length == t.length
s and t consist of lowercase English letters only.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
154.8K
Submissions
196.3K
Acceptance Rate
78.8%

*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int minSteps(string s, string t) {
    unordered_map<char, int> a;
    unordered_map<char, int> b;
    for (char c: s) {
      a[c]++;
    }
    for (char c: t) {
      b[c]++;
    }
    int res = 0;
    for (auto [k,v]: a) {
      if (b.find(k) == b.end()) {
        res+=v;
      } else {
        res+=v-b[k];
      }
    }
    return res;
  }
};