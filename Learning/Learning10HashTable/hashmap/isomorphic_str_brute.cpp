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
#include <iostream>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
          unordered_map<char, char> mapping;
          unordered_map<char, char> back_map;
          for (int i = 0; i < t.length(); ++i) {
            char sc = s[i];
            char tc = t[i];
            if (mapping.find(sc) != mapping.end() && (mapping[sc] != tc) ) return false;
            if (back_map.find(tc) != mapping.end() && (back_map[tc] != sc)) return false;
            if (mapping.find(sc) == mapping.end()) {
              mapping[sc] = tc;
              back_map[tc] = sc;
              continue;
            }


          }
          return true;
    }
};