
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  string removeDuplicateLetters(string s) {
    unordered_map<char, int> lastIdx;
    unordered_set<char> visited;
    int sz = s.size();
    for (int i = 0; i < sz; ++i) {
      lastIdx[s[i]] = i;
    }

    string tmp = "";
    for (int i = 0; i < sz; ++i) {
      char c = s[i];
      if (tmp.empty()) {
        tmp.push_back(c);
        visited.insert(c);
      } else {
        if (visited.find(c) != visited.end()) continue;
        char topItem = tmp.back();
        while (!tmp.empty() && topItem > c && i < lastIdx[topItem]) {
          tmp.pop_back();
          visited.erase(topItem);
          if (!tmp.empty()) topItem = tmp.back();
        }
        tmp.push_back(c);
        visited.insert(c);
      }
    }
    return tmp;
  }
};