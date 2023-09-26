#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
string r(string accum, set<char> remaining, int idx, int &s, int &t, unordered_map<char, vector<int>> &lookup) {
  cout << "accum is " << accum << endl;

  if (remaining.empty()) return accum;

  if (idx >= s) return "";


  for (char c: remaining) {
    set<char> cpy = remaining;
    cpy.erase(c);
    vector<int> pos = lookup[c];
    auto p = upper_bound(pos.begin(), pos.end(), idx);
    if (p==pos.end()) continue;

    int nextIdx = *p;
    string res = r(accum+c,cpy,nextIdx,s,t,lookup);
    if (res.size() == t) return res;
  }
  return "";
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
      int sz = s.size();
      int tgt = chars.size();
      string res = r("",chars, -1, sz,tgt, positions);
      return res;
    }
};