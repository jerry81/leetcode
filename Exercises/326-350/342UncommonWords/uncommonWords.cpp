/*

884. Uncommon Words from Two Sentences
Easy
1.3K
164
Companies
A sentence is a string of single-space separated words where each word consists
only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does
not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may
return the answer in any order.



Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: s1 = "apple apple", s2 = "banana"
Output: ["banana"]


Constraints:

1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.
Accepted
126.1K
Submissions
189.2K
Acceptance Rate
66.6%

*/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> split(string str, string delimiter) {
  // Returns first token
  vector<string> ret;
  const char *del = delimiter.c_str();
  char *token = strtok(str.data(), del);

  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != nullptr) {
    ret.push_back(token);
    token = strtok(nullptr, del);
  }

  return ret;
}

class Solution {
 public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> seen;
    unordered_map<string, int> seen2;
    vector<string> spl1 = split(s1, " ");
    for (string s : spl1) {
      seen[s]++;
    }
    vector<string> spl2 = split(s2, " ");
    vector<string> res;
    for (string s : spl2) {
      seen2[s]++;
    }
    for (auto [k, v] : seen) {
      if (v == 1) {
        if (seen2.find(k) == seen2.end()) res.push_back(k);
      }
    }
    for (auto [k, v] : seen2) {
      if (v == 1) {
        if (seen.find(k) == seen.end()) res.push_back(k);
      }
    }

    return res;
  }
};