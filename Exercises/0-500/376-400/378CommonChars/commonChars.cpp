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

    string foist = words.front();
    vector<string> ret;
    unordered_map<char, int> freq;
    for (char c: foist) {
      freq[c]++;
      ret.push_back(string(1,c));
    }

    if (words.size() == 1) return ret;

    ret = {};

    for (int i = 1; i < words.size(); ++i) {
      string cur = words[i];
      unordered_map<char, int> cfreq;
      for (char c: cur) {
        if (foist.find(c) == string::npos) continue;
        cfreq[c]++;
      }
      for (auto a: freq) {
        freq[a.first] = min(freq[a.first], cfreq[a.first]);
      }
    }
    for (auto a: freq) {
      for (int i = 0; i < a.second; ++i) {
        ret.push_back(string(1,a.first));
      }
    }
    return ret;
  }
};