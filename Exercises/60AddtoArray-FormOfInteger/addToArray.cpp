/*

989. Add to Array-Form of Integer
Easy
2K
185
Companies
The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.



Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021


Constraints:

1 <= num.length <= 104
0 <= num[i] <= 9
num does not contain any leading zeros except for the zero itself.
1 <= k <= 104
Accepted
158.9K
Submissions
343.8K
Acceptance Rate
46.2%

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
      long long multiplier = 1;
      long long sum = 0;
      for (int i = (num.size() - 1); i >= 0; --i) {
        long long addend = (num[i] * multiplier);
        sum+=addend;
        multiplier *= 10;
      }
      sum+=k;
      vector<int> result;
      multiplier = 1;
      string as_s = to_string(sum);
      for (char c: as_s) {
        result.push_back(c - '0');
      }
      return result;
    }

};

int main() {
  Solution s;
  vector<int> test1;
  test1 = {1,2,0,0};
  s.addToArrayForm(test1, 34);
  return 0;
}