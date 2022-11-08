/*

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.



Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true


Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char, int> freq_s;
      unordered_map<char, int> freq_t;
      for (char c:s) {
        if (freq_s.find(c) != freq_s.end()) {
          freq_s[c] = 1;
        } else {
          ++freq_s[c];
        }
      }
      for (char c:t) {
        if (freq_t.find(c) != freq_s.end()) {
          freq_t[c] = 1;
        } else {
          ++freq_t[c];
        }
      }
      /*
        make abstract counts of counts
      */
      unordered_map<int,int> freq_s2;
      unordered_map<int,int> freq_t2;
      for (pair<int,int> p: freq_s) {
        if (freq_s2.find(p.second) == freq_s2.end()) {
          freq_s2[p.second] = 1;
        } else {
          ++freq_s2[p.second];
        }
      }
      for (pair<int,int> p: freq_t) {
        if (freq_t2.find(p.second) == freq_t2.end()) {
          freq_t2[p.second] = 1;
        } else {
          ++freq_t2[p.second];
        }
      }
      for (auto p: freq_s2) {
        if (freq_t2[p.first] == p.second) {
          freq_t2.erase(p.first);
        }
      }

      return freq_t2.empty();
    }
};

/*

failing test

"bbbaaaba"
"aaabbbba"

expect false?

b/c order must be preserved, even though frequency matches (4 x 2 in both cases)
*/
