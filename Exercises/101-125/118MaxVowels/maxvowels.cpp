/*

1456. Maximum Number of Vowels in a Substring of Given Length
Medium
1.2K
53
Companies
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.



Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.


Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length
Accepted
65.1K
Submissions
110.3K
Acceptance Rate
59.0%

*/

#include <string>
#include <vector>
using namespace std;

class Solution {
bool isv(char c) {
  return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
public:
    int maxVowels(string s, int k) {
      int max_count = 0;
      vector<bool> memo;
      for (int i = 0; i < k; ++i) {
        if (isv(s[i])) {
          max_count++;
          memo.push_back(true);
        } else {
          memo.push_back(false);
        }
      }

      int curcount = max_count;
      for (int i = 1; i < (s.size() - k); ++i ) {
        if (memo[i]) curcount--;
        char back = s[i+k-1];
        if (isv(back)) {
          memo.push_back(true);
          curcount++;
          if (curcount > max_count) max_count = curcount;
        } else {
          memo.push_back(false);
        }
      }
      return max_count;
    }
};

// brute force?