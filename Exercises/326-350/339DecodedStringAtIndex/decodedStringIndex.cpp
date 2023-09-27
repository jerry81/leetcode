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
#include <vector>

using namespace std;

struct Register {
  string cur = "";
  string accum = "";
  int curSz = 0;
  int accumSz = 0;
  int totalSz = 0;
  int repeatCount = 1;
  Register(string cur, string accum, int repeatCount)
      : cur(cur), accum(accum), repeatCount(repeatCount) {
        curSz = cur.size();
        accumSz = accum.size();
        totalSz = curSz + accumSz;
      }
};
class Solution {

  vector<Register*> registers;
  void dec(string s) {
    string curAccum = "";
    string totalAccum = "";
    int regIdx = -1;
    bool prevWasNumber = false;
    for (char c: s) {
      if (isdigit(c)) {
        if (prevWasNumber) { // combine
        }
        prevWasNumber = true;
        if (regIdx < 0) {
          Register *r = new Register(curAccum, totalAccum, )
        }
        regIdx++;
        curAccum = "";
      } else {
        prevWasNumber = false;
        curAccum+=c;
        totalAccum+=c;
      }
    }
  }

  string solve(int k) {
    return "";
  }

 public:
  string decodeAtIndex(string s, int k) {
    dec(s);
    string res = solve(k);
    return res;
  }
};

// low acceptance rate means brute force (simulation will not work)
// what do we store for a23456789999
// i0 [a] i1 [2 i0] i2 [3 i1] etc...
// what do we store for leet2code3
// i0 [leet, leet] i1 [2 i0] i2 [code, leetcode], i3 [3, i2]