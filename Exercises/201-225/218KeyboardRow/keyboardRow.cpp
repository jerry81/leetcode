/*
500. Keyboard Row
Easy
1.4K
1.1K
Companies
Given an array of strings words, return the words that can be typed using
letters of the alphabet on only one row of American keyboard like the image
below.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".



Example 1:

Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
Example 2:

Input: words = ["omk"]
Output: []
Example 3:

Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]


Constraints:

1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] consists of English letters (both lowercase and uppercase).
Accepted
189.9K
Submissions
272.6K
Acceptance Rate
69.7%
*/

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findWords(vector<string>& words) {
    unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't',
                                'y', 'u', 'i', 'o', 'p'};
    unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};

    unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    vector<string> res;

    for (string s: words) {
      unordered_set<char> lookup;
      if (s.empty()) {
        res.push_back(s);
        continue;
      }

      if (row1.count(tolower(s[0])) > 0) {
        lookup = row1;
      } else if (row2.count(tolower(s[0])) > 0) {
         lookup = row2;
      } else if (row3.count(tolower(s[0])) > 0) {
        lookup = row3;
      } else {
        continue;
      }

      bool found = true;
      for (int i = 1; i < s.size(); ++i) {
        char tofind = tolower(s[i]);
        if (lookup.count(tofind) == 0) {
          found = false;
          break;
        }
      }

      if (found) res.push_back(s);
    }
    return res;
  }
};