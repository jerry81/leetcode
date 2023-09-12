/*

1647. Minimum Deletions to Make Character Frequencies Unique
Medium
3.6K
53
Companies
A string s is called good if there are no two different characters in s that
have the same frequency.

Given a string s, return the minimum number of characters you need to delete to
make s good.

The frequency of a character in a string is the number of times it appears in
the string. For example, in the string "aab", the frequency of 'a' is 2, while
the frequency of 'b' is 1.



Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.
Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string
"aaabbc". Example 3:

Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end
(i.e. frequency of 0 is ignored).


Constraints:

1 <= s.length <= 105
s contains only lowercase English letters.
Accepted
184.2K
Submissions
311.2K
Acceptance Rate
59.2%

*/

#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDeletions(string s) {
    /*
      set up freq map
    */
    map<char, int> freq;
    set<int> visited;
    if (s.length() == 1) return 0;

    for (char c : s) {
      if (freq.find(c) == freq.end()) freq[c] = 0;

      freq[c]++;
    }
    vector<int> vals;
    for (auto [_, v] : freq) {
      vals.push_back(v);
      visited.insert(v);
    }
    sort(vals.begin(), vals.end());
    int res = INT_MAX;
    for (int i = 0; i < vals.size() - 1; ++i) {
      int curVal = vals[i];
      int nVal = vals[i + 1];
      if (curVal == nVal) {
        // set of values
        int found = false;
        for (int j = curVal; j >= 0; --j) {
          if (visited.find(j) == visited.end()) {
            res = += (curVal-j);
            visited.insert(j);
            found = true;
            break;
          }
        }
        if (!found) {
          res += curVal;
        }
      }
    }
    return res;
  }
};