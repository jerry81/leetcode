/*

1531. String Compression II
Hard
1.7K
126
Companies
Run-length encoding is a string compression method that works by replacing
consecutive identical characters (repeated 2 or more times) with the
concatenation of the character and the number marking the count of the
characters (length of the run). For example, to compress the string "aabccc" we
replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string
becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. You need to delete at most k characters from
s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at
most k characters.



Example 1:

Input: s = "aaabcccd", k = 2
Output: 4
Explanation: Compressing s without deleting anything will give us "a3bc3d" of
length 6. Deleting any of the characters 'a' or 'c' would at most decrease the
length of the compressed string to 5, for instance delete 2 'a' then we will
have s = "abcccd" which compressed is abc3d. Therefore, the optimal way is to
delete 'b' and 'd', then the compressed version of s will be "a3c3" of length 4.
Example 2:

a3 b1 c3 d1
2 ops


Input: s = "aabbaa", k = 2
Output: 2
Explanation: If we delete both 'b' characters, the resulting compressed string
would be "a4" of length 2. Example 3:

Input: s = "aaaaaaaaaaa", k = 0
Output: 3
Explanation: Since k is zero, we cannot delete anything. The compressed string
is "a11" of length 3.


Constraints:

1 <= s.length <= 100
0 <= k <= s.length
s contains only lowercase English letters.
Accepted
45.8K
Submissions
92.7K
Acceptance Rate
49.4%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
  int memo[101][101];
  int r(string &s, int &sz, int idx, int rem_k) {
    if (sz - idx <= rem_k) return 0;

    if (memo[idx][rem_k] != -1) return memo[idx][rem_k];

    int ans = rem_k ? r(s, sz, idx + 1, rem_k - 1) : 9999;
    int consecutive = 1;
    char cur = s[idx];
    int k = rem_k;
    for (int j = idx + 1; j <= sz; ++j) {
      int consModifier = 0;
      if (consecutive > 1) consModifier = 1;
      if (consecutive > 9) consModifier = 2;
      if (consecutive > 99) consModifier = 3;
      ans = min(ans, 1+consModifier+r(s,sz,j,k));
      char cmp = s[j];
      if (cur == cmp) {
        consecutive++;
      } else {
        --k;
        if (k < 0) break;
      }
    }
    return memo[idx][rem_k] = ans;
  }

 public:
  int getLengthOfOptimalCompression(string s, int k) {
    memset(memo, -1, sizeof(memo));
    int sz = s.size();
    return r(s, sz, 0, k);
  }
};