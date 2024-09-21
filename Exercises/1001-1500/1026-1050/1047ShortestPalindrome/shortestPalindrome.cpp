/*

214. Shortest Palindrome
Hard
Topics
Companies
You are given a string s. You can convert s to a
palindrome
 by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.



Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"


Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.

Seen this question in a real interview before?
1/5
Yes
No
Accepted
223.8K
Submissions
616.9K
Acceptance Rate
36.3%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string lps = s + "#" + rev_s;
    vector<int> dp(lps.size(), 0);
    int j = 0, ans = 0;
    for (int i = 1; i < lps.size(); i++) {
        while (j > 0 && lps[i] != lps[j]) j = dp[j - 1];
        if (lps[i] == lps[j]) j++;
        dp[i] = j;
        ans = max(ans, j);
    }
    return rev_s.substr(0, s.size() - ans) + s;

  }
};