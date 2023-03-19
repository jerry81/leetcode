/*

211. Design Add and Search Words Data Structure
Medium
6K
347
Companies
Design a data structure that supports adding new words and finding if a string
matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that
matches word or false otherwise. word may contain dots '.' where dots can be
matched with any letter.


Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True


Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 3 dots in word for search queries.
At most 104 calls will be made to addWord and search.
Accepted
476.7K
Submissions
1.1M
Acceptance Rate
43.1%

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class WordDictionary {
  unordered_map<int, unordered_map<string, bool>> quick_lookup;
  vector<int> getWilds(string s) {
    vector<int> ret;
    for (int i = 0; i < s.length(); ++i) {
      char c = s[i];
      if (c == '.') ret.push_back(i);
    }
    return ret;
  };
  bool noWilds(string word) { return quick_lookup[word.size()][word]; };
  struct LetterTree {
    unordered_map<char, LetterTree*> children;
    bool isEndWord = false;
  };

  LetterTree* root = new LetterTree();

 public:
  WordDictionary() {}

  void addWord_old(string word) {
    int len = word.size();
    if (quick_lookup.find(len) == quick_lookup.end()) {
      unordered_map<string, bool> l;
      quick_lookup[len] = l;
    }
    quick_lookup[len][word] = true;
  }

  void addWord(string word) {
    LetterTree* cur = root;
    for (int i = 0; i < word.size(); ++i) {
      char c = word[i];
      if (root->children.find(c) == root->children.end()) {
        LetterTree* newlt = new LetterTree();
        root->children[c] = newlt;
      }
      cur = root->children[c];
      if (i == (word.size() - 1)) root->children[c]->isEndWord = true;
    }
  }

  bool searchR(string remaining, LetterTree* cur) {
    auto childr = cur->children;
    char first = remaining[0];
    string nextS = remaining.substr(1);

    if (first == '.') {
        if (remaining.size() == 1 && cur->isEndWord) return true;

        bool accum = false;

        for (auto c: childr) {
          accum = accum||searchR(nextS, c.second);
        }
        return accum;
    }

    if (childr.find(first) == childr.end()) return false;

    if (remaining.size() == 1 && cur->isEndWord) return true;

    return searchR(nextS, childr[first]);
  }

  bool search(string word) {
    return searchR(word, root);
  }

  bool search_old(string word) {
    if (quick_lookup.find(word.size()) == quick_lookup.end()) return false;
    vector<int> wilds = getWilds(word);
    if (wilds.empty()) return noWilds(word);

    auto a = quick_lookup[word.size()];

    for (auto b : a) {
      bool contains = true;
      for (int i = 0; i < word.size(); ++i) {
        if (word[i] == '.') continue;
        if (word[i] != b.first[i]) {
          contains = false;
          break;
        }
      }
      if (contains) return true;
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */