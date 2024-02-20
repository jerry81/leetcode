/*

917. Reverse Only Letters
Easy
2.1K
66
Companies
Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.



Example 1:

Input: s = "ab-cd"
Output: "dc-ba"
Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"


Constraints:

1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.
Accepted
183.7K
Submissions
291.1K
Acceptance Rate
63.1%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
  pair<vector<string>, string> customSplit(string s) {
    vector<string> ret;
    string curStr = "";
    string accum = "";
    for (char c : s) {
      if (!isalpha(c)) {
        if (!curStr.empty()) ret.push_back(curStr);
        string str(1, c);
        ret.push_back(str);
        curStr = "";
      } else {
        curStr += c;
        accum += c;
      }
    }
    if (!curStr.empty()) ret.push_back(curStr);

    return {ret, accum};
  }

 public:
  string reverseOnlyLetters(string s) {
    auto [strs, accum] = customSplit(s);
    string ret = "";

    int idx = accum.size() - 1;
    for (string s : strs) {
      string curStr = "";
      char c = s[0];
      if (isalpha(c)) {
        int countdown = s.size();
        for (int i = 0; i < countdown; ++i) {
          curStr += accum[idx];
          idx--;
        }

      } else {
        curStr = s;
      }
      ret += curStr;
    }
    return ret;
  }
};