/*

880. Decoded String at Index
Medium
1.5K
226
Companies
You are given an encoded string s. To decode the string to a tape, the encoded
string is read one character at a time and the following steps are taken:

If the character read is a letter, that letter is written onto the tape.
If the character read is a digit d, the entire current tape is repeatedly
written d - 1 more times in total. Given an integer k, return the kth letter
(1-indexed) in the decoded string.



Example 1:

Input: s = "leet2code3", k = 10
Output: "o"
Explanation: The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".
Example 2:

Input: s = "ha22", k = 5
Output: "h"
Explanation: The decoded string is "hahahaha".
The 5th letter is "h".
Example 3:

Input: s = "a2345678999999999999999", k = 1
Output: "a"
Explanation: The decoded string is "a" repeated 8301530446056247680 times.
The 1st letter is "a".


Constraints:

2 <= s.length <= 100
s consists of lowercase English letters and digits 2 through 9.
s starts with a letter.
1 <= k <= 109
It is guaranteed that k is less than or equal to the length of the decoded
string. The decoded string is guaranteed to have less than 263 letters. Accepted
40.6K
Submissions
139.4K
Acceptance Rate
29.2%

*/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct SRegister {
  string cur = "";
  int idx = 0;
  SRegister *parent = nullptr;
  int repeatCount = 1;
  long long int len = 0;
  int csize = 0;
  SRegister(string cur, int idx, int repeatCount, long long parentLen)
      : cur(cur), idx(idx), repeatCount(repeatCount) {
    csize = cur.size();
    len = csize;
    long long repeatBlock = parentLen + csize;
    len += (repeatBlock) * (repeatCount - 1);
    len += idx - 1;
  }
};
class Solution {
  vector<SRegister *> registers;

  string solve(SRegister *sr, int stopAt) {
    string ret = "l";
    int offset = stopAt - (sr->idx);
    // find the stopping register
    while (sr->parent != nullptr) {
      cout << "parent len is " << sr->parent->len << endl;
      if (sr->parent->len < offset) break;
      sr = sr->parent;
    }
    cout << "target sr is " << sr->cur << "(offset is )" << offset
         << " and target len is " << sr->len << endl;
    return ret;
    // must walk each register

    // - starting from its root, but skip to the relevant loop, shouldn't we
  }
  string dec(string s, int stopAt) {
    string res = "";
    string curAccum = "";
    int curIdx = 1;
    for (char c : s) {
      if (curIdx >= stopAt) cout << "handle it " << endl;

      if (isdigit(c)) {
        // apply repeats
        SRegister *t = nullptr;

        if (!registers.empty()) t = registers.back();
        long long parentlen = (!t) ? 0 : t->len;
        SRegister *r = new SRegister(curAccum, curIdx, c - '0', parentlen);
        if (t != nullptr) {
          r->parent = t;
        }
        registers.push_back(r);
        curIdx = r->len + 1;
        curAccum = "";
      } else {
        curAccum += c;
      }
    }
    return solve(registers.back(), stopAt);
  }

 public:
  string decodeAtIndex(string s, int k) {
    string res = dec(s, k);
    return res;
  }
};
// low acceptance rate means brute force (simulation will not work)
// what do we store for a23456789999
// i0 [a] i1 [2 i0] i2 [3 i1] etc...
// what do we store for leet2code3
// i0 [leet, leet] i1 [2 i0] i2 [code, leetcode], i3 [3, i2]