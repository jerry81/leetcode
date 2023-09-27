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
  vector<int> startIndexes;
  SRegister *parent = nullptr;
  int repeatCount = 1;
  long long int len = 0;
  SRegister(string cur, int idx, int repeatCount)
      : cur(cur), repeatCount(repeatCount) {
    len = (parent->len + cur.size()) * repeatCount;
    for (int i = 0; i < repeatCount; ++i) {
      startIndexes.push_back(idx*len);
    }
  }
};
class Solution {
  vector<SRegister *> registers;
  vector<int> indexes;
  string dec(string s, int stopAt) {
    string res = "";
    string curAccum = "";
    string totalAccum = "";
    int curIdx = 0;
    for (char c : s) {
      if (isdigit(c)) {
        // apply repeats

        curAccum = "";
        SRegister *r = new SRegister(curAccum, totalAccum, curIdx);
        registers.push_back(r);
        curIdx = totalAccum.size();
      } else {
        if (curIdx == stopAt) return c + "";
        curAccum += c;
        totalAccum += c;
        curIdx++;
      }
    }
  }

  string solve(int k) { return ""; }

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