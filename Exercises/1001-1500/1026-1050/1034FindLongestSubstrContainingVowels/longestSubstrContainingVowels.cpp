/*

1371. Find the Longest Substring Containing Vowels in Even Counts
Medium
Topics
Companies
Hint
Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.



Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.


Constraints:

1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
47.5K
Submissions
68.1K
Acceptance Rate
69.7%

*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mask_to_index{{0, -1}};
        int mask = 0;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case 'a': mask ^= 1; break;
                case 'e': mask ^= 2; break;
                case 'i': mask ^= 4; break;
                case 'o': mask ^= 8; break;
                case 'u': mask ^= 16; break;
            }
            if (mask_to_index.find(mask) == mask_to_index.end()) {
                mask_to_index[mask] = i;
            }
            res = max(res, i - mask_to_index[mask]);
        }
        return res;

    }
};