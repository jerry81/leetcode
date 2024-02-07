/*

451. Sort Characters By Frequency
Medium
Topics
Companies
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.



Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
614.9K
Submissions
862.2K
Acceptance Rate
71.3%

*/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
      unordered_map<char, int> freq;
      for (char c: s) {
        if (freq.find(c) != freq.end()) {
          freq[c]++;
        } else {
          freq[c] = 1;
        }
      }
      vector<pair<char, int>> pairs;
      for (auto [k,v]: freq) {
        pairs.push_back({k,v});
      }
    }
};