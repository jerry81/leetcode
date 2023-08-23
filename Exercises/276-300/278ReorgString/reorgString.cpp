/*

767. Reorganize String
Medium
6.5K
208
Companies
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

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

#include <string>
#include <vector>
#include <map>

using namespace std;

struct Item {
  int freq;
  char c;
  Item(int f, char c):freq(f), c(c) {}
};

bool compareItem(Item a, Item b) {
  return a.freq > b.freq;
}
class Solution {
public:
    string reorganizeString(string s) {
      // recursion & backtracking
      map<char,int> freqMap;
      vector<Item> items;
      for (char c: s) {
        if (freqMap.find(c) == freqMap.end()) {
          freqMap[c] = 1;
        } else {
          freqMap[c]++;
        }
      }
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
first determine if possible by counting frequency.  if highest freq duplicates over half the size of string u fucked

next - just find a possible arrangement
- we have freq map
- sort freq map
- then place them apart from each other by taking odd/even indexes
*/