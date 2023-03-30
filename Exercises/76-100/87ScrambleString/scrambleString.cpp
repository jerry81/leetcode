/*

87. Scramble String
Hard
2.1K
1K
Companies
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.



Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Explanation: One possible scenario applied on s1 is:
"great" --> "gr/eat" // divide at random index.
"gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
"gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
"g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
"r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
"r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
The algorithm stops now, and the result string is "rgeat" which is s2.
As one possible scenario led s1 to be scrambled to s2, we return true.
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false
Example 3:

Input: s1 = "a", s2 = "a"
Output: true


Constraints:

s1.length == s2.length
1 <= s1.length <= 30
s1 and s2 consist of lowercase English letters.
Accepted
165.6K
Submissions
456.1K
Acceptance Rate
36.3%

*/

#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
string target;
unordered_map<string, bool> lookup;

string to_hash(int l, int idx1, int idx2) {
  return to_string(l)+","+to_string(idx1)+","+to_string(idx2);
}

bool isScrambleR(string s1, int idx1, int idx2) {
  int len = s1.size();
  string hsh = to_hash(len,idx1,idx2);
  if (lookup.find(hsh) != lookup.end()) return lookup[hsh];
  if (len == 0) return true;
  if (len == 1) {
    lookup[hsh] = s1[0] == target[idx2];
    return lookup[hsh];
  }

  for (int si = 1; si < len; ++ si) {
    string s1a = s1.substr(0,si);
    string s1b = s1.substr(si);
    int sublen = len - si;
    int idx1b = idx1+si;
    int idx2b = idx2+si;
    int swapped = idx1+si;
    int swapped2 = idx2+sublen;
    string hsh1 = to_hash(si, idx1,idx2);
    string hsh2 = to_hash(sublen, idx1b,idx2b);
    string hsh3 = to_hash(si, idx1,swapped2);
    string hsh4 = to_hash(sublen, swapped, idx2);
    cout << "hashes " << hsh1 << " " << hsh2 << " " << hsh3 << " " << hsh4 << endl;
    if (lookup.find(hsh1) == lookup.end()) lookup[hsh1] = isScrambleR(s1a, idx1, idx2);

    if (lookup.find(hsh2) == lookup.end()) lookup[hsh2] = isScrambleR(s1b, idx1b, idx2b);

    if (lookup.find(hsh3) == lookup.end()) lookup[hsh3] = isScrambleR(s1a, idx1, swapped2);

    if (lookup.find(hsh4) == lookup.end()) lookup[hsh4] = isScrambleR(s1b, swapped, idx2);

    if (lookup[hsh1] && lookup[hsh2]) {
      lookup[hsh] = true;
      return lookup[hsh];
    }

    if (lookup[hsh3] && lookup[hsh4]) {
      lookup[hsh] = true;
      return lookup[hsh];
    }
  }
  lookup[hsh] = false;
  return lookup[hsh];
}
public:
    bool isScramble(string s1, string s2) {
      target = s2;

      return isScrambleR(s1,0,0);
      // end up with s1a s1b and s2a s2b
      // check isScramble for [s1a, s2a], [s1b, s2a]
    }
};

// editorial of shame:
/*

dynamic programming
recursively try all possibilities (all splits)

subproblem, how to check if end condition is met?

cut both the original and the target and compare substrings to each other.
the order of all items in the substrings are fixed relative to the other substring.

// question how to memoize??
*/