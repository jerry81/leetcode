/*

389. Find the Difference
Easy
3.9K
430
Companies
You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.



Example 1:

Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.
Example 2:

Input: s = "", t = "y"
Output: "y"


Constraints:

0 <= s.length <= 1000
t.length == s.length + 1
s and t consist of lowercase English letters.
Accepted
507.3K
Submissions
850.6K
Acceptance Rate
59.6%

*/

#include <string>
#include <map>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
      map<char, int> freq;
      for (char c: s) {
        freq[c]++;
      }
      for (char c: t) {
        freq[c]--;
        if (freq[c] < 0) return c;
      }
    }
};