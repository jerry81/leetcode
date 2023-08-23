/*

767. Reorganize String
Medium
6.5K
208
Companies
Given a string s, rearrange the characters of s so that any two adjacent
characters are not the same.

Return any possible rearrangement of s or return "" if not possible.



Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""


Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
Accepted
278.2K
Submissions
523.4K
Acceptance Rate
53.2%

*/

#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Item {
  int freq;
  char c;
  Item(int f, char c) : freq(f), c(c) {}
};

bool compareItem(Item a, Item b) { return a.freq > b.freq; }
class Solution {
 public:
  string reorganizeString(string s) {
    // recursion & backtracking
    map<char, int> freqMap;
    string ret(s.size(), ' ');
    vector<Item> items;
    for (char c : s) {
      if (freqMap.find(c) == freqMap.end()) {
        freqMap[c] = 1;
      } else {
        freqMap[c]++;
      }
    }
    for (auto [k, v] : freqMap) {
      items.push_back(Item(v, k));
    }
    sort(items.begin(), items.end(), compareItem);

    if (items[0].freq > ceil((double)((double)s.size()) / 2.0)) return "";

    int lastOdd = 1;
    int lastEven = 0;
    bool isEven = true;

    for (Item i : items) {
      int lastSeen = 0;
      int lastIdx = 0;
      if (lastEven < lastOdd) {
        isEven = true;
        lastSeen = lastEven;
      } else {
        isEven = false;
        lastSeen = lastOdd;
      }
      for (int j = 0; j < i.freq; j++) {
        lastIdx = lastSeen + (j * 2);
        ret[lastIdx] = i.c;
      }
      if (isEven) {
        lastEven = lastEven == lastIdx ? lastIdx + 2 : lastIdx;
      } else {
        lastOdd = lastOdd == lastIdx ? lastIdx + 2 : lastIdx;
      }
    }
    return ret;
  }
};

/*

"aaab"
01 no
02 no
03 yes
031 yes
0312 no
032 yes
0321 no

this would be brute force

or - find clever tricks with duplicates

official editorial:
first determine if possible by counting frequency.  if highest freq duplicates
over half the size of string u fucked

next - just find a possible arrangement
- we have freq map
- sort freq map
- then place them apart from each other by taking odd/even indexes
*/