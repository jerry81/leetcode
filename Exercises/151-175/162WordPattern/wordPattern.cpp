/*

290. Word Pattern
Easy
6.3K
754
Companies
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter
in pattern and a non-empty word in s.



Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false


Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
Accepted
528.3K
Submissions
1.3M
Acceptance Rate
41.7%

*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
  vector<string> split(string str) {
    // Returns first token
    vector<string> ret;
    char *token = strtok(str.data(), " ");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != nullptr) {
      ret.push_back(token);
      token = strtok(nullptr, " ");
    }

    return ret;
  }
  unordered_map<char, string> lookup;
  unordered_map<string, char> strLookup;

 public:
  bool wordPattern(string pattern, string s) {
    vector<string> sv = split(s);
    if (sv.size() != pattern.size()) return false;
    for (int i = 0; i < sv.size(); ++i) {
      char c = pattern[i];
      string str = sv[i];
      if (lookup.find(c) == lookup.end() && strLookup.find(str) == strLookup.end()){
        lookup[c] = str;
        strLookup[str] = c;
      } else if (lookup.find(c) != lookup.end()) {
        if (lookup[c] != str) return false;
      } else {
        if (strLookup[str] != c) return false;
      }
    }
    return true;
  }
};