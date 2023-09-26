#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
string r(set<char> remaining, int idx, int &s, unordered_map<char, vector<int>> &lookup) {
  if (remaining.empty()) return "";

  if (idx >= s) return "";

  set<char> cpy = remaining;
  for (char c: remaining) {
    cpy.erase(c);
    vector<int> pos = lookup[c];
    auto p = upper_bound(pos.begin(), pos.end(), idx);
    if (p==pos.end()) return "";

    int nextIdx = *p;
    string res = c+r(cpy,nextIdx,s,lookup);
    if (res.size() == s) return res;
  }
}

public:
    string removeDuplicateLetters(string s) {
      set<char> chars;
      unordered_map<char, vector<int>> positions;
      for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        chars.insert(c);
        positions[c].push_back(i);
      }

    }
};