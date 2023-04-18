/*

1768. Merge Strings Alternately
Easy
1.4K
22
Companies
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.



Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d


Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
Accepted
128.3K
Submissions
159K
Acceptance Rate
80.7%

*/

#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
      int p1 = 0;
      int p2 = 0;
      bool b1 = true;
      string merged = "";
      while (p1 < word1.size() && p2 < word2.size()) {
        char inserted;
        if (b1) {
          if (p1 < word1.size()) {
            ++p1;
          } else {
            inserted = word2[p2];
            ++p2;
          }
          b1 = false;
        } else {
          if (p2 < word2.size()) {
            ++p2;
          } else {
            inserted = word1[p1];
            ++p1;
          }
          b1 = true;
        }
        merged.push_back(inserted);
      }
      return merged;
    }
};