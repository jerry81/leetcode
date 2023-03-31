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
#include <vector>

using namespace std;
class Solution {
string source;
string target;
vector<vector<vector<int>>> lookup;


bool isScrambleR(int len, int idx1, int idx2) {
  int cached = lookup[len][idx1][idx2];
  if (cached > -1) return cached;
  if (len == 0) return true;
  if (len == 1) {
    int res = source[idx1] == target[idx2];
    lookup[len][idx1][idx2] = res;
    return res;
  }

  for (int si = 1; si < len; ++si) {
    int sublen = len - si;
    int idx1b = idx1+si;
    int idx2b = idx2+si;
    int swapped = idx1+si;
    int swapped2 = idx2+sublen;
    int hsh1 = lookup[si][idx1][idx2];
    int hsh2 = lookup[sublen][idx1b][idx2b];
    int hsh3 = lookup[si][idx1][swapped2];
    int hsh4 = lookup[sublen][swapped][idx2];
    if (hsh1 < 0) lookup[si][idx1][idx2] = isScrambleR(si, idx1, idx2);


    if (hsh2 < 0) lookup[sublen][idx1b][idx2b] = isScrambleR(sublen, idx1b, idx2b);

    if (hsh3 < 0) lookup[si][idx1][swapped2] = isScrambleR(si, idx1, swapped2);

    if (hsh4 < 0) lookup[sublen][swapped][idx2] = isScrambleR(sublen, swapped, idx2);

    if (lookup[si][idx1][idx2] && lookup[sublen][idx1b][idx2b]) {
      lookup[len][idx1][idx2] = true;
      return lookup[len][idx1][idx2];
;
    }

    if (lookup[si][idx1][swapped2] && lookup[sublen][swapped][idx2]) {
      lookup[len][idx1][idx2] = true;
      return lookup[len][idx1][idx2];
    }
  }
  lookup[len][idx1][idx2]= false;
  return lookup[len][idx1][idx2];
}
public:
    bool isScramble(string s1, string s2) {
      int d = s1.size();
      for (int i = 0; i < d+1; ++i) {
        vector<vector<int>> lenvec;
        for (int j = 0; j < d; ++j) {
          vector<int> startvec1;
          for (int k = 0; k < d; ++k) {
            startvec1.push_back(-1);
          }
          lenvec.push_back(startvec1);
        }
        lookup.push_back(lenvec);
      }
      target = s2;
      source = s1;

      return isScrambleR(s1.size(),0,0);
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

// 3 vars - len of string, "start index of s1, "start index of s2"

- TLE on a late case
- how to improve?

- stop passing the string and chopping it up
- still TLE

- try more efficient dp table?
- no unordered map and building hash each time.
- use 3d array
*/