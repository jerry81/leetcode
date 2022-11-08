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
          unordered_map<char, char> mapping;
          for (int i = 0; i < t.length(); ++i) {
            if (mapping.find(s[i]) != mapping.end()) {
              mapping[s[i]] = t[i];
            }
          }
          for (int i = 0; i < t.length(); ++i) {
            if (mapping[s[i]] != t[i]) return false;
          }
          return true;
    }
};