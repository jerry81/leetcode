/*

139. Word Break
Medium
14.9K
628
Companies
Given a string s and a dictionary of strings wordDict, return true if s can be
segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the
segmentation.



Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen
apple". Note that you are allowed to reuse a dictionary word. Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false


Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Accepted
1.4M
Submissions

*/

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct TrieNode {
  char c;
  bool ender = false;
  unordered_map<char, TrieNode*> nexts;
  TrieNode(char c) : c(c){};
};
class Solution {
  unordered_map<char, TrieNode*> root;

  void buildTreeR(unordered_map<char, TrieNode*> &root, string s) {
    if (s.empty()) return;

    char f = s[0];
    s.erase(s.begin());
    if (root.find(f) == root.end()) root[f] = new TrieNode(f);

    if (s.empty()) root[f]->ender = true;

    buildTreeR(root[f]->nexts, s);
  }

  void buildTrie(vector<string>& wordDict) {
    for (string s : wordDict) {
      buildTreeR(root, s);
    }
  }

  bool verify(string s, unordered_map<char, TrieNode*> cur) {
    if (s.empty()) return true;

    string cpy = s;
    char first = cpy[0];

    cpy.erase(cpy.begin());
    if (cur.find(first) == cur.end()) return false;

    bool ret = true;
    if (cur[first]->ender) {
      ret = verify(cpy,root) || verify(cpy,cur[first]->nexts);
    } else {
      ret = verify(cpy, cur[first]->nexts);
    }
    return ret;
  }

 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    buildTrie(wordDict);
    return verify(s, root);
  }
};

/*

b/c there are 1000 dict words, optimization must happen
build trie?

look for fullest word possible

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]

c a t(end)
       s (end)
s a n d
a n d
d o g (end)
      s (end)

fork in the road here, must recursively try both
c a t -> sandog
c a t s -> andog
*/