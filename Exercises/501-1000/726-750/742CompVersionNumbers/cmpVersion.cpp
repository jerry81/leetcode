/*

165. Compare Version Numbers
Medium
Topics
Companies
Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each
revision consists of digits and may contain leading zeros. Every revision
contains at least one character. Revisions are 0-indexed from left to right,
with the leftmost revision being revision 0, the next revision being revision 1,
and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order.
Revisions are compared using their integer value ignoring any leading zeros.
This means that revisions 1 and 001 are considered equal. If a version number
does not specify a revision at an index, then treat the revision as 0. For
example, version 1.0 is less than version 1.1 because their revision 0s are the
same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.


Example 1:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same
integer "1". Example 2:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: version1 does not specify revision 2, which means it is treated as
"0". Example 3:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0
< 1, so version1 < version2.


Constraints:

1 <= version1.length, version2.length <= 500
version1 and version2 only contain digits and '.'.
version1 and version2 are valid version numbers.
All the given revisions in version1 and version2 can be stored in a 32-bit
integer. Seen this question in a real interview before? 1/5 Yes No Accepted
387.2K
Submissions
1M
Acceptance Rate
37.2%
*/

#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, string delimiter) {
  // Returns first token
  vector<string> ret;
  const char *del = delimiter.c_str();
  char *token = strtok(str.data(), del);

  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != nullptr) {
    ret.push_back(token);
    token = strtok(nullptr, del);
  }

  return ret;
}

class Solution {
  string trim_zeroes(string input) {
    if (input.size() < 2) return input;
    while (true) {
      if (input.size() < 2) break;
      if (input.front() != '0') break;

      input.erase(input.begin());
    }
    return input;
  };

 public:
  int compareVersion(string version1, string version2) {
    vector<string> tk1 = split(version1, ".");
    vector<string> tk2 = split(version2, ".");
    while (!tk1.empty() || !tk2.empty()) {
      if (!tk1.empty() && !tk2.empty()) {
        string cmp1 = trim_zeroes(tk1.front());
        string cmp2 = trim_zeroes(tk2.front());
        // trim leading zeroes

        if (cmp1 < cmp2) return -1;
        if (cmp1 > cmp2) return 1;
        tk1.erase(tk1.begin());
        tk2.erase(tk2.begin());
        continue;
      }

      if (!tk1.empty()) {
        if (trim_zeroes(tk1.front()) != "0") {
          return 1;
        } else {
          tk1.erase(tk1.begin());
        }
        continue;
      }

      if (!tk2.empty()) {
        if (trim_zeroes(tk2.front()) != "0") {
          return -1;
        } else {
          tk2.erase(tk2.begin());
        }
        continue;
      }
    }
    return 0;
  }
};