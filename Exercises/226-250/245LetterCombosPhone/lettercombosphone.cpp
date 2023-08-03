/*

17. Letter Combinations of a Phone Number
Medium
16.2K
874
Companies
Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given
below. Note that 1 does not map to any letters.




Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
Accepted
1.6M
Submissions
2.9M
Acceptance Rate
57.7%

*/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    unordered_map<char, vector<char>> lookup;
    lookup['2'] = {'a', 'b', 'c'};
    lookup['3'] = {'d', 'e', 'f'};
    lookup['4'] = {'g', 'h', 'i'};
    lookup['5'] = {'j', 'k', 'l'};
    lookup['6'] = {'m', 'n', 'o'};
    lookup['7'] = {'p', 'q', 'r', 's'};
    lookup['8'] = {'t', 'u', 'v'};
    lookup['9'] = {'w', 'x', 'y', 'z'};
  }
};