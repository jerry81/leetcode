/*

1915. Number of Wonderful Substrings
Medium
Topics
Companies
Hint
A wonderful string is a string where at most one letter appears an odd number of times.

For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

A substring is a contiguous sequence of characters in a string.



Example 1:

Input: word = "aba"
Output: 4
Explanation: The four wonderful substrings are underlined below:
- "aba" -> "a"
- "aba" -> "b"
- "aba" -> "a"
- "aba" -> "aba"
Example 2:

Input: word = "aabb"
Output: 9
Explanation: The nine wonderful substrings are underlined below:
- "aabb" -> "a"
- "aabb" -> "aa"
- "aabb" -> "aab"
- "aabb" -> "aabb"
- "aabb" -> "a"
- "aabb" -> "abb"
- "aabb" -> "b"
- "aabb" -> "bb"
- "aabb" -> "b"
Example 3:

Input: word = "he"
Output: 2
Explanation: The two wonderful substrings are underlined below:
- "he" -> "h"
- "he" -> "e"


Constraints:

1 <= word.length <= 105
word consists of lowercase English letters from 'a' to 'j'.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
15.1K
Submissions
31.7K
Acceptance Rate
47.6%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {

public:
    long long wonderfulSubstrings(string word) {
      long long res = 0;
      int n = word.size();
      vector<int> freq(10, 0);
      int mask = 0;
      return res;
    }
};

/*
  watch video from Happy Coding
  brute force: try every substring
  count so dp
*/