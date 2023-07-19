/*

520. Detect Capital
Easy
3.2K
446
Companies
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.



Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false


Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.
Accepted
396.1K
Submissions
696.5K
Acceptance Rate
56.9%

*/

#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
      bool allCapital = true;
      bool allLower = true;
      bool notMixed = true;
      for (int i = 0; i < word.size(); ++i) {
        char c = word[i];
        if (isupper(c)) {
          allLower = false;
          if (i != 0) {
            notMixed = false;
          }
        } else {
          allCapital = false;
        }
      }
      return allCapital || allLower || notMixed;
    }
};