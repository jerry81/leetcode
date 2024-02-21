/*
1416. Restore The Array
Hard
483
21
Companies
A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may be very large, return it modulo 109 + 7.



Example 1:

Input: s = "1000", k = 10000
Output: 1
Explanation: The only possible array is [1000]
Example 2:

Input: s = "1000", k = 10
Output: 0
Explanation: There cannot be an array that was printed this way and has all integer >= 1 and <= 10.
Example 3:

Input: s = "1317", k = 2000
Output: 8
Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]


Constraints:

1 <= s.length <= 105
s consists of only digits and does not contain leading zeros.
1 <= k <= 109
Accepted
14.9K
Submissions
38.4K
Acceptance Rate
38.7%

*/

#include <string>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const static int MOD = pow(10,9) + 7;

class Solution {
vector<unordered_map<string, bool>> lookup;  // idx, suffix
int totalcount = 0;
int ulimit = 0;
int size = 0;
void traverse(int idx, string key) {
  if (idx >= size) return;
  int asI = stoi(key);

  if (lookup[idx].find(key) == lookup[idx].end()) {
      lookup[idx][key] = asI < ulimit;
      if (!lookup[idx][key]) return;
  }

  string compare = key.substr(idx);

  int cAsI = stoi(compare);

  string nextkey = key.substr(idx+1);

  traverse(idx+1, key);
  traverse(idx+1, nextkey);
}
public:
    int numberOfArrays(string s, int k) {
      ulimit = k;
      size = s.size();
      for (char _: s) {
        unordered_map<string, bool> h;
        lookup.push_back(h);
      }
      traverse(0, s);
    }
};
