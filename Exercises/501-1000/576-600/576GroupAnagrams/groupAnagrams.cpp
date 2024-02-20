/*

49. Group Anagrams
Medium
Topics
Companies
Given an array of strings strs, group the anagrams together. You can return the
answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different
word or phrase, typically using all the original letters exactly once.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]


Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
2.6M
Submissions
3.8M
Acceptance Rate
67.8%

*/

#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
  string to_h(map<char, int> freq) {
    string ret = "";
    for (auto [k, v] : freq) {
      ret += "k:";
      ret += k;
      ret += ",";
      ret += "v:";
      ret += to_string(v);
      ret += ",";
    }
    return ret;
  }

 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;

    if (strs.empty()) return {};

    if (strs.size() == 1) return {{strs[0]}};

    map<string, vector<string>> grouped;

    for (string s : strs) {
      map<char, int> freq;
      for (char c : s) {
        if (freq.find(c) != freq.end()) {
          freq[c]++;
        } else {
          freq[c] = 1;
        }
      }
      string as_s = to_h(freq);
      grouped[as_s].push_back(s);
    }

    for (auto [_, v] : grouped) {
      res.push_back(v);
    }
    return res;
  }
};