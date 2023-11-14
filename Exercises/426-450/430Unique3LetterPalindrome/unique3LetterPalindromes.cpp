/*

1930. Unique Length-3 Palindromic Subsequences
Medium
855
26
Companies
Given a string s, return the number of unique palindromes of length three that
are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is
still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string
with some characters (can be none) deleted without changing the relative order
of the remaining characters.

For example, "ace" is a subsequence of "abcde".


Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".
Example 3:

Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")


Constraints:

3 <= s.length <= 105
s consists of only lowercase English letters.
Accepted
35.7K
Submissions
63.2K
Acceptance Rate
56.5%

*/

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
  int r(int idx, char match) {}

 public:
  int countPalindromicSubsequence(string s) {
    // count each only once so use unordered_set
    // recursive?
    // but not necessary as it becomes a question of finding axa
    // brute force 1 - first and last occurence of each character and count
    // unique items between
    unordered_set<char> visited;
    int res = 0;
    return res;
  }
};