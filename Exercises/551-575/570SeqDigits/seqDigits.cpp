/*

1291. Sequential Digits
Medium
Topics
Companies
Hint
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.



Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]


Constraints:

10 <= low <= high <= 10^9
Seen this question in a real interview before?
1/4
Yes
No
Accepted
134.4K
Submissions
211.5K
Acceptance Rate
63.6%

*/

#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
      // irritating
      string low_str = to_string(low);
      string high_str = to_string(high);
      vector<int> res;
      return res;
    }
};