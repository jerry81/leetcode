/*

1291. Sequential Digits
Medium
Topics
Companies
Hint
An integer has sequential digits if and only if each digit in the number is one
more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that
have sequential digits.



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

#include <cmath>
#include <string>
#include <vector>

using namespace std;
class Solution {
  int make_seq(int sz, int start_dig) {
    int res = 0;
    while (sz >= 0) {
      int mult = pow(10, sz - 1);
      sz--;
      res += start_dig * mult;
      start_dig += 1;
    }
    return res;
  }

 public:
  vector<int> sequentialDigits(int low, int high) {
    // irritating
    string low_str = to_string(low);
    string high_str = to_string(high);
    int low_size = low_str.size();
    int high_size = high_str.size();
    int cur_sz = low_size;
    int start = 0;
    int test = make_seq(cur_sz,1);
    cout << "test result is " << test << endl;
    vector<int> res;
    return res;
  }
};