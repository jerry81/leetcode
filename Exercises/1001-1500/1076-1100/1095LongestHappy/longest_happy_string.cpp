

// 1405. Longest Happy String
// Medium
// Topics
// Companies
// Hint
// A string s is called happy if it satisfies the following conditions:

// s only contains the letters 'a', 'b', and 'c'.
// s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// s contains at most a occurrences of the letter 'a'.
// s contains at most b occurrences of the letter 'b'.
// s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string.
// If there are multiple longest happy strings, return any of them. If there is
// no such string, return the empty string "".

// A substring is a contiguous sequence of characters within a string.

// Example 1:

// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.
// Example 2:

// Input: a = 7, b = 1, c = 0
// Output: "aabaa"
// Explanation: It is the only correct answer in this case.

// Constraints:

// 0 <= a, b, c <= 100
// a + b + c > 0
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 93.1K
// Submissions
// 160.2K
// Acceptance Rate
// 58.1%

#include <string>

using namespace std;

class Solution {
 public:
  string longestDiverseString(int a, int b, int c) {
    // some kind of greedy
    string res = "";
    int omitted = -1;
    while (a > 0 || b > 0 || c > 0) {
      if (omitted == 0) {
        // omit a
        if (b == 0 && c == 0) break;
        if (b >= c) {
          res += 'b';
          b -= 1;
          if (b > 0) {
            res += 'b';
            b -= 1;
          }
          omitted = 1;
        } else {
          res += 'c';
          c -= 1;
          if (c > 0) {
            res += 'c';
            c -= 1;
          }
          omitted = 2;
        }
      } else if (omitted == 1) {
        // omit b
        if (a == 0 && c == 0) break;
        if (a >= c) {
          res += 'a';
          a -= 1;
          if (a > 0) {
            res += 'a';
            a -= 1;
          }
          omitted = 0;
        } else {
          res += 'c';
          c -= 1;
          if (c > 0) {
            res += 'c';
            c -= 1;
          }
          omitted = 2;
        }
      } else if (omitted == 2) {
        // omit c
        if (a == 0 && b == 0) break;

        if (a >= b) {
          res += 'a';
          a -= 1;
          if (a > 0) {
            res += 'a';
            a -= 1;
          }
          omitted = 0;
        } else {
          res += 'b';
          b -= 1;
          if (b > 0) {
            res += 'b';
            b -= 1;
          }
          omitted = 1;
        }
      } else {
        if (a == 0 && b == 0 && c == 0) break;
        // omit none
        if (a >= b && a >= c) {
          res += 'a';
          a -= 1;
          if (a > 0) {
            res += 'a';
            a -= 1;
          }
          omitted = 0;
        } else if (b >= a && b >= c) {
          res += 'b';
          b -= 1;
          if (b > 0) {
            res += 'b';
            b -= 1;
          }
          omitted = 1;
        } else {
          res += 'c';
          c -= 1;
          if (c > 0) {
            res += 'c';
            c -= 1;
          }
          omitted = 2;
        }
      }
    }
    return res;
  }
};