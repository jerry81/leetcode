/*

1662. Check If Two String Arrays are Equivalent
Easy
2.4K
179
Companies
Given two string arrays word1 and word2, return true if the two arrays represent
the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order
forms the string.



Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
Example 2:

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
Example 3:

Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true


Constraints:

1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.
Accepted
319.4K
Submissions
380.2K
Acceptance Rate
84.0%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string s1 = "";
    for (string s : word1) {
      s1 += s;
    }
    string s2 = "";
    for (string s : word2) {
      s2 += s;
    }
    return s1 == s2;
  }
};