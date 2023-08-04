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

int _counter = 0;
struct TrieNode {
  char c;
  bool ender = false;
  int id;
  unordered_map<char, TrieNode*> nexts;
  TrieNode(char c) : c(c){
    id = _counter;
    _counter++;
  };
};
class Solution {
  TrieNode* root;
  unordered_map<string, bool> lookup;

  void buildTreeR(TrieNode* &root, string s) {
    if (s.empty()) return;

    char f = s[0];
    s.erase(s.begin());
    if (root->nexts.find(f) == root->nexts.end()) root->nexts[f] = new TrieNode(f);

    if (s.empty()) root->nexts[f]->ender = true;

    buildTreeR(root->nexts[f], s);
  }

  void buildTrie(vector<string>& wordDict) {
    for (string s : wordDict) {
      buildTreeR(root, s);
    }
  }

  string to_hash(string s, int id) {
    return s + to_string(id);
  }

  bool verify(string s, TrieNode* cur) {
    string hsh = to_hash(s, cur->id);
    if (lookup.find(hsh) != lookup.end()) return lookup[hsh];

    if (s.size() == 1) {
      if (cur->nexts.find(s[0]) == cur->nexts.end()) return false;

      return (cur->nexts[s[0]]->ender);
    }

    string cpy = s;
    char first = cpy[0];

    cpy.erase(cpy.begin());
    if (cur->nexts.find(first) == cur->nexts.end()) {
      lookup[hsh] = false;
      return false;
    }

    bool ret = true;
    if (cur->nexts[first]->ender) {
      ret = verify(cpy,root) || verify(cpy,cur->nexts[first]);
    } else {
      ret = verify(cpy, cur->nexts[first]);
    }
    lookup[hsh] = ret;
    return ret;
  }

 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    root = new TrieNode('_');
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