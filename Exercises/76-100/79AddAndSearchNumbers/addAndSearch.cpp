/*

211. Design Add and Search Words Data Structure
Medium
6K
347
Companies
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.


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

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class WordDictionary {
unordered_map<int, unordered_map<string,bool>> quick_lookup;
public:
    WordDictionary() {
    }

    void addWord(string word) {
      int len = word.size();
      if (quick_lookup.find(len) == quick_lookup.end()) {
        unordered_map<string,bool> l;
        quick_lookup[len] = l;
      }
        quick_lookup[len][word] = true;
    }

    bool search(string word) {
      if (quick_lookup.find(word.size()) == quick_lookup.end()) return false;

      for (auto a: quick_lookup) {
        cout << "key is " << a.first << endl;
      }
      return quick_lookup[word.size()][word];
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */