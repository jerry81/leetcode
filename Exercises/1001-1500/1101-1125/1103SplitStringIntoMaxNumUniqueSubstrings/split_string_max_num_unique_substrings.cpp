/*
1593. Split a String Into the Max Number of Unique Substrings
Medium
Topics
Companies
Hint
Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.



Example 1:

Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
Example 2:

Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].
Example 3:

Input: s = "aa"
Output: 1
Explanation: It is impossible to split the string any further.


Constraints:

1 <= s.length <= 16

s contains only lower case English letters.

Seen this question in a real interview before?
1/5
Yes
No
Accepted
38.9K
Submissions
66.1K
Acceptance Rate
58.9%
*/

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int backtrack(int cur_idx, unordered_set<string>& seen, string &s) {
        if (cur_idx == s.size()) {
            return seen.size(); // Return the count of unique substrings
        }

        int maxCount = 0; // Track the maximum count of unique substrings

        for (int end = cur_idx + 1; end <= s.size(); ++end) {
            string substring = s.substr(cur_idx, end - cur_idx);
            if (seen.find(substring) == seen.end()) { // If substring is unique
                seen.insert(substring); // Add to seen
                maxCount = max(maxCount, backtrack(end, seen, s)); // Recur
                seen.erase(substring); // Backtrack
            }
        }

        return maxCount; // Return the maximum count found
    }

public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen; // Set to track unique substrings
        return backtrack(0, seen, s); // Start backtracking from index 0
    }
};