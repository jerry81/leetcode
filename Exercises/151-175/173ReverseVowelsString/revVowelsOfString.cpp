/*

345. Reverse Vowels of a String
Easy
3.5K
2.4K
Companies
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.



Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"


Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
Accepted
516.9K
Submissions
1M
Acceptance Rate
50.4%

*/

#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
      string v = "";
      string vowels = "aeiou";

      for (char c: s) {
        if (vowels.find(c) != string::npos) {
          v.push_back(c);
        }
      }

      for (int i = 0; i < s.size(); ++i) {
        if (vowels.find(s[i]) != string::npos) {
          s[i] = v.back();
          v.pop_back();
        }
      }
      return s;
    }
};

