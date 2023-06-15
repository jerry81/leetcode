/*

409. Longest Palindrome
Easy
4.8K
304
Companies
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.



Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.


Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
Accepted
526.6K
Submissions
974K
Acceptance Rate
54.1%

*/
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
      unordered_map<char, int> freq;
      int ret = 0;
      for (char c: s) freq[c]++;
      int plusOne = 0;
      for (auto [_,count]: freq) {
        if (count > 0) {
          ret+=(count/2)*2;

          if (count % 2 != 0) plusOne = 1;
        }
      }
      return ret;
    }
};

// another freq map counting problem?

// sum up freq of each number / 2
// can stick one extra odd item
// abccccdd -> a1 b1 c4 d2 4 + 2 + 1