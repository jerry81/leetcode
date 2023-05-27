/*

242. Valid Anagram
Easy
9.1K
286
Companies
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.


Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

Accepted
2.2M
Submissions
3.5M
Acceptance Rate
63.1%

*/

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
      unordered_map<char, int> freq;
      for (char c: s) {
        freq[c]++;
      }
      for (char c:t) {
        freq[c]--;
        if (freq[c] == 0) {
          freq.erase(c);
        }
      }
      return freq.size() == 0;
    }
};