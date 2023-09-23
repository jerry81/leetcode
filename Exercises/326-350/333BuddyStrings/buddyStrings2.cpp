/*

859. Buddy Strings
Easy
3K
1.7K
Companies
Given two strings s and goal, return true if you can swap two letters in s so
the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that
i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".


Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal
to goal. Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which
results in "ba" != goal. Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal
to goal.


Constraints:

1 <= s.length, goal.length <= 2 * 104
s and goal consist of lowercase letters.
Accepted
221.9K
Submissions
675.2K
Acceptance Rate
32.9%

*/

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  bool buddyStrings(string s, string goal) {
    char missing;
    char instead;
    bool found = false;
    bool repeat = false;
    bool swapped = false;
    unordered_set<char> seen;
    if (s.size() != goal.size()) return false;

    for (int i = 0; i < goal.size(); ++i) {
      if (s[i] != goal[i]) {
        if (swapped) return false;

        if (!found) {
          found = true;
          instead = s[i];
          missing = goal[i];
        } else {
          if (s[i] != missing || goal[i] != instead)  return false;
          swapped = true;
        }
      }
      if (seen.find(s[i]) != seen.end()) repeat = true;

      seen.insert(s[i]);
    }

    return swapped || (!found && repeat);
  }
};