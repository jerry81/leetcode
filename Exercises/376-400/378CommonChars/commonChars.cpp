/*

1002. Find Common Characters
Easy
3.4K
269
Companies
Given a string array words, return an array of all characters that show up in
all strings within the words (including duplicates). You may return the answer
in any order.



Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]


Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.
Accepted
194.1K
Submissions
282.8K
Acceptance Rate
68.6%

*/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    vector<unordered_map<char, int>> freqs;
    for (string w : words) {
      unordered_map<char,int> tmp;
      for (char c: w) {
        tmp[c]++;
      }
    }
    // brute force?
    vector<string> res;
    for (char c = 'a'; c <= 'z'; ++c) {
      bool missing = false;
      int count = INT_MAX;
      for (auto a: freqs) {
        if (a.find(c) == a.end()) {
          missing = true;
          break;
        }

        count = min(count, a[c]);
      }
      if (!missing) {
        for (int i = 0; i < count; ++i) {
          res.push_back(string(1,c));
        }
      }
    }
    return res;
  }
};